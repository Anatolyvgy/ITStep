#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MASSIZE 20

void fillArray(int array[], int arraySize);//���������� �������

void swap(int array[], int index1, int index2);//����� ���������

void printArray(int array[], int arraySize);//����� �� �����

void checkOnRepeat(int array[], int arraySize);//�������� �� ������


int main()
{	
	int myarray[MASSIZE];
	fillArray(myarray, MASSIZE);
	printArray(myarray, MASSIZE);
	printf("\n");
	checkOnRepeat(myarray, MASSIZE);
	printArray(myarray, MASSIZE);
	printf("\n");
	
	for (int i = 0; i < MASSIZE - 1; i++)//������ ���� ������ ����� ������� ��� � ��������
	{
		if (myarray[i] > myarray[i + 1]) //���� ������� ������� ������ ����������, 
		{
			swap(myarray, i, i+1);// �� ������ ������������, ����������� ������� �������� ������,
			//�� ������ ������ ��� ����� ������ �������� �������� �������� i � ���� ����� �� ������ �������������
			//��������
			//����� ������������ ��� ����� ��� ���� ����
			int j = i;/*������� ����������� ���������� j ��� 
					  ������ ����� �������� �����,
					  ��� ����� ����� ������� �������
					  */
			int buffs = myarray[i];/*������� �������� ���������� ��� �������� �������� 
								   ��� ����������� ������������ � ����� ����� �������*/
			while (j > 0 && myarray[j-1] > buffs)/*����� ���� ����� ���� j ������ 0
											   � ���� ���������� ������� ������ �������� buffs*/
			{
				myarray[j] = myarray[j - 1];/*���������� � ������� ������� �������� �����������*/
				j--;
			}
			myarray[j] = buffs;/*����� �� ����� �� ����������� ��������, 
							   ������� ������ �������� ������ � ������ ��� 
							   �� �������� ������*/
		}
		printArray(myarray, MASSIZE);/*��� ����������� */
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
