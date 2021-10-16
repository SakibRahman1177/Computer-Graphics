#include <GL/gl.h>
#include<iostream>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

#define PI 3.141592653589
GLfloat cloud1Position=0;
GLfloat cloud1speed=0.2;
GLfloat birdPosition=0;
GLfloat birdspeed=0.4;
GLfloat cloud2Position=0;
GLfloat cloud2speed=-0.3;
GLfloat cloud3Position=0;
GLfloat cloud3speed=0.4;
GLfloat sunXAxis=0;
GLfloat sunspeed=0.1;
GLfloat roadMiddleWhiteMark=0;
GLfloat roadMiddleWhiteMarkSpeed=0.5; //wrked reduced
GLfloat travellcarPosition1=0;
GLfloat travellcarPosition2=0;
GLfloat travellcarspeed=0.1;
GLfloat roadUpperWhiteBlackMark=0;
GLfloat roadUpperWhiteBlackMarkSpeed=0.2;
GLfloat shipPosition=0;
GLfloat shipSpeed=0.05;
GLfloat humanPosition1=0;
GLfloat humanspeed=0.2;
GLfloat humanPosition2=0;
GLfloat humanPosition3=0;
GLfloat humanPosition4=0;
GLfloat humanPosition5=0;
GLfloat humanPosition=0;
GLfloat cocoPosition=0;
GLfloat cocoSpeed=0.2;


void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius) {
		glPushMatrix();

		glTranslatef(x, y, 0);
		glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

		glPopMatrix();
}

// Function to Draw Circle
void drawSemiCircle(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat radius,
	GLfloat start_angle, GLfloat end_angle) {
		glPushMatrix();

		glTranslatef(tx, ty, 0);
		glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
    for (GLfloat i = start_angle; i < end_angle; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

		glPopMatrix();
}


void drawHumamsShirtAndTrousers(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bottom Shirt

	glBegin(GL_POLYGON);
	glVertex2f(0, 20);
	glVertex2f(100, 20);
	glVertex2f(100, 100);
	glVertex2f(0, 100);
	glEnd();

	// Top Shirt
	glBegin(GL_POLYGON);

	glVertex2f(100, 100);
	glVertex2f(135, 105);
	glVertex2f(120, 175);
	glVertex2f(100, 200);
	glVertex2f(50, 180);
	glVertex2f(0, 200);
	glVertex2f(-20, 175);
	glVertex2f(-35, 105);
	glVertex2f(0, 100);
	glEnd();

	// Left Trouser
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 25);
	glVertex2f(0, -100);
	glVertex2f(35, -100);
	glVertex2f(65, 25);
	glEnd();

	// Right Trouser

	glBegin(GL_POLYGON);
	glVertex2f(35, 25);
	glVertex2f(65, -100);
	glVertex2f(100, -100);
	glVertex2f(100, 25);
	glEnd();

	glPopMatrix();
}

