#include<iostream>


int binary_Search(int a[], int n, int x)
{
	int left = 0; 
	int right = n - 1;
	while (left <= right)
	{
		int midle = (left + right) / 2;
		if (a[midle] == x)
		{
			return midle;
		}
		else if (a[midle] < x)
		{
			left = midle + 1;
			
		}
		else if (a[midle] > x)
		{
			right = midle - 1;
		}
	}
	return -1;
}

void selection_sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min_pos] > a[j])
			{
				min_pos = j;
			}
		}
		std::swap(a[min_pos], a[i]);
	}
}
int partition(int a[], int low, int high)
{
	int left = low + 1;
	int right = high;
	int pivot = low;
	while (true)
	{
		while (left <= right && a[pivot] > a[left])
		{
			left++;
		}
		while (left <= right && a[pivot] < a[right])
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
	std::swap(a[pivot], a[right]);
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
void Buble_sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] < a[j - 1])
			{
				std::swap(a[j], a[j - 1]);
			}
		}
	}
}
void insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int k = i-1;
		while (k >= 0 && a[k] > key)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
void heapify(int a[], int n, int i)
{
	int left = i * 2;
	int right = left + 1;
	int max = i;
	if (left < n && a[max] < a[left])
		max = left;
	if (right < n && a[max] < a[right])
		max = right;
	if (max != i)
	{
		std::swap(a[max], a[i]);
		heapify(a, n, max);
	}
}
void heap_sort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = n-1; i >= 0; i--)
	{
		std::swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}
// C++ program for Merge Sort
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

int main()
{
	int a[] = { 1,4,2,7,9,5,0 };
	int n = sizeof(a) / sizeof(a[0]);
	/*if (binary_Search(a, n, -2) >= 0)
	{
		std::cout << "So co trong mang" << std::endl;
	}
	else
	{
		std::cout << "Khong co trong mang" << std::endl;
	}*/
	//selection_sort(a, n);
	//Quick_sort(a, 0, n - 1);
	//Buble_sort(a, n);
	//insertion_sort(a, n);
	heap_sort(a, n);
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << '\t';
	}
}
