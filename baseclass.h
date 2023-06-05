#ifndef BASECLASS_H
#define BASECLASS_H
class AstronomicalObject {
public:
	virtual ~AstronomicalObject() {}
	virtual std::string getName() const = 0;
	virtual std::string getType() const = 0;
	virtual double getMass() const = 0;
	virtual double getRadius() const = 0;
	virtual double getDistance() const = 0;
	virtual double getTemperature() const = 0;
	virtual double getApparentMagnitude() const = 0;
};
#endif
