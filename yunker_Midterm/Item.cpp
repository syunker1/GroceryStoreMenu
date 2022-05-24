#include "Item.h"

using namespace std;

//item constructors and references to set price/name 

Item::Item() {};

Item::Item(double p, string n, double ip, double a) {
	price = p;
	name = n;
	individualPrice = ip;
	amount = a;

}

//setter/getter for each variable 
void Item::setIP(double ip) {
	individualPrice = ip;
}

void Item::setAmount(double a) {
	amount = a;
}

void Item::setDelivery(double d) {
	delivery = d;
}
void Item::setName(string n) {
	name = n;
}
void Item::setTip(double t) {
	tip = t;
}
void Item::setPrice(double pri) {
	price = pri;
}

double Item::getAmount() {
	return amount;
}
double Item::getIP() {
	return individualPrice;
}
double Item::getDelivery() {
	return delivery;
}
string Item::getName() {
	return name;
}
double Item::getTip() {
	return tip;
}
double Item::getPrice() {
	return price;
}

//constructors with one to pass name/price
FreshProduce::FreshProduce() : Item() {}
FreshProduce::FreshProduce(double p, string n, double ip, double a) : Item(p, n, ip, a) {}

//calculates/returns total
double FreshProduce::calcPrice() {
	
	double total = getPounds() * getPrice();
	return total;
}
//pounds setter/getter
void FreshProduce::setPounds(double po) {
	pounds = po;
}
int FreshProduce::getPounds() {
	return pounds;
}

//constructors with one to pass name/price
MeasuredProduct::MeasuredProduct() : Item(){}
MeasuredProduct::MeasuredProduct(double p, string n, double ip, double a) : Item(p, n, ip, a) {}

//calculates/returns total
double MeasuredProduct::calcPrice() {
	double total = getQuantity() * getPrice();
	return total;
}

//quantity setter and getter 
void MeasuredProduct::setQuantity(int q) {
	quantity = q;
}
int MeasuredProduct::getQuantity() {
	return quantity;
}

