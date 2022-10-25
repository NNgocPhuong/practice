#include<iostream>
void chuyen_thanh_ma_tran_mot_chieu(int*& a, int b[][3], int m, int n) // m : so hang
																	// n : so cot
{
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[k] = b[i][j];
			k++;
		}
	}
}
void selection_sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min_pos = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[min_pos])
				min_pos = j;
		}
		std::swap(a[i], a[min_pos]);
	}
}
void chuyen_thanh_ma_tran_hai_chieu(int a[][3], int b[], int m, int n)
{
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[k];
			k++;
		}
	}
}

int main()
{
	int a[4][3] = { {1,3,2},{0,4,1},{5,3,2},{4,7,1} };
	int* b;
	int t = 4 * 3;
	b = new int[t];
	chuyen_thanh_ma_tran_mot_chieu(b, a, 4, 3);
	for (int i = 0; i < t; i++)
	{
		std::cout << b[i] << ' ';
	}
	std::cout << std::endl;
	selection_sort(b, t);
	for (int i = 0; i < t; i++)
	{
		std::cout << b[i] << ' ';
	}
	std::cout << std::endl;
	chuyen_thanh_ma_tran_hai_chieu(a, b, 4, 3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << a[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
