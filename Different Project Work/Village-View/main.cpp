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
GLfloat birdspeed=0.5;
GLfloat cloud2Position=0;
GLfloat cloud2speed=-0.3;
GLfloat cloud3Position=0;
GLfloat cloud3speed=0.4;
GLfloat sunXAxis=0;
GLfloat sunspeed=0.05;
GLfloat roadMiddleWhiteMark=0;
GLfloat roadMiddleWhiteMarkSpeed=0.8;
GLfloat humanPosition1=0;
GLfloat humanspeed=0.001;
GLfloat humanPosition2=0;
GLfloat humanPosition3=0;
GLfloat humanPosition4=0;
GLfloat humanPosition5=0;
GLfloat humanPosition=0;
GLfloat travellcarPosition1=0;
GLfloat travellcarPosition2=0;
GLfloat travellcarspeed=0;
GLfloat mountainPosition=0;
GLfloat mountainSpeed=0.1;
GLfloat housePosition=0;
GLfloat houseSpeed=0.8;
GLfloat roadUpperWhiteBlackMark=0;
GLfloat roadUpperWhiteBlackMarkSpeed=0.4;


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




	// Apples
	drawCircle(27, 234, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-15, 270, 255, 0, 0, 1, 1.2, 5);
	drawCircle(47, 255, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-2, 228, 255, 0, 0, 1, 1.2, 5);
	drawCircle(72, 216, 255, 0, 0, 1, 1.2, 5);

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
void well(GLfloat tx, GLfloat ty,
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

     ///well

    glPushMatrix();
    glTranslatef(50, 110, 0.0);

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
   drawSemiCircle(510, 380,
		3.2, 5.1,
		200, 230, 255,
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
	glColor3ub(60,179,113); // Green Grass
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(0, 128, 0); // dark green
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
void drawBackgroundNight(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


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


void drawBackgroundRain(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(12, 172, 232); // Sky Blue
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
	glVertex2f(1400, 300);
	glVertex2f(0, 300);
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

void drawMountain(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


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
		9);
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





glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=-1000;i<2500;i=i+120)
{
    drawMountain(i,520,
             .3,.3);
}

drawMountain(1400,450,
             .7,.7);


drawMountain(0,450,
             .7,.7);

drawMountain(420,450,
             1,.7);

drawMountain(900,450,
             .7,.7);
glPopMatrix();


glPushMatrix();
glTranslatef(housePosition,0.0f,0.0f);


hut(0,100,                   //hut
    .8,1);

well(0,100,                   //well
    .8,1);

school(0,0,                    //school
       .8,1);

house(550,200,
      .5,.5);

house(1650,250,
      .5,.5);

school(1000,0,                    //school
       .8,1);



hut(1900,100,                   //hut
    .8,1);

well(2000,100,                   //well
    .8,1);

drawTree(120,245,                   //tree
          .2,.45);
 drawTree(200,480,                   //tree
          .15,.35);
 drawTree(650,445,                   //tree
          .15,.35);
 drawTree(900,545,                   //tree
          .1,.25);





// forest

 drawTree(1040,445,                   //tree
          .15,.35);
 drawTree(1085,455,                   //tree
          .15,.35);
 drawTree(1130,425,                   //tree
          .15,.35);

 drawTree(1150,435,                   //tree
          .15,.35);

 drawTree(1195,445,                   //tree
          .15,.35);


 drawTree(1050,405,                   //tree
          .15,.35);
 drawTree(1090,415,                   //tree
          .15,.35);
 drawTree(1120,408,                   //tree
          .15,.35);

 drawTree(1160,425,                   //tree
          .15,.35);

 drawTree(1190,435,                   //tree
          .15,.35);

 //human

    drawHumam(200,320,
             .3,.35,
            250,0,0);

    drawHumam(750,400,
             .3,.35,
            250,150,0);
    drawHumam(850,450,
             .3,.35,
            50,150,100);




 drawTree(2540,445,                   //tree
          .15,.35);
 drawTree(2685,455,                   //tree
          .15,.35);
 drawTree(2630,425,                   //tree
          .15,.35);

 drawTree(2550,435,                   //tree
          .15,.35);

 drawTree(2610,445,                   //tree
          .15,.35);


 drawTree(2590,405,                   //tree
          .15,.35);
 drawTree(2600,415,                   //tree
          .15,.35);
 drawTree(2520,408,                   //tree
          .15,.35);

 drawTree(2560,425,                   //tree
          .15,.35);

 drawTree(2590,435,                   //tree
          .15,.35);

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


	///bird 2

	glTranslatef(-55,-30, 0.0);
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



    glPopMatrix();
// birds x
    glPushMatrix();
    glTranslatef(.2,900, 0);
    glTranslatef(birdPosition,00, 0.0);
    glBegin(GL_QUADS);
    glColor3f(255,255,255);
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
///bird 5
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



glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=-1000;i<2500;i=i+120)
{
    drawMountain(i,520,
             .3,.3);
}

drawMountain(1400,450,
             .7,.7);


drawMountain(0,450,
             .7,.7);

drawMountain(420,450,
             1,.7);

drawMountain(900,450,
             .7,.7);
glPopMatrix();


glPushMatrix();
glTranslatef(housePosition,0.0f,0.0f);


hut(0,100,                   //hut
    .8,1);

well(0,100,                   //well
    .8,1);

school(0,0,                    //school
       .8,1);

house(550,200,
      .5,.5);

house(1650,250,
      .5,.5);

school(1000,0,                    //school
       .8,1);



hut(1900,100,                   //hut
    .8,1);

well(2000,100,                   //well
    .8,1);

drawTree(120,245,                   //tree
          .2,.45);
 drawTree(200,480,                   //tree
          .15,.35);
 drawTree(650,445,                   //tree
          .15,.35);
 drawTree(900,545,                   //tree
          .1,.25);





// forest

 drawTree(1040,445,                   //tree
          .15,.35);
 drawTree(1085,455,                   //tree
          .15,.35);
 drawTree(1130,425,                   //tree
          .15,.35);

 drawTree(1150,435,                   //tree
          .15,.35);

 drawTree(1195,445,                   //tree
          .15,.35);


 drawTree(1050,405,                   //tree
          .15,.35);
 drawTree(1090,415,                   //tree
          .15,.35);
 drawTree(1120,408,                   //tree
          .15,.35);

 drawTree(1160,425,                   //tree
          .15,.35);

 drawTree(1190,435,                   //tree
          .15,.35);




 drawTree(2540,445,                   //tree
          .15,.35);
 drawTree(2685,455,                   //tree
          .15,.35);
 drawTree(2630,425,                   //tree
          .15,.35);

 drawTree(2550,435,                   //tree
          .15,.35);

 drawTree(2610,445,                   //tree
          .15,.35);


 drawTree(2590,405,                   //tree
          .15,.35);
 drawTree(2600,415,                   //tree
          .15,.35);
 drawTree(2520,408,                   //tree
          .15,.35);

 drawTree(2560,425,                   //tree
          .15,.35);

 drawTree(2590,435,                   //tree
          .15,.35);
drawHumam(250, 370,
		0.2, 0.35,
		255, 0, 0);
drawSemiCircle(250, 375,           //man walking in rain
		5.2, 11.1,
		50,50,50,
		5,
		-90, 90);




drawHumam(480, 350,
		0.2, 0.35,
		255, 250, 0);
drawSemiCircle(480, 355,           //man walking in rain
		5.2, 11.1,
		50,50,50,
		5,
		-90, 90);



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
glEnd();


//bird();                          //bird




glFlush();










rain();
glEnd();
glFlush();


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
		9);
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


glPushMatrix();
glTranslatef(mountainPosition,0.0f,0.0f);
for(int i=-1000;i<2500;i=i+120)
{
    drawMountain(i,520,
             .3,.3);
}

drawMountain(1400,450,
             .7,.7);


drawMountain(0,450,
             .7,.7);

drawMountain(420,450,
             1,.7);

drawMountain(900,450,
             .7,.7);
glPopMatrix();


glPushMatrix();
glTranslatef(housePosition,0.0f,0.0f);


hut(0,100,                   //hut
    .8,1);

well(0,100,                   //well
    .8,1);

school(0,0,                    //school
       .8,1);

house(550,200,
      .5,.5);

house(1650,250,
      .5,.5);

school(1000,0,                    //school
       .8,1);



hut(1900,100,                   //hut
    .8,1);

well(2000,100,                   //well
    .8,1);

drawTree(120,245,                   //tree
          .2,.45);
 drawTree(200,480,                   //tree
          .15,.35);
 drawTree(650,445,                   //tree
          .15,.35);
 drawTree(900,545,                   //tree
          .1,.25);





// forest

 drawTree(1040,445,                   //tree
          .15,.35);
 drawTree(1085,455,                   //tree
          .15,.35);
 drawTree(1130,425,                   //tree
          .15,.35);

 drawTree(1150,435,                   //tree
          .15,.35);

 drawTree(1195,445,                   //tree
          .15,.35);


 drawTree(1050,405,                   //tree
          .15,.35);
 drawTree(1090,415,                   //tree
          .15,.35);
 drawTree(1120,408,                   //tree
          .15,.35);

 drawTree(1160,425,                   //tree
          .15,.35);

 drawTree(1190,435,                   //tree
          .15,.35);

 //human

    drawHumam(200,320,
             .3,.35,
            250,0,0);

    drawHumam(750,400,
             .3,.35,
            250,150,0);
    drawHumam(850,450,
             .3,.35,
            50,150,100);




 drawTree(2540,445,                   //tree
          .15,.35);
 drawTree(2685,455,                   //tree
          .15,.35);
 drawTree(2630,425,                   //tree
          .15,.35);

 drawTree(2550,435,                   //tree
          .15,.35);

 drawTree(2610,445,                   //tree
          .15,.35);


 drawTree(2590,405,                   //tree
          .15,.35);
 drawTree(2600,415,                   //tree
          .15,.35);
 drawTree(2520,408,                   //tree
          .15,.35);

 drawTree(2560,425,                   //tree
          .15,.35);

 drawTree(2590,435,                   //tree
          .15,.35);



 glPopMatrix();




PS_drawRoad(-2000,-600,6,3);







glPushMatrix();
glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);

glPopMatrix();





glPushMatrix();
glTranslatef(travellcarPosition1,0.0f,0.0f);
travellCar(0,20,
          2.5,2.9);                            //travell car
glPopMatrix();
glEnd();


bird();                          //bird




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
  humanPosition+=humanspeed;
  travellcarPosition1+=travellcarspeed+.01;
  printf("%f\n",housePosition);
  mountainPosition-=mountainSpeed;
  housePosition-=houseSpeed;
  birdPosition+=birdspeed;
  roadUpperWhiteBlackMark-=roadUpperWhiteBlackMarkSpeed;

    if(housePosition<-2200)
  {
      housePosition=0;
  }

  if(birdPosition>1400)
  {
      birdPosition=-100;
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



 if(roadMiddleWhiteMark<-400)
 {
     roadMiddleWhiteMark=0;     //middle road white  motion
 }

  if(roadUpperWhiteBlackMark<-800)
 {
     roadUpperWhiteBlackMark=0;     //middle road white  motion
 }

 if(mountainPosition<-800)
 {
     mountainPosition=0;     //mountain motion
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

 if(travellcarPosition1>500)
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
	glutCreateWindow("LOCKDOWN VIEW");     // creating the window
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
