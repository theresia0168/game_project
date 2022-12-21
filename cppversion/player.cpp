#include "player.h"
#include "system.h"

void Account::income(Date *d) {
	credit += 2200000;
	outcome = (rand() % 30 + 140) * 10000;
	credit -= outcome;
	credit -= (300000 + (debt * 0.05) / 12);
	debt -= 300000;
	if (d->month % 3 == 0)
		credit += (credit * 0.03);
}