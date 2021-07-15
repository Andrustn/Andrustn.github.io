#include<iostream>
#include<string>
#include "ItemToPurchase.h"
#include<iomanip>
using namespace std;

int main() {

	ItemToPurchase Item1;
	ItemToPurchase Item2;
	string userName;
	double userPrice;
	int userQuantity;

	cout << "Item 1" << endl;
	cout << "Enter the item name: " << endl;
	getline(cin, userName);
	cout << "Enter the item price: " << endl;
	cin >> userPrice;
	cin.ignore();
	cout << "Enter the item quantity: " << endl;
	cin >> userQuantity;
	cin.ignore();

	Item1.SetName(userName);
	Item1.SetPrice(userPrice);
	Item1.SetQuantity(userQuantity);

	cout << "Item 2" << endl;
	cout << "Enter the item name: " << endl;
	getline(cin, userName);
	cout << "Enter the item price: " << endl;
	cin >> userPrice;
	cin.ignore();
	cout << "Enter the item quantity: " << endl;
	cin >> userQuantity;
	cin.ignore();

	Item2.SetName(userName);
	Item2.SetPrice(userPrice);
	Item2.SetQuantity(userQuantity);


	cout << "TOTAL COST" << endl;
	double Item1Cost;
	cout << Item1.GetName();
	cout << " ";
	cout << Item1.GetQuantity();
	cout << " @ ";
	cout << fixed;
	cout << "$" << setprecision(2) << Item1.GetPrice();
	cout << " = ";
	Item1Cost = Item1.GetQuantity() * Item1.GetPrice();
	cout << setprecision(2) << "$" << Item1Cost << endl;

	double Item2Cost;
	cout << Item2.GetName();
	cout << " ";
	cout << Item2.GetQuantity();
	cout << " @ ";
	cout << "$" << setprecision(2) << Item2.GetPrice();
	cout << " = ";
	Item2Cost = Item2.GetQuantity() * Item2.GetPrice();
	cout << setprecision(2) << "$" << Item2Cost << endl << endl;

	cout << "Total: $" << Item1Cost + Item2Cost << endl;




	system("pause");
	return 0;
}