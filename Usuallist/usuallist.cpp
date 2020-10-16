#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};
int main()
{
    Node* p, *Top;
    int x;
    Top = new Node;
    Top = NULL;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        p = new Node;
        p->info = x;
        p->next = Top;
        Top = p;
    }
    while(Top)
    {
        p=Top;
        cout << p->info << " ";
        Top = p->next;
        delete p;

    }
    return 0;
}
