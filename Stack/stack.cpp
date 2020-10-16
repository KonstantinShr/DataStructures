#include <iostream>
#include <stdlib.h>

using namespace std;

struct stack {
	int* data;
	int top;
};



stack* CreateStack(){
    stack* stk;
    stk = (stack*)malloc(sizeof(stack));
    stk->data = (int*)malloc(sizeof(int));
    stk->top = 0;
    return stk;
}

int add(stack* stk, int value) {
    stk->data[stk->top] = value;
    stk->data = (int*)realloc(stk->data, ((stk->top+2)*sizeof(int)));
	if (stk->data == NULL){
        return 100;
	}
	stk->top++;
    return 0;
}


int pop(stack* stk) {
    int rtn = 0;
    int buffer[stk->top];
    if (stk->top > 0){
        rtn = stk->data[stk->top-1];
        for (int i =0; i < stk->top; i++){
            buffer[i] = stk->data[i];
        }
        free(stk->data);
        stk->data = (int*)malloc(stk->top*sizeof(int));
        if (stk->data == NULL) return 100;
        for (int i =0; i < stk->top; i++){
            stk->data[i] = buffer[i];
        }
        stk->top--;
        return rtn;
    }
    else{
        return -7;
    }
}

void DeleteStack(stack* stk) {
	free(stk);
}

int main()
{
	stack* a;
    a = CreateStack();
	int data;
	while (true){
        cin >> data;
        if (data == 0){
            
            cout << pop(a);
            break;
        }
        else{
            add(a, data);
        }
	}
	DeleteStack(a);
	return 0;
}

