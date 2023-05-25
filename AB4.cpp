#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>

void myInit()
{
    //glClearColor(0.0, 1.0, 0.0, 0.0);
    //glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
    //glColor3f(0.0, 0.2, 0.0);
    glClearColor(128.0f / 255.0f, 0, 0, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // setting window dimension in X- and Y- direction
    glOrtho(-800, 800, -800, 800, -800, 800);
}
void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y, GLfloat startangle = 0, GLfloat endangle = 360) {
    GLfloat PI = 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (GLfloat angle = startangle; angle <= endangle; angle += 2.0 * PI / 1000.0) {
        GLfloat rangle = PI * angle / 180.0;
        glVertex2f(x + (cos(rangle) * rx), y + (sin(rangle) * ry));
    }
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1, 1.0 / 255 * 182.0, 1.0 / 255 * 12.0);
    //left leg
    glBegin(GL_TRIANGLES);
    glVertex2d(-50, 50);
    glVertex2d(-300, -50);
    glVertex2d(-80, -50);
    glEnd();

    //right leg
    glBegin(GL_TRIANGLES);
    glVertex2d(50, 50);
    glVertex2d(300, -50);
    glVertex2d(80, -50);
    glEnd();

    //left hand
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(-150, 350);
    glVertex2d(-400, 250);
    glVertex2d(-180, 250);
    glEnd();

    //right hand
    glBegin(GL_TRIANGLES);
    glVertex2d(150, 350);
    glVertex2d(400, 250);
    glVertex2d(180, 250);
    glEnd();

    //body
    circle(200, 150, 0, 400, 0, 360);
    circle(300, 250, 0, 150, 0, 180);
    circle(300, 150, 0, 150, 180, 360);


    // circle(20, 20, -60, 400, 0, 360);
    // circle(20, 20, 60, 400, 0, 360);
    //inner body
    glColor3f(1, 1, 1);
    circle(80, 80, -60, 400, 0, 360);
    circle(20, 20, -60, 400, 0, 360);
    circle(80, 80, 60, 400, 0, 360);
    circle(250, 200, 0, 150, 0, 180);
    circle(250, 120, 0, 150, 180, 360);
    //eyes
    glColor3f(0, 0, 0);
    circle(20, 20, -60, 400, 0, 360);
    circle(20, 20, 60, 400, 0, 360);
    circle(5, 5, -60, 400, 0, 360);
    circle(5, 5, 60, 400, 0, 360);


    // glColor3ub(1, 1, 1);
    // circle(5, 5, -60, 400, 0, 360);
    // circle(5, 5, 60, 400, 0, 360);


    //nose
    glColor3f(1, 1.0 / 255 * 182.0, 1.0 / 255 * 12.0);
    circle(60, 60, 0, 320, 60, 120);

    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("Penguine");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}