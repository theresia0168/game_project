#include "coin.h"

using namespace std;

void Coin::time_set(Coin* c, int year, int month) {
	c->year = year;
	c->month = month;
}

void Coin::volume() {
	vol += 100;
}

void Coin::day() {
	int pm;
	for (int i = 0; i < 24; i++) {
		pm = rand() % 5;
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				base = price / 5000000;
				if (bb_rate == 0) {			// 0 : 폭등
					if (pm < 4)
						price += base;
					else
						price -= base;
				}
				else if (bb_rate == 1) {	// 1 : 상승
					if (pm < 3)
						price += base;
					else
						price -= base;
				}
				else if (bb_rate == 2) {	// 2 : 보합
					if (pm < 2)
						price += base;
					else if (pm < 3)
						price = price;
					else
						price -= base;
				}
				else if (bb_rate == 3) {	// 3 : 하락
					if (pm < 2)
						price += base;
					else
						price -= base;
				}
				else if (bb_rate == 4) {	// 4 : 폭락
					if (pm < 1)
						price += base;
					else
						price -= base;
				}
			}
		}
	}
	if (price > month_max_price)
		month_max_price = price;

	if (price < month_min_price)
		month_min_price = price;
}

void Coin::month_setting() {
	s_price = price;
	month_max_price = price;
	month_min_price = price;
}

void Coin::month_cleanup() {
	if (month_max_price > year_max_price)
		year_max_price = month_max_price;

	if (month_min_price < year_min_price)
		year_min_price = month_min_price;

	e_price = price;
	fluctation = (e_price / s_price - 1) * 100;

	printf("시가 : \\%.2lf\n", s_price);
	printf("종가 : \\%.2lf\n", e_price);
	printf("고가 : \\%.2lf\n", month_max_price);
	printf("저가 : \\%.2lf\n", month_min_price);
	printf("등락률 : %.2lf%%\n", fluctation);
}