void drawHumam(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	drawSemiCircle(-1, -35, .6, 1,
		203, 166, 108,
		20, -90, 90);

	// Face
  drawCircle(0, 0,
		232, 190, 123,
		1, 1,
		24);

	// Left Eye
	drawCircle(-8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(-6, 0,
		10, 10, 10,
		1, 1,
		2);

	// Right Eye
	drawCircle(8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(10, 0,
		10, 10, 10,
		1, 1,
		2);




	// Cap
	drawSemiCircle(0, 10, 1, 1,
		0, 0, 0,
		24, -90, 90);


	// Hands
	drawCircle(-42, -82,
		232, 190, 123,
		1, 1,
		10);
	drawCircle(38, -82,
		232, 190, 123,
		1, 1,
		10);

	// Shirt and Trousers
	drawHumamsShirtAndTrousers(-32, -125,
		.6, .5		);

	// Left Shoe
	drawSemiCircle(-21, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	// Right Shoe
	drawSemiCircle(18, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	glPopMatrix();
}

void bench()
{

    glColor3ub(102, 51, 0); //seat
	glBegin(GL_POLYGON);
		glVertex2f(0.0,9.8);
		glVertex2f(0.0,20.0);
		glVertex2f(24.0,20.0);
		glVertex2f(24.0,9.8);
	glEnd();

    glColor3ub(0,0,0); //base
	glBegin(GL_POLYGON);
		glVertex2f(0.5,5.0);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,5.0);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(86, 46, 11);
        glVertex2f(3, -5);      //left
        glVertex2f(5, -5);
        glVertex2f(5, 20);
        glVertex2f(3, 20);
	glEnd();


	 glBegin(GL_POLYGON);
        glColor3ub(86, 46, 11); //right
        glVertex2f(19, -5);
        glVertex2f(21, -5);
        glVertex2f(21, 20);
        glVertex2f(19, 20);
	glEnd();

}

void trash()
{


    glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,16.0);
		glVertex2f(5.0,16.0);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3ub(128,128,128); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,13.5);
		glVertex2f(5.0,13.5);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(0.0,0.0,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,14.5);
		glVertex2f(2.5,15.5);
		glVertex2f(5.0,15.5);
		glVertex2f(5.0,14.5);
	glEnd();
}
void coconut_tree()
 {
    glRotatef(50,0,0,0);
     glTranslatef(1300 , 340, 0);
    glScalef(4,4,0);

    glPushMatrix();

    glTranslatef(10,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();

    glTranslatef(-18,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();

    glTranslatef(720,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();

    glTranslatef(700,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

 glPushMatrix();

    glTranslatef(600,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
     glPushMatrix();

    glTranslatef(550,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



     glPushMatrix();

    glTranslatef(510,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();


     glPushMatrix();

    glTranslatef(500,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();


     glPushMatrix();

    glTranslatef(200,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();


     glPushMatrix();

    glTranslatef(440,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
     glPushMatrix();

    glTranslatef(420,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();

    glTranslatef(380,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();

    glTranslatef(340,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();


     glPushMatrix();

    glTranslatef(320,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(180,10,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();


// Coconut tree 1
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///Coconut Tree 2
    glPushMatrix();
    glTranslatef(40,0,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();



	// Coconut tree 1
    glPushMatrix();
    glTranslatef(60,0,0);
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

    glPopMatrix();


	// Coconut tree 1
    glPushMatrix();
    glTranslatef(100,0,0);
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
    glPopMatrix();







    //glFlush();
	//glutSwapBuffers();

 }

void drawTree(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bark
	glBegin(GL_POLYGON);
	glColor3ub(86, 46, 11);
	glVertex2f(0, 0);
	glVertex2f(40, 0);
	glColor3ub(71, 36, 6);
	glVertex2f(35, 200);
	glVertex2f(5, 200);
	glEnd();

	// Tree
	//drawCircle(20, 200, 5, 80, 10, 1, 8, 20);

	//glRotatef(360,1.0f,1.0f,0.0f);
	float j=30;
	for(int i=180;i<420;i=i+10)
    {
       drawCircle(20, i, 5, 80, 10, 5, 2, j);
       j=j-1.2;
    }


	glPopMatrix();
}

void PS_drawRoad(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(40, 40, 40);
	glVertex2f(300, 275);
	glVertex2f(500, 275);
	glVertex2f(500, 200);
	glVertex2f(300, 200);
	glEnd();


    glPushMatrix();
    glTranslatef(roadUpperWhiteBlackMark,0.0f,0.0f);
	for(int i=300;i<2000;i=i+5){
    glBegin(GL_POLYGON);
    if(i%2==0){
      glColor3ub(250, 250, 250);
    }
    else{
        glColor3ub(0, 0, 0);
    }

	glVertex2f(i, 275);
	glVertex2f(i+5, 275);
	glVertex2f(i+5, 280);
	glVertex2f(i, 280);
	glEnd();
	}
     glPopMatrix();


    glPushMatrix();
    glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);
    glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	for(int i=-1000;i<=1000;i=i+5)
    {
        glVertex2f(i, 240);   //white marks in middle
    }



	glEnd();

    glPopMatrix();


	glLineWidth(1);
	glPopMatrix();
}




void DrawCould(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
    {
    //Cloud

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawSemiCircle(500, 400,
		7.2, 5.1,
		200, 230, 255,
		10,
		0, 360);
    drawSemiCircle(480, 420,
		3.2, 5.1,
		200, 230, 255,
		10,
		0, 360);
   drawSemiCircle(520, 410,
		3.2, 5.1,
		200, 230, 255,
		10,
		0, 360);
   drawSemiCircle(510, 380, //x,y
		3.2, 5.1, //
		200, 230, 255, //color
		10,
		0, 360);

    glPopMatrix();

    }

void DrawCouldRain(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
    {
    //Cloud

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawSemiCircle(500, 400,
		7.2, 5.1,
		119,136,153,
		10,
		0, 360);
    drawSemiCircle(480, 420,
		3.2, 5.1,
		119,136,153,
		10,
		0, 360);
   drawSemiCircle(520, 410,
		3.2, 5.1,
		119,136,153,
		10,
		0, 360);
   drawSemiCircle(510, 380,
		3.2, 5.1,
		119,136,153,
		10,
		0, 360);

    glPopMatrix();

    }

void drawBackground(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51); // sand
	glVertex2f(1400, 90);
	glVertex2f(0, 90);

	glColor3ub(0,107,180); //blu water
	glVertex2f(0, 400);
	glVertex2f(1400, 400);
	glEnd();

		// Background

	glBegin(GL_POLYGON);
	glColor3ub(135, 206, 250); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 400);
	glVertex2f(0, 400);
	glEnd();


	glPopMatrix();
}
void drawBackgroundNight(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51); // sand
	glVertex2f(1400, 90);
	glVertex2f(0, 90);

	glColor3ub(0,107,180); //blu water
	glVertex2f(0, 400);
	glVertex2f(1400, 400);
	glEnd();

		// Background
	glBegin(GL_POLYGON);
	glColor3ub(25,25,112); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 400);
	glVertex2f(0, 400);
	glEnd();

	//stars
        drawCircle(300, 400,
		250, 250, 250,
		7, 14,
		.1);
        drawCircle(200, 500,
		250, 250, 250,
		7, 14,
		.2);
        drawCircle(100, 550,
		250, 250, 0,
		7, 14,
		.2);
		 drawCircle(100, 400,
		250, 250, 250,
		7, 14,
		.25);
		 drawCircle(400, 550,
		250, 250, 0,
		7, 14,
		.3);
		 drawCircle(600, 600,
		250, 250, 250,
		7, 14,
		.2);
		 drawCircle(900, 700,
		250, 250, 250,
		7, 14,
		.2);


		for(int i=0;i<500;i++)
        {

        int x=rand()%1100;
        int y=rand()%1200;
        if(y>400){
         drawCircle(x, y,
		250, 250, 250,
		7, 14,
		.1);
        }
        }

	glPopMatrix();
}


void drawBackgroundRain(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51); // sand
	glVertex2f(1400, 90);
	glVertex2f(0, 90);

	glColor3ub(0, 102, 255); //blu water
	glVertex2f(0, 400);
	glVertex2f(1400, 400);
	glEnd();

		// Background
	glBegin(GL_POLYGON);
	glColor3ub(0, 51, 102); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 300);
	glVertex2f(0, 300);
	glEnd();


	glPopMatrix();
}

void travellCar(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
               {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3f (1, 1,1);
    glVertex2i(0,20);
	glVertex2i(3,30);
	glVertex2i(95,30);
	glVertex2i(100,20);
    glEnd();
//glFlush ();

glBegin(GL_POLYGON);
 glColor3f (0.8, 0.8,0.8);
    glVertex2i(3,30);
	glVertex2i(4,32);
	glVertex2i(94,32);
	glVertex2i(95,30);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1, 1,1);
    glVertex2i(4,32);
	glVertex2i(6,40);
	glVertex2i(87,40);
	glVertex2i(93,32);
glEnd();
//glFlush ();
//blue
glBegin(GL_POLYGON);
    glColor3f (0.7, 0.7,1.7);
    glVertex2i(93,32);
	glVertex2i(90.8,35);
	glVertex2i(88,35);
	glVertex2i(88,32);
glEnd();
//glFlush ();
//red
glBegin(GL_POLYGON);
    glColor3f (1.5, 0.5,0.5);
    glVertex2i(88,32);
	glVertex2i(88,35);
	glVertex2i(86,35);
	glVertex2i(86,32);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1.5, 0.5,0.5);
    glVertex2i(4,32);
	glVertex2i(4.8,35);
	glVertex2i(7,35);
	glVertex2i(7,32);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1,1,1);
    glVertex2i(15,40);
	glVertex2i(25,60);
	glVertex2i(62,60);
	glVertex2i(75,40);
glEnd();
//glFlush ();
//glass1
glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5,1.5);
    glVertex2i(18,40);
	glVertex2i(26,57);
	glVertex2i(43,57);
	glVertex2i(43,40);
glEnd();
//glFlush ();

glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(18,40);
	glVertex2i(26,57);
	glVertex2i(43,57);
	glVertex2i(43,40);
glEnd();
//glFlush ();

//glass2
glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5,1.5);
    glVertex2i(46,40);
	glVertex2i(46,57);
	glVertex2i(62,57);
	glVertex2i(73,40);
glEnd();
//glFlush ();

glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(46,40);
	glVertex2i(46,57);
	glVertex2i(62,57);
	glVertex2i(73,40);
glEnd();
//glFlush ();
//Door1
glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(18,40);
	glVertex2i(18,20);
	glVertex2i(43,20);
	glVertex2i(43,40);
glEnd();
//glFlush ();
//Door2
glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(46,40);
	glVertex2i(46,20);
	glVertex2i(73,20);
	glVertex2i(73,40);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (0.3, 0.3,0.3);
    glVertex2i(54,60);
	glVertex2i(56,61);
	glVertex2i(58,61);
	glVertex2i(60,60);
glEnd();
//glFlush ();





//wheel1
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0,0,0);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*10,15+sin(angle)*10);
		}
	glEnd();
//	glFlush ();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5,0.5,0.5);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*8,15+sin(angle)*8);
		}
	glEnd();
	//glFlush ();

			glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8,0.8,0.8);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*5.5,15+sin(angle)*5.5);
		}
	glEnd();
	//glFlush ();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.2,0.2,0.2);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*5,15+sin(angle)*5);
		}
	glEnd();
	//glFlush ();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1,1,1);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*1.5,15+sin(angle)*1.5);
		}
	glEnd();
	//glFlush ();

