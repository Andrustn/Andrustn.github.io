#pragma once
#include "BakedGood.h"
#include<string>
class Cake : public BakedGood {
public:
	Cake(string userCakeFlavor = "NONE", string userFrostingFlavor = "NONE");
	virtual string GatherGoodInfo() = 0;
protected:
	string cakeFlavor;
	string frostingFlavor;
};

