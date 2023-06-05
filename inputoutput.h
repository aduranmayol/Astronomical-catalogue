#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "table.h"
void input_output(std::string object_type, std::string file) {
	// Open the input file
	std::ifstream inputFile(file);
	if (!inputFile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	bool headers_printed = false; // Initialize flag to false
	while (std::getline(inputFile, line)) {
		// Extract values from the current line of the file
		std::istringstream  ss(line);
		std::string nameValue, typeValue;
		double massValue,
			radiusValue, distanceValue, temperatureValue, magnitudeValue;
		std::getline(ss, nameValue, '\t');
		std::getline(ss, typeValue, '\t');
		ss >> massValue >> radiusValue >> distanceValue >> temperatureValue >> magnitudeValue;
		// Process the line based on the object type
		if (object_type == "Galaxy") {
			if (typeValue == "Galaxy") {
				Galaxy new_galaxy(nameValue, typeValue, massValue, radiusValue, distanceValue,
					temperatureValue, magnitudeValue);
				std::vector<std::string> headers = { "Object",
					"Mass(M_s)", "Radius(R_s)", "Distance(ly)", "Temperature(K)",
					"m_v", "Luminosity(W)" };
				std::vector<Data> data;
				Data d = { new_galaxy.getName(), new_galaxy.getMass(), new_galaxy.getRadius(),
					new_galaxy.getDistance(), new_galaxy.getTemperature(), new_galaxy.getApparentMagnitude(),
					new_galaxy.getLuminosity() };
				data.push_back(d);
				print_table(data, headers, !headers_printed); // Pass false if headers have already been printed
				headers_printed = true; // Set flag to true after first object is processed
			}
		}
		if (object_type == "Star") {
			if (typeValue == "Star") {
				Star new_star(nameValue, typeValue, massValue, radiusValue, distanceValue, temperatureValue, magnitudeValue);
				std::vector<std::string> headers = { "Object",
					"Mass(M_s)", "Radius(R_s)", "Distance(ly)", "Temperature(K)",
					"m_v", "Luminosity(W)", "Spectral type" };
				std::vector<Data2> data;
				Data2 d = { new_star.getName(), new_star.getMass(), new_star.getRadius(),
					new_star.getDistance(), new_star.getTemperature(), new_star.getApparentMagnitude(),
					new_star.getLuminosity(), new_star.spectraltype() };
				data.push_back(d);
				print_table_star(data, headers, !headers_printed);
				headers_printed = true;
			}
		}
		if (object_type == "Planet") {
			if (typeValue == "Planet") {
				Planet new_planet(nameValue, typeValue, massValue, radiusValue, distanceValue, temperatureValue, magnitudeValue);
				std::vector<std::string> headers = { "Object", "Mass(M_s)",
					"Radius(R_s)", "Distance(ly)", "Temperature(K)",
					"m_v", "Luminosity(W)" };
				std::vector<Data> data;
				Data d = { new_planet.getName(), new_planet.getMass(), new_planet.getRadius(),
					new_planet.getDistance(), new_planet.getTemperature(), new_planet.getApparentMagnitude(),
					new_planet.getLuminosity() };
				data.push_back(d);
				print_table(data, headers, !headers_printed);
				headers_printed = true;
			}
		}
		if (object_type == "Nebula") {
			if (typeValue == "Nebula") {
				Nebula new_nebula(nameValue, typeValue, massValue, radiusValue, distanceValue, temperatureValue, magnitudeValue);
				std::vector<std::string> headers = { "Object", "Mass(M_s)",
					"Radius(R_s)", "Distance(ly)", "Temperature(K)",
					"m_v", "Luminosity(W)" };
				std::vector<Data> data;
				Data d = { new_nebula.getName(), new_nebula.getMass(), new_nebula.getRadius(),
					new_nebula.getDistance(), new_nebula.getTemperature(), new_nebula.getApparentMagnitude(),
					new_nebula.getLuminosity() };
				data.push_back(d);
				print_table(data, headers, !headers_printed);
				headers_printed = true;
			}
		}
		if (object_type == "Other") {
			if (typeValue == "Other") {
				Other new_other(nameValue, typeValue, massValue, radiusValue,
					distanceValue, temperatureValue, magnitudeValue);
				std::vector<std::string> headers = { "Object", "Mass(M_s)", "Radius(R_s)",
					"Distance(ly)", "Temperature(K)",
					"m_v", "Luminosity(W)" };
				std::vector<Data> data;
				Data d = { new_other.getName(), new_other.getMass(), new_other.getRadius(),
					new_other.getDistance(), new_other.getTemperature(), new_other.getApparentMagnitude(),
					new_other.getLuminosity() };
				data.push_back(d);
				print_table(data, headers, !headers_printed);
				headers_printed = true;
			}
		}
	}
}
void print_group(const std::string& name_galaxy, const std::string& name_star, const std::string& name_planet)
{
	Galaxy galaxy(name_galaxy, "Galaxy", 0, 0, 0, 0, 0);
	Star star(name_star, "Star", 0, 0, 0, 0, 0);
	Planet planet(name_planet, "Planet", 0, 0, 0, 0, 0);
	// Create two groups
	Group galaxyGroup(name_galaxy);
	Group starGroup(name_star);
	// Add objects to their respective groups
	galaxyGroup.addMember(&star);
	starGroup.addMember(&planet);
	// Print the members of each group
	std::cout << "\t||MEMBERS OF EACH GROUP||\n";
	std::cout << galaxyGroup.getName() << " includes ";
	for (auto membership : galaxyGroup.getMembers()) {
		std::cout << membership.getObject()->getName() << "\n";
	}

	std::cout << starGroup.getName() << " includes ";
	for (auto membership : starGroup.getMembers()) {
		std::cout << membership.getObject()->getName() << "\n";
	}
	std::cout << std::endl;
}
#endif