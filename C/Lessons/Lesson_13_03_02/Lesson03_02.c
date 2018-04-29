// Функции. Аргументы по умолчанию. Рекурсия

//default argument (аргументы по умолчанию)

#include<stdio.h>
#include<stdlib.h>
enum FuelType
{
	FuelType_92,
	FuelType_95,
	FuelType_98,
	FuelTypeDiesel
};

void printCarDetails(float weight, float engineVolume, enum FuelType fuelType = FuelType_92);

int main( )
{
	float weight;
	float engineVolume;
	enum FuelType fuelType;

	//printCarDetails(2.0, 1.6, FuelType_92);
	printCarDetails(2.0, 1.6);
	printCarDetails(3.0, 2.0, FuelType_98);
	printCarDetails(1.5, 1.4, FuelType_95);
	printCarDetails(1.7, 2.0, FuelTypeDiesel);

	system("pause");
	return 0;
}


void printCarDetails(float weight, float engineVolume, enum FuelType fuelType)
{
	printf("weight: %f, engineVolume: %f, fuelType: %i\n", weight, engineVolume, fuelType);
};



//recursion (рекурсия)

#include<stdio.h>
#include<stdlib.h>

//void printStars(int starCount);
//
//int main()
//{
//	int const starCount = 10;
//	printStars(starCount);
//	
//	system("pause");
//	return 0;
//}
//
//void printStars(int starCount)
//{
//	if (starCount > 0)
//	{	
//		printf("*");
//		printStars(starCount - 1);
//	}
//}
//******************************************************

//factorial

int recursion(int count, int result);

int main( )
{
	int result = 1;
	int count = 1;
	recursion(result, count);
	system("pause");
	return 0;
}

int recursion(int result, int count)
{
	if (count < 10)
	{
		result = result * count;
		printf("%ld\n", result);
		recursion(result, count + 1);
	}
}

//********************************************************
//Sergey

long long factor(int n);

int main( )
{
	int const n = 3;
	printf("factor (%i) = %dl", n, factor(n));
	system("pause");
	return 0;
}
long long factor(int n)
{
	if (n <= 1)
	//if (n < 2)
	{
		return 1;
	}
	return n*factor(n - 1);
}






