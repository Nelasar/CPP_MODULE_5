#pragma once
#include"MoneyCalculation.h"
#include"DrinkSlot.h"

namespace homework {
	class VendingMachine
	{
	private:
		DrinkSlot** drinkSlots = nullptr;
		MoneyCalculation* moneyCalculation = nullptr;//Денежная машина

		int slots = 0;
		int _rows = 0; //Столбцы и строки для двумерного динамического массива
		int _columns = 0;
		bool isActive = true;//Флаг работы машины
		
		struct CopyOfGoods {
			std::string c_name = "";
			int c_cost = 0;
			int c_volume = 0;
			int c_number = 0;
		};
		CopyOfGoods** copies = nullptr; //Копии понадобились для корректной работы функции перезаполнения слота.

		//Массивы ниже нужны для случайной генерации содержимого вендинговой машины
		std::string names[6] = { "Coca-Cola", "Pepsi", "Sprite", "Fanta", "7Up", "MountainDew" };
		int costs[6] = { 120, 100, 150, 90, 50, 89 };
		int volumes[6] = { 1500, 1000, 2000, 500, 750, 333 };

	public:
		VendingMachine();
		VendingMachine(int rows, int columns, int _amount);
		~VendingMachine();

		void refillSlots();
		void successBuying(int i, int j);
		void printInfoMachine();
		void process();
	};
}