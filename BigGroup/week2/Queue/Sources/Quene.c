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
		(*Q).rear = (*Q).front->next;//rear指向首元结点
		free((*Q).front);//释放头结点
		(*Q).front = (*Q).rear;//rear和front都为NULL
	}
}

int EnQueue(LinkQueue* Q, ElemType e)
{
	QNode * p = (QNode*)malloc(sizeof(QNode));//给结点分配空间
	if (!p)return 0;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;//将P接在队尾
	Q->rear = p;
	return 1;
}

int DeQueue(LinkQueue* Q, ElemType* e)
{
	if (Q->front=Q->rear)return 0;//空队
	QNode * p;
	p = Q->front->next;//指向首元结点
	e = p->data;  //记录出队的元素
	Q->front->next = p->next;   //将头结点覆盖
	if (Q->rear == p)Q->rear = Q->front;//只有一个结点有数时，front为空，将front与rear指向同个结点
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
	
	printf(">>>1.初始化          \n");
	printf(">>>2、销毁           \n");
	printf(">>>3、入队           \n");
	printf(">>>4、出队           \n");
	printf(">>>5、求队头元素     \n");
	printf(">>>6、求队的长度     \n");
	printf(">>>7、清空队         \n");
	printf(">>>8、反转队         \n");
	printf(">>>9、打印队         \n");
}

int judge()  //防止用户乱输入其他的字符
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
			if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
			{
				printf("请输入整数：");
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
	for (m = 0; m < len; m++)  // 将字符重新转换为数字
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
	QNode* p = Q->front;//指向队头结点
	while (p != Q->rear)//当p与rear同，遍历完成
	{
		length++;
		p = p->next;
		
	}
	printf("队列的长度为%d", length);

}

void ClearLQueue(LinkQueue* Q) {
	Q->rear = Q->front->next;//想将队尾指针指向首元结点
	while (Q->front->next) //此时只剩头结点
	{
		Q->rear = Q->rear->next;
		free(Q->front->next);//释放首元结点
		Q->front->next = Q->rear;//连接队列
	}
	Q->rear = Q->front;
	printf("清空成功");
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



