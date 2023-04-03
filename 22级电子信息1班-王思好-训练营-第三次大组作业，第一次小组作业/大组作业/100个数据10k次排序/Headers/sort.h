#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

//定义最大数据量
#define NUM 100

//函数声明
void savefile();//生成随机数
void loadfile(int arr[]);//读取随机数


void InsertSort(int k[], int n);//插入
void swap(int k[], int low, int high);//交换
int partition(int k[], int low, int high);//遍历
void QuickSort(int k[], int low, int high);//快速
void merging(int arr[], int left, int mid, int right);//归并
void MergeSort(int arr[], int left, int right);//归并
void CountSort(int arr[], int len);//计数
void RadixSort(int arr[], int len);//基数


void insert();//插入排序
void quick();//快速排序
void merge();//归并排序
void count();//计数排序
void radix();//基数排序
#endif //
