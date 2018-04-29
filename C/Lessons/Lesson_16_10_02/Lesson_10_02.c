 Урок 10.02 Массивы, сортировка массивов. 
**********Сортировка пузырьком

1. Выводим массив на экран
2. Сортируем
3. Выводим отсортированный массив
Попробовал изменить кодировку
// 30 min
********** Моя версия ************

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

void printArray(int mas[], int count);
void sortArray(int mas[], int count);

int main( )
{
	setlocale(LC_ALL, "rus");
	int mas[] = { 2, 32, 123, 45, 23, 67, 82, 54, 5, 87 };
	int count = sizeof(mas) / sizeof(int);

	printArray( mas, count);
	sortArray(mas, count);
	printArray(mas, count);

	system("pause");
	return 0;
}

void printArray(int mas[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%i _ ", mas[i]);
	}
	printf("\n\n");
}
/*В самом простом варианте проходим по массиву N - 1 раз, в усовершенствованном вводим счетчик 
количества перестановок, если после прохода перестановок не было, то массив отсортирован и больше
проходов делать не нужно*/
void sortArray(int mas[], int count)
{
	int swap;
	for (int h = 0; h < count; h++)
	{
		for (int j = 0; j < count -1 - h; j++)
		{
			if (mas[j] < mas[j + 1])
			{
				swap = mas[j];				
			}
			else
			{
				swap = mas[j + 1];
				mas[j + 1] = mas[j];
			}
			mas[j] = swap;
			printf("%i _ ", mas[j]);
		}
		printf("\n\n");
	}
}

***************************** Версия Сергея ***********************************
/* 01.50.00*/

#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 10

//функция выводит массив на печать 
void printArray(float const array[], int arraySize);

/*Функция сортировки
Возвращает количество перестановок,
которые были совершены в процессе сортировки*/
int sortBubble(float array[], int arraySize);

/*Функция перестановки элементов массива*/
void swapElements(float const array[], int index1, int index2);

int main()
{
	float array[] = { 0.9, 1.0, 1.7, 9.0, 4.0, 2.0, 1.9, 1.2, 3.5, 4.3 };
	int const arraySize = sizeof(array) / sizeof(float);

	printArray(array, arraySize);

	int swapCount = sortBubble(array, arraySize);

	sortBubble(array, arraySize);

	printArray(array, arraySize);
	printf("swapCount = %i\n", swapCount);

	system("pause");

	return 0;
}

void printArray(float const array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%4.1f", array[i]);
	}
	printf("\n");
}

int sortBubble(float array[], int arraySize)
{
	int swapCount = 0;

	for (int i = 0; i < arraySize -1; i++)
	{
		for (int j = 0; j < arraySize - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapElements(array, j, j + 1);
				swapCount++;
			}
		}
	}
	return swapCount;
}

void swapElements(float array[], int index1, int index2)
{
	float buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}


***************************  Усовершенствованная версия  **********************************


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

*********************************************************************************************************
*********************************** второй проход *******************************************************
***************** моя версия ************************

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#define MASSIZE 20

