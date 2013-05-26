#ifndef _RUBIK_H_
#define _RUBIK_H_

/**
 * This class defines a Rubik. It is specified by 27 cubes
 **/

#include "SolidCube.h"
#include "Image.h"

/* define the const for only convinient */
const int RED = 22;
const int GREEN = 16;
const int WHITE = 14;
const int ORANGE = 4;
const int BLUE = 10;
const int YELLOW = 12;

class Rubik
{
private:
	SolidCube cube[27];
	
	/* The function to bind a image with an number */
	GLuint loadTexture(Image* image);
	
public:
	/* constructor */
	Rubik();
	
	/* set the initial Rubik */
	void reset();
	
	/* function to draw the Rubik in OpenGL */
	void draw();
	
	/* function to rotate a face of a Rubik with given angle */
	void rotate(int face, float angle);
};

#endif
