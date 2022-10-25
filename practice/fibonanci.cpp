#include<iostream>

int fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	std::cout << "Nhap n: ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cout << fibo(i) << "  ";
	}
}
