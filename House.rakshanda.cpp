#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

void display() {
    glClearColor(0.678f, 0.847f, 0.902f, 1.0f); // Sky blue
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // ?? Grass
    glColor3f(0.4f, 0.8f, 0.4f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(400, 0);
        glVertex2f(400, 100);
        glVertex2f(0, 100);
    glEnd();

    // ?? House Base
    glColor3f(1.0f, 0.937f, 0.835f); // Peach
    glBegin(GL_POLYGON);
        glVertex2f(120, 100);
        glVertex2f(280, 100);
        glVertex2f(280, 220);
        glVertex2f(120, 220);
    glEnd();

    // ?? Roof
    glColor3f(0.8f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
        glVertex2f(100, 220);
        glVertex2f(300, 220);
        glVertex2f(200, 310);
    glEnd();

    // ?? Door
    glColor3f(0.36f, 0.25f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(180, 100);
        glVertex2f(220, 100);
        glVertex2f(220, 170);
        glVertex2f(180, 170);
    glEnd();

    // ? Doorknob
    glColor3f(1.0f, 1.0f, 0.8f);
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex2f(215, 135);
    glEnd();

    // ?? Windows
    auto draw_window = [](float x, float y) {
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_POLYGON);
            glVertex2f(x - 2, y - 2);
            glVertex2f(x + 32, y - 2);
            glVertex2f(x + 32, y + 32);
            glVertex2f(x - 2, y + 32);
        glEnd();
        glColor3f(0.75f, 0.9f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + 30, y);
            glVertex2f(x + 30, y + 30);
            glVertex2f(x, y + 30);
        glEnd();
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
            glVertex2f(x + 15, y); glVertex2f(x + 15, y + 30);
            glVertex2f(x, y + 15); glVertex2f(x + 30, y + 15);
        glEnd();
    };
    draw_window(135, 170); // Left window
    draw_window(235, 170); // Right window

    // ?? Sun
    glColor3f(1.0f, 0.85f, 0.0f);
    float cx = 340, cy = 330, r = 25;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0f * 3.14159f * i / 100;
            glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
        }
    glEnd();

    // ?? Clouds
    auto draw_cloud = [](float x, float y) {
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < 3; ++i) {
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(x + i * 20, y);
                for (int j = 0; j <= 100; j++) {
                    float angle = 2.0f * 3.14159f * j / 100;
                    glVertex2f((x + i * 20) + cos(angle) * 15, y + sin(angle) * 15);
                }
            glEnd();
        }
    };
    draw_cloud(70, 340);   // Left cloud
    draw_cloud(230, 360);  // Right cloud

    // ?? Pine Tree (left side)
    glColor3f(0.36f, 0.25f, 0.2f); // Trunk
    glBegin(GL_POLYGON);
        glVertex2f(40, 100);
        glVertex2f(50, 100);
        glVertex2f(50, 140);
        glVertex2f(40, 140);
    glEnd();
    glColor3f(0.0f, 0.5f, 0.2f); // Pine leaves
    glBegin(GL_TRIANGLES);
        glVertex2f(30, 140); glVertex2f(60, 140); glVertex2f(45, 170);
        glVertex2f(32, 155); glVertex2f(58, 155); glVertex2f(45, 185);
        glVertex2f(34, 170); glVertex2f(56, 170); glVertex2f(45, 200);
    glEnd();

    // ?? Round Tree (right side)
    glColor3f(0.4f, 0.26f, 0.13f); // Trunk
    glBegin(GL_POLYGON);
        glVertex2f(320, 100);
        glVertex2f(335, 100);
        glVertex2f(335, 160);
        glVertex2f(320, 160);
    glEnd();
    glColor3f(0.0f, 0.6f, 0.2f); // Leaves
    float tx = 328, ty = 185, tr = 30;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(tx, ty);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0f * 3.14159f * i / 100;
            glVertex2f(tx + cos(angle) * tr, ty + sin(angle) * tr);
        }
    glEnd();

    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Improved 2D House with Trees and Clouds");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
