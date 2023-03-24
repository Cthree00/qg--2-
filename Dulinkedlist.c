#include<stdio.h>
#include<stdlib.h>
#include "Dulinkedlist.h"
Status InitList_DuL(DuLinkedList* L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if (List == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    List->next = NULL;
    List->prior = NULL;
    *L = List;
    return success;
}

void DestroyList_DuL(DuLinkedList* L) {
    DuLinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
Status ListInsert(DuLNode* l, int i, ElemType e)
{
    DuLNode* p = l;
    DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
    int j = 0;
    while (p && j < i - 1) //寻找第i-1个结点，让p指向它
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)return error;   //i大于表长+1，或者小于1，插入位置非法
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
    if (p->next == NULL)//当链表为空时，直接连接p、q
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
        return success;
    }
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e) {
    if (p->next == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        //找到删除结点的位置
        while (posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("找不到该数据\n");
                return error;
            }
        }
        if (posNode->next != NULL)
        {
            posNodeFront->next = posNode->next;
            posNode->next->prior = posNodeFront;
        }
        else
        {
            posNodeFront->next = NULL;
        }
        free(posNode);
        return success;
    }
}
void LocateElem(DuLNode* p, ElemType a)
{
    p = p->next;
    int j = 1;
    while (p && p->data != a)
    {
        p = p->next;
        j++;
    }
    if (p)
        printf("该值在%d位置上", j);
    else
        printf("该值不存在");
}
void GetElem(DuLNode* p, int i)
{
    if(p!=NULL) 
       p = p->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next; ++j;
    }
    if (!p || j > i)return error;
    printf("第%d个元素是%d", i, p->data);
}
void TraverseList_DuL(DuLinkedList L) {
    if (L == NULL)
    {
        printf("链表未创建，请先创建链表\n");
    }
    else if (L->next == NULL)
    {
        printf("当前链表为空\n");
    }
    else
    {
        DuLinkedList temp = L->next;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void show(void)
{
    printf("\n\n\n\n双链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.头插法插入数据\n");
    printf("4.尾插法插入数据\n");
    printf("5.删除数据\n");
    printf("6.遍历链表\n");
    printf("7.插入结点\n");
    printf("8.按值查找\n");
    printf("9.按位查找\n");
    printf("10.退出\n");
    printf("\n请输入对应的数字(1-7)：");
}
