#include "Bread.h"

const double PRICE_OF_BREAD = 4.5;

Bread::Bread(string userBreadType) {
	breadType = userBreadType;
	priceOfGood = PRICE_OF_BREAD;
}
string Bread::GatherGoodInfo() {
	string goodInfo;
	goodInfo = breadType + " bread ($" + BakedGood::GatherGoodInfo() + ")";
	return goodInfo;
}
double Bread::GetDiscountPrice(int userNumOfGoods) {
	double discountPrice;
	double fullPrice = userNumOfGoods * priceOfGood;
	discountPrice = fullPrice;
	if (userNumOfGoods >= 3) {
		discountPrice = fullPrice - ((userNumOfGoods / 3) * priceOfGood);
	}
	return discountPrice;
}