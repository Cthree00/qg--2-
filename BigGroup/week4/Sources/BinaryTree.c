#include<stdio.h>
#include<assert.h>
#include"BinaryTree.h"


void Create(NodePtr root, int str[], int n) {
	root = NULL;
	for (int i = 0; i < n; i++) {
		root = BST_insert(root, str[i]);
	}
}

Status BST_insert(NodePtr T, ElemType e)
{
	NodePtr parent=NULL;   //��ʾ˫�׽�㣻
	NodePtr head = T;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->value = e;   //���������ݣ�
	p->left = p->right = NULL;  //���������ÿգ�


	while (head)
	{
		parent = head;
		if (e < head->value)
			head = head->left; //���������ϲ��ң� 
		else
			head = head->right;  //���������ϲ��ң�
	}
	//�ж���ӵ�������������������
	if (e < parent->value)   //С�ڸ���㣻
		parent->left = p;    //��ӵ���������
	else
		parent->right = p;   //��ӵ�������
}
Status BST_search(NodePtr T, ElemType x)
{
	if (T->value == x) {
		return T;
	}
	else if (x < T->value) {
		return BST_search(T->left, x);
	}
	else {
		return BST_search(T->right, x);
	}
}

Heap* HeapCreate()
{
	Heap* tmp = (Heap*)malloc(sizeof(Heap));
	if (tmp == NULL)
	{
		printf("HeapCreate error\n");
		return NULL;
	}
	tmp->_a = NULL;
	tmp->_size = tmp->_capacity = 0;
	return tmp;
}

//���ϵ����㷨
void AdjustUp(HPDataType* a, size_t child)
{
	assert(a); //���Է�ֹ����ָ��Ϊ��
	while (child != 0)
	{
		size_t parent = (child - 1) / 2;
		if (a[child] < a[parent])
		{

			int temp;
			temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
		}
		else
		{
			break;
		}

		child = parent;
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_capacity <= hp->_size)
	{
		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc error\n");
			return;
		}
		hp->_a = tmp;
		hp->_capacity = newCapacity;
	}

	hp->_a[hp->_size] = x;
	AdjustUp(hp->_a, hp->_size); //���ϵ����㷨
	hp->_size++;
}


void AdjustDown(HPDataType* a, size_t size)
{
	assert(a);
	size_t parent = 0;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		//�ֵܱȽϴ�С��ȡСΪchild
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child = child + 1;
		}

		//���ӱȽϣ������Ƿ񽻻�
		if (a[parent] > a[child])
		{
			int temp;
			temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
			
		}
		else
		{
			break;
		}

		parent = child;
		child = parent * 2 + 1;
	}

}
void Swap(int* p1, int* p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HeapPop(Heap* hp)
{
	
	assert(hp);
	
	assert(hp->_size > 0);
	
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	
	hp->_size--;
	
	AdjustDown(hp->_a, hp->_size);

}


Status BST_preorderR(NodePtr T, void (*visit)(NodePtr e)) 
{
	if (T == NULL)return true;
	else
	{
		visit(T);
		BST_preorderR(T->left, visit);
		BST_preorderR(T->right, visit);
	}


}

Status BST_inorderR(NodePtr T, void (*visit)(NodePtr e))
{
	if (T == NULL)return true;
	else {
		BST_inorderR(T->left, visit);
		visit(T);
		BST_inorderR(T->right, visit);
	}
}

Status BST_postorderR(NodePtr T, void (*visit)(NodePtr))
{
	if (T == NULL)return true;
	else {
		BST_postorderR(T->left,visit);
		BST_postorderR(T->right, visit);
		visit(T);
	}
}
//�������������
Status BST_preorderI(NodePtr T, void (*visit)(NodePtr))

{
	SqStack S;
	InitStack(&S);
	NodePtr p;
	p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			visit(p);
			push(&S, p);
			p = p->left;
		}
		else
		{
			pop(&S, p);
			p = p->right;
		}
	}
}


Status BST_inorderI(NodePtr T, void (*visit)(NodePtr))
{
	NodePtr p=T,q=NULL;
	SqStack S;
	InitStack(&S);
	ElemType e;
	while ( p|| !StackEmpty(S))
	{
		if (p) {
			push(&S, p);
			p = p->left;
		}
		else {
			pop(&S, q);
			visit(q);
			p = q->right;
		}
	}
	return true;

}
Status BST_postorderI(NodePtr T, void (*visit)(NodePtr))
{

	NodePtr p = T;
	NodePtr stack[MAXSIZE];
	int num = 0;
	NodePtr visited = NULL;

	while (NULL != p || num > 0)
	{
		while (NULL != p)
		{
			stack[num++] = p;
			p = p->left;
		}
		p = stack[num - 1];
		if (NULL == p->right || visited == p->right)
		{
			visit(p);
			num--;
			visited = p;
			p = NULL;
		}
		else
		{
			p = p->right;
		}
	}

}

Status InitStack(SqStack* S)
{
	S->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!S->base)exit(-1);//�洢����ʧ��
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return true;
}

