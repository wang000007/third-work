#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//基数排序
void RadixSort(int arr[], int len)
{
	if (len <= 1)
		return;

	//分配一个长度为10的桶数组
	int bucket[10][NUM], count[10];
	memset(count, 0, sizeof(count));//初始化为0

	//找到数组中最大的位数
	int max = arr[0], exp = 1;
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
			max = arr[i];

	}
	while (max / exp > 0)
	{
		//将桶中的元素按照位数依次放置到桶中
		for (int i = 0; i < len; i++)
		{
			int index = (arr[i] / exp) % 10;
			bucket[index][count[index]++] = arr[i];

		}

		//将桶中的数据按照顺序存储回原数组
		int pos = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < count[i]; j++)
				arr[pos++] = bucket[i][j];
			count[i] = 0;//计数器清零
		}

		//更新位数
		exp *= 10;
	}
}

//基数排序
void radix()
{
	int random_nums[NUM];

	clock_t total_time = 0; // 总时间

	for (int k = 0; k < 10000; k++) // 运行 100k 次
	{
		clock_t start = clock();
		savefile();
		loadfile(random_nums);

		RadixSort(random_nums, NUM);

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

