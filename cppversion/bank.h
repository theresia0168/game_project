#ifndef __BANK_H__
#define __BANK_H__

#include <cstdlib>
#include <ctime>
#include "system.h"

class Account {
public:
	int credit = 0;
	int outcome = 0;
	int debt = 20000000;
	void income(Date* d1, Market* mk);
	void loan(Account* ac);
};

#endif

