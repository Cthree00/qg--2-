#include<stdio.h>
#include"Queue.h"

int main()
{
	LinkQueue Q;
	int num = 0;
	int flag = 0;
	do {
		show();
		printf("���������ѡ��");
		num = judge();
		system("cls");
		switch (num)
		{
		case 1:
			if (Init(&Q))
				printf("��ʼ���ɹ�");
			flag = 1;
			break;
		case 2:
			if (flag)
				Destroy(&Q);
			else
				printf("���в�����");
		case 3:
		{
			ElemType e;
			if (flag)
			{

				printf("��������ӵ�ֵ");
				scanf_s("%d", &e);
				DeQueue(&Q, &e);
			}
			else
				printf("���в�����");
		}
		case 4:
		{
			ElemType e;

			if (flag)
			{

				DeQueue(&Q, &e);
				printf("���ӵ�Ԫ����%d", e);
			}
			else
				printf("���в�����");
		}
		case 5:
		{
			ElemType e;
			if (flag)
			{
				GetHead(Q, &e);
				printf("��ͷԪ��Ϊ%d", e);
			}
			else
				printf("���в�����");
		}
		case 6:
			if (flag)
			{
				LengthLQueue(&Q);
			}
			else
				printf("���в�����");
			
		case 7:
		{
			if (flag)
			{
				ClearLQueue(&Q);
			}
			else
				printf("���в�����");
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