#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(4.0f);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xFF00);

	glBegin(GL_LINES);

	glVertex2f(0.0f, 0.8f); glVertex2f(-0.8f, -0.4f);
	glVertex2f(0.0f, 0.8f); glVertex2f(0.8f, -0.4f);
	glVertex2f(-0.8f, -0.4f); glVertex2f(0.8f, -0.4f);

	glVertex2f(0.0f, -0.8f); glVertex2f(0.8f, 0.4f);
	glVertex2f(0.0f, -0.8f); glVertex2f(-0.8f, 0.4f);
	glVertex2f(0.8f, 0.4f); glVertex2f(-0.8f, 0.4f);

	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Labaratory 3");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
