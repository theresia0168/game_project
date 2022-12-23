#include<stdio.h>
#include "coin.h"
#include "system.h"
#include "bank.h"

void month(Coin* c1, Coin* c2, Date* d1, Market* ud, Account *ac);
void credit(Account* ac);

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
	Market UD;
	Account player;
	
	while (1) {
		int command = 0;
		printf("[1] 시간 진행\n");
		printf("[2] 매수/매도\n");
		printf("[3] 자산 확인\n");
		printf("[4] 대출 / 상환\n");
		printf("[5] 시장 지표 확인\n");
		printf("[6] 종료\n$ ");
		scanf_s("%d", &command);
		printf("\n");
		if (command == 1)
			month(&xrp, &btc, &date, &UD, &player);
		else if (command == 3)
			credit(&player);
		else if (command == 4) {
			printf("[1] 대출\n");
			printf("[2] 상환\n$ ");
			scanf_s("%d", &command);
			printf("\n");
			if (command == 1)
				player.loan(&player);
		}
		else if (command == 5)
			UD.Market_Indicator();
		else if (command == 6)
			break;
	}
	return 0;
}

void month(Coin* c1, Coin* c2, Date* d1, Market* ud, Account *ac) {
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
		event(ud);
	}
	ac->income(d1, ud);
	
	printf("XRP\n");
	c1->month_cleanup();
	printf("\n");

	printf("BTC\n");
	c2->month_cleanup();
	d1->time_spend(d1);
	printf("\n");
}

void credit(Account *ac) {
	printf("잔고 : \\%d\n", ac->credit);
	printf("지출 : \\%d\n", ac->outcome);
	printf("잔여 대출금 : \\%d\n", ac->debt);
	printf("\n");
}