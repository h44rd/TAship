// ----------------------------------------------------------------------------------------------------
// 
// 	File name: Game.h
//	Created By: Haard Panchal
//	Create Date: 10/26/19
//
//	Description:
//		Class declaration for Game class code. 
//      The Game class handles the game mechanics, the general attributes of the game and the object involved.
//
//	History:
//		10/24/19: H. Panchal Created the class.
//      10/26/19: H. Panchal Created static display function and static pointer to the class.
//		10/28/19: H. Panchal Created const variables.
//
//  Implementation and details:
//      Game.cpp
//
// ----------------------------------------------------------------------------------------------------

// #include guards to ensure each headerfile is include only once.
#ifndef GAME_H
#define GAME_H

// Including the Ball and the Wall headerfiles. 
#include "Ball.h"
#include "Wall.h"

// Including the OpenGL headerfiles.
#include <GL/glut.h>
#include <GL/gl.h>

class Game {
    private:

    // Declaring the wall and ball objects.
    Wall m_walls[4];
    Ball m_ball;

    // A static pointer that points to an instance/object of the Game class. To be used in the static function.
    static Game * current_instance;
    
    // The window height and width.
    int m_window_height;
    int m_window_width;

    // The following constants should not be changed and are assumed to be true throughout the program.
    // They are used to identify each wall.
    const int __GlobalConstant__LeftWall__ = 0; // The Left wall is assigned the interger 0.
    const int __GlobalConstant__TopWall__ = 1; // The Top wall is assigned the interger 1.
    const int __GlobalConstant__RightWall__ = 2; // The Right wall is assigned the interger 2.
    const int __GlobalConstant__BottomWall__ = 3; // The Bottom wall is assigned the interger 3.
    const int __GlobalConstant__NumberOfWalls__ = 4; // The total number of the walls is 4.

    public:

    Game(); // Default constructor

    // Constructor that initializes the game components. 
    Game(float x, float y, float angle, float speed, float radius, float c_red, float c_green, float c_blue, int w_height, int w_width);

    // Update all the moving parts.
    void update();

    // Draws all the game components
    void draw();

    // Static function that is used as a callback to the glutDisplayFunc in main.cpp
    static void display();

    // Returns the width of the window.
    int getWindowWidth();

    // Returns the Height of the window.
    int getWindowHeight();

    // Handles the collisions between the objects.
    void collisionDetection();
};

#endif