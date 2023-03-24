#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Status InitList(Linklist* l)
{
	*l = (Linklist)malloc(sizeof(LNode));

	if (*l != NULL)
	{
		(*l)->next = NULL;
		(*l)->data = 0;

	}
	return OK;

}
void Create(Linklist* l)//尾插法创建链表
{
	int n; //结点数
	int i; //计次
	Linklist trail;  //尾指针
	*l = (Linklist)malloc(sizeof(LNode));//头指针
	(*l)->next = NULL;
	(*l)->data = 0;
	printf("请输入你要创建的链表的结点数");
	scanf_s("%d", &n);

	trail = *l;
	for (i = 0; i < n; ++i)
	{
		Linklist p = (Linklist)malloc(sizeof(LNode)); //生成新结点，
		printf("请输入数值");
		scanf_s("%d", &(p->data));

		p->next = NULL;
		trail->next = p;  //插入到表尾
		trail = p;//指向新的尾结点


	}


}
void DestroyList(Linklist* l)
{
	LNode* p;
	while (l)
	{
		p = *l;
		*l = (*l)->next;
		free(p);
	}
}
Status InsertList(Linklist* l, int i, Elemtype a)
{
	Linklist p = *l;
	int j = 0;
	while (p && j < i - 1) //寻找第一个i-1结点，p指向i-1结点
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)return ERROR; //i大于表长+1或者小于1
	Linklist s = (Linklist)malloc(sizeof(LNode)); //生成新节点

	s->next = p->next;
	s->data = a;
	p->next = s;
	return OK;

}
Status DeleteList(Linklist* l, int i)
{
	Linklist* p = l;
	Linklist  q = NULL;
	int j = 0;
	while ((*p)->next && j < i - 1)
	{
		(*p) = (*p)->next;
		j++;
	}
	if (!((*p)->next) || j > i - 1)return ERROR;
	q = (*p)->next;   //临时保存被删结点的地址以备释放
	(*p)->next = q->next;
	free(q);
	return OK;
}
Status SearchList(Linklist l, Elemtype a)
{
	Linklist p = l->next;
	int j = 1;
	while (p && (p->data) != a)
	{
		p = p->next;
		j++;
	}
	if (p)return j;   //p不为空，即找到数值，返回元素的位置
	else return 0;
}
Linklist ReverseList(Linklist cur, Linklist pre)
{
	Linklist temp;
	if (cur == NULL) return pre;
	temp = cur->next;
	cur->next = pre;
	ReverseList(temp, cur);

}
Linklist ReverseList_literated(Linklist cur)
{
	Linklist pre = NULL, temp;
	while (cur)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}
int Listlength(Linklist l)
{
	Linklist p;
	p = l->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}
Status ExchangeOddEven(Linklist* l, int x)
{
	Linklist p1, p2, p;
	//先调换1、2节点的位置，让2结点成为头结点，1指向3
	p1 = *l;
	p2 = (*l)->next;
	p1->next = p2->next;
	p2->next = p1;
	p = p1; //p用于标记上一次调换后p1的位置
	for (int a = 1; a <= (x / 2) - 1; a++)  //因为1，2已经调换，所以循环次数-1
	{
		p1 = p->next;
		p2 = p1->next;                      //p->p1->p2
		p->next = p2;
		p1->next = p2->next;                //奇偶节点的调换
		p2->next = p1;
		p = p1;                             //标记调换后p1的位置
	}
	//输出测试一下
	p = *l;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}


}
Status IsloopList(Linklist l)
{
	Linklist fast = l, slow = l;
	while (fast->next != NULL && slow->next != NULL)
	{
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)return ERROR;
		if (fast == slow)return OK;
	}
	return ERROR;
}
LNode* FindMidNode(Linklist l)
{
	Linklist slow = l, fast = l;
	while (fast != NULL && slow != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
int InputNumber()
{
	int num;
	scanf_s("%d", &num);
	if (num < 1 || num>13)
	{
		printf("请输入正确的数字");
		scanf_s("%d", &num);
	}
	return num;
}
void TraverseList(Linklist l)
{
	Linklist temp;
	temp = l->next;
	while (temp)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
