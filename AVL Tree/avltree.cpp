#include <iostream>

using namespace std;

struct node
{
	int info;
    int height;
	node* right;
	node* left;
};


int height(node* &p)
{
    return p?p->height:0;
}



int difference(node* &p)
{
    return height(p->left)-height(p->right);
}



void change_height(node* &p)
{
    int hl = height(p->left);
    int hr = height(p->right);
    p->height =  (hl>hr?hl:hr)+1;
}



node* left_turn(node* &p)
{
    node* q = p->right;
    p->right = q->left;
    q->left = p;
    change_height(p);
    change_height(q);
    return q;
}


node* right_turn(node* &p)
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    change_height(p);
    change_height(q);
    return q;
}


node* balance(node* &p)
{
    change_height(p);
    if (difference(p) == 2){
        if (difference(p->right) < 0){
            p->right = right_turn(p->right);
        }
        return left_turn(p);
    }
    if (difference(p) == -2){
        if (difference(p->left) > 0){
            p->left = left_turn(p->left);
        }
        return right_turn(p);
    }
    return p;
}


node* add(int w, node* &p)
{
	if (p)
	{
		if (w > p->info)
		{
			add(w, p->right);
		}
		else
			if (w < p->info)
				add(w, p->left);
			else
				return nullptr;
	}
	else
	{
		p = new node;
		p->info = w;
		p->left = p->right = 0;
        return balance(p);
	}
}




node* find_min(node* &p) 
{
	return p->left?find_min(p->left):p;
}


node* remove_min(node* &p)
{
	if(p->left==0)
		return p->right;
	p->left = remove_min(p->left);
	return balance(p);
}



node* remove(node* &p, int w)
{
	if(!p) return 0;
	if(w < p->info)
		p->left = remove(p->left,w);
	else 
        if(w > p->info){
            p->right = remove(p->right,w);	
        }
        else
        {
            node* l = p->left;
            node* r = p->right;
            delete p;
            if(r == 0) return l;
            node* min = find_min(r);
            min->right = remove_min(r);
            min->left = l;
            return balance(min);
        }
    return balance(p);
}


void show(node* &p)
{
	if (p)
	{
		show(p->left);
		cout << p->info << "  ";
		show(p->right);
	}
	//cout << "\n";
}


void remove_tree(node* &p)
{
	if (p)
	{
		remove_tree(p->left);
		remove_tree(p->right);
        delete p;
	}
}


int main()
{
	int x, y, key = 0; node* Root = 0;
	while (1)
	{
		cout << "1. Add\n";
		cout << "2. Remove\n";
		cout << "3. Show\n";
		cout << "0. Exit\n";
		cin >> key;
		if (key == 1){
			cin >> x;
			add(x, Root);
		}
		if (key == 2){
			cin >> x;
			remove(Root, x);
		}
		if (key == 3){
			show(Root);
		}
		
		if (key == 0)
			break;
	}
    remove_tree(Root);
	return 0;
}
