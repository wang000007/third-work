#include"Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �鲢����������������
void merging(int arr[], int left, int mid, int right)
{
	int len1 = mid - left + 1;// �����鳤��
	int len2 = right - mid;// �����鳤��
	int* L = (int*)malloc(len1 * sizeof(int));  // ��̬����������ռ�
	int* R = (int*)malloc(len2 * sizeof(int));  // ��̬����������ռ�

	for (int i = 0; i < len1; i++)
	{
		L[i] = arr[left + i];  // ���������
	}

	for (int j = 0; j < len2; j++)
	{
		R[j] = arr[mid + 1 + j]; // ���������
	}

	int i = 0, j = 0, k = left;  // ��ʼ��ָ��i,j,k
	while (i < len1 && j < len2) { // ���������鶼��Ϊ��ʱ
		if (L[i] <= R[j]) {  // �����鵱ǰԪ��С�ڵ��������鵱ǰԪ��
			arr[k++] = L[i++];   // �������鵱ǰԪ�ظ��Ƶ�arr�У�ͬʱ����i,k
		}
		else {             // �����鵱ǰԪ�ش��������鵱ǰԪ��
			arr[k++] = R[j++];   // �������鵱ǰԪ�ظ��Ƶ�arr�У�ͬʱ����j,k
		}
	}
	while (i < len1) {  // ��������黹��ʣ��Ԫ�أ���ȫ�����Ƶ�arr��
		arr[k++] = L[i++];
	}
	while (j < len2) {  // ��������黹��ʣ��Ԫ�أ���ȫ�����Ƶ�arr��
		arr[k++] = R[j++];
	}
	free(L);  // �ͷ��ڴ�
	free(R);
}

// �鲢����
void MergeSort(int arr[], int left, int right)
{
	if (left >= right) return;

	int mid = (left + right) / 2;// �����м�λ��

	MergeSort(arr, left, mid);// �����߽�������
	MergeSort(arr, mid + 1, right);// ���Ұ�߽�������

	merging(arr, left, mid, right); // �鲢������������


}

//�鲢����
void merge()
{
	int random_nums[NUM];

	clock_t total_time = 0; // ��ʱ��

	for (int k = 0; k < 10000; k++) // ���� 100k ��
	{
		clock_t start = clock();
		savefile();
		loadfile(random_nums);

		MergeSort(random_nums, 0, NUM - 1);

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