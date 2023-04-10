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
	NodePtr parent=NULL;   //表示双亲结点；
	NodePtr head = T;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->value = e;   //保存结点数据；
	p->left = p->right = NULL;  //左右子树置空；


	while (head)
	{
		parent = head;
		if (e < head->value)
			head = head->left; //在左子树上查找； 
		else
			head = head->right;  //在右子树上查找；
	}
	//判断添加到左子树还是右子树；
	if (e < parent->value)   //小于父结点；
		parent->left = p;    //添加到左子树；
	else
		parent->right = p;   //添加到右子树
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

//向上调整算法
void AdjustUp(HPDataType* a, size_t child)
{
	assert(a); //断言防止传入指针为空
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
	AdjustUp(hp->_a, hp->_size); //向上调整算法
	hp->_size++;
}


void AdjustDown(HPDataType* a, size_t size)
{
	assert(a);
	size_t parent = 0;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		//兄弟比较大小，取小为child
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child = child + 1;
		}

		//父子比较，决定是否交换
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
//先序遍历二叉树
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
	if (!S->base)exit(-1);//存储分配失败
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
	printf("请以先序遍历顺序输入字符，空则输入#");
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

//判断队列为空

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
	if ((Q->rear + 1) % MAXSIZE == Q->front) return false;//队满
	Q->data[Q->rear] = *T;//将根节点加入队尾
	Q->rear = (Q->rear + 1) % MAXSIZE; //队尾指针加1
	return true;
}

Status DeQueue(SqQueue* Q, NodePtr P)
{
	if (Q->front == Q->rear)return false;//队空
	*P = Q->data[Q->front]; //将队头元素存入p
	Q->front = (Q->front + 1) % MAXSIZE;//队头指针+1
	return true;

}

Status BST_levelOrder(NodePtr T, void (*visit)(NodePtr))
{
	NodePtr p=NULL;
	SqQueue* q=NULL;
	InitQueue(q);
	EnQueue(q, T); //根节点指针进入队列
	while (!QueueEmpty(q)) //队列不为空则进入循环
	{
		DeQueue(q, p);   //出队结点p
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
	int child = 0;  //0表示左子树，1表示右子树；
	if (!T)    //如果排序树为空，则退出；
		return;
	while (p)  //二叉排序树有效；
	{
		if (p->value == e)
		{
			if (!p->left && !p->right)  //叶结点(左右子树都为空)；
			{
				if (p == T)  
					free(p);
				else if (child == 0)
				{
					parent->left = NULL;  //设置父结点左子树为空；
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
				if (child == 0)    //是父结点的左子树；
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
				L = p->right;  //从当前结点的右子树进行查找；
				if (L->left)  //左子树不为空；
				{
					LL = L;
					L = L->left;   //查找左子树；
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

		else if (e < p->value)  //需删除记录的关键字小于结点的数据；
		{
			//要删除的结点p是parent的左子树；
			child = 0; 
			parent = p;
			p = p->left; 
		}

		else  //需删除记录的关键字大于结点的数据；
		{
			
			child = 1;  
			parent = p;  //保存当前结点作为父结点；
			p = p->right;  //查找右子树；
		}
	}
}







void Visit(NodePtr p)
{
	printf("%c", p->value);
}





void show()
{
	printf(">>>1.初始化          \n");
	printf(">>>2、查找           \n");
	printf(">>>3、删除          \n");
	printf(">>>4、插入           \n");
	printf(">>>5、先序遍历递归        \n");
	printf(">>>6、中序遍历递归           \n");
	printf(">>>7、后序遍历递归      \n");
	printf(">>>8、先序遍历非递归 \n");
	printf(">>>9、中序遍历非递归 \n");
	printf(">>>10、后序遍历非递归  \n");
	printf(">>>11、层序遍历  \n");
	printf(">>>12、堆的初始化      \n");
	printf(">>>13、堆的销毁     \n");
	printf(">>>14、堆的插入        \n");
	printf(">>>15、退出      \n");



	printf("请输入你的选项");
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
