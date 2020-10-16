#include <iostream>

using namespace std;


struct Node
{
	int info;
	Node* next;
	Node* prev;
};


Node* add_back(Node* top,  int value){
    top->prev = new Node;
    top->prev->prev = 0;
    top->prev->next = top;
    top->prev->info = value;
    top = top->prev;
    Node *p = top;
    while (p){
        cout << p->info << " ";
        p = p->next;
        
    }
    cout << endl;
    return top;
}



Node* add_front(Node* top, Node* back, int value){
    back->next = new Node;
	back->next->prev = back;
	back->next->next = 0;
	back->next->info = value;
	back = back->next;
    Node *p = top;
    while (p){
        cout << p->info << " ";
        p = p->next;
        
    }
    cout << endl;
    return back;
}

Node* pop_back(Node* top, Node* back){
    Node *p = top;
    int rtn;
    if (top->next != 0){
        top->next->prev = 0;
        top = top->next;
        rtn = p->info;
        cout << "Вы удалили следующий элемент очереди: " << rtn << endl;
        delete p;
        cout << "Текущая очередь:" << endl;
        p = top;
        while (p){
            cout << p->info << " ";
            p = p->next;
        } 
        cout << endl;
    }
    else{
        rtn = top->info;
        delete top;
        cout << "Вы удалили последний элемент очереди" << endl;
        return top;
    }
    
    return top;
}


Node* pop_front(Node* top, Node* back){
    Node *p = back;
    int rtn;
    if (back->prev != 0){
        back->prev->next = 0;
        back = back->prev;
        rtn = p->info;
        delete p;
        cout << "Вы удалили следующий элемент очереди: " << rtn << endl;
        cout << "Текущая очередь:" << endl;
        p = top;
        while (p){
            cout << p->info << " ";
            p = p->next;
        } 
        cout << endl;
    }
    else{
        rtn = back->info;
        delete back;
        cout << "Вы удалили последний элемент очереди: " << endl;
        return back;
    }
    return back;
}


int main()
{
    setlocale(LC_ALL,"Russian");
    Node* Top, * Back, *p;
    int x = 10, value = 0, i, n = 0;
    cout << "Введите изначальный размер очереди: " << endl;
    cin >> n;
    if (n != 0){
	    Top = Back = new Node;
	    Top->next = 0;
	    Top->prev = 0;
	    Top->info = 0;
        for (i = 1; i < n; i++)
	    {
		    Back->next = new Node;
		    Back->next->prev = Back;
		    Back->next->next = 0;
		    Back->next->info = i;
		    Back = Back->next;
	    }
        cout << "Текущая очередь: " << endl;
        p = Top;
        while (p){
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
	cout << "Выберете действие, которое хотите сделать с очередью: " << endl << "   1. Добавить элемент в начало очереди;" << endl << "   2. Добавить элемент в конец очереди;" << endl << "   3. Удалить элемент с начала очереди;" << endl << "   4. Удалить элемент с конца очереди;" << endl << "   0. Выйти." << endl;
    while (x != 0){
        cin >> x;
        switch(x){
            case 1:{
                cout << "Введите значение, которое хотите добавить: " << endl;
                cin >> value;
                Top = add_back(Top, value);
                n++;
                break;
            }
            case 2:{
                cout << "Введите значение, которое хотите добавить: " << endl;
                cin >> value;
                Back = add_front(Top, Back, value);
                n++;
                break;
            }
            case 3:{
                if (n){
                    Top = pop_back(Top, Back);
                    n--;
                }
                else{
                    cout << "Эта операция вам недоступна, так как очередь пуста" << endl;
                }
                break;
            }
            case 4:{
               if (n){
                    Back = pop_front(Top, Back);
                    n--;
                }
                else{
                    cout << "Эта операция вам недоступна, так как очередь пуста" << endl;
                }
                break;
            }
            case 0:{
                
                while (p){
                    p = Top;
                    p->next->prev = 0;
                    Top = p->next;
                    delete p;
                }
                break;
            }
            default:{
                cout << "Вы ввели неизвестное значение!" << endl;
                break;
            } 
        }
        
    }
}
