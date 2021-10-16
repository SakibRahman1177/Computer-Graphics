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
GLfloat cloud2Position=0;
GLfloat cloud2speed= -0.8;
GLfloat cloud3Position=0;
GLfloat cloud3speed=0.4;
GLfloat birdPosition=0;
GLfloat birdspeed=0.5;
GLfloat sunXAxis=0;
GLfloat sunspeed=0.2;
GLfloat travellcarPosition1=0;
GLfloat travellcarPosition2=0;
GLfloat travellcarspeed=0;
GLfloat treePosition=0;
GLfloat treespeed=6;
GLfloat lampPosition=0;
GLfloat lampspeed=6;
GLfloat buildingPosition=0;
GLfloat buildingPosition1=0;
GLfloat buildingPosition2=0;
GLfloat buildingSpeed=5;
GLfloat buildingSpeed1=5;
GLfloat buildingSpeed2=5;
GLfloat hospitalPosition=0;
GLfloat hospitalSpeed=5;
GLfloat roadUpperWhiteBlackMark=0;
GLfloat roadUpperWhiteBlackMarkSpeed=1;
GLfloat roadMiddleWhiteMark=0;
GLfloat roadMiddleWhiteMarkSpeed=1.5;
GLfloat mountainPosition=0;
GLfloat mountainSpeed=5;
GLfloat humanPosition1=0;
GLfloat humanspeed=0.01;
GLfloat humanPosition2=0;
GLfloat humanPosition3=0;
GLfloat humanPosition4=0;
GLfloat humanPosition5=0;
GLfloat humanPosition=0;
GLfloat housePosition=0;
GLfloat houseSpeed=5;
GLfloat shipPosition=0;
GLfloat shipSpeed=0.1;
GLfloat cocoPosition=0;
GLfloat cocoSpeed=5;


