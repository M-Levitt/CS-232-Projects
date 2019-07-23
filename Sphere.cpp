#include "Sphere.h"
#include<iostream>

void Sphere::setRadius(double radiusPar) {
	if (radiusPar > 0)
		radius = radiusPar;
	else
		radius = 0;
}

double Sphere::getRadius(void) {
	return radius;
}

double Sphere::calcSurfaceArea(double radiusPar) {
	return 4.0 * 3.141596 * pow(radiusPar, 2.0);
}

double Sphere::calcVolume(double radiusPar) {
	return 4.0 / 3.0 * pow(radiusPar, 3.0) * 3.141596;
}

Sphere::Sphere() {
	radius = 0.0;
}

Sphere::Sphere(double radiusPar) {
	if (radiusPar > 0)
		radius = radiusPar;
	else
		radius = 0;
}