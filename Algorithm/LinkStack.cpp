#include<iostream>
typedef int ElemType;
using namespace std;
class node{
public:
    ElemType data;
    node *next;
};
class linkStack{
    node *top;
public:
    linkStack(){
        this->top=nullptr;
    }
    ~linkStack(){
        node *p=this->top->next;
        while(p!=nullptr){
            delete this->top;
            this->top=p;
            p=p->next;
        }
        delete this->top;
    }
    bool isEmpty(){
        return this->top==nullptr;
    }
    int getLength(){
        int len=0;
        node *p=this->top;
        while(p!=nullptr){
            len++;
            p=p->next;
        }
        return len;
    }
    void push(ElemType x){
        node *p=new node;
        p->data=x;
        p->next=this->top;
        this->top=p;
    }
    int pop(ElemType &x){
        if(this->top== nullptr){
            return -1;
        }
        node *s=this->top;
        this->top=s->next;
        x=s->data;
        delete s;
        return 1;
    }
    int getTop(ElemType &x){
        if(this->top== nullptr){
            return -1;
        }
        x=this->top->data;
        return 1;
    }
    void displayStack(){
        node *p=this->top;
        while(p!= nullptr){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
void test(){
    linkStack s;
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