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
	printf("請入大人人數：");
	while ((preturn = scanf("%d", &adults)) != 1)
	{
		printf("請輸入數字!!!! 請入大人人數：\n");
		while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
	}
	if (adults == 830508)
	{
		printf("今天是星期幾?：");
		while ((preturn = scanf("%d", &wday)) != 1)
		{
			printf("請輸入數字!!!! 今天是星期幾?：\n");
			while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
		}
		printf("現在時間是?：");
		while ((preturn = scanf("%d", &hour)) != 1)
		{
			printf("請輸入數字!!!! 現在時間是?：\n");
			while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
		}
		printf("請入大人人數：");
		while ((preturn = scanf("%d", &adults)) != 1)
		{
			printf("請輸入數字!!!! 請入大人人數：\n");
			while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
		}
	}
	printf("請輸入小孩人數：");
	while ((preturn = scanf("%d", &childs)) != 1)
	{
		printf("請輸入數字!!!! 請輸入小孩人數：\n");
		while ((c = getchar()) != '\n' && c != EOF); //clear stdin buffer, because if your input was not integer scanf didn't accecpt , then the input stay live in buffer
	}
	if (hour >= 22 || hour <= 8)
	{
		printf("本餐廳尚未營業\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	if (adults + childs > 40 || adults + childs == 0)
	{
		printf("人數有錯喔！！\n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	int pay = countBill(hour, wday, adults, childs);
	printf("---------------歡迎光臨---------------\n");
	printf("   %d 年 %d 月 %d 號     %d 點 %d 分 %d 秒  \n", year, month, day, hour, minute, second);
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
