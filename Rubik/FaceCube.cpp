/**
 * This file implements all methods of class FaceCube which was specified in 
 * file FaceCube.h 
 **/

#include "FaceCube.h"

FaceCube::FaceCube() 
{
	vertex[0].set(0.0, 0.0, 0.0);
	vertex[1].set(0.0, 0.0, 0.0);
	vertex[2].set(0.0, 0.0, 0.0);
	vertex[3].set(0.0, 0.0, 0.0);
	center.set(0.0, 0.0, 0.0);
}

FaceCube::FaceCube(Point3D _ver0, Point3D _ver1, Point3D _ver2, Point3D _ver3, GLuint _textureId)
{
	set(_ver0, _ver1, _ver2, _ver3, _textureId);
}

void FaceCube::set(const FaceCube& f)
{
	set(f.vertex[0], f.vertex[1], f.vertex[2], f.vertex[3], f.textureId);
}


void FaceCube::set(Point3D _ver0, Point3D _ver1, Point3D _ver2, Point3D _ver3, GLuint _textureId)
{
	vertex[0].set(_ver0);
	vertex[1].set(_ver1);
	vertex[2].set(_ver2);
	vertex[3].set(_ver3);
	
	float cenX = (vertex[0].getX() + vertex[1].getX() + vertex[2].getX() + vertex[3].getX())/4;
	float cenY = (vertex[0].getY() + vertex[1].getY() + vertex[2].getY() + vertex[3].getY())/4;
	float cenZ = (vertex[0].getZ() + vertex[1].getZ() + vertex[2].getZ() + vertex[3].getZ())/4;
	
	center.set(cenX, cenY, cenZ);
	
	textureId = _textureId;
}

void FaceCube::draw()
{
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
   	
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(vertex[0].getX(), vertex[0].getY(), vertex[0].getZ());
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(vertex[1].getX(), vertex[1].getY(), vertex[1].getZ());
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(vertex[2].getX(), vertex[2].getY(), vertex[2].getZ());
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(vertex[3].getX(), vertex[3].getY(), vertex[3].getZ());
    glEnd();
}

void FaceCube::rotate(Vector3D u, float angle)
{
	vertex[0].rotate(u.getX(), u.getY(), u.getZ(), angle);
	vertex[1].rotate(u.getX(), u.getY(), u.getZ(), angle);
	vertex[2].rotate(u.getX(), u.getY(), u.getZ(), angle);
	vertex[3].rotate(u.getX(), u.getY(), u.getZ(), angle);
	center.rotate(u.getX(), u.getY(), u.getZ(), angle);
}

Point3D FaceCube::getCenter()
{
	return center;
}

