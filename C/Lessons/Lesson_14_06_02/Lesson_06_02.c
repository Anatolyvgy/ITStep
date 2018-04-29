//Одномерные статические массивы 1.00
//scope and lifetime of variables

#include<stdio.h>
#include"Random.h"

int main( )
{
	int mass[3] = {12, 23, 65}; // инициализация массива
	int const mass[3] = {12, 23, 65}; // неизменяемый массив или используя #define
	int mass[] = {2,5,67,234,121};/* можно не указывать размер массива, но тогда мы 
	обязаны прописать значения в фигурных скобках, их можно добавлять потом и компилятор
	сам подстроится под размер*/
	int const masCount = sizeof(mass) / sizeof(int));/*так можно найти размер массива*/
	printf("%i", sizeof(mass) / sizeof(int));
}	
// Одномерные статические массивы 1.00

/*Задача:
Пользователь наблюдает за температурными изменениями в течение недели. Он вводит с консоли
7 значений температуры, они будут вещественными. Эти значения надо поместить в вещественный
массив. Далее нужно посчитать среднее значение температуры за неделю.*/

//#include<stdio.h>
//#include<locale.h>
//#include<stdlib.h>
//
//#define WEEK 7
//
//int main( )
//{
//	setlocale(LC_ALL, "rus");
//	float average_temperature = 0;
//	
//	float temperature[WEEK];
//	for (int i = 0; i <= WEEK - 1; i++)
//	{
//		printf("Введите значение температуры за %i день в формате 0,00\n", i + 1);		
//		scanf("%f", &temperature[i]);
//		average_temperature += temperature[i];
//	}
//	printf("Средняя температура за неделю %.2f\n", average_temperature / WEEK);
//	system("pause");
//	return 0;
//}

********************************************************************************

// Теперь найти наименьшее и наибольшее значение
// Решение Сергея 2.22.00

#include <stdio.h>
#define DAYS_COUNT 7

int main( )
{

	float temperatures[DAYS_COUNT];
	float summ =0;
	//float minTemperature = 0;// первое решение
	//float maxTemperature = 0;
	for (int i = 0; i < DAYS_COUNT -1; i++)
	{
		printf("Please enter temperature for %i day\n", i + 1);
		scanf("%f", &temperatures[i]);
		summ += temperatures[i];

		if (i == 0) //второе решение
		{
			minTemperature = temperatures[i];
			maxTemperature = temperatures[i];
		}


		if (minTemperature > temperatures[i])  //первое решение
		{
			minTemperature = temperatures[i];
		}

		if (maxTemperature < temperatures[i])
		{
			maxTemperature = temperatures[i];
		}

		
	}

	printf("Average temperature: %.2f\n", summ / DAYS_COUNT);
	printf("Minimum temperature : %.2f\n", minTemperature);
	printf("Maximum temperature : %.2f\n", maxTemperature);

	return 0;

}

****************************************************************************


//#define DAYS_COUNT 7
//
//float findAverageTemperature(float temperatures[ ]);
//float findMaximumTemperature(float temperatures[ ]);
//float findMinimumTemperature(float temperatures[ ]);
//
//int main( )
//{
//	float temperatures[DAYS_COUNT];
//
//
//	float minTemperature;
//	float maxTemperature;
//
//	for (int i = 0; i < DAYS_COUNT; i++)
//	{
//		printf("Please enter temperature "
//			"for %i day: ", i + 1);
//		scanf("%f", &temperatures[i]);
//
//		if (i == 0)
//		{
//			minTemperature = temperatures[i];
//			maxTemperature = temperatures[i];
//		}
//
//		if (minTemperature > temperatures[i])
//		{
//			minTemperature = temperatures[i];
//		}
//		if (maxTemperature < temperatures[i])
//		{
//			maxTemperature = temperatures[i];
//		}
//	}
//
//	float const averageTemperature =
//		findAverageTemperature(temperatures);
//
//	printf("Average temperature: %.2f\n",
//		averageTemperature);
//	printf("Maximum temperature: %.2f\n",
//		maxTemperature);
//	printf("Minimum temperature: %.2f\n",
//		minTemperature);
//}
//
//float findAverageTemperature(float temperatures[ ])
//{
//	float summ = 0;
//	for (int i = 0; i < DAYS_COUNT; i++)
//	{
//		summ += temperatures[i];
//	}
//	return summ / DAYS_COUNT;
//}











