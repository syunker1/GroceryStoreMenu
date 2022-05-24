#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>

/*
Steve Yunker
ITDEV 185 
Final
*/

using namespace std;

//declarations of static variables and class objects 

double Item::delivery = 20;
//double Item::tip;

MeasuredProduct mp;
FreshProduce fp;
vector<Item*> cart;

int deliveryMenu();
int mainMenu();
int freshProduceMenu();
int meatAndSeafood();
int frozenMenu();
void enterTip();
void calculateFrozen(vector<Item> &cart, double p, string n);
void calculateProduce(vector<Item> &cart, double p, string n);
void printVector(vector<Item>& newCart);
void printVectorTip(vector<Item>& newCart);
void addCustomOrder(vector<Item>& newCart);

int main() {
	vector<Item> cart;
	int choice = 0;
	int deliveryChoice = 0;
	int submenuChoice = 0;

	//switch statement for delivery choice 
	switch (deliveryChoice = deliveryMenu()) {
	case 1:
		break; 
	case 2:		
		enterTip();
		break;
	case 5:
		return  0;
} system("cls");

	/*
	* nested switch statement with main menu and sub menus with do while loops so the 
	* sub menus stay open before going back to main menu 
	*/
	do {
		switch (choice = mainMenu()) {
		case 1:
			system("cls");
			do {
				switch (submenuChoice = freshProduceMenu()) {
				case 1:
					calculateProduce(cart, 3.99, "GALA APPLES");
					break;
				case 2:
					calculateProduce(cart, 0.48, "BANANA");
					break;
				case 3:
					calculateProduce(cart, 2.99, "GRAPES");
					break;
				case 4:
					break;
				}
			} while (submenuChoice != 4);
			system("cls");
			break;
		case 2:
			system("cls");
			do {
				switch (submenuChoice = meatAndSeafood()) {
				case 1:
					calculateProduce(cart, 6.99, "CHICKEN");
					break;
				case 2:
					calculateProduce(cart, 4.99, "GROUND BEEF");
					break;
				case 3:
					calculateProduce(cart, 9.99, "SALMON");
					break;
				case 4:
					break;
				}
			} while (submenuChoice != 4);
			system("cls");
			break;
		case 3:
			system("cls");
			do {
				switch (submenuChoice = frozenMenu()) {
				case 1:
					calculateFrozen(cart, 6.99, "WAFFLES");
					break;
				case 2:
					calculateFrozen(cart, 4.99, "PIZZA");
					break;
				case 3:
					calculateFrozen(cart, 2.99, "POPSICLE");
					break;
				case 4:
					break;
					system("cls");
				}
			} while (submenuChoice != 4);
			system("cls");
			break;
		case 4:
			addCustomOrder(cart);
			break;
		case 5:
			system("cls");
			break;
		}
	} while (choice != 5);

	//prints delivery or not delivery method depending on the choice made above 

	if (deliveryChoice == 2) {
		
		printVectorTip(cart);
	}
	else {
		mp.setDelivery(0);
		mp.setTip(0);
		printVector(cart);
	}
}

//delivery menu 
int deliveryMenu() {
	int choice = 0;
			do {
				cout << "**********************************" << endl;
				cout << "(1) Pick Up" << endl;
				cout << "\n(2) Delivery" << endl;
				cout << "\n\n(5) Exit" << endl;
				cout << "**********************************" << endl;
				cin >> choice;
				if (choice != 1 && choice != 2 && choice != 5) {
					cout << "Invalid choice" << endl;
				}
			} while (choice != 1 && choice != 2 && choice != 5);
			return choice;
	}