//wheel2
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,0,0);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*10,15+sin(angle)*10);
		}
	glEnd();
	//glFlush ();


	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5,0.5,0.5);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*8,15+sin(angle)*8);
		}
	glEnd();
	//glFlush ();

				glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8,0.8,0.8);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*5.5,15+sin(angle)*5.5);
		}
	glEnd();
	//glFlush ();

			glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.2,0.2,0.2);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*5,15+sin(angle)*5);
		}
	glEnd();
	//glFlush ();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.5,1.5,1.5);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*1.5,15+sin(angle)*1.5);
		}
	glEnd();
	//glFlush ();

	glPopMatrix();
}

void rain()
{
    glLineWidth(3);
    for(int i=0;i<1000;i++)
    {

        int x=rand()%1080;
        int y=rand()%1000;
    glBegin(GL_LINES);
    glColor3ub (255,255,255);
    glVertex2i(x,y);
    glVertex2i(x+5,y-10);
    glEnd();
    }


}
void ship_a() //small ship day
{
    glScaled(5,5,0);

	glColor3ub(0,0,0); //base
	glBegin(GL_POLYGON);
		glVertex2f(0.5,5.0);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,5.0);
	glEnd();

	glColor3f(1.0,1.0,1.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(1.35,3.5);
		glVertex2f(1.6,3.2);
		glVertex2f(23.2,3.2);
		glVertex2f(23.35,3.5);
	glEnd();

	glColor3f(0.329412,0.329412,0.329412); //base
	glBegin(GL_POLYGON);
		glVertex2f(21.0,5.0);
		glVertex2f(21.0,6.0);
		glVertex2f(24.5,6.0);
		glVertex2f(24.0,5.0);
	glEnd();

	glColor3f(0.74902,0.847059,0.847059); //top-mid
	glBegin(GL_POLYGON);
		glVertex2f(2.0,5.0);
		glVertex2f(2.0,12.0);
		glVertex2f(15.0,12.0);
		glVertex2f(19.5,5.0);
	glEnd();

	glColor3f(0.137255,0.137255,0.556863); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.0,8.2);
		glVertex2f(2.0,8.8);
		glVertex2f(17.1,8.8);
		glVertex2f(17.5,8.2);
	glEnd();

	glColor3f(0.90,0.91,0.98); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,6.0);
		glVertex2f(3.0,7.2);
		glVertex2f(4.0,7.2);
		glVertex2f(4.0,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,6.0);
		glVertex2f(4.7,7.2);
		glVertex2f(5.7,7.2);
		glVertex2f(5.7,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,6.0);
		glVertex2f(8.1,7.2);
		glVertex2f(9.1,7.2);
		glVertex2f(9.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,6.0);
		glVertex2f(9.8,7.2);
		glVertex2f(10.8,7.2);
		glVertex2f(10.8,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,6.0);
		glVertex2f(6.4,7.2);
		glVertex2f(7.4,7.2);
		glVertex2f(7.4,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,6.0);
		glVertex2f(11.5,7.2);
		glVertex2f(12.5,7.2);
		glVertex2f(12.5,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,6.0);
		glVertex2f(13.3,7.2);
		glVertex2f(14.3,7.2);
		glVertex2f(14.3,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(15.1,6.0);
		glVertex2f(15.1,7.2);
		glVertex2f(16.1,7.2);
		glVertex2f(16.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.9,6.0);
		glVertex2f(16.9,7.2);
		glVertex2f(17.9,7.2);
		glVertex2f(17.9,6.0);
	glEnd();




	glColor3f(0.90,0.91,0.98); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,9.8);
		glVertex2f(3.0,11.0);
		glVertex2f(4.0,11.0);
		glVertex2f(4.0,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,9.8);
		glVertex2f(4.7,11.0);
		glVertex2f(5.7,11.0);
		glVertex2f(5.7,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,9.8);
		glVertex2f(8.1,11.0);
		glVertex2f(9.1,11.0);
		glVertex2f(9.1,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,9.8);
		glVertex2f(9.8,11.0);
		glVertex2f(10.8,11.0);
		glVertex2f(10.8,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,9.8);
		glVertex2f(6.4,11.0);
		glVertex2f(7.4,11.0);
		glVertex2f(7.4,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,9.8);
		glVertex2f(11.5,11.0);
		glVertex2f(12.5,11.0);
		glVertex2f(12.5,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,9.8);
		glVertex2f(13.3,11.0);
		glVertex2f(14.3,11.0);
		glVertex2f(14.3,9.8);
	glEnd();

	glColor3f(0.329412,0.329412,0.329412); //top-cover
	glBegin(GL_POLYGON);
		glVertex2f(1.5,12.0);
		glVertex2f(1.5,12.5);
		glVertex2f(16.0,12.5);
		glVertex2f(16.0,12.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,16.0);
		glVertex2f(5.0,16.0);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,13.5);
		glVertex2f(5.0,13.5);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,14.5);
		glVertex2f(2.5,15.5);
		glVertex2f(5.0,15.5);
		glVertex2f(5.0,14.5);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,16.0);
		glVertex2f(8.5,16.0);
		glVertex2f(8.5,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,14.5);
		glVertex2f(6.0,15.5);
		glVertex2f(8.5,15.5);
		glVertex2f(8.5,14.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,13.5);
		glVertex2f(8.5,13.5);
		glVertex2f(8.5,12.5);
	glEnd();
}
void ship_a_1() //small ship night
{
    glScaled(5,5,0);

	glColor3ub(0,0,0); //base
	glBegin(GL_POLYGON);
		glVertex2f(0.5,5.0);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,5.0);
	glEnd();

	glColor3f(1.0,1.0,1.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(1.35,3.5);
		glVertex2f(1.6,3.2);
		glVertex2f(23.2,3.2);
		glVertex2f(23.35,3.5);
	glEnd();

	glColor3f(0.329412,0.329412,0.329412); //base
	glBegin(GL_POLYGON);
		glVertex2f(21.0,5.0);
		glVertex2f(21.0,6.0);
		glVertex2f(24.5,6.0);
		glVertex2f(24.0,5.0);
	glEnd();

	glColor3f(0.74902,0.847059,0.847059); //top-mid
	glBegin(GL_POLYGON);
		glVertex2f(2.0,5.0);
		glVertex2f(2.0,12.0);
		glVertex2f(15.0,12.0);
		glVertex2f(19.5,5.0);
	glEnd();

	glColor3f(0.137255,0.137255,0.556863); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.0,8.2);
		glVertex2f(2.0,8.8);
		glVertex2f(17.1,8.8);
		glVertex2f(17.5,8.2);
	glEnd();

	glColor3ub(255,255,0); //window //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,6.0);
		glVertex2f(3.0,7.2);
		glVertex2f(4.0,7.2);
		glVertex2f(4.0,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,6.0);
		glVertex2f(4.7,7.2);
		glVertex2f(5.7,7.2);
		glVertex2f(5.7,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,6.0);
		glVertex2f(8.1,7.2);
		glVertex2f(9.1,7.2);
		glVertex2f(9.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,6.0);
		glVertex2f(9.8,7.2);
		glVertex2f(10.8,7.2);
		glVertex2f(10.8,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,6.0);
		glVertex2f(6.4,7.2);
		glVertex2f(7.4,7.2);
		glVertex2f(7.4,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,6.0);
		glVertex2f(11.5,7.2);
		glVertex2f(12.5,7.2);
		glVertex2f(12.5,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,6.0);
		glVertex2f(13.3,7.2);
		glVertex2f(14.3,7.2);
		glVertex2f(14.3,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(15.1,6.0);
		glVertex2f(15.1,7.2);
		glVertex2f(16.1,7.2);
		glVertex2f(16.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.9,6.0);
		glVertex2f(16.9,7.2);
		glVertex2f(17.9,7.2);
		glVertex2f(17.9,6.0);
	glEnd();




	glColor3ub(255,255,0); //window //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,9.8);
		glVertex2f(3.0,11.0);
		glVertex2f(4.0,11.0);
		glVertex2f(4.0,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,9.8);
		glVertex2f(4.7,11.0);
		glVertex2f(5.7,11.0);
		glVertex2f(5.7,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,9.8);
		glVertex2f(8.1,11.0);
		glVertex2f(9.1,11.0);
		glVertex2f(9.1,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,9.8);
		glVertex2f(9.8,11.0);
		glVertex2f(10.8,11.0);
		glVertex2f(10.8,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,9.8);
		glVertex2f(6.4,11.0);
		glVertex2f(7.4,11.0);
		glVertex2f(7.4,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,9.8);
		glVertex2f(11.5,11.0);
		glVertex2f(12.5,11.0);
		glVertex2f(12.5,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,9.8);
		glVertex2f(13.3,11.0);
		glVertex2f(14.3,11.0);
		glVertex2f(14.3,9.8);
	glEnd();

	glColor3f(0.329412,0.329412,0.329412); //top-cover
	glBegin(GL_POLYGON);
		glVertex2f(1.5,12.0);
		glVertex2f(1.5,12.5);
		glVertex2f(16.0,12.5);
		glVertex2f(16.0,12.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,16.0);
		glVertex2f(5.0,16.0);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,13.5);
		glVertex2f(5.0,13.5);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,14.5);
		glVertex2f(2.5,15.5);
		glVertex2f(5.0,15.5);
		glVertex2f(5.0,14.5);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,16.0);
		glVertex2f(8.5,16.0);
		glVertex2f(8.5,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,14.5);
		glVertex2f(6.0,15.5);
		glVertex2f(8.5,15.5);
		glVertex2f(8.5,14.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,13.5);
		glVertex2f(8.5,13.5);
		glVertex2f(8.5,12.5);
	glEnd();
}
void ship()
{


	glScaled(14,14,0);

	glColor3ub(0, 38, 77); //base
	glBegin(GL_POLYGON);
		glVertex2f(0.5,5.0);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,5.0);
	glEnd();





	glColor3f(0.74902,0.847059,0.847059); //top-mid
	glBegin(GL_POLYGON);
		glVertex2f(2.0,5.0);
		glVertex2f(2.0,12.0);
		glVertex2f(15.0,12.0);
		glVertex2f(19.5,5.0);
	glEnd();

	glColor3f(0.137255,0.137255,0.556863); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.0,8.2);
		glVertex2f(2.0,8.8);
		glVertex2f(17.1,8.8);
		glVertex2f(17.5,8.2);
	glEnd();

	glColor3f(0.90,0.91,0.98); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,6.0);
		glVertex2f(3.0,7.2);
		glVertex2f(4.0,7.2);
		glVertex2f(4.0,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,6.0);
		glVertex2f(4.7,7.2);
		glVertex2f(5.7,7.2);
		glVertex2f(5.7,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,6.0);
		glVertex2f(8.1,7.2);
		glVertex2f(9.1,7.2);
		glVertex2f(9.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,6.0);
		glVertex2f(9.8,7.2);
		glVertex2f(10.8,7.2);
		glVertex2f(10.8,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,6.0);
		glVertex2f(6.4,7.2);
		glVertex2f(7.4,7.2);
		glVertex2f(7.4,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,6.0);
		glVertex2f(11.5,7.2);
		glVertex2f(12.5,7.2);
		glVertex2f(12.5,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,6.0);
		glVertex2f(13.3,7.2);
		glVertex2f(14.3,7.2);
		glVertex2f(14.3,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(15.1,6.0);
		glVertex2f(15.1,7.2);
		glVertex2f(16.1,7.2);
		glVertex2f(16.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.9,6.0);
		glVertex2f(16.9,7.2);
		glVertex2f(17.9,7.2);
		glVertex2f(17.9,6.0);
	glEnd();




	glColor3f(0.90,0.91,0.98); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,9.8);
		glVertex2f(3.0,11.0);
		glVertex2f(4.0,11.0);
		glVertex2f(4.0,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,9.8);
		glVertex2f(4.7,11.0);
		glVertex2f(5.7,11.0);
		glVertex2f(5.7,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,9.8);
		glVertex2f(8.1,11.0);
		glVertex2f(9.1,11.0);
		glVertex2f(9.1,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,9.8);
		glVertex2f(9.8,11.0);
		glVertex2f(10.8,11.0);
		glVertex2f(10.8,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,9.8);
		glVertex2f(6.4,11.0);
		glVertex2f(7.4,11.0);
		glVertex2f(7.4,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,9.8);
		glVertex2f(11.5,11.0);
		glVertex2f(12.5,11.0);
		glVertex2f(12.5,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,9.8);
		glVertex2f(13.3,11.0);
		glVertex2f(14.3,11.0);
		glVertex2f(14.3,9.8);
	glEnd();

	glColor3f(0.329412,0.329412,0.329412); //top-cover
	glBegin(GL_POLYGON);
		glVertex2f(1.5,12.0);
		glVertex2f(1.5,12.5);
		glVertex2f(16.0,12.5);
		glVertex2f(16.0,12.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,16.0);
		glVertex2f(5.0,16.0);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,13.5);
		glVertex2f(5.0,13.5);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,14.5);
		glVertex2f(2.5,15.5);
		glVertex2f(5.0,15.5);
		glVertex2f(5.0,14.5);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,16.0);
		glVertex2f(8.5,16.0);
		glVertex2f(8.5,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,14.5);
		glVertex2f(6.0,15.5);
		glVertex2f(8.5,15.5);
		glVertex2f(8.5,14.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,13.5);
		glVertex2f(8.5,13.5);
		glVertex2f(8.5,12.5);
	glEnd();
}


