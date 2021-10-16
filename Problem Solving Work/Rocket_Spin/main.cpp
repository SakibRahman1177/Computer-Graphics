#include<windows.h>
#include<GL/glut.h>

GLfloat position = 0.0f;
GLfloat speed = 0.0f;

void myInit() {
   glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // white
}

void update(int value) {
    if(position>1.5)
        position = -1.0f;
        position += speed;
        glutPostRedisplay();
        glutTimerFunc(120, update, 0);

}

void display() {

glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glLoadIdentity();

//Background
glBegin(GL_QUADS);
	glColor3ub(135, 206, 250); // Sky Blue
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();

glTranslatef(position,position,0.0f);

//Body down part
glTranslatef(-0.6f, -0.5f, 0.0f);
glRotatef(70, 40.0f, 40.0f, 40.0f);
glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); //Green
    glVertex2f(-0.3f, -0.3f);
    glVertex2f( 0.3f, -0.3f);
    glVertex2f( 0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glEnd();

//Body upper part
glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); //Green
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.58f, 0.0f);
    glVertex2f(0.3f, 0.3f);
    glEnd();

//Another upper part
glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); //Yellow
    glVertex2f(0.28f,-0.28f);
    glVertex2f(0.55f, 0.0f);
    glVertex2f(0.28f, 0.28f);
    glEnd();

//Lower Portion - Fire 1
glTranslatef(-0.5f, -0.15f, 0.0f);
glScalef(0.4, 0.5, 0.5);
glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); //Yellow
    glVertex2f(0.2f,-0.2f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

//Lower Portion - Fire 2
glTranslatef(0.0f, 0.6f, 0.0f);
glScalef(1.0, 1.0, 0.0);
glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); //Yellow
    glVertex2f(0.2f,-0.2f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

glPopMatrix();
glFlush();

}

void handleMouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON)
{
    speed = 0.1f;
}
if (button == GLUT_RIGHT_BUTTON)
{
    speed = 0.0f;
}
glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{
switch (key) {
case 'a':
speed = 0.0f;
break;
case 'w':
speed = 0.1f;
break;
case 'r':
speed = -0.1f;
break;

glutPostRedisplay();
}
}

int main(int argc, char** argv) {

glutInit(&argc, argv);
glutInitWindowSize(800, 520);
glutInitWindowPosition(50, 50);
glutCreateWindow("Translation Rocket");
glutDisplayFunc(display);
myInit();
glutTimerFunc(120, update, 0);
glutKeyboardFunc(handleKeypress);
glutMouseFunc(handleMouse);
glutMainLoop();
return 0;

}
