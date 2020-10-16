#include <iostream>

using namespace std;


struct Node
{
	int info;
	Node* next;
	Node* prev;
};

int main()
{
	int x;
	Node* Top, * Back, *p;
	Top = Back = new Node;
	Top->next = 0;
	Top->prev = 0;
	cin >> x;
	Top->info = x;
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		Back->next = new Node;
		Back->next->prev = Back;
		Back->next->next = 0;
		Back->next->info = x;
		Back = Back->next;
	}
	p = Back;
	while(p)
	{
		cout << p->info << " ";
		p = p->prev;
	}

}
