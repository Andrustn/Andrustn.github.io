#include "CupCake.h"
#include<string>
using namespace std;

const double CUPCAKE_PRICE = 1.95;
const double CREAM_CHEESE_EXTRA = .20;
const double MORE_THAN_TWO_DISCOUNT = .30;
const double MORE_THAN_THREE_DISCOUNT = .40;
const double DISCOUNT_LIMIT_TWO = 2.0;
const double DISCOUNT_LIMIT_FOUR = 4.0;

Cupcake::Cupcake(string userCakeFlavor, string userFrostingFlavor, string userSprinklescolor) {
	cakeFlavor = userCakeFlavor;
	frostingFlavor = userFrostingFlavor;
	sprinklesColor = userSprinklescolor;
	priceOfGood = CUPCAKE_PRICE;

	if (userFrostingFlavor == "cream-cheese") {
		priceOfGood = priceOfGood + CREAM_CHEESE_EXTRA;
	}
}
string Cupcake::GatherGoodInfo() {
	string goodInfo;
	goodInfo = cakeFlavor + " cupcake with " + frostingFlavor + " frosting and " + sprinklesColor + " sprinkles ($" + BakedGood::GatherGoodInfo() + ")";
	return goodInfo;
}
double Cupcake::GetDiscountPrice(int userNumOfGoods) {
	double fullPrice = userNumOfGoods * priceOfGood;
	double discountPrice = fullPrice;
	if (userNumOfGoods >= DISCOUNT_LIMIT_FOUR) {
		discountPrice = discountPrice - MORE_THAN_THREE_DISCOUNT * userNumOfGoods;
	}
	else if (userNumOfGoods >= DISCOUNT_LIMIT_TWO) {
		discountPrice = discountPrice - MORE_THAN_TWO_DISCOUNT * userNumOfGoods;
	}
	
	return discountPrice;
}