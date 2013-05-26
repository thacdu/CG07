#ifndef _FACECUBE_H_
#define _FACECUBE_H_

/**
 * This class defines a face of a small cube among 27 cubes of the Rubik 
 * A face cube is specified by 4 vertice and a colour.
 * The color of the face is made by texture the image on the plane 
 * identified by 4 vertice
 */
 
 #include <GL/gl.h>
 
 #include "Point3D.h"
 #include "Vector3D.h"

class FaceCube
{
private:
	/* 4 vertice of the face, also of a square */
	Point3D vertex[4];
	
	/* the id of the color image related to this face */
	GLuint textureId;
	
	/* the center of the face, used for further purpose */
	Point3D center;

public:
	/* constructors */
	FaceCube();
	FaceCube(Point3D _ver0, Point3D _ver1, Point3D _ver2, Point3D _ver3, GLuint _textureId);
	
	/* setters */
	void set(Point3D _ver0, Point3D _ver1, Point3D _ver2, Point3D _ver3, GLuint _textureId);
	void set(const FaceCube& f);
	
	/* function to draw this face in OpenGL */
	void draw();
	
	/* function to rotate this face about vector u with given angel */
	void rotate(Vector3D u, float angle);
	
	/* function to return the center of the face */
	Point3D getCenter();
};


#endif 
