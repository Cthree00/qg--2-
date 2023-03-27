#ifndef QUEUE_H
#define QUEUE_H
#define MAXQSIZE 100

typedef int ElemType;
typedef int Status;
typedef struct Qnode {
	ElemType data;    //������
	struct Qnode* next;  //ָ����
}QNode;

typedef struct {
	QNode * front;  //ͷָ��
	QNode * rear; //βָ��
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
