#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdlib>
#include <ctime>
#include "system.h"

class Account {
public:
	int credit = 0;
	int outcome = 0;
	int debt = 20000000;
	void income(Date *d1);
};

#endif