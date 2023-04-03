#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����
void swap(int k[], int low, int high)
{
	int temp;
	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

//����
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

//��������
void QuickSort(int k[], int low, int high)
{


	if (low < high)
	{
		int point = partition(k, low, high);
		QuickSort(k, low, point - 1);
		QuickSort(k, point + 1, high);
	}
}

//��������
void quick()
{
	int random_nums[NUM];
	
	clock_t total_time = 0; // ��ʱ��

	for (int k = 0; k < 10000; k++) // ���� 100k ��
	{
		clock_t start = clock();
		savefile();
		loadfile(random_nums);

		QuickSort(random_nums, 0, NUM - 1);

		clock_t end = clock();
		total_time += end - start; // �ۼӱ������������ѵ�ʱ��
	}

	for (int i = 0; i < NUM; i++)
	{
		printf("%d ", random_nums[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("\n");

	printf("����ʱ%d ms\n", total_time);
	return 0;
}

