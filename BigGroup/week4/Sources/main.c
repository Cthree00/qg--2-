#include<stdio.h>
#include"BinaryTree.h"

int main()
{
	int num = 0;
	int flag1 = 0;//判断二叉树是否存在
	int flag2 = 0;//判断二叉排序树是否存在
	Node T,SortedT;
	void (*visit)(NodePtr) = Visit;
	Heap * H=NULL;
	do
	{
		show();
		printf("请输入你的选项");
		num = judge();
		system("cls");
		
		switch (num)
		{
		case 1:
			BST_init(&T);
			flag1 = 1;
			break;
		case 2:
		{if (flag2)
		{
			ElemType e;
			printf("请输入要查找的值");
			scanf_s("%d", &e);
			BST_search(&SortedT, e);
		}
		else
			printf("二叉树不存在");
		break;
		}

		case 3:
		{
			if (flag2)
			{
				ElemType e;
				printf("请输入要删除的值");
				scanf_s("%d", &e);
				BST_delete(&T, e);
			}
			else
				printf("二叉树不存在");
			break;
		}
		case 4:
		{
			if (flag2)
			{
				ElemType e;
				printf("请输入要插入的值");
				scanf_s("%d", &e);
				BST_insert(&T, e);
			}
			else
				printf("二叉树不存在");
			break;
		}

		case 5:
			if (flag1 || flag2)
				BST_preorderR(&T, visit);
			else
				printf("二叉树不存在");
			break;
		case 6:
			if (flag1 || flag2)
				BST_inorderR(&T, visit);
			else
				printf("二叉树不存在");
			break;
		case 7:
			if (flag1 || flag2)
				BST_postorderR(&T, visit);
			else
				printf("二叉树不存在");
			break;
		case 8:
			if (flag1 || flag2)
				BST_preorderI(&T, visit);
			else
				printf("二叉树不存在");
			break;
		case 9:
			if (flag1 || flag2)
				BST_postorderR(&T, visit);
			else
				printf("二叉树不存在");
			break;
		case 10:
			if (flag1 || flag2)
				BST_postorderI(&T, visit);
			else
				printf("二叉树不存在");
			break;
		case 11:
		{	if (flag1 || flag2)
			BST_levelOrder(&T, visit);
		else
			printf("二叉树不存在");
		break;

		}
		case 12:
			H = HeapCreate();
			break;
		case 13:
			HeapDestroy(H);

		case 14:
		{
			printf("请输入要插入的元素");
			HPDataType x;
			scanf_s("%d", &x);
			HeapPush(H, x);
		}

		}

	} while (num!=15);
}