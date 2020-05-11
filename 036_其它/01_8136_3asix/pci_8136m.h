#ifndef _PCI_8136_H

#define _PCI_8136_H

#include "motion.h"

#ifdef _WINNT
	#include <windows.h>
#endif

#ifdef _WIN95
    #include <windows.h>
#endif

/****************************************************************************/
/*      Typedef  Definitions                                                */
/****************************************************************************/
typedef unsigned char   U8;
typedef short           I16;
typedef unsigned short  U16;
typedef long            I32;
typedef unsigned long   U32;
typedef float           F32;
typedef double          F64;
typedef char            Boolean;

#define MAX_PCI_CARDS	      4

#define PLS_DIR		0
#define CW_CCW        	1
#define A_B            	2
#define INH            	3
			
#define E_A_B			0
#define E_CW_CCW		1
#define E_PLS_DIR		 2
#define E_INH			 3

#define X0		0
#define X1              1
#define X2              2
#define X4              3

#define CARD0			0
#define CARD1			1
#define CARD2			2
#define CARD3			3

#define ENC0			0
#define ENC1			1
#define ENC2			2
#define ENC3			3
#define ENC4			4
#define ENC5			5

#define CH0				0	
#define CH1             1
#define CH2             2
#define CH3             3
#define CH4             4
#define CH5             5

#define AXIS0			0
#define AXIS1           1
#define AXIS2           2
#define AXIS3           3
#define AXIS4           4
#define AXIS5           5

#define ENABLE			1
#define DISABLE			0

#define TRUE			1
#define FALSE			0

#define ON				1
#define OFF				0

#define PCL				1
#define DAC				0

#define START			1
#define STOP			0

#define motion_range  3666  //°¨¹F²¾°Ê¶ZÂ÷

#define ORG1 0
#define PEL1 6
#define MEL1 7
#define DO1  0

#define ORG2 1
#define PEL2 8
#define MEL2 9
#define DO2  1
//
#define ORG3 2
#define PEL3 10
#define MEL3 11
#define DO3  2

#define ORG4 3
#define PEL4 12
#define MEL4 13
#define DO4  3
//
#define ORG5 4
#define PEL5 14
#define MEL5 15
#define DO5  4

#define ORG6 5
#define PEL6 16
#define MEL6 17
#define DO6  5


//****************************************************************************
//      Error Code Definition
//****************************************************************************
enum {
    ERR_NoError,						//0
    ERR_BoardNoInit,                    //1
    ERR_InvalidBoardNumber,             //2
    ERR_InitializedBoardNumber,         //3
    ERR_BaseAddressError,               //4
    ERR_BaseAddressConflict,            //5
    ERR_DuplicateBoardSetting,          //6
    ERR_DuplicateIrqSetting,            //7
    ERR_PCIBiosNotExist,                //8
    ERR_PCIIrqNotExist,                 //9
    ERR_PCICardNotExist,                //10
    ERR_EncNoError,                     //11
    ERR_ModuleNoError,                  //12
    ERR_TimerValueError,                //13
    ERR_EnableError,                    //14
    ERR_RangeError,                     //15
    ERR_MemAllocError,                  //16
    ERR_MotionBusy,                     //17
	ERR_MotionNotStart,					//18
	ERR_SpeedError,						//19
	ERR_AccTimeError,					//20
	ERR_IOAlarmError,					//21
	ERR_OpenFileFail,					//22
	ERR_MemAllocateError,				//23
	ERR_MemNotFree,						//24
	ERR_OutputFileNotClose,				//25
	ERR_MoveAxisNotMatch,				//26
	ERR_PitchZero,						//27
};

