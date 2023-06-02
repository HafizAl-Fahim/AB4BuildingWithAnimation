#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
using namespace std;
//sun
int x = 100;
int y = 200;
int m = 120;
int n = 120;
//ab4 front
int x2 = 550;
int y2 = 450;
int m2 = 140;
int n2 = 120;
//cloud
int x3 = 150;
int y3 = 800;
int m3 = 80;
int n3 = 80;

int x4 = 250;
int y4 = 800;
int m4 = 80;
int n4 = 80;

int x5 = 250;
int y5 = 900;
int m5 = 80;
int n5 = 80;

int x6 = 150;
int y6 = 900;
int m6 = 80;
int n6 = 80;

int x7 = 100;
int y7 = 850;
int m7 = 80;
int n7 = 80;

int x8 = 300;
int y8 = 850;
int m8 = 80;
int n8 = 80;


void myInit()
{

    //glClearColor(0.0, 1.0, 0.0, 0.0);
    //glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
    //glColor3f(0.0, 0.2, 0.0);
    glClearColor(135.0f / 206.0f, 0, 0, 235.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    // setting window dimension in X- and Y- direction
    glOrtho(0, 1000, 0, 1000, -10.0, 10.0);


}

//moon
void circle(float x1, float y1, float rx, float ry)
{
    float x2, y2;

    //glBegin(GL_POLYGON);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 252, 215); //Center Color of Circle
    glVertex2f(x1, y1); //Center Vertex
    int angle;
    for (angle = 0;angle <= 360;angle++) //0,90,180,270
    {
        glColor3ub(254, 252, 215); //Edge color of Circle
        x2 = x1 + rx * sin((angle * 3.1416) / 180);  // convert degree to radian
        y2 = y1 + ry * cos((angle * 3.1416) / 180);
        glVertex2f(x2, y2);
    }

    glEnd();

}


//tree circle
void circleRe(int x, int y, int r, int g, int b)
{
    float x1, y1, x2, y2;
    float radiusx = 50;
    float radiusy = 50;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);
    float angle;
    for (angle = 0;angle <= 360;angle += 0.1)
    {
        int tx = rand() % 20;
        int ty = rand() % 70;
        x2 = tx + x1 + sin((angle * 3.1416) / 180) * radiusx;
        y2 = ty + y1 + cos((angle * 3.1416) / 180) * radiusy;
        glVertex2f(x2, y2);
    }

    glEnd();


}

//tree
void tree(int x, int y, int r, int g, int b)
{
    circleRe(x, y, r, g, b);


}

//cloud
void cloud(float x1, float y1, float rx, float ry)
{
    float x2, y2;

    //glBegin(GL_POLYGON);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 204, 204); //Center Color of Circle
    glVertex2f(x1, y1); //Center Vertex
    int angle;
    for (angle = 0;angle <= 360;angle++) //0,90,180,270
    {
        glColor3ub(204, 204, 204); //Edge color of Circle
        x2 = x1 + rx * sin((angle * 3.1416) / 180);  // convert degree to radian
        y2 = y1 + ry * cos((angle * 3.1416) / 180);
        glVertex2f(x2, y2);
    }

    glEnd();

}

