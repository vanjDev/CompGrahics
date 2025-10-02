#include <GL/glut.h>

void road() {
    // Road base
    glColor3f(0.2f, 0.2f, 0.2f); 
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f( 1.0f, -0.6f);
        glVertex2f(-1.0f, -0.6f);
    glEnd();

    // Road borders
    glColor3f(1.0f, 0.0f, 0.0f); // red borders
    glBegin(GL_LINES);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f(-1.0f, -0.6f);
        glVertex2f( 1.0f, -0.6f);
    glEnd();

    // Road stripes using lines
    glColor3f(1.0f, 1.0f, 1.0f);
    float startX = -1.0f;
    while (startX < 1.0f) {
        glBegin(GL_LINES);
            glVertex2f(startX, -0.5f);
            glVertex2f(startX + 0.1f, -0.5f);
        glEnd();
        startX += 0.2f;
    }
}

void house() {
    // House body
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.4f);
        glVertex2f( 0.3f, -0.4f);
        glVertex2f( 0.3f,  0.1f);
        glVertex2f(-0.3f,  0.1f);
    glEnd();

    // Border for house
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.3f, -0.4f);
        glVertex2f( 0.3f, -0.4f);
        glVertex2f( 0.3f,  0.1f);
        glVertex2f(-0.3f,  0.1f);
    glEnd();

    // Roof (pink)
    glColor3f(0.9f, 0.2f, 0.5f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.4f, 0.1f);
        glVertex2f( 0.4f, 0.1f);
        glVertex2f( 0.0f, 0.4f);
    glEnd();

    // Roof border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.4f, 0.1f);
        glVertex2f( 0.4f, 0.1f);
        glVertex2f( 0.0f, 0.4f);
    glEnd();

    // Door (light pink)
    glColor3f(1.0f, 0.6f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.4f);
        glVertex2f( 0.05f, -0.4f);
        glVertex2f( 0.05f, -0.1f);
        glVertex2f(-0.05f, -0.1f);
    glEnd();

    // Door border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.05f, -0.4f);
        glVertex2f( 0.05f, -0.4f);
        glVertex2f( 0.05f, -0.1f);
        glVertex2f(-0.05f, -0.1f);
    glEnd();
}

void tree() {
    // Trunk
    glColor3f(0.5f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.6f, -0.4f);
        glVertex2f(0.6f, -0.1f);
        glVertex2f(0.5f, -0.1f);
    glEnd();

    // Leaves (pentagon)
    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.45f, -0.1f);
        glVertex2f(0.65f, -0.1f);
        glVertex2f(0.7f, 0.1f);
        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.4f, 0.1f);
    glEnd();

    // Leaves border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.45f, -0.1f);
        glVertex2f(0.65f, -0.1f);
        glVertex2f(0.7f, 0.1f);
        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.4f, 0.1f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    road();
    house();
    tree();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("House with Road and Tree");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}