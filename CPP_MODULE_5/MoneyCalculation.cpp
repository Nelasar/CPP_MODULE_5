#include "MoneyCalculation.h"

namespace homework {
	//�������
	bool const MoneyCalculation::getFakeFlag() { return isNotFake; }
	bool const MoneyCalculation::getNominalFlag() { return isRightNominal; }
	bool const MoneyCalculation::getEnoughMoneyFlag() { return isEnoughMoney; }
	//�������
	void MoneyCalculation::setFakeFlag(bool flag) { isNotFake = flag; }
	void MoneyCalculation::setNominalFlag(bool flag) { isRightNominal = flag; }
	void MoneyCalculation::setEnoughMoneyFlag(bool flag) { isEnoughMoney = flag; }
	//�������-�����
	//������� ��� "�����" ����� � ������
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
				checkMoney(); //�������� �� ��������
				checkNominal(insert); //�������� ���������

				if (isRightNominal && isNotFake) { //���� �������� ��������, �� ����������� ����� �������� ����� �������������
					sum += insert;
				}
				else {// ����� - ����������� � �������� ������������
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

	//������� �������� ����������� �������� ����������� ����� ���� ������ (�.�. ������ ��� �����)
	bool MoneyCalculation::checkCost(Drink& drink) {
		if (sum >= drink.getCost()) {
			isEnoughMoney = true;
		}
		else {
			isEnoughMoney = false;
		}

		return isEnoughMoney;
	}

	//�������� �� �����������. ������ ���, ���������� �������� �����������
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

	//�������� ��������. ��� ��� ����������
	bool MoneyCalculation::checkNominal(int money) {
		for (int i = 0; i < NOMINALS_AMOUNT; i++) {
			if (money == nominals[i]) {
				isRightNominal = true;

				return isRightNominal;
			}
		}
	}

	//������� ��� ������ ����� ����������
	int MoneyCalculation::giveChange(Drink drink) {
		if (sum > drink.getCost()) {
			change = sum - drink.getCost();
			std::cout << "Don't forget your change! It is " << change << std::endl;

			return change;
		}
	}

	//���������� ���� ���������� ����� �������
	void MoneyCalculation::reset() {
		isNotFake = false;
		isRightNominal = false;
		isEnoughMoney = false;
		sum = 0;
		change = 0;
	}

	//������� �������� ����� ������������
	void  MoneyCalculation::giveMoneyBack() {
		std::cout << "Here is your money!" << std::endl;
		sum = 0;
		//�� ���� ������ ������� � ������������ ���������, ��������� ��� ������/�������, �� ������ �������� ���������.
		//��� ���� �� ����������, ���� �� ��� ����� ���������� � ����� "��������� ������"
	}
}