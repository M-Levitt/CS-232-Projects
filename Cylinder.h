#ifndef _CYLINDER
#define _CYLINDER
class Cylinder {
private:
	double height;
	double radius;
public:
	const double PI = 3.141592653589793;
	double getHeight();
	void setHeight(double heightPar);
	double getRadius();
	void setRadius(double radiusPar);
	double calcCylinderSurface();
	double calcCylinderVolume();
	Cylinder(); //constructor
	Cylinder(double heightPar, double radiusPar);
};

#endif