#pragma once
#include <string>
#include <iostream>
namespace homework {
	class Drink
	{
	private:
		std::string name = "\0";
		int cost = 0;
		int volume = 0;
	public:
		/// ŒÕ—“–” “Œ–€
		Drink();
		Drink(std::string);
		Drink(std::string, int);
		Drink(std::string, int, int);
		Drink(const Drink& other);
		///—≈““≈–€
		void setName(std::string);
		void setCost(int);
		void setVolume(int);
		///√≈““≈–€
		std::string const getName();
		int const getCost();
		int const getVolume();
		/// œ≈–≈√–”∆≈ÕÕ€≈ Œœ≈–¿“Œ–€
		friend std::ostream& operator<<(std::ostream&, const Drink&);
	};
}