void drawCircle(GLfloat x, GLfloat y,GLfloat r, GLfloat g, GLfloat b,GLfloat sx, GLfloat sy,GLfloat radius){
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
void drawSemiCircle(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy,GLfloat r, GLfloat g, GLfloat b,GLfloat radius,GLfloat start_angle, GLfloat end_angle){
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

void drawTree(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bark
	glBegin(GL_POLYGON);
	//glColor3ub(86, 46, 11);
	glColor3ub(86, 46, 11);
	glVertex2f(0, -10);
	glVertex2f(40, -10);
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




	// Apples
	drawCircle(27, 234, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-15, 270, 255, 0, 0, 1, 1.2, 5);
	drawCircle(47, 255, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-2, 228, 255, 0, 0, 1, 1.2, 5);
	drawCircle(72, 216, 255, 0, 0, 1, 1.2, 5);

	glPopMatrix();
}

void drawHumamsShirtAndTrousers(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bottom Shirt
	glColor3ub(shirt_r, shirt_g, shirt_b);
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
	glColor3ub(37, 107, 202);
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
		.6, .5,
		shirt_r, shirt_g, shirt_b);

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

void hut(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

     glColor3ub(204, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2i(80, 310);
    glVertex2i(80, 390);
    glVertex2i(140, 390);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(80, 310);
    glVertex2i(80, 390);
    glVertex2i(140, 390);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

     glColor3ub(0, 123, 240);
     glBegin(GL_TRIANGLES);
     glVertex2i(80, 390);
     glVertex2i(110, 450);
     glVertex2i(140, 390);
     glEnd();

    glColor3ub(0, 0, 0);
     glBegin(GL_LINE_LOOP);
     glVertex2i(80, 390);
     glVertex2i(110, 450);
     glVertex2i(140, 390);
     glEnd();

    glColor3ub(204, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 390);
    glVertex2i(240, 390);
    glVertex2i(240, 310);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(140, 390);
    glVertex2i(240, 390);
    glVertex2i(240, 310);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(110, 450);
    glVertex2i(200, 450);
    glVertex2i(240, 390);
    glVertex2i(140, 390);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(110, 450);
    glVertex2i(200, 450);
    glVertex2i(240, 390);
    glVertex2i(140, 390);
    //glPopMatrix();
    glEnd();

    ///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(100, 310);
    glVertex2i(100, 370);
    glVertex2i(120, 370);
    glVertex2i(120, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 310);
    glVertex2i(100, 370);
    glVertex2i(120, 370);
    glVertex2i(120, 310);
    glEnd();


    ///Window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(160, 370);
    glVertex2i(180, 370);
    glVertex2i(180, 340);
    glVertex2i(160, 340);
    //glPopMatrix();
    glEnd();

        glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(160, 370);
    glVertex2i(180, 370);
    glVertex2i(180, 340);
    glVertex2i(160, 340);
    //glPopMatrix();
    glEnd();

    ///Window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(220, 370);
    glVertex2i(200, 370);
    glVertex2i(200, 340);
    glVertex2i(220, 340);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(220, 370);
    glVertex2i(200, 370);
    glVertex2i(200, 340);
    glVertex2i(220, 340);
    glEnd();


    glPopMatrix();
}

void well(){


    glPushMatrix();
    glTranslatef(2000, 80, 0);
    glScalef(.8, 1, 0);


     ///well

    glColor3ub(51, 153, 255);
    glBegin(GL_POLYGON);
    glVertex2i(180, 300);
    glVertex2i(200, 290);
    glVertex2i(220, 290);
    glVertex2i(240, 300);
    glVertex2i(220, 310);
    glVertex2i(200, 310);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(180, 300);
    glVertex2i(200, 290);
    glVertex2i(220, 290);
    glVertex2i(240, 300);
    glVertex2i(220, 310);
    glVertex2i(200, 310);
    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(153, 102, 51);
    glVertex2i(180, 260);
    glVertex2i(200, 250);
    glVertex2i(220, 250);
    glVertex2i(240, 260);

    glVertex2i(240, 300);
    glVertex2i(220, 290);
    glVertex2i(200, 290);
     glVertex2i(180, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);

    glColor3ub(0, 0, 0);
    glVertex2i(180, 260);
    glVertex2i(200, 250);
    glVertex2i(220, 250);
    glVertex2i(240, 260);

    glVertex2i(240, 300);
    glVertex2i(220, 290);
    glVertex2i(200, 290);
     glVertex2i(180, 300);
    glEnd();

    ///Well's upper part
    glBegin(GL_LINE_STRIP);

    glColor3ub(0, 0, 0);
    glVertex2i(180, 300);
    glVertex2i(180, 340);
    glVertex2i(240, 340);
    glVertex2i(240, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex2i(200, 330);
    glVertex2i(200, 350);
    glVertex2i(220, 350);
    glVertex2i(220, 330);
    glEnd();

    glBegin(GL_LINE_LOOP);

    glColor3ub(0, 0, 0);
    glVertex2i(200, 330);
    glVertex2i(200, 350);
    glVertex2i(220, 350);
    glVertex2i(220, 330);
    glEnd();

    glPopMatrix();

}

void drawMountain(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy) {

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);
		// Background
	glBegin(GL_POLYGON);
	glColor3ub(85,65,36); // mountain color
	glVertex2f(-50, 150);
	glVertex2f(50, 400);
	glVertex2f(200, 150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(95,65,36); // mountain color
	glVertex2f(80, 150);
	glVertex2f(250, 450);
	glVertex2f(400, 150);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(75,55,26); // mountain color
	glVertex2f(50, 150);
	glVertex2f(150, 400);
	glVertex2f(300, 150);
	glEnd();



	glPopMatrix();
}

void drawMountain2(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


        glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.0f);
  //	glColor3ub(5,6,6); // mountain color
  	glVertex2f(-50, 150);
  	glVertex2f(50, 420);
  	glVertex2f(150, 150);
  	glEnd();


  		glBegin(GL_POLYGON);
  	glColor3ub(0, 128, 0); // mountain color
  	glVertex2f(-70, 150);
  	glVertex2f(50, 420);
  	glVertex2f(220, 150);
  	glEnd();
  			glBegin(GL_POLYGON);
  			glColor3f(0.0f, 1.0f, 0.0f);
  	//glColor3ub(0,0,1); // mountain color
  	glVertex2f(100, 150);
  	glVertex2f(50, 420);
  	glVertex2f(-100, 150);
  	glEnd();

  	      glBegin(GL_POLYGON);
  	glColor3ub(0, 128, 0); // mountain color
  	glVertex2f(50, 150);
  	glVertex2f(150, 490);
  	glVertex2f(420, 150);
  	glEnd();

  	glBegin(GL_POLYGON);
  	glColor3f(0.0f, 0.1f, 0.0f);
  //	glColor3ub(95,65,36); // mountain color
  	glVertex2f(80, 150);
  	glVertex2f(250, 470);
  	glVertex2f(400, 150);
  	glEnd();

/*  	    glBegin(GL_POLYGON);
  	glColor3ub(0, 128, 0); // mountain color
  	glVertex2f(50, 150);
  	glVertex2f(150, 440);
  	glVertex2f(300, 150);
  	glEnd();
  	  	    glBegin(GL_POLYGON);
  	glColor3ub(0, 128, 0); // mountain color
  	glVertex2f(-80, 150);
  	glVertex2f(150, 490);
  	glVertex2f(210, 150);
  	glEnd();*/

	glPopMatrix();
}

void school(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    /// Middle body
	glColor3ub(173, 151, 9);
    glBegin(GL_QUADS);
    glVertex2i(550, 350);
    glVertex2i(550, 525);
	glVertex2i(750, 525);
	glVertex2i(750, 350);
	glEnd();

	glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(550, 350);
    glVertex2i(550, 525);
	glVertex2i(750, 525);
	glVertex2i(750, 350);
	glEnd();

	///window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(570, 370);
	glVertex2i(620, 370);
	glVertex2i(620, 420);
	glVertex2i(570, 420);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
     glVertex2i(570, 370);
	glVertex2i(620, 370);
	glVertex2i(620, 420);
	glVertex2i(570, 420);
    glEnd();

     /// 2nd window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(680, 370);
	glVertex2i(730, 370);
	glVertex2i(730, 420);
	glVertex2i(680, 420);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
     glVertex2i(680, 370);
	glVertex2i(730, 370);
	glVertex2i(730, 420);
	glVertex2i(680, 420);
    glEnd();

    ///3rd window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(680, 460);
	glVertex2i(730, 460);
	glVertex2i(730, 505);
	glVertex2i(680, 505);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(680, 460);
	glVertex2i(730, 460);
	glVertex2i(730, 505);
	glVertex2i(680, 505);
    glEnd();

    ///4th window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(620, 460);
	glVertex2i(670, 460);
	glVertex2i(670, 505);
	glVertex2i(620, 505);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
   glVertex2i(620, 460);
	glVertex2i(670, 460);
	glVertex2i(670, 505);
	glVertex2i(620, 505);
    glEnd();

    ///5th window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(560, 460);
	glVertex2i(610, 460);
	glVertex2i(610, 505);
	glVertex2i(560, 505);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(560, 460);
	glVertex2i(610, 460);
	glVertex2i(610, 505);
	glVertex2i(560, 505);
    glEnd();

    ///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(635, 350);
	glVertex2i(665, 350);
	glVertex2i(665, 400);
	glVertex2i(635, 400);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(635, 350);
	glVertex2i(665, 350);
	glVertex2i(665, 400);
	glVertex2i(635, 400);
    glEnd();

    ///MIDDLE BODY UPPER
    glColor3ub(0, 102, 102);
    glBegin(GL_POLYGON);
    glVertex2i(750, 525);
	glVertex2i(730, 550);
	glVertex2i(500, 550);
	glVertex2i(480, 525);

    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(750, 525);
	glVertex2i(730, 550);
	glVertex2i(500, 550);
	glVertex2i(480, 525);

    glEnd();


	///left body
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(420, 260);
    glVertex2i(520, 260);
	glVertex2i(520, 435);
	glVertex2i(420, 435);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(420, 260);
    glVertex2i(520, 260);
	glVertex2i(520, 435);
	glVertex2i(420, 435);
    glEnd();

    ///wINDOW
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(440, 280);
    glVertex2i(500, 280);
	glVertex2i(500, 330);
	glVertex2i(440, 330);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(440, 280);
    glVertex2i(500, 280);
	glVertex2i(500, 330);
	glVertex2i(440, 330);
    glEnd();

    ///wINDOW2
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(440, 370);
    glVertex2i(500, 370);
	glVertex2i(500, 420);
	glVertex2i(440, 420);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(440, 370);
    glVertex2i(500, 370);
	glVertex2i(500, 420);
	glVertex2i(440, 420);
    glEnd();


    ///LEFT BODY SIDE

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(520, 260);
    glVertex2i(550, 350);
	glVertex2i(550, 525);
	glVertex2i(520, 435);
    glEnd();

     glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(520, 260);
    glVertex2i(550, 350);
	glVertex2i(550, 525);
	glVertex2i(520, 435);
    glEnd();

    ///LEFT SIDE UPPER PART
     glColor3ub(0, 102, 102);
    glBegin(GL_POLYGON);
    glVertex2i(420, 435);
	glVertex2i(520, 435);
	glVertex2i(550, 525);
	glVertex2i(480, 525);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(420, 435);
	glVertex2i(520, 435);
	glVertex2i(550, 525);
	glVertex2i(480, 525);
    glEnd();

    ///DEVIDING FLOOR

     glColor3ub(0, 0, 0);
    glBegin(GL_LINES);

    ///LEFT BODY
    glVertex2i(420, 348);
    glVertex2i(520, 348);

    ///MAIN BODY
	glVertex2i(550, 438);
    glVertex2i(750, 438);

    ///LEFT BODY SIDE
	glVertex2i(520, 348);
	glVertex2i(550, 438);
    glEnd();
    glPopMatrix();
}

void house(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

///house1
glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

glBegin(GL_POLYGON);

    glVertex3i(220, 350, 0);
    glVertex3i(380, 350, 0);
    glVertex3i(380, 450, 0);
    glVertex3i(220, 450, 0);


glEnd();

glColor3f(0, 0, 1);
glBegin(GL_POLYGON);

    glVertex3i(200, 450, 0);
    glVertex3i(400, 450, 0);
    glVertex3i(300, 650, 0);



glEnd();


glColor3f(1,1,0);
glBegin(GL_POLYGON);

    glVertex3i(280, 350, 0);
    glVertex3i(320, 350, 0);
    glVertex3i(320, 450, 0);
    glVertex3i(280, 450, 0);


glEnd();
///house2
glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

glBegin(GL_POLYGON);

    glVertex3i(220+200, 350+50, 0);
    glVertex3i(380+200, 350+50, 0);
    glVertex3i(380+200, 450+50, 0);
    glVertex3i(220+200, 450+50, 0);


glEnd();

glColor3f(1.444, .5, 0);
glBegin(GL_POLYGON);

    glVertex3i(200+200, 450+50, 0);
    glVertex3i(400+200, 450+50, 0);
    glVertex3i(300+200, 650+50, 0);



glEnd();


glColor3f(1,1,0);
glBegin(GL_POLYGON);

    glVertex3i(280+200, 350+50, 0);
    glVertex3i(320+200, 350+50, 0);
    glVertex3i(320+200, 450+50, 0);
    glVertex3i(280+200, 450+50, 0);


glEnd();
glPopMatrix();

}

void house2(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


/*         drawSemiCircle(500, 100,
 * 		9.2, 6.1,
 * 		400, 230, 255,
 *             18,
 * 		0, 560);
 */

///house1
glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

glBegin(GL_POLYGON);

    glVertex3i(220, 350, 0);
    glVertex3i(380, 350, 0);
    glVertex3i(380, 450, 0);
    glVertex3i(220, 450, 0);


glEnd();

glColor3f(0, 0, 1);
glBegin(GL_POLYGON);

    glVertex3i(200, 450, 0);
    glVertex3i(400, 450, 0);
    glVertex3i(300, 650, 0);



glEnd();


glColor3f(1,1,0);
glBegin(GL_POLYGON);

    glVertex3i(280, 350, 0);
    glVertex3i(320, 350, 0);
    glVertex3i(320, 450, 0);
    glVertex3i(280, 450, 0);


glEnd();
///house2
glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

glBegin(GL_POLYGON);

    glVertex3i(220+200, 350+50, 0);
    glVertex3i(380+200, 350+50, 0);
    glVertex3i(380+200, 450+50, 0);
    glVertex3i(220+200, 450+50, 0);


glEnd();

glColor3f(1.444, .5, 0);
glBegin(GL_POLYGON);

    glVertex3i(200+200, 450+50, 0);
    glVertex3i(400+200, 450+50, 0);
    glVertex3i(300+200, 650+50, 0);



glEnd();


glColor3f(1,1,0);
glBegin(GL_POLYGON);

    glVertex3i(280+200, 350+50, 0);
    glVertex3i(320+200, 350+50, 0);
    glVertex3i(320+200, 450+50, 0);
    glVertex3i(280+200, 450+50, 0);


glEnd();
glPopMatrix();

}

void building(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    double r1 = 175;
    double g1 = 238;
    double b1 = 238;

    //1st layer
    //1
    glBegin(GL_QUADS);
    glColor3ub (176, 196, 222);
    glVertex2i(0,160);
    glVertex2i(100,160);
    glVertex2i(100,310);
    glVertex2i(0,310);
    //2
    glVertex2i(172,290);
    glVertex2i(200,290);
    glVertex2i(200,270);
    glVertex2i(172,270);

    glVertex2i(280,160);
    glVertex2i(295,160);
    glVertex2i(295,280);
    glVertex2i(280,280);

    glVertex2i(305,160);
    glVertex2i(295,160);
    glVertex2i(295,270);
    glVertex2i(305,270);

    glVertex2i(305,160);
    glVertex2i(360,160);
    glVertex2i(360,320);
    glVertex2i(305,320);
    //3
    glVertex2i(420,160);
    glVertex2i(470,160);
    glVertex2i(470,320);
    glVertex2i(425,320);

    //4
    glVertex2i(620,160);
    glVertex2i(690,160);
    glVertex2i(690,300);
    glVertex2i(620,300);

    glVertex2i(690,160);
    glVertex2i(710,160);
    glVertex2i(710,250);
    glVertex2i(690,250);

    glVertex2i(760,160);
    glVertex2i(710,160);
    glVertex2i(710,330);
    glVertex2i(760,330);
    glEnd();
    //2nd layer
    glBegin(GL_QUADS);
    glColor3ub (180,180,180);
    //1
    glVertex2i(152,220);
    glVertex2i(72,220);
    glVertex2i(72,290);
    glVertex2i(152,290);

    glVertex2i(142,310); //from roof
    glVertex2i(82,310);
    glVertex2i(82,290);
    glVertex2i(142,290);

    glVertex2i(137,310);
    glVertex2i(87,310);
    glVertex2i(87,315);
    glVertex2i(137,315);

    glVertex2i(127,320);
    glVertex2i(97,320);
    glVertex2i(97,315);
    glVertex2i(127,315);

    //3
    glVertex2i(280,160);
    glVertex2i(200,160);
    glVertex2i(200,290);
    glVertex2i(280,290);

    glVertex2i(270,320);
    glVertex2i(210,320);
    glVertex2i(210,290);
    glVertex2i(270,290);
    //5
    glVertex2i(440,300);
    glVertex2i(360,300);
    glVertex2i(360,160);
    glVertex2i(440,160);


    //2
    glColor3ub (200,200,200); //light one
    glVertex2i(152,160);
    glVertex2i(200,160);
    glVertex2i(200,270);
    glVertex2i(152,270);

    //4
    glVertex2i(280,250);
    glVertex2i(360,250);
    glVertex2i(360,160);
    glVertex2i(280,160);

    glEnd();

    //1st layer
    glColor3ub (132,132,132);
    glBegin(GL_QUADS);
    //1
    glVertex2i(0,160);
    glVertex2i(40,160);
    glVertex2i(40,230);
    glVertex2i(0,230);

    //2
    glVertex2i(45,160);
    glVertex2i(92,160);
    glVertex2i(92,265);
    glVertex2i(45,265);

    //3
    glVertex2i(87,160);
    glVertex2i(160,160);
    glVertex2i(160,220);
    glVertex2i(87,220);

    glVertex2i(160,160);
    glVertex2i(190,160);
    glVertex2i(190,190);
    glVertex2i(160,190);

    glVertex2i(190,160);
    glVertex2i(200,160);
    glVertex2i(200,165);
    glVertex2i(190,165);
    //4
    glVertex2i(200,160);
    glVertex2i(230,160);
    glVertex2i(230,220);
    glVertex2i(200,220);

    glVertex2i(230,160);
    glVertex2i(235,160);
    glVertex2i(235,205);
    glVertex2i(230,205);

    glVertex2i(235,160);
    glVertex2i(255,160);
    glVertex2i(255,190);
    glVertex2i(235,190);

    //5
    glVertex2i(260,160);
    glVertex2i(310,160);
    glVertex2i(310,200);
    glVertex2i(260,200);
    //6
    glVertex2i(310,160);
    glVertex2i(380,160);
    glVertex2i(380,230);
    glVertex2i(310,230);

    glVertex2i(400,160);
    glVertex2i(380,160);
    glVertex2i(380,200);
    glVertex2i(400,200);
    //7
    glVertex2i(410,160);
    glVertex2i(470,160);
    glVertex2i(470,240);
    glVertex2i(410,240);
    //8
    glVertex2i(477,305);
    glVertex2i(513,305);
    glVertex2i(513,285);
    glVertex2i(477,285);

    glVertex2i(482,305);
    glVertex2i(507,305);
    glVertex2i(507,310);
    glVertex2i(482,310);

    glVertex2i(487,310);
    glVertex2i(502,310);
    glVertex2i(502,315);
    glVertex2i(487,315);

    glVertex2i(492,310);
    glVertex2i(498,310);
    glVertex2i(498,330);
    glVertex2i(492,330);

    //9
    glVertex2i(590,160);
    glVertex2i(650,160);
    glVertex2i(650,280);
    glVertex2i(590,280);

    glVertex2i(760,160);
    glVertex2i(670,160);
    glVertex2i(670,220);
    glVertex2i(760,220);


    //roof
    glColor3ub (112,112,112);
    //1
    glVertex2i(0,230);
    glVertex2i(40,230);
    glVertex2i(40,235);
    glVertex2i(0,235);

    glVertex2i(10,235);
    glVertex2i(30,235);
    glVertex2i(30,240);
    glVertex2i(10,240);

    //2
    glVertex2i(48,270);
    glVertex2i(87,270);
    glVertex2i(87,275);
    glVertex2i(48,275);

    glVertex2i(52,275);
    glVertex2i(70,275);
    glVertex2i(70,280);
    glVertex2i(52,280);

    //3
    glVertex2i(87,220);
    glVertex2i(157,220);
    glVertex2i(157,225);
    glVertex2i(87,225);

    glVertex2i(87,190);
    glVertex2i(160,190);
    glVertex2i(160,200);
    glVertex2i(87,200);
    //4
    glVertex2i(200,220);
    glVertex2i(230,220);
    glVertex2i(230,225);
    glVertex2i(200,225);

    glVertex2i(235,190);
    glVertex2i(255,190);
    glVertex2i(255,195);
    glVertex2i(235,195);

    //5
    glVertex2i(260,200);
    glVertex2i(310,200);
    glVertex2i(310,205);
    glVertex2i(260,205);

    glVertex2i(255,205);
    glVertex2i(310,205);
    glVertex2i(310,210);
    glVertex2i(255,210);
    //6
    glVertex2i(310,230);
    glVertex2i(380,230);
    glVertex2i(380,240);
    glVertex2i(310,240);

    glVertex2i(315,215);
    glVertex2i(325,215);
    glVertex2i(325,220);
    glVertex2i(315,220);

    glVertex2i(335,215);
    glVertex2i(345,215);
    glVertex2i(345,220);
    glVertex2i(335,220);

    glVertex2i(355,215);
    glVertex2i(365,215);
    glVertex2i(365,220);
    glVertex2i(355,220);

    glVertex2i(315,185);
    glVertex2i(335,185);
    glVertex2i(335,188);
    glVertex2i(315,188);

    glVertex2i(345,185);
    glVertex2i(365,185);
    glVertex2i(365,188);
    glVertex2i(345,188);
    //7
    glVertex2i(410,240);
    glVertex2i(470,240);
    glVertex2i(470,245);
    glVertex2i(410,245);
    //9
    glVertex2i(760,225);
    glVertex2i(670,225);
    glVertex2i(670,220);
    glVertex2i(760,220);

    glVertex2i(675,210);
    glVertex2i(760,210);
    glVertex2i(760,205);
    glVertex2i(675,205);

    //yellow
    glColor3ub (255,255,51);
    glVertex2i(270,190);
    glVertex2i(305,190);
    glVertex2i(305,193);
    glVertex2i(270,193);




    //shades
    //2
    glColor3ub (200,200,200);
    glVertex2i(48,265);
    glVertex2i(87,265);
    glVertex2i(87,270);
    glVertex2i(48,270);

    glVertex2i(50,160);
    glVertex2i(57,160);
    glVertex2i(57,255);
    glVertex2i(50,255);

    glVertex2i(65,160);
    glVertex2i(72,160);
    glVertex2i(72,255);
    glVertex2i(65,255);

    glVertex2i(80,160);
    glVertex2i(87,160);
    glVertex2i(87,255);
    glVertex2i(80,255);
    //8
    glColor3ub (180,180,180);
    glVertex2i(470,160);
    glVertex2i(530,160);
    glVertex2i(530,245);
    glVertex2i(470,245);

    glVertex2i(450,280);
    glVertex2i(540,280);
    glVertex2i(540,245);
    glVertex2i(450,245);

    glColor3ub (210,210,210);
    glVertex2i(455,280);
    glVertex2i(535,280);
    glVertex2i(535,285);
    glVertex2i(455,285);

    glVertex2i(470,240);
    glVertex2i(540,240);
    glVertex2i(540,245);
    glVertex2i(470,245);
    //9
    glColor3ub (160,160,160);
    glVertex2i(590,160);
    glVertex2i(530,160);
    glVertex2i(530,295);
    glVertex2i(590,295);

    glVertex2i(610,160);
    glVertex2i(670,160);
    glVertex2i(670,260);
    glVertex2i(610,260);


    //window and door
    //1
    glColor3ub (r1,g1,b1);
    glVertex2i(12,160);
    glVertex2i(26,160);
    glVertex2i(26,180);
    glVertex2i(12,180);

    glVertex2i(5,190);
    glVertex2i(12,190);
    glVertex2i(12,200);
    glVertex2i(5,200);

    glVertex2i(15,190);
    glVertex2i(22,190);
    glVertex2i(22,200);
    glVertex2i(15,200);

    glVertex2i(25,190);
    glVertex2i(32,190);
    glVertex2i(32,200);
    glVertex2i(25,200);

    glVertex2i(5,210);
    glVertex2i(12,210);
    glVertex2i(12,220);
    glVertex2i(5,220);

    glVertex2i(15,210);
    glVertex2i(22,210);
    glVertex2i(22,220);
    glVertex2i(15,220);

    glVertex2i(25,210);
    glVertex2i(32,210);
    glVertex2i(32,220);
    glVertex2i(25,220);

    //3
    glVertex2i(95,205);
    glVertex2i(110,205);
    glVertex2i(110,215);
    glVertex2i(95,215);

    glVertex2i(130,205);
    glVertex2i(145,205);
    glVertex2i(145,215);
    glVertex2i(130,215);

    glVertex2i(95,185);
    glVertex2i(110,185);
    glVertex2i(110,170);
    glVertex2i(95,170);

    glVertex2i(130,185);
    glVertex2i(145,185);
    glVertex2i(145,170);
    glVertex2i(130,170);

    glVertex2i(165,160);
    glVertex2i(180,160);
    glVertex2i(180,180);
    glVertex2i(165,180);
    //4
    glVertex2i(205,215);
    glVertex2i(215,215);
    glVertex2i(215,205);
    glVertex2i(205,205);

    glVertex2i(218,215);
    glVertex2i(228,215);
    glVertex2i(228,205);
    glVertex2i(218,205);

    glVertex2i(205,200);
    glVertex2i(215,200);
    glVertex2i(215,190);
    glVertex2i(205,190);

    glVertex2i(218,200);
    glVertex2i(228,200);
    glVertex2i(228,190);
    glVertex2i(218,190);

    glVertex2i(205,185);
    glVertex2i(210,185);
    glVertex2i(210,177);
    glVertex2i(205,177);

    glVertex2i(215,185);
    glVertex2i(220,185);
    glVertex2i(220,177);
    glVertex2i(215,177);

    glVertex2i(225,185);
    glVertex2i(230,185);
    glVertex2i(230,177);
    glVertex2i(225,177);

    //5
    glVertex2i(270,190);
    glVertex2i(285,190);
    glVertex2i(285,175);
    glVertex2i(270,175);

    glVertex2i(290,190);
    glVertex2i(305,190);
    glVertex2i(305,175);
    glVertex2i(290,175);

    glColor3ub (255,255,51);
    glVertex2i(270,190);
    glVertex2i(305,190);
    glVertex2i(305,193);
    glVertex2i(270,193);
    //6
    glColor3ub (r1,g1,b1);
    glVertex2i(315,215);
    glVertex2i(325,215);
    glVertex2i(325,195);
    glVertex2i(315,195);

    glVertex2i(335,215);
    glVertex2i(345,215);
    glVertex2i(345,195);
    glVertex2i(335,195);

    glVertex2i(355,215);
    glVertex2i(365,215);
    glVertex2i(365,195);
    glVertex2i(355,195);

    glVertex2i(315,185);
    glVertex2i(335,185);
    glVertex2i(335,170);
    glVertex2i(315,170);

    glVertex2i(345,185);
    glVertex2i(365,185);
    glVertex2i(365,170);
    glVertex2i(345,170);

    glVertex2i(385,170);
    glVertex2i(395,170);
    glVertex2i(395,180);
    glVertex2i(385,180);

    glVertex2i(382,185);
    glVertex2i(392,185);
    glVertex2i(392,195);
    glVertex2i(382,195);

    //7
    glVertex2i(420,230);
    glVertex2i(430,230);
    glVertex2i(430,210);
    glVertex2i(420,210);

    glVertex2i(450,230);
    glVertex2i(460,230);
    glVertex2i(460,210);
    glVertex2i(450,210);

    glVertex2i(420,200);
    glVertex2i(430,200);
    glVertex2i(430,180);
    glVertex2i(420,180);

    glVertex2i(450,200);
    glVertex2i(460,200);
    glVertex2i(460,180);
    glVertex2i(450,180);
    //8
    glVertex2i(502,295);
    glVertex2i(507,295);
    glVertex2i(507,287);
    glVertex2i(502,287);

    glVertex2i(492,295);
    glVertex2i(497,295);
    glVertex2i(497,287);
    glVertex2i(492,287);

    glVertex2i(482,295);
    glVertex2i(487,295);
    glVertex2i(487,287);
    glVertex2i(482,287);

    glVertex2i(460,270);
    glVertex2i(490,270);
    glVertex2i(490,260);
    glVertex2i(460,260);

    glVertex2i(500,270);
    glVertex2i(530,270);
    glVertex2i(530,260);
    glVertex2i(500,260);

    glColor3ub (112,112,112);
    glVertex2i(480,240);
    glVertex2i(483,240);
    glVertex2i(483,160);
    glVertex2i(480,160);

    glVertex2i(490,240);
    glVertex2i(493,240);
    glVertex2i(493,160);
    glVertex2i(490,160);

    glVertex2i(500,240);
    glVertex2i(503,240);
    glVertex2i(503,160);
    glVertex2i(500,160);

    glVertex2i(510,240);
    glVertex2i(513,240);
    glVertex2i(513,160);
    glVertex2i(510,160);


    //9
    glColor3ub (r1,g1,b1);
    glVertex2i(620,175);
    glVertex2i(635,175);
    glVertex2i(635,195);
    glVertex2i(620,195);

    glVertex2i(660,175);
    glVertex2i(645,175);
    glVertex2i(645,195);
    glVertex2i(660,195);

    glVertex2i(620,205);
    glVertex2i(635,205);
    glVertex2i(635,200);
    glVertex2i(620,200);

    glVertex2i(660,205);
    glVertex2i(645,205);
    glVertex2i(645,200);
    glVertex2i(660,200);

    glVertex2i(620,210);
    glVertex2i(635,210);
    glVertex2i(635,235);
    glVertex2i(620,235);

    glVertex2i(660,210);
    glVertex2i(645,210);
    glVertex2i(645,235);
    glVertex2i(660,235);

    glVertex2i(552,280);
    glVertex2i(570,280);
    glVertex2i(570,250);
    glVertex2i(552,250);

    glVertex2i(552,240);
    glVertex2i(570,240);
    glVertex2i(570,210);
    glVertex2i(552,210);

    glVertex2i(552,200);
    glVertex2i(570,200);
    glVertex2i(570,170);
    glVertex2i(552,170);

    glVertex2i(680,175);
    glVertex2i(700,175);
    glVertex2i(700,205);
    glVertex2i(680,205);

    glVertex2i(725,175);
    glVertex2i(705,175);
    glVertex2i(705,205);
    glVertex2i(725,205);

    glVertex2i(730,175);
    glVertex2i(750,175);
    glVertex2i(750,205);
    glVertex2i(730,205);

    //2nd layer
    //4
    glColor3ub (r1,g1,b1);
    glVertex2i(290,240);
    glVertex2i(300,240);
    glVertex2i(300,230);
    glVertex2i(290,230);

    glVertex2i(290,220);
    glVertex2i(300,220);
    glVertex2i(300,210);
    glVertex2i(290,210);
    //5
    glVertex2i(435,295);
    glVertex2i(420,295);
    glVertex2i(420,245);
    glVertex2i(435,245);

    glVertex2i(400,295);
    glVertex2i(415,295);
    glVertex2i(415,245);
    glVertex2i(400,245);
    glEnd();
    glPopMatrix();
}

void print(char *string,
	GLfloat r, GLfloat g, GLfloat b, GLfloat a,
	GLint x, GLint y,
	GLfloat w, GLfloat h,
	GLfloat strokeSize) {
	glPushMatrix();

	glColor4f(r, g, b, a);
	glTranslatef(x, y, 0);
	glScalef(w, h, 0);

	glPointSize(strokeSize);
	glLineWidth(strokeSize);

	while (*string)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);

	glPopMatrix();

	glLineWidth(1);
	glPointSize(1);
}

void Hotels(){

    glPushMatrix();

    glTranslatef(3330, 110, 0);
    glScalef(2.1, 1.5, 0);
    glBegin(GL_QUADS);
    //White Billboard
    glColor3ub (205, 38, 38); //red
    glVertex2i(-10,150);
    glVertex2i(50,150);
    glVertex2i(50,220);
    glVertex2i(-10,220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub (255, 255, 255); //White
    glVertex2i(-8,155);
    glVertex2i(48,155);
    glVertex2i(48,215);
    glVertex2i(-8,215);
    glEnd();

    print("HIGHWAY", 0, 0, 0, 1, -4, 165, .07, .4, 1.5);

    glBegin(GL_QUADS);
    glColor3ub (0, 0, 0); //Black stand
    glVertex2i(18,10);
    glVertex2i(20,10);
    glVertex2i(20,150);
    glVertex2i(18,150);
    glEnd();

    glTranslatef(-30,90,0);
    glBegin(GL_QUADS);
    glColor3ub (77, 77, 77); //1st Building
    glVertex2i(80,110);
    glVertex2i(140,110);
    glVertex2i(140,350);
    glVertex2i(80,350);

    glColor3ub (127, 127, 127); //1st Building design
    glVertex2i(85,110);
    glVertex2i(88,110);
    glVertex2i(88,350);
    glVertex2i(85,350);

    glColor3ub (127, 127, 127);
    glVertex2i(90,110);
    glVertex2i(93,110);
    glVertex2i(93,350);
    glVertex2i(90,350);

    glColor3ub (135, 206, 250); //window  1
    glVertex2i(100,285);
    glVertex2i(115,285);
    glVertex2i(115,330);
    glVertex2i(100,330);

    glColor3ub (135, 206, 250);//2
    glVertex2i(120,285);
    glVertex2i(135,285);
    glVertex2i(135,330);
    glVertex2i(120,330);

    glColor3ub (135, 206, 250);//3
    glVertex2i(100,225);
    glVertex2i(115,225);
    glVertex2i(115,270);
    glVertex2i(100,270);

    glColor3ub (135, 206, 250);//4
    glVertex2i(120,225);
    glVertex2i(135,225);
    glVertex2i(135,270);
    glVertex2i(120,270);

    glColor3ub (135, 206, 250);//5
    glVertex2i(100,165);
    glVertex2i(115,165);
    glVertex2i(115,210);
    glVertex2i(100,210);

    glColor3ub (135, 206, 250);//6
    glVertex2i(120,165);
    glVertex2i(135,165);
    glVertex2i(135,210);
    glVertex2i(120,210);
    glEnd();


    glTranslatef(-65,0, 0);
    glBegin(GL_QUADS);
    glColor3ub (250, 235, 215); //2nd Building
    glVertex2i(210,310);
    glVertex2i(350,310);
    glVertex2i(350,110);
    glVertex2i(210,110);
	//glFlush ();
     glEnd();

    //2nd building design
    glBegin(GL_QUADS);
    glColor3ub (205, 183, 181); //Gate
    glVertex2i(250,165);
    glVertex2i(310,165);
    glVertex2i(310,110);
    glVertex2i(250,110);
	//glFlush ();
    glEnd();
    glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(250, 165);
	glVertex2f(310, 165);
    glEnd();
    glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(280, 110);
	glVertex2f(280, 165);
    glEnd();
    glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(310, 110);
	glVertex2f(310, 165);
    glEnd();
    glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
    glVertex2f(250, 110);
	glVertex2f(250, 165);
	glEnd();

    glBegin(GL_POLYGON);
    for(int i=180;i<=310;i=i+20){

	glColor3ub(135, 206, 250);
	glVertex2f(215, i);
	glVertex2f(215, 300);
	glVertex2f(345, 300);
	glColor3ub(97, 131, 159);
	glVertex2f(345, i);
	glEnd();

	// Tuition Rectangular Window Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(215, i);
	glVertex2f(215, 180);
	glVertex2f(345, 180);
	glVertex2f(345, i);
	glEnd();

	// Tuition Rectangular Window Panes
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(215, i);
	glVertex2f(215, 240);
	glVertex2f(220, 260);
	glVertex2f(300, 260);
    }
	glEnd();


    glBegin(GL_LINE_LOOP); //panels
	glColor3ub(20, 20, 20);
	glVertex2f(255, 180);
	glVertex2f(255, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(300, 180);
	glVertex2f(300, 300);
    glEnd();

    glTranslatef(275, 0, 0);
    glBegin(GL_QUADS);
    glColor3ub (139, 58, 58); //3rd Building
    glVertex2i(80,110);
    glVertex2i(130,110);
    glVertex2i(130,400);
    glVertex2i(80,400);

    glColor3ub (205, 155, 155); //3rd Building design
    glVertex2i(85,110);
    glVertex2i(90,110);
    glVertex2i(90,400);
    glVertex2i(85,400);

    glVertex2i(93,110);
    glVertex2i(98,110);
    glVertex2i(98,400);
    glVertex2i(93,400);

    glVertex2i(80,370);
    glVertex2i(130,370);
    glVertex2i(130,380);
    glVertex2i(80,380);

    //windows
    glColor3ub (174, 238, 238);//1
    glVertex2i(110,285);
    glVertex2i(125,285);
    glVertex2i(125,330);
    glVertex2i(110,330);

    //2
    glVertex2i(110,225);
    glVertex2i(125,225);
    glVertex2i(125,270);
    glVertex2i(110,270);

    //3
    glVertex2i(110,165);
    glVertex2i(125,165);
    glVertex2i(125,210);
    glVertex2i(110,210);
    glEnd();


    //4th Building
    glTranslatef(130, 0, 0);
    glScalef(0.4,0.62,0);
    glBegin(GL_POLYGON);
	glColor3ub(190, 190, 190);
	glVertex2f(25, 175);
	glVertex2f(270, 175);
	glColor3ub(190, 190, 190);
	glVertex2f(270, 550);
	glVertex2f(25, 550);
	glEnd();

	// Hotel Board
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(90, 525);
	glVertex2f(220, 525);
	glVertex2f(220, 475);
	glVertex2f(90, 475);
	glEnd();

	// Hotel Board Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(90, 525);
	glVertex2f(220, 525);
	glVertex2f(220, 475);
	glVertex2f(90, 475);
	glEnd();

	print("HOTEL", 0, 0, 128, 1, 110, 492, .17, .2, 1.5);



    //Rectangular Window
	glBegin(GL_POLYGON);
    for(int i=240;i<=450;i=i+40){

	glColor3ub(59, 91, 132);
	glVertex2f(50, i);
	glVertex2f(50, 440);
	glVertex2f(240, 440);
	glColor3ub(97, 131, 159);
	glVertex2f(240, i);
	glEnd();

	//Rectangular Window Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(50, i);
	glVertex2f(50, 240);
	glVertex2f(240, 240);
	glVertex2f(240, i);
	glEnd();

	//Rectangular Window Panes
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(150, i);
	glVertex2f(150, 240);
	glVertex2f(50, 260);
	glVertex2f(240, 260);
    }
	glEnd();

	//5th Building
    glTranslatef(250, 60, 0);
    glScalef(2.0,0.72,0);
    glBegin(GL_POLYGON);
	glColor3ub(152, 251, 152);
	glVertex2f(25, 175);
	glVertex2f(270, 175);
	glColor3ub(176, 224, 230);
	glVertex2f(270, 600);
	glVertex2f(25, 600);
	glEnd();

    //Rectangular Window
	glBegin(GL_POLYGON);
    for(int i=240;i<=450;i=i+40){

	glColor3ub(59, 91, 132);
	glVertex2f(50, i);
	glVertex2f(50, 490);
	glVertex2f(240, 490);
	glColor3ub(97, 131, 159);
	glVertex2f(240, i);
	glEnd();

	//Rectangular Window Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(50, i);
	glVertex2f(50, 240);
	glVertex2f(240, 240);
	glVertex2f(240, i);
	glEnd();

	//Rectangular Window Panes
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(150, i);
	glVertex2f(150, 240);
	glVertex2f(50, 260);
	glVertex2f(240, 260);
    }
	glEnd();
    drawTree(-380, 90, .1, .65);
    drawTree(-350, 80, .06, .35);
    drawTree(-365, 70, .04, .25);
    drawTree(-120, 95, .08, .65);
    drawTree(15, 95, .09, .65);
    drawTree(-190, 100, .04, .35);
    drawTree(25, 75, .04, .25);
    drawTree(245, 95, .09, .65);
	glPopMatrix();
}

void PS_drawRoad(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){


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

void DrawCloud(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){
    //Cloud

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawSemiCircle(500, 400,7.2, 5.1,200, 230, 255,10,0, 360);
    drawSemiCircle(480, 420,3.2, 5.1,200, 230, 255,10,0, 360);
    drawSemiCircle(520, 410,3.2, 5.1,200, 230, 255,10,0, 360);
    drawSemiCircle(510, 380,3.2, 5.1,200, 230, 255,10,0, 360);

    glPopMatrix();

    }

void bird(){
	///bird 1
    glPushMatrix();
    glTranslatef(.2,900, 0);
    glTranslatef(birdPosition,00, 0.0);
    glBegin(GL_QUADS);
    glColor3f(255,255,255); //----------------------White body------------------------
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);    //----------------------Yellow Head-----------------------
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);        //----------------------White body border-----------------
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);        //----------------------Yellow Head border----------------
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
    glColor3f(255,69,0);   //----------------Upper wing yellow------------------
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);   //-----------------Lower wing yellow-----------------
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);      //----------------Upper wing yellow border-----------
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);      //----------------Lower wing yellow border------------
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

	///bird 2

	glTranslatef(-55,-30, 0.0);
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
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

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
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
///bird 7
    glTranslatef(-155,40, 0.0);
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
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	///bird 8
    glTranslatef(0,-130, 0.0);
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

