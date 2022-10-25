#include<iostream>

class Node
{
public:
	int data;
	Node* next;
	Node(int _data = 0) 
	{
		data = _data;
		next = NULL;
	}
};

class Queue
{
private:
	Node* front;
	Node* rear;
	int count;
protected:
	void removeAll() {
		while (front != NULL)
		{
			Node* k = front;
			front = front->next;
			delete k;
		}
	}
public:
	Queue()
	{
		count = 0;
		front = rear = NULL;
	}
	~Queue() { removeAll(); }
	bool Is_empty()
	{
		return front == NULL;
	}
	void en_Queue(int value)
	{
		if (Is_empty())
		{
			front = rear = new Node(value);
		}
		else
		{
			Node* p = new Node(value);
			rear->next = p;
			rear = p;
		}
		count++;
	}
	int de_Queue()
	{
		if (!Is_empty())
		{
			int x = front->data;
			Node* p = front;
			front = front->next;
			delete p;
			return x;
		}
		count--;
	}
	int get_Count() { return count; }
	void display()
	{
		if (Is_empty())
		{
			return;
		}
		else
		{
			Node* k = front;
			while (k != NULL)
			{
				std::cout << k->data << '\t';
				k = k->next;
			}
		}
	}
};

int main()
{
	Queue A;
	Queue B;
	int a[] = {-1,-8,-4,6,3,1,2,-8,-7,1,-5,-7,-5,-1,3};
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			A.en_Queue(a[i]);
		}
		else if(a[i] > 0)
		{
			B.en_Queue(a[i]);
		}
	}
	int max_size;
	if (A.get_Count() > B.get_Count())
		max_size = A.get_Count();
	else
		max_size = B.get_Count();

	for (int i = 0; i < max_size; i++)
	{
		if (!A.Is_empty())
		{
			std::cout << A.de_Queue() << ' ';
		}
		if (!B.Is_empty())
		{
			std::cout << B.de_Queue() << ' ';
		}
	}
	return 0;
}
