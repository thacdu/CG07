/**
 * this file implements all the methods of the class Point3D which was 
 * specified in file "Point3D.h"
 **/

#include "Point3D.h"
#include <cmath>

Point3D::Point3D()
{
	set(0.0, 0.0, 0.0);
}

Point3D::Point3D(float _x, float _y, float _z)
{
	set(_x, _y, _z);
}

Point3D::Point3D(const Point3D& _other_point)
{
	set(_other_point.x, _other_point.y, _other_point.z);
}

Point3D::~Point3D()
{
}

void Point3D::set(float _x, float _y, float _z)
{
	x = _x; y = _y; z = _z;
}

void Point3D::set(const Point3D& _other_point)
{
	set(_other_point.x, _other_point.y, _other_point.z);
}

float Point3D::getX()
{
	return x;
}

float Point3D::getY()
{
	return y;
}

float Point3D::getZ()
{
	return z;
}

void Point3D::rotate(float ux, float uy, float uz, float angle)
{
	/* convert the angle from degree to radian */
	float radian_angle = angle*M_PI/180;
	
	/* calculate the cos(angle) and sin(angle) */
	float c = cos(radian_angle);
	float s = sin(radian_angle);

	/* calculate the ordinates of this point after rotating */
	float result_x = (c + (1-c)*ux*ux)*x + ((1-c)*uy*ux - s*uz)*y + ((1-c)*uz*ux + s*uy)*z;
	float result_y = ((1-c)*ux*uy + s*uz)*x + (c + (1-c)*uy*uy)*y + ((1-c)*uz*uy - s*ux)*z;
	float result_z = ((1-c)*ux*uz - s*uy)*x + ((1-c)*uy*uz + s*ux)*y + (c + (1-c)*uz*uz)*z;
	
	/* set this point to the new ordinates */
	set(result_x, result_y, result_z);
}
