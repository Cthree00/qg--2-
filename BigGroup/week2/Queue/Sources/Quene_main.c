#include<stdio.h>
#include"Queue.h"

int main()
{
	LinkQueue Q;
	int num = 0;
	int flag = 0;
	do {
		show();
		printf("请输入你的选项");
		num = judge();
		system("cls");
		switch (num)
		{
		case 1:
			if (Init(&Q))
				printf("初始化成功");
			flag = 1;
			break;
		case 2:
			if (flag)
				Destroy(&Q);
			else
				printf("队列不存在");
		case 3:
		{
			ElemType e;
			if (flag)
			{

				printf("请输入入队的值");
				scanf_s("%d", &e);
				DeQueue(&Q, &e);
			}
			else
				printf("队列不存在");
		}
		case 4:
		{
			ElemType e;

			if (flag)
			{

				DeQueue(&Q, &e);
				printf("出队的元素是%d", e);
			}
			else
				printf("队列不存在");
		}
		case 5:
		{
			ElemType e;
			if (flag)
			{
				GetHead(Q, &e);
				printf("队头元素为%d", e);
			}
			else
				printf("队列不存在");
		}
		case 6:
			if (flag)
			{
				LengthLQueue(&Q);
			}
			else
				printf("队列不存在");
			
		case 7:
		{
			if (flag)
			{
				ClearLQueue(&Q);
			}
			else
				printf("队列不存在");
		case 8:
			if (flag)
			{
				void (*foo)(int q)=LPrint;
				TraverseLQueue(&Q, foo);
			}
		}
		}
	} while (num != 9);
}