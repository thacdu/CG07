#ifndef _POINT3D_H_
#define _POINT3D_H_

/**
 * This class defines a point in the 3-D world coordinates system.
 * The main basic method of this point is rotating about a vector with given 
 * angle.
 **/

class Point3D
{
private:
	float x, y, z;	// the ordinates in the 3-D coordinate

public:
	/* constructors */
	Point3D();	
	Point3D(float _x, float _y, float _z);
	Point3D(const Point3D& _other_point);
	
	/* destructor */
	~Point3D();
	
	/* setter */
	void set(float _x, float _y, float _z);
	void set(const Point3D& _other_point);
	
	/* getters */
	float getX();
	float getY();
	float getZ();
	
	/**
	 *	This function rotate this point about vector u(ux, uy, uz) with the 
	 * 	angle "angle". 
	 **/
	void rotate(float ux, float uy, float uz, float angle);
};

#endif
