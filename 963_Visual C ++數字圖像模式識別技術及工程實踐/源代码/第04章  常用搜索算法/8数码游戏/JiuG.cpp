// JiuG.cpp: implementation of the CJiuG class.

#include "stdafx.h"
#include "Jiugong.h"
#include "JiuG.h"
#include "math.h"//������ۺ����ǻ��õ�abs()������ô�λ�������ð���
#include "stdlib.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CJiuG::CJiuG()
{
	m_ndepth=100;//����Ĭ�ϵ����Ϊ100�������ڳ����иĶ�
}

CJiuG::~CJiuG()
{

}

/////////////////////////////////////////////////////////////////////
//����
bool CJiuG::MoveLeft(JGState *src,JGState *result)
{
	int x,y,tempx,tempy;
	for(x=0;x<3;x++){
		for(y=0;y<3;y++){
			if(src->state[x][y]==0){
				tempx=x;
				tempy=y;
			}
		}
	}

	if(tempy==0)
		return false;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			result->state[i][j]=src->state[i][j];
		}
	}
	
	result->state[tempx][tempy] = src->state[tempx][tempy-1];
	result->state[tempx][tempy-1] = 0;
	result->curdistance=src->curdistance+1;
	result->prestate=src;
	result->nextstate=NULL;

	return true;
}

////////////////////////////////////////////////////////////////////
//����
bool CJiuG::MoveRight(JGState *src,JGState *result)
{
	int x,y,tempx,tempy;
	for(x=0;x<3;x++){
		for(y=0;y<3;y++){
			if(src->state[x][y]==0){
				tempx=x;
				tempy=y;
			}
		}
	}

	if(tempy==2)
		return false;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			result->state[i][j]=src->state[i][j];
		}
	}

	result->state[tempx][tempy]=src->state[tempx][tempy+1];
	result->state[tempx][tempy+1]=0;
	result->curdistance=src->curdistance+1;
	result->prestate=src;
	result->nextstate=NULL;

	return true;
}

///////////////////////////////////////////////////////////////////
//���ƣ���������ƣ����ƣ���������ƣ��ṹһ��
bool CJiuG::MoveUp(JGState *src,JGState *result)
{
	int x,y,tempx,tempy;
	//Ѱ�ҿո�λ��
	for(x=0;x<3;x++){
		for(y=0;y<3;y++){
			if(src->state[x][y]==0){
				tempx=x;
				tempy=y;
			}
		}
	}

	//�ж��Ƿ����
	if(tempx==0)
		return false;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			result->state[i][j]=src->state[i][j];
		}
	}

	result->state[tempx][tempy]=src->state[tempx-1][tempy];
	result->state[tempx-1][tempy]=0;
	result->curdistance=src->curdistance+1;//��ȼ�һ
	result->prestate=src;//����ǰ���ڵ�
	result->nextstate=NULL;

	return true;
}

////////////////////////////////////////////////////////////////////
//����
bool CJiuG::MoveDown(JGState *src,JGState *result)
{
	int x,y,tempx,tempy;
	for(x=0;x<3;x++){
		for(y=0;y<3;y++){
			if(src->state[x][y]==0){
				tempx=x;
				tempy=y;
			}
		}
	}

	if(tempx==2)
		return false;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			result->state[i][j]=src->state[i][j];
		}
	}

	result->state[tempx][tempy]=result->state[tempx+1][tempy];
	result->state[tempx+1][tempy]=0;
	result->curdistance=src->curdistance+1;
	result->prestate=src;
	result->nextstate=NULL;

	return true;
}

///////////////////////////////////////////////////////////////////
//�Ƚ�����״̬�Ƿ����
bool CJiuG::Compare(JGState *src1,JGState *src2)
{
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			if(src1->state[i][j]!=src2->state[i][j])
				return false;
		}
	}

	return true;
}

///////////////////////////////////////////////////////////////////
//������ۺ�����������ÿһ���Ƶ���ȷ��λ����Ҫ�Ĳ���
int CJiuG::ComputeFn(JGState *cur,JGState *dest)
{
	int xcur[9],ycur[9],xdest[9],ydest[9];//����9������
	int i,j;
	int result=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			xcur[cur->state[i][j]]=i;
			ycur[cur->state[i][j]]=j;
			xdest[dest->state[i][j]]=i;
			ydest[dest->state[i][j]]=j;
		}
	}

	for(i=1;i<9;i++){
		result=result+abs(xcur[i]-xdest[i])+abs(ycur[i]-ydest[i]);
	}

	return result;
	/*int result=0;//ע�͵��Ĳ����ǲ����˴�λ��������
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(cur->state[i][j]!=dest->state[i][j])
				result++;
		}
	}

	return result;*/
}


