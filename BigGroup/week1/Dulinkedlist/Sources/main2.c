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
        printf("请输入选项");
        scanf_s("%d", &choice);
        num = judge();
        system("cls");
        switch (num)
        {
        case 1://创建空链表
        {
            if (InitList_DuL(&head))
            {
                printf("空链表创建成功\n");
            }
            else
            {
                printf("空链表创建失败\n");
            }
            break;
        }
        case 2://销毁链表
        {
            DestroyList_DuL(&head);
            printf("链表销毁成功\n");
            break;
        }
        case 3://头插法插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("请输入数据：");
                    scanf_s("%d", &newNode->data);
                    if (InsertBeforeList_DuL(head, newNode))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 4://尾插法插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("请输入数据：");
                    scanf_s("%d", &newNode->data);
                    if (InsertAfterList_DuL(head, newNode))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        
        case 5://删除数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你想删除哪个数据：");
                scanf_s("%d", &num);
                if (DeleteList_DuL(head, &num))
                {
                    printf("数据删除成功\n");
                }
                else
                {
                    printf("数据删除失败\n");
                }
            }
            break;
        }
        case 6://遍历链表
        {
            TraverseList_DuL(head);
            break;
        }
        case 7://插入结点
        {
            int i = 0;
            ElemType e = 0;
            printf("请输入要插入的结点位置和数值");
            scanf_s("%d,%d", &i, &e);
            ListInsert(head,  i, ElemType e)
        }
        case 8://按值查找
        {
            ElemType a;
            printf("请输入要查找的值");
            scanf_s("%d", a);
            LocateElem(head, ElemType a);
        }
        case 9://按位查找
        {
            int i = 0;
            printf("请输入要查找的位置");
            scanf_s("%d", &i);
            GetElem(head,  i)
        }
        case 10://退出程序 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字!(1-7)\n");
            break;
        }
        }
    } while (choice != 7);

    return 0;
}