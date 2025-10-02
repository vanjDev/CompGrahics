// ===== Ground (only bottom area for grass) =====
void ground() {
    glColor3f(0.0f, 0.7f, 0.2f); // Grass green
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.6f);
        glVertex2f(-1.0f, -0.6f);
    glEnd();
}

// ===== Road (above ground) =====
void road() {
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray asphalt
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.6f);
        glVertex2f( 1.0f, -0.6f);
        glVertex2f( 1.0f, -0.3f);
        glVertex2f(-1.0f, -0.3f);
    glEnd();

    // Road borders (white lines at edges)
    glLineWidth(2.5f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, -0.6f); glVertex2f(1.0f, -0.6f); // bottom edge
        glVertex2f(-1.0f, -0.3f); glVertex2f(1.0f, -0.3f); // top edge
    glEnd();

    // Center dashed line
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, -0.45f);
        glVertex2f( 1.0f, -0.45f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}