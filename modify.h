#ifndef MODIFY_H
#define MODIFY_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
void modify_data(std::string choice, std::string name, std::string type, double mass, double radius, double distance, double temperature, double magnitude)
{
	static bool copy_made = false;
	std::string filename = "data.dat";
	//COPY OF THE ORIGINAL FILE BEFORE ITS MODIFIED
	if (!copy_made) { // check if copy has already been made
		std::ifstream is(filename);
		std::ofstream os("datacopy.dat");//destination file
		// read the contents of the source file and write them to the destination file
		char c;
		while (is.get(c)) {
			os.put(c);
		}
		std::cout << "\t|A copy of the old file has been made|\n" << std::endl;
		is.close();
		os.close();
		copy_made = true; // set flag to true
	}
	if (choice == "add") {
		std::ofstream outputFile(filename, std::ios::app);
		if (!outputFile) {
			std::cerr << "Error: unable to open file " << filename << std::endl;
			return;
		}
		// write the new line to the file
		outputFile << name << "\t" << type << "\t" << mass << "\t" << radius << "\t" << 
			distance << "\t" << temperature << "\t" << magnitude << std::endl;
		// close the file
		outputFile.close();
		std::cout << "\t|Data has been added to the file|\n" << std::endl;
	}
	if (choice == "modify") {
		std::ofstream outputFile("temp.txt"); // Temporal data file
		outputFile << name << "\t" << type << "\t" << mass << "\t" << radius << "\t" <<
			distance << "\t" << temperature << "\t" << magnitude << std::endl;
		outputFile.close();
		if (remove(filename.c_str()) != 0) { // Delete the original file
			std::cerr << "Error deleting file" << std::endl;
		}
		if (rename("temp.txt", filename.c_str()) != 0) { // Rename the temporary output file to the original file name
			std::cerr << "Error renaming file" << std::endl;
		}
		std::cout << "\t|File modified|\n" << std::endl;
	}
}
#endif