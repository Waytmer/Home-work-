// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h";
#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1;
	while (i == 1) {

		std::cout << "Введите номер задания:" <<
			"\n" << "1) Задание с выражением" <<
			"\n" << "2) Задание с числами" <<
			"\n" << "3) Задание с + - / *" <<
			"\n" << "4) Задание с обменой значениями" <<
			"\n" << "5) Задание с формулой" <<
			"\n" << "Любое другое число для выхода";
		int ai;
		std::cout << "\n" << "Ввод значения:";
		std::cin >> ai;

		system("cls");
		//Первое  задание
		if (ai == 1) {
			std::cout << "Первое задание:" << "\n";
			std::cout << "Результат вычисления выражения 2+2*2=" << 2 + 2 * 2 << "\n";
		}

		//Второе задание
		else if (ai == 2) {
			std::cout << "Второе задание:" << "\n";
			int a = 3;
			int c = 3.14;
			double b = 3.14;
			double d = 3;
			std::cout << a << "\n" << c << "\n" << b << "\n" << d << "\n";
		}

		//Третье задание
		else if (ai == 3) {
			std::cout << "Третье задание(+ - * /):" << "\n";

			std::cout << "Два int:" << "\n";
			int a, b;
			std::cout << "Введите первое значение:";
			std::cin >> a;
			std::cout << "Введите второе значение:";
			std::cin >> b;
			std::cout << a + b <<
				"\n" << a - b <<
				"\n" << a * b <<
				"\n" << a / b << "\n";

			std::cout << "Два double:" << "\n";
			double c, d;
			std::cout << "Введите первое значение:";
			std::cin >> c;
			std::cout << "Введите второе значение:";
			std::cin >> d;
			std::cout << c + d <<
				"\n" << c - d <<
				"\n" << c * d <<
				"\n" << c / d << "\n";

			std::cout << "int double:" << "\n";
			int e;
			double g;
			std::cout << "Введите первое значение:";
			std::cin >> e;
			std::cout << "Введите второе значение:";
			std::cin >> g;
			std::cout << e + g <<
				"\n" << e - g <<
				"\n" << e * g <<
				"\n" << e / g << "\n";

			std::cout << "double int:" << "\n";
			double f;
			int h;
			std::cout << "Введите первое значение:";
			std::cin >> f;
			std::cout << "Введите второе значение:";
			std::cin >> h;
			std::cout << f + h <<
				"\n" << f - h <<
				"\n" << f * h <<
				"\n" << f / h << "\n";
		}


		//Четвертое задание
		else if (ai == 4) {

			std::cout << "Четвёртое задание:" << "\n";
			std::cout << "Замена с третьей переменной" << "\n";
			int a, b, c;
			std::cout << "Введите первое значение:";
			std::cin >> a;
			std::cout << "Введите второе значение:";
			std::cin >> b;
			c = a;
			a = b;
			b = c;
			std::cout << a << "\n" << b << "\n"; \

				std::cout << "Замена без третьей переменной:" << "\n";
			int d, e;
			std::cout << "Введите первое значение:";
			std::cin >> d;
			std::cout << "Введите второе значение:";
			std::cin >> e;
			d = d + e;
			e = d - e;
			d = d - e;
			std::cout << d << "\n" << e << "\n";
		}

		//Пятое задание
		else if (ai == 5) {
			std::cout << "Пятое задание:" << "\n";
			double x, v, t;
			double a = -9.8;
			std::cout << "Введите X0:";
			std::cin >> x;
			std::cout << "Введите V0:";
			std::cin >> v;
			std::cout << "Введите t:";
			std::cin >> t;
			std::cout << "Первый способ(a*t*t/2): X(t)=" << x + v + a * t*t / 2;
			std::cout << "\n" << "Второй способ(1/2*a*t*t): X(t)=" << x + v + 1 / 2 * a*t*t << "\n";}
		system("pause");
		system("cls");
		std::cout << "Хотите ли вы выбрать другое задание? 1-да, 0-нет:";
		std::cin >> i;
		system("cls");
    }
		
     system("pause");

	return 0;
}

