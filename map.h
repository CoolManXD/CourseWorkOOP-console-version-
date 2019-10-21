#pragma once
#include <vector>
#include <map>
#include <string>
//#include "driverMap.h"
//#include "client.h"
//class DriverMap;
//class Client;

class Map {
private:
	void loadMap();
public:
	int quantityStreet;
	std::map<std::string, int> listOfStreets;
	std::vector<std::vector<std::pair<int, float>>> mapOfTown;
	Map() 
	{
		loadMap();
	}
	/*friend class DriverMap;
	friend class Client;*/
	/*friend DriverMap::DriverMap(const Map& map);*/
	/*friend void DriverMap::updateDataTrafficJams();*/
};