/****************************************************************************/
/*      Function  Declerations                                              */
/****************************************************************************/

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef _WINNT95
I16 FNTYPE _8136_INT_Enable(I16 card_number,HANDLE *phEvent);
I16 FNTYPE _8136_INT_Disable(I16 card_number);
I16 FNTYPE _8136_M_Start_Motion_File(I16 CardNo,I16 MoveAxis, I16 *AxisArray,char *FileName);
I16 FNTYPE _8136_M_Create_Motion_File(char *FileName);
I16 FNTYPE _8136_M_Check_Create_Motion_File_Done(void);
I16 FNTYPE _8136_M_Stop_Motion_File(I16 CardNo,I16 TotalAxis, I16 *AxisArray);
void FNTYPE _8136_Callback_Function(I16 CardNo,void ( _stdcall *callbackAddr)(I16 AxisNo, U16 IntSts));
#endif

// System
I16 FNTYPE _8136_Initial(I16 *existCards);
void FNTYPE _8136_S_INT_Control(I16 cardNo, I16 intFlag );
I16 FNTYPE _8136_S_Close(I16 cardNo);
I16 FNTYPE _8136_S_Set_Int_Factor(I16 CardNo, I16 AxisNo, I16 IntFactor, I16 Option);
I16 FNTYPE _8136_S_Set_Timer_Value(I16 CardNo,U32 TimerValue);
I16 FNTYPE _8136_S_Get_Int_Status(I16 CardNo,I16 AxisNo,U16 *IntStatus);
void FNTYPE _8136_S_Get_IRQ_Channel(I16 cardNo, U16 *irq_no );
void FNTYPE _8136_S_Get_Base_Addr(I16 cardNo, U16 *base_addr );

// LIO
I16 FNTYPE _8136_D_Output(I16 CardNo,I16 Channel,I16 Control);
I16 FNTYPE _8136_D_Input(I16 CardNo,I16 Channel,I16* Control);
I16 FNTYPE _8136_D_OutputA(I16 CardNo,I16 Value);
I16 FNTYPE _8136_D_InputA(I16 CardNo,I32 *Value);

// RIO
I16 FNTYPE _8136_R_Initial(I16 CardNo,I16 SlaveNo,I16 SlaveControl);
I16 FNTYPE _8136_R_Set_RIO_Clk(I16 CardNo, I16 SlaveNo, I16 Clk_Divider);
I16 FNTYPE _8136_R_Status(I16 CardNo,I16 SlaveNo);
I16 FNTYPE _8136_R_Write(I16 CardNo,I16 SlaveNo,I16 SetNo,U16 SetValue);
I16 FNTYPE _8136_R_Read(I16 CardNo,I16 SlaveNo,I16 SetNo,U16 *SetValue);

// Analog
I16 FNTYPE _8136_A_Initial(I16 CardNo);
I16 FNTYPE _8136_A_Set_DAC_Clk(I16 CardNo, I16 Clk_Divider);
I16 FNTYPE _8136_A_Set_ADC_Clk(I16 CardNo, I16 Clk_Divider);
I16 FNTYPE _8136_A_Write_Value(I16 CardNo, I16 Channel, I16 Value);
I16 FNTYPE _8136_A_Write_Volt(I16 CardNo, I16 Channel, F64 Volt);
I16 FNTYPE _8136_A_Set_Source(I16 CardNo,I16 Channel,I16 Source);
I16 FNTYPE _8136_A_Set_Trigger_Map(I16 CardNo,I16 Channel,I16 Source);
I16 FNTYPE _8136_A_Set_Trigger(I16 CardNo,I16 Channel,I16 Control);
I16 FNTYPE _8136_A_Set_Preload_Volt(I16 CardNo, I16 Channel, F64 Volt);
I16 FNTYPE _8136_A_Read_Value(I16 CardNo, I16 Channel, I16 *Value);
I16 FNTYPE _8136_A_Read_Volt(I16 CardNo, I16 Channel, F64 *Volt);
I16 FNTYPE _8136_A_Output_Control(I16 CardNo, I16 Channel, I16 Control);
I16 FNTYPE _8136_A_Set_Compare_Value(I16 CardNo, I16 Channel, I16 Value);
I16 FNTYPE _8136_A_Set_Compare_Volt(I16 CardNo, I16 Channel, F64 Volt);

