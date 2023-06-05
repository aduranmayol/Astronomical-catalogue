#include "nebula.h"
#include <cmath>
#include <vector>
#include <string>
Nebula::Nebula(std::string n, std::string t, double m, double r, double d, double temp, double a)
    : name(n), type(t), mass(m), radius(r), distance(d), temperature(temp), apparentmagnitude(a)
{} // constructor implementation
std::string Nebula::getType() const
{
    return "Nebula";
}
std::string Nebula::getName() const
{
    return name;
}
double Nebula::getMass() const
{
    return mass;
}
double Nebula::getRadius() const
{
    return radius;
}
double Nebula::getDistance() const
{
    return distance;
}
double Nebula::getTemperature() const
{
    return temperature;
}
double Nebula::getApparentMagnitude() const
{
    return apparentmagnitude;
}
double Nebula::getLuminosity()
{
    double distance_pc = distance / 3.261563;
    double absolutemagnitude = apparentmagnitude - 5 * log10(distance_pc / 10);
    return pow(10, -(absolutemagnitude / 2.512)); //in solar luminosities
}