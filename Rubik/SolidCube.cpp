/**
 * This file implements all the methods of class SolidCube which is described 
 * in file "SolidCube.h"
 **/

#include "SolidCube.h"

SolidCube::SolidCube()
{
}

SolidCube::SolidCube(FaceCube f0, FaceCube f1, FaceCube f2, FaceCube f3, FaceCube f4, FaceCube f5)
{
	set(f0, f1, f2, f3, f4, f5);
}

void SolidCube::set(FaceCube f0, FaceCube f1, FaceCube f2, FaceCube f3, FaceCube f4, FaceCube f5)
{
	face[0].set(f0); Point3D p0 = f0.getCenter();
	face[1].set(f1); Point3D p1 = f1.getCenter();
	face[2].set(f2); Point3D p2 = f2.getCenter();
	face[3].set(f3); Point3D p3 = f3.getCenter();
	face[4].set(f4); Point3D p4 = f4.getCenter();
	face[5].set(f5); Point3D p5 = f5.getCenter();
	
	float cenx = (p0.getX() + p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX())/6;
	float ceny = (p0.getY() + p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY())/6;
	float cenz = (p0.getZ() + p1.getZ() + p2.getZ() + p3.getZ() + p4.getZ() + p5.getZ())/6;
	
	center.set(cenx, ceny, cenz);
}

void SolidCube::set(const SolidCube& cube)
{
	set(cube.face[0], cube.face[1], cube.face[2], cube.face[3], cube.face[4], cube.face[5]);
}

void SolidCube::draw()
{
	/* to draw the SolidCube we only need to call the functions to draw 6 faces
	of it */
	for (int i = 0; i < 6; i++) 
		face[i].draw();
}

void SolidCube::rotate(Vector3D u, float angle)
{
	/* to rotate the SolidCube we only need to call the functions to rotate 6
	faces of it */
	for (int i = 0; i < 6; i++)
		face[i].rotate(u, angle);
		
	/* rotate the center is required */
	center.rotate(u.getX(), u.getY(), u.getZ(), angle);
}

Point3D SolidCube::getCenter()
{
	return center;
}

