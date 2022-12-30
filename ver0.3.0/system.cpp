#include "system.h"
#include <cstdlib>
#include <ctime>

void Date::time_spend(Date *c) {
	c->date++;
	if (c->date == 29) {
		if (c->month == 2) {
			c->month++;
			c->date = 1;
		}
	}
	else if (c->date == 31) {
		if (c->month == 4 || c->month == 6 || c->month == 9 || c->month == 11) {
			c->month++;
			c->date = 1;
		}
	}
	else if (c->date == 32) {
		if (c->month == 1 || c->month == 3 || c->month == 5 || c->month == 7 || c->month == 8 || c->month == 10 || c->month == 12) {
			c->month++;
			c->date = 1;
			if (c->month == 13) {
				c->year++;
				c->month = 1;
			}
		}
	}
}

int Market::UpAndDown(Market* c) {
	int pm = rand() % 10000;
	if (pm < 1000) {
		down = 0;
		s_down = 0;
	}
	else if (pm < 1500) {
		s_down = 0;
	}
	else if (pm > 4000 && pm < 6000) {
		s_down = 0;
		s_up = 0;
	}
	else if (pm > 8500) {
		up = 0;
		s_up = 0;
		if (up > 5)
			cooltime = 100;
	}
	else if (pm > 8000) {
		s_up = 0;
	}

	if ((pm % 400 < 1 || up > 0) && (down == 0 && cooltime == 0)) {
		bb_rate = 0;
		s_up = 0;
		s_down = 0;
		up++;
		up_count++;
	}
	else if ((pm % 400 < 10 || s_up > 0) && (s_down == 0 && down == 0)) {
		bb_rate = 1;
		up = 0;
		s_up++;
		s_up_count++;
	}
	else if (pm % 400 < 390 && s_down == 0 && down == 0) {
		bb_rate = 2;
		nowave_count++;
	}
	else if ((pm % 400 < 399 || s_down > 0) && down == 0) {
		bb_rate = 3;
		s_down++;
		s_down_count++;
	}
	else if (pm % 400 < 400 || down > 0) {
		bb_rate = 4;
		down++;
		down_count++;
	}

	if (cooltime > 0)
		cooltime--;
	c->bb_rate = bb_rate;
	return c->bb_rate;
}

void Market::Market_Indicator() {
	printf("기준 금리 : %.2lf%%\n", base_rate * 100);
	printf("\n");
}

void event(Market* mk) {
	int parameter = 0;
	parameter = rand() % 10000;

	if (mk->up > 5 && (parameter > 1000 && parameter < 1300)) {
		printf("기준 금리 0.25%% 인상 %.2lf%% -> %.2lf%%\n", mk->base_rate * 100, mk->base_rate * 100 + 0.25);
		mk->up = 0;
		mk->base_rate += 0.0025;
		mk->cooltime = 60;
	}

	if (mk->down > 5 && (parameter > 8000 && parameter < 8300)) {
		printf("기준 금리 0.25%% 인하 %.2lf%% -> %.2lf%%\n", mk->base_rate * 100, mk->base_rate * 100 - 0.25);
		mk->down = 0;
		mk->base_rate -= 0.0025;
	}
}