void ship(){


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

void bench(){

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

void coconut_tree(){

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

void DrawCloudRain(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){
    //Cloud

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawSemiCircle(500, 400,7.2, 5.1,119,136,153,10,0, 360);
    drawSemiCircle(480, 420,3.2, 5.1,119,136,153,10,0, 360);
    drawSemiCircle(520, 410,3.2, 5.1,119,136,153,10,0, 360);
    drawSemiCircle(510, 380,3.2, 5.1,119,136,153,10,0, 360);

    glPopMatrix();
    }

void drawBackground(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(0, 200, 0); // Sky Blue
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(1400, 90);
	glVertex2f(0, 90);
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

void drawSeaBackground(GLfloat tx, GLfloat ty,
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

	glPopMatrix();
}

void drawBackgroundNight(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(60,179,113); // Green Grass
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(0, 128, 0); // dark green
	glVertex2f(1400, 90);
	glVertex2f(0, 90);
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
		 drawCircle(700, 650,
		250, 250, 250,
		7, 14,
		.2);
		 drawCircle(800, 550,
		250, 250, 0,
		7, 14,
		.3);
		 drawCircle(650, 500,
		250, 250, 250,
		7, 14,
		.3);
		drawCircle(750, 380,
		250, 250, 250,
		7, 14,
		.3);
        drawCircle(150, 480,
		250, 250, 250,
		7, 14,
		.25);

		for(int i=0;i<500;i++)
        {

        int x=rand()%1100;
        int y=rand()%800;
        if(y>300){
         drawCircle(x, y,
		250, 250, 250,
		7, 14,
		.1);
        }
        }

	glPopMatrix();
}

void drawBackgroundRain(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(82, 163, 42); // Sky Blue
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(1400, 90);
	glVertex2f(0, 90);
	glEnd();

		// Background
	glBegin(GL_POLYGON);
	glColor3ub(65,105,225); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 400);
	glVertex2f(0, 400);
	glEnd();


	glPopMatrix();
}

void travellCar(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){


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

void drawbuilding(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);
		// Background
	glBegin(GL_POLYGON);
	glColor3ub(200,200,200);
	glVertex2f(-50, -50);
	glVertex2f(100, -50);
	glVertex2f(100, 650);
	glVertex2f(-50, 650);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(200,150,200);
	glVertex2f(100, 150);
	glVertex2f(250, 150);
	glVertex2f(250, 750);
	glVertex2f(100, 750);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(200,200,200);
	glVertex2f(250, 150);
	glVertex2f(350, 150);
	glVertex2f(350, 500);
	glVertex2f(250, 500);
	glEnd();



	glPopMatrix();
}

void drawbuilding1(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);
		// Background
	glBegin(GL_POLYGON);
	glColor3ub(50,132,132); // mountain color
	glVertex2f(0, -150);
	glVertex2f(300, -150);
	glVertex2f(300, 850);
	glVertex2f(200, 850);
	glVertex2f(185, 900);
	glVertex2f(160, 900);
	glVertex2f(160, 950);
	glVertex2f(130, 950);
	glVertex2f(130, 900);
	glVertex2f(115, 900);
	glVertex2f(100, 850);
	glVertex2f(0, 850);

	glEnd();

	glPopMatrix();
}

void drawbuilding2(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy){

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);
		// Background
	glBegin(GL_QUADS);
	glColor3ub(200,200,200);
	glVertex2f(50, -300);
	glVertex2f(440, -300);
	glVertex2f(440, 900);
	glVertex2f(50, 900);
//----------------window--------------
	glColor3ub (20,204,255);
	glVertex2f(120, 650);
	glVertex2f(220, 650);
	glVertex2f(220, 750);
	glVertex2f(120, 750);

	glColor3ub (20,204,255);
	glVertex2f(280, 650);
	glVertex2f(380, 650);
	glVertex2f(380, 750);
	glVertex2f(280, 750);

	glColor3ub (20,204,255);
	glVertex2f(120, 450);
	glVertex2f(220, 450);
	glVertex2f(220, 550);
	glVertex2f(120, 550);

	glColor3ub (20,204,255);
	glVertex2f(280, 450);
	glVertex2f(380, 450);
	glVertex2f(380, 550);
	glVertex2f(280, 550);

	glColor3ub (20,204,255);
	glVertex2f(120, 250);
	glVertex2f(220, 250);
	glVertex2f(220, 350);
	glVertex2f(120, 350);

	glColor3ub (20,204,255);
	glVertex2f(280, 250);
	glVertex2f(380, 250);
	glVertex2f(380, 350);
	glVertex2f(280, 350);

	glColor3ub (20,204,255);
	glVertex2f(120, 50);
	glVertex2f(220, 50);
	glVertex2f(220, 150);
	glVertex2f(120, 150);

	glColor3ub (20,204,255);
	glVertex2f(280, 50);
	glVertex2f(380, 50);
	glVertex2f(380, 150);
	glVertex2f(280, 150);
//------------------------------------------
	glEnd();

	glPopMatrix();
}

void drawHospital(GLfloat tx, GLfloat ty){

glPushMatrix();
glTranslatef(tx, ty, 0);

	glBegin(GL_POLYGON);

	glColor3ub(190, 190, 190);
	glVertex2f(25, 275);
	glVertex2f(300, 275);
	glColor3ub(190, 190, 190);
	glVertex2f(300, 700);
	glVertex2f(25, 700);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 218, 154);
	glVertex2f(50, 725);
	glVertex2f(180, 725);
	glVertex2f(180, 675);
	glVertex2f(50, 675);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(50, 725);
	glVertex2f(180, 725);
	glVertex2f(180, 675);
	glVertex2f(50, 675);
	glEnd();

	    glBegin(GL_POLYGON);
	glColor3ub(255, 229, 204);
	glVertex2f(115, 225);
	glVertex2f(210, 225);
	glVertex2f(210, 275);
	glVertex2f(115, 275);
	glEnd();

	glBegin(GL_POLYGON);
for(int i=440;i<=650;i=i+40){

	glColor3ub(59, 91, 132);
	glVertex2f(50, i);
	glVertex2f(50, 640);
	glVertex2f(270, 640);
	glColor3ub(97, 131, 159);
	glVertex2f(270, i);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(50, i);
	glVertex2f(50, 440);
	glVertex2f(270, 440);
	glVertex2f(270, i);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(150, i);
	glVertex2f(150, 440);
	glVertex2f(50, 460);
	glVertex2f(270, 460);
}

	glEnd();
	glPopMatrix();
}

