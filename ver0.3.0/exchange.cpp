#include <stdio.h>
#include "exchange.h"

Exchange::Exchange() {
	Head->nextNode = NULL;
	Exchange::count = 0;
}

int Exchange::size() {
	return Exchange::count;
}

void Exchange::add() {
	int pm;

	Coin* NewCoin = new Coin;

	pm = rand() % 10000;
	pm = pm - (pm % 10);
	NewCoin->price = pm;
	NewCoin->nextNode = NULL;

	for (int i = 0; i < 3; i++) {
		pm = rand() % 26;
		pm += 65;
		NewCoin->CoinNum[i] = pm;
	}

	if (Head->nextNode == NULL) {
		Head->nextNode = NewCoin;
	}
	else {
		Coin* temp = Head;
		while (temp->nextNode != NULL)
			temp = temp->nextNode;
		temp->nextNode = NewCoin;
	}
	Exchange::count++;
	Exchange::upbit++;
}

void Exchange::set(int index, int data) {
	Coin* temp = Head;
	for (int i = 0; i <= index; i++) {
		temp = temp->nextNode;
	}
	temp->price = data;
}

void Exchange::remove(int index) {
	Coin* temp = Head;
	Coin* remove = Head;

	for (int i = 0; i < index; i++) {
		temp = temp->nextNode;
		remove = remove->nextNode;
	}
	remove = remove->nextNode;

	temp->nextNode = remove->nextNode;

	temp->nextNode = remove->nextNode;
	remove->nextNode = NULL;
	for (int i = 0; i < 3; i++) {
		printf("%c", remove->CoinNum[i]);
	}printf(" 상장 폐지\n");
	delete remove;
	Exchange::count--;
	Exchange::downbit++;
	Sleep(3000);
}

void Exchange::COSPI() {
	Coin* temp = Head;
	for (int i = 0; i < size(); i++) {
		temp = temp->nextNode;
		base_cap += temp->price;
	}
}

void Exchange::print(int index) {
	Coin* temp = Head;
	for (int i = 0; i < index; i++) {
		temp = temp->nextNode;
		for (int j = 0; j < 3; j++) {
			printf("%c", temp->CoinNum[j]);
		}
		printf(" : %.2lf\t%.2lf%%\n", temp->price, temp->fluc);
	}printf("현재 상장 종목 : %d\n총 상장 종목 : %d\n상폐 종목 : %d\n", count, upbit, downbit);
	printf("COSPI : %.2lf\n\n", cospi);
}

void Exchange::basePrice(Coin* tmp) {
	if (tmp->price < 10)
		tmp->base = 0.01;
	else if (tmp->price < 100)
		tmp->base = 0.1;
	else if (tmp->price < 1000)
		tmp->base = 1;
	else if (tmp->price < 10000)
		tmp->base = 5;
	else if (tmp->price < 100000)
		tmp->base = 10;
	else if (tmp->price < 1000000)
		tmp->base = 50;
	else if (tmp->price < 10000000)
		tmp->base = 500;
	else
		tmp->base = 1000;
}
void Exchange::day(Exchange* tmp, int index) {
	Coin* temp = Head;
	int pm;
	int remove = -1;
	for (int i = 0; i < index; i++) {
		temp = temp->nextNode;
		temp->ex_price = temp->price;
		for (int j = 0; j < 24; j++) {
			for (int k = 0; k < 60; k++) {
				basePrice(temp);
				pm = rand() % 2;
				if (pm == 0)
					temp->price += temp->base;
				else
					temp->price -= temp->base;
			}
		}
		if (temp->price <= 1) {
			remove = i;
		}
		temp->fluc = (temp->price / temp->ex_price - 1) * 100;
		if (temp->fluc > 20)
			bull++;
		else if (temp->fluc < -20)
			bear--;
		market_cap += temp->price;
	}
	if (remove != -1) {
		tmp->remove(remove);
		remove = -1;
	}
	cospi = (market_cap / base_cap) * 100;
	market_cap = 0;
}

void Exchange::event() {
	int pm = rand();
	if (pm % 100 == 3 && size() < 20)
		add();
	else if (pm % 500 == 444) {
		pm = rand() % size();
		remove(pm);
	}
}