void ship1() //big ship night
{


	glScaled(14,14,0);

	glColor3ub(0, 38, 77); //base
	glBegin(GL_POLYGON);
		glVertex2f(0.5,5.0);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,5.0);
	glEnd();

	glColor3f(0.74902,0.847059,0.847059); //top-mid
	glBegin(GL_POLYGON);
		glVertex2f(2.0,5.0);
		glVertex2f(2.0,12.0);
		glVertex2f(15.0,12.0);
		glVertex2f(19.5,5.0);
	glEnd();

	glColor3f(0.137255,0.137255,0.556863); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.0,8.2);
		glVertex2f(2.0,8.8);
		glVertex2f(17.1,8.8);
		glVertex2f(17.5,8.2);
	glEnd();

	glColor3ub(255,255,0); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,6.0);
		glVertex2f(3.0,7.2);
		glVertex2f(4.0,7.2);
		glVertex2f(4.0,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,6.0);
		glVertex2f(4.7,7.2);
		glVertex2f(5.7,7.2);
		glVertex2f(5.7,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,6.0);
		glVertex2f(8.1,7.2);
		glVertex2f(9.1,7.2);
		glVertex2f(9.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,6.0);
		glVertex2f(9.8,7.2);
		glVertex2f(10.8,7.2);
		glVertex2f(10.8,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,6.0);
		glVertex2f(6.4,7.2);
		glVertex2f(7.4,7.2);
		glVertex2f(7.4,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,6.0);
		glVertex2f(11.5,7.2);
		glVertex2f(12.5,7.2);
		glVertex2f(12.5,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,6.0);
		glVertex2f(13.3,7.2);
		glVertex2f(14.3,7.2);
		glVertex2f(14.3,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(15.1,6.0);
		glVertex2f(15.1,7.2);
		glVertex2f(16.1,7.2);
		glVertex2f(16.1,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.9,6.0);
		glVertex2f(16.9,7.2);
		glVertex2f(17.9,7.2);
		glVertex2f(17.9,6.0);
	glEnd();




	glColor3ub(255,255,0); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,9.8);
		glVertex2f(3.0,11.0);
		glVertex2f(4.0,11.0);
		glVertex2f(4.0,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.7,9.8);
		glVertex2f(4.7,11.0);
		glVertex2f(5.7,11.0);
		glVertex2f(5.7,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.1,9.8);
		glVertex2f(8.1,11.0);
		glVertex2f(9.1,11.0);
		glVertex2f(9.1,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.8,9.8);
		glVertex2f(9.8,11.0);
		glVertex2f(10.8,11.0);
		glVertex2f(10.8,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.4,9.8);
		glVertex2f(6.4,11.0);
		glVertex2f(7.4,11.0);
		glVertex2f(7.4,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.5,9.8);
		glVertex2f(11.5,11.0);
		glVertex2f(12.5,11.0);
		glVertex2f(12.5,9.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(13.3,9.8);
		glVertex2f(13.3,11.0);
		glVertex2f(14.3,11.0);
		glVertex2f(14.3,9.8);
	glEnd();

	glColor3f(0.329412,0.329412,0.329412); //top-cover
	glBegin(GL_POLYGON);
		glVertex2f(1.5,12.0);
		glVertex2f(1.5,12.5);
		glVertex2f(16.0,12.5);
		glVertex2f(16.0,12.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,16.0);
		glVertex2f(5.0,16.0);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,13.5);
		glVertex2f(5.0,13.5);
		glVertex2f(5.0,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,14.5);
		glVertex2f(2.5,15.5);
		glVertex2f(5.0,15.5);
		glVertex2f(5.0,14.5);
	glEnd();

	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,16.0);
		glVertex2f(8.5,16.0);
		glVertex2f(8.5,12.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,14.5);
		glVertex2f(6.0,15.5);
		glVertex2f(8.5,15.5);
		glVertex2f(8.5,14.5);
	glEnd();

	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,13.5);
		glVertex2f(8.5,13.5);
		glVertex2f(8.5,12.5);
	glEnd();
}

