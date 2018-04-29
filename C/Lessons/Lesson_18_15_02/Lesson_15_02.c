/*Быстрая сортировка попробовать
********************************4
В С++ есть заголовочный файл algoritm. В нем много разных алгоритмов и в частности алгоритм сортировки
Многомерные массивы 52минуты

*************** задача **********************
получить массив от пользователя и вывести его на экран в виде таблицы



*/
*************************************************************************************
int matrix[2][5] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < 2; i++)/*в многомерных массивах сколько измерений,
							   столько и форов понадобится*/
	{
		for (int j = 0; j < 5; j++)
		{
			printf("matrix[%i][%i] = %i\n", i, j, matrix[i][j]);
		}
	}
	
*************************************************************************************


*************** задача **********************
получить массив от пользователя и вывести его на экран в виде таблицы*/

#include<stdio.h>

void fillUserMatrix(int array[2][5]);
void printArray(int array[2][5]);

int main()
{
	int matrix[2][5];
	fillUserMatrix(matrix);
	printArray(matrix);
	
	return 0;
}

void fillUserMatrix(int array[2][5])
{
	for (int i = 0, f = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++, f++)
		{
			printf("enter the value of the %i array element: ", f);/*введите значение элемента массива*/
			scanf("%i", &array[i][j]);
		}
	}
}

void printArray(int array[2][5])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%5i  ", array[i][j]);
		}
		printf("\n");
	}
}

******************* вторая задача **********************************************
/*
************************** 2 задача 2.24************************
Есть 2 массива:
массив А состоящий из 3 элементов
массив В состоящий из 4 элементов
Нужно скопировать их в многомерный массив*/


#include<stdio.h>
#include<limits.h>

#define ARRAY_A_SIZE 3
#define ARRAY_B_SIZE 4

void printArray(int array[2][4]);

int main()
{
	int arrayA[3] = { 1, 2, 3 };
	int arrayB[4] = { 4, 5, 6, 7 };
	int arrayC[2][
		ARRAY_A_SIZE > ARRAY_B_SIZE ?
			ARRAY_A_SIZE : ARRAY_B_SIZE]; /*нам нужен еще 3 массив, у которого будет 2 строки 
										  и размерность равная большему из этих двух*/
	int const arrayCSize = ARRAY_A_SIZE > ARRAY_B_SIZE ?/*засунем размерность в переменную,
														потому что мы ее будем использовать в циклах*/
		ARRAY_A_SIZE : ARRAY_B_SIZE;

	/**/

	int const ARRAY_C_COLUMNS = 2;

	for (int i = 0; i < ARRAY_C_COLUMNS; i++)
	{
		for (int j = 0; j < arrayCSize; j++)
		{
			if (j < ARRAY_A_SIZE)
			{
				arrayC[0][j] = arrayA[j];
			}
			else
			{
				arrayC[0][j] = INT_MIN;
			}
			if (j < ARRAY_B_SIZE)
			{
				arrayC[1][j] = arrayB[j];
			}
		}
	}
	
	/*
	for (int j = 0; j < arrayCSize; j++)// можно и одним циклом
		{
			if (j < ARRAY_A_SIZE)
			{
				arrayC[0][j] = arrayA[j];
			}
			else
			{
				arrayC[0][j] = INT_MIN;
			}
			if (j < ARRAY_B_SIZE)
			{
				arrayC[1][j] = arrayB[j];
			}
		}*/
	
	

	printArray(arrayC);	

	return 0;
}

void printArray(int array[2][4])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%i  ", array[i][j]);
		}
		printf("\n");
	}
}

************************************** через функцию *****************************************

#include<stdio.h>
#include<limits.h>

#define ARRAY_A_SIZE 3
#define ARRAY_B_SIZE 4

void printArray(int array[2][4]);// вывод на печать

void joinArray(int arrayA[], int arrayB[], int arrayC[2][4],
	int arrayASize, int arrayBSize, int arrayCSize);

int main()
{
	int arrayA[ARRAY_A_SIZE] = { 1, 2, 3 };
	int arrayB[ARRAY_B_SIZE] = { 4, 5, 6, 7 };
	int arrayC[2][ARRAY_A_SIZE > ARRAY_B_SIZE ?	ARRAY_A_SIZE : ARRAY_B_SIZE];
	int const arrayCSize = ARRAY_A_SIZE > ARRAY_B_SIZE ? ARRAY_A_SIZE : ARRAY_B_SIZE;		

	joinArray(arrayA, arrayB, arrayC, ARRAY_A_SIZE, ARRAY_B_SIZE, arrayCSize);	

	printArray(arrayC);	

	return 0;
}

void printArray(int array[2][4])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%i  ", array[i][j]);
		}
		printf("\n");
	}
}

void joinArray(int arrayA[], int arrayB[], int arrayC[2][4],
	int arrayASize, int arrayBSize, int arrayCSize)
{	
	for (int i = 0; i < arrayCSize; i++)
	{
		arrayC[0][i] = i < arrayASize ? arrayA[i] : INT_MIN;
		arrayC[1][i] = i < arrayBSize ? arrayB[i] : INT_MIN;
	}
}