#pragma once

#include <vector>

class Map;

class DriverMap
{
private:
	/*int quantityStreet;*/
	
public:
	Map& m_map;
	std::vector<std::vector<std::pair<int, float>>> m_trafficJams;
	DriverMap(Map&);
	void updateDataTrafficJams();
};