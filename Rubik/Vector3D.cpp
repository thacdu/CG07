/**
 * This file implements all the methods specified int the file Vector3D.h
 **/

#include <cmath>
#include "Vector3D.h"

Vector3D::Vector3D() 
{
	set(0.0, 0.0, 0.0);
}

Vector3D::Vector3D(float _x, float _y, float _z)
{
	set(_x, _y, _z);
}

Vector3D::Vector3D(const Vector3D& _other_vector)
{
	set(_other_vector);
}

Vector3D::~Vector3D()
{

}

void Vector3D::set(float _x, float _y, float _z)
{
	x = _x; y = _y; z = _z;
}

void Vector3D::set(const Vector3D& _other_vector)
{
	set(_other_vector.x, _other_vector.y, _other_vector.z);
}

float Vector3D::getX() 
{
	return x;
}

float Vector3D::getY()
{
	return y;
}

float Vector3D::getZ()
{
	return z;
}

float Vector3D::length()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3D::setDiff(Point3D A, Point3D B)
{
	x = B.getX() - A.getX();
	y = B.getY() - A.getY();
	z = B.getZ() - A.getZ();
}

void Vector3D::normalize()
{
	/* calculate the length of this vector */
	float len = length();
	
	/* devided by the length to get the normal vector */
	set(x/len, y/len, z/len);
}

float Vector3D::dot(Vector3D _other)
{
	return x*_other.getX() + y*_other.getY() + z*_other.getZ();
}

Vector3D Vector3D::cross(Vector3D _other)
{
	/* calculate the ordinates of the cross product vector */
	float tempx = y*_other.getZ() - z*_other.getY();
	float tempy = z*_other.getX() - x*_other.getZ();
	float tempz = x*_other.getY() - y*_other.getX();
	
	return Vector3D(tempx, tempy, tempz);
}