void bird(){

 glPushMatrix();
    glTranslatef(.01,1000-.01, 0.0);
    glTranslatef(birdPosition,00, 0.0);
    glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();


///bird 3
	glTranslatef(birdPosition,48, 0.0);
	glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);;
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();



    glPopMatrix();
// birds x black
    glPushMatrix();
    glTranslatef(.2,900, 0);
    glTranslatef(birdPosition,00, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

	///bird 2



///bird 3
	glTranslatef(0,48, 0.0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);///text school
    glPushMatrix();
    glTranslatef(60, 125, 0);
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();

	glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(740, 605, 0);

    glPopMatrix();

	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

///bird 4
    glTranslatef(0,-98, 0.0);
	glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(255,255,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,255,255);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,255,255);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
///bird 5
    glTranslatef(50,40, 0.0);
	glColor3ub(255, 170, 0);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(255, 255,255);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(255, 255,255);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(255, 255,255);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	///bird 6
    glTranslatef(50,30,0);
	glColor3ub(5, 85, 144); //bdy
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(5, 85, 144); //head
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
///bird 5
    glTranslatef(-155,40, 0.0);
	glColor3ub(5, 176, 144);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(0, 94, 232);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
   glColor3ub(0, 94, 232);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(0, 94, 232);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	///bird 8 pink
    glTranslatef(0,-130, 0.0);
	glColor3ub(250, 9, 243);// body
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(250, 9, 243); // head
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(205, 176, 251); //left pakha
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(205, 176, 251); //rigght pakha
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();


    glPopMatrix();

}

