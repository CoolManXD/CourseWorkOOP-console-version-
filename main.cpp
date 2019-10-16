#include <iostream>
#include "map.h"
#include "driverMap.h"
#include "taxiPark.h"
#include "client.h"
int main()
{
	
	Map map;
	DriverMap driverMap{ map };
	TaxiPark park;
	std::cout << park.getIndependent(0).getDriver().getName();
	park.checkLoadData();
	/*Client *client = new Client{ map };*/
	/*std::cout << client->getDesination();*/
	park.receiveOrder(new Client{ map });
	park.completeOrder();
	

	system("pause");
	return 0;
}





