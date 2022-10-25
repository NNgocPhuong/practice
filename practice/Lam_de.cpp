#include<iostream>

//int find_number(int a[], int n, int value) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[i] + a[j] == value)
//			{
//				std::cout << a[i] << ' ' << a[j];
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int arr[] = { 71,58,74,84,70,21 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	if (find_number(arr, n, 95))
//		std::cout << "\nFound!";
//	else
//		std::cout << "\nNot Found!";
//	return 0;
//}

struct data{
	int bac;
	int k;
	data(int a, int b):bac(a),k(b){}
};

class Node
{
public:
	data value;
	Node* next;
	Node(int a, int b) : value(a, b)
	{
		next = NULL;
	}
};
