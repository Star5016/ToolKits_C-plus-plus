#include <iostream>
#define ElemType char
#define MaxSize 100

using namespace std;
typedef struct SqStack{
    ElemType data[MaxSize];
    int top;
};

void InitStack(SqStack*& S){
    S=new SqStack();
    S->top=-1;
};

void DestoryStack(SqStack*& S){
    delete S;
};

bool isEmpty(SqStack *S){
    return S->top==-1;
};

void push(SqStack*& S, ElemType elem){
    if(S->top==MaxSize-1){
        cout<<"栈已满"<<endl;
        return;
    }
    S->top++;
    S->data[S->top]=elem;
};

bool pop(SqStack*& S, ElemType& elem){
    if(S->top==-1){
        cout<<"栈为空"<<endl;
        return false;
    }
    elem=S->data[S->top];
    S->top--;
    return true;
}
int main() {
    
    return 0;
}
