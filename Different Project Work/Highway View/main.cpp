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

GLfloat sunXAxis=0;
GLfloat sunspeed=0.2;
GLfloat cloud1Position=0;
GLfloat cloud1speed=1.0;
GLfloat cloud2Position=0;
GLfloat cloud2speed=0.7;
GLfloat cloud3Position=0;
GLfloat cloud3speed=1.5;
GLfloat travellcarPosition1=0;
GLfloat travellcarPosition2=0;
GLfloat travellcarspeed=0;
GLfloat roadMiddleWhiteMark=0;
GLfloat roadMiddleWhiteMarkSpeed=0.2;
GLfloat roadUpperWhiteBlackMark=0;
GLfloat roadUpperWhiteBlackMarkSpeed=0.08;
GLfloat moveScenerio=0;
GLfloat moveScenerioSpeed=0.3;
GLfloat moveLampPost=0;
GLfloat moveLampPostSpeed=0.5;

void update(int value) {
     cloud1Position+=cloud1speed;
     cloud2Position-=cloud2speed;
     cloud3Position+=cloud3speed;
     sunXAxis-=sunspeed;
     printf("%f\n",moveScenerio);
     moveScenerio-=moveScenerioSpeed;
     moveLampPost-=moveLampPostSpeed;
     roadMiddleWhiteMark-=roadMiddleWhiteMarkSpeed;
     travellcarPosition1+=travellcarspeed+.05;
     roadUpperWhiteBlackMark-=roadUpperWhiteBlackMarkSpeed;


    if(moveScenerio<-850)
    {
      moveScenerio=0;
    }

    if(moveLampPost<-1200)
    {
      moveLampPost=0;
    }

     if(cloud1Position>1000)    //cloud 1 reassign position
     {
      cloud1Position=-500;
     }
     if(cloud2Position<-1000)       //cloud 2 reassign position
     {
      cloud2Position=+200;
     }
    if(cloud3Position>500)     //cloud 3 reassign position
    {
      cloud3Position=-800;
    }
    if(sunXAxis<-1100)    //sun reassign position
    {
      sunXAxis=0;
    }

    if(roadMiddleWhiteMark<-400)
     {
         roadMiddleWhiteMark=0;     //middle road white  motion
     }

    if(roadUpperWhiteBlackMark<-800)
     {
         roadUpperWhiteBlackMark=0;     //middle road white  motion
     }

    if(travellcarPosition1>1000)
     {
         travellcarPosition1=-300;           //travell car motion
     }


    glutPostRedisplay();
    glutTimerFunc(5, update, 0);

}

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
void DrawCloud(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy)
{

    //Cloud
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawSemiCircle(500, 400,
		7.5, 5.4,
		200, 230, 255,
		9,
		0, 360);
    drawSemiCircle(480, 420,
		3.5, 5.4,
		200, 230, 255,
		9,
		0, 360);
    drawSemiCircle(520, 410,
		3.5, 5.4,
		200, 230, 255,
		9,
		0, 360);
    drawSemiCircle(510, 380,
		3.5, 5.4,
		200, 230, 255,
		9,
		0, 360);

    glPopMatrix();

    //Sun
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawCircle(25, 12,
		8.0, 5.5,
		255, 215, 0,
		.12);

    glPopMatrix();

    }

