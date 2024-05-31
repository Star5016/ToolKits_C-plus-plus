#include<iostream>
#define MAXSIZE 100
typedef int ElemType;
using namespace std;
class SqStack{
    ElemType *data;
    int top;
public:
    SqStack(){
        top = -1;
        data = new ElemType[MAXSIZE];
    }
    ~SqStack(){
        delete[] data;
    }
    bool isEmpty(){
        return top == -1;
    }
    int getLength(){
        return top + 1;
    }
    void push(ElemType x){
        if(top==MAXSIZE-1){
            cout<<"Stack is Full"<<endl;
            return;
        }
        data[++top] = x;
    }
    int pop(ElemType &x){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        x = data[top--];
        return 1;
    }
    int getTop(ElemType &x){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        x = data[top];
        return 1;
    }
    void displayStack(){
        for(int i=top;i>=0;i--){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};
void test(){
    SqStack s;
    int x;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.displayStack();
    s.pop(x);
    s.displayStack();
    s.getTop(x);
    cout<<x<<endl;
    s.displayStack();
}
int main(){
    test();
    return 0;
}
