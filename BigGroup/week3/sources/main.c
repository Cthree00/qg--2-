#include<stdio.h>
#include"sort.h"
#include<stdlib.h>
#include <time.h>



int GetLargeData(int**a)//生成大数据量的数组（1000，5000，20000）
{
    int lower, upper, count;

    srand(time(0));
    printf("请输入数的范围和个数");
    scanf_s("%d,%d,%d", &lower, &upper, &count);
    *a = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        a[i] = (rand() % (upper - lower + 1)) + lower;
    }
	return count;

}
int GetSmallData(int** a)//生成大量小数据量的数组，例如10000个小于100的数
{
    int lower, upper, count;

    srand(time(0));
    printf("请输入数的范围和个数");
    scanf_s("%d,%d,%d", &lower, &upper, &count);
    *a = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        a[i] = (rand() % (upper - lower + 1)) + lower;
    }
	return count;
}

int main()
{
	
	int flag = 1;
	int size = 0;//记录数组元素个数
	
	int num = 0;
	int* temp ;
	int* a;
	int begintime, endtime;
	int i = 0;
	int lower, upper, count;
	int begin = 0, end;
	begintime = clock();
	do
    {
    
		
		printf("输入1选择创建大数据量数组，输入0选择创建小数据量数组");
		scanf_s("%d", &flag);

		if (flag)
		{
			begintime = clock();
			srand(time(0));
			printf("请输入数的范围和个数");
			scanf_s("%d%d%d", &lower, &upper, &count);
			a = (int*)malloc(sizeof(int) * (count+1));
			printf("%d", count);
			for (int i = 0; i < count; i++) {
				a[i] = (rand() % (upper - lower + 1)) + lower;
			}
			size=count;
			endtime = clock();	//计时结束
			printf("Running Time：%dms\n", endtime - begintime);

		}
		else
		{
			begintime = clock();
			srand(time(0));
			printf("请输入数的范围和个数");
			scanf_s("%d%d%d", &lower, &upper, &count);
			a = (int*)malloc(sizeof(int) * (count+1));

			for (int i = 0; i < count; i++) {
				a[i] = (rand() % (upper - lower + 1)) + lower;
			}
			size= count;
			endtime = clock();	//计时结束
			printf("Running Time：%dms\n", endtime - begintime);
		}
		print(a,size);
		end = size - 1;
     
		
			show();
			printf("请输入你的选项");
			num = judge();
			system("cls");
			switch (num)
			{
			case 1:
				begintime = clock();
				insertSort(a, size);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);

				break;
			case 2:
			{
				begintime = clock();
				temp = (int*)malloc(sizeof(int) * size);

				MergeSort(a, begin, end, temp);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);
				print(a, end + 1);

				break;
			}
			case 3:
				begintime = clock();
				QuickSort_Recursion(a, begin, end);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);

				print(a, end + 1);
				break;
			case 4:
				begintime = clock();
				QuickSort(a,size);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);

				print(a, end + 1);
				break;

			case 5:
				begintime = clock();
				randomizedQuickSort(a, begin, end);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);
				print(a, size);
				break;
			case 6:
				begintime = clock();
				GetMidIndex(a, begin, end);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);
			case 7:
			{
				int max = a[0];
				int min = a[0];

				for (int i = 0; i < size; i++)
				{
					if (a[i] > max)
					{
						max = a[i];
					}
					if (a[i] < min)
					{
						min = a[i];
					}
				}
				
				begintime = clock();
				CountSort(a, size, max, min);
				
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);
				break;
			}
			case 8:
				begintime = clock();
				RadixCountSort(a, size);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);
				break;
			case 9:
				begintime = clock();
				ColorSort(a, size);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);
				break;
			case 10:
			{
				int k = 0;
				printf("请输入要找第k大的数");
				scanf_s("%d", &k);
				begintime = clock();
				k = Findklargest(a, begin,end, k);
				endtime = clock();	//计时结束
				printf("Running Time：%dms\n", endtime - begintime);
				printf("%d为第k小的数", k);
				break;
			}

			default:
			{
				printf("请重新输入数字1-11");
			}
			}
		


	} while (num!= 11);
        
    

}
