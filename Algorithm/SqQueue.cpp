#include<iostream>
#define MAXSIZE 100
typedef int ElemType;
using namespace std;
class SqQueue{
    ElemType *data;
    int front,rear;
public:
    SqQueue(){
        data=new ElemType[MAXSIZE];
        front=rear=0;
    }
    ~SqQueue(){
        delete []data;
    }
    bool isEmpty(){
        return front==(rear+1)%MAXSIZE;
    }
    bool isFull(){
        return (rear+1)%MAXSIZE==front;
    }
    int enQueue(ElemType x){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return -1;
        }
        data[rear]=x;
        rear=(rear+1)%MAXSIZE;
        return 1;
    }
    int deQueue(ElemType &x){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        x=data[front];
        front=(front+1)%MAXSIZE;
        return 1;
    }
    void displayQueue(){
        for(int i=front;i!=rear;i=(i+1)%MAXSIZE){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};
void test(){
    SqQueue q;
    int x;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.displayQueue();
    q.deQueue(x);
    q.displayQueue();
    cout<<x<<endl;
}
int main(){
    test();
    return 0;
}
