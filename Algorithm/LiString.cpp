#include <iostream>
using namespace std;
class node{
public:
    char data;
    node *next;
};
class LiString{
    node *head;
public:
    LiString(){
        head = new node;
        head->next = nullptr;
    }
    explicit LiString(char s[]){
        head=new node;
        node *p=head,*q;
        for(int i=0;s[i]!='\0';i++){
            q = new node;
            q->data = s[i];
            p->next=q;
            p=q;
        }
        p->next=nullptr;
    }
    ~LiString(){
        node *p = head;
        while(p){
            node *q = p->next;
            delete p;
            p = q;
        }
        delete p;
    }
    void display(){
        node *p = head->next;
        while(p){
            cout<<p->data;
            p=p->next;
        }
    }
    bool isEqual(LiString &ls){
        node *p = this->head->next,*q = ls.head->next;
        while(p&&q&&p->data==q->data){
            p=p->next;
            q=q->next;
        }
        if(!p&&!q){
            return true;
        }else{
            return false;
        }
    }
    void Concat(LiString &ls){
        node *p = this->head,*q = ls.head->next;
        while(p->next){
            p=p->next;
        }
        while(q){
            node *r = new node;
            r->data = q->data;
            p->next = r;
            p=r;
            q=q->next;
        }
        p->next = nullptr;
    }
    void insert(int pos,char c){
        node *p = this->head,*q;
        while(p&&pos--){
            p=p->next;
        }
        if(p){
            q = new node;
            q->data = c;
            q->next = p->next;
            p->next = q;
        }else{
            cout<<"error: Position out of range"<<endl;
        }

    }
    void deleteNode(int pos){
        node *p = this->head,*q;
        while(p&&pos--){
            p=p->next;
        }
        if(p){
            q = p->next;
            p->next = q->next;
            delete q;
        }else{
            cout<<"error: Position out of range"<<endl;
        }
    }
    LiString SubString(int start,int len){
        LiString temp;
        node *p = this->head,*q,*s=temp.head;
        while(p&&start--){
            p=p->next;
        }
        while(p&&len--){
            q = new node;
            q->data = p->data;
            s->next = q;
            s=q;
            p=p->next;
        }
        s->next = nullptr;
        return temp;
    }


};

int main(){
    char s[] = "hello";
    LiString ls(s);
    ls.insert(6,'w');
    ls.SubString(1,3).display();
    //ls.display();
    return 0;
}