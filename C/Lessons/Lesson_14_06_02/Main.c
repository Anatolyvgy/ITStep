// Одномерные статические массивы 1.00

/*Задача:
Пользователь наблюдает за температурными изменениями в течение недели. Он вводит с консоли
7 значений температуры, они будут вещественными. Эти значения надо поместить в вещественный
массив. Далее нужно посчитать среднее значение температуры за неделю.*/


// Теперь найти наименьшее и наибольшее значение
// Решение Сергея 2.22.00 использование функций

#include <stdio.h>
//#include<stdlib.h>
#include "func.h"
#define DAYS_COUNT 7

int main( )
{
	float temperatures[DAYS_COUNT];

	for (int i = 0; i < DAYS_COUNT; i++)
	{
		printf("Please enter temperature for %i day\n", i + 1);
		scanf("%f", &temperatures[i]);
	}

	printf("Average temperature: %.2f\n", FindAverageTemperature(temperatures));
	printf("Minimum temperature : %.2f\n", FindMinimumTemperature(temperatures));
	printf("Maximum temperature : %.2f\n", FindMaximumTemperature(temperatures));

	return 0;
}