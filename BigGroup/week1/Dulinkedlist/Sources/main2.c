#include<stdio.h>
#include<stdlib.h>
#include "dulinklist.h"
int main()
{
    int choice, num = 0;
    DuLinkedList head;
    head = NULL;

    do
    {
        show();
        printf("������ѡ��");
        scanf_s("%d", &choice);
        num = judge();
        system("cls");
        switch (num)
        {
        case 1://����������
        {
            if (InitList_DuL(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        }
        case 2://��������
        {
            DestroyList_DuL(&head);
            printf("�������ٳɹ�\n");
            break;
        }
        case 3://ͷ�巨��������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("���������ݣ�");
                    scanf_s("%d", &newNode->data);
                    if (InsertBeforeList_DuL(head, newNode))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 4://β�巨��������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("���������ݣ�");
                    scanf_s("%d", &newNode->data);
                    if (InsertAfterList_DuL(head, newNode))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        
        case 5://ɾ������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                printf("����ɾ���ĸ����ݣ�");
                scanf_s("%d", &num);
                if (DeleteList_DuL(head, &num))
                {
                    printf("����ɾ���ɹ�\n");
                }
                else
                {
                    printf("����ɾ��ʧ��\n");
                }
            }
            break;
        }
        case 6://��������
        {
            TraverseList_DuL(head);
            break;
        }
        case 7://������
        {
            int i = 0;
            ElemType e = 0;
            printf("������Ҫ����Ľ��λ�ú���ֵ");
            scanf_s("%d,%d", &i, &e);
            ListInsert(head,  i, ElemType e)
        }
        case 8://��ֵ����
        {
            ElemType a;
            printf("������Ҫ���ҵ�ֵ");
            scanf_s("%d", a);
            LocateElem(head, ElemType a);
        }
        case 9://��λ����
        {
            int i = 0;
            printf("������Ҫ���ҵ�λ��");
            scanf_s("%d", &i);
            GetElem(head,  i)
        }
        case 10://�˳����� 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("��������������!(1-7)\n");
            break;
        }
        }
    } while (choice != 7);

    return 0;
}