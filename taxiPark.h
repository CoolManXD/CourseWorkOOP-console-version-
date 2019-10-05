#pragma once
#include <vector>
#include "driver.h"

class TaxiPark {
private:
	std::vector<Driver> drivers;
	void loadData();
public:
	TaxiPark() {
		loadData();
	}
	~TaxiPark(){}
	/*~TaxiPark() {
		for (int i = 0; i < drivers.size; i++)
		{
			delete drivers[i];
		}
	}*/
	Driver getItem(int index);
	/*Driver* operator[] (const int index);*/
};