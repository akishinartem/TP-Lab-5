#include "Keeper.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	Keeper Contain;
	int menu = 0;
	cout << "Добро пожаловать!" << endl;
	do {
		try {
			cout << "Текущее количество элементов в контейнере: " << Contain.GetSize() << "." << endl
				<< "Выберите действие:" << endl
				<< "[1] Добавить элемент." << endl
				<< "[2] Сохранить данные в файл." << endl
				<< "[3] Загрузить данные из файла." << endl
				<< "[4] Вывести данные из контейнера." << endl
				<< "[0] Выход." << endl
				<< ">> ";
			cin >> menu;
			if (menu > 5 || menu < 0) {
				throw 1;
			}
			switch (menu) {
			case 1:
				Contain.Add();
				break;
			case 2:
				Contain.Save();
				break;
			case 3:
				Contain.Load();
				break;
			case 4:
				cout << Contain;
				break;
			default:
				break;
			}
		}
		catch (...) {
			cout << "Допустимые значения переменной 'menu' = 0, 1, 2, 3, 4, 5." << endl;
		}
		system("pause");
		system("cls");
	} while (menu != 0);
	return 0;
}