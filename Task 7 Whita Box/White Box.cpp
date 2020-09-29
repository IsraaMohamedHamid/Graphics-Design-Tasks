#include <GL\glew.h>
#include <GL\freeglut.h>
#include <math.h>
#include <stdlib.h>

/*  Set initial display-window size. */
GLsizei winWidth = 600, winHeight = 600;

/*  Set range for world coordinates.  */
GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;

class wcPt2D {
public:
	GLfloat x, y;
};

typedef GLfloat Matrix3x3[3][3];

Matrix3x3 matComposite;

const GLdouble pi = 3.14159;
int frameNumber = 0;

void drawsquare() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-2.5, 0);
	glVertex2f(2.5, 0);
	glVertex2f(2.5, 5);
	glVertex2f(-2.5, 5);
	glEnd();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glLoadIdentity();

	/* Apply a translation to the square to make the square move horizontally. The amount
	 * of the translation depends on the frame number, which makes the square move from
	 * left to right across the screen as the animation progresses.  The square animation
	 * repeats every 300 frames.  At the beginning of the animation, the square is off
	 * the left edge of the screen. If we increase the frames then the square will go
	 *slower across the screen and vice versa.*/

	glPushMatrix();
	glTranslated(-1 + 13 * (frameNumber % 300) / 300.0, 0, 0);/*-1 refers to the starting position
	in which the square begins in. glTranslated(x,y,z)*/
	/*To move the box from right to left make the 13 positive and the -1 to +8*/
	glScaled(0.2, 0.2, 1); //To see the square better.
	drawsquare();
	glPopMatrix();

	glutSwapBuffers();
	/*glutSwapBuffers() is the GLUT function that instructs the computer that you are done
	/with the current frame and the buffers should be swapped*/
}


void doFrame(int v) {
	frameNumber++;
	glutPostRedisplay();
	glutTimerFunc(30, doFrame, 0);//The glutTimerFunc waits for a number of milliseconds to pass before calling the callback which is the matrix. 
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("A white box moving from left to right.");

	init();

	glutDisplayFunc(display);
	glutTimerFunc(200, doFrame, 0);
	glutMainLoop();
	return 0;
}