#pragma once

#include <vector>

class Map;

class DriverMap
{
private:
	/*int quantityStreet;*/
	const Map& m_map;
	std::vector<std::vector<std::pair<int, float>>> m_trafficJams;
	void updateDataTrafficJams();
public:
	DriverMap(const Map& map);
};