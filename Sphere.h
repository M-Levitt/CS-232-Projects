#ifndef _SPHERE
#define _SPHERE

class Sphere {
public:
	void setRadius(double radiusPar); //mutator, setter
	double getRadius(void); //accessor, getter

	double calcSurfaceArea(double radiusPar);
	double calcVolume(double radiusPar);

	Sphere(); //default constructor
	Sphere(double radiusPar); //overloaded constructor
private:
	double radius;

};

#endif