int main()
{
	int myarray[MASSIZE];
	srand(time(0));
	bool flag = true;
	int buffer; // переменная для сортировки
	for (int i = 0; i < MASSIZE; i++)
	{
		myarray[i] = rand() % 25;
		printf("%2i ", myarray[i]);
	}
	printf("\n");

	/*check for recurrence
	проверка на повторение*/
	for (int i = 0; i < MASSIZE; i++)
	{
		int j = 0;
		while (j < i || flag == false)
		{
			if (myarray[j] == myarray[i])
			{
				myarray[i] = rand() % 25;
				j = 0;
				flag = false;
				continue;
			}
			flag = true;
			j++;
		}
		printf("%2i ", myarray[i]);
	}
	printf("\n");
	//сортировка

	for (int i = 0; i < MASSIZE; i++)
	{
		for (int j = 0; j < MASSIZE - 1 - i; j++)
		{
			if (myarray[j + 1] < myarray[j])
			{
				buffer = myarray[j + 1];
				myarray[j+1] = myarray[j];
				myarray[j] = buffer;
			}
			printf("%2i ", myarray[j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < MASSIZE; i++)
	{
		printf("%2i ", myarray[i]);
	}
	system("pause");
	return 0;
}

************************************* моя версия через функции ******************************************


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

*************************  базовая версия Сергея 1.50 *************************************************
//****************************************************************************************************************

#include<stdio.h>
#include<stdlib.h>
#define  ARRAY_SIZE 10 // размер массива

/*функция вывода на печать
функция принимает параметрами массив и его размер*/
void printArray(float const array[], int arraySize); 

/*сортировка пузырьком, функция сортировки
возвращает количество перестановок через
переменную swapCount*/
int sortBubble(float array[], int arraySize);

/*замена элементов
функция меняет местами значения элементов*/
void swapElements(float array[], int index1, int index2);

int swapCount = 0;

int main()
{
	float array[] = { 0.9, 1.0, 1.7, 9.0, 1.3, 2.0, 1.9, 4.5, 2.7, 3.4 };
	int const arraySize = sizeof(array) / sizeof(float);/* переменная хранит размер массива */

	printArray(array, arraySize);

	sortBubble(array, arraySize);

	int swapCount = sortBubble(array, arraySize);/* swapCount количество перестановок*/	

	printArray(array, arraySize);

	printf("swapCount = %i", swapCount);/*выводим на экран количество перестановок*/

	system("pause");
	return 0;
}

void printArray(float const array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%4.1f", array[i]);
	}
	printf("\n");
}

int sortBubble(float array[], int arraySize)
{
	
	for (int i = 0; i < arraySize -1; i++)
	{
		for (int j = 0; j < arraySize - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapElements(array, j, j + 1);
				printf("%4.1f", array[j]);
				swapCount++; 
			}
			
		}
		printf("\n");
	}
	return swapCount;
}

void swapElements(float array[], int index1, int index2)
{
	float buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}

****************************** усовершенствование 1 *********************************************
заполним массив случайными числами


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define  ARRAY_SIZE 10 // размер массива

/*функция вывода на печать
функция принимает параметрами массив и его размер*/
void printArray(float const array[], int arraySize); 

/*сортировка пузырьком, функция сортировки
возвращает количество перестановок через
переменную swapCount*/
int sortBubble(float array[], int arraySize);

/*замена элементов
функция меняет местами значения элементов*/
void swapElements(float array[], int index1, int index2);

/*заполнение массива случайными числами*/
void fillRandomArray(float array[], int arraySize);


int main()
{
	srand(time(0));
	float array[ARRAY_SIZE];

	fillRandomArray(array, ARRAY_SIZE);

	printArray(array, ARRAY_SIZE);

	sortBubble(array, ARRAY_SIZE);

	int swapCount = sortBubble(array, ARRAY_SIZE);/* swapCount количество перестановок*/	

	printArray(array, ARRAY_SIZE);

	printf("swapCount = %i\n", sortBubble(array, ARRAY_SIZE));/*выводим на экран количество перестановок*/

	system("pause");
	return 0;
}

void printArray(float const array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%5.1f", array[i]);
	}
	printf("\n");
}

int sortBubble(float array[], int arraySize)
{
	int swapCount = 0;
	for (int i = 0; i < arraySize -1; i++)
	{
		int trySwapCount = 0;//количество перестановок за попытку
		for (int j = 0; j < arraySize - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapElements(array, j, j + 1);				
				trySwapCount++; 
			}
			swapCount++;
		}
		if (trySwapCount == 0) //проверяем, были ли перестановки
		{
			break;
		}
		
	}
	printf("\n");
	return swapCount;
}

void swapElements(float array[], int index1, int index2)
{
	float buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}


void fillRandomArray(float array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 200 / 10;
	}
}

********************************* усовершенствование 2 ****************************************
модернизируем функцию sortBubble, чтобы она возвращала 2 значения
Если мы хотим вернуть 2 значения, мы можем вернуть массив


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define  ARRAY_SIZE 10 // размер массива

/*функция вывода на печать
функция принимает параметрами массив и его размер*/
void printArray(float const array[], int arraySize); 

/*сортировка пузырьком, функция сортировки
возвращает количество перестановок через
массив sortResults[3]*/
void sortBubble(float array[], int arraySize, int sortResults[]);

/*замена элементов
функция меняет местами значения элементов*/
void swapElements(float array[], int index1, int index2);

/*заполнение массива случайными числами*/
void fillRandomArray(float array[], int arraySize);


int main()
{
	srand(time(0));
	float array[ARRAY_SIZE];
	fillRandomArray(array, ARRAY_SIZE);
	printArray(array, ARRAY_SIZE);

	int sortResults[3]; //массив для возвращаемого значения функцией sortBubble

	sortBubble(array, ARRAY_SIZE, sortResults);			

	/*выводим на экран количество перестановок и количество проверок */
	printf("swapCount = %i , tryCount = %i\n", sortResults[0], sortResults[1]);
	printArray(array, ARRAY_SIZE);
	system("pause");
	return 0;
}

void printArray(float const array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%5.1f", array[i]);
	}
	printf("\n");
}

