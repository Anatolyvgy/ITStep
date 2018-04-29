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
