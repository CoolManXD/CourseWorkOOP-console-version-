#pragma once
#include "map.h"

class DriverMap
{
private:
	int quantityStreet;
	std::vector<std::vector<std::pair<int, float>>> trafficJams;
	void updateDataTrafficJams();
public:
	DriverMap(Map& map);
};