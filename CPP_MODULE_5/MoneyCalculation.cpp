#include "MoneyCalculation.h"

namespace homework {
	//СЕТТЕРЫ
	bool const MoneyCalculation::getFakeFlag() { return isNotFake; }
	bool const MoneyCalculation::getNominalFlag() { return isRightNominal; }
	bool const MoneyCalculation::getEnoughMoneyFlag() { return isEnoughMoney; }
	//ГЕТТЕРЫ
	void MoneyCalculation::setFakeFlag(bool flag) { isNotFake = flag; }
	void MoneyCalculation::setNominalFlag(bool flag) { isRightNominal = flag; }
	void MoneyCalculation::setEnoughMoneyFlag(bool flag) { isEnoughMoney = flag; }
	//ФУНКЦИИ-ЧЛЕНЫ
	//Функция для "ввода" денег в машину
	void MoneyCalculation::insertMoney() {
		bool flag = true;
		int insert = 0;

		system("cls");

		std::cout << "Please, give us your money\nType '0' to stop" << std::endl;
		while (flag) {
			std::cout << "Your sum: " << sum << std::endl;
			std::cin >> insert;

			if (insert == 0) {
				flag = false;
			}
			else {
				checkMoney(); //Проверка на вшивость
				checkNominal(insert); //Проверка номиналов

				if (isRightNominal && isNotFake) { //Если проверки пройдены, то увеличиваем сумму введённых денег пользователем
					sum += insert;
				}
				else {// Иначе - информируем о проблеме пользователя
					if (!isRightNominal) {
						std::cout << "Try again! You can only insert 1, 2, 5, 10, 50, 100"
							<< "\t\t\n200, 500, 1000, 2000, 5000 nominals" << std::endl;
					}
					else if (!isNotFake) {
						std::cout << "It is not money! Calling the police..." << std::endl;
					}
				}
			}
		}
	}

	//Функция проверка соответсвия введённой покупателем суммы цене товара (м.б. больше или равно)
	bool MoneyCalculation::checkCost(Drink& drink) {
		if (sum >= drink.getCost()) {
			isEnoughMoney = true;
		}
		else {
			isEnoughMoney = false;
		}

		return isEnoughMoney;
	}

	//Проверка на фальшивость. Просто так, захотелось элемента случайности
	bool MoneyCalculation::checkMoney() {
		srand(time(NULL));

		int check = 1 + rand() % (10 - 1 + 1);

		if (check == 1) {
			isNotFake = false;
		}
		else{
			isNotFake = true;
		}

		return isNotFake;
	}

	//Проверка номинала. Мне так захотелось
	bool MoneyCalculation::checkNominal(int money) {
		for (int i = 0; i < NOMINALS_AMOUNT; i++) {
			if (money == nominals[i]) {
				isRightNominal = true;

				return isRightNominal;
			}
		}
	}

	//Функция для выдачи сдачи покупателю
	int MoneyCalculation::giveChange(Drink drink) {
		if (sum > drink.getCost()) {
			change = sum - drink.getCost();
			std::cout << "Don't forget your change! It is " << change << std::endl;

			return change;
		}
	}

	//Обновление всех переменных после покупки
	void MoneyCalculation::reset() {
		isNotFake = false;
		isRightNominal = false;
		isEnoughMoney = false;
		sum = 0;
		change = 0;
	}

	//Функция возврата денег пользователю
	void  MoneyCalculation::giveMoneyBack() {
		std::cout << "Here is your money!" << std::endl;
		sum = 0;
		//Не стал делать функцию с возвращаемым значением, поскольку нет класса/функций, от такого возврата зависящих.
		//Это было бы необходимо, если бы был класс покупателя с полем "Имеющиеся деньги"
	}
}