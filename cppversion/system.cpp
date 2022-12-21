#include "system.h"
#include "coin.h"
#include <cstdlib>
#include <ctime>

void Date::time_spend(Date *c) {
	if (c->month == 12) {
		c->year++;
		c->month = 1;
		c->date = 1;
	}
	else {
		c->month++;
		c->date = 1;
	}
}

int Date::date_range_set() {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 32;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 31;
	}
	else {
		return 29;
	}
}

int UpDown::UpAndDown(UpDown* c) {
	int pm = rand() % 10000;
	if (pm < 750) {
		down = 0;
		s_down = 0;
	}
	else if (pm < 1250) {
		s_down = 0;
	}
	else if (pm > 4000 && pm < 5000) {
		s_down = 0;
		s_up = 0;
	}
	else if (pm > 8500) {
		up = 0;
		s_up = 0;
		if (up > 10)
			cooltime = 100;
	}
	else if (pm > 8000) {
		s_up = 0;
	}

	if ((pm < 50 || up > 0) && (down == 0 && cooltime == 0)) {
		bb_rate = 0;
		s_up = 0;
		s_down = 0;
		up++;
	}
	else if ((pm < 1500 || s_up>0) && (s_down == 0 && down == 0)) {
		bb_rate = 1;
		up = 0;
		s_up++;
	}
	else if (pm < 8500 && s_down == 0 && down == 0) {
		bb_rate = 2;
	}
	else if ((pm < 9950 || s_down>0) && down == 0) {
		bb_rate = 3;
		s_down++;
	}
	else if (pm < 10000 || down>0) {
		bb_rate = 4;
		down++;
	}

	if (cooltime > 0)
		cooltime--;
	c->bb_rate = bb_rate;
	return c->bb_rate;
}