#include <iostream>
using namespace std;

//List define
typedef struct SLNode{
	int data;//data
	struct SLNode* next;//pointer to next node
 }SingleNodeLinkList;

typedef struct DLNode{
	int data;//data
	struct DLNode* prior;//pointer to former node
	struct DLNode* next;//pointer to next node
}DoubleNodeLinkList;



// main function
int main(){


return 0;
}

// The function for Single Node Link List   BEGIN
// 1.HeadInsert
void HeadInsertForSLNode(SingleNodeLinkList &L,int elemArr[],int n){
	SingleNodeLinkList *s;
	L= new SingleNodeLinkList(sizeof(SingleNodeLinkList));
	L->next=NULL;
	for(int i =0;i<n;i++){
		s=new SingleNodeLinkList(sizeof(SingleNodeLinkList));
		s->data=elemArr[i];
		s->next=L->next;
		L->next=s;
	}
}

//2.Tail Insert
void TailInsertForSLNode(SingleNodeLinkList &L,int elemArr[],int n){
	SingleNodeLinkList *s,*r;
	L=new SingleNodeLinkList(sizeof(SingleNodeLinkList));
	r=L; //pointer r always point to the tail node
	for(int i = 0;i<n;i++){
		s=new SingleNodeLinkList(sizeof(SingleNodeLinkList));
		s->data=elemArr[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;//the last node point NULL
}

//3.Init SingleNodeLinkList
void InitSLNode(SingleNodeLinkList &L){
	L=new SingleNodeLinkList(sizeof(SingleNodeLinkList));
	L->next=NULL;
}

void DestorySLNode(SingleNodeLinkList &L){
	SingleNodeLinkList *pre=L, *p=L->next;
	while(p!=NULL){
		delete pre;
		pre=p;
		p=pre->next;
	}
	delete pre;
}


//The function for Single Node Link List  END

// The function for Double Node Link List BEGIN
void HeadInsertForDLNode(DoubleNodeLinkList &L,int elemArr[],int n){

}

// The function for Double Node Link List  END

// The function for Both Of All BEGIN


// The function for Both Of All END
// Written by Star
