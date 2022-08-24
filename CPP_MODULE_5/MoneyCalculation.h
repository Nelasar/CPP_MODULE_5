#pragma once
#include <iostream>
#include <ctime>
#include "Drink.h"

namespace homework {
	const int NOMINALS_AMOUNT = 11;

	class MoneyCalculation
	{
	private:
		bool isNotFake = false;
		bool isRightNominal = false;
		bool isEnoughMoney = false;

		int sum = 0;
		int change = 0;
		int nominals[NOMINALS_AMOUNT]{ 1, 2, 5, 10,
					  50, 100, 200,
					  500, 1000, 2000, 5000 }; // Нет номиналов '1', '5000', 
	public:
		bool const getFakeFlag();
		bool getNominalFlag();
		void setFakeFlag();
		void setNominalFlag();

		void giveMoneyBack() {
			std::cout << "Here is your money!" << std::endl;
			sum = 0;
		}

		bool checkCost(Drink& drink);
		void insertMoney();
		bool checkMoney();
		bool checkNominal(int money);
		int giveChange(Drink drink);
		void reset();
	};
}

