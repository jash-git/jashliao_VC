#ifndef __NEWMODEL_H__
#define __NEWMODEL_H__
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
////////////////////////////////////////////////////////////////////////

	GLfloat view_x=0.0f;
	GLfloat view_y=0.0f;
	GLfloat view_z=0.0f;
////////////////////////////////////////////////////////////////////////
	static GLfloat Base_W1 = 750.0f;
	static GLfloat Base_L1 = 750.0f;
	static GLfloat Base_H1 = 56.0f;

	static GLfloat Base_W2 = 75.0f;
	static GLfloat Base_L2 = 215.0f;
	static GLfloat Base_H2 = 100.0f;

	static GLfloat shift_1 = 202.0f;
	static GLfloat shift_2 = 166.0f;
	static GLfloat shift_3 = 13.0f;
	static GLfloat shift_4 = 100.0f;
	static GLfloat shift_5 = 85.0f;

	static GLfloat Base_W3 = 600.0f;
	static GLfloat Base_L3 = 40.0f;
	static GLfloat Base_H3 = 27.0f;
	
	static GLfloat Base_W4 = 580.0f;
	static GLfloat Base_L4 = 20.0f;
	static GLfloat Base_H4 = 15.0f;
	
	static GLfloat Base_W5 = 45.82f;
	static GLfloat Base_L5 = 215.0f;
	static GLfloat Base_H5 = 150.0f;

	static GLfloat Base_W6 = 29.18f;
	static GLfloat Base_L6 = 215.0f;
	static GLfloat Base_H6 = 150.0f;

	static GLfloat Base_W7 = 100.0f;
	static GLfloat Base_L7 = 215.0f;
	static GLfloat Base_H7 = 30.0f;
	// Rotation amounts

	static GLfloat aRotate = 0.0f;
	static GLfloat bRotate = 0.0f;
	
