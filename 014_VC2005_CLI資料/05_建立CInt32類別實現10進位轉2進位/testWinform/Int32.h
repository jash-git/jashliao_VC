#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class CInt32
{
public:
	Int32 data;
    CInt32(void);
	CInt32(int);
	CInt32% operator+(int);
	CInt32% operator-(int);
	CInt32% operator*(int);
	CInt32% operator/(int);
	CInt32% operator+(CInt32);
	CInt32% operator-(CInt32);
	CInt32% operator*(CInt32);
	CInt32% operator/(CInt32);
	void operator++();
	void operator--();
	void operator+=(CInt32);
	void operator-=(CInt32);
	void operator*=(CInt32);
	void operator/=(CInt32);
/*
	void operator+=(int);
	void operator-=(int);
	void operator*=(int);
	void operator/=(int);
*/
	void operator=(int r) {
		data = r;
	}
	void operator=(CInt32% r) {
      data = r.data;
   }
	String^ IntToString(void);
	String^ Int10toInt2(void);
private:
protected:
	String^ m_str;
};
