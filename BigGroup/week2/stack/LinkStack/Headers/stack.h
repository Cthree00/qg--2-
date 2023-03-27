#ifndef STACK_H
#define STACK_H

typedef int SElemType;
typedef int Status;

#define OK 1
typedef struct StackNode {
	SElemType data;
	struct StackNoede* next;

}StackNode, * LinkStack;

int InitStack(LinkStack* S);//初始化

Status StackEmpty(LinkStack S);//判断是否为空

Status Push(LinkStack* S, SElemType e);//入栈

Status Pop(LinkStack* S);//出栈

SElemType GetTop(LinkStack S); //获得栈顶元素

Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack s);//检测栈长度





#endif