///////////////////////////////////////////////////////////////////
//�������Ž⣬���ǳ���ĺ��Ĳ���
bool CJiuG::Search()
{
	int MAXDEPTH=m_ndepth;
	FreeList(&OpenList);
	FreeList(&CloseList);
	FreeList(&ResultList);
	JGState *newstate,*pstart;
	int i,k;
	newstate=(JGState *)malloc(sizeof(JGState));
	CopyJG(&StateInit,newstate);
	newstate->curdistance=0;
	newstate->nextstate=NULL;
	newstate->prestate=NULL;
	pstart=newstate;
	curstep=pstart;
	//�����ʼ״̬��ĩ̬��ͬ�������ɹ��˳�
	if(Compare(&StateInit,&StateObj)==true){
		ResultList.AddTail((void *)newstate);
		return true;
	}
	
	//����ʼ������Open����
	OpenList.AddHead((void *)newstate);
	
	//����
	while(true){
		JGState *pmin;
		int nmin;
		int nindex=0;
		//Open��Ϊ�գ�ʧ���˳�
		if(OpenList.IsEmpty())
			return false;
		i=OpenList.GetCount();
		nmin=100000000;
		//����Open���й���ֵ��С�Ľڵ�
		for(k=0;k<i;k++){
			JGState *ptemp;
			ptemp=(JGState *)OpenList.GetAt(OpenList.FindIndex(k));
			int ntemp=ptemp->curdistance+ComputeFn(ptemp,&StateObj);
			if(ntemp<nmin){
				nmin=ntemp;
				pmin=ptemp;
				nindex=k;
			}
		}
	
		//�����ۺ�����С�Ľڵ��Open��ɾ�������뵽Close����
		OpenList.RemoveAt(OpenList.FindIndex(nindex));
		CloseList.AddTail((void *)pmin);

		newstate=(JGState *)malloc(sizeof(JGState));

		//move to left������������ȿ��ơ���������ƣ����ƣ����Ƴ���ṹ��ͬ
		//���Խ���ͬ�Ĳ���д�ɺ�������û��������
		if((MoveLeft(pmin,newstate)==true)&&(newstate->curdistance<=MAXDEPTH)){
			if((Compare(newstate,&StateObj)==false)){
				//����Ŀ��ڵ㣬���Ƿ���Լ��뵽Open����
				bool inopen=false;
				bool inclose=false;
				JGState *ptemp;
				//����Ƿ���Open����
				i=OpenList.GetCount();
				if(i==0)
					inopen=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)OpenList.GetAt(OpenList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inopen=true;
							if(ptemp->curdistance>newstate->curdistance)
								CopyJG(newstate,ptemp);
							break;
						}
					}
				}
				//����Ƿ���Close����
				i=CloseList.GetCount();
				if(i==0)
					inclose=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)CloseList.GetAt(CloseList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inclose=true;
							break;
						}
					}
				}
				if((inopen==false)&&(inclose==false))
					OpenList.AddHead(newstate);
			}//end if
			else{
				//�ҵ�Ŀ����
				JGState *newstate1;
				ResultList.AddHead((void *)newstate);
				newstate=newstate->prestate;
				//���ݣ��õ�ResultList
				while(newstate!=pstart){
					newstate1=(JGState *)malloc(sizeof(JGState));
					CopyJG(newstate,newstate1);
					ResultList.AddHead(newstate1);
					newstate=newstate->prestate;
				}
				newstate1=(JGState *)malloc(sizeof(JGState));
				CopyJG(newstate,newstate1);
				ResultList.AddHead(newstate1);
				return true;
			}//end else
		}//end if 
		else{
			free(newstate);
		}//end move left

		newstate=(JGState *)malloc(sizeof(JGState));

		//move to right
		if(MoveRight(pmin,newstate)==true&&(newstate->curdistance<=MAXDEPTH)){
			if((Compare(newstate,&StateObj)==false)){
				//����Ŀ��ڵ㣬���Ƿ���Լ��뵽Open����
				bool inopen=false;
				bool inclose=false;
				JGState *ptemp;
				i=OpenList.GetCount();
				if(i==0)
					inopen=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)OpenList.GetAt(OpenList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inopen=true;
							if(ptemp->curdistance>newstate->curdistance)
								CopyJG(newstate,ptemp);
							break;
						}
					}
				}
				i=CloseList.GetCount();
				if(i==0)
					inclose=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)CloseList.GetAt(CloseList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inclose=true;
							break;
						}
					}
				}
				if((inopen==false)&&(inclose==false))
					OpenList.AddHead(newstate);
			}//end if
			else{
				//�ҵ�Ŀ����
				JGState *newstate1;
				ResultList.AddHead((void *)newstate);
				newstate=newstate->prestate;
				while(newstate!=pstart){
					newstate1=(JGState *)malloc(sizeof(JGState));
					CopyJG(newstate,newstate1);
					ResultList.AddHead(newstate1);
					newstate=newstate->prestate;
				}
				newstate1=(JGState *)malloc(sizeof(JGState));
				CopyJG(newstate,newstate1);
				ResultList.AddHead(newstate1);
				return true;
			}//end else
		}//end if 
		else{
			free(newstate);
		}//end move right

		newstate=(JGState *)malloc(sizeof(JGState));

		//move to up
		if(MoveUp(pmin,newstate)==true&&(newstate->curdistance<=MAXDEPTH)){
			if((Compare(newstate,&StateObj)==false)){
				//����Ŀ��ڵ㣬���Ƿ���Լ��뵽Open����
				bool inopen=false;
				bool inclose=false;
				JGState *ptemp;
				i=OpenList.GetCount();
				if(i==0)
					inopen=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)OpenList.GetAt(OpenList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inopen=true;
							if(ptemp->curdistance>newstate->curdistance)
								CopyJG(newstate,ptemp);
							break;
						}
					}
				}
				i=CloseList.GetCount();
				if(i==0)
					inclose=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)CloseList.GetAt(CloseList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inclose=true;
							break;
						}
					}
				}
				if((inopen==false)&&(inclose==false))
					OpenList.AddHead(newstate);
			}//end if
			else{
				//�ҵ�Ŀ����
				JGState *newstate1;
				ResultList.AddHead((void *)newstate);
				newstate=newstate->prestate;
				while(newstate!=pstart){
					newstate1=(JGState *)malloc(sizeof(JGState));
					CopyJG(newstate,newstate1);
					ResultList.AddHead(newstate1);
					newstate=newstate->prestate;
				}
				newstate1=(JGState *)malloc(sizeof(JGState));
				CopyJG(newstate,newstate1);
				ResultList.AddHead(newstate1);
				return true;
			}//end else
		}//end if 
		else{
			free(newstate);
		}//end move up

		newstate=(JGState *)malloc(sizeof(JGState));

		//move to down
		if(MoveDown(pmin,newstate)==true&&(newstate->curdistance<=MAXDEPTH)){
			if((Compare(newstate,&StateObj)==false)){
				//����Ŀ��ڵ㣬���Ƿ���Լ��뵽Open����
				bool inopen=false;
				bool inclose=false;
				JGState *ptemp;
				i=OpenList.GetCount();
				if(i==0)
					inopen=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)OpenList.GetAt(OpenList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inopen=true;
							if(ptemp->curdistance>newstate->curdistance)
								CopyJG(newstate,ptemp);
							break;
						}
					}
				}
				i=CloseList.GetCount();
				if(i==0)
					inclose=false;
				else{
					for(k=0;k<i;k++){
						ptemp=(JGState *)CloseList.GetAt(CloseList.FindIndex(k));
						if(Compare(newstate,ptemp)==true){
							inclose=true;
							break;
						}
					}
				}
				if((inopen==false)&&(inclose==false))
					OpenList.AddHead(newstate);
			}//end if
			else{
				//�ҵ�Ŀ����
				JGState *newstate1;
				ResultList.AddHead((void *)newstate);
				newstate=newstate->prestate;
				while(newstate!=pstart){
					newstate1=(JGState *)malloc(sizeof(JGState));
					CopyJG(newstate,newstate1);
					ResultList.AddHead(newstate1);
					newstate=newstate->prestate;
				}
				newstate1=(JGState *)malloc(sizeof(JGState));
				CopyJG(newstate,newstate1);
				ResultList.AddHead(newstate1);
				return true;
			}//end else
		}//end if 
		else{
			free(newstate);
		}//end move down
	}
}

