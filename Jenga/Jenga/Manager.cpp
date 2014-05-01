#include "Manager.h"
#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

int window;

double rotate_y=0; 
double rotate_x=0;

Manager::Manager(void)
{
}

Manager::~Manager(void)
{
}

void idle (void)
{
    //  Call display function (draw the current frame)
    glutPostRedisplay();
}

// used to draw/redraw the window
void display(void)
{
	glutSetWindow(window);  // main window
	
// clear all pixels in the buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//Resets transformations
	glLoadIdentity();

	// Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

//  drawing code goes here
	/*glBegin(GL_LINE);
	glVertex3f(-1,-.125,.25);
	glVertex3f(1,-.125,1);
	glVertex3f(-1,.125,1);
	glVertex3f(1,.125,1);
	glVertex3f(-1,.125,-1);
	glVertex3f(1,.125,-1);
	glVertex3f(-1,-.125,-1);
	glVertex3f(1,.125,-1);
	glEnd();*/

	// White side - BACK
glBegin(GL_POLYGON);
glColor3f(   1.0,  1.0, 1.0 );
glVertex3f(  0.15, -0.125, 0.5 );
glVertex3f(  0.15,  0.125, 0.5 );
glVertex3f( -0.15,  0.125, 0.5 );
glVertex3f( -0.15, -0.125, 0.5 );
glEnd();
 
// Purple side - RIGHT
glBegin(GL_POLYGON);
glColor3f(  1.0,  0.0,  1.0 );
glVertex3f( 0.15, -0.125, -0.5 );
glVertex3f( 0.15,  0.125, -0.5 );
glVertex3f( 0.15,  0.125,  0.5 );
glVertex3f( 0.15, -0.125,  0.5 );
glEnd();
 
// Green side - LEFT
glBegin(GL_POLYGON);
glColor3f(   0.0,  1.0,  0.0 );
glVertex3f( -0.15, -0.125,  0.5 );
glVertex3f( -0.15,  0.125,  0.5 );
glVertex3f( -0.15,  0.125, -0.5 );
glVertex3f( -0.15, -0.125, -0.5 );
glEnd();
 
// Blue side - TOP
glBegin(GL_POLYGON);
glColor3f(   0.0,  0.0,  1.0 );
glVertex3f(  0.15,  0.125,  0.5 );
glVertex3f(  0.15,  0.125, -0.5 );
glVertex3f( -0.15,  0.125, -0.5 );
glVertex3f( -0.15,  0.125,  0.5 );
glEnd();
 
// Red side - BOTTOM
glBegin(GL_POLYGON);
glColor3f(   1.0,  0.0,  0.0 );
glVertex3f(  0.15, -0.125, -0.5 );
glVertex3f(  0.15, -0.125,  0.5 );
glVertex3f( -0.15, -0.125,  0.5 );
glVertex3f( -0.15, -0.125, -0.5 );
glEnd();

// Yellow side - FRONT
glBegin(GL_POLYGON);
glColor3f( 1.0, 1.0, 0.0 );
glVertex3f( -0.15, 0.125, -0.5 );
glVertex3f( -0.15, -0.125, -0.5 );
glVertex3f( 0.15, -0.125, -0.5 );
glVertex3f( 0.15, 0.125, -0.5 );
glEnd();

//  start processing buffered OpenGL routines 
    glutSwapBuffers();
}

void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

void init (void) 
{
//  select clearing (background) color
//	yup - it's cornflower blue
    glClearColor (0.0, 0.0, 0.0, 1.0);
	
// initialize viewing values - projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
// orthographic projection
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

/* 
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
	// initialize GLUT using command line arguments
    glutInit(&argc, argv);

	// tell it to use double buffering, and RGB color
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

	// 700 by 700 pixels for window
    glutInitWindowSize(700, 700); 

	// offset by 50 pixels in x and y direction from origin
	// of the screen - upper left corner
    glutInitWindowPosition(50, 50);

	// create window with given title displayed
    window = glutCreateWindow ("Jenga");  // change string for a new title

	glEnable(GL_DEPTH_TEST);

	// our initialization function from above
    init();

	// callback for display - gets called whenever window needs to be redisplayed
    glutDisplayFunc(display); 
	
	// additional callbacks
	glutSpecialFunc(specialKeys);

	glutIdleFunc(idle); // call if nothing else is going on

	// event handling loop - keeps program from exiting after
	// doing all of the above work
    glutMainLoop();
    return 0;   
}