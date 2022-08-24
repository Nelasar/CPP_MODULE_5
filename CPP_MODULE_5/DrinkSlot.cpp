#include "DrinkSlot.h"

namespace homework {
	///КОНСТРУКТОРЫ
	DrinkSlot::DrinkSlot(DrinkSlot& other) {
		this->amount = other.amount;
		this->count = other.count;
		this->drinks = other.drinks;
	}
	DrinkSlot::DrinkSlot() {
		amount = 10;
		drinks = new Drink[amount];
		count = 0;
	};
	DrinkSlot::DrinkSlot(int _amount = 10) : amount(_amount)
	{
		count = 0;
		drinks = new Drink[amount]();
	}
	DrinkSlot::DrinkSlot(int _amount, std::string _name, int _cost, int _volume) : amount(_amount), count(_amount)
	{
		Drink drink{ _name, _cost, _volume };
		drinks = new Drink[amount]();

		for (int i = 0; i < count; i++) {
			drinks[i] = drink;
		}
	}

	DrinkSlot::~DrinkSlot() {
		delete[] drinks;
	}
	///ФУНКЦИИ-ЧЛЕНЫ
	//Функция заполнения пустого слота
	void DrinkSlot::fillSlot(Drink drink) {
		for (int i = 0; i < amount; i++) {
			drinks = new Drink[amount]();
			drinks[i] = drink;
		}
	}
	//Функция вывода информации о слоте
	void DrinkSlot::printInfo() {
		if (!count) {
			std::cout << "Slot is empty!" << std::endl;

			return;
		}
		for (int i = 0; i < count; i++) {
			std::cout << drinks[i] << std::endl;
		}
	}
	//Функция добавления напитка в слот
	void DrinkSlot::addDrink(Drink drink) {
		drinks[count] = drink;
		++count;
	}
	//Функция выдачи напитка
	Drink& DrinkSlot::giveDrink() {
		Drink* _drinks = new Drink[amount](); //Создаём дополнительный массив

		for (int i = 0; i < count - 1; i++) {
			_drinks[i] = drinks[i]; //Копируем старый в новый
		}
		for (int i = 0; i < count; i++) {
			drinks[i] = _drinks[i]; //Копируем новый в старый, но уже без последнего элемента-напитка
		}

		delete[] _drinks;//удаляем новый массив
		
		--count;//Уменьшаем актуально количество напитков
		std::cout << "Here is your drink!" << std::endl;

		return drinks[0]; //Возвращаем напиток, для корректной работы функции, зависящих от этой. Ну и это логично - даём напиток, значит возвращаем его
	}
	/// 
	/// 
	///ГЕТТЕРЫ
	Drink& const DrinkSlot::getDrink() { return drinks[0]; }
	int  const DrinkSlot::getAmount() { return amount; }
	int const DrinkSlot::getCount() { return count; }
	std::string const DrinkSlot::getDrinkName() { return drinks->getName(); }
	int const DrinkSlot::getCost() { return drinks->getCost(); }
	int const DrinkSlot::getVolume() { return drinks->getVolume(); }
	int const DrinkSlot::getNumber() { return number; }
	///СЕТТЕРЫ
	void DrinkSlot::setNumber(int n) { number = n; }
	void DrinkSlot::setAmount(int amount) { this->amount = amount; }
	void DrinkSlot::setCount(int count) { this->count = count; }
	/// 
	///
	///ПЕРЕГРУЖЕННЫЕ ОПЕРАТОРЫ
	DrinkSlot& DrinkSlot::operator--() {
		--amount;
		return *this;
	}
	DrinkSlot& DrinkSlot::operator++() {
		++amount;
		return *this;
	}
	Drink& DrinkSlot::operator[](int index) {
		return drinks[index];
	}
}