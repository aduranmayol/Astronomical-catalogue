#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "galaxy.h"
#include "star.h"
#include "planet.h"
#include "nebula.h" 
#include "other.h"
struct Data { //allows the creation of a vector of strings and doubles
	std::string name;
	double mass;
	double radius;
	double distance;
	double temperature;
	double magnitude;
	double luminosity;
};
struct Data2 { // for star class with one more string
	std::string name;
	double mass;
	double radius;
	double distance;
	double temperature;
	double magnitude;
	double luminosity;
	std::string spectraltype;
};
void print_table(std::vector<Data> data, std::vector<std::string> headers, bool print_headers = true)
{
	int colWidth = 17;
	if (print_headers) { // Print headers if flag is set to true
		for (size_t i = 0; i < headers.size(); i++) {
			std::cout << std::setw(colWidth) << std::left << headers[i];
		}
		std::cout << "|" << std::endl;
		for (size_t k = 0; k < headers.size(); k++) {
			std::cout << std::string(colWidth, '-');
		}
		std::cout << std::endl;
	}
	// Print data with scientific notation when needed
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << std::setw(colWidth) << std::left << data[i].name;
		std::cout << std::setw(colWidth) << std::scientific << std::setprecision(2) << std::left << data[i].mass;
		std::cout << std::setw(colWidth) << std::left << data[i].radius;
		std::cout << std::setw(colWidth) << std::left << data[i].distance;
		std::cout << std::setw(colWidth) << std::fixed << std::setprecision(2) << std::left << data[i].temperature;
		std::cout << std::setw(colWidth) << std::left << data[i].magnitude;
		std::cout << std::setw(colWidth) << std::scientific << std::left << data[i].luminosity;
		std::cout << "|" << std::endl;
	}
}
void print_table_star(std::vector<Data2> data, std::vector<std::string> headers, bool print_headers = true)
{
	// Prints personalised table for star, with struct Data2
	int colWidth = 17;
	if (print_headers) { // Print headers if flag is set to true
		for (size_t i = 0; i < headers.size(); i++) {
			std::cout << std::setw(colWidth) << std::left << headers[i];
		}
		std::cout << "|" << std::endl;
		for (size_t k = 0; k < headers.size(); k++) {
			std::cout << std::string(colWidth, '-');
		}
		std::cout << std::endl;
	}
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << std::setw(colWidth) << std::left << data[i].name;
		std::cout << std::setw(colWidth) << std::scientific << std::setprecision(2) << std::left << data[i].mass;
		std::cout << std::setw(colWidth) << std::left << data[i].radius;
		std::cout << std::setw(colWidth) << std::left << data[i].distance;
		std::cout << std::setw(colWidth) << std::fixed << std::setprecision(2) << std::left << data[i].temperature;
		std::cout << std::setw(colWidth) << std::left << data[i].magnitude;
		std::cout << std::setw(colWidth) << std::scientific << std::left << data[i].luminosity;
		std::cout << std::setw(colWidth) << std::left << data[i].spectraltype;
		std::cout << "|" << std::endl;
	}
}
#endif