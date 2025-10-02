#include <GL/glut.h>

void road() {
    // Road base
    glColor3f(1.0f, 0.6f, 0.8f); // light pink
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f( 1.0f, -0.6f);
        glVertex2f(-1.0f, -0.6f);
    glEnd();

    // Road markings (dashed)
    glColor3f(1.0f, 0.9f, 0.95f); // pale pink stripes
    float startX = -1.0f;
    while (startX < 1.0f) {
        glBegin(GL_QUADS);
            glVertex2f(startX, -0.49f);
            glVertex2f(startX + 0.1f, -0.49f);
            glVertex2f(startX + 0.1f, -0.51f);
            glVertex2f(startX, -0.51f);
        glEnd();
        startX += 0.2f; // space between dashes
    }
}

void house() {
    // House body
    glColor3f(1.0f, 0.4f, 0.7f); // darker pink
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.4f);
        glVertex2f( 0.3f, -0.4f);
        glVertex2f( 0.3f,  0.1f);
        glVertex2f(-0.3f,  0.1f);
    glEnd();

    // Roof
    glColor3f(0.9f, 0.2f, 0.5f); // deep pink
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.4f, 0.1f);
        glVertex2f( 0.4f, 0.1f);
        glVertex2f( 0.0f, 0.4f);
    glEnd();

    // Door
    glColor3f(1.0f, 0.8f, 0.9f); // pale pink
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.4f);
        glVertex2f( 0.05f, -0.4f);
        glVertex2f( 0.05f, -0.1f);
        glVertex2f(-0.05f, -0.1f);
    glEnd();
}

void tree() {
    // Trunk
    glColor3f(0.7f, 0.3f, 0.5f); // muted pink
    glBegin(GL_QUADS);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.55f, -0.4f);
        glVertex2f(0.55f, -0.1f);
        glVertex2f(0.5f, -0.1f);
    glEnd();

    // Tree top
    glColor3f(1.0f, 0.5f, 0.7f); // bright pink
    glBegin(GL_POLYGON);
        glVertex2f(0.475f, -0.1f);
        glVertex2f(0.575f, -0.1f);
        glVertex2f(0.65f,  0.1f);
        glVertex2f(0.525f, 0.25f);
        glVertex2f(0.4f,   0.1f);
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
    glutCreateWindow("Pink Theme Scene");
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}