/**
 * This file implements all the methods of class Rubik that was defined in 
 * file "Rubik.h"
 **/

#include "Rubik.h"
#include "Image.h"

GLuint Rubik::loadTexture(Image* image) {
    	GLuint textureId;
    	glGenTextures(1, &textureId);
    	glBindTexture(GL_TEXTURE_2D, textureId);
    	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    	return textureId;
}

Rubik::Rubik(){
	reset();
}

void Rubik::reset() 
{
	Point3D p[4][4][4];
	FaceCube faceX[4][3][3], faceY[3][4][3], faceZ[3][3][4];
	
	GLuint white_textureId;
	GLuint red_textureId;
	GLuint blue_textureId;
	GLuint green_textureId;
	GLuint yellow_textureId;
	GLuint orange_textureId;
	GLuint gray_textureId;
	
	/* bind each color image with an id */
    Image* image = loadBMP("white.bmp");
    white_textureId = loadTexture(image);
    delete image;
    	
    Image* image1 = loadBMP("red.bmp");
    red_textureId = loadTexture(image1);
    delete image1;
 
    Image* image2 = loadBMP("blue.bmp");
 	blue_textureId = loadTexture(image2);
    delete image2;

 	Image* image3 = loadBMP("orange.bmp");
    orange_textureId = loadTexture(image3);
    delete image3;

    Image* image4 = loadBMP("green.bmp");
    green_textureId = loadTexture(image4);
    delete image4;

    Image* image5 = loadBMP("yellow.bmp");
    yellow_textureId = loadTexture(image5);
    delete image5;
    	
    Image* image6 = loadBMP("gray.bmp");
    gray_textureId = loadTexture(image6);
    delete image6;
    	
    /* initialize all point in the rubik */
  	for (int x = 0; x < 4; x++)
  		for (int y = 0; y < 4; y++)
  			for (int z = 0; z < 4; z++)
  				p[x][y][z].set((float)x - 1.5, (float)y - 1.5, (float)z - 1.5);
  				
  	/* initilize all FaceCube that perpendicular with x-axis */
  	for (int x = 0; x < 4; x++)
  		for (int y = 0; y < 3; y++)
  			for (int z = 0; z < 3; z++)
  				if (x == 0)
  					faceX[x][y][z].set(p[x][y][z], p[x][y+1][z], p[x][y+1][z+1], p[x][y][z+1], orange_textureId);
  				else if (x == 3)
  					faceX[x][y][z].set(p[x][y][z], p[x][y+1][z], p[x][y+1][z+1], p[x][y][z+1], red_textureId);
  				else
  					faceX[x][y][z].set(p[x][y][z], p[x][y+1][z], p[x][y+1][z+1], p[x][y][z+1], gray_textureId);
  					
  	/* initilize all FaceCube that perpendicular with y-axis */
  	for (int x = 0; x < 3; x++)
  		for (int y = 0; y < 4; y++)
  			for (int z = 0; z < 3; z++)
  				if (y == 0)
  					faceY[x][y][z].set(p[x][y][z], p[x][y][z+1], p[x+1][y][z+1], p[x+1][y][z], blue_textureId);
  				else if (y == 3)
  					faceY[x][y][z].set(p[x][y][z], p[x][y][z+1], p[x+1][y][z+1], p[x+1][y][z], green_textureId);
  				else
  					faceY[x][y][z].set(p[x][y][z], p[x][y][z+1], p[x+1][y][z+1], p[x+1][y][z], gray_textureId);
	
	/* initilize all FaceCube that perpendicular with z-axis */
	for (int x = 0; x < 3; x++)
  		for (int y = 0; y < 3; y++)
  			for (int z = 0; z < 4; z++)
  				if (z == 0)
  					faceZ[x][y][z].set(p[x][y][z], p[x][y+1][z], p[x+1][y+1][z], p[x+1][y][z], yellow_textureId);
  				else if (z == 3)
  					faceZ[x][y][z].set(p[x][y][z], p[x][y+1][z], p[x+1][y+1][z], p[x+1][y][z], white_textureId);
  				else
  					faceZ[x][y][z].set(p[x][y][z], p[x][y+1][z], p[x+1][y+1][z], p[x+1][y][z], gray_textureId);
    	
    	
    	
    /* inititalize 27 SolidCubes of the Rubik */
    for (int x = 0; x < 3; x++)
    	for (int y = 0; y < 3; y++)
    		for (int z = 0; z < 3; z++)
    			cube[9*x+3*y+z].set(faceX[x][y][z], faceX[x+1][y][z], faceY[x][y][z], faceY[x][y+1][z], faceZ[x][y][z], faceZ[x][y][z+1]);
    
}

void Rubik::draw()
{
	/* to draw Rubik we only need to call the functions to draw 27 cubes */
	for (int i = 0; i < 27; i++)
		cube[i].draw();
}

void Rubik::rotate(int face, float angle)
{
	Vector3D u;

	/* to rotate a face of Rubik, we only need to rotate 9 SolidCube of that face */
	if (face == RED) {
		u.set(1.0, 0.0, 0.0);
		for (int i = 0; i < 27; i++)
			if (cube[i].getCenter().getX() > 0.5)
				cube[i].rotate(u, angle);
	}
	
	if (face == GREEN) {
		u.set(0.0, 1.0, 0.0);
		for (int i = 0; i < 27; i++)
			if (cube[i].getCenter().getY() > 0.5)
				cube[i].rotate(u, angle);
	}
	
	if (face == WHITE) {
		u.set(0.0, 0.0, 1.0);
		for (int i = 0; i < 27; i++)
			if (cube[i].getCenter().getZ() > 0.5)
				cube[i].rotate(u, angle);
	}
	
	if (face == ORANGE) {
		u.set(-1.0, 0.0, 0.0);
		for (int i = 0; i < 27; i++)
			if (cube[i].getCenter().getX() < -0.5)
				cube[i].rotate(u, angle);
	}
	
	if (face == BLUE) {
		u.set(0.0, -1.0, 0.0);
		for (int i = 0; i < 27; i++)
			if (cube[i].getCenter().getY() < -0.5)
				cube[i].rotate(u, angle);
	}
	
	if (face == YELLOW) {
		u.set(0.0, 0.0, -1.0);
		for (int i = 0; i < 27; i++)
			if (cube[i].getCenter().getZ() < -0.5)
				cube[i].rotate(u, angle);
	}
}


