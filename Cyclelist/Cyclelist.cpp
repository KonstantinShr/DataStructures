#include <iostream>

using namespace std;

struct Node{
    int info;
    Node* link;
};

int main() {
    Node *p, *back;
    int x, count, output;
    cout << "Enter count of elements" << endl;
    cin >> count;
    cout << "Enter elements" << endl;
    cin >> x;
    try {
        back = new Node;
    }
    catch (std::bad_alloc &e){
        return 1;
    }
    back->info = x;
    back->link = back;
    for (int i = 0; i < count-1; i++){
        cin >> x;
        try {
            p = new Node;
        }
        catch (std::bad_alloc &e){
            return 1;
        }
        p->info = x;
        p->link = back->link;
        back->link = p;
        back = p;
    }
    cout << "How much elements would you like to print?" << endl;
    cin >> output;
    p = back->link;
    for (int i = 0; i < output; i++){
        cout << p->info << " ";
        p = p->link;
    }
    for (int i = 0; i < count; i++){
        p = back->link;
        back->link = p->link;
        delete p;
    }
    return 0;
}