#include "StdAfx.h"
#include "wmvstream.h"


CWmvStream::CWmvStream()
: m_pINSSBuffer(NULL)
, m_IVideoOutputProps(NULL)
, m_theMediaType(NULL)
, m_bitmapBuffer(NULL)
, m_dwrdBitmapBufferLength(0)
, m_theOutputsCount(0)
, m_iVideoOutputNumber(0)
, m_iAudioOutputNumber(0)
, m_iVideoStreamNumber(0)
, m_iAudioStreamNumber(0)
,m_iFramesRead(0)
{
	::CoInitialize(NULL);
	m_ISyncReader = NULL;
	m_qwCurrrentPostionInSeconds =0;
	m_qwTotalTimeInSeconds = 0;

}

CWmvStream::~CWmvStream(void)
{
	CloseStream();
	::CoUninitialize();
	
	if(m_bitmapBuffer)
		delete []m_bitmapBuffer;
	m_bitmapBuffer = NULL;
	

}

// opens the file and gets all its properties
bool CWmvStream::OpenStream(CString filename)
{
	m_filename = filename;
	bool error = false;
		//Step 1: Create the Reader Object
		hr  = WMCreateSyncReader(NULL,0,&m_ISyncReader);
		if(hr!=S_OK)
		{
			error = true;
			return (!error); 
			//AfxMessageBox("problem initializing the syncReader");
		}
		//Step 2: Open the file
		//note: When the synchronous reader opens the file, it assigns an output number to each stream
		hr = m_ISyncReader->Open(m_filename.AllocSysString());
		if(hr!=S_OK)
		{
			error = true;
			//AfxMessageBox("problem opening file");
			return (!error);
		}
		
		/*step 3: Analyise the output stream in the file   //working with outputs MSDN
		   note:A wmv file has Outputs and streams number,a stream in a wmv file starts from 1 not from 0 
				and the Output nubmers strat from 0;
				Every output has a stream refurring to it! the numbers are not the same
				There are functions to find from an Output number a stream number and also the opposite*/
				
		//3.1 get the number of outputs:
		//DWORD theOutputCount;
		m_ISyncReader->GetOutputCount(&m_theOutputsCount);
		//3.2 Loop threw the streams and determine wich is the audio and wich is the video
		DWORD theSize;
		for (int i=0;i<m_theOutputsCount;i++)
		{
			SAFE_RELEASE( m_IVideoOutputProps );
			SAFE_ARRAYDELETE( m_theMediaType );
			m_ISyncReader->GetOutputProps(i,&m_IVideoOutputProps);
			hr = m_IVideoOutputProps->GetMediaType(NULL,&theSize);
			m_theMediaType = ( WM_MEDIA_TYPE* ) new BYTE[ theSize ];
			hr = m_IVideoOutputProps->GetMediaType(m_theMediaType,&theSize);
			
			if( FAILED( hr ) )
			{
				error = true;
				return (!error); 
				//_tcscpy( tszErrMsg, _T( "Could not query for the space needed for media type" ) );
				//break;
			}

			if( WMMEDIATYPE_Video == m_theMediaType->majortype)//pMediaType->majortype )
			{
				m_iVideoOutputNumber = i;
				m_ISyncReader->GetStreamNumberForOutput(m_iVideoOutputNumber,(WORD*)&m_iVideoStreamNumber);
				/*theVideoOutputProp->GetMediaType(NULL,&theSize);
				theVideoOutputProp->GetMediaType(&theMediaType,&theSize);*/
				if(m_theMediaType->formattype == WMFORMAT_VideoInfo)
				{
					//setting the bitmapInfoHeader by reading the WmvInfoHeader
					memcpy(&m_theVideoInfoHeader,m_theMediaType->pbFormat,sizeof(WMVIDEOINFOHEADER));
					m_BitmapInfoHdr= m_theVideoInfoHeader.bmiHeader;			
				}

				
			}
			if( WMMEDIATYPE_Audio == m_theMediaType->majortype)
            {
				m_iAudioOutputNumber = i;
				m_ISyncReader->GetStreamNumberForOutput(m_iAudioOutputNumber,(WORD*)&m_iAudioStreamNumber);
            }

		}
		//relesae the memory
		SAFE_RELEASE( m_IVideoOutputProps );
		SAFE_ARRAYDELETE( m_theMediaType );
		
		//step 4 : Set to recive correct sample durations.
		/* To ensure that the synchronous reader delivers correct sample durations for video streams,
		you must first configure the stream output. Call the IWMSyncReader::SetOutputSetting 
		method to set the g_wszVideoSampleDurations setting to TRUE.
		If True, the reader will deliver accurate sample durations.*/
		BYTE* pValue = new BYTE[5];
		strcpy((char*)pValue,"TRUE");
		hr = m_ISyncReader->SetOutputSetting(m_iVideoOutputNumber,g_wszVideoSampleDurations,WMT_TYPE_BOOL,pValue,sizeof(pValue));
		delete []pValue;
		if(FAILED (hr))
		{
			//AfxMessageBox("could not set Video Ouptut Sample durations");
			error=true;
			return (!error); 
		}
		
		//step 5: Set To recive Uncompressed Samples
		/*The SetReadStreamSamples method specifies whether samples from a stream will 
		be 	delivered compressed or uncompressed.
		setting to recive uncompressed samples*/
		hr = m_ISyncReader->SetReadStreamSamples(m_iVideoStreamNumber,FALSE);
		if(FAILED (hr))
		{
			//AfxMessageBox("could not set Video Stream to give Uncompressed Samples");
			error=true;
			return (!error); 
		}
			
		
		if(!error)
			m_isStreamOpen  = m_OpenSuccesfully = true;

		//step 6: Get wmv Duration (total time)
		//6.1 create a MetaData Editor
		IWMMetadataEditor *pEditor;
		
		hr= WMCreateEditor(&pEditor);
		if(hr==S_OK)
		{
			pEditor->Open(m_filename.AllocSysString());
		//6.2 create a HeaderInfo interface. (note: only attributes that were inserted to the header in the creation of the file could be found)
			IWMHeaderInfo3* pHdrInfo;
			pHdrInfo    = NULL;
			hr = pEditor->QueryInterface(IID_IWMHeaderInfo3,(void**)&pHdrInfo);
			WORD wStream =0;// for any stream;
			WMT_ATTR_DATATYPE dType;
			QWORD dwDuration;
			WORD wSize =0;// sizeof(dwDuration);
			//first Call for receiving the buffer size
			hr = pHdrInfo->GetAttributeByName(&wStream,L"Duration",&dType,(BYTE*)NULL,&wSize);
			
			BYTE* pValue;
			if(wSize>0) 
			pValue = new BYTE[wSize];
			hr = pHdrInfo->GetAttributeByName(&wStream,L"Duration",&dType,pValue,&wSize);
			dwDuration =*((QWORD*)pValue);
			//QWORD *mDword = (QWORD*) pValue;
			//QWORD yyy = *mDword;
			m_qwTotalTimeInSeconds = (dwDuration*100)/1000000000;
			SAFE_ARRAYDELETE(pValue);
			SAFE_RELEASE(pHdrInfo);
			SAFE_RELEASE(pEditor);
			
			
		}
	
	error=false;	
	return (!error); 
}

