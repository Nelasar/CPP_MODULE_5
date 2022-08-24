#pragma once
#include "Drink.h"
namespace homework {
	class DrinkSlot
	{
	private:
		Drink* drinks = nullptr;
		int amount = 10;
		int count = 0;
		int number = 0;
	public:
		///������������
		DrinkSlot();
		DrinkSlot(int);
		DrinkSlot(int, std::string name, int cost, int volume);
		DrinkSlot(DrinkSlot& other);
		///������������
		~DrinkSlot();
		///������������
		int getAmount();
		int getCount();
		int getNumber();
		Drink& getDrink();
		std::string getDrinkName();
		int getCost();
		int getVolume();
		///������������
		void setNumber(int n);
		void setAmount(int);
		void setCount(int count);
		///������������
		void printInfo();
		void addDrink(Drink drink);
		Drink& giveDrink();
		void fillSlot(Drink drink);

		DrinkSlot& operator--();
		DrinkSlot& operator++();
		Drink& operator[](int index);
	};
}
