#pragma once
#include <vector>
#include <string>
//#include "driverMap.h"
//#include "client.h"
class DriverMap;
class Client;

class Map {
private:
	int quantityStreet;
	std::vector<std::vector<std::pair<std::string, float>>> mapOfTown;
	const int INF{ 1000000000 };
	void loadMap();
public:
	Map() 
	{
		loadMap();
	}
	friend class DriverMap;
	friend class Client;
	/*friend DriverMap::DriverMap(const Map& map);*/
	/*friend void DriverMap::updateDataTrafficJams();*/
};