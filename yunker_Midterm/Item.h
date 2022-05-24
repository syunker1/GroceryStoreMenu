#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
	double price = 0;
	string name = "";
	static double delivery;
	double tip = 0;
	double individualPrice = 0;
	double amount = 0;

public:
	Item();
	Item(double p, string n, double ip, double a);
	void setDelivery(double d);
	void setTip(double t);
	void setName(string n);
	void setPrice(double pri);
	void setIP(double ip);
	void setAmount(double a);
	double getIP();
	double getAmount();
	double getDelivery();
	double getTip();
	string getName();
	double getPrice();
};

class FreshProduce : public Item {
private:
	double pounds = 0;
public:
	FreshProduce();
	FreshProduce(double p, string n, double ip, double a);
	double calcPrice();
	void setPounds(double p);
	int getPounds();
};

class MeasuredProduct : public Item {
private:
	int quantity = 0;
public:
	MeasuredProduct();
	MeasuredProduct(double p, string n, double ip, double a);
	double calcPrice();
	void setQuantity(int q);
	int getQuantity();
};

#endif // !ITEM_H