//main menu 
int mainMenu() {
	int choice = 0;
	do {
		cout << "**********************************" << endl;
		cout << "\n(1) Fresh Produce" << endl;
		cout << "\n(2) Meat and Seafood" << endl;
		cout << "\n(3) Frozen Foods" << endl;
		cout << "\n(4) Add Custom Order" << endl;
		cout << "\n(5) Check Out" << endl;
		cout << "**********************************" << endl;
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice !=5) {
			cout << "Invalid choice" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
	return choice;
}

//menu for fresh produce 
int freshProduceMenu() {
	int choice = 0;
	do {
		cout << "**********************************" << endl;
		cout << "\n(1) Gala Apples $3.99/lb" << endl;
		cout << "\n(2) Banana $0.48/lb" << endl;
		cout << "\n(3) Grapes $2.99/lb" << endl;
		cout << "\n(4) Return to Main Menu" << endl;
		cout << "**********************************" << endl;
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << "Invalid choice" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
	return choice;
}
//menu for meat 
int meatAndSeafood() {
	int choice = 0;
	do {
		cout << "**********************************" << endl;
		cout << "\n(1) Whole Chicken 6.99/lb" << endl;
		cout << "\n(2) Ground Beef $4.99/lb" << endl;
		cout << "\n(3) Salmon $9.99/lb" << endl;
		cout << "\n(4) Return to Main Menu" << endl;
		cout << "**********************************" << endl;
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << "Invalid choice" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
	return choice;
}
//menu for frozen food
int frozenMenu() {
	int choice = 0;
	do {
		cout << "**********************************" << endl;
		cout << "\n(1) Waffles $6.99" << endl;
		cout << "\n(2) Pizza $4.99" << endl;
		cout << "\n(3) Popsicle $2.99" << endl;
		cout << "\n(4) Return to Main Menu" << endl;
		cout << "**********************************" << endl;
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << "Invalid choice" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
	return choice;
}
//method to calculate quantity and set the price/name in vector 
void calculateFrozen(vector<Item>& newCart, double p, string n) {
	double price;
	string name;
	double choice;
	double individualPrice;
	cout << "Enter the quantity of your item: " << endl;
	cin >> choice;
	mp.setQuantity(choice);
	mp.setPrice(p);
	mp.setName(n);
	mp.setIP(p);
	individualPrice = mp.getIP();
	name = mp.getName();
	price = mp.calcPrice();
	MeasuredProduct newOrder(price, name, individualPrice, mp.getQuantity());
	newCart.push_back(newOrder);
}
//method to calculate produce and set price/names in vector
void calculateProduce(vector<Item>& newCart, double p, string n) {
	double price;
	string name;
	double choice;
	double individualPrice;
	cout << "weight of selected items in pounds: " << endl;
	cin >> choice;
	fp.setPounds(choice);
	fp.setPrice(p);
	fp.setName(n);
	fp.setIP(p);
	individualPrice = fp.getIP();
	name = fp.getName();
	price = fp.calcPrice();
	FreshProduce newOrder(price, name, individualPrice, fp.getPounds());
	newCart.push_back(newOrder);
}

//method to print total without delivery 
void printVector(vector<Item>& newCart) {
	double total = 0;
	cout << fixed << left << setprecision(2) << endl;
	cout << "***************************************" << endl;
	for (int i = 0; i < newCart.size(); i++) {
		total += newCart[i].getPrice();
		cout << "\t" << setw(10) << newCart[i].getName() << setw(5)  << "\t$"
			<< setw(3) << newCart[i].getPrice() << "\n"
			<< "\t" << newCart[i].getAmount() << " @ $" << newCart[i].getIP() << endl;
	}
	cout << "\n" << endl;
	cout << "\t" << setw(10) << "TIP" << setw(5) << "\t$" << setw(3) << mp.getTip() << endl;
	cout << "\t" << setw(10) << "DELIVERY" << setw(5) << "\t$" << setw(3) << mp.getDelivery() << endl;
	cout << "\t" << setw(15) << "__________________________" << endl;
	cout << "\t" << setw(10) << "TOTAL" << setw(5) << "\t$" << setw(3) << total << endl;
	cout << "\n***************************************" << endl;
	cout << "***************************************" << endl;
}
//method to print total with delivery 
void printVectorTip(vector<Item>& newCart) {
	double total = 0;
	cout << fixed << left << setprecision(2) << endl;
	cout << "***************************************" << endl;
	for (int i = 0; i < newCart.size(); i++) {
		total += newCart[i].getPrice();
		cout << "\t" << setw(10) << newCart[i].getName() << setw(5) << "\t$"
			<< setw(3) << newCart[i].getPrice() << "\n"
			<< "\t" << newCart[i].getAmount() << " @ $" << newCart[i].getIP() << endl;
	}
	total += mp.getDelivery();
	total += mp.getTip();
	cout << "\n" << endl;
	cout << "\t" << setw(10) << "TIP" << setw(5) << "\t$" << setw(3) << mp.getTip() << endl;
	cout << "\t" << setw(10) << "DELIVERY" << setw(5) << "\t$" << setw(3) << mp.getDelivery() << endl;
	cout << "\t" << setw(15) << "_________________________" << endl;
	cout << "\t" << setw(10) << "TOTAL" << setw(5) << "\t$" << setw(3) << total << endl;
	cout << "\n***************************************" << endl;
	cout << "***************************************" << endl;
}
void enterTip() {
	double tip; 
	do {
		cout << "\nPlease enter your tip amount as a number greater than 0" << endl;
		cin >> tip;
		if (tip <= 0){
			cout << "Tip must be greater than 0!" << endl;
		}
	} while (tip <= 0);
	mp.setTip(tip);
}

void addCustomOrder(vector<Item>& newCart) {
	int itemTypeChoice;
	string name;
	double individualPrice;
	int quantity;
	double pounds; 
	double price;
	do {
		cout << "Would you like to add an item measured in lbs or quantity?" << endl;
		cout << "(1) Lbs" << endl;
		cout << "\n(2) Quantity" << endl;
		cin >> itemTypeChoice;
		if (itemTypeChoice != 1 && itemTypeChoice != 2) {
			cout << "\ninvalid choice, choose 1 or 2" << endl;
		}
	} while (itemTypeChoice != 1 && itemTypeChoice != 2);
	if (itemTypeChoice == 1) {
		cout << "Enter the name of the product: " << endl;
		cin >> name;
		for (int i = 0; i < name.size(); i++) {
			name.at(i) = toupper(name.at(i));
		}
		cout << "Enter the price of the product per pound: " << endl;
		cin >> individualPrice;
		cout << "Enter the amount of pounds" << endl;
		cin >> pounds;
		fp.setPounds(pounds);
		fp.setPrice(individualPrice);
		fp.setName(name);
		price = fp.calcPrice();
		FreshProduce newOrder(price, fp.getName(), fp.getPrice(), fp.getPounds());
		newCart.push_back(newOrder);
	}
	else if (itemTypeChoice == 2) {
		cout << "Enter the name of the product: " << endl;
		cin >> name;
		for (int i = 0; i < name.size(); i++) {
			name.at(i) = toupper(name.at(i));
		}
		cout << "Enter the price of the single product: " << endl;
		cin >> individualPrice;
		cout << "Enter the quantity you're purchasing: " << endl;
		cin >> quantity;
		mp.setQuantity(quantity);
		mp.setPrice(individualPrice);
		mp.setName(name);
		price = mp.calcPrice();
		FreshProduce newOrder(price, mp.getName(), mp.getPrice(), mp.getQuantity());
		newCart.push_back(newOrder);
	}
}