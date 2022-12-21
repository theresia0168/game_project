#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "coin.h"
#include <cstdlib>
#include <ctime>

class Date {
public:
	int year = 2022;
	int month = 1;
	int date = 1;
	int date_range = 0;
	void time_spend(Date *c);
	int date_range_set();
};

class UpDown {
public:
	int up = 0;
	int s_up = 0;
	int s_down = 0;
	int down = 0;
	int bb_rate = 0;
	int cooltime = 0;
	int UpAndDown(UpDown *c);
};

#endif