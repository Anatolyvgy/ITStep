//Продолжаем игру Угадай число. Только теперь отгадывает комп.

/*1. Вводим с клавиатуры 2 числа. Компьютер должен рандомно выдавать числа в диапазоне
между ними  */




//#include<Windows.h>/*для Sleep и system("cls")*/
#include<time.h>/* для псевдослучайных чисел и функции time(), если мы пишем в скобках 0, то она
возвращает нам текущее время*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>// для srand()
//#include<stdbool.h>

enum Result
{
	Bolshe = 1,
	Menshe,		
};

int main()
{
	setlocale(LC_ALL, "rus");
	//srand(time(0));
	srand((unsigned int)(time(NULL)));//чтобы не ругалась на преобразование типа
	int n1 = 0;
	int n2 = 0;
	int secret = 0;
	int count = 0;

	printf("Введите начало диапазона: ");
	scanf("%i", &n1);

	printf("Введите конец диапазона: ");
	scanf("%i", &n2);

	printf("Введите секретное число: ");
	scanf("%i", &secret);

	for (int try = 0; try < (secret + 1); try++)
	{
		int quess = (n1 + 1) + rand() % (n2 - n1 - 1);

		count++;
		if (quess == secret)
		{
			printf("Я угадал!!!, Ваше число: %i\n", secret);
			break;
		}

		printf("Это Ваше число?: %i\n", quess);		
		printf("Больше - 1\nМеньше - 2\n");

		enum Result result;
		scanf("%i", &result);

		switch (result)
		{		
		case Bolshe:
			n1 = quess;
			break;
		case Menshe:
			n2 = quess;
			break;
		}
	}

	printf("Мне потребовалось %i попыток\n", count);
	return 0;	
}