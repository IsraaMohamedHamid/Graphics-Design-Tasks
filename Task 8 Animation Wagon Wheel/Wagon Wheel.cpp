#include <GL\glew.h>
#include <GL\freeglut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;
const double PI = 3.141592654;
GLsizei winWidth = 500, winHeight = 500; // Initial display window size.
GLuint regCircle; // Define name for display list.
static GLfloat rotTheta = 0.0;

class scrPt {
public:
    GLint x, y;
};

void DrawWagonWheel(void)
{
    scrPt circleVertex;
    GLfloat k;

    glClearColor(1.0, 1.0, 1.0, 0.0);
    regCircle = glGenLists(1);
    glNewList(regCircle, GL_COMPILE);

    /* Draw the outer fill of the big circle. */
    glBegin(GL_POLYGON);
    glColor3f(0.75, 0.75, 0.75);
    for (k = 0; k < 180; k += 0.001) { //Big Circle, radius 100, position 150
        circleVertex.x = 100 * cos(k);
        circleVertex.y = 100 * sin(k);
        glVertex2i(circleVertex.x, circleVertex.y);
    }
    glEnd();
    /* Draw the outer outline of the big circle. */
    glBegin(GL_LINES);
    glColor3f(0.25, 0.25, 0.25);
    for (k = 0; k < 180; k += 0.001) { //Big Circle, radius 100, position 150
        circleVertex.x = 100 * cos(k);
        circleVertex.y = 100 * sin(k);
        glVertex2i(circleVertex.x, circleVertex.y);
    }
    glEnd();
    /* Draw the inner fill of the white circle to cover the rest og the grey circle. */
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (k = 0; k < 180; k += 0.001) { //Small Circle, radius 10, position 150
        circleVertex.x = 80 * cos(k);
        circleVertex.y = 80 * sin(k);
        glVertex2i(circleVertex.x, circleVertex.y);
    }
    glEnd();

    /*DRAW THE LINES FOR THE WHEEL*/
    {
    glBegin(GL_LINES);//Up
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(3, 0);
    glVertex2d(+3, 80);
    glVertex2f(-3, 0);
    glVertex2d(-3, 80);
    glEnd();
    
    glColor3f(0.45, 0.45, 0.45);
    glBegin(GL_POLYGON);//Up
    glVertex2f(-3, 0);
    glVertex2f(3, 0);
    glVertex2d(+3, 80);
    glVertex2d(-3, 80);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);//Down
    glVertex2f(3, 0);
    glVertex2d(+3, -80);
    glVertex2f(-3, 0);
    glVertex2d(-3, -80);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//Down
    glVertex2f(-3, 0);
    glVertex2f(3, 0);
    glVertex2d(+3, -80);
    glVertex2d(-3, -80);
    glEnd();

    glBegin(GL_LINES);//Left
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0, 3);
    glVertex2d(-80, +3);
    glVertex2f(0, -3);
    glVertex2d(-80, -3);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//Left
    glVertex2f(0, -3);
    glVertex2f(0, 3);
    glVertex2d(-80, +3);
    glVertex2d(-80, -3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);//Right
    glVertex2f(0, 3);
    glVertex2d(80, +3);
    glVertex2f(0, -3);
    glVertex2d(80, -3);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//Right
    glVertex2f(0, -3);
    glVertex2f(0, 3);
    glVertex2d(80 ,+3);
    glVertex2d(80,-3);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//Left-Up
    glVertex2f(-4, 0);
    glVertex2f(0, 4);
    glVertex2d(-80 * cos(TWO_PI / 8), 4 + 80 * sin(TWO_PI / 8)); 
    glVertex2d(-4 - 80 * cos(TWO_PI / 8), 80 * sin(TWO_PI / 8));
    glEnd();

    glBegin(GL_LINES);//Left-Up
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-4, 0);
    glVertex2d(-4 - 80 * cos(TWO_PI / 8), 80 * sin(TWO_PI / 8));
    glVertex2f(0, 4);
    glVertex2d(-80 * cos(TWO_PI / 8), 4 + 80 * sin(TWO_PI / 8));
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//Left-Down
    glVertex2f(-4, 0);
    glVertex2f(0, -4);
    glVertex2d(-80 * cos(TWO_PI / 8), -4 - 80 * sin(TWO_PI / 8));
    glVertex2d(-4 - 80 * cos(TWO_PI / 8), -80 * sin(TWO_PI / 8));
    glEnd();

    glBegin(GL_LINES);//Left-Down
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-4, 0);
    glVertex2d(-4 - 80 * cos(TWO_PI / 8), -80 * sin(TWO_PI / 8));
    glVertex2f(0, -4);
    glVertex2d(-80 * cos(TWO_PI / 8), -4 - 80 * sin(TWO_PI / 8));
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//Right-Up
    glVertex2f(4, 0);
    glVertex2f(0, 4);
    glVertex2d(80 * cos(TWO_PI / 8), 4 + 80 * sin(TWO_PI / 8));
    glVertex2d(4 + 80 * cos(TWO_PI / 8), 80 * sin(TWO_PI / 8));
    glEnd();

    glBegin(GL_LINES);//Right-Up
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(4, 0);
    glVertex2d(4 + 80 * cos(TWO_PI / 8), 80 * sin(TWO_PI / 8));
    glVertex2f(0, 4);
    glVertex2d(80 * cos(TWO_PI / 8), 4 + 80 * sin(TWO_PI / 8));
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//Right-Down
    glVertex2f(4, 0);
    glVertex2f(0, -4);
    glVertex2d(80 * cos(TWO_PI / 8), -4 - 80 * sin(TWO_PI / 8));
    glVertex2d(4 + 80 * cos(TWO_PI / 8), -80 * sin(TWO_PI / 8));
    glEnd();

    glBegin(GL_LINES);//Right-Down
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(4, 0);
    glVertex2d(4 + 80 * cos(TWO_PI / 8), -80 * sin(TWO_PI / 8));
    glVertex2f(0, -4);
    glVertex2d(80 * cos(TWO_PI / 8), -4 - 80 * sin(TWO_PI / 8));
    glEnd();
    }
    /* Draw the inner outline of the big circle. */
    glBegin(GL_LINES);
    glColor3f(0.25, 0.25, 0.25);
    for (k = 0; k < 180; k += 0.001) { //Small Circle, radius 80, position 150
        circleVertex.x = 80 * cos(k);
        circleVertex.y = 80 * sin(k);
        glVertex2i(circleVertex.x, circleVertex.y);
    }
    glEnd();
    /* Draw the outline of the small circle. */
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.25, 0.25, 0.25);
    for (k = 0; k < 180; k += 0.001) { //Small Circle, radius 10, position 150
        circleVertex.x = 10 * cos(k);
        circleVertex.y = 10 * sin(k);
        glVertex2i(circleVertex.x, circleVertex.y);
    }
    glEnd();
    glLineWidth(1);
    /* Draw the fill of the small white circle. */
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (k = 0; k < 180; k += 0.001) { //Small Circle, radius 10, position 150
        circleVertex.x = 10 * cos(k);
        circleVertex.y = 10 * sin(k);
        glVertex2i(circleVertex.x, circleVertex.y);
    }
    glEnd();

    glEndList();
    glFlush();

}




