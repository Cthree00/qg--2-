#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"


int main()
{
	Linklist head = NULL;
	int num = 0;
	int flag = 0;//�ж��Ƿ����������
	do
	{
		show();



		printf("���������ѡ��");
		num = judge();
		system("cls");
		switch (num)
		{
		case 1:
			if (InitList(&head))
				printf("��ʼ���ɹ�");
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
				printf("û���������");
			}
			break;
		case 4:
			if (flag)
			{
				int i;//�����λ��
				Elemtype data;//���������
				printf("����������λ��");
				scanf_s("%d", &i);
				printf("������Ҫ���������");
				scanf_s("%d", &data);
				if (InsertList(&head, i, data))
				{
					printf("����ɹ�");
				}
				else
				{
					printf("����ʧ�ܣ���������������λ��");
					scanf_s("%d", &i);
					InsertList(&head, i, data);


				}
			}
			else
			{
				printf("û���������");
			}
			break;
		case 5:
			if (flag)
			{
				Elemtype x;
				printf("������Ҫɾ����λ��");
				scanf_s("%d", &x);
				if (DeleteList(&head, x))
				{
					printf("ɾ���ɹ�");
				}
				else
				{
					printf("ɾ��ʧ�ܣ�����������λ��");
					scanf_s("%d", &x);
				}
			}
			else
			{
				printf("û���������");
			}
			break;
		case 6:
			if (flag)
			{
				int num;
				printf("��������Ҫ���ҵ�����");
				scanf_s("%d", &num);
				if (SearchList(head, num))
				{
					printf("��������\n");
				}
				else
				{
					printf("����������\n");
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
				printf("û���������");
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
				printf("û���������");
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
				printf("û���������");
			}
			break;
		case 10:
			if (flag)
			{
				printf("�����м�洢��ֵΪ%d/n", (FindMidNode(head)->data));
			}
			else
			{
				printf("û���������");
			}
			break;
		case 11:
			if (flag)
			{
				if (IsloopList(head))
				{
					printf("����ɻ�");
				}
				else
					printf("�����ɻ�");

			}
			else
			{
				printf("û���������");
			}
		case 12:
			if (flag)
			{
				int length = Listlength(head);
				printf("��Ϊ%d", length);
			}
		case 13:
			if (flag)
			{
				TraverseList(head);

			}
			else
			{
				printf("û���������");
			}
			break;

		case 14:
			if (flag)
			{
				DestroyList(&head);
			}
		default:
		{
			printf("��������������1-14");
		}
		}
		

	}while (num != 14);

	return 0;

}