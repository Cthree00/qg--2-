#include<stdio.h>
#include"sort.h"
#include<stdlib.h>
#include<assert.h>


void insertSort(int* a, int n)
{
	int i, j, temp;
	for (i = 1;i < n; ++i)//从大到小
	{
		if (a[i] < a[i - 1])
		{
			temp = a[i];
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}

	}
	for (i = 0; i <n ; ++i)
		printf("%d ", a[i]);
}


int Partition(int* a, int left, int right)
{
	
		int key = left;//取最左边的元素做key
		int t = 0;
		while (left < right)//当左右没有相遇
		{
			while (left < right && a[right] >= a[key])//如果右比key小就退出循环
				right--;
			while (left < right && a[left] <= a[key])//如果左比key大就退出循环
				left++;
			t=a[right];//交换左右
			a[right] = a[left];
			a[left] = t;
		}
		//交换key和相遇位置的元素
		t = a[left];
		a[left] = a[key];
		a[key] = t;
		return left;//返回key的位置
}


void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin < end) //序列长度大于1
	{
		int pivotloc = Partition(a, begin, end);//返回枢轴的位置
		QuickSort_Recursion(a, begin, pivotloc - 1);// 对左边的子表排序
		QuickSort_Recursion(a, pivotloc + 1, end);// 对右边的子表排序

	}


}
//交换函数
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}




//初始化
void StackInit(ST* ps)
{
	ps->a = (STDateType*)malloc(sizeof(STDateType) * 4);
	ps->top = 0;
	ps->capacity = 4;
}

//销毁栈
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//入栈
void StackPush(ST* ps, STDateType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDateType* tmp = (STDateType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDateType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}


//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//获取栈顶元素
STDateType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//获取栈元素个数
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//判断栈是否为空
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}


//快排非递归
void QuickSort(int* arr, int n)
{
	ST st;
	StackInit(&st);

	//把左右区间压栈，先压右边
	StackPush(&st, n - 1);
	//后压左边
	StackPush(&st, 0);

	//只要栈不为空，就继续分割排序
	while (!StackEmpty(&st))
	{
		//从栈里面取出左右区间
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int index = GetMidIndex(arr, left, right);
		//因为我们下面的逻辑都是把第一个数作为key，
		//为了避免改动代码，这里我们直接交换就可以
		swap(&arr[left], &arr[index]);

		//开始单趟排序
		int begin = left;
		int end = right;
		int pivot = begin;
		int key = arr[begin];

		while (begin < end)
		{
			//end开始找小
			while (begin < end && arr[end] >= key)
			{
				end--;
			}
			arr[pivot] = arr[end];
			pivot = end;
			//begin开始找大
			while (begin < end && arr[begin] <= key)
			{
				begin++;
			}
			arr[pivot] = arr[begin];
			pivot = begin;
		}
		pivot = begin;
		arr[pivot] = key;

		//区间分为[left,pivot-1]pivot[pivot+1,right]
		//利用循环继续分割区间
		//先入右子区间
		if (pivot + 1 < right)
		{
			//说明右子区间不止一个数
			//先入右边边界
			StackPush(&st, right);
			//再入左边边界
			StackPush(&st, pivot + 1);
		}

		//再入左子区间
		if (left < pivot - 1)
		{
			//说明左子区间不止一个数
			//先入右边边界
			StackPush(&st, pivot - 1);
			//再入左边边界
			StackPush(&st, left);
		}
	}
	StackDestory(&st);
}





void randomizedQuickSort(int *a, int left, int right) {
	if (left < right) {
		srand((time(0)));
		int randNum = rand() % (right - left + 1) + left;
		swap(&a[left], &a[randNum]);
		int pivot = Partition(a, left, right);
		randomizedQuickSort(a, left, pivot - 1);
		randomizedQuickSort(a, pivot + 1, right);
	}
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int i = begin;
	int j = mid + 1;
	int m = mid, n = end;
	int k = 0;
	while(i<=mid&&j<=end)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k ++] = a[j++];
		}
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= n)
		temp[k++] = a[j++];
	for (i = 0; i <k; i++)
	{
		a[begin+i] = temp[i];
	}
	
}
void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin >= end)return;
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid+1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}

