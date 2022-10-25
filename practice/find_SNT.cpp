#include<iostream>
#include<math.h>
bool Ktra_SNT(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return false;
	}
	return x > 1;
}

int main()
{
	int a;
	std::cout << "Nhap a:";
	std::cin >> a;
	if (Ktra_SNT(a))
		std::cout << a << " la so nguyen to!" << std::endl;
	else
		std::cout << a << " khong phai la so nguyen to!" << std::endl;

	return 0;
}
