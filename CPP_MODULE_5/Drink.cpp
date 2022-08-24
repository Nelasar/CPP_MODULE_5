#include "Drink.h"
namespace homework {
	/// ŒÕ—“–” “Œ–€
	Drink::Drink() {
		name = "\0";
		cost = 0;
		volume = 0;
	};
	Drink::Drink(std::string name) {
		this->name = name;
	}
	Drink::Drink(std::string name, int cost) {
		this->name = name;
		this->cost = cost;
	}
	Drink::Drink(std::string _name, int _cost, int _volume) : name(_name), cost(_cost), volume(_volume) {}
	//{
	//	this->name = name;
	//	this->cost = cost;
	//	this->volume = volume;
	//}
	Drink::Drink(const Drink& other) {
		this->name = other.name;
		this->cost = other.cost;
		this->volume = other.volume;
	}
	///—≈““≈–€
	void Drink::setName(std::string name) { this->name = name; }
	void Drink::setCost(int cost) { this->cost = cost; }
	void Drink::setVolume(int volune) { this->volume = volume; }
	///√≈““≈–€
	std::string  const Drink::getName() { return name; }
	int const Drink::getCost() { return cost; }
	int const Drink::getVolume() { return volume; }
	/// 

	std::ostream& operator<<(std::ostream& out, const Drink& drink) {
		out << drink.name << ' ' << drink.cost << ' ' << drink.volume << ' ';

		return out;
	}

	/// 
	/// 
	///
}