void displayCircle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotTheta, 0.0, 0.0, 1.0);
    glCallList(regCircle);
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}
void displayCircle1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotTheta, 0.0, 0.0, -1.0);
    glCallList(regCircle);
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}
void rotateCircle(void)
{
    rotTheta += 3.0;
    if (rotTheta > 360.0)
        rotTheta -= 360.0;
    glutPostRedisplay();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
    glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -320.0, 320.0); //TO REDUCE OR INCREASE SCREEN SIZE
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
}
void winReshapeFcn1(GLint newWidth, GLint newHeight)
{
    glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600.0, 600.0, -600.0, 600); //TO REDUCE OR INCREASE SCREEN SIZE
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
}
void mouseFcn(GLint button, GLint action, GLint x, GLint y)
{
    switch (button) {
    case GLUT_LEFT_BUTTON: // Start the rotation.
        if (action == GLUT_DOWN)
            glutIdleFunc(rotateCircle);
        break;
    case GLUT_RIGHT_BUTTON: // Stop the rotation.
        if (action == GLUT_DOWN)
            glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Wagon Wheel counter clockwise rotation on the center");
    DrawWagonWheel();
    glutDisplayFunc(displayCircle);
    glutReshapeFunc(winReshapeFcn);
    glutMouseFunc(mouseFcn);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Wagon Wheel clockwise rotation on the center");
    DrawWagonWheel();
    glutDisplayFunc(displayCircle1);
    glutReshapeFunc(winReshapeFcn);
    glutMouseFunc(mouseFcn);
    glutMainLoop();
    return 0;
}