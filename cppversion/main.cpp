#include<stdio.h>
#include "coin.h"
#include "system.h"
#include "player.h"

void month(Coin* c1, Coin* c2, Date* d1, UpDown* ud, Account *ac);

int main(int argc, char* argv[]) {
	srand((unsigned int)time(NULL));
	double baserand1;
	double baserand2;

	Coin xrp;
	baserand1 = rand() % 100;
	baserand2 = rand() % 5;
	xrp.price =  baserand1 + (baserand2 + 1) * 100;

	Coin btc;
	baserand1 = rand() % 1000;
	baserand2 = rand() % 5;
	btc.price = baserand1 + (baserand2 + 1) * 1000;

	Date date;
	UpDown UD;
	Account player;

	while (1) {
		int command = 0;
		printf("[1] : 시간 진행\n");
		printf("[2] : 매수/매도\n");
		printf("[3] : 자산 확인\n");
		printf("[4] : 종료\n$ ");
		scanf_s("%d", &command);
		printf("\n");
		if (command == 1)
			month(&xrp, &btc, &date, &UD, &player);
		else if (command == 4)
			break;
	}
	return 0;
}

void month(Coin* c1, Coin* c2, Date* d1, UpDown* ud, Account *ac) {
	printf("%d - %d\n", d1->year, d1->month);
	d1->date_range = d1->date_range_set();
	c1->month_setting();
	c2->month_setting();
	for (int j = 1; j < d1->date_range; j++) {
		ud->UpAndDown(ud);
		c1->bb_rate = ud->bb_rate;
		c2->bb_rate = ud->bb_rate;
		c1->day();
		c2->day();
		d1->date++;
	}
	ac->income(d1);
	printf("잔고 : \\%d\n", ac->credit);
	printf("지출 : \\%d\n", ac->outcome);
	printf("\n");

	printf("XRP\n");
	c1->month_cleanup();
	printf("\n");

	printf("BTC\n");
	c2->month_cleanup();
	d1->time_spend(d1);
	printf("\n");
}