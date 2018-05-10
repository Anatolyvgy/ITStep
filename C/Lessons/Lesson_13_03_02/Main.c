/*�������� return ��������� ������� � ���������� ���������� ���������� 
��������� ������ ���������� �������. ��� ���������� ���� � ������, 
���� �������� return � ������� �� �������� ���������.
����� ����� ��������� �������� ������ ����:
	return;
�� �������� � ���������� ������� � ���������� ���������� ����������
�������. ��-�� ����, ��� ��������� �� return �����������, �������� 
�� ������������, � ��� ����� ������ �������������� ������ � 
�������� ���� void*/

#include<stdio.h>
#include<locale.h>


long recurs(int a);
long fact(int n);

int main()
{
	
	setlocale(LC_ALL, "rus");
	//recurs(1);
	int num = 5;
	//int static result = 5;
	printf("��������� %i = %ld", num, recurs(num));

	return 0;
}

long recurs(int a)
{
	if (a <= 1)
	{
		return 1;
	}
	
	
	return a * recurs(a - 1);
	
}

/*recurs(5)
	return 5 x recurs(5 - 1)(return 24)
				return 4 x recurs(4 - 1)(return 6)
							return 3 x recurs(3 - 1)(return 2)
										return 2 x recurs(2 - 1)(return 1)
													                    */

long fact(int n)
{
	int ans;
	if (n > 0)
	{
		ans = n * fact(n - 1);
	}
	else
		ans = 1;
	return ans;
}

/*  fact(3);
		int ans;
		if(3 > 0)
		ans = 3 x fact(3 - 1)
					int ans;
					if(2 > 0)
					ans = 2 x */