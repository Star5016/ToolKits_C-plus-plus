#define ElemType char
using namespace std;
typedef struct linknode {
    ElemType data;
    struct linknode* next;
}LinkStNode;

void InitStack(LinkStNode*&s){
    s=new LinkStNode;
    s->next=nullptr;
}

void DestoryStack(LinkStNode*&s){
    LinkStNode* pre=s,*p=s->next;
    while(p!= nullptr){
        delete pre;
        pre=p;
        p=p->next;
    }
    delete pre;
}

bool isEmpty(LinkStNode* s){
    return s->next==nullptr;
}
bool push(LinkStNode*&s, ElemType elem){
    LinkStNode* p=new LinkStNode;
    p->data=elem;
    p->next=s->next;
    s->next=p;
}

bool pop(LinkStNode*&s, ElemType&elem){
    if(isEmpty(s)){
        return false;
    }
    LinkStNode* p=s->next;
    elem=p->data;
    s->next=p->next;
    delete p;
    return true;
}

int main() {
    

    return 0;
}
