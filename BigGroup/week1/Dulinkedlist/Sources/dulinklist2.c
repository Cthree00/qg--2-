#include<stdio.h>
#include<stdlib.h>
#include "dulinklist.h"
Status InitList_DuL(DuLinkedList* L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if (List == NULL)
    {
        printf("�ڴ����ʧ��\n");
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
Status ListInsert(DulNode * l, int i, ElemType e)
{
    DulNode* p = l;
    DulNode* s = (DulNode*)malloc(sizeof(DulNode));
    int j = 0;
    while (p && j < i - 1) //Ѱ�ҵ�i-1����㣬��pָ����
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)return error;   //i���ڱ�+1������С��1������λ�÷Ƿ�
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

Status InsertBeforeList_DuL(DulNode* p, DuLNode* q) {
    if (p->next == NULL)//������Ϊ��ʱ��ֱ������p��q
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
        printf("����Ϊ�գ��޷�ɾ��\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        //�ҵ�ɾ������λ��
        while (posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("�Ҳ���������\n");
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
void LocateElem(DulNode* p, ElemType a)
{
    p = p->next;
    int j = 1;
    while (p && p->data != a)
    {
        p = p->next;
        j++;
    }
    if (p)
        printf("��ֵ��%dλ����", j);
    else
        printf("��ֵ������");
}
void GetElem(DulNode* p, int i)
{
    p = p->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next; ++j;
    }
    if (!p || j > i)return error;
    printf("��%d��Ԫ����%d", i, p->data);
}
void TraverseList_DuL(DuLinkedList L) {
    if (L == NULL)
    {
        printf("����δ���������ȴ�������\n");
    }
    else if (L->next == NULL)
    {
        printf("��ǰ����Ϊ��\n");
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
    printf("\n\n\n\n˫����ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.ͷ�巨��������\n");
    printf("4.β�巨��������\n");
    printf("5.ɾ������\n");
    printf("6.��������\n");
    printf("7.������\n");
    printf("8.��ֵ����\n");
    printf("9.��λ����\n");
    printf("10.�˳�\n");
    printf("\n�������Ӧ������(1-7)��");
}
int judge() //��������Ƿ�Ϸ�
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        gets_s(word, 10);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // ���ַ�����ת��Ϊ����
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}
