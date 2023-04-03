#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//交换
void swap(int k[], int low, int high)
{
	int temp;
	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

//遍历
int partition(int k[], int low, int high)
{
	int point = k[low];

	while (low < high)
	{
		while (low < high && k[high] >= point)
			high--;
		swap(k, low, high);
		while (low < high && k[low] <= point)
			low++;
		swap(k, low, high);
	}
	return low;
}

//快速排序
void QuickSort(int k[], int low, int high)
{


	if (low < high)
	{
		int point = partition(k, low, high);
		QuickSort(k, low, point - 1);
		QuickSort(k, point + 1, high);
	}
}

//快速排序
void quick()
{
	int random_nums[NUM];
	
	clock_t total_time = 0; // 总时间

	for (int k = 0; k < 10000; k++) // 运行 100k 次
	{
		clock_t start = clock();
		savefile();
		loadfile(random_nums);

		QuickSort(random_nums, 0, NUM - 1);

		clock_t end = clock();
		total_time += end - start; // 累加本次排序所花费的时间
	}

	for (int i = 0; i < NUM; i++)
	{
		printf("%d ", random_nums[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("\n");

	printf("共用时%d ms\n", total_time);
	return 0;
}

