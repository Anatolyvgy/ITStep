**********************************  Функции  ****************************************
/* Dependency Walker - бесплатная утилита, которая сканирует любой 32-разрядный или 64-битный 
Windows-модуль (exe, dll, ocx, sys и т. Д.) И создает иерархическую древовидную диаграмму всех 
зависимых модулей. Для каждого найденного модуля перечислены все функции, которые экспортируются
 этим модулем, и какие из этих функций фактически вызывают другие модули. В другом представлении
 отображается минимальный набор требуемых файлов, а также подробная информация о каждом файле,
 включая полный путь к файлу, базовый адрес, номера версий, тип машины, отладочную информацию 
 и т. Д. 
 
 http://dependencywalker.com/
 
 Если программа не запускается или не работает, то открыв ее в этой утилите мы увидим каких 
 библиотек или зависимостей не хватает. 
 */
 
 ***********************************************************************
 //Нужно стремиться давать функциям понятные имена, отображающие то, что функция делает
 
 *********************************************************************************
 // Лучше не нагружать функцию лишними действиями
 // Лучше разбить задачу на несколько конкретных функций
Синтаксис обьявления и определения функции

//int main ()  обьявление функции
/* int main() определение функции
   {   }*/

int foo( );// функция возвращает значение типа int и не принимает аргументов
int foo2( );
int add(int a, int b);//функция возвращает значение типа int и принимает 2 аргумента


#include<stdio.h>
int main( )
{
	foo( );
	foo2( );
	int const a = 12;
	int const b = 6;
	int result = add(a, b);
	printf("%i + %i = %i\n", a, b, result);
	system("pause");
	return 0;
}

int add(int a, int b)
{
	int result = a + b;
	printf("%i\n", result);
	return result;
}

int foo( )
{
	printf("my name is foo\n");
}

int foo2( )
{
	printf("my name is foo2\n");
}

/* сделать калькулятор
*/


#include<stdio.h>
enum Operations;
int showMenu(void);
float calculate(int a, int b, enum Operations operation);
int number1;
int number2;
enum Operations operation;
int enterNumber1( );
int enterNumber2( );
//*********************************************
int main( )
{	
	showMenu( );
	enterNumber1( );
	enterNumber2( );
	//calculate(number1, number2, operation);
	int result = calculate(number1, number2, operation);
	printf("Obtained result = %i\n", result);
	system("pause");
	return 0;
}

//*********************************************
enum Operations
{
	addition = 1,     // сложение
	subtraction,      // вычитание
	multiplication,   // умножение
	division          // деление
};

int showMenu(void)
{
	printf("Is a calculator program\n"); // Это программа калькулятор
	printf("What math operation you want to perform?\n");  //Какое арифметическое действие вы хотите совершить
	printf(" 1 - addition\n 2 - subtraction\n 3 - multiplication\n 4 - division\n ");
	scanf("%i", &operation);
	return operation;
}

float calculate(int a, int b, enum Operations operation)
{
	int result;
	a = number1;
	b = number2;
	switch (operation)
	{
	case addition:
		{
		result = a + b;
		break;
		}
	case subtraction:
	{
		result = a - b;
		break;
	}
	case multiplication:
	{
		result = a * b;
		break;
	}
	case division:
	{
		if (number2 == 0)
		{
			printf("on 0 you can not divide\n");//на ноль делить нельзя
			break;
		}
		else
		{
			result = a / b;
			break;
		}
	}
	
	}

	return result;
}

int enterNumber1( )
{
	printf("enter the first number:\n");
	scanf("%i", &number1);
	return number1;
}

int enterNumber2( )
{
	printf("enter the first number:\n");
	scanf("%i", &number2);
	return number2;
}

/* должны быть 4 функции, 1 на каждое арифметическое действие 
не использовать глобальные переменные*/