///////////////////////////////////////////////////////////////////
//�ͷ��ڴ�
void CJiuG::FreeList(CPtrList *list)
{
	if(list->IsEmpty())
		return;
	int i=list->GetCount();
	JGState *p;
	for(int j=0;j<i;j++){
		p=(JGState *)list->GetHead();
		list->RemoveHead();
		free(p);
	}
}

void CJiuG::CopyJG(JGState *src,JGState *dest)
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			dest->state[i][j]=src->state[i][j];
		}
	}
	dest->curdistance=src->curdistance;
	dest->prestate=src->prestate;
	dest->nextstate=src->nextstate;
}

//////////////////////////////////////////////////////////////////
//����������ż�ԣ����ж����޽⣬�����ҶԾŹ�������Ƿ�ɴ��֤��
//����0Ϊż������1Ϊ��
int CJiuG::ComputeJO(JGState *jo)
{
	int result=0;
	int i,j;
	int k=0;
	int temp[8];
	//��ȥ0��������8�������μ��뵽������
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(jo->state[i][j]!=0){
				temp[k]=jo->state[i][j];
				k++;
			}
		}
	}
	//�ж���ż��
	for(i=0;i<7;i++){
		for(j=i+1;j<8;j++){
			if(temp[i]>temp[j])
				result++;
		}
	}

	result=result%2;
	return result;
}
