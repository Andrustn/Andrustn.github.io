#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

const string BREAD_STRING = "Bread";
const string LAYER_CAKE_STRING = "Layer-cake";
const string CUPCAKE_STRING = "Cupcake";
const string NULL_STRING = "NONE";
const string DONE_STRING = "done";

int main() {
	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	vector <BakedGood*> shoppingCart;

	string userItemSelection = NULL_STRING;
	cout << "Sub-order: ";
	
	while (userItemSelection != DONE_STRING) {
		
		
		cin >> userItemSelection;

		if (userItemSelection == BREAD_STRING) {
			//cout << "enter bread type" << endl;
			string userBreadType;
			int breadQuantity;
			cin >> userBreadType;
			//cout << "enter quantity" << endl;
			cin >> breadQuantity;
			cin.ignore();
			for (int i = 0; i < breadQuantity; i++) {
				BakedGood* breadPtr = new Bread(userBreadType);
				shoppingCart.push_back(breadPtr);
			}
		}
		else if (userItemSelection == LAYER_CAKE_STRING) {
			
			//cout << "enter cake flavor" << endl;
			string userCakeFlavor;
			string userFrostingFlavor;
			int userNumLayers;
			cin >> userCakeFlavor;
			//cout << "enter frosting flavor" << endl;
			cin >> userFrostingFlavor;
			//cout << "enter number of layers" << endl;
			cin >> userNumLayers;
			cin.ignore();
			//cout << "enter quantity" << endl;
			int layerCakeQuantitiy;
			cin >> layerCakeQuantitiy;
			cin.ignore();

			for (int i = 0; i < layerCakeQuantitiy; i++) {
				BakedGood* layerCakePtr = new LayerCake(userCakeFlavor, userFrostingFlavor, userNumLayers);
				shoppingCart.push_back(layerCakePtr);
			}
		
		}
		else if (userItemSelection == CUPCAKE_STRING) {
			//cout << "enter cake flavor" << endl;
			string userCakeFlavor;
			string userFrostingFlavor;
			string userSprinklesColor;
			cin >> userCakeFlavor;
			//cout << "enter frosting flavor" << endl;
			cin >> userFrostingFlavor;
			//cout << "enter sprinkles color" << endl;
			cin >> userSprinklesColor;
			//cout << "enter quantity" << endl;
			int cupcakeQuantitiy;
			cin >> cupcakeQuantitiy;
			cin.ignore();

			for (int i = 0; i < cupcakeQuantitiy; i++) {
				BakedGood* cupcakePtr = new Cupcake(userCakeFlavor, userFrostingFlavor, userSprinklesColor);
				shoppingCart.push_back(cupcakePtr);
			}
		}
		else if (userItemSelection == DONE_STRING) {
			break;
		}
		cout << "Sub-order: " << endl;
	}
	
	cout << "Order Confirmations: ";

	for (unsigned int i = 0; i < shoppingCart.size(); i++) {
		cout << shoppingCart.at(i)->GatherGoodInfo() << endl;
	}
	cout << endl;

	vector<int> quantityList;

	for (unsigned int i = 0; i < shoppingCart.size(); i++) {
		int incrementValue = 0;
		for (unsigned int j = i + 1; j < shoppingCart.size(); j++) {
			if (shoppingCart.at(i)->GatherGoodInfo() == shoppingCart.at(j)->GatherGoodInfo()) {
				incrementValue++;
				delete shoppingCart.at(j);
				shoppingCart.erase(shoppingCart.begin() + j);
				j--;
			}
		}
		quantityList.push_back(incrementValue + 1);
	}

	cout << "Invoice: " << endl;
	cout << setw(75) << left << "Baked Good" << setw(9) << right << "Quantity" << setw(9) << right << "Total" << endl;
	double totalCost = 0;
	double totalQuantity = 0;


	for (unsigned int i = 0; i < shoppingCart.size(); i++) {
		cout << setw(75) << left << shoppingCart.at(i)->GatherGoodInfo() << setw(9) << right << quantityList.at(i) << setw(9) << setprecision(2) << fixed << shoppingCart.at(i)->GetDiscountPrice(quantityList.at(i)) << endl;
		totalCost = totalCost + shoppingCart.at(i)->GetDiscountPrice(quantityList.at(i));
		totalQuantity = totalQuantity + quantityList.at(i);
	}
	cout << setprecision(0) << fixed;

	cout << setw(75) << left << "Totals" << setw(9) << right << totalQuantity << setw(9) << right << setprecision(2) << fixed << totalCost << endl;



	cout << "Goodbye" << endl;


	//system("pause");
	return 0; 
}