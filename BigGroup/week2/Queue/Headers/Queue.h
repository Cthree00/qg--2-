#ifndef QUEUE_H
#define QUEUE_H
#define MAXQSIZE 100

typedef int ElemType;
typedef int Status;
typedef struct Qnode {
	ElemType data;    //数据域
	struct Qnode* next;  //指针域
}QNode;

typedef struct {
	QNode * front;  //头指针
	QNode * rear; //尾指针
}LinkQueue;

int Init(LinkQueue* Q);
int Destroy(LinkQueue* Q);
int EnQueue(LinkQueue* Q, ElemType e);
int DeQueue(LinkQueue* Q, ElemType* e);
int GetHead(LinkQueue Q, ElemType* e);
int LengthLQueue(LinkQueue* Q);
void ClearLQueue(LinkQueue* Q);
Status TraverseLQueue(const LinkQueue* Q, void (*foo)(void* q));
void LPrint(void* q);




void show();
int judge();

#endif
