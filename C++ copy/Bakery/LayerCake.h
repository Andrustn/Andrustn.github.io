#pragma once
#include "Cake.h"


class LayerCake : public Cake {
public:
	LayerCake(string userCakeFlavor, string userFrostingFlavor, int userNumLayers);
	string GatherGoodInfo();
	double GetDiscountPrice(int userNumOfGoods);
private:
	int numLayers;
};

