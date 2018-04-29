// Курс «Язык программирования C»
// Неделя №4, день №1 (9 января 2017)
// Тема: switch/enum
// Домашнее задание
// Задание 1
// Пользователь вводит с клавиатуры символ. Определить, какой это символ: Буква, цифра,
// знак препинания или другое.
// Задание 2
// Написать программу подсчета стоимости разговора для разных мобильных операторов.
// Пользователь вводит время разговора и выбирает с какого на какой оператор он
// звонит. Вывести стоимость на экран.
// Задание 3
// Написать программу определения названия свадебного юбилея в зависимости от
// продолжительности совместной жизни в браке. Пользователь вводит количество лет в
// годах, а программа делает вывод, является ли указанный период юбилейным и выводит его
// название в этом случае.

Задание 1

#include<stdio.h>
#include<locale.h>
//#include<stdlib.h>

int main()
{
	setlocale(LC_ALL, "rus");
	char ch = 0;
	printf("Введите символ \n");
	scanf("%c", &ch);
	if (ch == ',' || ch == '.' || ch == ';')
	{
		printf(" Это знак препинания \n");
	}

	if (ch >= 'A' && ch <= 'Z')
	{
		printf(" Это заглавная латинская буква \n");
	}
	
	if (ch >= 'a' && ch <= 'z')
	{
		printf(" Это строчная латинская буква \n");
	}	

	if (ch >= '0' && ch <= '9')
	{
		printf(" Это цифра \n");
	}

	/*int a = 0;
	while (a < 256)
	{
		printf("%d соответствует %c\n", a, a);
		a++;
	}*/	
	return 0;
}

//*******************************************************************
Задание 2

// Написать программу подсчета стоимости разговора для разных мобильных операторов.
// Пользователь вводит время разговора и выбирает с какого на какой оператор он
// звонит. Вывести стоимость на экран.


#include<stdio.h>
#include<locale.h>
enum Operators
{
	MTS = 1,
	VELCOM,
	BELTELECOM,
	LIFE	
};

int main()
{
	setlocale(LC_ALL, "rus");
	int user_Time;
	int price_In;
	

	printf("Введите время разговора в минутах: \n");
	scanf("%d", &user_Time);
	
	printf("Выберите оператора исходящего вызова: \n");
	printf("1 - MTS\n");
	printf("2 - VELCOM\n");
	printf("3 - BELTELECOM\n");
	printf("4 - LIFE\n");

	enum Operators Call_In;
	scanf("%d", &Call_In);

	printf("Выберите оператора входящего вызова: \n");
	
	enum Operators Call_To;
	scanf("%d", &Call_To);
	
	switch (Call_In)
	{
	case MTS:
	{
		switch (Call_To)
		{
		case MTS:
			price_In = 10;
			break;
		case VELCOM:
			price_In = 110;
			break;
		case BELTELECOM:
			price_In = 110;
			break;
		case LIFE:
			price_In = 110;
			break;
		default:
			printf("Такого оператора нет в списке\n");
			break;
		}
		break;
	}
	case VELCOM:
	{

		switch (Call_To)
		{
		case MTS:
			price_In = 210;
			break;
		case VELCOM:
			price_In = 30;
			break;
		case BELTELECOM:
			price_In = 210;
			break;
		case LIFE:
			price_In = 210;
			break;
		default:
			printf("Такого оператора нет в списке\n");
			break;
		}
		break;
	}
	case BELTELECOM:
	{

		switch (Call_To)
		{
		case MTS:
			price_In = 230;
			break;
		case VELCOM:
			price_In = 250;
			break;
		case BELTELECOM:
			price_In = 25;
			break;
		case LIFE:
			price_In = 160;
			break;
		default:
			printf("Такого оператора нет в списке\n");
			break;
		}
		break;
	}
	case LIFE:
	{

		switch (Call_To)
		{
		case MTS:
			price_In = 210;
			break;
		case VELCOM:
			price_In = 210;
			break;
		case BELTELECOM:
			price_In = 210;
			break;
		case LIFE:
			price_In = 20;
			break;
		default:
			printf("Такого оператора нет в списке\n");
			break;
		}
		break;
	}

	default:
		//printf("Такого оператора нет в списке\n");
		break;
	}

	printf("Стоимость разговора %d рублей\n", price_In * user_Time);
	//system("pause");
	return 0;
}


//********************************************************************

Задание 3

#include<stdio.h>
#include<locale.h>
enum Wedding
{
	Calico = 1, //ситцевая 1 год
	Paper,      //бумажная 2 года     
	Leather,    //кожаная 3 года
	Linen,      //льняная 4 года
	Wooden,     //деревянная 5 лет
	Iron,       //чугунная 6 лет
	Copper,     //медная 7 лет
	Tinny,      //жестяная 8 лет
	Porceline,  //фаянсовая 9 лет
	Pewter,     //оловянная 10 лет
	Still,      //стальная 11 лет
	Nickel,     //никелевая 12 лет
	Lace,       //кружевная 13 лет
	Agate,      //агатовая 14 лет
	Crystal,    //кристальная 15 лет
	Topaz,      //топазовая 16 лет 
};

int main()
{
	setlocale(LC_ALL, "rus");
	
	enum  Wedding Wedding_anniversary; //годовщина свадьбы
	printf("Введите количество совместно прожитых лет: ");
	scanf("%d", &Wedding_anniversary);
	switch (Wedding_anniversary)
	{
	case Calico:
		printf("Это ситцевая свадьба \n");
		break;
	case Paper:
		printf("Это бумажная свадьба \n");
		break;
	case Leather:
		printf("Это кожаная свадьба \n");
		break;
	case Linen:
		printf("Это льняная свадьба \n");
		break;
	case Wooden:
		printf("Это деревянная свадьба \n");
		break;
	case Iron:
		printf("Это чугунная свадьба \n");
		break;
	case Copper:
		printf("Это медная свадьба \n");
		break;
	case Tinny:
		printf("Это жестяная свадьба \n");
		break;
	case Porceline:
		printf("Это фаянсовая свадьба \n");
		break;
	case Pewter:
		printf("Это оловянная свадьба \n");
		break;
	case Still:
		printf("Это стальная свадьба \n");
		break;
	case Nickel:
		printf("Это никелевая свадьба \n");
		break;
	case Lace:
		printf("Это кружевная свадьба \n");
		break;
	case Agate:
		printf("Это агатовая свадьба \n");
		break;
	case Crystal:
		printf("Это кристальная свадьба \n");
		break;
	case Topaz:
		printf("Это топазовая свадьба \n");
		break;
	default:
		printf("Этот год не является юбилейным \n");
		break;
	}
	return 0;
}