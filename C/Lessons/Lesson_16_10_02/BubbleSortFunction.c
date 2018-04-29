#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MASSIZE 20

void fillArray(int array[], int massize);/*заполнение массива*/

/*проверка элементов на повтор*/
void checkOnRepeat(int array[], int massize, bool flag);

/*вывод массива на экран*/
void printArray(int array[], int massize);

void sortArray(int array[], int massize);/*сортировка*/

/*обмен элементов*/
void eschange(int array[], int i, int j);

//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	srand(time(0));
	bool flag = true;//флаг для проверки на повторяемость

	int myarray[MASSIZE];

	fillArray(myarray, MASSIZE);

	printArray(myarray, MASSIZE);

	checkOnRepeat(myarray, MASSIZE, flag);

	printArray(myarray, MASSIZE);

	sortArray(myarray, MASSIZE);

	printArray(myarray, MASSIZE);

	system("pause");
	return 0;

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void printArray(int array[], int massize)
{
	for (int i = 0; i < massize; i++)
	{
		printf("%2i", array[i]);
	}
	printf("\n");
}

void eschange(int array[], int i, int j)
{
	int buffer = array[i];	//переменная для замены
	array[i] = array[j];
	array[j] = buffer;
}

void checkOnRepeat(int array[], int massize, bool flag)
{
	for (int i = 0; i < massize; i++)
	{
		int j = 0;
		while (j < i || flag == false)
		{
			if (array[j] == array[i])
			{
				array[i] = rand() % 25;
				j = 0;
				flag = false;
				continue;
			}
			flag = true;
			j++;
		}
		printf("%2i ", array[i]);
	}
	printf("\n");
}

void fillArray(int array[], int massize)
{
	for (int i = 0; i < massize; i++)
	{
		array[i] = rand() % 25;
		printf("%2i ", array[i]);
	}
	printf("\n");
}

void sortArray(int array[], int massize)
{
	for (int i = 0; i < massize; i++)
	{
		for (int j = 0; j < massize - 1 - i; j++)
		{
			if (array[j + 1] < array[j])
			{
				eschange(array, j, j + 1);
			}
			printf("%2i ", array[j]);
		}
		printf("\n");
	}
	printf("\n");
}