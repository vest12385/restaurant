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
		year = now->tm_year + 1900,
		month = now->tm_mon + 1,
		day = now->tm_mday,
		hour = now->tm_hour,
		minute = now->tm_min,
		second = now->tm_sec,
		wday = now->tm_wday;
	//printf("%d %d %d %d %d %d %d", year, month, day, hour, minute, second, wday);
	if (hour >= 22 || hour <= 8)
	{
		printf("���\�U�|����~\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	printf("�ФJ�j�H�H�ơG");
	scanf("%d", &adults);
	printf("�п�J�p�ĤH�ơG");
	scanf("%d", &childs);
	if (adults + childs > 40)
	{
		printf("���\�U�S����h��m�I�I\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	int pay = countBill(hour, wday, adults, childs);
	printf("---------------�w����{---------------\n");
	printf("   %d �~ %d �� %d ��     %d �� %d ��  \n", year, month, day, hour, second);
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
