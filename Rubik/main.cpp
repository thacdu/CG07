#include <iostream>
#include <fstream>
#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Point3D.h"
#include "Vector3D.h"
#include "Image.h"
#include "FaceCube.h"
#include "SolidCube.h"
#include "Rubik.h"
#include "Camera.h"

using namespace std;

/* this counter is used to count the number of time sub-rotation. It insures 
that each rotation is exact 90 degree */
int num = 0;

/* this function is used to prevent other rotation to be executed when have 
a rotation are being in rotating */
bool isRotating = false;	

/* the unique camera of the program */
Camera myCam;

/* the unique our Rubik */
Rubik myRubik;

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    	
   	glEnable(GL_DEPTH_TEST);
   	glClearColor(0.0f,0.0f,0.0f,1.0f);
 	
   	myRubik.draw();
 	 
    	glFlush();
    	glutSwapBuffers();
}

void rotate_counter_clockwise(int value)
{
	myRubik.rotate(value, 1.5);
	glutPostRedisplay();
	if (num < 59) {
		glutTimerFunc(1, rotate_counter_clockwise, value);
		num++;
	} else {
		isRotating = false;
		num = 0;
	}
}

void rotate_clockwise(int value)
{
	myRubik.rotate(value, -1.5);
	glutPostRedisplay();
	if (num < 59) {
		glutTimerFunc(1, rotate_clockwise, value);
		num++;
	} else {
		num = 0;
		isRotating = false;
	}
}

void myKeyboard(unsigned char key,int x,int y)
{
    	switch(key)
    	{
        	case 27:
        		exit(0);
        		break;
        	
        	case 'r':
        		if (isRotating == false) {
			  		glutTimerFunc(1, rotate_counter_clockwise, RED);
			  		isRotating = true;
		  		}
        		break;
        	
        	case 'R':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_clockwise, RED);
        			isRotating = true;
		  		}
        		break;
        		
        	case 'g':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_counter_clockwise, GREEN);
        			isRotating = true;
		  		}
        		break;
        	
        	case 'G':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_clockwise, GREEN);
        			isRotating = true;
		  		}
        		break;
        		
        	case 'w':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_counter_clockwise, WHITE);
        			isRotating = true;
		  		}
        		break;
        	
        	case 'W':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_clockwise, WHITE);
        			isRotating = true;
		  		}
        		break;
        		
        	case 'o':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_counter_clockwise, ORANGE);
        			isRotating = true;
		  		}
        		break;
        	
        	case 'O':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_clockwise, ORANGE);
        			isRotating = true;
		  		}
        		break;
        		
        	case 'b':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_counter_clockwise, BLUE);
        			isRotating = true;
		  		}
        		break;
        	
        	case 'B':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_clockwise, BLUE);
        			isRotating = true;
		  		}
        		break;
        		
        	case 'y':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_counter_clockwise, YELLOW);
        			isRotating = true;
		  		}
        		break;
        	
        	case 'Y':
        		if (isRotating == false) {
        			glutTimerFunc(1, rotate_clockwise, YELLOW);
        			isRotating = true;
		  		}
        		break;
        	
        	
        	case '+': myCam.slide(0, 0, -0.2); break;
        	case '-': myCam.slide(0, 0, 0.2); break;
        	case 'c': myCam.rotate_clockwise(5.0); break;
        	case 'v': myCam.rotate_clockwise(-5.0); break;
    	}
    	
    	glutPostRedisplay(); // draws it again
}

void mySpecial(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_RIGHT: myCam.right(-5.0); break;
		case GLUT_KEY_LEFT: myCam.right(5.0); break;		
		case GLUT_KEY_UP: myCam.up(5.0); break;
		case GLUT_KEY_DOWN: myCam.up(-5.0); break;
	}
	
	glutPostRedisplay();
}



int main(int argc, char** argv)
{
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700,700);

    glutCreateWindow("Rubik");
    glutDisplayFunc(myDisplay);
   	glutKeyboardFunc(myKeyboard);
   	glutSpecialFunc(mySpecial);
	
    myRubik.reset();
 	myCam.set(7.0, 7.0, 7.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 	myCam.setShape(45.0f, 1.0, 0.1f, 50.0f);

    glutMainLoop();
 
	return 0;
}

