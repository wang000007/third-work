#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void savefile()
{
	int i;
	FILE* fp = fopen("random_numbers.txt", "w");

	//����rand��������Ϊ��ǰʱ��
	srand((unsigned)time(NULL));

	//ʹ��ѭ������NUM�������
	for (i = 0; i < NUM; i++)
	{
		fprintf(fp, "%d ", rand());
	}

	//�ر��ļ�

	fclose(fp);

}

void loadfile(int arr[])
{
	int i;

	FILE* fp = fopen("random_numbers.txt", "r");
	if (fp == NULL)
	{
		printf("Failed to open file !\n");
		return;
	}

	//ѭ����ȡ�ļ��е�������������������
	for (i = 0; i < NUM; i++)
	{
		fscanf(fp, "%d", &arr[i]);
		
	}
	fclose(fp);
}