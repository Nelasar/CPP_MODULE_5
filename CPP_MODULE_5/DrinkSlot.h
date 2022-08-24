#pragma once
#include "Drink.h"
namespace homework {
	class DrinkSlot
	{
	private:
		Drink* drinks = nullptr; //Для создания слота, который, по сути, будет динмаческим массивом напитков
		int amount = 10; //Общее доступное количество напитков в слоте
		int count = 0; // Актуальное количество напитков в слоте
		int number = 0; //Порядковый номер слота
	public:
		///КОНСТРУКТОРЫ
		DrinkSlot();
		DrinkSlot(int);
		DrinkSlot(int, std::string name, int cost, int volume);
		DrinkSlot(DrinkSlot& other);
		///ДЕСТРУКТОРЫ
		~DrinkSlot();
		///ГЕТТЕРЫ
		int const getAmount();
		int const getCount();
		int const getNumber();
		Drink& const getDrink();
		std::string const getDrinkName();
		int const getCost();
		int const getVolume();
		///СЕТТЕРЫ
		void setNumber(int n);
		void setAmount(int);
		void setCount(int count);
		///ФУНКЦИИ-ЧЛЕНЫ
		void printInfo();
		void addDrink(Drink drink);
		Drink& giveDrink();
		void fillSlot(Drink drink);
		//ПЕРЕГРУЖЕННЫЕ ОПЕРАТОРЫ
		DrinkSlot& operator--();
		DrinkSlot& operator++();
		Drink& operator[](int index);
	};
}
