#include "Manager.h"
#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

int window;

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
    glClear(GL_COLOR_BUFFER_BIT);

//  drawing code goes here
	
//  start processing buffered OpenGL routines 
    glutSwapBuffers();
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
    glOrtho(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
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

	// our initialization function from above
    init();

	// callback for display - gets called whenever window needs to be redisplayed
    glutDisplayFunc(display); 

	// additional callbacks
	
	glutIdleFunc(idle); // call if nothing else is going on

	// event handling loop - keeps program from exiting after
	// doing all of the above work
    glutMainLoop();
    return 0;   
}