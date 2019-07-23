#ifndef _CUBE
#define _CUBE
class Cube {
private:
	double side;
public:
	double getSide();
	void setSide(double sidePar);
	double calcSurface();
	double calcVolume();
	Cube(); //constructor
	Cube(double sidePar);
};

#endif