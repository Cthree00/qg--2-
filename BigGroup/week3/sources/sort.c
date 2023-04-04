#include<stdio.h>
#include"sort.h"
#include<stdlib.h>
#include<assert.h>


void insertSort(int* a, int n)
{
	int i, j, temp;
	for (i = 1;i < n; ++i)//�Ӵ�С
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
	
		int key = left;//ȡ����ߵ�Ԫ����key
		int t = 0;
		while (left < right)//������û������
		{
			while (left < right && a[right] >= a[key])//����ұ�keyС���˳�ѭ��
				right--;
			while (left < right && a[left] <= a[key])//������key����˳�ѭ��
				left++;
			t=a[right];//��������
			a[right] = a[left];
			a[left] = t;
		}
		//����key������λ�õ�Ԫ��
		t = a[left];
		a[left] = a[key];
		a[key] = t;
		return left;//����key��λ��
}


void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin < end) //���г��ȴ���1
	{
		int pivotloc = Partition(a, begin, end);//���������λ��
		QuickSort_Recursion(a, begin, pivotloc - 1);// ����ߵ��ӱ�����
		QuickSort_Recursion(a, pivotloc + 1, end);// ���ұߵ��ӱ�����

	}


}
//��������
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}




//��ʼ��
void StackInit(ST* ps)
{
	ps->a = (STDateType*)malloc(sizeof(STDateType) * 4);
	ps->top = 0;
	ps->capacity = 4;
}

//����ջ
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//��ջ
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


//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//��ȡջ��Ԫ��
STDateType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//��ȡջԪ�ظ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}


//���ŷǵݹ�
void QuickSort(int* arr, int n)
{
	ST st;
	StackInit(&st);

	//����������ѹջ����ѹ�ұ�
	StackPush(&st, n - 1);
	//��ѹ���
	StackPush(&st, 0);

	//ֻҪջ��Ϊ�գ��ͼ����ָ�����
	while (!StackEmpty(&st))
	{
		//��ջ����ȡ����������
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int index = GetMidIndex(arr, left, right);
		//��Ϊ����������߼����ǰѵ�һ������Ϊkey��
		//Ϊ�˱���Ķ����룬��������ֱ�ӽ����Ϳ���
		swap(&arr[left], &arr[index]);

		//��ʼ��������
		int begin = left;
		int end = right;
		int pivot = begin;
		int key = arr[begin];

		while (begin < end)
		{
			//end��ʼ��С
			while (begin < end && arr[end] >= key)
			{
				end--;
			}
			arr[pivot] = arr[end];
			pivot = end;
			//begin��ʼ�Ҵ�
			while (begin < end && arr[begin] <= key)
			{
				begin++;
			}
			arr[pivot] = arr[begin];
			pivot = begin;
		}
		pivot = begin;
		arr[pivot] = key;

		//�����Ϊ[left,pivot-1]pivot[pivot+1,right]
		//����ѭ�������ָ�����
		//������������
		if (pivot + 1 < right)
		{
			//˵���������䲻ֹһ����
			//�����ұ߽߱�
			StackPush(&st, right);
			//������߽߱�
			StackPush(&st, pivot + 1);
		}

		//������������
		if (left < pivot - 1)
		{
			//˵���������䲻ֹһ����
			//�����ұ߽߱�
			StackPush(&st, pivot - 1);
			//������߽߱�
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

void CountSort(int* a, int size, int max, int min)//���������Ż�
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
	int* temp = (int*)malloc(sizeof(int) * size);//���ڴ���м�������̵�����
	for (i = 1; i < size; i++)//���������ֵ
	{
		if (a[i] > max)
			max = a[i];
	}
	int digit = 1;//�������λ��
	while (max>=10)
	{
		max /= 10;
		digit++;
	}
	for (i = 1; i <= digit; i++)//ִ��d������
	{
		for (j = 0; j < 10; j++)//ÿ��ͳ��ǰ��Ͱ��ʼ��Ϊ0
		{
			bucket[j] = 0;
		}
		for (j = 0; j < size; j++)//ͳ��ÿ��Ͱ��Ԫ�ظ���
		{
			k = (a[j] / radix) % 10;
			bucket[k]++;
		}
		for (j = 1; j < 10; j++)//����buket��ֵ��������temp��ӳ���ϵ
		{
			bucket[j] += bucket[j - 1];

		}
		for (j = size - 1; j >= 0; j--)//�Ӻ���ǰȡ����a,��֤��˳������
		{
			k = (a[j] / radix) % 10;
			temp[bucket[k] - 1] = a[j];
			bucket[k]--;
		}
		for (j = 0; j < size; j++)//����ʱ����copy������a
			a[j] = temp[j];
		radix *= 10;//������һλ������
	}
	print(a, size);

}
void ColorSort(int* a, int size)
{
	int p0 = 0; //ͷ����
	int p2 = size - 1;//β����
	int index = 0;
	while (index <= p2)//ѭ����������Ϊ������������p2
	{
		if (a[index] == 0)//����p0��index�����ϵ�ֵ
		{
			a[index] = a[p0];
			a[p0++] = 0;
		}
		if (a[index] == 2)
		{
			a[index] = a[p2];
			a[p2--] = 2;
			continue;//��ʱ����Ҫ������������Ҫ+1,��Ҫ�Ƚϸ�λ����p0
		}
		index++;
	}
	print(a, size);
}

int Swap(int arr[], int left, int right) {//���Ȼ�׼���������ǰ�棬���Ȼ�׼��С�����ź���
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
	arr[right] = temp;//��׼�����м�
	return right;
}

int Findklargest(int *a, int left, int right, int k) {
	int temp = Swap(a, left, right);//���ص��ǱȻ����������Ĵ�С
	if (temp >= k)
		return Findklargest(a, left, temp - 1, k);//��k��ֵ�ڴ����������
	else if (temp < k - 1)
		return Findklargest(a, temp + 1, right, k);//��k������С��������ߣ��������k�����Ĵ�С
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
	QuickSort_Recursion(a, left, pivotloc - 1);// ����ߵ��ӱ�����
	QuickSort_Recursion(a, pivotloc + 1, right);// ���ұߵ��ӱ�����
	print(a, right + 1);
	return pivotloc;
}

void show()
{
	printf(">>>�����������ʱ��  \n");
	printf(">>>1����������       \n");
	printf(">>>2���鲢����       \n");
	printf(">>>3���������򣨵ݹ飩\n");
	printf(">>>4���������򣨷ǵݹ飩\n");
	printf(">>>5���������������\n");
	printf(">>>6�����ţ�����ȡ�� ��\n");
	printf(">>>7����������        \n");
	printf(">>>8����������       \n");
	printf(">>>9����ɫ����       \n");
	printf(">>>10���ҵ���K��     \n");
	printf(">>>11���˳�          \n");

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
void print(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}