// ----------------------------------------------------------------------------------------------------
// 
// 	File name: Wall.cpp
//	Created By: Haard Panchal
//	Create Date: 10/26/19
//
//	Description:
//		Class implementation for Wall class code. 
//
//	History:
//		10/24/19: H. Panchal Created the class.
//      10/26/19: H. Panchal Moved collision detection from Game class to Wall class
//		10/28/19: H. Panchal Documented 
//
//  Declaration:
//      Wall.h
//
// ----------------------------------------------------------------------------------------------------

// Including the declarations from the headerfile. 
#include "Wall.h"
#include "Ball.h"

// Including other necessary libraries.
#include <GL/glut.h>
#include <GL/gl.h>

/*  Constructor: Wall
    Class : Wall

    Default Constructor for class Wall.

    Parameters:

        None

    Returns:

        Class object
*/
Wall::Wall() {}

/*  Constructor: Wall
    Class : Wall

    Implemenation of the main constructor. Assigns the position of the wall, it's height and width using the given format:

       (x1, y1) o-----------------.
                |                 |  
                |                 |
                `-----------------o (x2, y2)

    Also assigns the type of Wall to the object.

    Parameters:

        int x1: Top left point
        int y1: Top left point
        int x2: Bottom Right point
        int y2: Bottom Right point
        int wall_id: The type of the wall
        
    Returns:

        Class object
*/
Wall::Wall(int x1, int y1, int x2, int y2, int wall_id)
:m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_wall_id(wall_id) {}

/*  Member Function: draw
    Class : Wall

    Based on the given coordinates (x1, y1) and (x2, y2), the function defines vertices to 
    draw the quadrilateral.

       (x1, y1) o-----------------. (x2, y1)
                |                 |  
                |                 |
       (x1, y2) `-----------------o (x2, y2)

    Parameters:

        None

    Returns:

        None
*/
void Wall::draw() {
    glColor3f(1, 0.5, 0); // Assign the color
    glBegin(GL_QUADS); // Initiate drawing quadrilateral

    // Define vertices in clockwise direction
    glVertex2f(m_x1, m_y1); // Define first vertex
    glVertex2f(m_x2, m_y1);
    glVertex2f(m_x2, m_y2);
    glVertex2f(m_x1, m_y2);
    glEnd(); // End drawing quadrilateral
}

/*  Member Function: detectCollision
    Class : Wall

    Detects whether the ball collides with the Wall by checking if the boundary of the Ball crosses the boundary of the wall.
 
    Parameters:

        Ball ball: The Ball Object

    Returns:

        bool ifCollisionDetected: True if a collision is detected
                                  False if there is no collision with the wall
*/
bool Wall::detectCollision(Ball ball) {

    if(m_wall_id == __GlobalConstant__LeftWall__) { // Checks for the Wall type to detect the specific type of collision
        if(ball.getLeftBoundary() < m_x2) { // Checking if the boundary of the ball crosses the wall's boundaries
                                            // Here, the boundaries is defined by the coordinate x2.
            return true; // Return true if boundaries cross
        }
        else {
            return false; // Return false if boundaries do not cross
        }
    }

    if(m_wall_id == __GlobalConstant__RightWall__) {
        if(ball.getRightBoundary() > m_x1) {
            return true;
        }
        else {
            return false;
        }
    }

    if(m_wall_id == __GlobalConstant__TopWall__) {
        if(ball.getTopBoundary() < m_y2) {
            return true;
        }
        else {
            return false;
        }
    }

    if(m_wall_id == __GlobalConstant__BottomWall__) {
        if(ball.getBottomBoundary() > m_y1) {
            return true;
        }
        else {
            return false;
        }
    }

}

/*  Member Function: getId
    Class : Wall

    Returns the ID(type) of the wall.  
 
    Parameters:

        void

    Returns:

        int m_wall_id
*/
int Wall::getId() {
    return m_wall_id;
}

/*  Member Function: getLeftBoundary
    Class : Wall

    Returns the left boundary of the wall. From the figure, it is easy to see the left boundary
    is the x1 coordinate.  
 
    Parameters:

        void

    Returns:

        int leftBoundary
*/
int Wall::getLeftBoundary() {
    return m_x1;
}

/*  Member Function: getTopBoundary
    Class : Wall

    Returns the Top boundary of the wall.
 
    Parameters:

        void

    Returns:

        int topBoundary
*/
int Wall::getTopBoundary() {
    return m_y1;
}

/*  Member Function: getRightBoundary
    Class : Wall

    Returns the Right boundary of the wall.
 
    Parameters:

        void

    Returns:

        int rightBoundary
*/
int Wall::getRightBoundary() {
    return m_x2;
}

/*  Member Function: getBottomBoundary
    Class : Wall

    Returns the bottom boundary of the wall.
 
    Parameters:

        void

    Returns:

        int bottomBoundary
*/
int Wall::getBottomBoundary() {
    return m_y2;
}