Status StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return true;
	else
		return false;
}
Status push(SqStack* S, NodePtr p)
{
	if (S->top - S->top == S->stacksize)
		return failed;
	(S->top) = p;
	S->top++;
	return true;
}

Status pop(SqStack* S,NodePtr  q)
{
	ElemType e;
	if (S->base == S->top)
		return false;
	q = --(S->top);
	return true;
}

Status BST_init(NodePtr T)
{
	int i=0;
	printf("�����������˳�������ַ�����������#");
	scanf_s("%d" ,&i);
	if (i == "#") 
		T = NULL;
	else {
		if(!(T = (NodePtr)malloc(sizeof(Node))))return false;
		if (T != NULL)
		{
			T->value = i;
			BST_init(T->left);
			BST_init(T->right);
		}
	}
	return true;
}


Status InitQueue(SqQueue* Q)
{
	Q->front = Q->rear = -1;
}

//�ж϶���Ϊ��

int QueueEmpty(SqQueue* q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	return 0;
}

Status EnQueue(SqQueue* Q, NodePtr T)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) return false;//����
	Q->data[Q->rear] = *T;//�����ڵ�����β
	Q->rear = (Q->rear + 1) % MAXSIZE; //��βָ���1
	return true;
}

Status DeQueue(SqQueue* Q, NodePtr P)
{
	if (Q->front == Q->rear)return false;//�ӿ�
	*P = Q->data[Q->front]; //����ͷԪ�ش���p
	Q->front = (Q->front + 1) % MAXSIZE;//��ͷָ��+1
	return true;

}

Status BST_levelOrder(NodePtr T, void (*visit)(NodePtr))
{
	NodePtr p=NULL;
	SqQueue* q=NULL;
	InitQueue(q);
	EnQueue(q, T); //���ڵ�ָ��������
	while (!QueueEmpty(q)) //���в�Ϊ�������ѭ��
	{
		DeQueue(q, p);   //���ӽ��p
		visit(p);     
		if (p->left != NULL)
			EnQueue(q, p->left);
		if (p->right != NULL)
			EnQueue(q, p->right);

	}
	
}



Status BST_delete(NodePtr T, ElemType e)
{
	NodePtr L, LL;    
	NodePtr p= T;
	NodePtr parent = T;
	int child = 0;  //0��ʾ��������1��ʾ��������
	if (!T)    //���������Ϊ�գ����˳���
		return;
	while (p)  //������������Ч��
	{
		if (p->value == e)
		{
			if (!p->left && !p->right)  //Ҷ���(����������Ϊ��)��
			{
				if (p == T)  
					free(p);
				else if (child == 0)
				{
					parent->left = NULL;  //���ø����������Ϊ�գ�
					free(p);   
				}
				else   
				{
					parent->right = NULL;  
					free(p); 
				}
			}

			else if (!p->left)
			{
				if (child == 0)    //�Ǹ�������������
					parent->left = p->right;
				else    
					parent->right = p->right;
				free(p); 
			}

			else if (!p->right)
			{
				if (child == 0)
					parent->left = p->left;
				else
					parent->right = p->left;
				free(p);
			}

			else
			{
				LL = p;  
				L = p->right;  //�ӵ�ǰ�������������в��ң�
				if (L->left)  //��������Ϊ�գ�
				{
					LL = L;
					L = L->left;   //������������
					p->value = L->value; 
					LL->left = L->left;  
					for (; L->left; L = L->left);
					L->left = p->left;
					p->left = NULL;
				}
				else
				{
					p->value = L->value;
					LL->right = L->right;
				}
			}
			p = NULL;
		}

		else if (e < p->value)  //��ɾ����¼�Ĺؼ���С�ڽ������ݣ�
		{
			//Ҫɾ���Ľ��p��parent����������
			child = 0; 
			parent = p;
			p = p->left; 
		}

		else  //��ɾ����¼�Ĺؼ��ִ��ڽ������ݣ�
		{
			
			child = 1;  
			parent = p;  //���浱ǰ�����Ϊ����㣻
			p = p->right;  //������������
		}
	}
}







void Visit(NodePtr p)
{
	printf("%c", p->value);
}





void show()
{
	printf(">>>1.��ʼ��          \n");
	printf(">>>2������           \n");
	printf(">>>3��ɾ��          \n");
	printf(">>>4������           \n");
	printf(">>>5����������ݹ�        \n");
	printf(">>>6����������ݹ�           \n");
	printf(">>>7����������ݹ�      \n");
	printf(">>>8����������ǵݹ� \n");
	printf(">>>9����������ǵݹ� \n");
	printf(">>>10����������ǵݹ�  \n");
	printf(">>>11���������  \n");
	printf(">>>12���ѵĳ�ʼ��      \n");
	printf(">>>13���ѵ�����     \n");
	printf(">>>14���ѵĲ���        \n");
	printf(">>>15���˳�      \n");



	printf("���������ѡ��");
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
