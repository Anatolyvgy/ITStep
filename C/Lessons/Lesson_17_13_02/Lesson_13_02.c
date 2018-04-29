
********************* сортировка методом вставок ****************************

//1.20 минут

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


*************************************************** сортировка выбором ***********************************************************

/* Сортировка выбором Selection Sort

Шаги алгоритма:

1.находим номер минимального значения в текущем списке

2.производим обмен этого значения со значением первой неотсортированной позиции (обмен не нужен, 
если минимальный элемент уже находится на данной позиции)

3.теперь сортируем хвост списка, исключив из рассмотрения уже отсортированные элементы

Для реализации устойчивости алгоритма необходимо в пункте 2 минимальный элемент непосредственно 
вставлять в первую неотсортированную позицию, не меняя порядок остальных элементов.*/

//*****************************Задания************************

/*1. Выполнить сортировку на убывание
2. Реализовать функцию, которая позволяет пользователю задать направление сортировки.
В функции задается 3 параметра: массив, его размер, направление сортировки (через enum )
3. Реализовать такую функцию по всем видам сортировки
*/
//********************* сортировка выбором ****************************

//2.04 минут
// по возрастанию

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MASSIZE 10

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
//*****************************************************************************
	for (int i = 0; i < MASSIZE - 1; i++)/*идем циклом по всему нашему массиву и ищем
										 минимальный индекс.*/										 
	{
		int minindex = i;               /*По умолчанию он у нас равен текущему i.
										 Когда i будет увеличиваться, у нас текущие будут
										 сдвигаться правее, для того чтобы левые элементы не
										 трогать.*/
		for (int f = i + 1; f < MASSIZE; f++)/*Делаем еще один цикл от следующего после i
											 элемента*/
		{
			if (myarray[f] < myarray[minindex])/*В котором сравниваем элементы с 
											   минимальным индексом*/
			{
				minindex = f;                  /*И если значение меньше минимального индекса,
											   заносим его в минимальный индекс*/
			}
		}

		if(minindex != i)
		{
			swap(myarray, i, minindex);
		}

		printArray(myarray, MASSIZE);
		printf("\n");
	}
	//***********************************************************************************

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

******************************************************************************

//по убыванию

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MASSIZE 10

void fillArray(int array[], int arraySize);

void swap(int array[], int index1, int index2);

void printArray(int array[], int arraySize);

void checkOnRepeat(int array[], int arraySize);


int main()
{
	int myarray[MASSIZE];
	fillArray(myarray, MASSIZE);
	printArray(myarray, MASSIZE);
	printf("\n");
	checkOnRepeat(myarray, MASSIZE);
	printArray(myarray, MASSIZE);
	printf("\n");
//*****************************************************************************
	for (int i = 0; i < MASSIZE - 1; i++)/*идем циклом по всему нашему массиву и ищем
										 максимальный индекс.*/										 
	{
		int maxindex = i;               /*По умолчанию он у нас равен текущему i.
										 Когда i будет увеличиваться, у нас текущие будут
										 сдвигаться правее, для того чтобы левые элементы не
										 трогать.*/
		for (int f = i + 1; f < MASSIZE; f++)/*Делаем еще один цикл от следующего после i
											 элемента*/
		{
			if (myarray[f] > myarray[maxindex])/*В котором сравниваем элементы с 
											   иаксимальным индексом*/
			{
				maxindex = f;                  /*И если значение больше максимального индекса,
											   заносим его в максимальный индекс*/
			}
		}

		if(maxindex != i)
		{
			swap(myarray, i, maxindex);
		}

		printArray(myarray, MASSIZE);
		printf("\n");
	}
	//***********************************************************************************

	printArray(myarray, MASSIZE);
	
	system("pause");
	return 0;
}

/*вывод на экран*/
void printArray(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%2i ", array[i]);
	}
	printf("\n");
}
/*обмен элементов*/
void swap(int array[], int index1, int index2)
{
	int buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}


/*проверка на повтор*/
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

/*заполнение массива*/
void fillArray(int array[], int arraySize)
{
	srand(time(0));
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % (arraySize + 5);
	}
}


