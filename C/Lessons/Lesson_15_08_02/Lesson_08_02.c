/****************        Статический одномерный массив
sizeof(mass) / sizeof(int) - узнать количество элементов массива, т. к. sizeof возвращает размер в байтах
#define MASSIZE 9
mass[9] - то что в квадратных скобках должно иметь константное свойство. В С++ можно использовать 
модификатор const для переменной, но он не работает в С. Поэтому нам нужно использовать define
mass[MASSIZE] 
*********************************
**************            Передача массива в функцию            

Если функция не изменяет значения элементов массива, то в обьявлении массива и в определении и 
обявлении функции нужно указать const перед именем массива, чтобы не поменять ченить по ошибке*/

#include<stdio.h>
#define DAYS_COUNT 7

void printArray(int mas[ ], int count);

int main( )
{
	int mas[ ] = { 123, 345, 567, 678, 358, 
		123, 345, 567, 678, 358,
		123, 345, 567, 678, 358,
		123, 345, 567, 678, 358,
		123, 345, 567, 678, 358 };
	
	int const masCount = sizeof(mas) / sizeof(int);// находим размер массива
	printf("size of massive = %i \n", masCount);	

	printArray(mas, masCount);
	
	system("pause");
	return 0;
}

/*
	Prints array.
	Args:
		int mas[] - pointer to array
		int count - конечное число массива
*/
void printArray(int mas[ ], int count)//если оставить комментарий перед функцией или перед  
{ // обьявлением функции, студия покажет его при наведении курсора на эту функцию в любом месте программы
	for (int i = 0; i < count; i++)
	{
		printf("mas[%i] = %i\n", i, mas[i]);
	}
}

/*  ******    Задание на урок №1    ******** 
47минут*/

/**  ******    Задание на урок    ********
 Написать программу, в которой пользователь вводит 10 целых чисел. После чего программа выводит на экран
 количество ненулевых элементов. Перед вводом и выводом каждого элемента массива должна выводится подсказка
 с номером элемента массива. Когда мы найдем ненулевые элементы массива, должны быть выведены позиции этих
 элементов. Ввод и вывод значенией массива реализовать через отдельные функции. 
47минут*/
#define WILL 10
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>


/*ввод значений элементов массива*/
void entering_values(int array[ ]);

/*Вывод значений элементов массива*/
void output_values(int array[ ]);

/*поиск ненулевых символов*/
void goodElement(int array[ ]);

int myarray[WILL];

int main( )
{
	setlocale(LC_ALL, "rus");

	entering_values(myarray[WILL]);
	output_values(myarray[WILL]);
	goodElement(myarray[WILL]);

	system("pause");
	return 0;
}
/*ввод значений элементов массива*/
void entering_values(int array[ ])
{
	for (int i = 0; i < WILL; i++)
	{
		printf("Введите значение %i элемента массива:", i+1);
		scanf("%i", &myarray[i]);
	}
	printf("ok\n\n");
}
/*вывод значений элементов массива на экран*/
void output_values(int array[ ])
{
	for (int i = 0; i < WILL; i++)
	{
		printf("%i элемент массива содержит значение %i\n", i, myarray[i]);		
	}
	printf("ok\n\n");
}
/*вывод на экран ненулевых элементов */
void goodElement(int array[ ])
{
	for (int i = 0; i < WILL; i++)
	{
		if (myarray[i] % 10 != 0)
		{
			printf("%i элемент массива содержит ненулевое значение %i\n", i, myarray[i]);
		}
		
	}
	printf("ok\n\n");
}

*****************************************************************************

//Вариант Сергея
// Если вставлять комментарий перед функцией или переменной то при наведении курсора студия покажет его
//программа monosnap для записи видео и скриншотов экрана
#include<stdio.h>
#include<stdlib.h>
//#include<locale.h>

void printArray(int mas[ ], int count);

int main( )
{
	//setlocale(LC_ALL, "rus");
	int mas[ ] = { 121, 33, 345, 556, 34, 567, 432, 34, 55, 67, 89 };
	int const count = sizeof(mas) / sizeof(int);

	//printf("%i\n", sizeof(mas));
	// здесь sizeof указывает и выведет значение первого элемента массива
	printArray(mas, count);

	system("pause");
	return 0;

}

void printArray(int const mas[ ], int count)
{
	//printf("%i\n", sizeof(mas));
	//здесь выводится указатель на первый элемент массива(размер типа)
	for (int i = 0; i < count; i++)
	{
		printf("mas[%i] = %i\n", i, mas[i]);
	}
}

********************************************************************************************

/*  ******    Задание на урок 2   ******** 
1 час 09 минут

Есть массив. Он задан в коде программы. Элементы массива все разные. Можно задать случайные значения,
но тогда нужно включить элемент неповторяемости. Задача найти среднее арифметическое без учета минимального и 
максимального элементов*/
//???функция принимает любой массив 
//#include<stdio.h>
//#define ARRAY1 10
//#define ARRAY2 20
///*заполнение массива*/
//void fillArray(int mas[ ], int count);
//
//int main( )
//{ 
//	int mas[ARRAY1];
//	int mas2[ARRAY2];
//	//int const count = sizeof(mas) / sizeof(int);
//
//}
//
//void fillArray(int mas[ ], int count)
//{
//	count = sizeof(mas) / sizeof(int);
//}

*********************************************************************************************

/*Решение Сергея 2.23*/

#include<stdio.h>
#define MAS_SIZE 10

/*заполнение массива*/
void fillArray(int mas[], int size);

/*Выводим на экран ненулевые элементы*/
void printNonZeroElements(int mas[ ], int size);

int main( )
{
	int mas[MAS_SIZE];	
	fillArray(mas, MAS_SIZE);	
	printNonZeroElements(mas, MAS_SIZE);
	return 0;
}

void fillArray(int mas[ ], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Enter %d number: \n", i + 1);
		scanf("%d", &mas[i]);
	}

}

void printNonZeroElements(int mas[ ], int size)
{
	int i = 0;
	while (i < size)
	{
		if (mas[i] != 0)
		{
			printf("%i element = %i\n", i + 1, mas[i]);
		}		
		i++;
	}
}

**************************************************************

/**обзор ошибок 2.45 
При вызове функции в параметрах указываем просто имя массива без всяких скобок и
типов данных.
Нужно стараться передать размерность массива отдельным параметром
*/



