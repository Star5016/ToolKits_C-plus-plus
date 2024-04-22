// Double Link Node List 
#include <iostream>
using namespace std;
typedef int ElementType;

class DNode{
public:
    ElementType data;
    DNode *prior,*next;
};

class DLinkList{
    DNode *head;
public:
    // Empty Constructor
    DLinkList(){
        head=new DNode;
        head->next=head->prior=nullptr;
    }
    // Destructor
    ~DLinkList(){
        DNode *p=head,*q;
        while(p!= nullptr){
            q=p->next;
            delete p;
            p=q;
        }
        delete p;
    }
    // Copy Array by Head Insertion
    void HeadInsert(ElementType a[],int n){
        DNode *s;
        for(int i =0;i<n;i++){
            s=new DNode;
            s->data=a[i];
            s->next=head->next;
            if(head->next!=nullptr){head->next->prior=s;}
            head->next=s;
            s->prior=head;
        }
    }
    // Copy Array by Tail Insertion
    void TailInsert(ElementType a[],int n){
        DNode *s,*p=head;
        // Find the Last Node
        while(p->next!=nullptr){
            p=p->next;
        }
        for (int i =0;i<n;i++){
            s=new DNode;
            s->data=a[i];
            s->prior=p;p->next=s;
            p=s;
        }
        p->next=nullptr;
    }
    // Insert Element at the i-th position
    bool Insert(int i ,ElementType x){
        int j=0;
        DNode *p=head;
        while(p!=nullptr&&j<i-1){
            p=p->next;
            j++;
        }
        if(p==nullptr){
            cout<<"Index out of range"<<endl;
            return false;
        }
        else{
            DNode *s=new DNode;
            s->data=x;
            s->next=p->next;
            if (p->next!=nullptr)p->next->prior=s;
            s->prior=p;
            p->next=s;
        }
    }
    // Delete Element at the i-th position then assign it to x
    bool Delete(int i,ElementType &x){
        int j=0;DNode *p=head,*q;
        while(p!=nullptr&&j<i-1){
            p=p->next;
            j++;
        }
        if(p==nullptr){
            cout<<"Index out of range"<<endl;
            return false;
        }
        else{
            q=p->next;
            if(q==nullptr){
                return false;
        }
            x=q->data;
            p->next=q->next;
            if(q->next!=nullptr)q->next->prior=p;
            delete q;
            return true;
        }
    }
    // Locate the Element and then return the positon  -1 means not found
    int locate(ElementType x){
        DNode *p=head;
        int j=0;
        while(p!=nullptr&&p->data!=x){
            p=p->next;
            j++;
        }
        if(p==nullptr){
            return -1;
        }
        else{
            return j;
        }
    }
    // Display the List
    void Display(){
        DNode *p=head->next;
        if(p==nullptr){
            cout<<"Empty List"<<endl;
        }
        else{
            while(p!=nullptr){
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
    }
};

void test(){
    DLinkList L;
    ElementType a[5]={1,2,3,4,5};
    L.HeadInsert(a,5);
    L.Display();
    L.TailInsert(a,5);
    L.Display();
    L.Insert(2,6);
    L.Display();
    ElementType x;
    L.Delete(2,x);
    L.Display();
    cout<<L.locate(3)<<endl;
}
int main(){
    test();
    return 0;
}

