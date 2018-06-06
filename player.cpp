#include <iostream>
#include "Player.h"
#include "math.h"

using namespace std;

int matrix(int level)
{
	int n = 0;
	switch (level)
	{
	case 1:
	{
		n = 3;
		break;
	}
	case 2:
	{
		n = 4;
		break;
	}
	case 3:
	{
		n = 5;
		break;
	}
	default:
		cout << "Надо ввести уровень сложности(1, 2 или 3):" << ' ';
		cin >> level;
		matrix(level);
		return 0;
	}
	
	return n;
}



void out(int** arr)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < lenght(arr, i); j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}



int inOut(int** arr)
{
	int m, n;// m - строка, n - количество фишек
	cout << "Введите номер строки и количество фишек, которые хотите убрать:" << ' ';
	cin >> m >> n;
	int len = lenght(arr, m - 1);
	if (m > 3 || n > len) {
		cout << "Вводимые параметры заходят за границы поля игры" << endl;
		return 0;
	}
	m--;
	int g = len - n;
	for (int i = g; i < len;i++) {
		arr[m][g] = 0; 
		g++;
	}
	if (lenght(arr, 0) == 0 && lenght(arr, 1) == 0 && lenght(arr, 2) == 0)
		return -1;
	out(arr);
	cout << endl << "Ход компьютера" << endl;
	comp_step(arr);
	if (lenght(arr, 0) == 0 && lenght(arr, 1) == 0 && lenght(arr, 2) == 0)
		return 1;
	out(arr);
	return 0;
}
