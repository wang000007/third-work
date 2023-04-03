#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��������
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

//��������
void insert()
{
	int random_nums[NUM];
	
	clock_t total_time = 0; // ��ʱ��

	for (int k = 0; k < 10000; k++) // ���� 100k ��
	{
		clock_t start = clock();
		savefile();
		loadfile(random_nums);

		InsertSort(random_nums, NUM);

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