void DrawCloudRain(GLfloat tx, GLfloat ty,
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

void building(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


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

    //1st layer second building
    glBegin(GL_QUADS);
    glColor3ub (180,180,180);
    //2
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

    //4
    glVertex2i(270,320);
    glVertex2i(210,320);
    glVertex2i(210,290);
    glVertex2i(270,290);

    //5
    glVertex2i(440,300);
    glVertex2i(360,300);
    glVertex2i(360,160);
    glVertex2i(440,160);


    //3
    glColor3ub (200,200,200); //1st layer building no. 3
    glVertex2i(152,160);
    glVertex2i(200,160);
    glVertex2i(200,270);
    glVertex2i(152,270);

    //5
    glVertex2i(280,250);
    glVertex2i(360,250);
    glVertex2i(360,160);
    glVertex2i(280,160);

    glEnd();

    //2nd layer
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


    //2nd layer roof
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
	drawCircle(27, 234, r, r, g, 1, 1.2, 5);
	drawCircle(-15, 270, 255, 0, 0, 1, 1.2, 5);
	drawCircle(47, 255, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-2, 228, 255, 0, 0, 1, 1.2, 5);
	drawCircle(72, 216, 255, 0, 0, 1, 1.2, 5);

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

void Hotels()
{

    glPushMatrix();

    glTranslatef(40, 110, 0);
    glScalef(1.9, 1.4, 0);
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


    //glTranslatef(20, 0, 0);
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

    glTranslatef(330, 0, 0);
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
    glTranslatef(180, 0, 0);
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

	print("Hotel", 0, 0, 128, 1, 110, 492, .17, .2, 1.5);



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
    glTranslatef(350, 60, 0);
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

	glPopMatrix();
}

void lampPost(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy,
               GLfloat light_r, GLfloat light_g,GLfloat light_b)
{
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);



      glBegin(GL_POLYGON);
    glColor3ub (0,0,0);
    glVertex2i(52,320);      //handel
	glVertex2i(58,320);
	glVertex2i(58,230);
	glVertex2i(52,230);
   glEnd();


    drawCircle(55, 320,
		light_r,light_g,light_b,                //light
		7, 14,
		2);


    glPopMatrix();
}

void drawCar(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy){


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



void drawBackground(GLfloat tx, GLfloat ty,
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
	glColor3ub(135, 206, 250); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 150);
	glVertex2f(0, 150);
	glEnd();


	glPopMatrix();
}
void drawBackgroundNight(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(0, 172, 232); // Sky Blue
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(1400, 90);
	glVertex2f(0, 90);
	glEnd();

		// Background
	glBegin(GL_POLYGON);
	glColor3ub(25,25,112); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 200);
	glVertex2f(0, 200);
	glEnd();

	//stars

    for(int i=0;i<500;i++)
    {

      int x=rand()%1800;
      int y=rand()%1000;
      if(y>300){
         drawCircle(x, y, 250, 250, 250, 7, 14, .1);
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
	glVertex2f(1400, 150);
	glVertex2f(0, 150);
	glEnd();


	glPopMatrix();
}


void DayView()
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

      drawBackground(0, 130, 1, 1.2);

      glPushMatrix();
      glTranslatef(sunXAxis,0.0f,0.0f);
      drawCircle(1050, 900, 250, 250, 0, 7, 14, 5); //sun
      glPopMatrix();

      glPushMatrix();
      glTranslatef(cloud1Position,0.0f,0.0f);
      DrawCloud(-800,500,                          //first cloud motion
          2,1);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(cloud2Position,0.0f,0.0f);
      DrawCloud(100,500,                        //third cloud motion
          1.5,.8);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(cloud3Position,0.0f,0.0f);
      DrawCloud(100,580,                        //second cloud motion
          1,.8);
      glPopMatrix();

    building(0, 80, 1.5, 1.4);

    glPushMatrix();
    glTranslatef(moveScenerio,0.0f,0.0f);
    Hotels();

    drawTree(320, 275, .18, .45);
    drawTree(370, 290, .15, .45);
    drawTree(410, 265, .2, .45);
    drawTree(750, 265, .18, .5);
    drawTree(960, 285, .2, .45);
    drawTree(1260, 265, .18, .5);
    drawTree(1730, 290, .15, .45);
    drawTree(1770, 265, .2, .45);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(moveLampPost,0.0f,0.0f);
    for(int i=100;i<=3500;i+=150)
    {

       lampPost(i, 10, 1, 1, 176, 224, 230);
    }
    glPopMatrix();

    PS_drawRoad(-2000, -600, 6, 3);

    glPushMatrix();
    glTranslatef(travellcarPosition1,0.0f,0.0f);
    drawCar(0,20,2.5,2.9);                            //travell car
    glPopMatrix();

    glPushMatrix();
    glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);
    glPopMatrix();

    glEnd();

    glFlush();

}

