#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

//�������������
#define NUM 100

//��������
void savefile();//���������
void loadfile(int arr[]);//��ȡ�����


void InsertSort(int k[], int n);//����
void swap(int k[], int low, int high);//����
int partition(int k[], int low, int high);//����
void QuickSort(int k[], int low, int high);//����
void merging(int arr[], int left, int mid, int right);//�鲢
void MergeSort(int arr[], int left, int right);//�鲢
void CountSort(int arr[], int len);//����
void RadixSort(int arr[], int len);//����


void insert();//��������
void quick();//��������
void merge();//�鲢����
void count();//��������
void radix();//��������
#endif //
