// Animates a square using OpenGL

// Requires freeglut
// In Ubuntu setup with:
// sudo apt-install -y freeglut3-dev mesa-common-dev libglew-dev libglm-dev

// Compile with: 
// g++ animateSquare.cpp  -o animateSquare -lGL -lglut

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <chrono>
#include <thread>

// Draws the square on a specific position with a specified width
void square(GLfloat positionx, GLfloat positiony, GLfloat width)
{
    glBegin(GL_POLYGON);
    glVertex3f(positionx, positiony, 0);
    glVertex3f(positionx + width, positiony, 0.0);
    glVertex3f(positionx + width, positiony + width, 0.0);
    glVertex3f(positionx, positiony+width, 0.0);
    glEnd();
}

// The initial position of the top left corner of the square on x axis
GLfloat positionx = -0.5;

// Used to display the square as part of the main loop of the application
void render()
{
    // Clear the view
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render the square
    square(positionx, positionx, 0.2);

    // Increase the position so that the square moves on the next loop
    positionx += 0.1;

    glutSwapBuffers();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

int main(int argc, char **argv)
{
    // Initialize and show the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1024, 800);
    glutCreateWindow("Basic Window");

    // Tell Glut what to use to display and to refresh the screen
    // In our case it's the same function for both
    glutDisplayFunc(render);
    glutIdleFunc(render);

    // start the main loop
    glutMainLoop();

    return 1;
}
