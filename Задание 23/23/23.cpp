
#include "pch.h"
#include <iostream>

void swap(int *int_1 , int *int_2) {
	int a = *int_1;
	*int_1 = *int_2;
	*int_2 = a;
}
int msort(int *one, int *too, int *three) {
	while (true) {
		if (*one > *too) swap(one, too);
		else if (*too > *three) swap(too, three);
		else if (*one > *three) swap(one, three);
		else break;
	}
	return *three;
}
void info(const int *value) {
	std::cout << "Адрес:" << &value << "; " << "Значение:" << *value << ";\n";
}
int* add(int *value1, const int *value2) {
	*value1 += *value2;
	return value1;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a=7, b=5, c=3;
	info(&a);
	info(&b);
	info(&c);
	std::cout << msort(&a, &b, &c)<<"\n";
	*add(&b, &c);
	std::cout << *add(&a, &b);
	system("pause");
}
