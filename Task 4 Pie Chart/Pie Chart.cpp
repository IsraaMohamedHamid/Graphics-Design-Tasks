#include <stdlib.h>
#include <math.h>
#include <GL\glew.h>
#include <GL\freeglut.h>


#include <iostream>

typedef struct
{
    float x;
    float y;
}SCREENPT;

SCREENPT circle;

void createcircle(GLint k, GLint r, GLint h) {
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.25, 0.25);       //  Set circle color to blue.
    for (int i = 0; i < 180; i++)
    {
        circle.x = r * cos(i) - h;
        circle.y = r * sin(i) + k;
        glVertex3f(circle.x + k, circle.y - h, 0);

        circle.x = r * cos(i + 0.1) - h;
        circle.y = r * sin(i + 0.1) + k;
        glVertex3f(circle.x + k, circle.y - h, 0);
    }
    glEnd();
}

/*void Drawlines(void) { 

    SCREENPT piept;
    
    GLint x = 0;
    GLint r = 1;
    GLint y = 0;
    for (int i = 0; i < 360; i=i+30)
    {
        piept.x = r * cos(i) + x;
        piept.y = r * sin(i) + y;

        glBegin(GL_LINES);
        glColor3ub(i, i,i);
        glVertex2f(0, 0);
        glVertex2f(piept.x , piept.y);
        glEnd();
    }
   

}*/

void Drawlines(void) {
    //glClear(GL_COLOR_BUFFER_BIT);
    createcircle(1, 1, 1);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 1.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);

    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-1.0, 0.0);

    glColor3f(0.98, 0.625, 0.12);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.7, 0.7);

    glColor3f(0.98, 0.04, 0.7);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.7, -0.7);

    glColor3f(0.6, 0.4, 0.7);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.7, 0.7);

    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.7, -0.7);


    glEnd();
}
void displayFcn(void)
{
    glClear(GL_COLOR_BUFFER_BIT);   //  Clear display window.

    //displayMe();
    Drawlines();
    
    glFlush();
}

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(500, 500);                    // window size
    glutInitWindowPosition(10, 10);                // distance from the top-left screen
    glutCreateWindow("This is a pie chart");    // message displayed on top bar window

    //myinit();
    glutDisplayFunc(displayFcn);
    glutMainLoop();
    return 0;
}