#pragma once
#include <vector>
#include "driverDependent.h"
#include "driverIndependent.h"

class TaxiPark {
private:
	std::vector<DriverDependent> driversDependent;
	std::vector<DriverIndependent> driversIndependent;
	void loadData();
public:

	TaxiPark() {
		loadData();
	}
	~TaxiPark() {}
	/*~TaxiPark() {
		for (int i = 0; i < drivers.size; i++)
		{
			delete drivers[i];
		}
	}*/
	DriverDependent getDependent(int index);
	DriverIndependent getIndependent(int index);
	/*Driver* operator[] (const int index);*/
};