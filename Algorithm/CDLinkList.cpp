// Circle Double Node Link List
#include<iostream>
using namespace std;
typedef int ElemType;
class Node{
public:
    ElemType data;
    Node *next;
    Node *prior;
};
class LinkList{
public:
    Node *head;
//public:
    // Constructor of LinkList
    LinkList(){
        head = new Node;
        head->next = head->prior=head;
    }
    // Destructor of LinkList
    ~LinkList(){
        Node *p = head->next, *q=p->next;
        while(p!=head){
            delete p;
            p=q;
            q=q->next;
        }
        delete head;
    }
    // Copy from Array by Head Insertion
    void HeadInsert(ElemType a[] ,int n){
        Node *p;
        for(int i =0;i<n;i++){
            p=new Node;
            p->data=a[i];
            p->next=head->next;
            head->next->prior=p;
            head->next=p;
            p->prior=head;
        }

    }
    // Copy from Array by Tail Insertion
    void TailInsert(ElemType a[],int n){
        Node *p=head,*q=head->prior,*s;
        for (int i =0;i<n;i++){
            s=new Node;
            s->data=a[i];
            p->next=s;
            s->prior=q;
            p=s;
        }
        p->next=q;
        q->prior=p;
    }
    // Check if the LinkList is Empty
    bool isEmpty(){
        return (head->next==head);
    }
    // Get the length of LinkList
    int getLength(){
        Node *p=head->next;
        int len=0;
        while(p!=head){
            len++;
            p=p->next;
        }
        return len;
    }
    // Display List
    void display(){
        Node *p=head->next;
        while(p!=head){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    // Get the i-th element of LinkList
    bool GetElem(int i,ElemType &e){
        Node *p=head->next;
        int j=1;
        if(p!=head){
            while(p!=head&&j<i){
                p=p->next;
                j++;
            }
            if(p==head){
                cout<<"i is out of range"<<endl;
                return false;}
            e=p->data;
            return true;
        }
        else return false;

    }
    // Insert the element e at the i-th position of LinkList
    bool Insert(int i,ElemType e){
        Node *p=head->next,*q=head,*s;
        int j=1;
        while(p!=head&&j<i){
            p=p->next;
            q=q->next;
            j++;
        }
        if(i==1&&p==head){//Empty List
            s=new Node;
            s->data=e;
            s->next=head->next;
            head->next->prior=s;
            s->prior=head;
            head->next=s;
        }
        else if(p==head){
            cout<<"i is out of range"<<endl;
            return false;
        }
        else{
            s=new Node;
            s->data=e;
            s->next=q->next;
            q->next->prior=s;
            q->next=s;
            s->prior=q;
            return true;
        }
    }
    // Delete the i-th element of LinkList
    bool Delete(int i,ElemType &e){
        Node *p=head->next,*q=head,*s;
        int j=1;
        while(p!=head&&j<i) {
            p = p->next;
            q = q->next;
            j++;
        }
        if(p==head){
            cout<<"i is out of range"<<endl;
            return false;
        }
        else{
            q->next=p->next;
            p->next->prior=q;
            e=p->data;
            delete p;
            return true;
        }
    }
};

void test(){
    LinkList L;
    ElemType e;
    int a[5]={1,2,3,4,5};
    //L.Insert(1,99);
    L.TailInsert(a,5);
    cout<<L.head->prior->data;
    L.display();
    L.Delete(3,e);
    L.display();
}

int main(){
    test();
    return 0;
}
