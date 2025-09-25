#include <GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5.0f);
	glBegin(GL_LINES);

	glVertex2f(0.0f, 0.8f); glVertex2f(-0.8f, -0.4f);
	glVertex2f(0.0f, 0.8f); glVertex2f(0.8f, -0.4f);
	glVertex2f(-0.8f, -0.4f); glVertex2f(0.8f, -0.4f);

	glVertex2f(0.0f, -0.8f); glVertex2f(0.8f, 0.4f);
	glVertex2f(0.0f, -0.8f); glVertex2f(-0.8f, 0.4f);
	glVertex2f(0.8f, 0.4f); glVertex2f(-0.8f, 0.4f);

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Labaratory 3");
	glutInitWindowSize(1200, 1200);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
