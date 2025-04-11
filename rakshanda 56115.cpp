#include <iostream>
#include <GL/glut.h> // open window

float carX = 0.0f;  // Car's initial horizontal position
float carSpeed = 0.1f;  // Speed of the car

// Function to display the scene
void drawCar() {
    // Draw the car body
    glColor3f(1.0f, 0.0f, 0.0f);  // red color for the car body
    glBegin(GL_QUADS);  // Define a rectangle for the car body
    glVertex2f(carX - 0.2f, -0.2f);
    glVertex2f(carX + 0.2f, -0.2f);
    glVertex2f(carX + 0.2f, 0.0f);
    glVertex2f(carX - 0.2f, 0.0f);
    glEnd();  // Complete the car body drawing

    // Draw the first wheel (left wheel)
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color for wheels
    glBegin(GL_QUADS);
    glVertex2f(carX - 0.15f, -0.25f);
    glVertex2f(carX - 0.05f, -0.25f);
    glVertex2f(carX - 0.05f, -0.2f);
    glVertex2f(carX - 0.15f, -0.2f);
    glEnd();

    // Draw the second wheel (right wheel)
    glBegin(GL_QUADS);
    glVertex2f(carX + 0.05f, -0.25f);
    glVertex2f(carX + 0.15f, -0.25f);
    glVertex2f(carX + 0.15f, -0.2f);
    glVertex2f(carX + 0.05f, -0.2f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the window
    
    glLoadIdentity();  // Reset the coordinate system
    drawCar();  // Draw the car
    glFlush();  // Render the drawn shapes
}

void specialKeys(int key, int x, int y) {
    // Arrow key handling with switch statement
    switch (key) {
        case GLUT_KEY_LEFT:
            carX -= carSpeed;  // Move the car to the left
            break;
        case GLUT_KEY_RIGHT:
            carX += carSpeed;  // Move the car to the right
            break;
        default:
            break;
    }
    glutPostRedisplay();  // Redisplay the scene with the new position
}

// Function to initialize OpenGL
void init() {
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);  // Set the background color to white
    glMatrixMode(GL_PROJECTION);  // Set up the projection matrix
    glLoadIdentity();

}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set up display mode
    glutInitWindowSize(500, 500);  // Set window size
    glutInitWindowPosition(100, 100);  // Starting position batana
    glutCreateWindow("Car Movement Using Arrow Keys");  // Create window
    init();  // Initialize OpenGL

    glutDisplayFunc(display);  // Register display callback function
    glutSpecialFunc(specialKeys);  // Register special key (arrow keys) callback function
    
    glutMainLoop();  // Start the main loop

    return 0;
}
