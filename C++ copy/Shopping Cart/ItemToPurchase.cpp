#include "ItemToPurchase.h"
#include<string>
using namespace std;

ItemToPurchase::ItemToPurchase() {
	itemName = "None";
	itemPrice = 0;
	itemQuantity = 0;
}
void ItemToPurchase::SetName(string userName) {
	itemName = userName;
}
string ItemToPurchase::GetName() {
	return itemName;
}
void ItemToPurchase::SetPrice(double userPrice) {
	itemPrice = userPrice;
}
double ItemToPurchase::GetPrice() {
	return itemPrice;
}
void ItemToPurchase::SetQuantity(int userQuantity) {
	itemQuantity = userQuantity;
}
int ItemToPurchase::GetQuantity() {
	return itemQuantity;
}


