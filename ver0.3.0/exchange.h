#ifndef __EXCHANGE_H__
#define __EXCHANGE_H__

#include <cstdlib>
#include <ctime>
#include <Windows.h>

class Exchange {
private:
	class Coin {
	public:
		int CoinNum[3] = { 0 };
		double base = 0;
		double price;
		double ex_price;
		double fluc = 0;
		Coin* nextNode;
	};
	int count;
	int bull = 0;
	int bear = 0;
	int upbit = 0;
	int downbit = 0;
	double base_cap = 0;
	double market_cap = 0;
	double cospi = 0;
	Coin* Head = new Coin;
public:
	Exchange();

	void add();
	int size();
	void set(int index, int data);
	void remove(int index);
	void COSPI();
	void print(int index);
	void basePrice(Coin* tmp);
	void day(Exchange* tmp, int index);
	void event();
};

#endif // !__LINKLIST_H__

