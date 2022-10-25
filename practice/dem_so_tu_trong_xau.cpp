#include<iostream>

int COUNT(char* s, int& n)
{
	//xoa ky tu dau
	while (s[0] == ' ')
	{
		for (int i = 0; i < n; i++)
		{
			s[i] = s[i + 1];
		}
		n = n - 1;
	}
	//xoa ky tu cuoi
	while (s[n-1] == ' ')
	{
		s[n - 1] = s[n];
		n = n - 1;
	}
	// dem so tu trong xau
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != ' ' && s[i+1] == ' ')
		{
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	char *s;
	s = new char[100];
	std::cin.getline(s, 100);
	int n = strlen(s);
	int k = COUNT(s, n);
	std::cout << k + 1;
	return 0;
}