void DayView()
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

drawBackground(0,110,
                  1,1.2);




glPushMatrix();
glTranslatef(sunXAxis,0.0f,0.0f);
drawCircle(1050, 850,
		250, 250, 0,                 //sun motion
		7, 14,
		5);
glPopMatrix();


glPushMatrix();
glTranslatef(700,580.0f,0.0f); //ship small
ship_a();
glPopMatrix();


glPushMatrix();
glTranslatef(shipPosition,550.0f,0.0f); //ship
ship();
glPopMatrix();







glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCould(-1500,100,                          //first cloud motion
          4,2);
glPopMatrix();


glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCould(-100,500,                        //third cloud motion
          2,.8);
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCould(100,580,                        //second cloud motion
          1,.8);
glPopMatrix();

//trash1
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(370, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//trash 2
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1400, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//t3
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2000, 200, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//t4
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2400, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();





glPushMatrix();
glTranslatef(humanPosition,0.0f,0.0f);





//human

    drawHumam(50,320,
            .3,.35,
            250,0,0);  //1

   drawHumam(500,400,
            .3,.35,
        250,150,0); //2
   drawHumam(600,350,
            .3,.35,
           50,150,100); //3

   drawHumam(200,350,
            .3,.35,
        50,150,100); //4



drawHumam(700,450,
            .3,.35,  //5
        50,150,100);

 drawHumam(750,450 ,
            .3,.35, //6
        50,150,100);

        drawHumam(920,370, //7
            .3,.35,
        50,150,100);
 drawHumam(1000,500,
            .3,.35, //8
        50,150,100);


        drawHumam(1100  ,520,
            .3,.35, //9
        50,150,100);

  drawHumam(1250  ,500,
            .3,.35, //10
        50,150,100);


        drawHumam(1480,450,
            .3,.35,  //5
        50,150,100);

 drawHumam(1450,450 ,
            .3,.35, //6
        50,150,100);

        drawHumam(1600,370, //7
            .3,.35,
        50,150,100);
 drawHumam(1700,500,
            .3,.35, //8
        50,150,100);


        drawHumam(1750  ,520,
            .3,.35, //9
        50,150,100);

  drawHumam(1780  ,500,
            .3,.35, //10
        50,150,100);


        drawHumam(2100  ,320,
            .3,.35, //9
        50,150,100);

  drawHumam(2050  ,300,
            .3,.35, //10
        50,150,100);

 glPopMatrix();



 //bench 2
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
 //bench 1
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(300, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 3
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1500, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 4
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 5
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1800, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 6
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2100, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench7
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2500, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();

//bench 8
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 9
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(3000, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();






glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
//glScalef(2,2,0);
coconut_tree();          //coconuttree
glPopMatrix();



PS_drawRoad(-2000,-600,
             6,3);





glPushMatrix();
glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);

glPopMatrix();





glPushMatrix();
glTranslatef(travellcarPosition1,0.0f,0.0f);
travellCar(0,20,
          2.5,2.9);                            //travell car
glPopMatrix();


bird();                          //bird



glEnd();
glFlush();


}


void NightView()
{

glClear (GL_COLOR_BUFFER_BIT);
//glColor3ub (128, 128, 128);
glPointSize(5.0);

drawBackgroundNight(0,110,
                  1,1.2);


glPushMatrix();
glTranslatef(sunXAxis,0.0f,0.0f);
drawCircle(1050, 850,
		255, 255, 255,                 //moon motion
		7, 14,
		5);
glPopMatrix();

glPushMatrix();
glTranslatef(700,580.0f,0.0f); //ship small
ship_a_1();
glPopMatrix();

glPushMatrix();
glTranslatef(shipPosition,550.0f,0.0f);
glBegin(GL_POLYGON);
      glColor3ub (255,255,0);
    glVertex2i(230,70);
	glVertex2i(350,20);          //head light
	glVertex2i(450,30);
	 glVertex2i(200,90);
   glEnd();
ship1();
glPopMatrix();


glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCould(-800,500,                          //first cloud motion
          2,1);
glPopMatrix();


glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCould(100,500,                        //third cloud motion
          1.5,.8);
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCould(100,580,                        //second cloud motion
          1,.8);
glPopMatrix();



//trash1
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(370, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//trash 2
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1400, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//t3
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2000, 200, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//t4
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2400, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();


glPushMatrix();
glTranslatef(humanPosition,0.0f,0.0f);

// forest


 //human


   drawHumam(600,350,
            .3,.35,
           50,150,100); //3

   drawHumam(200,350,
            .3,.35,
        50,150,100);
        drawHumam(700,450,
            .3,.35,  //5
        50,150,100);



        drawHumam(920,370, //7
            .3,.35,
        50,150,100);
 drawHumam(1000,500,
            .3,.35, //8
        50,150,100);



  drawHumam(1250  ,500,
            .3,.35, //10
        50,150,100);


        drawHumam(1480,450,
            .3,.35,  //5
        50,150,100);

 drawHumam(1450,450 ,
            .3,.35, //6
        50,150,100);

        drawHumam(1600,370, //7
            .3,.35,
        50,150,100);



        drawHumam(1750  ,520,
            .3,.35, //9
        50,150,100);

  drawHumam(1780  ,500,
            .3,.35, //10
        50,150,100);

  drawHumam(2050  ,300,
            .3,.35, //10
        50,150,100);






 glPopMatrix();

 //bench 2
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
 //bench 1
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(300, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 3
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1500, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 4
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 5
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1800, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 6
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2100, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench7
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2500, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();

//bench 8
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 9
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(3000, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();




glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
//glScalef(2,2,0);
coconut_tree();          //coconuttree
glPopMatrix();


PS_drawRoad(-2000,-600,
             6,3);







glPushMatrix();
glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);

glPopMatrix();






glPushMatrix();
glTranslatef(travellcarPosition1,0.0f,0.0f);

glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex2i(230,70);
	glVertex2i(350,20);          //head light
	glVertex2i(450,30);
	 glVertex2i(200,90);
   glEnd();
travellCar(0,20,
          2.5,2.9);    //travell car
glPopMatrix();


//bird();                          //bird

glFlush();

}

void RainView()
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);




drawBackgroundRain(0,110,
                  1,1.2);



glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCouldRain(-800,500,                          //first cloud motion
          2,1);
glPopMatrix();


glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCouldRain(100,500,                        //third cloud motion
          1.5,.8);
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCouldRain(100,580,                        //second cloud motion
          1,.8);
glPopMatrix();


//trash1
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(370, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//trash 2
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1400, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//t3
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2000, 200, 0);
glScalef(14,14,0);
trash();
glPopMatrix();
//t4
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2400, 100, 0);
glScalef(14,14,0);
trash();
glPopMatrix();


glPushMatrix();
glTranslatef(100,460.0f,0.0f); //ship small

ship_a_1();
glPopMatrix();

glPushMatrix();
glTranslatef(400,430.0f,0.0f);
ship1();
glPopMatrix();



glPushMatrix();



 glPopMatrix();

 //bench 2
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
 //bench 1
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(300, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 3
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1500, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 4
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 5
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(1800, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 6
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2100, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench7
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2500, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();

//bench 8
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(2700, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();
//bench 9
glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(3000, 300, 0);
glScalef(4,4, 0);
bench();
glPopMatrix();



 glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
//glScalef(2,2,0);
coconut_tree();          //coconuttree
glPopMatrix();

PS_drawRoad(-2000,-600,
             6,3);







glPushMatrix();
glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);

glPopMatrix();





glPushMatrix();
glTranslatef(travellcarPosition1,0.0f,0.0f);
glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex2i(230,70);
	glVertex2i(350,20);          //head light
	glVertex2i(450,30);
	 glVertex2i(200,90);
   glEnd();
travellCar(0,20,
          2.5,2.9);                            //travell car
glPopMatrix();
glEnd();


//bird();                          //bird




glFlush();










rain();
glEnd();
glFlush();


}

void update(int value) {


  cloud1Position+=cloud1speed;
  cloud2Position+=cloud2speed;
  cloud3Position+=cloud3speed;
  sunXAxis-=sunspeed;

  roadMiddleWhiteMark-=roadMiddleWhiteMarkSpeed;
humanPosition1+=humanspeed;
  humanPosition2+=humanspeed;
  humanPosition3+=humanspeed;
  humanPosition4+=humanspeed;
  humanPosition5+=humanspeed;
  humanPosition-=humanspeed;
  shipPosition+=shipSpeed;
  travellcarPosition1+=travellcarspeed+.01;

  birdPosition+=birdspeed;
  cocoPosition-=cocoSpeed;
  roadUpperWhiteBlackMark-=roadUpperWhiteBlackMarkSpeed;

//    if(housePosition<-2200)
  //{
      //housePosition=0;
  //}

  if(birdPosition>1400)
  {
      birdPosition=-100;
  }

   if(cocoPosition<-2500)
  {
      cocoPosition=500;
  }

  if(sunXAxis<-1100)    //sun reassign position
  {
      sunXAxis=0;
  }

    if(cloud1Position>800)    //cloud 1 reassign position
  {
      cloud1Position=-900;
  }
  if(cloud2Position<-1200)       //cloud 2 reassign position
  {
      cloud2Position=300;
  }
    if(cloud3Position>500)     //cloud 3 reassign position
  {
      cloud3Position=-700;
  }

 if(shipPosition>1000)     //cloud 3 reassign position
  {
      shipPosition=-700;
  }

 if(roadMiddleWhiteMark<-400)
 {
     roadMiddleWhiteMark=0;     //middle road white  motion
 }

  if(roadUpperWhiteBlackMark<-800)
 {
     roadUpperWhiteBlackMark=0;     //middle road white  motion
 }

if(humanPosition1>50)
 {
     humanPosition1=-500;     //firse human
 }
  if(humanPosition2-70>50)
 {
     humanPosition2=-430;        // second human;
 }
   if(humanPosition3-140>50)
 {
     humanPosition3=-360;        // trird human;
 }
    if(humanPosition4-210>50)
 {
     humanPosition4=-300;        // fourth human;
 }

     if(humanPosition5-280>50)
 {
     humanPosition5=-250;        // fifth human;
 }
      if(humanPosition>800)
 {
     humanPosition=-450;        // fifth human;
 }


 if(travellcarPosition1>1000)
 {
     travellcarPosition1=-1000;           //travell car motion
 }

  if(travellcarPosition2>1000)
 {
     travellcarPosition2=-500;          //travell car motion
 }


	glutPostRedisplay();
    glutTimerFunc(1, update, 0);
}

void display(void)
{

glClear (GL_COLOR_BUFFER_BIT);
//glColor3ub (128, 128, 128);
glPointSize(5.0);

DayView();
glEnd();
glFlush ();

}
void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {


  break;
    case 'd':
   //   PlaySound(NULL,0,0);
       //PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
   //    PlaySound(TEXT("travell.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
      glutDisplayFunc(DayView);



      break;
    case 'n':

      //  PlaySound(NULL,0,0);
    //   PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        glutDisplayFunc(NightView);

        break;


         break;
    case 'r':
       // PlaySound(NULL,0,0);
     //   PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        glutDisplayFunc(RainView);
        break;


        default:
     glutPostRedisplay();
    break;
	}
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
     //        PlaySound(NULL,0,0);
       //PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			glutDisplayFunc(NightView);


	}


		if (button == GLUT_RIGHT_BUTTON)
	{

     //        PlaySound(NULL,0,0);
       //PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
   //    PlaySound(TEXT("travell.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			glutDisplayFunc(DayView);


	}
			if (button == GLUT_MIDDLE_BUTTON)
	{

     //       PlaySound(NULL,0,0);
       // PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			glutDisplayFunc(RainView);


	}
}

void init() {
   glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}
int main(int argc,char** argv)
{


    printf("\nEnter 'd' for day view.");
    printf("\nEnter 'n' for night view.");
    printf("\nEnter 'r' for rain view.");


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("SEA SIDE BEACH VIEW");     // creating the window
	//glutFullScreen();       // making the window full screen
	//glutInitWindowPosition(0,0);
	//PlaySound(TEXT("travell.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	glutDisplayFunc(DayView);
	init();
	glutTimerFunc(1, update, 0);

	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(handleMouse);
	//glutTimerFunc(10, update, 0);

	glutMainLoop();
	return 0;
}
