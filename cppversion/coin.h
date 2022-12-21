#ifndef __COIN_H__
#define __COIN_H__

#include "system.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Coin {
public:
	double price = 0;
	double s_price = 0;
	double e_price = 0;
	double month_max_price = 0;
	double month_min_price = 0;
	double year_max_price = 0;
	double year_min_price = 0;
	int year = 2022;
	int month = 1;
	int bb_rate = 0;
	double base = 0;
	double vol = 0;
	double fluctation = 0;
	void time_set(Coin* c, int year, int month);
	void volume();
	void day();
	void month_setting();
	void month_cleanup();
};

#endif