void CountSort(int* a, int size, int max, int min)//计数排序优化
{
	int range = max - min + 1;
	int i, j=0;

	int* temp2 = (int*)malloc(sizeof(int) * range);
	memset(temp2, 0, sizeof(int) * range);
	for (i = 0; i < size; i++)
	{
		temp2[a[i]-min]++;
	}
	for (i = 0; i < range;i++)
	{
		while (temp2[i])
		{
			a[j++] = i+min;
			temp2[i]--;
		}
	}
	free(temp2);
	print(a, size);
}
void RadixCountSort(int* a, int size)
{
	int max = a[0];
	int i,j,k;
	int radix = 1;
	int bucket[10];
	int* temp = (int*)malloc(sizeof(int) * size);//用于存放中间排序过程的数组
	for (i = 1; i < size; i++)//求数组最大值
	{
		if (a[i] > max)
			max = a[i];
	}
	int digit = 1;//最大数的位数
	while (max>=10)
	{
		max /= 10;
		digit++;
	}
	for (i = 1; i <= digit; i++)//执行d次排序
	{
		for (j = 0; j < 10; j++)//每次统计前将桶初始化为0
		{
			bucket[j] = 0;
		}
		for (j = 0; j < size; j++)//统计每个桶的元素个数
		{
			k = (a[j] / radix) % 10;
			bucket[k]++;
		}
		for (j = 1; j < 10; j++)//更新buket的值，建立与temp的映射关系
		{
			bucket[j] += bucket[j - 1];

		}
		for (j = size - 1; j >= 0; j--)//从后往前取数组a,保证按顺序排列
		{
			k = (a[j] / radix) % 10;
			temp[bucket[k] - 1] = a[j];
			bucket[k]--;
		}
		for (j = 0; j < size; j++)//将临时数组copy到数组a
			a[j] = temp[j];
		radix *= 10;//进行下一位的排序
	}
	print(a, size);

}
void ColorSort(int* a, int size)
{
	int p0 = 0; //头索引
	int p2 = size - 1;//尾索引
	int index = 0;
	while (index <= p2)//循环结束条件为遍历索引大于p2
	{
		if (a[index] == 0)//交换p0与index索引上的值
		{
			a[index] = a[p0];
			a[p0++] = 0;
		}
		if (a[index] == 2)
		{
			a[index] = a[p2];
			a[p2--] = 2;
			continue;//此时不需要遍历索引不需要+1,还要比较该位置与p0
		}
		index++;
	}
	print(a, size);
}

int Swap(int arr[], int left, int right) {//将比基准数大的数放前面，将比基准数小的数放后面
	int temp = arr[left];
	while (left < right) {
		while (temp >= arr[right] && left < right) {
			right--;
		}
		arr[left] = arr[right];
		while (temp <= arr[left] && left < right) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[right] = temp;//基准数放中间
	return right;
}

int Findklargest(int *a, int left, int right, int k) {
	int temp = Swap(a, left, right);//返回的是比基数大的数组的大小
	if (temp >= k)
		return Findklargest(a, left, temp - 1, k);//第k个值在大数数组这边
	else if (temp < k - 1)
		return Findklargest(a, temp + 1, right, k);//第k个数在小数数组这边，还是求第k个数的大小
	else
		return a[temp];
	return -1;
}





int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	int pivotloc = 0;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			pivotloc = mid;
		}
		else if (a[left] > a[right])
		{
			pivotloc = left;
		}
		else
		{
			pivotloc = right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			pivotloc = mid;
		}
		else if (a[left] < a[right])
		{
			pivotloc = left;
		}
		else
		{
			pivotloc = right;
		}
	}
	QuickSort_Recursion(a, left, pivotloc - 1);// 对左边的子表排序
	QuickSort_Recursion(a, pivotloc + 1, right);// 对右边的子表排序
	print(a, right + 1);
	return pivotloc;
}

void show()
{
	printf(">>>输出排序所用时间  \n");
	printf(">>>1、插入排序       \n");
	printf(">>>2、归并排序       \n");
	printf(">>>3、快速排序（递归）\n");
	printf(">>>4、快速排序（非递归）\n");
	printf(">>>5、快速排序（随机）\n");
	printf(">>>6、快排（三数取中 ）\n");
	printf(">>>7、计数排序        \n");
	printf(">>>8、基数排序       \n");
	printf(">>>9、颜色排序       \n");
	printf(">>>10、找到第K大     \n");
	printf(">>>11、退出          \n");

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
void print(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}