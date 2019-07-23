#include<iostream>
#include"Cube.h"

double Cube::getSide() {
	return side;
}

void Cube::setSide(double sidePar) {
	if (sidePar > 0)
		side = sidePar;
	else
		side = 0;
}

double Cube::calcSurface() {
	return 6.0 * pow(side, 2.0);
}

double Cube::calcVolume() {
	return pow(side, 3.0);
}

Cube::Cube() {
	side = 0;
}

Cube::Cube(double sidePar) {
	if (sidePar > 0)
		side = sidePar;
	else
		side = 0;
}