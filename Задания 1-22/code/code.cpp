// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

void factorization(int n)
{
	setlocale(LC_ALL, "ru");
	int i = 0, j;
	if (n == 1)
	{
		std::cout << "-";
	}
	else if (n < 1)
	{
		std::cout << "Ошибка";
	}
	else
	{
		for (j = 2; j <= n; j++)
		{
			while (n % j == 0)
			{
				n = n / j;
				i++;
			}
			if (i > 1)
			{
				std::cout << j << "^" << i;
				if (n != 1)
				{
					std::cout << "*";
				}
			}
			else if (i != 0)
			{
				std::cout << j;
				if (n != 1)
				{
					std::cout << "*";
				}
			}
			i = 0;
		}
	}
}

double BMI(double weight, double height) {
	double c;
	c = weight / (height*height);
	return c;
}
void printBMI(double BMI) {
	std::string s;
	if (BMI < 18.5) s="Underweight(недостаточная масса)";
	else if (BMI >= 18.5 && BMI < 25) s = "Normal weight(норма)";
	else if (BMI >= 25 && BMI < 30) s = "Overweight(избыточная масса)";
	else if (BMI >= 30) s = "Obesity(ожирение)";
	std::cout << s << "\n";
 }
void printbubble(int a[], int n) {
	int i = 1,j = 1,c;
	c=0;
	while (i < n) {
		while (j < n) {
			if (a[j] <= a[j + 1]) {
				c = a[j];
				a[j] = a[j + 1];
				a[j + 1] = c;
			}
			j++;
		}
		j = 1;
		i++;
	}
	
	i = 1;
	while (i <= n) {
		std::cout << a[i] << " ";
		i++;
	}
	std::cout << "\n";
}

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
			"\n" << "5) Задание с формулой" << "\n6)Поиск корней в квадратном уравнении\n7)Поиск площади треугольника\n8)Калькулятор v2.0\n9)Игра на угадывания числа\n10)Возведение в степень\n11)Факториал" <<
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
			std::cout << "\n" << "Второй способ(1/2*a*t*t): X(t)=" << x + v + 1 / 2 * a*t*t << "\n";
		}


		//Шестое задание
		else if (ai == 6) {
			double a, b, c, d, x1, x2;
			int a1, b1, c1;
			std::cout << "Введите a:";
			std::cin >> a;
			std::cout << "Введите b:";
			std::cin >> b;
			std::cout << "Введите c:";
			std::cin >> c;

			if (a == 0) {
				if (b == 0) {
					if (c == 0) {
						std::cout << "X-Любое число";
					}
					else {
						std::cout << "Нет корней";
					}
					std::cout << "Нет корней";					
				}
				else if (c == 0) {
					std::cout << "Корен равен:"<<-c/b<<"\n";									}
			}
			else if (b == 0) {
				if (-c/a<0) {
					std::cout << "Нет корней\n";
				}				
				else {
					if (sqrt(-c / a) == 0) std::cout << "Корен равен:0\n";
					else {
						std::cout << "Первый корень равен:" << (sqrt(-c / a)) << "\n";
						std::cout << "Второй корень равен:" << (-sqrt(-c / a)) << "\n";
					}
				}
			}
			else if (c == 0) {
				
					std::cout << "Первый корен равен:0\n";
					std::cout << "Второй корень равен" << (-b / a) << "\n";
					

				
			}
			else {
				d = b * b - 4 * a*c;

				if (d > 0) {
					x1 = (-b + sqrt(d)) / (2 * a);
					x2 = (-b - sqrt(d)) / (2 * a);

					std::cout << "D>0" << "\n" << "Первый корень равен:" << x1 << "\n";
					std::cout << "Второй корень равен:" << x2;
					std::cout << "\n";
				}


				else if (d == 0) {

					x1 = (-b + sqrt(d)) / (2 * a);
					std::cout << "D=0" << "\n" << "Корень равен:" << x1 << "\n";

				}
				else
					std::cout << "D<0" << "\n" << "Нет корней,т.к. D<0" << "\n";
			}
		}
	
		//Седьмое задание
		else if (ai == 7) {

			int i;
			std::cout << "Выберите способ нахождения площади треугольника:" <<
				"\n" << "1-по трем сторонам:" <<
				"\n" << "2-по координатам вершин" <<
				"\n" << "Введите номер способа:";
			std::cin >> i;
			system("cls");

			switch (i) {
			case 1:
				double a, b, c, p, s;
				std::cout << "Введите первую сторону:";
				std::cin >> a;
				std::cout << "Введите вторую сторону:";
				std::cin >> b;
				std::cout << "Введите третью сторону:";
				std::cin >> c;
				if ((a + b > c) && (b + c > a) && (a + c > b)) {

					p = (a + b + c) / 2;
					s = sqrt(p*(p - a)*(p - b)*(p - c));

					std::cout << "Площадь треугольника равна:" << s << "\n";
				}
				else std::cout << "По введённым вами сторонами-это не треугольник!";
				break;
			case 2:

				double a1, a2, b1, b2, c1, c2, s1, a3, b3, c3;
				std::cout << "Введите координаты первой вершины:";
				std::cin >> a1 >> a2;
				std::cout << "Введите координаты второй вершины:";
				std::cin >> b1 >> b2;
				std::cout << "Введите координаты третьей вершины:";
				std::cin >> c1 >> c2;
				a3 = sqrt(b1 - a1)*(b1 - a1) + (b2 - a2)*(b2 - a2);
				b3 = sqrt(c1 - b1)*(c1 - b1) + (c2 - b2)*(c2 - b2);
				c3 = sqrt(a1 - c1)*(a1 - c1) + (a2 - c2)*(a2 - c2);
				if ((a3 + b3 > c3) && (b3 + c3 > a3) && (c3 + a3 > b3)) {
					std::cout << "\n";
					s1 = (abs((b1 - a1)*(c2 - a2) - (c1 - a1)*(b2 - a2))) / 2;
					std::cout << "Площадь треугольника равна:" << s1 << "\n";
				}
				else std::cout << "По введённым вами сторонами-это не треугольник!";
				break;

			default:
				std::cout << "Вы ввели неверное значения меню.";
				system("pause");
				break;
			}
		}

		//Восьмое задание
		else if (ai == 8) {
			char k = '0';
			int i = 0;
			int q = 0;
			while (i == 0) {

				char b;
				double a, c;
				std::cout << "Калькулятор\n\n (+)-сложение\n (-)-вычитание\n (*)-умножение\n (/)-деление\n\nЧто будем считать?\nВведите выражение:";
				std::cin >> a >> b >> c;



				/*if (b == '+' || b == '-' || b == '*' || b == '/') {*/
				switch (b) {
				case '+': {
					std::cout << "Ответ:" << a + c << "\n"; }
						  break;

				case '-': {
					std::cout << "Ответ:" << a - c << "\n"; }
						  break;

				case '*': {
					std::cout << "Ответ:" << a * c << "\n"; }
						  break;

				case '/': {
					if (c == 0) { std::cout << "EROR 404: НА НОЛЬ ДЕЛИТЬ НЕЛЬЗЯ!!!!!!!!!!\nEROR 404: НА НОЛЬ ДЕЛИТЬ НЕЛЬЗЯ!!!!!!!!!!\nEROR 404: НА НОЛЬ ДЕЛИТЬ НЕЛЬЗЯ!!!!!!!!!!\n"; }
					else { std::cout << "Ответ:" << a / c << "\n"; }
				}
						  break;


				default:
					system("cls");
					std::cout << "Вы ввели неверное действие,пожалуйста повторите ваш пример с данными действиями(+,-,*,/)\n\n";
					continue;
				}


				system("pause");
				system("cls");
				break;
			}
		}
		
		//Девятое задание
		else if (ai == 9) {
			int c = 0;
			char j;
			while (c == 0) {
				int a = 1;
				setlocale(LC_ALL, "Russian");
				int i, k;
				srand(time(0));
				i = rand() % 101;
				std::cout << "Добро пожаловать в игру,игрок.\nЦель данной игры очень проста:ты должен угадать число,которое я загадал в уме.\nОно находиться в диапазоне от 0 до 100 включительно,кстате я буду давать тебе подсказки.\nУ тебя есть 5 попыток,чтобы угадать число,иначе ты проиграл.\nДумаю ты понял правила,так что начинаем игру!\n   Загадываю число...";
				while (a < 6) {
					std::cout << "\n\n" << a << " попытка:\nВведите число,которое по вашему мнению я загадал:";
					std::cin >> k;
					if (k < 0 || k>101) {
						std::cout << "Вы ввели число которое не входит в мой диапазон данных(от 0,до 100 включительно).\nДанным действием вы потеряли 1 ход,пожайлуста в дальнейшем не вводите числа не входящие в мой диапазон.\n";
					}
					if (k > i) std::cout << "Загаданное число меньще,чем ваше";
					else if (k == i) {
						system("cls");
						std::cout << "Вы победили!\n";
						break;
					}
					else if (k < i) std::cout << "Загаданное число больше,чем ваше";
					a++;
				}

				if (a == 6) {
					system("cls");
					std::cout << "Простите...но вы ПРОИГРАЛИ!\nВы не смогли угадать число за 5 попыток...\nДанным числом было:" << i << "\n";
				}
				std::cout << "Желаете ли вы ещё поиграть?\n1-да,что-нибудь другое-нет\nВведите значение:";
				std::cin >> j;
				system("cls");
				if (j == '1') {
					continue;
				}
				else break;


			}
		}
		//Десятое задание(ЮБИЛЕЙ))
		else if (ai == 10) {
			std::cout << "Возведение в степень:\n";
			int a;
			int b, c;
			double s;
			s = 1;
			c = 1;
			std::cout << "Введите число:";
			std::cin >> a;
			std::cout << "Введите степень:";
			std::cin >> b;
			if (b > 0) {
				while (c <= b) {
					s = a * s;
					c++;
				}
			}
			else if (b < 0) {
				
				if (a == 0) 
					std::cout << "Недопустимый ввод" << "\n";
				else {
					while (c >= b) {
						s = a * s;
						c = c - 1;
					}
					s = 1 / s;

				}
			}
			else if (b = 0) s = 1;
			if(a!=0)std::cout << "Ваш ответ:" << s << "\n";


		}
		//Одиннадцатое задание
		else if (ai == 11) {
			std::cout << "Факториал";
			int i, c, s;
			c = 1;
			s = 1;
			std::cout << "Введите число:";
			std::cin >> i;
			if (i < 0)std::cout << "Факториал можно найти только у положительных чисел и нуля!";
			else if (i == 0) std::cout << "Ответ:1\n";
			else {
				while (c <= i) {
					s = s * c;
					c++;
				}
				std::cout << "Ответ:" << s << "\n";
			}
		}
		//двеннадцатое задание
		else if (ai == 12) {
			int i, c, k;
			k = 0;
			c = 2;
			std::cout << "Задача на нахождение простого и сложного положительного числа\nВведите число,которое хотите проверить:";
			std::cin >> i;
			if (i == 1) std::cout << "Единица не являеться составным или простым числом\n";
			else if (i <= 0) std::cout << "Вводить можно только положительные числа!\n";
			while (c < i) {
				if (i%c == 0)k++;
				if (k >= 1) {
					std::cout << "Ваше число:составное\n";
					break;
				}
				c++;
			}
				if(k==0) 
			std::cout << "Ваше число:простое\n";
				
			}
		
		//Тринадцатое задание
		else if (ai == 13) {
			int c, s;
			double i, k;
			k = 1;
			c = 1;
			std::cout << "Степень двойки:\nВведите число,чтобы узнать,сколько в нем степеней двойки:";
			std::cin >> i;
			while (c <= i) {
				k = k * 2;
				if (k >= i)	break;

				c++;
			}
			if (i == k)std::cout << "Ответ:" << c + 1 << "\n";
			else if (i == 0) std::cout << "Ответ:0\n";
			else if (i > k)std::cout << "Ответ:" << c + 1 << "\n";
			else if (i < k)std::cout << "Ответ:" << c << "\n";
			
		}
		//Четырнадцатое задание
		else if (ai == 14) {

			long long i, q, s, l1, r1, l2, r2, x1, x2;
			bool f = 0;
			std::cout << "Введите s,l1,r1,l2,r2 через пробел:";
			std::cin >> s >> l1 >> r1 >> l2 >> r2;
			if (r1 < l1 || r2 < l2) {
				std::cout << "Вы ввели неверный диапазон значений\n";
			}
			else {
				i = l1;
				q = l2;
				x1 = r1 + 1;
				x2 = r2 + 1;
				while (i <= r1) {
					while (q <= r2) {
						if (i + q == s) {
							f = true;
							if (x1 > i) {
								x1 = i;
								x2 = q;
							}
						}
						q++;
					}
					i++;
					q = l2;
				}
				if (f == 0) {
					std::cout << "Ваш ответ:-1\n";
				}
				else {
					std::cout << "Ваш ответ:" << x1 << " " << x2 << "\n";
				}
			}
		}
		//Пятнадцатое задание
		else if (ai == 15) {
		int x1, x2, x3, x4, x5, c, n,a,i;
		int b[100000];
		std::cout << "Введите N:";
		std::cin >> n;
		if (n <= -4) {
			std::cout << "Вы ввели неверное значение N.\n";
		}
		else {
			std::cout << "Введите числа:";
			switch (n) {
			case(1):
				std::cin >> x1;
				std::cout << x1;
				break;
			case(2):
				std::cin >> x1 >> x2;
				std::cout << x1 << "\n";
				if (x1 > x2 || x1 == x2) {
				}
				else {
					c = x2;
					x2 = x1;
					x1 = c;
				}
				std::cout << x1 << " " << x2;
				break;
			case(3):
				std::cin >> x1 >> x2 >> x3;
				std::cout << x1 << "\n";
				if (x1 > x2 || x1 == x2) {
				}
				else {
					c = x2;
					x2 = x1;
					x1 = c;
				}
				std::cout << x1 << " " << x2 << "\n";
				if (x3 > x1) {
					c = x2;
					x2 = x1;
					x1 = x3;
					x3 = c;
				}
				else if (x3 > x2) {
					c = x2;
					x2 = x3;
					x3 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3;
				break;
			case(4):
				std::cin >> x1 >> x2 >> x3 >> x4;
				std::cout << x1 << "\n";
				if (x1 > x2 || x1 == x2) {
				}
				else {
					c = x2;
					x2 = x1;
					x1 = c;
				}
				std::cout << x1 << " " << x2 << "\n";
				if (x3 > x1) {
					c = x2;
					x2 = x1;
					x1 = x3;
					x3 = c;
				}
				else if (x3 > x2) {
					c = x2;
					x2 = x3;
					x3 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3;
				if (x4 >= x1) {
					c = x1;
					x1 = x4;
					a = x2;
					x2 = c;
					c = x3;
					x3 = a;
					x4 = c;
				}
				else if (x4 >= x2) {
					c = x3;
					x3 = x2;
					x2 = x4;
					x4 = c;
				}
				else if (x4 >= x3) {
					c = x4;
					x4 = x3;
					x3 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << "\n";
				break;
			case(5):
				std::cin >> x1 >> x2 >> x3 >> x4 >> x5;
				std::cout << x1 << "\n";
				if (x1 >= x2) {
				}
				else {
					c = x2;
					x2 = x1;
					x1 = c;
				}
				std::cout << x1 << " " << x2 << "\n";
				if (x3 >= x1) {
					c = x2;
					x2 = x1;
					x1 = x3;
					x3 = c;
				}
				else if (x3 >= x2) {
					c = x2;
					x2 = x3;
					x3 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3 << "\n";
				if (x4 >= x1) {
					c = x1;
					x1 = x4;
					a = x2;
					x2 = c;
					c = x3;
					x3 = a;
					x4 = c;
				}
				else if (x4 >= x2) {
					c = x3;
					x3 = x2;
					x2 = x4;
					x4 = c;
				}
				else if (x4 >= x3) {
					c = x4;
					x4 = x3;
					x3 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << "\n";
				if (x5 >= x1) {
					c = x1;
					x1 = x5;
					a = x2;
					x2 = c;
					c = x3;
					x3 = a;
					a = x4;
					x4 = c;
					x5 = a;
				}
				else if (x5 >= x2) {
					c = x2;
					x2 = x5;
					a = x3;
					x3 = c;
					c = x4;
					x4 = a;
					x5 = c;
				}
				else if (x5 >= x3) {
					c = x3;
					x3 = x5;
					a = x4;
					x4 = c;
					x5 = a;
				}
				else if (x5 >= x4) {
					c = x4;
					x4 = x5;
					x5 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << "\n";
				break;
			default:
				i = 1;
				while (i <= n) {
					std::cin >> b[i];
					i++;
				}
				x1 = b[1];
				x2 = b[2];
				x3 = b[3];
				x4 = b[4];
				x5 = b[5];
				std::cout << x1 << "\n";
				if (x1 >= x2) {
				}
				else {
					c = x2;
					x2 = x1;
					x1 = c;
				}
				std::cout << x1 << " " << x2 << "\n";
				if (x3 >= x1) {
					c = x2;
					x2 = x1;
					x1 = x3;
					x3 = c;
				}
				else if (x3 >= x2) {
					c = x2;
					x2 = x3;
					x3 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3 << "\n";
				if (x4 >= x1) {
					c = x1;
					x1 = x4;
					a = x2;
					x2 = c;
					c = x3;
					x3 = a;
					x4 = c;
				}
				else if (x4 >= x2) {
					c = x3;
					x3 = x2;
					x2 = x4;
					x4 = c;
				}
				else if (x4 >= x3) {
					c = x4;
					x4 = x3;
					x3 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << "\n";
				if (x5 >= x1) {
					c = x1;
					x1 = x5;
					a = x2;
					x2 = c;
					c = x3;
					x3 = a;
					a = x4;
					x4 = c;
					x5 = a;
				}
				else if (x5 >= x2) {
					c = x2;
					x2 = x5;
					a = x3;
					x3 = c;
					c = x4;
					x4 = a;
					x5 = c;
				}
				else if (x5 >= x3) {
					c = x3;
					x3 = x5;
					a = x4;
					x4 = c;
					x5 = a;
				}
				else if (x5 >= x4) {
					c = x4;
					x4 = x5;
					x5 = c;
				}
				std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << "\n";
				i = 6;
				while (i <= n) {
					if (b[i] < x1 && b[i] >= x2) {
						x1 = b[i];
					}
					else if (b[i] <= x2 && b[i] >= x3) {
						x1 = x2;
						x2 = b[i];
					}
					else if (b[i] <= x3 && b[i] >= x4) {
						x1 = x2;
						x2 = x3;
						x3 = b[i];
					}
					else if (b[i] <= x4 && b[i] >= x5) {
						x1 = x2;
						x2 = x3;
						x3 = x4;
						x4 = b[i];
					}
					else if (b[i] <= x5) {
						x1 = x2;
						x2 = x3;
						x3 = x4;
						x4 = x5;
						x5 = b[i];
					}
					std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << "\n";
					i++;
				}
			}
		}
}
		else if (ai == 16) {
				int a;
				setlocale(LC_ALL, "ru");
				std::cout << "Введите положительное число\n";
				std::cin >> a;
				factorization(a);
				std::cout << "\n\n";
			
}
		else if (ai == 17) {
		std::cout << "Введите Вес и рост:";
		double weight, height;
		std::cin >> weight >> height;
		printBMI(BMI(weight,height/100));
	}

		else if (ai == 18) {
		
		int a[101];
		int i = 1, n = 20, a_max,a_min;
		srand(time(0));
		while (i <= n) {
			a[i] = rand() % 201 - 101;
			std::cout << a[i] << " ";
			i++;
		}
		i = 2;
		a_max = a[1];
		a_min = a[1];
		while (i <= n) {
			if (a_max < a[i]) a_max = a[i];
			if (a_min > a[i]) a_min = a[i];
			i++;
		}
		std::cout << "\nMIN=" << a_min << "\nMAX=" << a_max << "\n";
}
		else if (ai == 19) {
			int a[100000], n, i, d, k,j;
			std::cout << "Введите N:";
			std::cin >> n;
			std::cout << "Введите массив:";
			i = 1;
			while (i <= n) {
				std::cin >> a[i];
				i++;
			}
			i = 1;
			d = 0;
			k = 9;
			j = 0;
			while (d <= k) {
				while (i <= n){
					if (a[i] == d) j++;
				i++;
			}
				if (j != 0) std::cout << d << ":" << j<<"\n";
				d++;
				j = 0;
				i = 1;
			}
		}

		else if (ai == 20) {
		
		int n, i, a[10000];
		std::cout << "Введите N:";
		std::cin >> n;
		std::cout << "Введите элементы массива";
		i = 1;
		while (i <= n) {
		std::cin >> a[i];
			i++;
		}
		printbubble(a, n);
    }

		else if (ai == 21) {
		int i,z,c=5,gi,gz;
		const int size_x = 10, size_y = 8;
		int a[size_x][size_y];
		i = 1;
		z = 1;
		while (i <= size_x) {
			while (z <= size_y) {
				a[i][z] = 0;
				z++;
			}
			z = 1;
			i++;
		}
		srand(time(0));
		i = rand() % 11;
		srand(time(0));
		z = rand() % 9;
		a[i][z] = 1;
		while (c > 0) {
			std::cin >> gi >> gz;
			if ((gi > size_x || gz > size_y) || (gi <= 0 || gz <= 0)) {
				std::cout << "Вы вышли за границы\n";
			}
			else if (a[gi][gz] == 1) {
				std::cout << "Вы угадали\n";
				break;
			}

			else if (a[gi][gz] == 0) {
				a[gi][gz] = 2;
				std::cout << "Вы не угадали\n";
				c = c - 1;
			}
			else if (a[gi][gz] == 2) {
				std::cout << "Эту уже проверяли\n";
			}
		}
		if (c == 0) std::cout << "GAME OVER/n";
}
		else if (ai == 23) {

}
		system("pause");
		system("cls");
		std::cout << "Хотите ли вы выбрать другое задание? 1-да, 0-нет:";
		std::cin >> i;
		system("cls");
	}
	return 0;
}


