/*Astronomical catalogue
Arnau Duran Mayol
April-May 2023
------------------------
The program contains options to display, add and classify data into to galaxies,
nebulae, stars, planets, and other astronomical objects.
The program uses several header files to define classes and functions, reads and writes data to a file
and accesses the membership information.
The main function displays a menu of options for the user to choose from and calls corresponding functions based on the user's input.
The program also checks for invalid input and provides prompts for the user to correct any errors.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
// HEADER FILES
#include "baseclass.h" 
#include "galaxy.h"
#include "star.h"
#include "planet.h"
#include "nebula.h" 
#include "other.h"
#include "membershipgroup.h"
#include "inputoutput.h"
#include "modify.h"
int main()
{
	std::cout << "\t" << "||ASTRONOMICAL CATALOGUE||" << "\n" << std::endl;
	std::string file = "data.dat";
	while (true) {
		std::string answer;
		// Display options for the user to choose
		std::cout << "Select one of these options:\n" <<
			"\t1. Galaxies\n" << "\t2. Nebulae\n" <<
			"\t3. Stars" << "\n" << "\t4. Planets" <<
			"\n" << "\t5. Other\n" << "\t6. Add data\n" << "\t7. Input data to an empty file\n" <<
			"\t8. Save file\n" << "\t9. Access copy of the original data\n" <<
			"\t10. Membership information\n" << "\t11. Exit console" << std::endl;
		std::cin >> answer;
		// Read user input and check if it is valid
		while (answer != "1" && answer != "2" && answer != "3" && answer != "4" &&
			answer != "5" && answer != "6" && answer != "7" && answer != "8" && answer != "9" && answer != "10" && answer != "11") {
			std::cerr << "Invalid answer. Please choose an option" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> answer;
		}
		// Call the corresponding function based on the user's choice
		if (answer == "1") {
			std::cout << "\t ||GALAXIES||" << std::endl;
			input_output("Galaxy", file);
			std::cout << std::endl;
		}
		if (answer == "2") {
			std::cout << "\t ||NEBULAE||" << std::endl;
			input_output("Nebula", file);
			std::cout << std::endl;
		}
		if (answer == "3") {
			std::cout << "\t ||STARS||" << std::endl;
			input_output("Star", file);
			std::cout << std::endl;
		}
		if (answer == "4") {
			std::cout << "\t ||PLANETS||" << std::endl;
			input_output("Planet", file);
			std::cout << std::endl;
		}
		if (answer == "5") {
			std::cout << "\t ||OTHER||" << std::endl;
			input_output("Other", file);
			std::cout << std::endl;
		}
		if (answer == "6") {
			// Get user input for adding new data
			std::string nameValue, typeValue;
			double massValue, radiusValue, distanceValue, temperatureValue, magnitudeValue;
			std::cin.ignore();
			std::cout << "Name: ";
			std::getline(std::cin, nameValue);
			std::cout << "Type: ";
			std::getline(std::cin, typeValue);
			std::cout << "Mass: ";
			while (!(std::cin >> massValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "Radius: ";
			while (!(std::cin >> radiusValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "Distance: ";
			while (!(std::cin >> distanceValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "Temperature: ";
			while (!(std::cin >> temperatureValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "Apparent magnitude: ";
			while (!(std::cin >> magnitudeValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << std::endl;
			modify_data("add", nameValue, typeValue, massValue, radiusValue, distanceValue, temperatureValue, magnitudeValue);

		}
		if (answer == "7") {
			std::string nameValue, typeValue;
			double massValue, radiusValue, distanceValue, temperatureValue, magnitudeValue;
			std::cin.ignore();
			std::cout << "Name: ";
			std::getline(std::cin, nameValue);
			std::cout << "Type: ";
			std::getline(std::cin, typeValue);
			std::cout << "New mass: ";
			while (!(std::cin >> massValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "Radius: ";
			while (!(std::cin >> radiusValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "New distance: ";
			while (!(std::cin >> distanceValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "New temperature: ";
			while (!(std::cin >> temperatureValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "Apparent magnitude: ";
			while (!(std::cin >> magnitudeValue)) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << std::endl;
			modify_data("modify", nameValue, typeValue, massValue, radiusValue, distanceValue, temperatureValue, magnitudeValue);
		}
		if (answer == "8") {
			std::string file;
			std::cout << "Type filename: ";
			std::cin >> file;
			std::ifstream ifs("data.dat");
			std::ofstream ofs(file);//destination file
			// read the contents of the source file and write them to the destination file
			char c;
			while (ifs.get(c)) {
				ofs.put(c);
			}
			std::cout << "\t|File has been saved|\n" << std::endl;
			ifs.close();
			ofs.close();
		}
		if (answer == "9") {
			file = "datacopy.dat";
			std::cout << "\t|The copy has been accessed|\n" << std::endl;
		}
		if (answer == "10") {
			// create membership associations
			std::string name_galaxy, name_star, name_planet;
			std::cin.ignore();
			std::cout << "Name the galaxy: ";
			std::getline(std::cin, name_galaxy);
			std::cout << std::endl;
			std::cout << "Name the star member of the galaxy: ";
			std::getline(std::cin, name_star);
			std::cout << std::endl;
			std::cout << "Name the planet member of the star: ";
			std::getline(std::cin, name_planet);
			std::cout << std::endl;
			print_group(name_galaxy, name_star, name_planet);
		}
		if (answer == "11") {
			break;
		}
	}
}