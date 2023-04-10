#include<stdio.h>
#include"BinaryTree.h"

int main()
{
	int num = 0;
	int flag1 = 0;//�ж϶������Ƿ����
	int flag2 = 0;//�ж϶����������Ƿ����
	Node T,SortedT;
	void (*visit)(NodePtr) = Visit;
	Heap * H=NULL;
	do
	{
		show();
		printf("���������ѡ��");
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
			printf("������Ҫ���ҵ�ֵ");
			scanf_s("%d", &e);
			BST_search(&SortedT, e);
		}
		else
			printf("������������");
		break;
		}

		case 3:
		{
			if (flag2)
			{
				ElemType e;
				printf("������Ҫɾ����ֵ");
				scanf_s("%d", &e);
				BST_delete(&T, e);
			}
			else
				printf("������������");
			break;
		}
		case 4:
		{
			if (flag2)
			{
				ElemType e;
				printf("������Ҫ�����ֵ");
				scanf_s("%d", &e);
				BST_insert(&T, e);
			}
			else
				printf("������������");
			break;
		}

		case 5:
			if (flag1 || flag2)
				BST_preorderR(&T, visit);
			else
				printf("������������");
			break;
		case 6:
			if (flag1 || flag2)
				BST_inorderR(&T, visit);
			else
				printf("������������");
			break;
		case 7:
			if (flag1 || flag2)
				BST_postorderR(&T, visit);
			else
				printf("������������");
			break;
		case 8:
			if (flag1 || flag2)
				BST_preorderI(&T, visit);
			else
				printf("������������");
			break;
		case 9:
			if (flag1 || flag2)
				BST_postorderR(&T, visit);
			else
				printf("������������");
			break;
		case 10:
			if (flag1 || flag2)
				BST_postorderI(&T, visit);
			else
				printf("������������");
			break;
		case 11:
		{	if (flag1 || flag2)
			BST_levelOrder(&T, visit);
		else
			printf("������������");
		break;

		}
		case 12:
			H = HeapCreate();
			break;
		case 13:
			HeapDestroy(H);

		case 14:
		{
			printf("������Ҫ�����Ԫ��");
			HPDataType x;
			scanf_s("%d", &x);
			HeapPush(H, x);
		}

		}

	} while (num!=15);
}