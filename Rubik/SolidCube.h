#ifndef _SOLIDCUBE_H_
#define _SOLIDCUBE_H_

/** 
 * This class defines a small cube. It is specified by 6 FaceCubes and a center
 **/
 
#include "Point3D.h"
#include "Vector3D.h"
#include "FaceCube.h"

class SolidCube
{
private:
	FaceCube face[6];
	Point3D center;
	
public:
	/* constructors */
	SolidCube();
	SolidCube(FaceCube f0, FaceCube f1, FaceCube f2, FaceCube f3, FaceCube f4, FaceCube f5);
	
	/* setters */
	void set(FaceCube f0, FaceCube f1, FaceCube f2, FaceCube f3, FaceCube f4, FaceCube f5);
	void set(const SolidCube& cube);
	
	/* function to draw a SolidCube in OpenGL */
	void draw();
	
	/* function to rotate this SolidCube about vector u with given angle */
	void rotate(Vector3D u, float angle);
	
	/* return the center of the cube */
	Point3D getCenter();
};

#endif
