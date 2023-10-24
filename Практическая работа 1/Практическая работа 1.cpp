
#include <iostream>
//#include <cmath>
#include <conio.h>
using namespace std;
void binInt()
{
	system("cls");
	cout << "Вывести на экран двоичное представление в памяти (все разряды) целого числа.\n\n";
	int value; // Значение числа
	cout << "Введите целое число: ";
	cin >> value;
	//делаем защиту функции.

	while (cin.fail()) {
		cout << "Ошибка ввода!!! \n\n";
		cout << "Введите целое число: ";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> value;
		cout << "\n\n";
	}
	unsigned int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		mask >>= 1;
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << "\n\nХотите отобразить зеркально биты?" << "\n\n Если Да введите 1, если Нет - 0\n\n";
	int buttIdz;
	cin >> buttIdz;
	while (buttIdz < 0 || buttIdz > 1 || cin.fail())
	{
		cout << "ошибка\n\n" << "Введите число повторно: ";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> buttIdz;
	}
	int numIdz;
	if (buttIdz == 1)
	{
		cout << "С какого бита хотите начать отражение? ";
		int numIdz;
		cin >> numIdz;
		while (numIdz < 0 || numIdz > 32 || cin.fail())
		{
			cout << "ошибка\n\n" << "Введите число повторно: ";
			cin.clear();
			cin.ignore(10000000000, '\n');
			cin >> numIdz;
		}
		mask = 1 << order - 1;
		for (int i = 1; i < numIdz; i++)
		{
			putchar(value & mask ? '1' : '0');
			mask >>= 1;
		}
		mask = 1;
		for (int i = order; i >= numIdz; i--)
		{
			putchar(value & mask ? '1' : '0');
			mask <<= 1;
		}

	}
	cout << endl << endl;
	cout << "Для выхода в меню нажмите любую клавишу";
	_getch();
	cout << "\n\n";
	system("cls");
}
void binFloat()
{
	system("cls");
	cout << "Вывести на экран двоичное представление в памяти (все разряды) вещественного числа типа float числа.\n\n";
	union {
		int toolF;
		float numb_f;
	};
	cout << "Введите вещественное число: ";
	cin >> numb_f;
	while (cin.fail()) {
		cout << "Ошибка вода!!!";
		cout << "Введите вещественное число: " << "\n\n";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> numb_f;
		cout << "\n\n";
	}
	unsigned int orderF = sizeof(float) * 8;
	unsigned int maskF = 1 << orderF - 1;
	for (int i = 1; i <= orderF; i++)
	{
		putchar(toolF & maskF ? '1' : '0');
		maskF >>= 1;

		if (i % orderF - 9 == 0 || i % orderF - 32 == 0 || i % orderF - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << "\n\nХотите отобразить зеркально биты?" << "\n\n Если Да введите 1, если Нет - 0\n\n";
	int buttIdzF;
	cin >> buttIdzF;
	while (buttIdzF < 0 || buttIdzF > 1 || cin.fail())
	{
		cout << "ошибка\n\n" << "Введите число повторно: ";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> buttIdzF;
	}
	int numIdzF;
	if (buttIdzF == 1)
	{
		cout << "С какого бита хотите начать отражение? ";
		cin >> numIdzF;
		while (numIdzF < 0 || numIdzF > 32 || cin.fail())
		{
			cout << "ошибка\n\n" << "Введите число повторно: ";
			cin.clear();
			cin.ignore(10000000000, '\n');
			cin >> numIdzF;
		}
		maskF = 1 << orderF - 1;
		for (int i = 1; i < numIdzF; i++)
		{
			putchar(toolF & maskF ? '1' : '0');
			maskF >>= 1;
		}
		maskF = 1;
		for (int i = orderF; i >= numIdzF; i--)
		{
			putchar(toolF & maskF ? '1' : '0');
			maskF <<= 1;
		}
	}
	cout << endl << endl;
	cout << "Для выхода в меню нажмите любую клавишу";
	_getch();
	cout << "\n\n";
	system("cls");
}
void binDouble()
{
	system("cls");
	cout << "Вывести на экран двоичное представление в памяти (все разряды) вещественного числа типа double числа.\n\n";
	union {
		int arrTool[2];
		double numb_d;
	};
	cout << "Введите вещественное число: ";
	cin >> numb_d;
	while (cin.fail()) {
		cout << "Ошибка вода!!!";
		cout << "Введите вещественное число: " << "\n\n";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> numb_d;
		cout << "\n\n";
	}
	unsigned int orderD = sizeof(int) * 8; 
	unsigned int maskD = 1 << orderD - 1; 
	for (int i = 1; i >= 0; i--)
	{
		maskD = 1 << orderD - 1;

		for (int j = 0; j < orderD; j++)
		{
			putchar(arrTool[i] & maskD ? '1' : '0');
			maskD >>= 1; 
			if ((j % orderD == 1) && i)
			{
				putchar(' ');
			}
			if ((j == 12) && i)
			{
				putchar(' ');
			}
			if ((j % orderD == 0) && i)
			{
				putchar(' ');
			}
		}
	}
	cout << "\n\nХотите отобразить зеркально биты?" << "\n\n Если Да введите 1, если Нет - 0\n\n";
	int buttIdzD;
	cin >> buttIdzD;
	while (buttIdzD < 0 || buttIdzD > 1 || cin.fail())
	{
		cout << "ошибка\n\n" << "Введите число повторно: ";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> buttIdzD;
	}
	int numIdzD;
	while (buttIdzD == 1)
	{
		cout << "Введите число: ";
		cin >> numIdzD;
		while (numIdzD < 0 || numIdzD > 64 || cin.fail())
		{
			cout << "ошибка\n\n" << "Введите число повторно: ";
			cin.clear();
			cin.ignore(10000000000, '\n');
			cin >> numIdzD;
		}
		for (int i = 1; i >= 0; i--)
		{
			maskD = 1 << orderD - 1;

			for (int j = 0; j < numIdzD; j++)
			{
				putchar(arrTool[i] & maskD ? '1' : '0');
				maskD >>= 1;
			}
			maskD = 1;
			for (int j = orderD; j >= numIdzD; j--)
			{
				putchar(arrTool[i] & maskD ? '1' : '0');
				maskD <<= 1;
			}
		}
		break;
	}
	cout << endl << endl;
	cout << "Для выхода в меню нажмите любую клавишу";
	_getch();
	cout << "\n\n";
	system("cls");
}
void dataTypes() {
	system("cls");
	cout << "Вывод, сколько памяти (в байтах) отводится под различные типы данных:" << endl;
	cout << "float: " << sizeof(float) << " байт" << endl;
	cout << "bool: " << sizeof(bool) << " байт" << endl;
	cout << "char: " << sizeof(char) << " байт" << endl;
	cout << "short int: " << sizeof(short int) << " байт" << endl;
	cout << "long int: " << sizeof(long int) << " байт" << endl;
	cout << "int: " << sizeof(int) << " байт" << endl;
	cout << "double: " << sizeof(double) << " байт" << endl;
	cout << endl << endl;
	cout << "Для выхода в меню нажмите любую клавишу";
	_getch();
	cout << "\n\n";
	system("cls");
}
int main() {
	setlocale(LC_ALL, "ru");
	int enterButton;
	do {
		cout << "Выберете 1 из вариантов.\n";
		cout << "1. Вывод, сколько памяти (в байтах) отводится под различные типы данных\n";
		cout << "2. Вывод на экран двоичное представление в памяти (все разряды) целого числа.\n";
		cout << "3. Вывод на экран двоичное представление в памяти (все разряды) вещественного числа типа float числа.\n";
		cout << "4. Вывод на экран двоичное представление в памяти (все разряды) вещественного числа типа double числа.\n";
		cout << "5. Выход из программы.\n";
		cout << ">";
		cin >> enterButton;
		cout << "\n\n";
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000000000, '\n');
		}
		switch (enterButton) {
		case 1:
			dataTypes();
			break;
			return 0;
		case 2:
			binInt();
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 3:
			binFloat();
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 4:
			binDouble();
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 5:
			exit(0);
			break;
		default:
			cout << "Такой вариант отсутствует :) \n\n";
			cout << "Введите число: ";
			break;
		}
	} while (true);
	system("cls");
	return 0;
}
