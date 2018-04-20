// Чтобы консоль не закрывалась, можно использовать:
// system("pause");
// или подключить conio.h и использовать getch() 
// 



#include <stdio.h>// для printf, scanf
#include <locale.h>// для русской локализации

int main()
{
	setlocale(LC_ALL, "rus"); //русская локализация
	//setlocale(LC_ALL, "C")// для перехода на английский
	
	printf("Введите километры : ");
	long long km = 0;// переменные, которые мы используем лучше инициализировать
	scanf("%lli", &km);
	return 0; 
}
*********
#include <stdio.h>// для printf, scanf
#include <locale.h>// для русской локализации
int main()
{
	setlocale(LC_ALL, "rus"); //русская локализация
	int number = 9;
	printf("number / 2 = %i\n", number / 2);//простое деление
	printf("number %% 2 = %i\n", number % 2);//возвращает остаток от деления
	printf("number %% 3 = %i\n", number % 3);//можем использовать как проверку на кратность
	return 0; 
}
***************
#include <stdio.h>// для printf, scanf
#include <locale.h>// для русской локализации
int main()
{
	setlocale(LC_ALL, "rus"); //русская локализация
	int number = 9;
	printf("%i\n", number > 0 || number == 0);//простое деление

	printf("%i\n", number >= 0);
	printf("%i\n", number <= 10);//возвратит булевское значение
	printf("%i\n", number == 10);
	return 0; 
}
*************
Високосность лет определяется по номеру года
Нужно соблюсти 3 условия:
1. Каждый 4 год високосный.
2. Каждый 100 год не високосный.
3. Каждый 400 год високосный.
#include <stdio.h>// для printf, scanf
#include <locale.h>// для русской локализации
int main()
{
	setlocale(LC_ALL, "rus"); //русская локализация
	int year;
	scanf("%i", &year);	
	printf("%s\n", ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? "год високосный" : "год не високосный");	
	return 0; 
}
*****************************************************************************************
*****************************************************************************************
     Enum    //перечисляемый тип данных 
	 
	 //с его помощью можно делать меню с пользователем
#include <stdio.h>// для printf, scanf
#include <locale.h>// для русской локализации
enum Operator
{
	mts = 1,
	velcom,
	life,
	beltelecom
};
int main()
{
	enum Operator operatorFrom;
	enum Operator operatorTo;
	setlocale(LC_ALL, "rus"); //русская локализация
	printf("enter number: 1 - mts, 2 - vekcom, 3 - life, 4 - beltelecom\n");
	printf("Куда звоним? :\n");
	scanf("%i", &operatorTo);
	printf("%s", operatorTo == mts ? " mts \n" : " no mts \n");
	printf("%s", operatorTo == velcom ? " velcom \n" : " no velcom \n");
	printf("%s", operatorTo == life ? " life \n" : " no life \n");
	printf("%s", operatorTo == beltelecom ? " beltelecom \n" : " no beltelecom \n");
	printf("откуда звоним? :\n");
	scanf("%i", &operatorFrom);
	printf("%s", operatorFrom == mts ? " mts \n" : " no mts \n");
	printf("%s", operatorFrom == velcom ? " velcom \n" : " no velcom \n");
	printf("%s", operatorFrom == life ? " life \n" : " no life \n");
	printf("%s", operatorFrom == beltelecom ? " beltelecom \n" : " no beltelecom \n");	
	return 0; 
}

******************
****************** а можно и так

#include <stdio.h>// для printf, scanf
#include <locale.h>// для русской локализации
enum Operator
{
	mts = 1,
	velcom,
	life,
	beltelecom
};
int main()
{
	enum Operator operatorFrom;
	enum Operator operatorTo;
	setlocale(LC_ALL, "rus"); //русская локализация
	printf("enter number: 1 - mts, 2 - velcom, 3 - life, 4 - beltelecom\n");

	printf("Куда звоним? :\n");
	scanf("%i", &operatorTo);
	printf("%s", (operatorTo == mts) ? " mts \n" :
		(operatorTo == velcom) ? " velcom \n" :
		(operatorFrom == beltelecom) ? " beltelecom \n" :
		" нет такого оператора \n");
	
	printf("откуда звоним? :\n");
	scanf("%i", &operatorFrom);
	printf("%s", (operatorFrom == mts) ? " mts \n" :
		(operatorFrom == velcom) ? " velcom \n" :
		(operatorFrom == life) ? " life \n" :		
		(operatorFrom == beltelecom) ? " beltelecom \n" :
		" нет такого оператора \n");

	return 0; 
}




	 
	 
	 