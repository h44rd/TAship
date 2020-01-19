// ----------------------------------------------------------------------------------------------------
// 
// 	File name: Ball.h
//	Created By: Haard Panchal
//	Create Date: 10/26/19
//
//	Description:
//		Class declaration for Ball class code for bouncing ball. 
//
//	History:
//		10/24/19: F. Quek. Created and tested the Ball Constructor
//      10/27/19: H. Panchal Created undoUpdate and Boundary functions
//		10/28/19: H. Panchal. Changed const variables to static const
//
//  Implementation and details:
//      Ball.cpp
// ----------------------------------------------------------------------------------------------------

// #include guards to ensure each headerfile is include only once.
#ifndef BALL_H
#define BALL_H

class Ball {
    private:
    // The following are variables which pertain to the Ball class. The define the various attributes of the Ball.
    float m_x, m_y, m_angle, m_x_speed, m_y_speed, m_c_red, m_c_green, m_c_blue, m_radius;

    // The following constants should not be changed and are assumed to be true throughout the program.
    // They are used to identify each wall.
    static const int __GlobalConstant__LeftWall__ = 0; // The Left wall is assigned the interger 0.
    static const int __GlobalConstant__TopWall__ = 1; // The Top wall is assigned the interger 1.
    static const int __GlobalConstant__RightWall__ = 2; // The Right wall is assigned the interger 2.
    static const int __GlobalConstant__BottomWall__ = 3; // The Bottom wall is assigned the interger 3.
    static const int __GlobalConstant__NumberOfWalls__ = 4; // The total number of the walls is 4.

    public:

    Ball(); // Default constructor (Does not take any parameters)

    Ball(float x, float y, float angle, float speed, float radius, float c_red, float c_green, float c_blue); // Constructs/Initializes an object of the class Ball.

    void update(); // Updates the position of the Ball.

    void undoUpdate(); // Undo the previous update.

    void draw(); // Draws the ball.

    void ifCollidedWall(int wall_id, int wall_left_boundary, int wall_top_boundary, int wall_right_boundary, int wall_bottom_boundary); // Handles the collisions with the specified wall.

    float getLeftBoundary(); // Returns the Left boundary of the ball

    float getRightBoundary(); // Returns the Right boundary of the ball

    float getTopBoundary(); // Returns the Bottom doundary of the ball

    float getBottomBoundary(); // Returns the Bottom doundary of the ball
};

#endif