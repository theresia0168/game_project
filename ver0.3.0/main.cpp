#include <stdio.h>
#include "exchange.h"
#include <Windows.h>
#include "system.h"

int main() {
	Exchange test;
	Date d;

	srand(time(NULL));

	for (int i = 0; i < 20; i++) {
		test.add();
	}test.COSPI();
	
	while (1) {
		printf("%d - %d - %d\n", d.year, d.month, d.date);
		test.day(&test, test.size());
		test.event();
		test.print(test.size());
		d.time_spend(&d);
	}

	return 0;
}