#include "driverMap.h"

#include <cstdlib>
#include <ctime>


void DriverMap::updateDataTrafficJams() {
	srand(time(NULL));
	for (int i = 0; i < trafficJams.size(); i++)
	{
		for (int j = 0; j < trafficJams[i].size(); j++)
		{
			
			trafficJams[i][j].second = float(rand() % 5 + 1) / 2;
		}
	}
}

DriverMap::DriverMap(Map& map) : quantityStreet(map.quantityStreet)
{
	trafficJams.resize(quantityStreet);
	for (int i = 0; i < quantityStreet; i++)
	{
		for (int j = 0; j < map.map[i].size(); j++)
		{
			trafficJams[i].push_back(std::make_pair((map.map[i][j].first)[0] - 49, 0));
		}
	}
	updateDataTrafficJams();
}