void drawHospital2(GLfloat tx, GLfloat ty){

glPushMatrix();
glTranslatef(tx, ty, 0);

	glBegin(GL_POLYGON);

	glColor3ub(190, 190, 190);
	glVertex2f(325, 275);
	glVertex2f(600, 275);
	glColor3ub(190, 190, 190);
	glVertex2f(600, 800);
	glVertex2f(325, 800);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(255, 229, 204);
	glVertex2f(390, 225);
	glVertex2f(510, 225);
	glVertex2f(510, 275);
	glVertex2f(390, 275);
	glEnd();

	glBegin(GL_POLYGON);
    for(int i=340;i<=750;i=i+40){

	glColor3ub(59, 91, 132);
	glVertex2f(530, i);
	glVertex2f(530, 740);
	glVertex2f(590, 740);
	glColor3ub(97, 131, 159);
	glVertex2f(590, i);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(530, i);
	glVertex2f(530, 440);
	glVertex2f(590, 440);
	glVertex2f(590, i);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(560, i);
	glVertex2f(560, 440);
	glVertex2f(530, 460);
	glVertex2f(590, 460);
}
	glEnd();
	glPopMatrix();
}

void drawSchool(){


	glPushMatrix();
	//glTranslatef(tx, ty, 0);
    //glScalef(sx, sy, 0);



	glBegin(GL_POLYGON);
    glColor3ub(184, 88, 68);
    glVertex2f(625, 275);
	glVertex2f(1225, 275);
	glVertex2f(1225, 700);
	glColor3ub(241, 130, 94);
	glVertex2f(625, 700);
	glEnd();

	// School Building Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(625, 275);
	glVertex2f(1225, 275);
	glVertex2f(1225, 600);
	glVertex2f(625, 600);
	glEnd();

	// School Board
	glBegin(GL_POLYGON);
	glColor3ub(183, 184, 188);
	glVertex2f(795, 630);
	glVertex2f(1055, 630);
	glVertex2f(1055, 570);
	glVertex2f(795, 570);
	glEnd();

	// School Board Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(795, 630);
	glVertex2f(1055, 630);
	glVertex2f(1055, 570);
	glVertex2f(795, 570);
	glEnd();

	//print("HOSPITAL", 255, 0, 0, 1, 580, 485, .3, .3, 1.5);

  // School Door
	glBegin(GL_POLYGON);
	glColor3ub(183, 184, 188);
	glVertex2f(825, 275);
	glVertex2f(825, 380);
	glVertex2f(1025, 380);
	glVertex2f(1025, 275);
	glEnd();

	// School Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(825, 275);
	glVertex2f(825, 380);
	glVertex2f(1025, 380);
	glVertex2f(1025, 275);
	glEnd();

	// School Door Divider
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(925, 380);
	glVertex2f(925, 275);
	glEnd();

		    glBegin(GL_POLYGON);
	glColor3ub(255, 229, 204);
	glVertex2f(825, 225);
	glVertex2f(1025, 225);
	glVertex2f(1025, 275);
	glVertex2f(825, 275);
	glEnd();

	// School Windows
	for (int i = 0; i <= 500; i+=100) {
		for (int j = 0; j <= 100; j+=80) {
			glBegin(GL_POLYGON);
			glColor3ub(59, 91, 132);
			glVertex2f(650 + i, 550 - j);
			glVertex2f(700 + i, 550 - j);
			glVertex2f(700 + i, 500 - j);
			glColor3ub(97, 131, 159);
			glVertex2f(650 + i, 500 - j);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glColor3ub(20, 20, 20);
			glVertex2f(650 + i, 550 - j);
			glVertex2f(700 + i, 550 - j);
			glVertex2f(700 + i, 500 - j);
			glVertex2f(650 + i, 500 - j);
			glEnd();

			glLineWidth(4);
			glBegin(GL_LINES);
			glColor3ub(140, 75, 55);
			glVertex2f(650 + i, 500 - j);
			glVertex2f(700 + i, 500 - j);
			glEnd();
			glLineWidth(1);
		}
	}

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(650, 380);
	glVertex2f(700, 380);
	glVertex2f(700, 300);
	glColor3ub(97, 131, 159);
	glVertex2f(650, 300);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(650, 380);
	glVertex2f(700, 380);
	glVertex2f(700, 300);
	glVertex2f(650, 300);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(750, 380);
	glVertex2f(800, 380);
	glVertex2f(800, 300);
	glColor3ub(97, 131, 159);
	glVertex2f(750, 300);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(750, 380);
	glVertex2f(800, 380);
	glVertex2f(800, 300);
	glVertex2f(750, 300);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(1050, 380);
	glVertex2f(1100, 380);
	glVertex2f(1100, 300);
	glColor3ub(97, 131, 159);
	glVertex2f(1050, 300);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(1050, 380);
	glVertex2f(1100, 380);
	glVertex2f(1100, 300);
	glVertex2f(1050, 300);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(1150, 380);
	glVertex2f(1200, 380);
	glVertex2f(1200, 300);
	glColor3ub(97, 131, 159);
	glVertex2f(1150, 300);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(1150, 380);
	glVertex2f(1200, 380);
	glVertex2f(1200, 300);
	glVertex2f(1150, 300);


	glEnd();
	glPopMatrix();

}

