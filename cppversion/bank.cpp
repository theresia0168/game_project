#include "bank.h"
#include "system.h"

void Account::income(Date* d, Market *mk) {
	credit += 1200000;
	outcome = ((rand() % 20 + 90) * 10000) + (debt * mk->base_rate) / 12;
	credit -= outcome;
	if (d->month % 3 == 0)
		credit += (credit * mk->base_rate);
}

void Account::loan(Account* ac) {
	double loan;
	printf("대출 금액을 입력하시오 : ");
	scanf_s("%lf", &loan);
	ac->debt += loan;
	printf("\n");
}