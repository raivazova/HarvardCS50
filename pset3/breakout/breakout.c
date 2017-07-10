//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400
#define padHEIGHT 10
#define padWIDTH 60

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
GLabel initLive(GWindow window);

void updateScoreboard(GWindow window, GLabel label, int points);
void updateLive(GWindow window, GLabel live, int lives);

GObject detectCollision(GWindow window, GOval ball);

int main(int argc, char* argv[])
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);
    
    // instantiate scoreboard
    initScoreboard(window);
    
    // instantiate liveLost
    initLive(window);
    
    

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);
    
    // instantiate lives
    GLabel live = initLive(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // a label for the live counter
    GLabel livesLeft = newGLabel("LIVES :");
    setFont(livesLeft, "SansSerif-36");
    setColor(livesLeft, "BLACK");
    setLocation(livesLeft, (getWidth(window) / 2) - getWidth(livesLeft), 40);
    add(window, livesLeft);
    
    
    double velocity = drand48();
    double xVelocity = 0;
    if(velocity < 0.5)
    {
        xVelocity = 2.5;
    }
    else
    {
        xVelocity = velocity * 3.5;
    }
    
    double yVelocity = xVelocity * 1.2;
    
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        
        if(argc == 2 && strcmp(argv[1], "GOD") == 0)
        {
            double x = getX(ball);
            double y = 530;
            setLocation(paddle, x, y);
        }
        
        
        GObject object = detectCollision(window, ball);
        if(object == paddle)
        {
            yVelocity = -yVelocity;
        }
        else if(object != NULL && object != label && object != livesLeft && object != live)
        {
            removeGWindow(window, object);
       
            xVelocity = xVelocity + 0.03 ;
            yVelocity = -yVelocity + 0.03;  
            points++;
            bricks--;
        }
        // updating the score
        updateScoreboard(window, label, points);
        
          
           
            
        // move circle along x and y-axis
        move(ball, xVelocity, yVelocity);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            xVelocity = -xVelocity;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
           xVelocity = -xVelocity;
        }
        // loose a point if reaches bottom edge
        else if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            lives--;
                
            
            setLocation(ball,WIDTH / 2 - RADIUS, HEIGHT / 2 - RADIUS);
            // pause unless game over
            if(lives != 0)
            {
                waitForClick();
            }
            xVelocity = -xVelocity;
        }
       
        
        // bounce off upper edge
        else if (getY(ball) <= 0)
        {
            yVelocity = -yVelocity;
        }
        
        
        // updating the lives
        updateLive(window,live,lives);
        
        // linger before moving again
        pause(10);
        
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows top cursor
                double x = getX(event) - getWidth(paddle) / 2;
                double y = 530;
                setLocation(paddle, x, y);
            }
        }
    }
    if(bricks == 0)
    {
        removeGWindow(window, label);
        GLabel win = newGLabel("YOU WIN !");
        setFont(win, "SansSerif-36");
        setColor(win, "BLACK");
        double a = (getWidth(window) - getWidth(win)) / 2;
        double b = (getHeight(window) - getHeight(win)) / 2;
        setLocation(win, a, b);
        add(window, win);
    }
    if(lives == 0)
    {
        removeGWindow(window, label);
        GLabel youLost = newGLabel("YOU LOST !");
        setFont(youLost, "SansSerif-36");
        setColor(youLost, "RED");
        double a = (getWidth(window) - getWidth(youLost)) / 2;
        double b = (getHeight(window) - getHeight(youLost)) / 2;
        setLocation(youLost, a, b);
        add(window, youLost);
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
    
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    int yPos = 80;
    
    for(int i = 0; i < ROWS; i++)
    {
        int xPos = 2;
                      
        for(int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect(xPos, yPos, 35, 20);
            setFilled(brick, true);
            if(i == 0)
            {
                setColor(brick, "CYAN");
            }
            if(i == 1)
            {
                setColor(brick, "LIGHT_GRAY");
            }
            if(i == 2)
            {
                setColor(brick, "PINK");
            }
            if(i == 3)
            {
                setColor(brick, "GREEN");
            }
            if(i == 4)
            {
                setColor(brick, "BLUE");
            }
            
            add(window, brick);
             
            
            xPos = xPos + 40;
            
        }
        yPos = yPos + 25;
    }
};

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH / 2 - RADIUS, HEIGHT / 2 - RADIUS, RADIUS * 2, RADIUS * 2);
    setFilled(ball, true);
    setColor(ball, "GRAY");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(170, 530, padWIDTH, padHEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "MAGENTA");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}
/**
 * Instantiates, configures, and returns label for lives.
 */
GLabel initLive(GWindow window)
{
    GLabel live = newGLabel("");
    setFont(live, "SansSerif-36");
    setColor(live, "BLACK");
    add(window, live);
    return live;
}

/**
 * Updates live's label, keeping it centered in window.
 */
void updateLive(GWindow window, GLabel live, int lives)
{
    // update label
    char s[12];
    sprintf(s, "    %i", lives);
    setLabel(live, s);

    // center label in window
    double x = getWidth(window) / 2;
    double y = 40;
    setLocation(live, x, y);
}





/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
