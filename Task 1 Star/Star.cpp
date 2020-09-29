#include <GL\glew.h>
#include <GL\freeglut.h>

/*
* glVertex2f(float x, float y){.
* The point (0.0, 0.0) represents the middle of the window (not the top left corner).
* The "2f" suffix means 2 values of float type (x and y).
*/

void displayMe(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 0.5);                  
    glVertex2f(-0.4,-0.2);               
    glVertex2f(0.5, 0.25);
    glVertex2f(-0.5, 0.25);
    glVertex2f(0.4, -0.2); 
    glEnd();
    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);                    // window size
    glutInitWindowPosition(10, 10);                // distance from the top-left screen
    glutCreateWindow("This is a star");    // message displayed on top bar window
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}