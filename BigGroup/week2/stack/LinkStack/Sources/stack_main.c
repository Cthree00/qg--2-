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
		printf("请输入你的选项");
		num = judge();
		system("cls");
		switch (num)
		{

		case 1:
		{	if (StackEmpty(S))
			printf("栈为空");
		   else
			printf("栈不为空");
		break;
		}
		case 2:
		{	SElemType e;
		printf("请输入你要插入的元素");
		scanf_s("%d", &e);
		if (Push(&S, e))
			printf("插入成功");
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
		case 5:
		{
			if (clearLStack(&S))
				printf("清空成功");
			else
				printf("清空失败");

			break;
		}
		case 6:
			if (destroyLStack(&S))
				printf("销毁成功");
			else
				printf("销毁失败");
			break;
		case 7:
		{
			int length;
			length=LStackLength(S);
			printf("栈的长度为%d", length);
		}

		



		}
	} while (num!=8);
}

