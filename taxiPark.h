#pragma once
#include <vector>
#include "driverDependent.h"
#include "driverIndependent.h"

class Client;

class TaxiPark {
private:
	std::vector<DriverDependent> driversDependent;
	std::vector<DriverIndependent> driversIndependent;
	Client* m_client{ NULL };
	void loadData();
public:
	TaxiPark() {
		loadData();
	}
	bool checkLoadData();
	void receiveOrder(Client*);
	void completeOrder();
	DriverDependent getDependent(int index);
	DriverIndependent getIndependent(int index);
	/*Driver* operator[] (const int index);*/
	~TaxiPark() {}
};