///////////////////////////////////////////////////////////////////////////////////
	static GLfloat X_Base_W1 = 260.0f;
	static GLfloat X_Base_L1 = 550.0f;
	static GLfloat X_Base_H1 = 12.0f;

	static GLfloat X_Base_W2 = 20.0f;
	static GLfloat X_Base_L2 = 520.0f;
	static GLfloat X_Base_H2 = 15.0f;

	static GLfloat shift_6 = 60.0f;
	static GLfloat shift_7 = 140.0f;
	static GLfloat shift_8 = 7.0f;
	static GLfloat shift_9 = 20.0f;
	static GLfloat shift_10 = 17.0f;
	static GLfloat shift_11 = 20.0f;

	static GLfloat X_Base_W3 = 60.0f;
	static GLfloat X_Base_L3 = 70.0f;
	static GLfloat X_Base_H3 = 43.0f;

	static GLfloat X_Base_W4 = 75.7f;
	static GLfloat X_Base_L4 = 44.0f;
	static GLfloat X_Base_H4 = 15.0f;

	static GLfloat X_Base_W5 = 75.7f;
	static GLfloat X_Base_L5 = 12.0f;
	static GLfloat X_Base_H5 = 10.0f;

	static GLfloat X_Base_W6 = 140.0f;
	static GLfloat X_Base_L6 = 550.0f;
	static GLfloat X_Base_H6 = 3.0f;

	static GLfloat X_Base_W7 = 20.0f;
	static GLfloat X_Base_L7 = 520.0f;
	static GLfloat X_Base_H7 = 10.72f;
	//////////////////////////////////////////////////////////////

	static GLfloat Y_Base_W1 = 260.0f;
	static GLfloat Y_Base_L1 = 270.0f;
	static GLfloat Y_Base_H1 = 20.0f;

	static GLfloat Y_Base_W2 = 60.0f;
	static GLfloat Y_Base_L2 = 70.0f;
	static GLfloat Y_Base_H2 = 38.0f;

	static GLfloat shift_12 = 20.0f;
	static GLfloat shift_13 = 8.0f;
	static GLfloat shift_14 = 20.0f;
	static GLfloat shift_15 = 17.0f;

	static GLfloat Y_Base_W3 = 260.0f;
	static GLfloat Y_Base_L3 = 20.0f;
	static GLfloat Y_Base_H3 = 25.0f;

	static GLfloat Y_Base_W4 = 75.7f;
	static GLfloat Y_Base_L4 = 44.0f;
	static GLfloat Y_Base_H4 = 15.0f;

	static GLfloat Y_Base_W5 = 75.7f;
	static GLfloat Y_Base_L5 = 12.0f;
	static GLfloat Y_Base_H5 = 10.0f;
	//////////////////////////////////////////////////////////////
	static GLfloat left_support_W1 = 85.0f;
	static GLfloat left_support_L1 = 144.0f;
	static GLfloat left_support_H1 = 120.0f;

	static GLfloat shift_18 = 72.5f;
	static GLfloat shift_19 = 4.0f;
	static GLfloat shift_20 = 84.0f;

	static GLfloat radius_1 = 35.0f;
	static GLfloat radius_2 = 20.0f;

	static GLfloat left_support_W2 = 157.5f;
	static GLfloat left_support_L2 = 60.0f;
	static GLfloat left_support_H2 = 40.0f;

	static GLfloat left_support_W3 = 87.0f;
	static GLfloat left_support_W4 = 92.0f;
	//////////////////////////////////////////////////////////////////
	static GLfloat right_support_W1 = 80.0f;
	static GLfloat right_support_L1 = 50.0f;
	static GLfloat right_support_H1 = 79.0f;

	static GLfloat right_support_W2 = 120.0f;
	static GLfloat right_support_L2 = 50.0f;
	static GLfloat right_support_H2 = 15.0f;

	static GLfloat right_support_U3 = 40.0f;
	static GLfloat right_support_L3 = 80.0f;
	static GLfloat right_support_H3 = 20.0f;
	static GLfloat right_support_W3 = 50.0f;
	///////////////////////////////////////////////////////////////
	static GLfloat watchcase_support_W1 = 400.0f;
	static GLfloat watchcase_support_L1 = 25.0f;
	static GLfloat watchcase_support_H1 = 120.0f;

	static GLfloat shift_25 = 9.0f;
	static GLfloat shift_26 = 10.0f;
	static GLfloat shift_27 = 5.0f;
	static GLfloat shift_28 = 10.0f;

	static GLfloat watchcase_support_radius_1 = 35.0f;
	static GLfloat watchcase_support_radius_2 = 27.5f;
	static GLfloat watchcase_support_radius_3 = 15.6f;
	static GLfloat watchcase_support_radius_4 = 12.5f;

	static GLfloat watchcase_support_W2 = 20.0f;
	static GLfloat watchcase_support_L2 = 30.0f;
	static GLfloat watchcase_support_H2 = 120.0f;

	static GLfloat watchcase_support_W3 = 51.96f;
	static GLfloat watchcase_support_L3 = 120.0f;
	static GLfloat watchcase_support_H3 = 30.0f;
	////////////////////////////////////////////////////////////////
	static GLfloat jig_radius_1 = 27.22f;
	static GLfloat jig_radius_2 = 17.5;

	static GLfloat jig_cir_H1 = 6.0f; 
	static GLfloat jig_cir_H2 = 25.0f;

	static GLfloat jig_W3 = 28.0f;
	static GLfloat jig_L3 = 18.0f;
	static GLfloat jig_H3 = 3.5f;
	////////////////////////////////////////////////////////////////////
	static GLfloat Z_axis_W1 = 260.0f;
	static GLfloat Z_axis_L1 = 500.0f;
	static GLfloat Z_axis_H1 = 97.0f;

	static GLfloat Z_axis_L = 320.0f;

	static GLfloat Z_axis_W6 = 35.0f;
	static GLfloat Z_axis_L6 = 500.0f;
	static GLfloat Z_axis_H6 = 97.0f;

	static GLfloat Z_axis_W7 = 190.0f;
	static GLfloat Z_axis_L7 = 50.0f;
	static GLfloat Z_axis_H7 = 97.0f;

	static GLfloat Z_axis_W8 = 56.0f;
	static GLfloat Z_axis_L8 = 500.0f;
	static GLfloat Z_axis_H8 = 10.0f;

	static GLfloat Z_axis_W9 = 108.0f;
	static GLfloat Z_axis_L9 = 105.0f;
	static GLfloat Z_axis_H9 = 10.0f;

	static GLfloat Z_axis_L10 = 75.0f;

	static GLfloat Z_axis_U2 = 178.0f;
	static GLfloat Z_axis_L2 = 260.0f;
	static GLfloat Z_axis_H2 = 46.0f;
	static GLfloat Z_axis_W2 = 500.0f;

	static GLfloat Z_axis_W3 = 220.0f;
	static GLfloat Z_axis_L3 = 500.0f;
	static GLfloat Z_axis_H3 = 10.0f;

	static GLfloat Z_axis_W4 = 130.0f;
	static GLfloat Z_axis_L4 = 500.0f;
	static GLfloat Z_axis_H4 = 3.0f;

	static GLfloat shift_29 = 45.0f;

	static GLfloat Z_axis_W5 = 20.0f;
	static GLfloat Z_axis_L5 = 460.0f;
	static GLfloat Z_axis_H5 = 15.0f;

