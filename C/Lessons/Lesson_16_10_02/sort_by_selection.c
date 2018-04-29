
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10

void printArray(float const array[], int arraySize);
void sortBubble(float array[], int arraySize, enum SortResult sortResults[]);
void swapElements(float const array[], int index1, int index2);
void fillRandomArray(float array[], int arraySize);
 
enum SortResult
{
	SortResultSwapCount = 0,
	SortResultCompareCount,
	SortResultCount
};

int main()
{
	srand(time(0));
	float array[ARRAY_SIZE];	
	fillRandomArray(array, ARRAY_SIZE);	

	printArray(array, ARRAY_SIZE);	

	enum SortResult sortResults[SortResultCount];
	
	sortBubble(array, ARRAY_SIZE, sortResults);	

	/*так выведем количество перестановок*/
	printf("swapCount = %i, compareCount = %i\n",
		sortResults[SortResultSwapCount],
		sortResults[SortResultCompareCount]);	

	printArray(array, ARRAY_SIZE);	

	system("pause");
	return 0;
}

/*функция выводит массив на печать*/
void printArray(float const array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%5.1f", array[i]);
	}
	printf("\n");
}

/*Функция сортировки
Возвращает количество перестановок,
которые были совершены в процессе сортировки*/
void sortBubble(float array[], int arraySize, enum SortResult sortResults[])
{
	sortResults[SortResultCompareCount] = 0;
	sortResults[SortResultSwapCount] = 0;

	for (int i = 0; i < arraySize -1; i++)
	{
		for (int j = 0; j < arraySize - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapElements(array, j, j + 1);
				sortResults[SortResultSwapCount]++;
			}
			
			sortResults[SortResultSwapCount]++;
		}

		if (sortResults[SortResultSwapCount] == 0)
		{
			break;
		}
	}	
}

/*Функция перестановки элементов массива*/
void swapElements(float array[], int index1, int index2)
{
	float buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}

/*Функция заполняет массив случайными числами*/
void fillRandomArray(float array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 200 / 10;
	}
}



