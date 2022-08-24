#pragma once
#include <iostream>
#include <ctime>
#include "Drink.h"
//��� ����� �������� ������ ��������� ��������.
//��� ������ - ��������� ������, ��������� �� �� �����������, ��������� ��������, ���������, ������� �� ����� �� �������
//� ����� �������� ����� ��� ���������� ������
namespace homework {
	const int NOMINALS_AMOUNT = 9; // ��������� ��� ������� ���������

	class MoneyCalculation
	{
	private:
		bool isNotFake = false; // ���� ��� �������� ����������� ����� (������ ��� ���������� ���������, �� �����)
		bool isRightNominal = false; // ���� ��� �������� �������� ����� (������ ��� ���������� ��������� ����� �����/����� � ������)
		bool isEnoughMoney = false; // ���� ��� �������� �������� �����

		int sum = 0; //�������� �����
		int change = 0; //�����
		int nominals[NOMINALS_AMOUNT]{ 2, 5, 10, //��������� ��������
					  50, 100, 200,
					  500, 1000, 2000 }; // ��� ��������� '1', '5000', ������ ��� 
	public:
		//�������
		bool const getFakeFlag();
		bool const getNominalFlag();
		bool const getEnoughMoneyFlag();
		//�������
		void setFakeFlag(bool);
		void setNominalFlag(bool);
		void setEnoughMoneyFlag(bool);
		//�������-�����
		void giveMoneyBack(); 
		bool checkCost(Drink& drink);
		void insertMoney();
		bool checkMoney();
		bool checkNominal(int money);
		int giveChange(Drink drink);
		void reset();
	};
}

