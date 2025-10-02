#include <GL/glut.h>
#include <cmath>

// ===== Sky with Gradient =====
void drawSkyGradient() {
    glBegin(GL_QUADS);
        // Top sky (darker blue)
        glColor3f(0.2f, 0.6f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f( 1.0f, 1.0f);

        // Near horizon (lighter)
        glColor3f(0.7f, 0.9f, 1.0f);
        glVertex2f( 1.0f, -0.2f);
        glVertex2f(-1.0f, -0.2f);
    glEnd();
}

// ===== Ground (Grass) =====
void drawGround() {
    glColor3f(0.0f, 0.7f, 0.2f); // bright green grass
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f( 1.0f, -0.2f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();
}

// ===== Clouds =====
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= 100; i++) {
            float angle = i * 2.0f * 3.14159f / 100;
            glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
        }
    glEnd();
}

void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f); // white
    drawCircle(x, y, 0.1f);
    drawCircle(x + 0.12f, y + 0.05f, 0.12f);
    drawCircle(x + 0.25f, y, 0.1f);
    drawCircle(x + 0.12f, y - 0.05f, 0.1f);
}

// ===== Road =====
void road() {
    // Asphalt road (dark gray)
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-0.8f, -0.6f);
        glVertex2f( 0.8f, -0.6f);
        glVertex2f( 0.8f, -0.4f);
        glVertex2f(-0.8f, -0.4f);
    glEnd();

    // Road border (white lines at edges)
    glLineWidth(3.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.8f, -0.6f); glVertex2f(0.8f, -0.6f); // bottom
        glVertex2f(-0.8f, -0.4f); glVertex2f(0.8f, -0.4f); // top
    glEnd();

    // Middle dashed line
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.8f, -0.5f);
        glVertex2f( 0.8f, -0.5f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

// ===== House =====
void House() {
    // Walls
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.3f);
        glVertex2f( 0.3f, -0.3f);
        glVertex2f( 0.3f,  0.3f);
        glVertex2f(-0.3f,  0.3f);
    glEnd();

    // Border
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.3f, -0.3f);
        glVertex2f( 0.3f, -0.3f);
        glVertex2f( 0.3f,  0.3f);
        glVertex2f(-0.3f,  0.3f);
    glEnd();

    // Roof
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.4f, 0.3f);
        glVertex2f( 0.4f, 0.3f);
        glVertex2f( 0.0f, 0.55f);
    glEnd();

    // Door
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.3f);
        glVertex2f( 0.05f, -0.3f);
        glVertex2f( 0.05f,  0.0f);
        glVertex2f(-0.05f,  0.0f);
    glEnd();

    // Door border
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.05f, -0.3f);
        glVertex2f( 0.05f, -0.3f);
        glVertex2f( 0.05f,  0.0f);
        glVertex2f(-0.05f,  0.0f);
    glEnd();
}

// ===== Tree =====
void Tree() {
    // Trunk
    glColor3f(0.5f, 0.25f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.5f, -0.3f);
        glVertex2f(0.55f, -0.3f);
        glVertex2f(0.55f,  0.2f);
        glVertex2f(0.5f,  0.2f);
    glEnd();

    // Leaves
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.45f, 0.2f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.65f, 0.45f);
        glVertex2f(0.525f, 0.55f);
        glVertex2f(0.4f, 0.45f);
    glEnd();
}

// ===== Display =====
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSkyGradient();
    drawGround();
    road();
    House();
    Tree();

    // Clouds
    drawCloud(-0.8f, 0.8f);
    drawCloud(0.0f, 0.85f);
    drawCloud(0.6f, 0.75f);

    glFlush();
}

// ===== Init =====
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
    glutCreateWindow("Laboratory 5 - House Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
