#define _ISOC99_SOURCE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
	int countBill(int, int, int, int);
int main(void)
{
	time_t current_time = time(NULL);
	struct tm * now = localtime(&current_time);
	int adults = 0,
		childs = 0,
		preturn = 0,
		c,
		year = now->tm_year + 1900,
		month = now->tm_mon + 1,
		day = now->tm_mday,
		hour = now->tm_hour,
		minute = now->tm_min,
		second = now->tm_sec,
		wday = now->tm_wday;
	//printf("%d %d %d %d %d %d %d", year, month, day, hour, minute, second, wday);
	printf("�ФJ�j�H�H�ơG");
	while ((preturn = scanf("%d", &adults)) != 1)
	{
		printf("�п�J�Ʀr!!!! �ФJ�j�H�H�ơG\n");
		while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
	}
	if (adults == 830508)
	{
		printf("���ѬO�P���X?�G");
		while ((preturn = scanf("%d", &wday)) != 1)
		{
			printf("�п�J�Ʀr!!!! ���ѬO�P���X?�G\n");
			while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
		}
		printf("�{�b�ɶ��O?�G");
		while ((preturn = scanf("%d", &hour)) != 1)
		{
			printf("�п�J�Ʀr!!!! �{�b�ɶ��O?�G\n");
			while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
		}
		printf("�ФJ�j�H�H�ơG");
		while ((preturn = scanf("%d", &adults)) != 1)
		{
			printf("�п�J�Ʀr!!!! �ФJ�j�H�H�ơG\n");
			while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
		}
	}
	printf("�п�J�p�ĤH�ơG");
	while ((preturn = scanf("%d", &childs)) != 1)
	{
		printf("�п�J�Ʀr!!!! �п�J�p�ĤH�ơG\n");
		while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
	}
	if (hour >= 22 || hour <= 8)
	{
		printf("���\�U�|����~\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	if (adults + childs > 40 || adults + childs == 0)
	{
		printf("�H�Ʀ�����I�I\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	int pay = countBill(hour, wday, adults, childs);
	printf("---------------�w����{---------------\n");
	printf("   %d �~ %d �� %d ��     %d �I %d �� %d ��  \n", year, month, day, hour, minute, second);
	printf("   �j�H %d ��  �p�� %d ��  �@ %d ��\n", adults, childs, adults + childs);
	printf("                         �`�@ %d ��\n", pay);
	printf("---------------���´f�U---------------\n");
	system("PAUSE");
}

int countBill(int hour, int wday, int adults, int childs)
{
	double pay = 0.0;
	int total = adults + childs;
	int total_temp = total;
	int childs_temp = childs;
	while ((total_temp = total_temp - 3) >= 0)
	{
		if ((childs_temp = childs_temp - 1) >= 0)
			childs--;
		else
			adults--;
	}
	if (hour <= 17 && wday < 6)
		pay += adults * 268 + childs * 120;
	else
		pay += adults * 368 + childs * 150 + (adults * 368 + childs * 150) * 0.1;
	if (total > 10)
		pay = pay * 0.95;
	pay = round(pay);
	return pay;
}
