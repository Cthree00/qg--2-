#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

void show()
{
	
	printf(">>>1、判空           \n");
	printf(">>>2、入栈           \n");
	printf(">>>3、出栈           \n");
	printf(">>>4、取栈顶元素     \n");
	printf(">>>5、退出           \n");
}
int judge() //检测输入是否合法
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
			if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
			{
				printf("请输入整数：");
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
	for (m = 0; m < len; m++)  // 将字符重新转换为数字
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
		printf("栈顶元素为%d", S->data);
	else
		printf("栈为空");
}