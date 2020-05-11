#include <iostream>
using namespace std;
void procreation(int,void (*run)(char*,int)); /* 以函數指標為參數 */
void slow_run_shoes(char*,int);
void leisure_shoes(char*,int);
void spiked_shoes(char*,int);
int main()
{
	int procreation_number;/* 生產項目代號1~3 */
	int size;/* 尺寸 */
	procreation_number=2;
	size=8;
	switch(procreation_number)
	{
		case 1:
			procreation(size,slow_run_shoes); /* 參數列中傳入函數slow_run_shoes的位址 */
			break;
		case 2:
			procreation(size,leisure_shoes); /* 參數列中傳入函數leisure_shoes的位址 */
			break;
		case 3:
			procreation(size,spiked_shoes); /* 參數列中傳入函數spiked_shoes的位址 */
			break;
		default:
			cout <<"停止生產!!!" <<endl;
	}
	getchar();
	return 0;
}
void procreation(int size,void (*run)(char* material,int size))
{
	char* material; /* 質料名稱 */
	int material_number; /* 質料代號1~3 */
	material_number=3;
	switch(material_number)
	{
		case 1:
			material="布";
			break;
		case 2:
			material="獸皮";
			break;
		case 3:
			material="塑膠";
	}
	(*run)(material,size); /* 呼叫函數指標 */
}
void slow_run_shoes(char* material,int size)
{
	cout <<"以質料為" <<material <<"、尺寸為" <<size <<"來生產慢跑鞋" <<endl;
}
void leisure_shoes(char* material,int size)
{
	cout <<"以質料為" <<material <<"、尺寸為" <<size <<"來生產休閒鞋" <<endl;
}
void spiked_shoes(char* material,int size)
{
	cout <<"以質料為" <<material <<"、尺寸為" <<size <<"來生產釘鞋" <<endl;
}
