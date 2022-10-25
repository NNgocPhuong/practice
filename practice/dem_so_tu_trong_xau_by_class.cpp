#include<iostream>

class XKT
{
private:
	char* s;
	int length;
public:
	XKT(int n = 0)
	{
		length = n;
		s = new char[length];
	}
	XKT(int n, char* p)
	{
		length = n;
		s = new char[length];
		for (int i = 0; i < length; i++)
		{
			s[i] = p[i];
		}
	}
	~XKT()
	{
		if (s != NULL)
			delete[] s;
	}
	XKT& operator=(XKT& p)
	{
		delete[] s;
		length = p.length;
		s = new char[length];
		for (int i = 0; i < length; i++)
		{
			s[i] = p.s[i];
		}
		return *this;
	}
	XKT(const XKT& a)
	{
		length = a.length;
		s = new char[length];
		for (int i = 0; i < length; i++)
		{
			s[i] = a.s[i];
		}
	}
public:
	void Nhap()
	{
		std::cout << "Nhap xau ky tu: ";
		std::cin.getline(s, length);
	}
	void COUNT()
	{
		//xoa ky tu dau
		while (s[0] == ' ')
		{
			for (int i = 0; i < length; i++)
			{
				s[i] = s[i + 1];
			}
			length = length - 1;
		}
		//xoa ky tu cuoi
		while (s[length - 1] == ' ')
		{
			s[length - 1] = s[length];
			length = length - 1;
		}
		// dem so tu trong xau
		int cnt = 0;
		for (int i = 0; i < length; i++)
		{
			if (s[i] != ' ' && s[i + 1] == ' ')
			{
				cnt++;
			}
		}
		std::cout << "So tu trong XKT la: " << cnt + 1 << std::endl;
	}

};


int main()
{
	XKT S(100);
	S.Nhap();
	S.COUNT();
	return 0;
}
