#include "driverMap.h"
#include "map.h"
#include <cstdlib>
#include <ctime>

DriverMap::DriverMap(const Map& map) : m_map(map)
{
	m_trafficJams.resize(m_map.quantityStreet);
	for (int i = 0; i < m_map.quantityStreet; i++)
	{
		for (int j = 0; j < m_map.mapOfTown[i].size(); j++)
		{
			m_trafficJams[i].push_back(std::make_pair((m_map.mapOfTown[i][j].first)[0] - 49, 0));
		}
	}
	updateDataTrafficJams();
}

void DriverMap::updateDataTrafficJams() {
	srand(time(NULL));
	for (int i = 0; i < m_trafficJams.size(); i++)
	{
		for (int j = 0; j < m_trafficJams[i].size(); j++)
		{
			m_trafficJams[i][j].second = (float(rand() % 5 + 1) / 2)*m_map.mapOfTown[i][j].second;
		}
	}
}

