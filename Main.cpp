#include "Keeper.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	Keeper Contain;
	int menu = 0;
	cout << "����� ����������!" << endl;
	do {
		try {
			cout << "������� ���������� ��������� � ����������: " << Contain.GetSize() << "." << endl
				<< "�������� ��������:" << endl
				<< "[1] �������� �������." << endl
				<< "[2] ��������� ������ � ����." << endl
				<< "[3] ��������� ������ �� �����." << endl
				<< "[4] ������� ������ �� ����������." << endl
				<< "[0] �����." << endl
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
			cout << "���������� �������� ���������� 'menu' = 0, 1, 2, 3, 4, 5." << endl;
		}
		system("pause");
		system("cls");
	} while (menu != 0);
	return 0;
}