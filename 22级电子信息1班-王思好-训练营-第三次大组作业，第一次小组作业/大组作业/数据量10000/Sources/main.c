#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int choice = 0;
	do {
		printf("��ǰ������Ϊ10000����ѡ������ʽ��\n");
		printf("0.�˳�\n");
		printf("1.��������\n");
		printf("2.�鲢����\n");
		printf("3.��������\n");
		printf("4.��������\n");
		printf("5.��������\n");
		
		scanf("%d", &choice);
		system("cls"); //����
		switch (choice)
		{
		case 1:
		{
			insert();
			break;
		}
		case 2:
		{
			merge();
			break;
		}
		case 3:
		{
			quick();
			break;
		}
		case 4:
		{
			count();
			break;
		}
		case 5:
		{
			radix();
			break;
		}
		default:
		{
			printf("����������\n");
			break;
		}
		}
	} while (choice != 0);
	return 0;
}

