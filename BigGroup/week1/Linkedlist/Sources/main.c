#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"


int main()
{
	Linklist head = NULL;
	int num = 0;
	int flag = 0;//判断是否有链表存在
	do
	{
		show();



		printf("请输入你的选项");
		num = judge();
		system("cls");
		switch (num)
		{
		case 1:
			if (InitList(&head))
				printf("初始化成功");
			flag = 1;
			break;
		case 2:
			Create(&head);
			flag = 1;
			break;
		case 3:
			if (flag)
			{
				DestroyList(&head);
				flag = 0;
			}
			else
			{
				printf("没有链表存在");
			}
			break;
		case 4:
			if (flag)
			{
				int i;//插入的位置
				Elemtype data;//插入的数据
				printf("请输入插入的位置");
				scanf_s("%d", &i);
				printf("请输入要插入的数据");
				scanf_s("%d", &data);
				if (InsertList(&head, i, data))
				{
					printf("插入成功");
				}
				else
				{
					printf("插入失败，请重新输入插入的位置");
					scanf_s("%d", &i);
					InsertList(&head, i, data);


				}
			}
			else
			{
				printf("没有链表存在");
			}
			break;
		case 5:
			if (flag)
			{
				Elemtype x;
				printf("请输入要删除的位置");
				scanf_s("%d", &x);
				if (DeleteList(&head, x))
				{
					printf("删除成功");
				}
				else
				{
					printf("删除失败，请重新输入位置");
					scanf_s("%d", &x);
				}
			}
			else
			{
				printf("没有链表存在");
			}
			break;
		case 6:
			if (flag)
			{
				int num;
				printf("请输入你要查找的数据");
				scanf_s("%d", &num);
				if (SearchList(head, num))
				{
					printf("该数存在\n");
				}
				else
				{
					printf("该数不存在\n");
				}
				break;
			}
		case 7:
			if (flag)
			{
				Linklist l = (Linklist)malloc(sizeof(LNode));
				l->next = ReverseList(head->next, NULL);
				head = l;
			}
			else
			{
				printf("没有链表存在");
			}
			break;
		case 8:
			if (flag)
			{
				Linklist l = (Linklist)malloc(sizeof(LNode));
				l->next = ReverseList(head->next, NULL);
				head = l;
			}
			else
			{
				printf("没有链表存在");
			}
			break;
		case 9:
			if (flag)
			{
				int x = Listlength(head);
				ExchangeOddEven(&head, x);
			}
			else
			{
				printf("没有链表存在");
			}
			break;
		case 10:
			if (flag)
			{
				printf("链表中间存储的值为%d/n", (FindMidNode(head)->data));
			}
			else
			{
				printf("没有链表存在");
			}
			break;
		case 11:
			if (flag)
			{
				if (IsloopList(head))
				{
					printf("链表成环");
				}
				else
					printf("链表不成环");

			}
			else
			{
				printf("没有链表存在");
			}
		case 12:
			if (flag)
			{
				int length = Listlength(head);
				printf("表长为%d", length);
			}
		case 13:
			if (flag)
			{
				TraverseList(head);

			}
			else
			{
				printf("没有链表存在");
			}
			break;

		case 14:
			if (flag)
			{
				DestroyList(&head);
			}
		default:
		{
			printf("请重新输入数字1-14");
		}
		}
		

	}while (num != 14);

	return 0;

}