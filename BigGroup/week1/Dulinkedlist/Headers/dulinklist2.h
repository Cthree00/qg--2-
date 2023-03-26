#ifndef DULINKLIST_H_INCLUDED
#define DULINKLIST_H_INCLUDED

#define success 1
#define error 0

typedef int Status;
typedef int ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode* next, *prior;
}DuLNode, * DuLinkedList;

Status InitList_DuL(DuLinkedList* L);
void DestroyList_DuL(DuLinkedList* L);
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);
Status DeleteList_DuL(DuLNode* p, ElemType* e);
Status ListInsert(DuLinkedList* l, int i, ElemType e)
void LocateElem(DulNode* p, ElemType a);
void GetElem(DulNode* p, int i);
void TraverseList_DuL(DuLinkedList L);
void show(void);
int judge();
#endif





