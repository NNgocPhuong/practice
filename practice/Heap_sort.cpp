#include<iostream>


void heapify(int a[], int n, int i)
{
	int left = i * 2;
	int right = left + 1;
	int max = i;
	if (a[max] < a[left] && left < n) max = left;
	if (a[max] < a[right] && right < n) max = right;

	if (max != i)
	{
		std::swap(a[i], a[max]);
		heapify(a, n, max);
	}
}
void heap_sort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}


int main()
{
	int a[] = { 9,8,2,12,5,4,7,16,1,3,15 };
	int n = sizeof(a) / sizeof(a[0]);
	heap_sort(a, n);
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << ' ';
	}
	return 0;
}