//////////////////////////////////////////////////////////
	static GLfloat jig_fixed_W1 = 121.5f;
	static GLfloat jig_fixed_L1 = 140.0f;
	static GLfloat jig_fixed_H1 = 71.0f;

	static GLfloat jig_fixed_W2 = 70.0f;
	static GLfloat jig_fixed_L2 = 40.0f;
	static GLfloat jig_fixed_H2 = 71.0f;

	static GLfloat shift_30 = 50.0f;
	static GLfloat shift_31 = 90.0f;
	static GLfloat shift_32 = 83.0f;
	static GLfloat shift_33 = 88.2f;

	static GLfloat jig_fixed_radius_1 = 29.98f;
	static GLfloat jig_fixed_radius_2 = 15.0f;
///////////////////////////////////////////////////////////
	static GLfloat Z_Base_W1 = 210.0f;	
	static GLfloat Z_Base_L1 = 210.0f;
	static GLfloat Z_Base_H1 = 20.0f;

	static GLfloat Z_Base_W2 = 44.0f;
	static GLfloat Z_Base_L2 = 75.7f;
	static GLfloat Z_Base_H2 = 15.0f;

	static GLfloat shift_34 = 8.0f;
	static GLfloat shift_35 = 7.85f;
	static GLfloat shift_36 = 8.0f;
	static GLfloat shift_37 = 151.5f;
	static GLfloat shift_38 = 4.0f;

	static GLfloat Z_Base_W3 = 12.0f;
	static GLfloat Z_Base_L3 = 75.7f;
	static GLfloat Z_Base_H3 = 10.0f;

	static GLfloat Z_Base_W4 = 102.0f;
	static GLfloat Z_Base_L4 = 20.0f;
	static GLfloat Z_Base_H4 = 122.0f;

	static GLfloat Z_Base_W5 = 8.5f;
	static GLfloat Z_Base_L5 = 15.0f;
	static GLfloat Z_Base_H5 = 120.0f;

	static GLfloat Z_Base_W6 = 8.5f;
	static GLfloat Z_Base_L6 = 30.0f;
	static GLfloat Z_Base_H6 = 15.0f;

	static GLfloat Z_Base_W7 = 30.0f;
	static GLfloat Z_Base_L7 = 8.5f;
	static GLfloat Z_Base_H7 = 105.0f;
//////////////////////////////////////////////////////
	static GLfloat main_shaft_W1 = 223.0f;
	static GLfloat main_shaft_L1 = 93.0f;
	static GLfloat main_shaft_H1 = 82.0f;

	static GLfloat main_shaft_W2 = 10.0f;
	static GLfloat main_shaft_L2 = 90.0f;
	static GLfloat main_shaft_H2 = 79.0f;

	static GLfloat main_shaft_radius_1 = 36.0f;
	static GLfloat main_shaft_radius_2 = 19.0f;
	static GLfloat main_shaft_radius_3 = 12.5f;
	static GLfloat main_shaft_radius_4 = 11.0f;
	static GLfloat main_shaft_radius_5 = 12.0f;
	static GLfloat main_shaft_radius_6 = 5.0f;
	static GLfloat main_shaft_radius_7 = 76.2f;

	static GLfloat cir_W1 = 35.5f; 
	static GLfloat cir_W2 = 7.0f;
	static GLfloat cir_W3 = 4.5f;
	static GLfloat cir_W4 = 10.0f;
	static GLfloat cir_W5 = 23.0f;
	static GLfloat cir_W6 = 25.0f;
	static GLfloat cir_W7 = 15.0f;
/////////////////////////////////////////////////////

	static GLfloat motor_W1 = 60.0f;
	static GLfloat motor_L1 = 60.0f;
	static GLfloat motor_H1 = 122.34f;

	static GLfloat motor_radius_1 = 25.0f;
	static GLfloat motor_radius_2 = 6.98f;

	static GLfloat motor_cir_H1 = 3.0f; 
	static GLfloat motor_cir_H2 = 27.0f; 
#endif