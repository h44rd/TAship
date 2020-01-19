// ----------------------------------------------------------------------------------------------------
// 
// 	File name: Game.cpp
//	Created By: Haard Panchal
//	Create Date: 10/26/19
//
//	Description:
//		Class implementation for Game class code. 
//      The Game class handles the game mechanics, the general attributes of the game and the object involved.
//
//	History:
//		10/24/19: H. Panchal Created the class.
//      10/26/19: H. Panchal Added colon constructors and tested.
//		10/28/19: H. Panchal Created and Tested collision handlers.
//      10/28/19: H. Panchal Moved collisionDetection to display function from update function.
//
//  Declaration:
//      Game.h
//
// ----------------------------------------------------------------------------------------------------

// Including the declarations from the headerfile.
#include "Game.h"

/*  Constructor: Game
    Class : Game

    Default Constructor for class Game.

    Parameters:

        None

    Returns:

        Class object
*/
Game::Game () {}

/*  Constructor: Game
    Class : Game

    Implementation of the main constructor. Initializes the Ball and the Wall objects giving them appropriate 
    positions on the screen. It also makes the current_instance pointer point to it's own instance.

    Parameters:

        float x: Initial x coordinate of the center of the Ball.
        float y: Initial y coordinate of the center of the Ball.
        loat angle: The angle from the x axis in clockwise direction which direction of the path.
        float speed: The speed of the ball.
        float radius: The radius of the ball.
        float c_red: The red component of the ball color.
        float c_green: The green component of the ball color.
        float c_blue: The blue component of the ball color.
        int w_height: Height of the window.
        int w_width: Width of the window.

    Returns:

        Class object
*/
Game::Game(float x, float y, float angle, float speed, float radius, float c_red, float c_green, float c_blue, int w_height, int w_width) 
: m_window_height(w_height), m_window_width(w_width) {
    m_ball = Ball(x, y, angle, speed, radius, c_red, c_green, c_blue);

    // Wall objects are organized in an array.
    // Each object can be accessed based on the type of wall it is.

    // (x1, y1) o-----------------.
    //          |                 |  
    //          |                 |
    //          `-----------------o (x2, y2)

    // (x1, y1) and (x2, y2) are given values based on the wall's position and it's height and width.

    // For example:
    // Top Wall:
    //
    //   (0, 0) o-----------------.
    //          |                 |  
    //          |                 |
    //          `-----------------o (window_width, window_height * 0.1)

    m_walls[__GlobalConstant__LeftWall__] = Wall(0, 0, m_window_width * 0.1, m_window_height, __GlobalConstant__LeftWall__);
    m_walls[__GlobalConstant__TopWall__] = Wall(0, 0, m_window_width, m_window_height * 0.1, __GlobalConstant__TopWall__);
    m_walls[__GlobalConstant__RightWall__] = Wall(m_window_width * 0.9, 0, m_window_width, m_window_height, __GlobalConstant__RightWall__);
    m_walls[__GlobalConstant__BottomWall__] = Wall(0, m_window_height * 0.9, m_window_width, m_window_height, __GlobalConstant__BottomWall__);

    // Making current_instance point to the "this" instance of the class.
    // "this" is a keyword and each class instance will have a copy of "this" pointer which points to it's own address.
    // Note: The Game class has only one instance throughout.
    current_instance = this;
}

/*  Member Function: update
    Class : Game

    Updates the position of all the Game objects.

    Parameters:

        void

    Returns:

        void

    Warning:

        The functions does NOT check for any collisions. Use it with care. 
*/
void Game::update() {
    m_ball.update(); // Calls update on the Ball as it is the only object which is moving.
}

/*  Member Function: draw
    Class : Game

    Draws all the Game objects on the window.

    Parameters:

        void

    Returns:

        void
*/
void Game::draw() {
    m_ball.draw(); // Calls draw function

    for(int i = 0; i < __GlobalConstant__NumberOfWalls__; i++) { // Iterates through all the walls in the array and calls draw.
        m_walls[i].draw();
    }
}

/*  Member Function: display
    Class : Game

    The static callback function which will be called every frame. Contains the update, draw and detectCollision function.

    Parameters:

        void

    Returns:

        void
    
    Warning:

        It is a static function. It is not possible to use non-static member variables of parameters in the function.
        Hence, a static class Game pointer is used.

*/
void Game::display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen to draw updated frame.
    current_instance->update(); 
    current_instance->draw();
    current_instance->collisionDetection(); // The function is called AFTER the update and draw function to make the 
                                            // the bounce transition look smoother. Also, the tentative values of the ball can be used to detect collision.
}

/*  Member Function: getWindowWidth
    Class : Game

    Returns the width of the window.

    Parameters:

        void

    Returns:

        int window_width
*/
int Game::getWindowWidth() {
    return m_window_width;
}

/*  Member Function: getWindowHeight
    Class : Game

    Returns the height of the window.

    Parameters:

        void

    Returns:

        int window_height
*/
int Game::getWindowHeight() {
    return m_window_height;
}


/*  Member Function: collisionDetection
    Class : Game

    The function iterates through the wall array, checking if the ball collides with any of them. 
    If the collision of the ball is detected, the collision handler of the ball is called with 
    the appropriate wall_id and boundaries.

    Parameters:

        void

    Returns:

        void
*/
void Game::collisionDetection() {
    for(int i = 0; i < __GlobalConstant__NumberOfWalls__; i++) { // Iterate through every wall
        if(m_walls[i].detectCollision(m_ball) == true) { // Check with each wall if the Ball if colliding or not
            // If any wall detects a collision, the collision handler of the ball is called.
            m_ball.ifCollidedWall(m_walls[i].getId(), m_walls[i].getLeftBoundary(), m_walls[i].getTopBoundary(), m_walls[i].getRightBoundary(), m_walls[i].getBottomBoundary());
        }
    }
}