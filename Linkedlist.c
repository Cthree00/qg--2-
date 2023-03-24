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
void Create(Linklist* l)//β�巨��������
{
	int n; //�����
	int i; //�ƴ�
	Linklist trail;  //βָ��
	*l = (Linklist)malloc(sizeof(LNode));//ͷָ��
	(*l)->next = NULL;
	(*l)->data = 0;
	printf("��������Ҫ����������Ľ����");
	scanf_s("%d", &n);

	trail = *l;
	for (i = 0; i < n; ++i)
	{
		Linklist p = (Linklist)malloc(sizeof(LNode)); //�����½�㣬
		printf("��������ֵ");
		scanf_s("%d", &(p->data));

		p->next = NULL;
		trail->next = p;  //���뵽��β
		trail = p;//ָ���µ�β���


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
	while (p && j < i - 1) //Ѱ�ҵ�һ��i-1��㣬pָ��i-1���
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)return ERROR; //i���ڱ�+1����С��1
	Linklist s = (Linklist)malloc(sizeof(LNode)); //�����½ڵ�

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
	q = (*p)->next;   //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
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
	if (p)return j;   //p��Ϊ�գ����ҵ���ֵ������Ԫ�ص�λ��
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
	//�ȵ���1��2�ڵ��λ�ã���2����Ϊͷ��㣬1ָ��3
	p1 = *l;
	p2 = (*l)->next;
	p1->next = p2->next;
	p2->next = p1;
	p = p1; //p���ڱ����һ�ε�����p1��λ��
	for (int a = 1; a <= (x / 2) - 1; a++)  //��Ϊ1��2�Ѿ�����������ѭ������-1
	{
		p1 = p->next;
		p2 = p1->next;                      //p->p1->p2
		p->next = p2;
		p1->next = p2->next;                //��ż�ڵ�ĵ���
		p2->next = p1;
		p = p1;                             //��ǵ�����p1��λ��
	}
	//�������һ��
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
		printf("��������ȷ������");
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
