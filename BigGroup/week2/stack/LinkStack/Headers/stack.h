#ifndef STACK_H
#define STACK_H

typedef int SElemType;
typedef int Status;

#define OK 1
typedef struct StackNode {
	SElemType data;
	struct StackNoede* next;

}StackNode, * LinkStack;

int InitStack(LinkStack* S);//��ʼ��

Status StackEmpty(LinkStack S);//�ж��Ƿ�Ϊ��

Status Push(LinkStack* S, SElemType e);//��ջ

Status Pop(LinkStack* S);//��ջ

SElemType GetTop(LinkStack S); //���ջ��Ԫ��

Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack s);//���ջ����





#endif