void rain(){
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

void lampPost(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy,GLfloat light_r, GLfloat light_g,GLfloat light_b){
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3ub (0,0,0);
    glVertex2i(52,380);      //handel
	glVertex2i(58,380);
	glVertex2i(58,240);
	glVertex2i(52,240);
    glEnd();

    drawCircle(55, 380,light_r,light_g,light_b,7, 14,2);             //light

    glPopMatrix();
}

void NightView(){
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

drawBackgroundNight(0,110,1,1.2);


glPushMatrix();
glTranslatef(sunXAxis,0.0f,0.0f);
drawCircle(950, 850, 255, 255, 255, 7, 14, 5);     //sun motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCloud(-1000,80,2,1.9);                        //first cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCloud(-100,500,2,.8);                        //second cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCloud(100,580,1,.8);                         //third cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(buildingPosition,0.0f,0.0f);
building(3310, 350, 1.5, 1.4);
Hotels();
glPopMatrix();


//-------------------first layer-------------------
glPushMatrix();
glTranslatef(buildingPosition,0.0f,0.0f);
for(int i=-1000;i<2000;i=i+120)
{
    drawbuilding(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------second layer---------------------
glPushMatrix();
glTranslatef(buildingPosition1,0.0f,0.0f);
for(int i=-929;i<1800;i=i+225)
{
    drawbuilding1(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------third layer----------------------
glPushMatrix();
glTranslatef(buildingPosition2,0.0f,0.0f);
for(int i=-665;i<2000;i=i+300)
{
    drawbuilding2(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------fourth layer----------------------

glPushMatrix();
glTranslatef(hospitalPosition,0.0f,0.0f);
drawHospital(0,0);
drawHospital2(0,0);
drawSchool();
drawHospital(1205,0);
drawHospital2(1190,0);

drawTree(25,275,.15,.35);

drawTree(305,275,.3,.5);
drawTree(605,270,.12,.32);
drawTree(620,270,.12,.32);
drawTree(815,265,.1,.3);
drawTree(815,250,.1,.3);
drawTree(1035,265,.1,.3);
drawTree(1035,250,.1,.3);
drawTree(1245,265,.1,.3);
drawTree(1275,265,.1,.3);
drawTree(1305,265,.1,.3);
drawTree(1425,265,.1,.3);
drawTree(1455,265,.1,.3);
drawTree(1485,265,.1,.3);
//drawTree(1530,265,.1,.3);
drawTree(1560,265,.1,.3);
drawTree(1710,265,.1,.3);

glPopMatrix();
//----------------------------------------------------

glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=2000;i<3300;i=i+120)
{
    drawMountain(i,520,.3,.3);
}
//drawMountain(1400,450,.7,.7);
drawMountain(2000,450,.7,.7);
//drawMountain(2300,450,1,.7);
drawMountain(2350,450,.7,.7);
//drawMountain(2600,450,.7,.7);
drawMountain(2700,450,1,.7);
//drawMountain(3200,450,.7,.7);
drawMountain(2900,450,1,.7);
glPopMatrix();

glPushMatrix();
glTranslatef(housePosition,0.0f,0.0f);


hut(2000,100,.8,1);                   //hut

school(2700,50,.8,1);                    //school

house(2100,200,.5,.5);
house(2600,250,.5,.5);

school(2100,50,.8,1);                    //school

hut(2830,100,.8,1);                   //hut

well();                   //well

drawTree(1950,265,.1,.3);
drawTree(1980,255,.1,.3);
drawTree(2000,285,.2,.45);                   //tree
drawTree(2030,320,.15,.35);                   //tree
drawTree(2015,265,.15,.35);                   //tree
drawTree(2060,300,.1,.25);                   //tree
drawTree(2050,260,.1,.3);
// forest
 drawTree(2210,525,.1,.3);                     //tree
 drawTree(2230,525,.1,.3);
 drawTree(2400,525,.1,.3);
 drawTree(2260,535,.1,.3);
 drawTree(2285,525,.1,.3);                   //tree
 drawTree(2300,525,.1,.3);                   //tree
 drawTree(2390,515,.1,.3);                   //tree
 drawTree(2420,500,.1,.3);                   //tree

    drawHumam(2200,320,.3,.35,250,0,0);
    drawHumam(2750,400,.3,.35,250,150,0);
    drawHumam(2850,450,.3,.35,50,150,100);

 drawTree(2880,275,.15,.35);                   //tree
 drawTree(2925,285,.15,.35);                   //tree
 drawTree(2860,255,.15,.35);                   //tree
 drawTree(2900,265,.15,.35);                   //tree
 drawTree(3280,255,.15,.35);                   //tree
 drawTree(3240,265,.15,.35);                   //tree
 drawTree(3265,260,.1,.3);

 glPopMatrix();


//-------------------Tree-----------------------------
glPushMatrix();
glTranslatef(treePosition,0.0f,0.0f);
 for(int i=100;i<=2100;i+=100)
{

   drawTree(i,245,.2,.45);
}
glPopMatrix();
//-----------------------------------------------------
//-------------------road------------------------------
PS_drawRoad(-2000,-600,6,3);

glPushMatrix();
glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);

glPopMatrix();

//-----------------------------------------------------
//---------------------Hill Area-----------------------
glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=4715;i<6000;i=i+120)
{
   drawMountain2(i,460,
             .7,.7);
}

drawMountain2(4800,390,.7,.7);
drawMountain2(5000,390,.7,.7);
drawMountain2(5500,370,.7,.7);
drawMountain2(5850,380,.7,.7);
//drawMountain2(100,370,.7,.7);
//drawMountain2(600,370,.7,.7);
//drawMountain2(800,370,0.7,.7);
//drawMountain2(900,370,0.7,.7);
//drawMountain2(1000,370,0.7,.7);
//drawMountain2(1200,370,0.7,.7);
//drawMountain2(1400,370,0.7,.7);
DrawCloud(4560,150,2,.5);                       //third cloud motion
house(4805,270,.5,.4);
house(5090,170,.6,.5);
house(5700,130,.5,.5);

drawTree(4730,355,.2,.5);
drawTree(4800,345,.15,.6);
drawTree(4840,365,.3,.5);
drawTree(4770,325,.18,.4);
drawTree(5150,450,.2,.5);
drawTree(5180,430,.25,.5);
drawTree(5720,400,.19,.4);
drawTree(5750,410,.23,.5);
drawTree(5790,375,.18,.4);
glPopMatrix();


//-----------------------------------------------------
//---------------------lamp post-----------------------
glPushMatrix();
glTranslatef(lampPosition,0.0f,0.0f);
 for(int i=0;i<=6000;i+=300)
{

   lampPost(i, 0, 1, 1, 255, 255, 0);
}
glPopMatrix();
//-----------------------------------------------------
//---------------------Bird---------------------------
bird();
//-----------------------------------------------------

glPushMatrix();
glTranslatef(travellcarPosition1,0.0f,0.0f);

glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex2i(220,100);
	glVertex2i(350,20);          //head light
	glVertex2i(450,30);
    glVertex2i(210,130);
   glEnd();

travellCar(0,20,2.5,2.9);

glPopMatrix();
glEnd();




glFlush();


}

void RainView(){
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

drawBackgroundRain(0,110,1,1.2);


glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCloudRain(-1000,80,2,1.9);                        //first cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCloudRain(-100,500,2,.8);                        //second cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCloudRain(100,580,1,.8);                         //third cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(buildingPosition,0.0f,0.0f);
building(3310, 350, 1.5, 1.4);
Hotels();
glPopMatrix();


//-------------------first layer-------------------
glPushMatrix();
glTranslatef(buildingPosition,0.0f,0.0f);
for(int i=-1000;i<2000;i=i+120)
{
    drawbuilding(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------second layer---------------------
glPushMatrix();
glTranslatef(buildingPosition1,0.0f,0.0f);
for(int i=-929;i<1800;i=i+225)
{
    drawbuilding1(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------third layer----------------------
glPushMatrix();
glTranslatef(buildingPosition2,0.0f,0.0f);
for(int i=-665;i<2000;i=i+300)
{
    drawbuilding2(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------four layer----------------------

glPushMatrix();
glTranslatef(hospitalPosition,0.0f,0.0f);
drawHospital(0,0);
drawHospital2(0,0);
drawSchool();
drawHospital(1205,0);
drawHospital2(1190,0);

drawTree(25,275,.15,.35);

drawTree(305,275,.3,.5);
drawTree(605,270,.12,.32);
drawTree(620,270,.12,.32);
drawTree(815,265,.1,.3);
drawTree(815,250,.1,.3);
drawTree(1035,265,.1,.3);
drawTree(1035,250,.1,.3);
drawTree(1245,265,.1,.3);
drawTree(1275,265,.1,.3);
drawTree(1305,265,.1,.3);
drawTree(1425,265,.1,.3);
drawTree(1455,265,.1,.3);
drawTree(1485,265,.1,.3);
//drawTree(1530,265,.1,.3);
drawTree(1560,265,.1,.3);
drawTree(1710,265,.1,.3);

glPopMatrix();
//----------------------------------------------------

glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=2000;i<3300;i=i+120)
{
    drawMountain(i,520,.3,.3);
}
//drawMountain(1400,450,.7,.7);
drawMountain(2000,450,.7,.7);
//drawMountain(2300,450,1,.7);
drawMountain(2350,450,.7,.7);
//drawMountain(2600,450,.7,.7);
drawMountain(2700,450,1,.7);
//drawMountain(3200,450,.7,.7);
drawMountain(2900,450,1,.7);
glPopMatrix();

glPushMatrix();
glTranslatef(housePosition,0.0f,0.0f);


hut(2000,100,.8,1);                   //hut

school(2700,50,.8,1);                    //school

house(2100,200,.5,.5);
house(2600,250,.5,.5);

school(2100,50,.8,1);                    //school

hut(2830,100,.8,1);                   //hut

well();                   //well

drawTree(1950,265,.1,.3);
drawTree(1980,255,.1,.3);
drawTree(2000,285,.2,.45);                   //tree
drawTree(2030,320,.15,.35);                   //tree
drawTree(2015,265,.15,.35);                   //tree
drawTree(2060,300,.1,.25);                   //tree
drawTree(2050,260,.1,.3);
// forest
 drawTree(2210,525,.1,.3);                     //tree
 drawTree(2230,525,.1,.3);
 drawTree(2400,525,.1,.3);
 drawTree(2260,535,.1,.3);
 drawTree(2285,525,.1,.3);                   //tree
 drawTree(2300,525,.1,.3);                   //tree
 drawTree(2390,515,.1,.3);                   //tree
 drawTree(2420,500,.1,.3);                   //tree

    drawHumam(2200,320,.3,.35,250,0,0);
    drawHumam(2750,400,.3,.35,250,150,0);
    drawHumam(2850,450,.3,.35,50,150,100);

 drawTree(2880,275,.15,.35);                   //tree
 drawTree(2925,285,.15,.35);                   //tree
 drawTree(2860,255,.15,.35);                   //tree
 drawTree(2900,265,.15,.35);                   //tree
 drawTree(3280,255,.15,.35);                   //tree
 drawTree(3240,265,.15,.35);                   //tree
 drawTree(3265,260,.1,.3);

 glPopMatrix();

//-------------------Tree-----------------------------
glPushMatrix();
glTranslatef(treePosition,0.0f,0.0f);
 for(int i=100;i<=2100;i+=100)
{

   drawTree(i,245,.2,.45);
}
glPopMatrix();
//-----------------------------------------------------
//-------------------road------------------------------
PS_drawRoad(-2000,-600,6,3);

glPushMatrix();
glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);

glPopMatrix();

//-----------------------------------------------------
//---------------------Hill Area-----------------------
glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=4715;i<6000;i=i+120)
{
   drawMountain2(i,460,
             .7,.7);
}

drawMountain2(4800,390,.7,.7);
drawMountain2(5000,390,.7,.7);
drawMountain2(5500,370,.7,.7);
drawMountain2(5850,380,.7,.7);
//drawMountain2(100,370,.7,.7);
//drawMountain2(600,370,.7,.7);
//drawMountain2(800,370,0.7,.7);
//drawMountain2(900,370,0.7,.7);
//drawMountain2(1000,370,0.7,.7);
//drawMountain2(1200,370,0.7,.7);
//drawMountain2(1400,370,0.7,.7);
DrawCloud(4560,150,2,.5);                       //third cloud motion
house(4805,270,.5,.4);
house(5090,170,.6,.5);
house(5700,130,.5,.5);

drawTree(4730,355,.2,.5);
drawTree(4800,345,.15,.6);
drawTree(4840,365,.3,.5);
drawTree(4770,325,.18,.4);
drawTree(5150,450,.2,.5);
drawTree(5180,430,.25,.5);
drawTree(5720,400,.19,.4);
drawTree(5750,410,.23,.5);
drawTree(5790,375,.18,.4);
glPopMatrix();


//-----------------------------------------------------
//---------------------lamp post-----------------------
glPushMatrix();
glTranslatef(lampPosition,0.0f,0.0f);
 for(int i=0;i<=6000;i+=300)
{

   lampPost(i,0,1,1,176,224,230);
}
glPopMatrix();
//-----------------------------------------------------
//---------------------Bird---------------------------
//bird();
//-----------------------------------------------------

glPushMatrix();
glTranslatef(travellcarPosition1,0.0f,0.0f);
glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex2i(220,100);
	glVertex2i(350,20);          //head light
	glVertex2i(450,30);
    glVertex2i(210,130);
   glEnd();
travellCar(0,20,2.5,2.9);

glPopMatrix();
glEnd();
glFlush();

rain();
glEnd();
glFlush();

}

void DayView(){
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

drawBackground(0,110,1,1.2);

glPushMatrix();
glTranslatef(sunXAxis,0.0f,0.0f);
drawCircle(950, 850, 250, 250, 0, 7, 14, 5);     //sun motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCloud(-1000,80,2,1.9);                        //first cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCloud(-100,500,2,.8);                        //second cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCloud(100,580,1,.8);                         //third cloud motion
glPopMatrix();

glPushMatrix();
glTranslatef(buildingPosition,0.0f,0.0f);
building(3310, 350, 1.5, 1.4);
Hotels();
glPopMatrix();

//-------------------first layer-------------------
glPushMatrix();
glTranslatef(buildingPosition,0.0f,0.0f);
for(int i=0;i<2000;i=i+120)
{
    drawbuilding(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------second layer---------------------
glPushMatrix();
glTranslatef(buildingPosition1,0.0f,0.0f);
for(int i=0;i<1800;i=i+225)
{
    drawbuilding1(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------third layer----------------------
glPushMatrix();
glTranslatef(buildingPosition2,0.0f,0.0f);
for(int i=0;i<2000;i=i+300)
{
    drawbuilding2(i,520,.3,.3);
}
glPopMatrix();
//----------------------------------------------------
//-------------------fourth layer----------------------

glPushMatrix();
glTranslatef(hospitalPosition,0.0f,0.0f);
drawHospital(0,0);
drawHospital2(0,0);
drawSchool();
drawHospital(1205,0);
drawHospital2(1190,0);

drawTree(25,275,.15,.35);

drawTree(305,275,.3,.5);
drawTree(605,270,.12,.32);
drawTree(620,270,.12,.32);
drawTree(815,265,.1,.3);
drawTree(815,250,.1,.3);
drawTree(1035,265,.1,.3);
drawTree(1035,250,.1,.3);
drawTree(1245,265,.1,.3);
drawTree(1275,265,.1,.3);
drawTree(1305,265,.1,.3);
drawTree(1425,265,.1,.3);
drawTree(1455,265,.1,.3);
drawTree(1485,265,.1,.3);
//drawTree(1530,265,.1,.3);
drawTree(1560,265,.1,.3);
drawTree(1710,265,.1,.3);

glPopMatrix();
//----------------------------------------------------

glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=2000;i<3300;i=i+120)
{
    drawMountain(i,520,.3,.3);
}
//drawMountain(1400,450,.7,.7);
drawMountain(2000,450,.7,.7);
//drawMountain(2300,450,1,.7);
drawMountain(2350,450,.7,.7);
//drawMountain(2600,450,.7,.7);
drawMountain(2700,450,1,.7);
//drawMountain(3200,450,.7,.7);
drawMountain(2900,450,1,.7);
glPopMatrix();

glPushMatrix();
glTranslatef(housePosition,0.0f,0.0f);


hut(2000,100,.8,1);                   //hut

school(2700,50,.8,1);                    //school

house(2100,200,.5,.5);
house(2600,250,.5,.5);

school(2100,50,.8,1);                    //school

hut(2830,100,.8,1);                   //hut

well();                   //well

drawTree(1950,265,.1,.3);
drawTree(1980,255,.1,.3);
drawTree(2000,285,.2,.45);                   //tree
drawTree(2030,320,.15,.35);                   //tree
drawTree(2015,265,.15,.35);                   //tree
drawTree(2060,300,.1,.25);                   //tree
drawTree(2050,260,.1,.3);
// forest
 drawTree(2210,525,.1,.3);                     //tree
 drawTree(2230,525,.1,.3);
 drawTree(2400,525,.1,.3);
 drawTree(2260,535,.1,.3);
 drawTree(2285,525,.1,.3);                   //tree
 drawTree(2300,525,.1,.3);                   //tree
 drawTree(2390,515,.1,.3);                   //tree
 drawTree(2420,500,.1,.3);                   //tree

    drawHumam(2200,320,.3,.35,250,0,0);
    drawHumam(2750,400,.3,.35,250,150,0);
    drawHumam(2850,450,.3,.35,50,150,100);

 drawTree(2880,275,.15,.35);                   //tree
 drawTree(2925,285,.15,.35);                   //tree
 drawTree(2860,255,.15,.35);                   //tree
 drawTree(2900,265,.15,.35);                   //tree
 drawTree(3280,255,.15,.35);                   //tree
 drawTree(3240,265,.15,.35);                   //tree
 drawTree(3265,260,.1,.3);

 glPopMatrix();

//-------------------Tree-----------------------------
glPushMatrix();
glTranslatef(treePosition,0.0f,0.0f);
 for(int i=100;i<=2100;i+=100)
{

   drawTree(i,245,.2,.45);
}
glPopMatrix();
//-----------------------------------------------------

//------------------------SeaView-----------------------------
glPushMatrix();
glTranslatef(buildingPosition2,0.0f,0.0f);
drawSeaBackground(6200,110,1,1.2);
glTranslatef(shipPosition,0.0f,0.0f); //ship
glTranslatef(6200, 500, 0);
ship();
glPopMatrix();

glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glScalef(2.5,2.5,0);
glTranslatef(2605, 130, 0);
bench();
glPopMatrix();

glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glScalef(2.5,2.5,0);
glTranslatef(2755, 130, 0);
bench();
glPopMatrix();

glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glScalef(2.5,2.5,0);
glTranslatef(2915, 130, 0);
bench();
glPopMatrix();

glPushMatrix();
glTranslatef(cocoPosition , 0 , 0);
glTranslatef(6350 , 230, 0);
glScalef(2,2,0);
coconut_tree();       //coconuttree
glPopMatrix();

//-------------------road------------------------------
PS_drawRoad(-2000,-600,6,3);

glPushMatrix();
glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);

glPopMatrix();

//-----------------------------------------------------
//---------------------Bird---------------------------
bird();
//-----------------------------------------------------

glPushMatrix();
glTranslatef(travellcarPosition1,0.0f,0.0f);
travellCar(0,20,2.5,2.9);

glPopMatrix();

//-----------------------------------------------------
//---------------------Hill Area-----------------------
glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=4715;i<6000;i=i+120)
{
   drawMountain2(i,460,
             .7,.7);
}

drawMountain2(4800,390,.7,.7);
drawMountain2(5000,390,.7,.7);
drawMountain2(5500,370,.7,.7);
drawMountain2(5850,380,.7,.7);
//drawMountain2(100,370,.7,.7);
//drawMountain2(600,370,.7,.7);
//drawMountain2(800,370,0.7,.7);
//drawMountain2(900,370,0.7,.7);
//drawMountain2(1000,370,0.7,.7);
//drawMountain2(1200,370,0.7,.7);
//drawMountain2(1400,370,0.7,.7);
DrawCloud(4560,150,2,.5);                       //third cloud motion
house(4805,270,.5,.4);
house(5090,170,.6,.5);
house(5700,130,.5,.5);

drawTree(4730,355,.2,.5);
drawTree(4800,345,.15,.6);
drawTree(4840,365,.3,.5);
drawTree(4770,325,.18,.4);
drawTree(5150,450,.2,.5);
drawTree(5180,430,.25,.5);
drawTree(5720,400,.19,.4);
drawTree(5750,410,.23,.5);
drawTree(5790,375,.18,.4);
glPopMatrix();

//-----------------------------------------------------
//---------------------lamp post-----------------------
glPushMatrix();
glTranslatef(lampPosition,0.0f,0.0f);
 for(int i=0;i<=6000;i+=300)
{
   lampPost(i,0,1,1,176,224,230);
}
glPopMatrix();


glFlush();


}

void update(int value) {


  cloud1Position+=cloud1speed;
  cloud2Position+=cloud2speed;
  cloud3Position+=cloud3speed;
  sunXAxis-=sunspeed;
  treePosition -= treespeed;
  lampPosition -= lampspeed;
  roadMiddleWhiteMark-=roadMiddleWhiteMarkSpeed;
  shipPosition+=shipSpeed;
  cocoPosition-=cocoSpeed;
  travellcarPosition1+=travellcarspeed+.01;
  //printf("%f\n",treePosition);
  buildingPosition-=buildingSpeed;
  buildingPosition1-=buildingSpeed1;
  buildingPosition2-=buildingSpeed2;
  hospitalPosition-=hospitalSpeed;


  humanPosition1+=humanspeed;
  humanPosition2+=humanspeed;
  humanPosition3+=humanspeed;
  humanPosition4+=humanspeed;
  humanPosition5+=humanspeed;
  humanPosition+=humanspeed;
  housePosition-=houseSpeed;
  mountainPosition-=mountainSpeed;



  birdPosition+=birdspeed;

  roadUpperWhiteBlackMark-=roadUpperWhiteBlackMarkSpeed;


  if(shipPosition>1000)     //cloud 3 reassign position
  {
      shipPosition=-700;
  }

  if(cocoPosition<-8500)
  {
      cocoPosition=500;
  }

    if(housePosition<-6000)
  {
      housePosition=1400;
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

 if(mountainPosition<-6000)
 {
     mountainPosition=1500;
 }
  if(birdPosition>2400)
  {
      birdPosition=-100;
  }
  if(sunXAxis<-1100)
  {
      sunXAxis=0;
  }
  if(cloud1Position>800)
  {
      cloud1Position=-900;
  }
  if(cloud2Position<-1200)
  {
      cloud2Position=300;
  }
  if(cloud3Position>500)
  {
      cloud3Position=-700;
  }
  if(treePosition<-20000)
  {
     treePosition=0;
  }
  if(lampPosition<-20000)
  {
     lampPosition=0;
  }
  if(roadMiddleWhiteMark<-400)
  {
     roadMiddleWhiteMark=0;
  }
  if(roadUpperWhiteBlackMark<-800)
  {
     roadUpperWhiteBlackMark=0;
  }
  if(buildingPosition<-7000)
  {
     buildingPosition=500;
  }
  if(buildingPosition1<-7000)
  {
     buildingPosition1=500;
  }
  if(buildingPosition2<-7000)
  {
     buildingPosition2=500;
  }
  if(hospitalPosition<-7000)
  {
     hospitalPosition=500;
  }
  if(travellcarPosition1>500)
  {
     travellcarPosition1=-1000;
  }
  if(travellcarPosition2>1000)
  {
     travellcarPosition2=-500;
  }


	glutPostRedisplay();
    glutTimerFunc(1, update, 0);
}

void display(void){

glClear (GL_COLOR_BUFFER_BIT);
//glColor3ub (128, 128, 128);
glPointSize(5.0);

DayView();
glEnd();
glFlush ();

}

void handleKeypress(unsigned char key, int x, int y){

	switch (key) {
      break;
    case 'd':
        glutDisplayFunc(DayView);
      break;
    case 'n':
        glutDisplayFunc(NightView);
      break;
      break;
    case 'r':
        glutDisplayFunc(RainView);
      break;
      default:
     glutPostRedisplay();
      break;
	}
}

void handleMouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON)
	{
			glutDisplayFunc(NightView);
	}
		if (button == GLUT_RIGHT_BUTTON)
	{
			glutDisplayFunc(DayView);
	}
			if (button == GLUT_MIDDLE_BUTTON)
	{
			glutDisplayFunc(RainView);
	}
}

void init(){
   glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

int main(int argc,char** argv){


    printf("\nEnter 'd' for day view.");
    printf("\nEnter 'n' for night view.");
    printf("\nEnter 'r' for rain view.");


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Travelling Scenerio");     // creating the window
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
