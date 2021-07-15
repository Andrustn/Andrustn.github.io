#include "LayerCake.h"


const double DISCOUNT_QUANTITY = 3.0;
const double DISCOUNT_VALUE = 2.0;
const double LAYER_CAKE_PRICE = 9.00;
const double LAYER_PRICE = 3.00;


LayerCake::LayerCake(string userCakeFlavor, string userFrostingFlavor, int userNumLayers) {
	cakeFlavor = userCakeFlavor;
	frostingFlavor = userFrostingFlavor;
	numLayers = userNumLayers;

	priceOfGood = LAYER_CAKE_PRICE + LAYER_PRICE * (userNumLayers - 1);

	if (userFrostingFlavor == "cream-cheese") {
		priceOfGood = priceOfGood + userNumLayers;
	}
}
string LayerCake::GatherGoodInfo() {
	string goodInfo;
	goodInfo = to_string(numLayers) + "-layer " + cakeFlavor + " cake with " + frostingFlavor + " frosting ($" + BakedGood::GatherGoodInfo() + ")";
	return goodInfo;
}

double LayerCake::GetDiscountPrice(int userNumOfGoods){
	double fullPrice = userNumOfGoods * priceOfGood;
	double discountPrice = fullPrice;
	if (userNumOfGoods >= DISCOUNT_QUANTITY) {
		discountPrice = discountPrice - DISCOUNT_VALUE * userNumOfGoods;
	}
	return discountPrice;
}