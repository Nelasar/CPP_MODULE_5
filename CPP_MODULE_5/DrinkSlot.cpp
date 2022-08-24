#include "DrinkSlot.h"

namespace homework {
	/// ŒÕ—“–” “Œ–€
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
	///‘”Õ ÷»»-◊À≈Õ€
	void DrinkSlot::fillSlot(Drink drink) {
		for (int i = 0; i < amount; i++) {
			drinks = new Drink[amount]();
			drinks[i] = drink;
		}
	}
	void DrinkSlot::printInfo() {
		if (!count) {
			std::cout << "Slot is empty!" << std::endl;

			return;
		}
		for (int i = 0; i < count; i++) {
			std::cout << drinks[i] << std::endl;
		}
	}
	void DrinkSlot::addDrink(Drink drink) {
		drinks[count] = drink;
		++count;
	}
	Drink& DrinkSlot::giveDrink() {
		Drink* _drinks = new Drink[amount]();

		for (int i = 0; i < count - 1; i++) {
			_drinks[i] = drinks[i];
		}
		for (int i = 0; i < count; i++) {
			drinks[i] = _drinks[i];
		}

		delete[] _drinks;
		
		--count;
		std::cout << "Here is your drink!" << std::endl;

		return drinks[0];
	}
	/// 
	/// 
	///√≈““≈–€
	Drink& DrinkSlot::getDrink() { return drinks[0]; }
	int DrinkSlot::getAmount() { return amount; }
	int DrinkSlot::getCount() { return count; }
	std::string DrinkSlot::getDrinkName() { return drinks->getName(); }
	int DrinkSlot::getCost() { return drinks->getCost(); }
	int DrinkSlot::getVolume() { return drinks->getVolume(); }
	int DrinkSlot::getNumber() { return number; }
	///—≈““≈–€
	void DrinkSlot::setNumber(int n) { number = n; }
	void DrinkSlot::setAmount(int amount) { this->amount = amount; }
	void DrinkSlot::setCount(int count) { this->count = count; }
	/// 
	///
	///œ≈–≈√–”∆≈ÕÕ€≈ Œœ≈–¿“Œ–€
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