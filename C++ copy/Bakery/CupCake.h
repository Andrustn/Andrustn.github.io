#pragma once
#include "Cake.h"
class Cupcake : public Cake {
public:
	Cupcake(string userCakeFlavor, string userFrostingFlavor, string userSprinklescolor);
	string GatherGoodInfo();
	virtual double GetDiscountPrice(int userNumOfGoods);

private:
	string sprinklesColor;
};
