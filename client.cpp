#include "client.h"
#include "map.h"
#include <iostream>

Client::Client(const Map& map) : m_map{ map }
{
	std::cout << "Fill profile\n";
	std::cout << "Name: ";
	std::getline(std::cin, m_name);

	std::cout << std::endl << "List of streets\n";
	for (auto it = m_map.listOfStreets.begin(); it != m_map.listOfStreets.end(); ++it)
	{
		std::cout << it->first << std::endl;
	}
	do
	{
		std::cout << "Location: ";
		std::getline(std::cin, m_location);
	} while (m_map.listOfStreets.find(m_location) == m_map.listOfStreets.end());


	std::cout << std::endl << "List of streets\n";
	for (auto it = m_map.listOfStreets.begin(); it != m_map.listOfStreets.end(); ++it)
	{
		std::cout << it->first << std::endl;
	}
	do
	{
		std::cout << "Destination: ";
		std::getline(std::cin, m_destination);
	} while (m_map.listOfStreets.find(m_destination) == m_map.listOfStreets.end() || m_destination == m_location);

}

Client::Client(const Map& map, std::string name, std::string location, std::string destination)
	: m_map{ map }, m_name{ name }, m_location{ location }, m_destination{ destination }
{

}
const std::string& Client::getLocation()
{
	return m_location;
}
const std::string& Client::getDesination()
{
	return m_destination;
}