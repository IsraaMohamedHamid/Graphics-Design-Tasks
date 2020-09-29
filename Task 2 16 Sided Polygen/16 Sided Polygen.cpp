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
    glVertex2f(-0.75, 0.0); //a
    glVertex2f(-0.693, 0.287); //b
    glVertex2f(-0.497, 0.546); //c
    glVertex2f(-0.287, 0.693); //d
    
    glVertex2f(0.0, 0.75); //e
    glVertex2f(0.287, 0.693); //f
    glVertex2f(0.497, 0.546); //g
    glVertex2f(0.693, 0.287); //h
    
    glVertex2f(0.75, 0.0); //i
    glVertex2f(0.693, -0.287); //l
    glVertex2f(0.497, -0.546); //k
    glVertex2f(0.287, -0.693); //j
    
    glVertex2f(0.0, -0.75); //m
    glVertex2f(-0.287, -0.693); //n
    glVertex2f(-0.497, -0.546); //o
    glVertex2f(-0.693, -0.287); //p
   
    glEnd();
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);                    // window size
    glutInitWindowPosition(10, 10);                // distance from the top-left screen
    glutCreateWindow("This is a 16 side polygen");    // message displayed on top bar window
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}