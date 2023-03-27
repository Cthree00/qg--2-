#include<stdio.h>
#include"Queue.h"

int Init(LinkQueue* Q)
{
	Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
	
	if (Q->front==NULL)
		return 0;

	if(Q->front!=NULL)
	   Q->front->next = NULL;
}

int Destroy(LinkQueue* Q)
{
	while ((*Q).front) {
		(*Q).rear = (*Q).front->next;//rearָ����Ԫ���
		free((*Q).front);//�ͷ�ͷ���
		(*Q).front = (*Q).rear;//rear��front��ΪNULL
	}
}

int EnQueue(LinkQueue* Q, ElemType e)
{
	QNode * p = (QNode*)malloc(sizeof(QNode));//��������ռ�
	if (!p)return 0;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;//��P���ڶ�β
	Q->rear = p;
	return 1;
}

int DeQueue(LinkQueue* Q, ElemType* e)
{
	if (Q->front=Q->rear)return 0;//�ն�
	QNode * p;
	p = Q->front->next;//ָ����Ԫ���
	e = p->data;  //��¼���ӵ�Ԫ��
	Q->front->next = p->next;   //��ͷ��㸲��
	if (Q->rear == p)Q->rear = Q->front;//ֻ��һ���������ʱ��frontΪ�գ���front��rearָ��ͬ�����
	free(p);
	return 1;
}

int GetHead(LinkQueue Q, ElemType* e)
{
	if (Q.front == Q.rear)return 0;
	e = Q.front->next->data;
	return 1;
}
void show()
{
	
	printf(">>>1.��ʼ��          \n");
	printf(">>>2������           \n");
	printf(">>>3�����           \n");
	printf(">>>4������           \n");
	printf(">>>5�����ͷԪ��     \n");
	printf(">>>6����ӵĳ���     \n");
	printf(">>>7����ն�         \n");
	printf(">>>8����ת��         \n");
	printf(">>>9����ӡ��         \n");
}

int judge()  //��ֹ�û��������������ַ�
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

int LengthLQueue(LinkQueue* Q)
{
	
	int length = 0;
	QNode* p = Q->front;//ָ���ͷ���
	while (p != Q->rear)//��p��rearͬ���������
	{
		length++;
		p = p->next;
		
	}
	printf("���еĳ���Ϊ%d", length);

}

void ClearLQueue(LinkQueue* Q) {
	Q->rear = Q->front->next;//�뽫��βָ��ָ����Ԫ���
	while (Q->front->next) //��ʱֻʣͷ���
	{
		Q->rear = Q->rear->next;
		free(Q->front->next);//�ͷ���Ԫ���
		Q->front->next = Q->rear;//���Ӷ���
	}
	Q->rear = Q->front;
	printf("��ճɹ�");
}

Status TraverseLQueue(const LinkQueue* Q, void (*foo)(int q))
{
	QNode* p = Q->front;
	while (p != Q->rear)
	{
		
		p = p->next;
		
		(* foo)(p->data);
		
	}
}

void LPrint(int q)
{
	printf("%d/n",q);
}