void NightView(){
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

drawBackgroundNight(0, 110, 1, 1.2);

glPushMatrix();
glTranslatef(sunXAxis,0.0f,0.0f);
drawCircle(1050, 900, 240, 255, 240, 7, 14, 5); //moon
glPopMatrix();

glPushMatrix();
      glTranslatef(cloud1Position,0.0f,0.0f);
      DrawCloud(-800,500,                          //first cloud motion
          2,1);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(cloud2Position,0.0f,0.0f);
      DrawCloud(100,500,                        //third cloud motion
          1.5,.8);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(cloud3Position,0.0f,0.0f);
      DrawCloud(100,580,                        //second cloud motion
          1,.8);
      glPopMatrix();

      building(0, 80, 1.5, 1.4);

        glPushMatrix();
        glTranslatef(moveScenerio,0.0f,0.0f);
        Hotels();

        drawTree(320, 275, .18, .45);
        drawTree(370, 290, .15, .45);
        drawTree(410, 265, .2, .45);
        drawTree(750, 265, .18, .5);
        drawTree(960, 285, .2, .45);
        drawTree(1260, 265, .18, .5);
        drawTree(1730, 290, .15, .45);
        drawTree(1770, 265, .2, .45);
        glPopMatrix();

        PS_drawRoad(-2000, -600, 6, 3);

        glPushMatrix();
        glTranslatef(moveLampPost,0.0f,0.0f);
        for(int i=100;i<=3500;i+=150)
        {
        lampPost(i, 10, 1, 1, 255, 255, 0);
        }
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
        drawCar(0,20,2.5,2.9);                            //travell car
        glPopMatrix();

        glPushMatrix();
        glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);
        glPopMatrix();

        glEnd();

glFlush();

}

void RainView()
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

    drawBackgroundRain(0,130,1,1.2);

    glPushMatrix();
    glTranslatef(cloud1Position,0.0f,0.0f);
    DrawCloudRain(-800,500,                          //first cloud motion
              2,1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloud2Position,0.0f,0.0f);
    DrawCloudRain(100,500,                        //third cloud motion
              1.5,.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud3Position,0.0f,0.0f);
    DrawCloudRain(100,580,                        //second cloud motion
              1,.8);
    glPopMatrix();

    building(0, 80, 1.5, 1.4);

    glPushMatrix();
    glTranslatef(moveScenerio,0.0f,0.0f);
    Hotels();

    drawTree(320, 275, .18, .45);
    drawTree(370, 290, .15, .45);
    drawTree(410, 265, .2, .45);
    drawTree(750, 265, .18, .5);
    drawTree(960, 285, .2, .45);
    drawTree(1260, 265, .18, .5);
    drawTree(1730, 290, .15, .45);
    drawTree(1770, 265, .2, .45);
    glPopMatrix();

    PS_drawRoad(-2000, -600, 6, 3);
    glPushMatrix();

    glPushMatrix();
    glTranslatef(moveLampPost,0.0f,0.0f);
    for(int i=100;i<=3500;i+=150)
    {

       lampPost(i, 10, 1, 1, 176, 224, 230);
    }
    glPopMatrix();

    glTranslatef(travellcarPosition1,0.0f,0.0f);
    drawCar(0,20,2.5,2.9);                            //travell car
    glPopMatrix();

    glPushMatrix();
    glTranslatef(roadMiddleWhiteMark,0.0f,0.0f);
    glPopMatrix();

    rain();

    glEnd();

    glFlush();
}

void init() {
   glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

void display() {
glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT);

glPointSize(5.0);
DayView();
glEnd();

glFlush();

}

void handleMouse(int button, int state, int x, int y) {

if (button == GLUT_RIGHT_BUTTON)
{

			glutDisplayFunc(DayView);

}
if (button == GLUT_LEFT_BUTTON)
{

			glutDisplayFunc(NightView);


}
if (button == GLUT_MIDDLE_BUTTON)
{

			glutDisplayFunc(RainView);

}

//glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

switch (key) {


  break;
    case 'd':

      glutDisplayFunc(DayView);

      break;

    case 'n':

        glutDisplayFunc(NightView);

    break;

    case 'r':

        glutDisplayFunc(RainView);

    break;


        default:
     glutPostRedisplay();
    break;
//glutPostRedisplay();

}
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitWindowSize(1200, 600);
glutInitWindowPosition(50, 50);
glutCreateWindow("Highway View");
glutDisplayFunc(display);
init();
glutTimerFunc(100, update, 0);
glutKeyboardFunc(handleKeypress);
glutMouseFunc(handleMouse);
glutMainLoop();
return 0;
}