int CWmvStream::NextFrame()
{

	QWORD cnsSampleTime = 0;
	QWORD cnsSampleDuration = 0;
	DWORD dwFlags = 0;
	DWORD dwOutputNumber;
		
	hr = m_ISyncReader->GetNextSample(m_iVideoStreamNumber,
											&m_pINSSBuffer,
											&cnsSampleTime,
											&cnsSampleDuration,
											&dwFlags,
											NULL,//&dwOutputNumber,
											NULL);
	if(hr== NS_E_NO_MORE_SAMPLES)
	{
		//no more samples to read in file
			return 0;
	}

	if(SUCCEEDED(hr))
	{
		// TODO: Process the sample in whatever way is appropriate 
		// to your application. When finished, clean up.
		if(dwFlags ==WM_SF_CLEANPOINT) //this a clean point frame, a picture to take read sdk for explantion 
		{
//					AfxMessageBox("found new sample");
			//1. Get the Bitmap from the frame
			//BYTE* meir;
			unsigned char *buffer;
			m_pINSSBuffer->GetBufferAndLength(&buffer,&m_dwrdBitmapBufferLength);
			if(m_bitmapBuffer==NULL)
			{
				m_bitmapBuffer = new unsigned char[m_dwrdBitmapBufferLength];
			}
			memcpy(m_bitmapBuffer,buffer,m_dwrdBitmapBufferLength);
			//calc the current postion in seconds
			m_qwCurrrentPostionInSeconds = (cnsSampleTime*100)/1000000000;
			m_iFramesRead++;
			
		
		}
		//cleaning up before reading next sample
		m_pINSSBuffer->Release();
		m_pINSSBuffer = NULL;
		/*cnsSampleTime     = 0;
		cnsSampleDuration = 0;
		dwFlags           = 0;
		dwOutputNumber    = 0;*/
	}
	
	return 1;
}



void CWmvStream::CloseStream()
{
	SAFE_RELEASE(m_ISyncReader);
	
}

int CWmvStream::SaveCurrentFrameToBmp(char* filename)
{
	ULONG theFileLen = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) +  m_BitmapInfoHdr.biSizeImage;
	BITMAPFILEHEADER theFileHeader = {'BM',theFileLen,0,0,(sizeof(BITMAPFILEHEADER) + m_BitmapInfoHdr.biSize + DibPaletteSize(&m_BitmapInfoHdr))};// };
	theFileHeader.bfType =BFT_BITMAP;// 0X4D42;
	BITMAPINFOHEADER theInfoHeader = m_BitmapInfoHdr;
	FILE *theFile = fopen(filename,"wb+");
	fwrite(&theFileHeader,sizeof(BITMAPFILEHEADER),1,theFile);
	fwrite(&theInfoHeader,sizeof(BITMAPINFOHEADER),1,theFile);
	fwrite(m_bitmapBuffer,m_dwrdBitmapBufferLength,1,theFile);
	fclose(theFile);
	
	return 0;
}