// Close Loop Control
I16 FNTYPE _8136_C_Initial(I16 CardNo, I16 AxisNo);
I16 FNTYPE _8136_C_Set_Gain(I16 cardNo, I16 Axis,I16 Kp1,I16 Kp2);

//PIO
I16 FNTYPE _8136_P_Initial(I16 CardNo);
I16 FNTYPE _8136_P_Set_Output_Type(I16 CardNo, I16 AxisNo, I16 PulseFmt);
I16 FNTYPE _8136_P_Set_Input_Type(I16 CardNo, I16 EncNo, I16 EncFmt, I16 Mul);
I16 FNTYPE _8136_P_Read(I16 CardNo, I16 EncNo, I32 *EncData);
I16 FNTYPE _8136_P_Send(I16 CardNo,I16 AxisNo,F64 Frq);
I16 FNTYPE _8136_P_Stop(I16 CardNo,I16 AxisNo);
I16 FNTYPE _8136_P_Clear(I16 CardNo, I16 EncNo);
I16 FNTYPE _8136_P_Set_Compare_Value(I16 CardNo,I16 EncNo, I32 CompValue);
I16 FNTYPE _8136_P_Set_Index_Latch(I16 CardNo, I16 EncNo, I16 Type);
I16 FNTYPE _8136_P_Read_Index(I16 CardNo, I16 AxisNo, I16 *Index);
I16 FNTYPE _8136_P_Read_Latch_Value(I16 CardNo, I16 EncNo, I32 *Value);
I16 FNTYPE _8136_P_Change_Speed(I16 CardNo,I16 AxisNo,F64 Frq);
I16 FNTYPE _8136_P_Set_Enc_Filter(I16 CardNo,I16 Filter);

