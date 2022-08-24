#include <iostream>
#include "VendingMachine.h"

using namespace homework;

int main()
{
	//Drink cola{ "Coca-Cola", 87, 2000 };
	//DrinkSlot* slot1 = new DrinkSlot(10);

	//slot1->addDrink(cola);
	//slot1->addDrink(cola);
	//slot1->addDrink(cola);
	//
	//slot1->printInfo();
	//
	//std::cout << "NOW GIVE!!!" << std::endl << std::endl;
	//
	//system("pause");
	//system("cls");
	//
	//slot1->giveDrink();
	//slot1->printInfo();

	VendingMachine* vendingMachine = new VendingMachine(2, 3, 5);

 	//vendingMachine->printMachine();
	//vendingMachine->printInfoMachine();
	vendingMachine->process();

	return 0;
}