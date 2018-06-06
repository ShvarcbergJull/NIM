#include <iostream>
#include <locale.h>
#include "Player.h"
#include "math.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	cout << "Игра НИМ" << endl;
	cout << "Правила: Имеется три кучки предметов по n, (n+1) и (n+2) штук." << endl;
	cout << "Игроки поочередно берут предметы, и тот, кто возьмет последний предмет, выигрывает. " << endl;
	cout << "За один ход разрешается взять любое ненулевое число предметов из одной кучки." << endl;
	int l;
	cout << "Выберите уровень сложности(1 - лёгкий, 2 - средний, 3 - сложный): ";
	cin >> l;

	int n = matrix(l); // выдаёт количество фишек в первой строчке

	int** arr = new int*[3];
	for (int i = 0, k = n; i < 3; i++, k++)
		arr[i] = new int[k];

	int k = n;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < k; i++)
			arr[j][i] = 1;
		k++;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
		n++;
	}

	int coef = 0;
	while (coef == 0)
		coef = inOut(arr);
	if (coef == 1)
		cout << "Вы проиграли!" << endl;
	else
		cout << "Вы выиграли!" << endl;

	for (int i = 0; i < 3; i++)
		delete[] arr[i];
	delete[] arr;

	system("pause");
	return 0;
}
