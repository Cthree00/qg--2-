#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	LinkStack S = NULL;
	int num = 0, choice = 0;

	do
	{
		show();
		printf("���������ѡ��");
		num = judge();
		system("cls");
		switch (num)
		{

		case 1:
		{	if (StackEmpty(S))
			printf("ջΪ��");
		   else
			printf("ջ��Ϊ��");
		break;
		}
		case 2:
		{	SElemType e;
		printf("��������Ҫ�����Ԫ��");
		scanf_s("%d", &e);
		if (Push(&S, e))
			printf("����ɹ�");
		break;
		}
		case 3:
		{
			SElemType e;
			Pop(&S);
			
				
			
			break;
		}
		case 4:
		{
			
			GetTop(S);
			break;
		}
		


		}
	} while (num!=5);
}

