// ----------------------------------------------------------------------------------------------------
// 
// 	File name: main.cpp
//	Created By: Haard Panchal
//	Create Date: 10/22/19
//
//	Description:
//		The main file, called at starting of the program. Handles initializing the OpenGL environment.
//
//	History:
//		10/22/19: H. Panchal used template given with the OpenGL dependencies.
//		10/24/19: F. Quek Tested and Reviewed Code.
//      10/24/19: H. Panchal Switched to a modular version of the code. Separated class into definition and declaration.
//		10/28/19: H. Panchal Tested the game.
//      10/28/19: H. Panchal Added condition to test number of arguments.
//
// ----------------------------------------------------------------------------------------------------

// Include the necessary libraries
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
#include <chrono>

// Include the custom classes
#include "Game.h"

// Use the standard namespace
using namespace std;

/* Used to initialize the OpenGL environment.*/
void init(int w_width, int w_height)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, w_width - 1, w_height - 1, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}


/* Sets the global idle callback to be func so a GLUT program can perform backgrond processing tasks or continuous animation*/
void animateScene() {
	glutSwapBuffers();
	glutPostRedisplay(); //Calls for a scene to be redrawn.

}

// Globally initialising the static variable to NULL.
Game * Game::current_instance = NULL;

/*  Function: main

	Parses the argument list. Initializes the Game object. Initializes OpenGL environment.

	Parameters:

		int argc: Number of arguments
		char *argv[]: List of the arguments
	
	Return:
		int: 0 if successful
*/
int main(int argc, char *argv[])
{
    if(argc < 11) {
        cout<<"Wrong number of arguments!"<<endl;
		cout<<"Expected number of argrments: 10"<<endl;
        return 0;
    }
    
	//Convert the arguments of type char[] to integer.
    int screen_size_x = atoi(argv[1]); //atoi converts to integer
    int screen_size_y = atoi(argv[2]);
    float col_r = atof(argv[3]); //atof converts to float
    float col_g = atof(argv[4]);
    float col_b = atof(argv[5]);
    int radius = atoi(argv[6]);
    int ini_x = atoi(argv[7]);
    int ini_y = atoi(argv[8]);
    int angle = atoi(argv[9]);
    int speed = atoi(argv[10]);

	// Initialize the Game object
    Game g = Game(ini_x, ini_y, angle, speed, radius, col_r, col_g, col_b, screen_size_x, screen_size_y);

	glutInit(&argc, argv); // Used to initialize the GLUT library.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Sets the initial display mode.
	glutInitWindowSize(g.getWindowWidth(), g.getWindowHeight()); // Sets the initial window size.
	glutInitWindowPosition(100, 100); // Sets the initial window position.
	glutCreateWindow("Assignment 2: Bouncing Ball"); //Creates a toplevel window.
	init(g.getWindowWidth(), g.getWindowHeight());
	
	// Calling static function display from class Game
	glutDisplayFunc(Game::display); // Sets the function used for display callback for the current window.
	
	glutIdleFunc(animateScene); //Sets the function used for global idle callback.
	glutMainLoop(); // Used to enter the event processing loop

	return 0;
}
