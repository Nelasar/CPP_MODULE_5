#include <iostream>
#include "VendingMachine.h"

using namespace homework;

int main()
{
	//Большинство заморочек в программе, костылей и прочего имеются для того, чтобы функция main
	//содержала в себе по сути три строчки.
	//Создаётся переменная вендингового аппарат и вызывается функция, отвечающая за весь процесс торговли. 

	VendingMachine* vendingMachine = new VendingMachine(2, 3, 5);

	vendingMachine->process();

	return 0;
}