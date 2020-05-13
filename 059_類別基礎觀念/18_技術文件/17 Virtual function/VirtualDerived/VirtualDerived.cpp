// VirtualDerived.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//虛擬繼承 範例
class Base {
public:
	int getWeight() {         
		return 10;
	}
};
class Land:virtual public Base {
};
class Air:virtual public Base{
};
class AirAuto:public Land,public Air {
};
int main(int argc, char* argv[])
{
	AirAuto cool;
	int weight=cool.getWeight();               // 加入虛擬繼承後,不會有ambigous的問題了
	// int weight=cool.Land::getWeight();
	return 0;
}

