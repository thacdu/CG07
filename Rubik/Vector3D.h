#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

/**
 * This class defines a vector in the 3-D coordinate system.
 * A vector is specified by ordinates x, y, z corresponding to x, y, z-axis
 * and some method such as
 * 		method to return the length of vector
 *		method to nomalize the vector
 * 		calculate the cross product and dot product of two vectors
 *		set a vector from 2 given point
 **/

#include "Point3D.h"
 
class Vector3D
{
private:
	float x, y, z;	// 3 ordinates in 3-D coordinate
	
public:
	/* constructors */
	Vector3D();	
	Vector3D(float _x, float _y, float _z);
	Vector3D(const Vector3D& _other_vector);
	
	/* destructor */
	~Vector3D();
	
	/* setter */
	void set(float _x, float _y, float _z);
	void set(const Vector3D& _other_vector);
	
	/* getter */
	float getX();
	float getY();
	float getZ();
	
	/* function to return the length of the vector */
	float length();
	
	/* function to set a vector from 2 points. This vector will be set to equal
	to vector AB */
	void setDiff(Point3D A, Point3D B);
	
	/* function to re-length the vector to 1, with the same direction */
	void normalize(); 
	
	/* calculate the dot product of this vector and other vector */
	float dot(Vector3D _other); 
	
	/* calculate the cross product of this vector and other vector */
	Vector3D cross(Vector3D _other); 
};

#endif