void sortBubble(float array[], int arraySize, int sortResults[])
{
	sortResults[0] = 0;// в нулевом значении мы храним количество совершенных перестановок
	sortResults[1] = 0;//количество проверок
	for (int i = 0; i < arraySize -1; i++)
	{
		sortResults[2] = 0;// количество совершенных перестановок в данной итерации
		for (int j = 0; j < arraySize - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapElements(array, j, j + 1);				
				sortResults[0]++;
				sortResults[2]++;
			}
			sortResults[1]++;
		}
		if (sortResults[2] == 0)//если перестановок не было, массив отсортирован
		{
			break;
		}
		printArray(array, ARRAY_SIZE);//для наглядности
	}
	printf("\n");
	
}

void swapElements(float array[], int index1, int index2)
{
	float buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}

void fillRandomArray(float array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 200 / 10;
	}
}


********************************* усовершенствование 3 ******************************************
через enum ( НЕ РАБОТАЕТ В С++ !!!)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void printArray(float const array[], int arraySize);
void sortBubble(float array[], int arraySize,
	enum SortResult sortResults[]);
void swapElements(float array[], int index1, int index2);
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
	printf("swapCount = %i, compareCount = %i\n",
		sortResults[SortResultSwapCount],
		sortResults[SortResultCompareCount]);

	printArray(array, ARRAY_SIZE);

	system("pause");
	return 0;
}

void printArray(float const array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%5.1f", array[i]);
	}
	printf("\n");
}

void sortBubble(float array[], int arraySize,
	enum SortResult sortResults[])
{
	sortResults[SortResultCompareCount] = 0;
	sortResults[SortResultSwapCount] = 0;

	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = 0; j < arraySize - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapElements(array, j, j + 1);
				sortResults[SortResultSwapCount]++;
			}

			sortResults[SortResultCompareCount]++;
		}
		if (sortResults[SortResultSwapCount] == 0)
		{
			break;
		}
	}
}

void swapElements(float array[], int index1, int index2)
{
	float buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}

void fillRandomArray(float array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 200 / 10;
	}
}



********************* сортировка методом вставок ****************************

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MASSIZE 20

void fillArray(int array[], int arraySize);//заполнение массива

void swap(int array[], int index1, int index2);//обмен элементов

void printArray(int array[], int arraySize);//вывод на экран

void checkOnRepeat(int array[], int arraySize);//проверка на повтор


int main()
{	
	int myarray[MASSIZE];
	fillArray(myarray, MASSIZE);
	printArray(myarray, MASSIZE);
	printf("\n");
	checkOnRepeat(myarray, MASSIZE);
	printArray(myarray, MASSIZE);
	printf("\n");
	
	for (int i = 0; i < MASSIZE - 1; i++)//первый цикл проход слева направо как в пузырьке
	{
		if (myarray[i] > myarray[i + 1]) //если текущий элемент больше следующего, 
		{
			swap(myarray, i, i+1);// мы делаем перестановку, протягиваем большее значение вправо,
			//на каждой замене нам нужно делать проверку текущего значения i и идти влево до самого максимального
			//значения
			//после перестановки нам нужен еще один цикл
			int j = i;/*заведем управляющую переменную j для 
					  нашего цикла проверки влево,
					  она будет равна текущей позиции
					  */
			int buffs = myarray[i];/*заведем буферную переменную для текущего значения 
								   для последующих перестановок в левой части массива*/
			while (j > 0 && myarray[j-1] > buffs)/*будем идти влево пока j больше 0
											   и пока предыдущий элемент больше значения buffs*/
			{
				myarray[j] = myarray[j - 1];/*записываем в текущий элемент значение предыдущего*/
				j--;
			}
			myarray[j] = buffs;/*здесь мы дошли до наименьшего значения, 
							   которое больше значения буфера и меняем его 
							   на значение буфера*/
		}
		printArray(myarray, MASSIZE);/*для мониторинга */
		printf("\n");
	}	
	printf("\n");

	printArray(myarray, MASSIZE);	

	// 2.37
	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////
void printArray(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%2i ", array[i]);
	}
	printf("\n");
}
////////////////////////////////////////////////////////////////////
void swap(int array[], int index1, int index2)
{
	int buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}

//////////////////////////////////////////////////////////
void checkOnRepeat(int array[], int arraySize)
{
	bool flag = true;
	for (int i = 0; i < arraySize; i++)
	{
		int j = 0;
		while (flag == false || j < i)
		{
			if (array[j] == array[i])
			{
				array[i] = rand() % 15;
				flag = false;
				j = 0;
				continue;
			}
			flag = true;
			j++;
		}		
	}
}
/////////////////////////////////////////////////////////////////////
void fillArray(int array[], int arraySize)
{
	srand(time(0));
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % (arraySize + 5);		
	}	
}






