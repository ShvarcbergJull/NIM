#include <iostream>
#include "math.h"


using namespace std;

int lenght(int** arr, int m)
{
	int count = 0;
	bool p = true;
	while (p)
		if (arr[m][count] == 1)
			count++;
		else
			return count;
	return 0;
}

int podbor(int** arr, int m, int j)
{
	int sum;
	int len = lenght(arr, m) - j;
	switch (m)
	{
	case 0:
		sum = len ^ lenght(arr, 1) ^ lenght(arr, 2);
		break;
	case 1:
		sum = len ^ lenght(arr, 0) ^ lenght(arr, 2);
		break;
	case 2:
		sum = len ^ lenght(arr, 1) ^ lenght(arr, 0);
		break;
	}
	return sum;
}

void comp_step(int** arr)
{
	int nim_sum = lenght(arr, 0) ^ lenght(arr, 1) ^ lenght(arr, 2);
	if (nim_sum == 0)
	{
		if (lenght(arr, 0) != 0)
			arr[0][lenght(arr, 0) - 1] = 0;
		else
			if (lenght(arr, 1) != 0)
				arr[1][lenght(arr, 1) - 1] = 0;
			else
				arr[2][lenght(arr, 2) - 1] = 0;
	}
	else
	{
		for (int i = 0; i < 3; i++) {
			int j = 1;
			int len = lenght(arr, i);
			while (nim_sum != 0 && j <= len)
			{
				nim_sum = podbor(arr, i, j);
				j++;
			}
			if (nim_sum == 0) {
				j--;
				int n = len - j;
				for (int k = n; k < len; k++)
					arr[i][k] = 0;
				break;
			}
		}
	}
}
