#include<iostream>

int partition(int a[], int low, int high)
{
	int left = low + 1;
	int right = high;
	int key = a[low];

	while (true)
	{
		while (left <= right && key > a[left])
		{
			left++;
		}
		while (left <= right && key < a[right])
		{
			right--;
		}
		if (left <= right)
		{
			std::swap(a[left], a[right]);
			left++;
			right--;
		}
		else
		{
			break;
		}
	}
	std::swap(a[low], a[right]);
	return right;
}
void Quick_sort(int a[], int left, int right)
{
	if (left < right)
	{
		int pi = partition(a, left, right);
		Quick_sort(a, left, pi - 1);
		Quick_sort(a, pi + 1, right);
	}
}


int main()
{
	int a[] = { 4,1,6,6,3,12,3,0,7,8 };
	int n = sizeof(a) / sizeof(a[0]);
	Quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << ' ';
	}

	return 0;
}