************************************ функции ******************************

void SortingSort(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)//первый цикл проход слева направо как в пузырьке
	{
		if (array[i] > array[i + 1]) //если текущий элемент больше следующего, 
		{
			swap(array, i, i + 1);// мы делаем перестановку, протягиваем большее значение вправо,
								  //на каждой замене нам нужно делать проверку текущего значения i и идти влево до самого максимального
								  //значения
								  //после перестановки нам нужен еще один цикл
			int j = i;/*заведем управляющую переменную j для
					  нашего цикла проверки влево,
					  она будет равна текущей позиции
					  */
			int buffs = array[i];/*заведем буферную переменную для текущего значения
								 для последующих перестановок в левой части массива*/
			while (j > 0 && array[j - 1] > buffs)/*будем идти влево пока j больше 0
												 и пока предыдущий элемент больше значения buffs*/
			{
				array[j] = array[j - 1];/*записываем в текущий элемент значение предыдущего*/
				j--;
			}
			array[j] = buffs;/*здесь мы дошли до наименьшего значения,
							 которое больше значения буфера и меняем его
							 на значение буфера*/
		}		
	}
}

void SortingSortConversely(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)//первый цикл проход слева направо как в пузырьке
	{
		if (array[i] < array[i + 1]) //если текущий элемент больше следующего, 
		{
			swap(array, i, i + 1);// мы делаем перестановку, протягиваем большее значение вправо,
									//на каждой замене нам нужно делать проверку текущего значения i и идти влево 
									//до самого максимального значения
									//после перестановки нам нужен еще один цикл
			int j = i;/*заведем управляющую переменную j для
					  нашего цикла проверки влево,
					  она будет равна текущей позиции
					  */
			int buffs = array[i];/*заведем буферную переменную для текущего значения
								   для последующих перестановок в левой части массива*/
			while (j > 0 && array[j - 1] < buffs)/*будем идти влево пока j больше 0
												   и пока предыдущий элемент больше значения buffs*/
			{
				array[j] = array[j - 1];/*записываем в текущий элемент значение предыдущего*/
				j--;
			}
			array[j] = buffs;/*здесь мы дошли до наименьшего значения,
							   которое больше значения буфера и меняем его
							   на значение буфера*/
		}
	}
}

void SelectionSort(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)/*идем циклом по всему нашему массиву и ищем
										 минимальный индекс.*/
	{
		int minindex = i;               /*По умолчанию он у нас равен текущему i.
										Когда i будет увеличиваться, у нас текущие будут
										сдвигаться правее, для того чтобы левые элементы не
										трогать.*/
		for (int f = i + 1; f < arraySize; f++)/*Делаем еще один цикл от следующего после i
											 элемента*/
		{
			if (array[f] < array[minindex])/*В котором сравниваем элементы с
											   минимальным индексом*/
			{
				minindex = f;                  /*И если значение меньше минимального индекса,
											   заносим его в минимальный индекс*/
			}
		}

		if (minindex != i)
		{
			swap(array, i, minindex);
		}		
	}
}

void SelectionSortConversely(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)/*идем циклом по всему нашему массиву и ищем
										 максимальный индекс.*/
	{
		int maxindex = i;               /*По умолчанию он у нас равен текущему i.
										Когда i будет увеличиваться, у нас текущие будут
										сдвигаться правее, для того чтобы левые элементы не
										трогать.*/
		for (int f = i + 1; f < arraySize; f++)/*Делаем еще один цикл от следующего после i
											 элемента*/
		{
			if (array[f] > array[maxindex])/*В котором сравниваем элементы с
											   иаксимальным индексом*/
			{
				maxindex = f;                  /*И если значение больше максимального индекса,
											   заносим его в максимальный индекс*/
			}
		}
		if (maxindex != i)
		{
			swap(array, i, maxindex);
		}
	}
}

*****************************  реализация задания  **************************************

