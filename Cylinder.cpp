#include<iostream>
#include"Cylinder.h"

double Cylinder::getHeight() {
	return height;
}

void Cylinder::setHeight(double heightPar) {
	if (heightPar > 0)
		height = heightPar;
	else
		height = 0;
}

double Cylinder::getRadius() {
	return radius;
}

void Cylinder::setRadius(double radiusPar) {
	if (radiusPar > 0)
		radius = radiusPar;
	else
		radius = 0;
}

double Cylinder::calcCylinderSurface() {
	return 2.0 * PI * radius * height + 2.0 * PI * pow(radius, 2.0);
}

double Cylinder::calcCylinderVolume() {
	return PI * pow(radius, 2.0) * height;
}

Cylinder::Cylinder() {
	height = 0.0;
	radius = 0.0;
}

Cylinder::Cylinder(double heightPar, double radiusPar) {
	if (heightPar > 0)
		height = heightPar;
	else
		height = 0;

	if (radiusPar > 0)
		radius = radiusPar;
	else
		radius = 0;
}