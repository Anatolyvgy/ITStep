// Циклы
// cmd/? - посмотреть в командной строке интересная штука

//system("calc");
//system("notepad");// так можно запускать программы
//system("notepad c:\\totalcmd\\SIZE!.TXT"); // так открыть файл
*******************************   графики   ************************************
#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	setlocale(LC_ALL, "C")// для перехода на английский
	//int a = 0;
	//while (a < 256)
	//{
	//	printf("%d соответствует %c\n", a, a);//2
	//	a++;
	//}
		
	/*for (int i = 0; i < 2; i++) 
	{
		printf("%i - %c\n", i, i);
	}*/
	//char ch = "1 студент";

	int height_of_graph;        //высота графика
	int number_of_jobs;         //процент выполненных заданий
	int const total_jobs = 25;  //всего заданий
	int const total_graph = 20; //максимальная высота графика 
	int student1;
	int student2;
	int student3;
	int student4;
	
	int a = 2; 
	char ch = ' ';
	printf("Сколько заданий выполнил 1 студент:");
	scanf("%d", &student1);
	printf("Сколько заданий выполнил 2 студент:");
	scanf("%d", &student2);
	printf("Сколько заданий выполнил 3 студент:");
	scanf("%d", &student3);
	printf("Сколько заданий выполнил 4 студент:");
	scanf("%d", &student4);


	if (student1 <= 25)
	{
		number_of_jobs = (student1 * 100) / total_jobs;
		height_of_graph = number_of_jobs / 5;
		printf("%5c 1 студент:   ", ch);
		for (int i = 0; i < height_of_graph; i++)
		{
			printf("%c", a);
		}
		printf("\n");
	}
	else
		printf("У нас всего 25 заданий\n");


	if (student2 <= 25)
	{
	number_of_jobs = (student2 * 100) / total_jobs;
	height_of_graph = number_of_jobs / 5;
	printf("%5c 2 студент:   ", ch);
		for (int i = 0; i < height_of_graph; i++)
		{
			printf("%c", a);
		}	
		printf("\n");
	}
	else
		printf("У нас всего 25 заданий\n");


	if (student3 <= 25)
	{
		number_of_jobs = (student3 * 100) / total_jobs;
		height_of_graph = number_of_jobs / 5;
		printf("%5c 3 студент:   ", ch);
		for (int i = 0; i < height_of_graph; i++)
		{
			printf("%c", a);
		}
		printf("\n");
	}
	else
		printf("У нас всего 25 заданий\n");


	if (student4 <= 25)
	{
	number_of_jobs = (student4 * 100) / total_jobs;
	height_of_graph = number_of_jobs / 5;
	printf("%5c 4 студент:   ", ch);
	for (int i = 0; i < height_of_graph; i++)
	{
		printf("%c", a);
	}	
	printf("\n");
	}
	else
		printf("У нас всего 25 заданий\n");
	return 0;
}//12минут

*******************Функция Sleep() спать**********************
/* Иногда нужно сделать задержку экрана консоли. Есть специальный модуль, он С++, но здесь он 
работает. Подключаем #include<Windows.h> он специфичен только для Windows. в Sleep можно 
передать количество миллисекунд, которые нужно спать(милли - это 10 в 3) т.е. 1000 миллисекунд
соответствует 1 секунде. Это удобно в циклах, можно показать что то пользователю или самим 
посмотреть */

#include<Windows.h>
#include<stdio.h>
#include<locale.h>
int main()
{	
	setlocale(LC_ALL, "C");// английская локализация
	for(int i = 0; i < 256; i++)
	{
		printf("%c - %i\t", i, i );
		Sleep(5000);// здесь каждая итерация цикла будет задерживаться на 5 секунд 
	}
	
	return 0;
	
}

************************* функция system("cls") *********************************
/*      Функция очистки экрана, требует подключения Windows.h     */

#include<Windows.h>
#include<stdio.h>
#include<locale.h>
int main()
{	
	setlocale(LC_ALL, "C");// английская локализация
	for(int i = 0; i < 256; i++)
	{
		printf("%c - %i\t", i, i );
		Sleep(5000);// здесь каждая итерация цикла будет задерживаться на 5 секунд 
		system("cls");// функция очистки экрана
		//таким образом можно делать какие то анимации, спецэффекты
	}
	
	return 0;
	
}

**********Игра больше меньше********************




#include<Windows.h>/*для Sleep и system("cls")*/
#include<time.h>/* для псевдослучайных чисел и функции time(), если мы пишем в скобках 0, то она
возвращает нам текущее время*/
#include<stdio.h>
#include<locale.h>
#include<stdbool.h>// для _Bool

int main()
{

	setlocale(LC_ALL, "rus");
	srand(time(0));
	int rnd = rand() % 10;
	int user_Number = 0;
	_Bool flag = false;
	printf("Компьютер загадал число от 0 до 9 \n");
	printf("У Вас есть 3 попытки, чтобы его отгадать \n\n");
	
	for (int i = 0; i < 3; i++)
	{
		printf("Введите число:");
		scanf("%i", &user_Number);
		if (user_Number <= 9)
		{
			if (rnd == user_Number)
			{
				printf("Угадали!!! Это действительно %i\n", rnd);
				flag = true;
				break;
			}

			if (rnd < user_Number)
			{
				printf("Число меньше\n");
				continue;
			}
			if (rnd > user_Number)
				printf("Число больше\n");
		}
		else
			printf("Число должно быть в указаннном диапазоне\n");
		
		//Sleep(2000);// задержка цикла на 1 секунду
		//system("cls");// функция очистки экрана
	}

	if (flag == true)
		printf("Поздравляем, У Вас талант угадывать числа\n");
	else
		printf("К сожалению Вы не угадали, попробуйте еще раз\n");

	return 0;
	

}// 2.00.00



