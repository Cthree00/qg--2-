#ifndef STACK_H
#define STACK_H

typedef int SElemType;
typedef int Status;

#define OK 1
typedef struct StackNode {
	SElemType data;
	struct StackNoede* next;
}StackNode, * LinkStack;

int InitStack(LinkStack* S);

Status StackEmpty(LinkStack S);

Status Push(LinkStack* S, SElemType e);

Status Pop(LinkStack* S);

SElemType GetTop(LinkStack S);





#endif