void display()
{



    glClear(GL_COLOR_BUFFER_BIT);

    //night sky
    glBegin(GL_POLYGON);
    glColor3ub(19, 24, 98);
    glVertex2d(0, 0);
    glVertex2d(1920, 0);
    glVertex2d(1920, 1080);
    glVertex2d(0, 1080);
    glEnd();

    //moon
    if (y < 1000) {
        y++;
    }
    else {
        y = 0;
    }
    circle(x, y, m, n);

    //cloud
    x3++;
    cloud(x3, y3, m3, n3);
    x4++;
    cloud(x4, y4, m4, n4);
    x5++;
    cloud(x5, y5, m5, n5);
    x6++;
    cloud(x6, y6, m6, n6);
    x7++;
    cloud(x7, y7, m7, n7);
    x8++;
    cloud(x8, y8, m8, n8);

    //Grass
    glBegin(GL_POLYGON);
    glColor3ub(45, 90, 80);
    glVertex2d(0, 0);
    glVertex2d(1000, 0);
    glVertex2d(1000, 200);
    glVertex2d(0, 200);
    glEnd();




    //building 1
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(500, 200);
    glVertex2d(750, 150);
    glVertex2d(750, 700);
    glVertex2d(500, 600);
    glEnd();

    //building 2
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(200, 200);
    glVertex2d(600, 200);
    glVertex2d(600, 600);
    glVertex2d(200, 600);
    glEnd();


    //building 2
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(750, 150);
    glVertex2d(850, 200);
    glVertex2d(850, 650);
    glVertex2d(750, 700);
    glEnd();




    //window 1
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(610, 635);
    glVertex2d(610, 610);
    glVertex2d(635, 620);
    glVertex2d(635, 645);
    glEnd();

    //window 2
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(610, 605);
    glVertex2d(610, 580);
    glVertex2d(635, 590);
    glVertex2d(635, 615);
    glEnd();
    //window 3
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(610, 575);
    glVertex2d(610, 550);
    glVertex2d(635, 560);
    glVertex2d(635, 585);
    glEnd();

    //window 4
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(650, 650);
    glVertex2d(685, 665);
    glVertex2d(685, 640);
    glVertex2d(650, 625);
    glEnd();

    //window 5
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(650, 620);
    glVertex2d(685, 635);
    glVertex2d(685, 610);
    glVertex2d(650, 595);
    glEnd();

    //window 6
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(650, 590);
    glVertex2d(685, 605);
    glVertex2d(685, 580);
    glVertex2d(650, 565);
    glEnd();

    //window 7
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(650, 560);
    glVertex2d(685, 575);
    glVertex2d(685, 550);
    glVertex2d(650, 535);
    glEnd();


    //window 8
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(650, 530);
    glVertex2d(685, 545);
    glVertex2d(685, 520);
    glVertex2d(650, 505);
    glEnd();

    //window 9
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(700, 672);
    glVertex2d(740, 687);
    glVertex2d(740, 662);
    glVertex2d(700, 647);
    glEnd();

    //window 10
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 642);
    glVertex2d(740, 657);
    glVertex2d(740, 632);
    glVertex2d(700, 617);
    glEnd();

    //window 11
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 612);
    glVertex2d(740, 627);
    glVertex2d(740, 602);
    glVertex2d(700, 587);
    glEnd();
    //window 12
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 582);
    glVertex2d(740, 597);
    glVertex2d(740, 572);
    glVertex2d(700, 557);
    glEnd();


    //window 13
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(700, 552);
    glVertex2d(740, 567);
    glVertex2d(740, 542);
    glVertex2d(700, 527);
    glEnd();

    //window 14
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(700, 522);
    glVertex2d(740, 537);
    glVertex2d(740, 512);
    glVertex2d(700, 497);
    glEnd();

    //window 15
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 492);
    glVertex2d(740, 507);
    glVertex2d(740, 482);
    glVertex2d(700, 467);
    glEnd();

    //window 16
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 462);
    glVertex2d(740, 477);
    glVertex2d(740, 452);
    glVertex2d(700, 437);
    glEnd();

    //window 17
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 432);
    glVertex2d(740, 447);
    glVertex2d(740, 422);
    glVertex2d(700, 407);
    glEnd();

    //window 18
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 402);
    glVertex2d(740, 417);
    glVertex2d(740, 392);
    glVertex2d(700, 377);
    glEnd();

    //window 19
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 372);
    glVertex2d(740, 387);
    glVertex2d(740, 362);
    glVertex2d(700, 347);
    glEnd();

    //window 20
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 342);
    glVertex2d(740, 357);
    glVertex2d(740, 332);
    glVertex2d(700, 317);
    glEnd();

    //window 21
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 312);
    glVertex2d(740, 327);
    glVertex2d(740, 302);
    glVertex2d(700, 287);
    glEnd();

    //window 22
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(700, 282);
    glVertex2d(740, 297);
    glVertex2d(740, 272);
    glVertex2d(700, 257);
    glEnd();

    //window 23
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 252);
    glVertex2d(740, 267);
    glVertex2d(740, 242);
    glVertex2d(700, 227);
    glEnd();

    //window 24
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 222);
    glVertex2d(740, 237);
    glVertex2d(740, 212);
    glVertex2d(700, 197);
    glEnd();


    //window 25
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 192);
    glVertex2d(740, 207);
    glVertex2d(740, 182);
    glVertex2d(700, 167);
    glEnd();

    //window 24
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(700, 162);
    glVertex2d(740, 177);
    glVertex2d(740, 152);
    glVertex2d(700, 137);
    glEnd();


    //window 25
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 685);
    glVertex2d(840, 645);
    glVertex2d(840, 620);
    glVertex2d(755, 660);
    glEnd();

    //window 26
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 655);
    glVertex2d(840, 615);
    glVertex2d(840, 590);
    glVertex2d(755, 630);
    glEnd();

    //window 27
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(755, 625);
    glVertex2d(840, 585);
    glVertex2d(840, 560);
    glVertex2d(755, 600);
    glEnd();


    //window 28
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 595);
    glVertex2d(840, 555);
    glVertex2d(840, 530);
    glVertex2d(755, 570);
    glEnd();


    //window 29
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(755, 565);
    glVertex2d(840, 525);
    glVertex2d(840, 500);
    glVertex2d(755, 540);
    glEnd();

    //window 30
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 535);
    glVertex2d(840, 495);
    glVertex2d(840, 470);
    glVertex2d(755, 510);
    glEnd();

    //window 31
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 505);
    glVertex2d(840, 465);
    glVertex2d(840, 440);
    glVertex2d(755, 480);
    glEnd();

    //window 32
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 475);
    glVertex2d(840, 435);
    glVertex2d(840, 410);
    glVertex2d(755, 450);
    glEnd();

    //window 33
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(755, 445);
    glVertex2d(840, 405);
    glVertex2d(840, 380);
    glVertex2d(755, 420);
    glEnd();


    //window 34
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 415);
    glVertex2d(840, 375);
    glVertex2d(840, 350);
    glVertex2d(755, 390);
    glEnd();

    //window 35
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(755, 385);
    glVertex2d(840, 345);
    glVertex2d(840, 320);
    glVertex2d(755, 360);
    glEnd();

    //window 36
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 355);
    glVertex2d(840, 315);
    glVertex2d(840, 290);
    glVertex2d(755, 330);
    glEnd();

    //window 37
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2d(755, 325);
    glVertex2d(840, 285);
    glVertex2d(840, 260);
    glVertex2d(755, 300);
    glEnd();

    //window 38
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 295);
    glVertex2d(840, 255);
    glVertex2d(840, 230);
    glVertex2d(755, 270);
    glEnd();

    //window 39
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 265);
    glVertex2d(840, 225);
    glVertex2d(840, 200);
    glVertex2d(755, 240);
    glEnd();

    //window 40
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 235);
    glVertex2d(840, 195);
    glVertex2d(840, 170);
    glVertex2d(755, 210);
    glEnd();

    //window 41
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(755, 205);
    glVertex2d(840, 165);
    glVertex2d(840, 140);
    glVertex2d(755, 180);
    glEnd();

    //window 42
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(755, 175);
    glVertex2d(840, 135);
    glVertex2d(840, 110);
    glVertex2d(755, 150);
    glEnd();

    //window 43
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(205, 595);
    glVertex2d(595, 595);
    glVertex2d(595, 205);
    glVertex2d(205, 205);
    glEnd();

    //window 44
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 590);
    glVertex2d(590, 590);
    glVertex2d(590, 560);
    glVertex2d(210, 560);
    glEnd();

    //window 45
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 555);
    glVertex2d(590, 555);
    glVertex2d(590, 525);
    glVertex2d(210, 525);
    glEnd();

    //window 46
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 520);
    glVertex2d(590, 520);
    glVertex2d(590, 490);
    glVertex2d(210, 490);
    glEnd();

    //window 47
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 485);
    glVertex2d(590, 485);
    glVertex2d(590, 455);
    glVertex2d(210, 455);
    glEnd();

    //window 48
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 450);
    glVertex2d(590, 450);
    glVertex2d(590, 420);
    glVertex2d(210, 420);
    glEnd();

    //window 49
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 415);
    glVertex2d(590, 415);
    glVertex2d(590, 385);
    glVertex2d(210, 385);
    glEnd();

    //window 50
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 380);
    glVertex2d(590, 380);
    glVertex2d(590, 350);
    glVertex2d(210, 350);
    glEnd();

    //window 51
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 345);
    glVertex2d(590, 345);
    glVertex2d(590, 315);
    glVertex2d(210, 315);
    glEnd();

    //window 52
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 310);
    glVertex2d(590, 310);
    glVertex2d(590, 280);
    glVertex2d(210, 280);
    glEnd();

    //window 53
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 275);
    glVertex2d(590, 275);
    glVertex2d(590, 245);
    glVertex2d(210, 245);
    glEnd();

    //window 54
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(210, 240);
    glVertex2d(590, 240);
    glVertex2d(590, 210);
    glVertex2d(210, 210);
    glEnd();

    //lift
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(260, 640);
    glVertex2d(420, 640);
    glVertex2d(420, 600);
    glVertex2d(260, 600);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(320, 635);
    glVertex2d(360, 635);
    glVertex2d(360, 200);
    glVertex2d(320, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(270, 620);
    glVertex2d(315, 620);
    glVertex2d(315, 605);
    glVertex2d(270, 605);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(370, 620);
    glVertex2d(415, 620);
    glVertex2d(415, 605);
    glVertex2d(370, 605);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(260, 620);
    glVertex2d(270, 620);
    glVertex2d(270, 205);
    glVertex2d(260, 205);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(415, 620);
    glVertex2d(420, 620);
    glVertex2d(420, 205);
    glVertex2d(415, 205);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(465, 600);
    glVertex2d(475, 600);
    glVertex2d(475, 205);
    glVertex2d(465, 205);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(540, 600);
    glVertex2d(550, 600);
    glVertex2d(550, 205);
    glVertex2d(540, 205);
    glEnd();


    //solar
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(500, 600);
    glVertex2d(455, 600);
    glVertex2d(455, 615);
    glVertex2d(500, 615);
    glEnd();

    //ab4 round
    circle(x2, y2, m2, n2);


    //y pillar 2
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(690, 163);
    glVertex2d(695, 163);
    glVertex2d(695, 677);
    glVertex2d(690, 677);
    glEnd();


    //round square
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(410, 200);
    glVertex2d(690, 163);
    glVertex2d(690, 500);
    glVertex2d(410, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 57);
    glVertex2d(370, 540);
    glVertex2d(730, 540);
    glVertex2d(690, 500);
    glVertex2d(410, 500);
    glEnd();

    //center building window
    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(420, 490);
    glVertex2d(680, 490);
    glVertex2d(680, 450);
    glVertex2d(420, 450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(420, 440);
    glVertex2d(680, 440);
    glVertex2d(680, 400);
    glVertex2d(420, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(420, 390);
    glVertex2d(680, 390);
    glVertex2d(680, 350);
    glVertex2d(420, 350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50);
    glVertex2d(420, 340);
    glVertex2d(680, 340);
    glVertex2d(680, 300);
    glVertex2d(420, 300);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(102, 104, 105);
    glVertex2d(420, 290);
    glVertex2d(680, 290);
    glVertex2d(680, 150);
    glVertex2d(420, 200);
    glEnd();


    //front pillar 1
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(500, 190);
    glVertex2d(510, 190);
    glVertex2d(510, 500);
    glVertex2d(500, 500);
    glEnd();


    //front pillar 2
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(590, 190);
    glVertex2d(600, 190);
    glVertex2d(600, 500);
    glVertex2d(590, 500);
    glEnd();

    //stairs
    glBegin(GL_POLYGON);
    glColor3ub(205, 205, 205);
    glVertex2d(480, 285);
    glVertex2d(610, 285);
    glVertex2d(580, 300);
    glVertex2d(510, 300);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(205, 205, 205);
    glVertex2d(480, 255);
    glVertex2d(610, 255);
    glVertex2d(610, 285);
    glVertex2d(480, 285);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(450, 225);
    glVertex2d(630, 225);
    glVertex2d(610, 255);
    glVertex2d(480, 255);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(235, 235, 235);
    glVertex2d(450, 225);
    glVertex2d(630, 225);
    glVertex2d(630, 195);
    glVertex2d(450, 195);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 205, 205);
    glVertex2d(450, 195);
    glVertex2d(630, 195);
    glVertex2d(630, 150);
    glVertex2d(450, 190);
    glEnd();

    //Road 1
    glBegin(GL_POLYGON);
    glColor3ub(67, 76, 72);
    glVertex2d(0, 200);
    glVertex2d(410, 200);
    glVertex2d(410, 150);
    glVertex2d(0, 150);
    glEnd();


    //Road 2
    glBegin(GL_POLYGON);
    glColor3ub(67, 76, 72);
    glVertex2d(410, 200);
    glVertex2d(410, 150);
    glVertex2d(690, 113);
    glVertex2d(690, 163);
    glEnd();

    //Road 3
    glBegin(GL_POLYGON);
    glColor3ub(67, 76, 72);
    glVertex2d(1000, 100);
    glVertex2d(1000, 50);
    glVertex2d(690, 113);
    glVertex2d(690, 163);
    glEnd();

    //roof_corner
    glBegin(GL_POLYGON);
    glColor3ub(67, 76, 72);
    glVertex2d(200, 600);
    glVertex2d(200, 587);
    glVertex2d(188, 587);
    glVertex2d(188, 600);
    glEnd();

    //building pillar 1
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(750, 700);
    glVertex2d(745, 700);
    glVertex2d(745, 150);
    glVertex2d(750, 150);
    glEnd();

    //building pillarr 3
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(640, 656);
    glVertex2d(645, 656);
    glVertex2d(645, 540);
    glVertex2d(640, 540);
    glEnd();

    //building pillar 4
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(600, 640);
    glVertex2d(605, 640);
    glVertex2d(605, 560);
    glVertex2d(600, 560);
    glEnd();

    ///building pillar 5
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(800, 670);
    glVertex2d(805, 670);
    glVertex2d(805, 200);
    glVertex2d(800, 200);
    glEnd();

    //building pillar 1
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(602, 643);
    glVertex2d(602, 638);
    glVertex2d(745, 695);
    glVertex2d(745, 700);
    glEnd();

    //building pillar 2
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(750, 700);
    glVertex2d(750, 695);
    glVertex2d(850, 645);
    glVertex2d(850, 650);
    glEnd();

    //building pillar 5
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2d(850, 650);
    glVertex2d(845, 650);
    glVertex2d(845, 247);
    glVertex2d(850, 247);
    glEnd();


    //grass 2
    glBegin(GL_POLYGON);
    glColor3ub(45, 90, 80);
    glVertex2d(750, 150);
    glVertex2d(1000, 100);
    glVertex2d(1000, 250);
    glVertex2d(850, 250);
    glEnd();

    //tree1
    glBegin(GL_POLYGON);
    glColor3ub(72, 6, 7);
    glVertex2d(100, 200);
    glVertex2d(100, 300);
    glVertex2d(120, 300);
    glVertex2d(120, 200);
    glEnd();
    tree(100, 300, 0, 245, 0);

    //tree2
    glBegin(GL_POLYGON);
    glColor3ub(72, 6, 7);
    glVertex2d(900, 200);
    glVertex2d(900, 300);
    glVertex2d(920, 300);
    glVertex2d(920, 200);
    glEnd();
    tree(900, 300, 0, 245, 0);

    //tree3
    glBegin(GL_POLYGON);
    glColor3ub(72, 6, 7);
    glVertex2d(950, 200);
    glVertex2d(950, 300);
    glVertex2d(970, 300);
    glVertex2d(970, 200);
    glEnd();
    tree(950, 300, 0, 245, 0);

    //tree4
    glBegin(GL_POLYGON);
    glColor3ub(72, 6, 7);
    glVertex2d(950, 100);
    glVertex2d(950, 200);
    glVertex2d(970, 200);
    glVertex2d(970, 100);
    glEnd();
    tree(950, 300, 0, 245, 0);
    //tree5
    glBegin(GL_POLYGON);
    glColor3ub(72, 6, 7);
    glVertex2d(750, 200);
    glVertex2d(750, 300);
    glVertex2d(770, 300);
    glVertex2d(770, 200);
    glEnd();
    tree(750, 300, 0, 245, 0);
    //tree5
    glBegin(GL_POLYGON);
    glColor3ub(72, 6, 7);
    glVertex2d(750, 100);
    glVertex2d(750, 200);
    glVertex2d(770, 200);
    glVertex2d(770, 100);
    glEnd();
    tree(750, 300, 0, 245, 0);

    //Human1
    //head
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(100, 150);
    glVertex2d(120, 150);
    glVertex2d(120, 170);
    glVertex2d(100, 170);
    glEnd();

    //body
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(108, 130);
    glVertex2d(112, 130);
    glVertex2d(112, 150);
    glVertex2d(108, 150);
    glEnd();

    //arms
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(100, 140);
    glVertex2d(108, 140);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(110, 140);
    glVertex2d(128, 140);
    glEnd();

    //legs
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
    glVertex2d(108, 130);
    glVertex2d(108, 120);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(112, 130);
    glVertex2d(112, 120);
    glEnd();

    //Human 2
     //head
    glColor3ub(255, 90, 0);
    glBegin(GL_POLYGON);
    glVertex2d(150, 170);
    glVertex2d(170, 170);
    glVertex2d(170, 190);
    glVertex2d(150, 190);
    glEnd();

    //body
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(158, 150);
    glVertex2d(162, 150);
    glVertex2d(162, 170);
    glVertex2d(158, 170);
    glEnd();

    //arms
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(150, 160);
    glVertex2d(158, 160);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(170, 160);
    glVertex2d(178, 160);
    glEnd();

    // legs
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
    glVertex2d(158, 150);
    glVertex2d(158, 140);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(162, 150);
    glVertex2d(162, 140);
    glEnd();

    //Human 3

    //head
    glColor3ub(5, 20, 18);
    glBegin(GL_POLYGON);
    glVertex2d(200, 220);
    glVertex2d(220, 220);
    glVertex2d(220, 240);
    glVertex2d(200, 240);
    glEnd();

    //body
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(208, 200);
    glVertex2d(212, 200);
    glVertex2d(212, 220);
    glVertex2d(208, 220);
    glEnd();

    //arms
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(200, 210);
    glVertex2d(228, 210);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(220, 210);
    glVertex2d(228, 210);
    glEnd();

    //legs
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
    glVertex2d(208, 200);
    glVertex2d(208, 190);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(212, 200);
    glVertex2d(212, 190);
    glEnd();

    //Human 4

    //head
    glColor3ub(30, 210, 118);
    glBegin(GL_POLYGON);
    glVertex2d(500, 220);
    glVertex2d(520, 220);
    glVertex2d(520, 240);
    glVertex2d(500, 240);
    glEnd();

    //body
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(508, 200);
    glVertex2d(512, 200);
    glVertex2d(512, 220);
    glVertex2d(508, 220);
    glEnd();

    //arms
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(500, 210);
    glVertex2d(528, 210);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(520, 210);
    glVertex2d(528, 210);
    glEnd();

    //legs
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
    glVertex2d(508, 200);
    glVertex2d(508, 190);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(512, 200);
    glVertex2d(512, 190);
    glEnd();


    //front door
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(550, 300);
    glVertex2d(570, 300);
    glVertex2d(570, 340);
    glVertex2d(550, 340);
    glEnd();




    glFlush();
}
void update(int val) {


    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(100, 0);

    // Giving name to window
    glutCreateWindow("AB4 Night");
    myInit();

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    update(0);
    glutMainLoop();
}