// Motion
I16 FNTYPE _8136_M_Set_System_Param(I16 CardNo, I16 Speed, I16 CycleTime);
I16 FNTYPE _8136_Start_TR_Move(I16 CardNo,I16 AxisNo,I32 Dist,F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Start_SR_Move(I16 CardNo,I16 AxisNo,I32 Dist,F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Start_TA_Move(I16 CardNo,I16 AxisNo,I32 Dist,F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Start_SA_Move(I16 CardNo,I16 AxisNo,I32 Dist,F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Start_S_Move_XYZ(I16 CardNo, I16* AxisArray,I32 PX, I32 PY, I32 PZ, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Start_Move_XYZ(I16 CardNo, I16* AxisArray,I32 PX, I32 PY, I32 PZ, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Motion_Stop(I16 CardNo,I16 AxisNo);
I16 FNTYPE _8136_Motion_Status(I16 CardNo,I16 AxisNo);
I16 FNTYPE _8136_V_Move(I16 CardNo,I16 AxisNo,F64 StrVel,F64 MaxVel,F64 Tacc);
I16 FNTYPE _8136_SV_Move(I16 CardNo,I16 AxisNo,F64 StrVel,F64 MaxVel,F64 Tacc);
I16 FNTYPE _8136_Home_Move(I16 CardNo,I16 AxisNo,F64 StrVel,F64 MaxVel,F64 Tacc);
I16 FNTYPE _8136_Start_Move_XY(I16 CardNo, I16* AxisArray,I32 PX, I32 PY, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Start_Arc_XY(I16 CardNo, I16* AxisArray, I32 PX, I32 PY, F64 Angle, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8136_Start_Heli_XY(I16 CardNo, I16* AxisArray, I32 PX, I32 PY,I32 Depth, I32 Pitch, I16 Dir,F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8136_Start_S_Heli_XY(I16 CardNo, I16* AxisArray, I32 PX, I32 PY,I32 Depth, I32 Pitch, I16 Dir,F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8136_Start_S_Move_XY(I16 CardNo, I16* AxisArray,I32 PX, I32 PY, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8136_Start_S_Arc_XY(I16 CardNo, I16* AxisArray, I32 PX, I32 PY, F64 Angle, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8136_M_ORG_Status(I16 CardNo,I16 Channel);
I16 FNTYPE _8136_M_PEL_Status(I16 CardNo,I16 Channel);
I16 FNTYPE _8136_M_MEL_Status(I16 CardNo,I16 Channel);
I16 FNTYPE _8136_M_ALM_Status(I16 CardNo);
I16 FNTYPE _8136_M_Switch_Logic(I16 CardNo,I16 Home_Logic, I16 EL_Logic, I16 ALM_Logic);
I16 FNTYPE _8136_M_Set_IO_Active(I16 CardNo, I16 AxisNo, I16 Control);
I16 FNTYPE _8136_M_Get_Speed(I16 CardNo,I16 AxisNo,F64 *Speed);
I16 FNTYPE _8136_M_Set_Feedback(I16 CardNo, I16 AxisNo, I16 Control);
I16 FNTYPE _8136_M_Set_SVON(I16 CardNo, I16 AxisNo, I16 Control);

// Undocument
#ifdef _WINNT95
void FNTYPE _8136_Get_Share_Mem_Data(I16 cardNo,I16 AxisNo, I16* V1, I16* V2, I16 *V3, I32 *V4, I16* F1);
void FNTYPE _8136_DDA_Insert_Queue(I16 CardNo,I16 AxisNo,I16 Cmd);
void FNTYPE _8136_DDA_Reset_Queue(I16 CardNo,I16 AxisNo);
void FNTYPE _8136_DDA_Get_Queue_Size(I16 CardNo,I16 AxisNo,I16 *Size);
#endif
I16 FNTYPE _8136_DDA_Set_Command(I16 cardNo,I16 AxisNo,I16 DDACommand);
I16 FNTYPE _8136_DDA_Start_Stop(I16 CardNo, I16 AxisNo, I16 Control);
I16 FNTYPE _8136_DDA_Get_Stock_Count(I16 cardNo, I16 AxisNo, I16 *StockCount);
I16 FNTYPE _8136_DDA_Start_Stop2(I16 CardNo, I16 AxisNo1, I16 AxisNo2,I16 Control);
I16 FNTYPE _8136_DDA_Start_Stop3(I16 CardNo, I16 AxisNo1, I16 AxisNo2,I16 AxisNo3, I16 Control);
I16 FNTYPE _8136_DDA_Start_Stop4(I16 CardNo, I16 AxisNo1, I16 AxisNo2,I16 AxisNo3, I16 AxisNo4, I16 Control);
I16 FNTYPE _8136_DDA_Start_Stop5(I16 CardNo, I16 AxisNo1, I16 AxisNo2,I16 AxisNo3, I16 AxisNo4, I16 AxisNo5, I16 Control);
I16 FNTYPE _8136_DDA_Start_Stop6(I16 CardNo, I16 AxisNo1, I16 AxisNo2,I16 AxisNo3, I16 AxisNo4, I16 AxisNo5,I16 AxisNo6, I16 Control);

#ifdef _MSDOS
// ISR
void _8136_Set_DDA_Cycle(I16 CardNo, I16 Control);
void FNTYPE _8136_isr0 (void);
void FNTYPE _8136_isr1 (void);
void FNTYPE _8136_isr2 (void);
void FNTYPE _8136_isr3 (void);
I16 FNTYPE _8136_RC_get_position(I16 CardNo, I16 AxisNo, I32 *EncData);
I16 FNTYPE _8136_RC_Set(I16 CardNo, I16 AxisNo, I32 RCValue);
I16 FNTYPE _8136_MVP_V_Change(I16 CardNo, I16 AxisNo, F64 Speed);
I16 FNTYPE _8136_Start_MVP_Move(I16 CardNo, I16 AxisNo, I32 Dist, F64 Vel1, F64 Tacc);
#endif

#ifdef __cplusplus
	}
#endif

#endif