#include "VendingMachine.h"

namespace homework {
	//КОНСТРУКТОРЫ
	VendingMachine::VendingMachine(){
		drinkSlots = nullptr;
		moneyCalculation = nullptr;
	}
	VendingMachine::VendingMachine(int rows, int columns, int _amount) : _rows(rows), _columns(columns) {
		slots = rows * columns;

		drinkSlots = new DrinkSlot * [rows]();
		copies = new CopyOfGoods * [rows]();
		for (int i = 0; i < rows; i++) {
			drinkSlots[i] = new DrinkSlot[columns]();
			copies[i] = new CopyOfGoods[columns]();
		}

		int count = 1;
		for (int i = 0; i < rows; i++) {
			srand(time(NULL));

			for (int j = 0; j < columns; j++) {

				std::string name_ = names[0 + rand() % (5)];
				int cost_ = costs[0 + rand() % (5)];
				int volume_ = volumes[0 + rand() % (5)];

				DrinkSlot* drinkSlot = new DrinkSlot(_amount, name_, cost_, volume_);

				copies[i][j].c_name = name_;
				copies[i][j].c_cost = cost_;
				copies[i][j].c_volume = volume_;
				copies[i][j].c_number = count;

				drinkSlots[i][j] = *drinkSlot;
				drinkSlots[i][j].setNumber(count++);
			}
		}
		moneyCalculation = new MoneyCalculation();
	}
	//ДЕСТРУКТОР
	VendingMachine::~VendingMachine() {
		for (int i = 0; i < _rows; i++) {
			delete[] drinkSlots[i];
			delete[] copies[i];
		}
		delete[] drinkSlots;
		delete[] copies;
	}
	//ФУНКЦИИ-ЧЛЕНЫ
	//Функция перезаполнения вендинговой машины. Для неё нужны копии значений для каждого слота.
	//НЕ получилось просто копировать значения слота, когда значение count(оставшееся количество напитков в слоте) 
	//достигает нуля, потому что функция выдачи напитка по сути удаляет объекты напитков и все значения обнуляются.
	//Из-за этого необходимы копии
	void VendingMachine::refillSlots() {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				if (drinkSlots[i][j].getCount() == 0) {
					int number = drinkSlots[i][j].getNumber();

					std::string name_ = copies[i][j].c_name;
					int cost_ = copies[i][j].c_cost;
					int volume_ = copies[i][j].c_volume;

					DrinkSlot* drinkSlot = new DrinkSlot(drinkSlots[i][j].getAmount(), name_, cost_, volume_);

					drinkSlots[i][j] = *drinkSlot;
					drinkSlots[i][j].setNumber(number);
				}
			}
		}
	}

	//Функция процесса успешной покупки. Потребовалась после разрастания функции process()
	//после добавления проверки на пустой слот
	//К сожалению, получилась большой
	void VendingMachine::successBuying(int i, int j) {
		bool insertinMoneyFlag = true;

		while (insertinMoneyFlag) {
			moneyCalculation->insertMoney(); //Вставляем деньги

			if (moneyCalculation->checkCost(drinkSlots[i][j].getDrink())) //Если денег достаточно
			{
				moneyCalculation->giveChange(drinkSlots[i][j].getDrink());//Даём сдачу
				moneyCalculation->reset();//Обнуляем значения денежной машины торгового аппарата
				drinkSlots[i][j].giveDrink();//Выдаём напиток

				std::cout << "Enjoy your drink!" << std::endl;
				system("pause");

				insertinMoneyFlag = false;
			}
			else {
				char choice = '\0';
				std::cout << "Not enough money!\n 1 - Insert more, 0 - Refuse" << std::endl; //Спршиваем, будет ли покупатель докидывать деньги или вернёт себе то, что уже вставил
				std::cin >> choice;

				switch (choice)
				{
				case '0': {
					moneyCalculation->giveMoneyBack(); //Отдаём деньги
					moneyCalculation->reset();//Обнуляем денежную машину

					insertinMoneyFlag = false;

					break;
				}
				case '1': {
					continue;
					break;
				}
				default:
					std::cout << "Wrong data!" << std::endl;
					break;
				}
			}
		}
	}

	//Выводим на экран содержимаое вендинговой машины: слот, какой напиток в слоте, цена и объём.
	void VendingMachine::printInfoMachine() {
		std::cout << "Hello and Welcome!\nLook at our goods!\n" << std::endl;
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				std::cout << "Slot #" << drinkSlots[i][j].getNumber() << " Name: " << drinkSlots[i][j].getDrinkName() << " Cost: "
					<< drinkSlots[i][j].getCost() << " Volume: " << drinkSlots[i][j].getVolume() << " Availiable drinks: " << drinkSlots[i][j].getCount() << std::endl;
			}
		}
	}

	//Функция, которая запускает работу  торгового аппарата и объединяет в себе всё и вся.
	//К сожалению, получилась большой
	void VendingMachine::process() {
		while (isActive) {
			system("cls");
			printInfoMachine();

			std::cout << "\nTo buy yourself a drink, enter slot number:\nEnter 0 to stop" << std::endl;
			int slot = 0;
			std::cin >> slot;

			if (!slot) {
				isActive = false;

				break;
			}
			if (slot >= 1 && slot <= _rows * _columns) {
				for (int i = 0; i < _rows; i++) {
					for (int j = 0; j < _columns; j++) {
						if (drinkSlots[i][j].getNumber() == slot) {
							if (drinkSlots[i][j].getCount() == 0) {
								std::cout << "Oops! There is no drinks in this slot...\n"
									<< "Type 1 to call an operator to refill slots or 0 to buy something else" << std::endl;

								char choice = '\0';
								std::cin >> choice;

								bool flag = true;
								while (flag) {
									switch (choice) {
									case '0': {
										moneyCalculation->giveMoneyBack();
										moneyCalculation->reset();

										flag = false;

										break;
									}
									case '1': {
										refillSlots();
										std::cout << "Done!\nYou can now continue shopping" << std::endl;
										system("pause");

										successBuying(i, j);

										flag = false;

										break;
									}
									default: {
										std::cout << "Wrong data!" << std::endl;

										break;
									}
									}
								}
								system("pause");
							}
							else {
								successBuying(i, j);
							}
						}
					}
				}
			}
			else {
				std::cout << "Sorry, there is no such slot in the Machine!" << std::endl;

				system("pause");
			}
		}
	}
}