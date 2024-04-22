// Single Node Link List

#include <iostream>
using namespace std;
typedef int ElementType;

class node {
public:
    ElementType data;
    node *next;
};

class LinkList {
    node *head;
public:
    // Constructor
    LinkList() {
        head = new node;
        head->next = nullptr;
    }

    // Destructor
    ~LinkList() {
        node *p = head, *q;
        while (p != nullptr) {
			q = p->next;
            delete p;
            p = q;
        }
        delete p;
    }
    // Display the list
    void Display() {
        node *p = head->next;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
    }
    // Copy the array to the list by Head Insertion
    void HeadInsert(ElementType a[],int n){
        node *p;
        for (int i=0;i<n;i++){
            p=new node;
            p->data=a[i];
            p->next=this->head->next;
            this->head->next=p;
        }
    }
    // Copy the array to the list by Tail Insertion
    void TailInsert(ElementType a[],int n){
        node *p,*q;
        q=this->head;
        // Locate the last node
        while(q->next!=nullptr) {
            q = q->next;
        }
        for (int i=0;i<n;i++){
            p=new node;
            p->data=a[i];
            q->next=p;
            q=p;
        }
        q->next=nullptr;
    }
    // Get the length of the list
    int Length(){
        node *p=this->head;
        int len=0;
        while(p->next!=nullptr){
            len++;
            p=p->next;
        }
        return len;
    }

    // Get the i-th node
    bool GetElem(int i,ElementType &e){
        node *p=this->head;
        int j=0;
        while(p!= nullptr &&j<i){
            p=p->next;
            j++;
        }
        if(p== nullptr){
            return false;
        }
        else{
            e=p->data;
            return true;
        }
    }

    // Insert the node at the i-th position
    bool Insert(int i,ElementType e){
        node *p=this->head;
        int j=0;
        while(p!= nullptr &&j<i-1){
            p=p->next;
            j++;
        }
        if(p== nullptr){
            return false;
        }
        else{
            node *s=new node;
            s->data=e;
            s->next=p->next;
            p->next=s;
            return true;
        }
    }

    // Delete the node at the i-th position
    bool Delete(int i){
        node *p=this->head;
        int j=0;
        while(p!= nullptr &&j<i-1){
            p=p->next;
            j++;
        }
        if(p== nullptr){
            return false;
        }
        else{
            node *q=p->next;
            p->next=q->next;
            delete q;
            return true;
        }
    }
};

void test() {
    LinkList L;
    ElementType a[5] = {1, 2, 3, 4, 5};
    L.HeadInsert(a, 5);
    L.Display();
    cout << endl;
    L.TailInsert(a, 5);
    L.Display();
    cout << endl;
    ElementType e;
    L.GetElem(3, e);
    cout << e << endl;
    L.Insert(3, 6);
    L.Display();
    cout << endl;
    L.Delete(3);
    L.Display();
}

int main(){
    test();
    return 0;
}
