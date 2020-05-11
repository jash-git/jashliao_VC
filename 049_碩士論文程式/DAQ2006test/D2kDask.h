#ifndef		_D2K_DASK_H
#define		_D2K_DASK_H

#ifdef __cplusplus
extern "C" {
#endif

//DAQ2000 Device
#define DAQ_2010        1
#define DAQ_2205        2
#define DAQ_2206        3
#define DAQ_2005        4
#define DAQ_2204        5
#define DAQ_2006        6
#define DAQ_2501        7
#define DAQ_2502        8
#define DAQ_2208        9
#define DAQ_2213        10
#define DAQ_2214        11

#ifndef __DaskConst
#define __DaskConst
//DASK Data Types
typedef unsigned char   U8;
typedef short           I16;
typedef unsigned short  U16;
typedef long            I32;
typedef unsigned long   U32;
typedef float           F32;
typedef double          F64;

#define MAX_CARD        32

//Error Number
#define NoError                       0
#define ErrorUnknownCardType         -1
#define ErrorInvalidCardNumber       -2
#define ErrorTooManyCardRegistered   -3
#define ErrorCardNotRegistered       -4
#define ErrorFuncNotSupport          -5
#define ErrorInvalidIoChannel        -6
#define ErrorInvalidAdRange          -7
#define ErrorContIoNotAllowed        -8
#define ErrorDiffRangeNotSupport     -9
#define ErrorLastChannelNotZero      -10
#define ErrorChannelNotDescending    -11
#define ErrorChannelNotAscending     -12
#define ErrorOpenDriverFailed        -13
#define ErrorOpenEventFailed         -14
#define ErrorTransferCountTooLarge   -15
#define ErrorNotDoubleBufferMode     -16
#define ErrorInvalidSampleRate       -17
#define ErrorInvalidCounterMode      -18
#define ErrorInvalidCounter          -19
#define ErrorInvalidCounterState     -20
#define ErrorInvalidBinBcdParam      -21
#define ErrorBadCardType             -22
#define ErrorInvalidDaRefVoltage     -23
#define ErrorAdTimeOut               -24
#define ErrorNoAsyncAI               -25
#define ErrorNoAsyncAO               -26
#define ErrorNoAsyncDI               -27
#define ErrorNoAsyncDO               -28
#define ErrorNotInputPort            -29
#define ErrorNotOutputPort           -30
#define ErrorInvalidDioPort          -31
#define ErrorInvalidDioLine          -32
#define ErrorContIoActive            -33
#define ErrorDblBufModeNotAllowed    -34
#define ErrorConfigFailed            -35
#define ErrorInvalidPortDirection    -36
#define ErrorBeginThreadError        -37
#define ErrorInvalidPortWidth        -38
#define ErrorInvalidCtrSource        -39
#define ErrorOpenFile                -40
#define ErrorAllocateMemory          -41
#define ErrorDaVoltageOutOfRange     -42
#define ErrorInvalidSyncMode         -43
#define ErrorInvalidBufferID         -44
#define ErrorInvalidCNTInterval	     -45
#define ErrorReTrigModeNotAllowed    -46
#define ErrorResetBufferNotAllowed   -47
#define ErrorAnaTriggerLevel         -48
#define ErrorDAQEvent		         -49
//Error number for driver API 
#define ErrorConfigIoctl			 -201
#define ErrorAsyncSetIoctl			 -202
#define ErrorDBSetIoctl				 -203
#define ErrorDBHalfReadyIoctl		 -204
#define ErrorContOPIoctl			 -205
#define ErrorContStatusIoctl		 -206
#define ErrorPIOIoctl				 -207
#define ErrorDIntSetIoctl			 -208
#define ErrorWaitEvtIoctl			 -209
#define ErrorOpenEvtIoctl			 -210
#define ErrorCOSIntSetIoctl			 -211
#define ErrorMemMapIoctl			 -212
#define ErrorMemUMapSetIoctl		 -213
#define ErrorCTRIoctl			     -214
#define ErrorGetResIoctl		     -215

#define TRUE    1
#define FALSE   0

//Synchronous Mode
#define SYNCH_OP        1
#define ASYNCH_OP       2

//AD Range
#define AD_B_10_V       1
#define AD_B_5_V        2
#define AD_B_2_5_V      3
#define AD_B_1_25_V     4
#define AD_B_0_625_V    5
#define AD_B_0_3125_V   6
#define AD_B_0_5_V      7
#define AD_B_0_05_V     8
#define AD_B_0_005_V    9
#define AD_B_1_V       10
#define AD_B_0_1_V     11
#define AD_B_0_01_V    12
#define AD_B_0_001_V   13
#define AD_U_20_V      14
#define AD_U_10_V      15
#define AD_U_5_V       16
#define AD_U_2_5_V     17
#define AD_U_1_25_V    18
#define AD_U_1_V       19
#define AD_U_0_1_V     20
#define AD_U_0_01_V    21
#define AD_U_0_001_V   22
#define AD_B_2_V	   23
#define AD_B_0_25_V    24
#define AD_B_0_2_V     25
#define AD_U_4_V	   26
#define AD_U_2_V	   27
#define AD_U_0_5_V     28
#define AD_U_0_4_V     29

//DIO Port Direction
#define INPUT_PORT      1
#define OUTPUT_PORT     2

//Channel & Port
#define Channel_P1A             0
#define Channel_P1B             1
#define Channel_P1C             2
#define Channel_P1CL            3
#define Channel_P1CH            4
#define Channel_P1AE            10
#define Channel_P1BE            11
#define Channel_P1CE            12
#define Channel_P2A             5
#define Channel_P2B             6
#define Channel_P2C             7
#define Channel_P2CL            8
#define Channel_P2CH            9
#define Channel_P2AE            15
#define Channel_P2BE            16
#define Channel_P2CE            17
#define Channel_P3A             10
#define Channel_P3B             11
#define Channel_P3C             12
#define Channel_P3CL            13
#define Channel_P3CH            14
#define Channel_P4A             15
#define Channel_P4B             16
#define Channel_P4C             17
#define Channel_P4CL            18
#define Channel_P4CH            19
#define Channel_P5A             20
#define Channel_P5B             21
#define Channel_P5C             22
#define Channel_P5CL            23
#define Channel_P5CH            24
#define Channel_P6A             25
#define Channel_P6B             26
#define Channel_P6C             27
#define Channel_P6CL            28
#define Channel_P6CH            29

#endif
/*-------- Constants for DAQ2000 --------------------*/

#define All_Channels	-1
#define BufferNotUsed	-1
/* Constants for Analog trigger */
/* define analog trigger condition constants */
#define Below_Low_level         0x0000
#define Above_High_Level        0x0100
#define Inside_Region           0x0200
#define High_Hysteresis         0x0300
#define Low_Hysteresis          0x0400
/* define analog trigger Dedicated Channel */
#define CH0ATRIG				0x00
#define CH1ATRIG				0x02
#define CH2ATRIG				0x04
#define CH3ATRIG				0x06
#define EXTATRIG				0x01
#define ADCATRIG				0x00 //used for DAQ-2205/2206
/* Time Base */
#define DAQ2K_IntTimeBase		0x00
#define DAQ2K_ExtTimeBase		0x01
#define DAQ2K_SSITimeBase		0x02
/* Constants for AD	*/
#define DAQ2K_AI_ADCONVSRC_Int    0x00
#define DAQ2K_AI_ADCONVSRC_AFI0   0x04
#define DAQ2K_AI_ADCONVSRC_SSI    0x08
#define DAQ2K_AI_ADCONVSRC_AFI1   0x0C

#define DAQ2K_AI_ADCONVSRC_PFI0   DAQ2K_AI_ADCONVSRC_AFI0

//AI Delay Counter SRC: only available for DAQ-250X
#define DAQ2K_AI_DTSRC_Int      0x00
#define DAQ2K_AI_DTSRC_AFI1     0x10
#define DAQ2K_AI_DTSRC_GPTC0    0x20
#define DAQ2K_AI_DTSRC_GPTC1    0x30

#define DAQ2K_AI_TRGSRC_SOFT      0x00   
#define DAQ2K_AI_TRGSRC_ANA       0x01   
#define DAQ2K_AI_TRGSRC_ExtD      0x02   
#define DAQ2K_AI_TRSRC_SSI        0x03   
#define DAQ2K_AI_TRGMOD_POST      0x00   //Post Trigger Mode
#define DAQ2K_AI_TRGMOD_DELAY     0x08   //Delay Trigger Mode
#define DAQ2K_AI_TRGMOD_PRE       0x10   //Pre-Trigger Mode
#define DAQ2K_AI_TRGMOD_MIDL      0x18   //Middle Trigger Mode
#define DAQ2K_AI_ReTrigEn         0x80
#define DAQ2K_AI_Dly1InSamples    0x100
#define DAQ2K_AI_Dly1InTimebase   0x000
#define DAQ2K_AI_MCounterEn       0x400
#define DAQ2K_AI_TrgPositive      0x0000
#define DAQ2K_AI_TrgNegative      0x1000
//AI Reference ground
#define	AI_RSE			0x0000
#define	AI_DIFF			0x0100
#define	AI_NRSE			0x0200
/* Constants for DA	*/
//DA CH config constant
#define DAQ2K_DA_BiPolar          0x1
#define DAQ2K_DA_UniPolar         0x0
#define DAQ2K_DA_Int_REF          0x0
#define DAQ2K_DA_Ext_REF          0x1
//DA control constant
#define DAQ2K_DA_WRSRC_Int      0x00
#define DAQ2K_DA_WRSRC_AFI1     0x01
#define DAQ2K_DA_WRSRC_SSI      0x02

#define DAQ2K_DA_WRSRC_PFI0     DAQ2K_DA_WRSRC_AFI0
#define DAQ2K_DA_WRSRC_AFI0     DAQ2K_DA_WRSRC_AFI1
//DA group 
#define	DA_Group_A		0x00
#define	DA_Group_B		0x04
#define	DA_Group_AB		0x08
//DA TD Counter SRC: only available for DAQ-250X
#define DAQ2K_DA_TDSRC_Int      0x00
#define DAQ2K_DA_TDSRC_AFI0     0x10
#define DAQ2K_DA_TDSRC_GPTC0    0x20
#define DAQ2K_DA_TDSRC_GPTC1    0x30
//DA BD Counter SRC: only available for DAQ-250X
#define DAQ2K_DA_BDSRC_Int      0x00
#define DAQ2K_DA_BDSRC_AFI0     0x40
#define DAQ2K_DA_BDSRC_GPTC0    0x80
#define DAQ2K_DA_BDSRC_GPTC1    0xC0

//DA trigger constant
#define DAQ2K_DA_TRGSRC_SOFT    0x00   
#define DAQ2K_DA_TRGSRC_ANA     0x01   
#define DAQ2K_DA_TRGSRC_ExtD    0x02   
#define DAQ2K_DA_TRSRC_SSI      0x03
#define DAQ2K_DA_TRGMOD_POST    0x00
#define DAQ2K_DA_TRGMOD_DELAY   0x04
#define DAQ2K_DA_ReTrigEn       0x20
#define DAQ2K_DA_Dly1InUI		0x40
#define DAQ2K_DA_Dly1InTimebase 0x00
#define DAQ2K_DA_Dly2InUI		0x80
#define DAQ2K_DA_Dly2InTimebase 0x00
#define DAQ2K_DA_DLY2En			0x100
#define DAQ2K_DA_TrgPositive    0x000
#define DAQ2K_DA_TrgNegative    0x200

//DA stop mode
#define DAQ2K_DA_TerminateImmediate 0
#define DAQ2K_DA_TerminateUC        1
#define DAQ2K_DA_TerminateIC		2

#define DAQ2K_DA_TerminateFIFORC    DAQ2K_DA_TerminateIC
//DA stop source : only available for DAQ-250X
#define DAQ2K_DA_STOPSRC_SOFT     0
#define DAQ2K_DA_STOPSRC_AFI0     1
#define DAQ2K_DA_STOPSRC_ATrig    2
#define DAQ2K_DA_STOPSRC_AFI1     3

#ifndef __CTR8254Const
#define __CTR8254Const
/*-------- Timer/Counter -----------------------------*/
//Counter Mode (8254)
#define TOGGLE_OUTPUT             0     //Toggle output from low to high on terminal count
#define PROG_ONE_SHOT             1     //Programmable one-shot
#define RATE_GENERATOR            2     //Rate generator
#define SQ_WAVE_RATE_GENERATOR    3     //Square wave rate generator
#define SOFT_TRIG                 4     //Software-triggered strobe
#define HARD_TRIG                 5     //Hardware-triggered strobe
//16-bit binary or 4-decade BCD counter
#define BIN             0
#define BCD             1
#endif
//General Purpose Timer/Counter
//Counter Mode
#define SimpleGatedEventCNT		  0x01 
#define SinglePeriodMSR			  0x02
#define SinglePulseWidthMSR		  0x03
#define SingleGatedPulseGen		  0x04	
#define SingleTrigPulseGen	      0x05
#define RetrigSinglePulseGen	  0x06
#define SingleTrigContPulseGen	  0x07
#define ContGatedPulseGen		  0x08
//GPTC clock source
#define GPTC_GATESRC_EXT		  0x04
#define GPTC_GATESRC_INT		  0x00
#define GPTC_CLKSRC_EXT		      0x08
#define GPTC_CLKSRC_INT		      0x00
#define GPTC_UPDOWN_SEL_EXT	      0x10
#define GPTC_UPDOWN_SEL_INT	      0x00
//GPTC clock polarity
#define GPTC_CLKEN_LACTIVE        0x01
#define GPTC_CLKEN_HACTIVE		  0x00
#define GPTC_GATE_LACTIVE		  0x02
#define GPTC_GATE_HACTIVE		  0x00
#define GPTC_UPDOWN_LACTIVE	      0x04
#define GPTC_UPDOWN_HACTIVE	      0x00
#define GPTC_OUTPUT_LACTIVE       0x08
#define GPTC_OUTPUT_HACTIVE	      0x00
#define GPTC_INT_LACTIVE	      0x10
#define GPTC_INT_HACTIVE	      0x00
//GPTC paramID
#define GPTC_IntGATE			  0x00
#define GPTC_IntUpDnCTR			  0x01
#define GPTC_IntENABLE		      0x02
//SSI signal code
#define SSI_TIME	1
#define SSI_CONV	2
#define SSI_WR		4
#define SSI_ADTRIG  0x20 
#define SSI_DATRIG  0x40
//DAQ Event type for the event message  
#define DAQEnd   0
#define DBEvent  1
#define TrigEvent  2
#define DAQEnd_A   0
#define DAQEnd_B   2
#define DAQEnd_AB  3
#define DATrigEvent    4
#define DATrigEvent_A  4
#define DATrigEvent_B  5
#define DATrigEvent_AB 6

/*------------------------------------------------------------------
** PCIS-DASK Function prototype
------------------------------------------------------------------*/
I16 __stdcall D2K_Register_Card (U16 CardType, U16 card_num);
I16 __stdcall D2K_Release_Card  (U16 CardNumber);
I16 __stdcall D2K_AIO_Config (U16 wCardNumber, U16 TimerBase, U16 AnaTrigCtrl, U16 H_TrgLevel, U16 L_TrgLevel);
/*---------------------------------------------------------------------------*/
I16 __stdcall D2K_AI_Config (U16 wCardNumber, U16 ConfigCtrl, U32 TrigCtrl, U32 MidOrDlyScans, U16 MCnt, U16 ReTrgCnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AI_PostTrig_Config (U16 wCardNumber, U16 ClkSrc, U32 TrigSrcCtrl, U16 ReTrgEn, U16 ReTrgCnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AI_DelayTrig_Config (U16 wCardNumber, U16 ClkSrc, U32 TrigSrcCtrl, U32 DlyScans, U16 ReTrgEn, U16 ReTrgCnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AI_PreTrig_Config (U16 wCardNumber, U16 ClkSrc, U32 TrigSrcCtrl, U16 MCtrEn, U16 MCnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AI_MiddleTrig_Config (U16 wCardNumber, U16 ClkSrc, U32 TrigSrcCtrl, U32 MiddleScans, U16 MCtrEn, U16 MCnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AI_CH_Config (U16 wCardNumber, U16 wChannel, U16 wAdRange_RefGnd);
I16 __stdcall D2K_AI_InitialMemoryAllocated (U16 CardNumber, U32 *MemSize);
I16 __stdcall D2K_AI_ReadChannel (U16 CardNumber, U16 Channel, U16 *Value);
I16 __stdcall D2K_AI_VReadChannel (U16 CardNumber, U16 Channel, F64 *voltage);
I16 __stdcall D2K_AI_SimuReadChannel (U16 wCardNumber, U16 wNumChans, U16 *pwChans, U16 *pwBuffer);
I16 __stdcall D2K_AI_ScanReadChannels (U16 wCardNumber, U16 wNumChans, U16 *pwChans, U16 *pwBuffer);
I16 __stdcall D2K_AI_VoltScale (U16 CardNumber, U16 AdRange, I16 reading, F64 *voltage);
I16 __stdcall D2K_AI_ContReadChannel (U16 CardNumber, U16 Channel,
               U16 BufId, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 SyncMode);
I16 __stdcall D2K_AI_ContReadMultiChannels (U16 CardNumber, U16 NumChans, U16 *Chans,
               U16 BufId, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 SyncMode);
I16 __stdcall D2K_AI_ContScanChannels (U16 CardNumber, U16 Channel,
               U16 BufId, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 SyncMode);
I16 __stdcall D2K_AI_ContReadChannelToFile (U16 CardNumber, U16 Channel, U16 BufId,
               U8 *FileName, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 SyncMode);
I16 __stdcall D2K_AI_ContReadMultiChannelsToFile (U16 CardNumber, U16 NumChans, U16 *Chans,
               U16 BufId, U8 *FileName, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 SyncMode);
I16 __stdcall D2K_AI_ContScanChannelsToFile (U16 CardNumber, U16 Channel, U16 BufId,
               U8 *FileName, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 SyncMode);
I16 __stdcall D2K_AI_ContStatus (U16 CardNumber, U16 *Status);
I16 __stdcall D2K_AI_ContVScale (U16 wCardNumber, U16 adRange, void *readingArray, F64 *voltageArray, I32 count);
I16 __stdcall D2K_AI_AsyncCheck (U16 CardNumber, BOOLEAN *Stopped, U32 *AccessCnt);
I16 __stdcall D2K_AI_AsyncClear (U16 CardNumber, U32 *StartPos, U32 *AccessCnt);
I16 __stdcall D2K_AI_AsyncDblBufferHalfReady (U16 CardNumber, BOOLEAN *HalfReady, BOOLEAN *StopFlag);
I16 __stdcall D2K_AI_AsyncDblBufferMode (U16 CardNumber, BOOLEAN Enable);
I16 __stdcall D2K_AI_AsyncDblBufferToFile (U16 CardNumber);
I16 __stdcall D2K_AI_ContBufferSetup (U16 wCardNumber, void *pwBuffer, U32 dwReadCount, U16 *BufferId);
I16 __stdcall D2K_AI_ContBufferReset (U16 wCardNumber);
I16 __stdcall D2K_AI_MuxScanSetup (U16 wCardNumber, U16 wNumChans, U16* pwChans, U16* pwAdRange_RefGnds);
I16 __stdcall D2K_AI_ReadMuxScan (U16 wCardNumber, U16 *pwBuffer);
I16 __stdcall D2K_AI_ContMuxScan (U16 wCardNumber, U16 BufId, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 wSyncMode);
I16 __stdcall D2K_AI_ContMuxScanToFile (U16 wCardNumber, U16 BufId, U8 *fileName, U32 ReadScans, U32 ScanIntrv, U32 SampIntrv, U16 wSyncMode);
I16 __stdcall D2K_AI_EventCallBack (U16 wCardNumber, I16 mode, I16 EventType, U32 callbackAddr);
I16 __stdcall D2K_AI_AsyncReTrigNextReady (U16 wCardNumber, BOOLEAN *trgReady, BOOLEAN *StopFlag, U16 *RdyTrigCnt);
I16 __stdcall D2K_AI_AsyncDblBufferHandled (U16 wCardNumber);
I16 __stdcall D2K_AI_AsyncDblBufferOverrun (U16 wCardNumber, U16 op, U16 *overrunFlag);
/*---------------------------------------------------------------------------*/
I16 __stdcall D2K_AO_CH_Config (U16 wCardNumber, U16 wChannel, U16 wOutputPolarity, U16 wIntOrExtRef, F64 refVoltage);
I16 __stdcall D2K_AO_Config (U16 wCardNumber, U16 ConfigCtrl, U16 TrigCtrl, U16 ReTrgCnt, U16 DLY1Cnt, U16 DLY2Cnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AO_PostTrig_Config (U16 wCardNumber, U16 ClkSrc, U16 TrigSrcCtrl, U16 DLY2Ctrl, U16 DLY2Cnt, U16 ReTrgEn, U16 ReTrgCnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AO_DelayTrig_Config (U16 wCardNumber, U16 ClkSrc, U16 TrigSrcCtrl, U16 DLY1Cnt, U16 DLY2Ctrl, U16 DLY2Cnt, U16 ReTrgEn, U16 ReTrgCnt, BOOLEAN AutoResetBuf);
I16 __stdcall D2K_AO_InitialMemoryAllocated (U16 CardNumber, U32 *MemSize);
I16 __stdcall D2K_AO_WriteChannel (U16 CardNumber, U16 Channel, I16 Value);
I16 __stdcall D2K_AO_VWriteChannel (U16 CardNumber, U16 Channel, F64 Voltage);
I16 __stdcall D2K_AO_VoltScale (U16 CardNumber, U16 Channel, F64 Voltage, I16 *binValue);
I16 __stdcall D2K_AO_ContWriteChannel (U16 wCardNumber, U16 wChannel,
        U16 BufId, U32 dwUpdateCount, U32 wIterations, U32 dwCHUI, U16 definite, U16 wSyncMode);
I16 __stdcall D2K_AO_ContWriteMultiChannels (U16 wCardNumber, U16 wNumChans, U16 *pwChans,
        U16 BufId, U32 dwUpdateCount, U32 wIterations, U32 dwCHUI, U16 definite, U16 wSyncMode);
I16 __stdcall D2K_AO_AsyncCheck (U16 CardNumber, BOOLEAN *Stopped, U32 *WriteCnt);
I16 __stdcall D2K_AO_AsyncClear (U16 CardNumber, U32 *WriteCnt, U16 stop_mode);
I16 __stdcall D2K_AO_AsyncDblBufferHalfReady (U16 CardNumber, BOOLEAN *HalfReady);
I16 __stdcall D2K_AO_AsyncDblBufferMode (U16 CardNumber, BOOLEAN Enable);
I16 __stdcall D2K_AO_SimuWriteChannel (U16 wCardNumber, U16 wNumChans, U16 *pwBuffer);
I16 __stdcall D2K_AO_ContBufferSetup (U16 wCardNumber, void *pwBuffer, U32 dwWriteCount, U16 *BufferId);
I16 __stdcall D2K_AO_ContBufferReset (U16 wCardNumber);
I16 __stdcall D2K_AO_ContStatus (U16 CardNumber, U16 *Status);
I16 __stdcall D2K_AO_ContBufferComposeAll (U16 wCardNumber, U16 group, U32 dwUpdateCount, void *ConBuffer, void * pwBuffer, BOOLEAN fifoload);
I16 __stdcall D2K_AO_ContBufferCompose (U16 wCardNumber, U16 group, U16 wChannel, U32 dwUpdateCount, void *ConBuffer, void *pwBuffer, BOOLEAN fifoload);
I16 __stdcall D2K_AO_EventCallBack (U16 wCardNumber, I16 mode, I16 EventType, U32 callbackAddr);
/*---------------------------------------------------------------------------*/
I16 __stdcall D2K_AO_Group_Setup (U16 wCardNumber, U16 group, U16 wNumChans, U16 *pwChans);
I16 __stdcall D2K_AO_Group_Update (U16 CardNumber,  U16 group, I16 *pwBuffer);
I16 __stdcall D2K_AO_Group_VUpdate (U16 CardNumber,  U16 group, F64 *pVoltage);
I16 __stdcall D2K_AO_Group_FIFOLoad (U16 wCardNumber, U16 group, U16 BufId, U32 dwWriteCount);
I16 __stdcall D2K_AO_Group_WFM_StopConfig (U16 wCardNumber, U16 group, U16 stopSrc, U16 stopMode);
I16 __stdcall D2K_AO_Group_WFM_Start (U16 wardNumber, U16 group, U16 fstBufIdOrNotUsed, U16 sndBufId,
        U32 dwUpdateCount, U32 wIterations, U32 dwCHUI, U16 definite);
I16 __stdcall D2K_AO_Group_WFM_AsyncCheck (U16 CardNumber, U16 group, U8 *Stopped, U32 *WriteCnt);
I16 __stdcall D2K_AO_Group_WFM_AsyncClear (U16 CardNumber, U16 group, U32 *WriteCnt, U16 stop_mode);
/*---------------------------------------------------------------------------*/
I16 __stdcall D2K_DI_ReadLine (U16 CardNumber, U16 Port, U16 Line, U16 *State);
I16 __stdcall D2K_DI_ReadPort (U16 CardNumber, U16 Port, U32 *Value);
/*---------------------------------------------------------------------------*/
I16 __stdcall D2K_DO_WriteLine (U16 CardNumber, U16 Port, U16 Line, U16 Value);
I16 __stdcall D2K_DO_WritePort (U16 CardNumber, U16 Port, U32 Value);
I16 __stdcall D2K_DO_ReadLine (U16 CardNumber, U16 Port, U16 Line, U16 *Value);
I16 __stdcall D2K_DO_ReadPort (U16 CardNumber, U16 Port, U32 *Value);
/*---------------------------------------------------------------------------*/
I16 __stdcall D2K_DIO_PortConfig (U16 CardNumber, U16 Port, U16 Direction);
/*---------------------------------------------------------------------------*/
I16 __stdcall D2K_GCTR_Setup (U16 wCardNumber, U16 wGCtr, U16 wMode, U8 SrcCtrl, U8 PolCtrl, U16 LReg1_Val, U16 LReg2_Val);
I16 __stdcall D2K_GCTR_Control (U16 wCardNumber, U16 wGCtr, U16 ParamID, U16 Value);
I16 __stdcall D2K_GCTR_Reset (U16 wCardNumber, U16 wGCtr);
I16 __stdcall D2K_GCTR_Read (U16 wCardNumber, U16 wGCtr, U32 *pValue);
I16 __stdcall D2K_GCTR_Status (U16 wCardNumber, U16 wGCtr, U16 *pValue);

I16 __stdcall D2K_SSI_SourceConn (U16 wCardNumber, U16 sigCode);
I16 __stdcall D2K_SSI_SourceDisConn (U16 wCardNumber, U16 sigCode);
I16 __stdcall D2K_SSI_SourceClear (U16 wCardNumber);

I16 __stdcall DAQ2205_Acquire_DA_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *da0v_err, F32 *da5v_err);
I16 __stdcall DAQ2205_Acquire_AD_Error(U16 wCardNumber, F32 *gain_err, F32 *bioffset_err, F32 *unioffset_err, F32 *hg_bios_err);
I16 __stdcall DAQ2206_Acquire_DA_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *da0v_err, F32 *da5v_err);
I16 __stdcall DAQ2206_Acquire_AD_Error(U16 wCardNumber, F32 *gain_err, F32 *bioffset_err, F32 *unioffset_err, F32 *hg_bios_err);
I16 __stdcall DAQ2213_Acquire_AD_Error(U16 wCardNumber, F32 *gain_err, F32 *bioffset_err, F32 *unioffset_err, F32 *hg_bios_err);
I16 __stdcall DAQ2214_Acquire_DA_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *da0v_err, F32 *da5v_err);
I16 __stdcall DAQ2214_Acquire_AD_Error(U16 wCardNumber, F32 *gain_err, F32 *bioffset_err, F32 *unioffset_err, F32 *hg_bios_err);
I16 __stdcall DAQ2010_Acquire_AD_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *gain_err, F32 *offset_err);
I16 __stdcall DAQ2010_Acquire_DA_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *gain_err, F32 *offset_err);
I16 __stdcall DAQ2005_Acquire_AD_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *gain_err, F32 *offset_err);
I16 __stdcall DAQ2005_Acquire_DA_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *gain_err, F32 *offset_err);
I16 __stdcall DAQ2006_Acquire_AD_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *gain_err, F32 *offset_err);
I16 __stdcall DAQ2006_Acquire_DA_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *gain_err, F32 *offset_err);
I16 __stdcall DAQ2204_Acquire_DA_Error(U16 wCardNumber, U16 channel, U16 polarity, F32 *da0v_err, F32 *da5v_err);
I16 __stdcall DAQ2204_Acquire_AD_Error(U16 wCardNumber, F32 *gain_err, F32 *bioffset_err, F32 *unioffset_err, F32 *hg_bios_err);
I16 __stdcall DAQ2208_Acquire_AD_Error(U16 wCardNumber, F32 *gain_err, F32 *bioffset_err, F32 *unioffset_err, F32 *hg_bios_err);
I16 __stdcall DAQ250X_Acquire_DA_Error(I16 wCardNumber, U16 channel, U16 polarity, float *gain_err, float *offset_err);
I16 __stdcall DAQ250X_Acquire_AD_Error(I16 wCardNumber, U16 polarity, float *gain_err, float *offset_err);
I16 __stdcall D2K_DB_Auto_Calibration_ALL(U16 wCardNumber);
I16 __stdcall D2K_EEPROM_CAL_Constant_Update(U16 wCardNumber, U16 bank);
I16 __stdcall D2K_Load_CAL_Data(U16 wCardNumber, U16 bank);

I16 __stdcall D2K_AI_GetEvent(U16 wCardNumber, HANDLE *hEvent);
I16 __stdcall D2K_AO_GetEvent(U16 wCardNumber, HANDLE *hEvent);
I16 __stdcall D2K_DI_GetEvent(U16 wCardNumber, HANDLE *hEvent);
I16 __stdcall D2K_DO_GetEvent(U16 wCardNumber, HANDLE *hEvent);

#ifdef __cplusplus
}
#endif

#endif		//D2K_DASK_H
