#include<string>
using namespace std;
#pragma once

class BakedGood {
public:
	BakedGood();
	virtual string GatherGoodInfo();
	virtual double GetDiscountPrice(int userNumGoods);

protected:
	double priceOfGood;
};

