//***************************************************************************
// �ļ���Thinner.h
// ���ܣ����ֲ�ͬ��ϸ���㷨
//***************************************************************************

void beforethin(unsigned char *ip, unsigned char *jp, 
				unsigned long lx, unsigned long ly);
void ThinnerHilditch(void *image, unsigned long lx, unsigned long ly);
void ThinnerPavlidis(void *image, unsigned long lx, unsigned long ly);
void ThinnerRosenfeld(void *image, unsigned long lx, unsigned long ly);
//ע��ú���lWidthӦ����Height��
BOOL WINAPI ThiningDIBSkeleton (LPSTR lpDIBBits, LONG lWidth, LONG lHeight);