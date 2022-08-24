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
		/// ŒÕ—“–” “Œ–€
		DrinkSlot();
		DrinkSlot(int);
		DrinkSlot(int, std::string name, int cost, int volume);
		DrinkSlot(DrinkSlot& other);
		/// ŒÕ—“–” “Œ–€
		~DrinkSlot();
		/// ŒÕ—“–” “Œ–€
		int getAmount();
		int getCount();
		int getNumber();
		Drink& getDrink();
		std::string getDrinkName();
		int getCost();
		int getVolume();
		/// ŒÕ—“–” “Œ–€
		void setNumber(int n);
		void setAmount(int);
		void setCount(int count);
		/// ŒÕ—“–” “Œ–€
		void printInfo();
		void addDrink(Drink drink);
		Drink& giveDrink();
		void fillSlot(Drink drink);

		DrinkSlot& operator--();
		DrinkSlot& operator++();
		Drink& operator[](int index);
	};
}
