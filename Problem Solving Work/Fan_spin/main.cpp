#include<windows.h>
#include<GL/glut.h>

static GLfloat spin = 0.0;
static GLfloat spin_speed = 0.1;
float spin_x = 0;
float spin_y = 0;
float spin_z = 1;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -2.0;

float Fan1=0, Fan2=0, Fan3=0, Fan4=0;

void shape(void)
{
    glBegin(GL_LINE_LOOP);                         //First Blade

        glVertex3f(0, -0.05, 0.0);
        glVertex3f(-.05, .07, 0.0);
        glVertex3f(-.12, .07, 0.0);
        glVertex3f(-.18, .15, 0.0);
        glVertex3f(-.1, .15, 0.0);
        glVertex3f(-.15, .22, 0.0);
        glVertex3f(-.20, .22, 0.0);
        glVertex3f(-.27, .30, 0.0);
        glVertex3f(-.10, .30, 0.0);
        glVertex3f(-.17, .37, 0.0);
        glVertex3f(-.24, .37, 0.0);
        glVertex3f(-.27, .45, 0.0);
        glVertex3f(-.12, .45, 0.0);
        glVertex3f(-.2, .55, 0.0);
        glVertex3f(.2, .55, 0.0);
        glVertex3f(.12, .45, 0.0);
        glVertex3f(.27, .45, 0.0);
        glVertex3f(.24, .37, 0.0);
        glVertex3f(.17, .37, 0.0);
        glVertex3f(.10, .30, 0.0);
        glVertex3f(.27, .30, 0.0);
        glVertex3f(.20, .22, 0.0);
        glVertex3f(.15, .22, 0.0);
        glVertex3f(.1, .15, 0.0);
        glVertex3f(.18, .15, 0.0);
        glVertex3f(.12, .07, 0.0);
        glVertex3f(.05, .07, 0.0);

    glEnd();
}

void Fan(void)
{
    shape();                                    //2nd Blade
    glRotatef(90,0.0,0.0,1.0);
    glTranslatef(-0.05,0.055,0.0);
    shape();                                    //3rd Blade
    glRotatef(180,0.0,0.0,1.0);
    glTranslatef(0.0,0.11,0.0);
    shape();                                    //4th Blade
    glRotatef(270,0.0,0.0,1.0);
    glTranslatef(0.055,0.05,0.0);
    shape();
}

void reshape(int w,int h)
{
    glViewport(0,0, (GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30,1,1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(translate_x, translate_y, translate_z);

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(spin,spin_x,spin_y,spin_z);
    Fan();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.5,1.5,0); //Fan1 Upper Right
        glScalef(Fan1,Fan1,1);
        Fan();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.5,-1.5,0); //Fan2 Lower Right
        glScalef(Fan2,Fan2,1);
        Fan();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.5,-1.5,0); //Fan3 Lower Left
        glScalef(Fan3,Fan3,1);
        Fan();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.5,1.5,0); //Fan4 Upper Left
        glScalef(Fan4,Fan4,1);
        Fan();
    glPopMatrix();

glFlush();

}

void setSpin(float x, float y, float z)
{
    spin_x = x;
    spin_y = y;
    spin_z = z;
}

void spinDisplay(void)
{
    spin=spin+spin_speed;
    if(spin>360.0)
    {
        spin=spin-360.0;
    }
    glutPostRedisplay();
}



void spinDisplayReverse(void)
{
    spin=spin-spin_speed;
    if(spin<360.0)
    {
        spin=spin+360.0;
    }
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;


        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN)
            {
                glutIdleFunc(NULL);
            }
            break;


        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(spinDisplayReverse);
            break;


        default:
            break;

    }
}

void keyboard(unsigned char key, int x, int y)
{

    if(key=='a'){
        Fan1=0.5;
        glutPostRedisplay();
    }

    else if(key=='b'){
        Fan2=0.5;
        glutPostRedisplay();
    }

    else if(key=='c'){
        Fan3=0.5;
        glutPostRedisplay();
    }

    else if(key=='d'){
        Fan4=0.5;
        glutPostRedisplay();
    }
  //glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    //init();
    glutMainLoop();
    return 0;
}
