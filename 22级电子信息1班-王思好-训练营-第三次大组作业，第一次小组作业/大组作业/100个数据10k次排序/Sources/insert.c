#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//插入排序
void InsertSort(int arr[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];

			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

//插入排序
void insert()
{
	int random_nums[NUM];
	
	clock_t total_time = 0; // 总时间

	for (int k = 0; k < 10000; k++) // 运行 100k 次
	{
		clock_t start = clock();
		savefile();
		loadfile(random_nums);

		InsertSort(random_nums, NUM);

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