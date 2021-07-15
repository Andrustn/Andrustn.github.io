#include<string>
#include<iostream>
#include "BakedGood.h"
using namespace std;

BakedGood::BakedGood(){
	priceOfGood = 0.0;
}

string BakedGood::GatherGoodInfo() {
	string goodInfo;
	goodInfo = to_string(priceOfGood);
	return goodInfo;
}

double BakedGood::GetDiscountPrice(int userNumGoods) {
	double discountPrice;
	discountPrice = priceOfGood;
	return discountPrice;
}