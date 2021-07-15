#pragma once
#include "BakedGood.h"
#include<string>
class Bread : public BakedGood {
public:
	Bread(string userBreadType = "No bread type specified");
	string GatherGoodInfo();
	double GetDiscountPrice(int userNumOfGoods);
private:
	string breadType;
};

