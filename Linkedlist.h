#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED






#define OK 1
#define ERROR 0


typedef int Status;
typedef int Elemtype;

typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode, * Linklist;

Status InitList(Linklist* l);

void Create(Linklist* l);

Status InsertList(Linklist* l, int i, Elemtype a);

Status DeleteList(Linklist* l, Elemtype a);

void DestroyList(Linklist* l);


Status SearchList(Linklist l, Elemtype a);

Status ExchangeOddEven(Linklist* l, int x);
Linklist ReverseList(Linklist cur, Linklist pre);

Linklist ReverseList_literated(Linklist l);

LNode* FindMidNode(Linklist l);

Status IsloopList(Linklist l);

int Listlength(Linklist l);

void TraverseList(Linklist l);

int InputNumber();

#endif
