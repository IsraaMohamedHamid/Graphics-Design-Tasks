#include <GL\glew.h>
#include <GL\freeglut.h>

/*
* glVertex2f(float x, float y){.
* The point (0.0, 0.0) represents the middle of the window (not the top left corner).
* The "2f" suffix means 2 values of float type (x and y).
*/

void displayMe(void) {
    
    glClear(GL_COLOR_BUFFER_BIT);

    
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 255);
    glVertex2f(1, 0.0); //a
    glVertex2f(0.5, 0.866025); //b
    
    //glColor3ub(0, 255, 0);
    glVertex2f(-0.5, 0.866025); //c
    glVertex2f(-1, 0.0); //d

    //glColor3ub(255, 0, 0);
    glVertex2f(-0.5, -0.866025); //e
    glVertex2f(0.5, -0.866025); //f

    //glColor3f(1, 1, 1);
   
    glEnd();
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);                    // window size
    glutInitWindowPosition(10, 10);                // distance from the top-left screen
    glutCreateWindow("This is a hexagon");    // message displayed on top bar window
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}