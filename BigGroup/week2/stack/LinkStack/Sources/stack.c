#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

void show()
{
	
	printf(">>>1���п�           \n");
	printf(">>>2����ջ           \n");
	printf(">>>3����ջ           \n");
	printf(">>>4��ȡջ��Ԫ��     \n");
	printf(">>>5���˳�           \n");
}
int judge() //��������Ƿ�Ϸ�
{
	int len, num = 0, arg = 1;
	char word[10];
	int m, j = 1, k;
	while (j)
	{
		gets_s(word, 10);
		len = strlen(word);
		for (m = 0; m < len; m++)
		{
			if (word[m] < '0' || word[m]>'9')  //�����Ƿ��������������ַ�
			{
				printf("������������");
				break;
			}
			else
			{
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	for (m = 0; m < len; m++)  // ���ַ�����ת��Ϊ����
	{
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}

Status StackEmpty(LinkStack S)
{
	if (S == NULL)return 1;
	else return 0;

}

Status Push(LinkStack* S, SElemType e)
{
	LinkStack p = (LinkStack)malloc(sizeof(StackNode));
	p->data = e;
	p->next = (*S);
	*S = p;
	return OK;
}

Status Pop(LinkStack* S)
{
	LinkStack p;
	if (*S == NULL)return 0;
	
	p = (*S);
	(*S) = (*S)->next;
	free(p);
	return OK;

}
SElemType GetTop(LinkStack S)
{
	if (S != NULL)
		printf("ջ��Ԫ��Ϊ%d", S->data);
	else
		printf("ջΪ��");
}