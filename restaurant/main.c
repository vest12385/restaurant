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
		printf("本餐廳尚未營業\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	printf("請入大人人數：");
	scanf("%d", &adults);
	printf("請輸入小孩人數：");
	scanf("%d", &childs);
	if (adults + childs > 40)
	{
		printf("本餐廳沒那麼多位置！！\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	int pay = countBill(hour, wday, adults, childs);
	printf("---------------歡迎光臨---------------\n");
	printf("   %d 年 %d 月 %d 號     %d 分 %d 秒  \n", year, month, day, hour, second);
	printf("   大人 %d 位  小孩 %d 位  共 %d 位\n", adults, childs, adults + childs);
	printf("                         總共 %d 元\n", pay);
	printf("---------------謝謝惠顧---------------\n");
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