/*1. Выполнить сортировку на убывание
2. Реализовать функцию, которая позволяет пользователю задать направление сортировки.
В функции задается 3 параметра: массив, его размер, направление сортировки (через enum )
3. Реализовать такую функцию по всем видам сортировки
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MASSIZE 10

enum Sort
{
	InsertSorting = 1,
	InsertConverselySorting,
	SelectionSorting,
	SelectionConverselySorting
};

enum Sort userChoice;

void fillArray(int array[], int arraySize);
void swap(int array[], int index1, int index2);
void printArray(int array[], int arraySize);
void checkOnRepeat(int array[], int arraySize);

void SortingSort(int array[], int arraySize);
void SortingSortConversely(int array[], int arraySize);
void SelectionSort(int array[], int arraySize);
void SelectionSortConversely(int array[], int arraySize);

void UserChoice(int array[], int arraySize, enum Sort userChoise);

int main()
{
	int myarray[MASSIZE];
	fillArray(myarray, MASSIZE);	
	checkOnRepeat(myarray, MASSIZE);
	printf("There is an unsorted array of characters:\n");
	printArray(myarray, MASSIZE);
	printf("\n");
	UserChoice(myarray, MASSIZE, userChoice);
	system("pause");
	return 0;
 }

/*заполнение массива*/
void fillArray(int array[], int arraySize)
{
	srand(time(0));
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % (arraySize + 5);
	}
}

/*проверка на повтор*/
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

/*вывод на экран*/
void printArray(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%2i ", array[i]);
	}
	printf("\n");
}

/*обмен элементов*/
void swap(int array[], int index1, int index2)
{
	int buffer = array[index1];
	array[index1] = array[index2];
	array[index2] = buffer;
}

/*сортировка вставками по возрастанию*/
void SortingSort(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		if (array[i] > array[i + 1]) 
		{
			swap(array, i, i + 1);
			int j = i;
			int buffs = array[i];
			while (j > 0 && array[j - 1] > buffs)
			{
				array[j] = array[j - 1];
				j--;
			}
			array[j] = buffs;
		}
		printArray(array, arraySize);
		printf("\n");
	}	
}

/*сортировка вставками по убыванию*/
void SortingSortConversely(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		if (array[i] < array[i + 1]) 
		{
			swap(array, i, i + 1);
								  
			int j = i;
			int buffs = array[i];
			while (j > 0 && array[j - 1] < buffs)
			{
				array[j] = array[j - 1];
				j--;
			}
			array[j] = buffs;
		}
		printArray(array, arraySize);
		printf("\n");
	}	
}

/*сортировка выбором по возрастанию*/
void SelectionSort(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		int minindex = i;               
		for (int f = i + 1; f < arraySize; f++)
		{
			if (array[f] < array[minindex])
			{
				minindex = f;                  
			}
		}
		if (minindex != i)
		{
			swap(array, i, minindex);
		}
		printArray(array, arraySize);
		printf("\n");
	}	
}

/*сортировка выбором по убыванию*/
void SelectionSortConversely(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		int maxindex = i;               
		for (int f = i + 1; f < arraySize; f++)
		{
			if (array[f] > array[maxindex])
			{
				maxindex = f;                  
			}
		}
		if (maxindex != i)
		{
			swap(array, i, maxindex);
		}
		printArray(array, arraySize);
		printf("\n");
	}	
}

/*функция выбора способа сортировки*/
void UserChoice(int array[], int arraySize, enum Sort userChoise)
{
	printf("Please enter the sorting method: \n");
	printf("1 - the insertion sort in ascending order\n");
	printf("2 - the insertion sort for descending order\n");
	printf("3 - sort by ascending order\n");
	printf("4 - sorting option for descending order\n");

	scanf("%i", &userChoice);
	switch (userChoice)
	{
	case InsertSorting:
		SortingSort(array, arraySize);
		break;
	case InsertConverselySorting:
		SortingSortConversely(array, arraySize);
		break;
	case SelectionSorting:
		SelectionSort(array, arraySize);
		break;
	case SelectionConverselySorting:
		SelectionSortConversely(array, arraySize);
		break;
	default:
		printf("this item is not available\n");
		break;
	}	
}

