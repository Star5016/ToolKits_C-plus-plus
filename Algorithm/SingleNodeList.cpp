#include <iostream>
using namespace std;

//List define
typedef struct SLNode {
	int data;//data
	struct SLNode* next;//pointer to next node
}SingleNodeLinkList;

// The function for Single Node Link List   BEGIN
// 1.HeadInsert
void HeadInsertForSLNode(SingleNodeLinkList*& L, int elemArr[], int n) {
	SingleNodeLinkList* s;
	L = new SLNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = new SLNode;
		s->data = elemArr[i];
		s->next = L->next;
		L->next = s;
	}
}

//2.Tail Insert
void TailInsertForSLNode(SingleNodeLinkList*& L, int elemArr[], int n) {
	SingleNodeLinkList* s, * r;
	L = new SingleNodeLinkList;
	r = L; //pointer r always point to the tail node
	for (int i = 0; i < n; i++) {
		s = new SingleNodeLinkList;
		s->data = elemArr[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;//the last node point NULL
}

//3.Init SingleNodeLinkList
void InitSLNode(SingleNodeLinkList*& L) {
	L = new SingleNodeLinkList;
	L->next = NULL;
}

//4.DestorySLNode
void DestorySLNode(SingleNodeLinkList*& L) {
	SingleNodeLinkList* pre = L, * p = L->next;
	while (p != NULL) {
		delete pre;
		pre = p;
		p = pre->next;
	}
	delete pre;
}

//5.show data
void showElemForSLNode(SLNode& L) {
	SLNode* p = L.next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}
//The function for Single Node Link List  END


//The Main Function
int main() {


	return 0;
}


// Written by Star 
// Date : 2024.03.08
