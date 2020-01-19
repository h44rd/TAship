// ----------------------------------------------------------------------------------------------------
// 
// 	File name: Ball.cpp
//	Created By: Haard Panchal
//	Create Date: 10/26/19
//
//	Description:
//		Class implementation for Ball class code. 
//
//	History:
//		10/24/19: H. Panchal Created the class.
//      10/26/19: H. Panchal Created static display function and static pointer to the class.
//		10/28/19: H. Panchal Created and Tested collision handlers.
//
//  Declaration:
//      Ball.h
//
// ----------------------------------------------------------------------------------------------------

// Including the declarations from the headerfile. 
#include "Ball.h"

// Including other necessary libraries.
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

/*  Constructor: Ball
    Class : Ball

    Default Constructor for class Ball.

    Parameters:

        None

    Returns:

        Class object
*/
Ball::Ball() {}

/*  Constructor: Ball
    Class : Ball

    Implementation of the main constructor. Initializes the object by placing the ball at the initial position
    and calculating the speed in x and y direction using angle and speed. 

    Parameters:

        float x: The x coordinate of the initial position of the Ball.
        float y: The y coordinate of the initial position of the Ball.
        float angle: The angle from the x axis in clockwise direction which direction of the path.
        float speed: The speed of the ball.
        float radius: The radius of the ball.
        float c_red: The red component of the ball color.
        float c_green: The green component of the ball color.
        float c_blue: The blue component of the ball color.

    Returns:

        Class object
*/
Ball::Ball(float x, float y, float angle, float speed, float radius, float c_red, float c_green, float c_blue) 
// Colon constructors used to avoid variable initialization overhead.
: m_x(x), m_y(y), m_radius(radius), m_c_red(c_red), m_c_green(c_green), m_c_blue(c_blue), m_angle(angle) {
    float angle_rad = m_angle * 3.141596 / 180.0; // Converts angle in degrees to radians.
    m_x_speed = speed * cos(angle_rad); // Calculating speed along the x axis from taking the horizontal component of the speed.
    m_y_speed = speed * sin(angle_rad); // Calculating speed along the y axis from taking the vertical component of the speed.
}

/*  Member Function: update
    Class : Ball

    Updates the position of the center of the Ball by adding the corresponding speeds in the x and y direction.

    Parameters:

        void

    Returns:

        void

    Warning:

        The functions does NOT check for any collisions. Use it with care. 
*/
void Ball::update() {
    m_x += m_x_speed;
    m_y += m_y_speed;
}

/*  Member Function: undoUpdate
    Class : Ball

    Undo the update to the position of the center of the Ball by subtracting the corresponding speeds in the x and y direction.
    Places the ball in it's previous position.

    Parameters:

        void

    Returns:

        void

    Warning:

        The function will ONLY undo the basic update function. Will not place the ball correctly if the ball has gone through a collision.   
*/
void Ball::undoUpdate() {
    m_x -= m_x_speed;
    m_y -= m_y_speed;
}

/*  Member Function: draw
    Class : Ball

    Constructs a circle with triangles which are drawn around the center.

    Parameters:

        void

    Returns:

        void

*/
void Ball::draw() {
    int num_segments = 20; // number of segments(triangles) in the circle.

    glColor3f(m_c_red, m_c_green, m_c_blue); // Set the color of the ball.
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // get the current angle

        float t_x = m_radius * cosf(theta); // calculate the x component
        float t_y = m_radius * sinf(theta); // calculate the y component

        glVertex2f(t_x + m_x, t_y + m_y); // output vertex

    }
    glEnd();
}

/*  Member Function: ifCollidedWall
    Class : Ball

    Handles the collision with walls. Updates the speed and position of the Ball based on the given wall_id.

    Logic:
        Once the collision with Wall wall_id is detected, the function first brings the ball back to the previous 
        position. It can be assumed that the ball was not colliding with the wall then.

        The position of the center is then changed to it's reflection on the axis perpendicular to the major axis of 
        the wall by adding twice the amount of speed which corresponds to the major axis of the wall.

        Major Axis: If the wall is vertical, it is the y axis.
                    If the wall is horizontal, it is the x axis.

    IMP: Called only AFTER collision is detected with the Wall of type wall_id. 

    Parameters:

        int wall_id: The type of the wall that the ball collides with.
        int wall_left_boundary: The left boundary of the wall
        int wall_top_boundary: The top boundary of the wall
        int wall_right_boundary: The right boundary of the wall
        int wall_bottom_boundary: The bottom boundary of the wall

    Returns:

        void

*/
void Ball::ifCollidedWall(int wall_id, int wall_left_boundary, int wall_top_boundary, int wall_right_boundary, int wall_bottom_boundary) {

    undoUpdate();

    if (wall_id == __GlobalConstant__LeftWall__) { // If the ball is colliding with the left wall (vertical)
        m_x_speed = -1 * m_x_speed; // Updates the speed in x direction to move the ball in the opposing direction.
        
        m_y += 1 * m_y_speed; // Reflects along the x axis.
    }

    if (wall_id == __GlobalConstant__TopWall__) { // If the ball is colliding with the Top wall (horizontal)
        m_y_speed = -1 * m_y_speed; // Updates the speed in y direction to move the ball in the opposing direction.
        
        m_x += 1 * m_x_speed; // Reflects along the x axis.
    }

    if (wall_id == __GlobalConstant__RightWall__) {
        m_x_speed = -1 * m_x_speed;
        
        m_y += 1 * m_y_speed;
    }

    if (wall_id == __GlobalConstant__BottomWall__) {
        m_y_speed = -1 * m_y_speed;
        
        m_x += 1 * m_x_speed;
    }
}


/*  Member Function: getLeftBoundary
    Class : Ball

    Returns the left boundary of the ball.
    Calculated by subtracting the radius from the x coordinate of the center of the ball.

    Parameters:

        void

    Returns:

        float leftBoundary

*/
float Ball::getLeftBoundary() {
    return m_x - m_radius; // Subtracting the from the x coordinate to give the left boundary.
}

/*  Member Function: getRightBoundary
    Class : Ball

    Returns the Right boundary of the ball.
    Calculated by adding the radius to the x coordinate of the center of the ball.

    Parameters:

        void

    Returns:

        float rightBoundary

*/
float Ball::getRightBoundary() {
    return m_x + m_radius; // Adding radius to the x coor
}

/*  Member Function: getTopBoundary
    Class : Ball

    Returns the Top boundary of the ball.
    Calculated by subtracting the radius from the y coordinate of the center of the ball.

    Parameters:

        void

    Returns:

        float topBoundary

*/
float Ball::getTopBoundary() {
    return m_y - m_radius;
}

/*  Member Function: getBottomBoundary
    Class : Ball

    Returns the Bottom boundary of the ball.
    Calculated by adding the radius to the y coordinate of the center of the ball.

    Parameters:

        void

    Returns:

        float topBoundary

*/
float Ball::getBottomBoundary() {
    return m_y + m_radius;
}