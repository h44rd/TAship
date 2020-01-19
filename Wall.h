// ----------------------------------------------------------------------------------------------------
// 
// 	File name: Wall.h
//	Created By: Haard Panchal
//	Create Date: 10/26/19
//
//	Description:
//		Class declaration for Wall class code for walls that the ball can collide with. 
//
//	History:
//		10/26/19: H. Panchal Created the file with basic functions 
//      10/27/19: H. Panchal Created Boundary functions and moved the detectCollision to Wall.h
//		10/28/19: H. Panchal Changed const variables to static const
//
//  Implementation and details:
//      Wall.cpp
//
// ----------------------------------------------------------------------------------------------------

// #include guards to ensure each headerfile is include only once.
#ifndef WALL_H
#define WALL_H

// Including the Ball class. To be used in the detectCollision
#include "Ball.h"

class Wall {
    private:
    // Variables which define the position of the rectangular Wall.
    // m_x1, m_y1: x and y coordinates of the TOP LEFT vertex of the rectangle.
    // m_x2, m_y2: x and y coordinates of the BOTTOM RIGHT vertex of the rectangle.
    int m_x1, m_y1, m_x2, m_y2;

    // The following constants should not be changed and are assumed to be true throughout the program.
    // They are used to identify each wall.
    static const int __GlobalConstant__LeftWall__ = 0; // The Left wall is assigned the interger 0.
    static const int __GlobalConstant__TopWall__ = 1; // The Top wall is assigned the interger 1.
    static const int __GlobalConstant__RightWall__ = 2; // The Right wall is assigned the interger 2.
    static const int __GlobalConstant__BottomWall__ = 3; // The Bottom wall is assigned the interger 3.
    static const int __GlobalConstant__NumberOfWalls__ = 4; // The total number of the walls is 4.
 
    int m_wall_id; // The type of Wall based on the definition above. Defines whether the wall is either of: Left, Top, Right, Bottom.

    public:
    Wall(); // Default constructor

    // Constructor initializes a Wall object based on the position and type of the wall.
    Wall(int x1, int y1, int x2, int y2, int wall_id); 

    // Draw the wall on the screen.
    void draw();

    // Detect of the Ball collides with the wall.
    bool detectCollision(Ball b);

    // Returns the type of Wall
    int getId();

    
    int getLeftBoundary(); // Returns the Left boundary of the wall

    int getTopBoundary(); // Returns the Right boundary of the wall

    int getRightBoundary(); // Returns the Bottom doundary of the wall

    int getBottomBoundary(); // Returns the Bottom doundary of the wall
};

#endif