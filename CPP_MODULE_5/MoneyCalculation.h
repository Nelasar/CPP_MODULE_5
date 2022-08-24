#pragma once
#include <iostream>
#include <ctime>
#include "Drink.h"
//Это класс денежной машины торгового аппарата.
//Его задача - принимать деньги, проверять их на фальшивость, проверять номиналы, проверять, хватает ли денег на покупку
//А также выдавать сдачу или возвращать деньги
namespace homework {
	const int NOMINALS_AMOUNT = 9; // Константа для массива номиналов

	class MoneyCalculation
	{
	private:
		bool isNotFake = false; // Флаг для проверки принимаемых денег (просто для усложнения механизма, не более)
		bool isRightNominal = false; // Флаг для проверки номинала денег (просто для простейшей симуляции ввода купюр/монет в машину)
		bool isEnoughMoney = false; // Флаг для проверки итоговой суммы

		int sum = 0; //Итоговая сумма
		int change = 0; //Сдача
		int nominals[NOMINALS_AMOUNT]{ 2, 5, 10, //Доступные номиналы
					  50, 100, 200,
					  500, 1000, 2000 }; // Нет номиналов '1', '5000', просто так 
	public:
		//СЕТТЕРЫ
		bool const getFakeFlag();
		bool const getNominalFlag();
		bool const getEnoughMoneyFlag();
		//ГЕТТЕРЫ
		void setFakeFlag(bool);
		void setNominalFlag(bool);
		void setEnoughMoneyFlag(bool);
		//ФУНКЦИИ-ЧЛЕНЫ
		void giveMoneyBack(); 
		bool checkCost(Drink& drink);
		void insertMoney();
		bool checkMoney();
		bool checkNominal(int money);
		int giveChange(Drink drink);
		void reset();
	};
}

