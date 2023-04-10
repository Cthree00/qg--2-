#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
#define MAXSIZE 100

typedef int ElemType;

typedef struct Node {
    ElemType value;
    struct Node* left, * right;
}Node, * NodePtr;

//定义顺序栈，用于非递归遍历
typedef struct {
    NodePtr base;//栈底指针
    NodePtr top;//栈顶指针
    int stacksize;//栈可用最大容量
} SqStack;

//定义队列，用于层次遍历
typedef struct {
    Node data[MAXSIZE];//存放队中元素
    int front, rear;//队头、队尾指针
}SqQueue;//循环顺序队列

//堆


typedef int HPDataType;
typedef struct Heap
{
    HPDataType* _a;
    int _size;
    int _capacity;
}Heap;

Status InitStack(SqStack* S);

Status StackEmpty(SqStack S);

Status push(SqStack* S, ElemType e);

Status pop(SqStack* S, ElemType e);

Status InitQueue(SqQueue* Q);

Status EnQueue(SqQueue* Q, NodePtr T);

Status DeQueue(SqQueue* Q, ElemType e);

Status QueueEmpty(SqQueue *q);

// 堆的构建

Heap* HeapCreate();
// 堆的销毁
void HeapDestroy(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);



/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(NodePtr T);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(NodePtr T, ElemType e);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(NodePtr T, ElemType e);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr T, ElemType e);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr T, void (*visit)(NodePtr));

void show();

int judge();

void Visit(NodePtr p);

#endif


