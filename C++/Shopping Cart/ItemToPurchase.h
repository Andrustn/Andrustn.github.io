#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include "ItemToPurchase.cpp"
#include<string>
using namespace std;
class ItemToPurchase {
public:
	ItemToPurchase();
	void SetName(string userName);
	string GetName();
	void SetPrice(double userPrice);
	double GetPrice();
	void SetQuantity(int userQuantity);
	int GetQuantity();

private:
	string itemName;
	double itemPrice;
	int itemQuantity;
};
#endif