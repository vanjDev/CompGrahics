#include <GL/glut.h>

void road() {
	glColor3f(0.5, 0.0, 0.0);
	glLineWidth(4.0f);
	glBegin(GL_LINES);
	glVertex2f(-0.8f, -0.6f); glVertex2f(0.8f, -0.6f); // Bottom
	glVertex2f(-0.8f, -0.4f); glVertex2f(0.8f, -0.4f); // Top
	glEnd();
	
	// RoadLines
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xFF00);
	glBegin(GL_LINES);
	glVertex2f(-0.8f, -0.5f); glVertex2f(0.8f, -0.5f);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}

void House() {
	// Walls
	glColor3f(1.0, 1.0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-0.3, -0.3); 
	glVertex2f(0.3, -0.3);
	glVertex2f(0.3, 0.3); 
	glVertex2f(-0.3, 0.3);
	glEnd();

	// Border
	glLineWidth(2.0f);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.3, -0.3);
	glVertex2f(0.3, -0.3);
	glVertex2f(0.3, 0.3);
	glVertex2f(-0.3, 0.3);
	glEnd();

	// Roof
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.4, 0.3); glVertex2f(0.4, 0.3);
	glVertex2f(0.0, 0.55);
	glEnd();

	// Door
	glColor3f(0.0, 0.5, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(0.05, -0.3);
	glVertex2f(-0.05, -0.3);
	glVertex2f(-0.05, 0.0);
	glVertex2f(0.05, 0.0);
	glEnd();

	// Border
	glColor3f(0.4, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.05, -0.3);
	glVertex2f(-0.05, -0.3);
	glVertex2f(-0.05, 0.0);
	glVertex2f(0.05, 0.0);
	glEnd();
}

void Tree() {
	//Trunk
	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(0.5, -0.3);
	glVertex2f(0.55, -0.3);
	glVertex2f(0.55, 0.4);
	glVertex2f(0.5, 0.4);
	glEnd();

	// Leaves
	glColor3f(0.0, 0.6, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.45, 0.2);
	glVertex2f(0.6, 0.2);
	glVertex2f(0.65, 0.45);
	glVertex2f(0.525, 0.55);
	glVertex2f(0.4, 0.45);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	House();
	Tree();
	glFlush();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Labaratory 5");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
