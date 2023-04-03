#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��������
void CountSort(int arr[], int len)
{
	if (len < 1)return;

	//Ѱ������Ԫ��
	int max = arr[0];
	for (int i = 1; i < len; i++)
		if (arr[i] > max)
			max = arr[i];

	//����һ������Ϊmax+1������洢����������ʼ��Ϊ0
	int* count = (int*)malloc(sizeof(int) * (max + 1));
	memset(count, 0, sizeof(int) * (max + 1));// ��ʼ��Ϊ 0

	//����
	for (int i = 0; i < len; i++)
		count[arr[i]]++;// ͳ�� arr[i] Ԫ�س��ֵĴ���

	//ͳ�Ƽ������ۼ�ֵ
	for (int i = 1; i < max + 1; i++)
		count[i] += count[i - 1];// �� count ���鴦����ۼƴ�������ʽ

	//����һ����ʱ���鱣����
	int* output = (int*)malloc(sizeof(int) * len);

	//��Ԫ�طŵ���ȷ��λ����
	for (int i = len - 1; i >= 0; i--)
	{
		output[--count[arr[i]]] = arr[i]; // �� count �����в��� arr[i] ��Ӧ���±꣬��������� output ������
	}

	//��������ƻ�ԭ����
	for (int i = 0; i < len; i++)
		arr[i] = output[i];
	free(count); // �ͷŶ�̬������ڴ�
	free(output);
}

//��������
void count()
{
	int random_nums[NUM];
	
	clock_t total_time = 0; // ��ʱ��

	for (int k = 0; k < 10000; k++) // ���� 100k ��
	{
		clock_t start = clock();
		savefile();
		loadfile(random_nums);

		CountSort(random_nums, NUM);

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
