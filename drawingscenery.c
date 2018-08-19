#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
//#include "mission.h"


GLfloat cntrlpts[3][3]= {{437.5,750.0,0},{500,850,0},{562.5,750.0,0}};
void draw_curve(){
    glMap1f(GL_MAP1_VERTEX_3,0.0,1.0,3,3,*cntrlpts);
    glEnable(GL_MAP1_VERTEX_3);
    GLint k;
    glColor3f(1.0,0.9,0.0);
    glBegin(GL_LINE_STRIP);
        for(k=0;k<80;k++)
            glEvalCoord1f((GLfloat) k /80.0);
    glEnd();
  /*  glColor3f(1,0,0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
        for(k=0;k<3;k++)
            glVertex3fv(&cntrlpts[k][0]);
    glEnd();*/
    glFlush();
}
void draw_sun(){
    int i;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    for(i=0;i<125;i++){
        glTranslatef(-0.5,-1.2,0);
        draw_curve();
    }
    glPopMatrix();
    glFlush();
}
void draw_bank(){
    glBegin(GL_QUADS);
        //printf("hello\n");
        glColor3f(0.0,1.0,0.0);
        glVertex2f(0,0);
        glVertex2f(200,0);
        glVertex2f(400,600);
        glVertex2f(0,600);
        //glVertex2f(0,400);

        glColor3f(0.0,1.0,0.0);
        glVertex2f(1000,0);
        glVertex2f(1000,600);
        glVertex2f(600,600);
        glVertex2f(800,0);
        //glVertex2f(700,0);

        glEnd();
}
void draw_background()
{
    glColor4f(0,0.8,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(0,400);
        glVertex2f(1000,400);
        glVertex2f(1000,1000);
        glVertex2f(0,1000);
    glEnd();
}
void draw_mountain()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.4,0.2,0.0);
        glVertex2f(0,600);
        glVertex2f(125,900);
        glVertex2f(250,600);

        glVertex2f(250,600);
        glVertex2f(375,900);
        glVertex2f(500,600);

        glVertex2f(500,600);
        glVertex2f(625,900);
        glVertex2f(750,600);

        glVertex2f(750,600);
        glVertex2f(875,900);
        glVertex2f(1000,600);
    glEnd();
}
void draw_river(){
    glBegin(GL_POLYGON);
        glColor3f(0.2,0.61,0.84);
        glVertex2f(200,0);
        glVertex2f(400,600);
        glVertex2f(600,600);
        glVertex2f(800,0);
    glEnd();
}
void draw_boat(){
    //printf("inside draw boat");
    //glBegin(GL_POLYGON);
    glColor3f(0.1,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(255,160);
        glVertex2f(500,160);
        glVertex2f(450,100);
        glVertex2f(300,100);
    glEnd();
}
void draw_missionaries(){
    // Hair
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(850, 200);
	glVertex2i(850, 250);
	glVertex2i(890, 250);
	glVertex2i(890, 200);
	glEnd();

	// Head
	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
	glVertex2i(860, 235);
	glVertex2i(880, 235);
	glVertex2i(880, 190);
	glVertex2i(860, 190);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
	glVertex2i(865,190);
	glVertex2i(875,190);
	glVertex2i(875,185);
	glVertex2i(865,185);
	glEnd();

	/*// Face
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 17, py + 67);
	glVertex2i(px + 21, py + 67);
	glVertex2i(px + 21, py + 69);
	glVertex2i(px + 17, py + 69);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 24, py + 67);
	glVertex2i(px + 28, py + 67);
	glVertex2i(px + 28, py + 69);
	glVertex2i(px + 24, py + 69);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 20, py + 64);
	glVertex2i(px + 25, py + 64);
	glVertex2i(px + 25, py + 65);
	glVertex2i(px + 20, py + 65);
	glEnd();*/

	// Hand
	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
        glVertex2i(840,185);
        glVertex2i(860,185);
        glVertex2i(860,165);
        glVertex2i(845,165);
        //glVertex2i(850,145);
        //glVertex2i(845,145);
        glVertex2i(845,120);
        glVertex2i(840,120);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
        glVertex2i(900,185);
        glVertex2i(880,185);
        glVertex2i(880,165);
        glVertex2i(895,165);
        glVertex2i(895,120);
        glVertex2i(900,120);
        //glVertex2i(880,165);
	glEnd();

	// Body
	glBegin(GL_POLYGON);
	glColor3f(0.68, 0.50, 0.77);
	glVertex2i(850,185);
	glVertex2i(890,185);
	glVertex2i(890,120);
	glVertex2i(850,120);
	glEnd();


	// Pant
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.33, 0.56);
	glVertex2i(850,120);
	glVertex2i(890,120);
	glVertex2i(890,100);
	glVertex2i(850,100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.33, 0.56);
	glVertex2i(850,100);
	glVertex2i(865,100);
	glVertex2i(865,55);
	glVertex2i(850,55);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.33, 0.56);
	glVertex2i(875,100);
	glVertex2i(890,100);
	glVertex2i(890,55);
	glVertex2i(875,55);
	glEnd();



	/*// Shoes
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 7, py + 3);
	glVertex2i(px + 19, py + 3);
	glVertex2i(px + 19, py + 8);
	glVertex2i(px + 7, py + 8);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 25, py + 3);
	glVertex2i(px + 38, py + 3);
	glVertex2i(px + 38, py + 8);
	glVertex2i(px + 25, py + 8);
	glEnd();*/
}
void draw_cannibals(){
    // Hair
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(850, 200);
	glVertex2i(850, 250);
	glVertex2i(890, 250);
	glVertex2i(890, 200);
	glEnd();

	// Head
	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
	glVertex2i(860, 235);
	glVertex2i(880, 235);
	glVertex2i(880, 190);
	glVertex2i(860, 190);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
	glVertex2i(865,190);
	glVertex2i(875,190);
	glVertex2i(875,185);
	glVertex2i(865,185);
	glEnd();

	/*// Face
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 17, py + 67);
	glVertex2i(px + 21, py + 67);
	glVertex2i(px + 21, py + 69);
	glVertex2i(px + 17, py + 69);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 24, py + 67);
	glVertex2i(px + 28, py + 67);
	glVertex2i(px + 28, py + 69);
	glVertex2i(px + 24, py + 69);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 20, py + 64);
	glVertex2i(px + 25, py + 64);
	glVertex2i(px + 25, py + 65);
	glVertex2i(px + 20, py + 65);
	glEnd();*/

	// Hand
	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
        glVertex2i(840,185);
        glVertex2i(860,185);
        glVertex2i(860,165);
        glVertex2i(845,165);
        //glVertex2i(850,145);
        //glVertex2i(845,145);
        glVertex2i(845,120);
        glVertex2i(840,120);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.99, 0.87, 0.75);
        glVertex2i(900,185);
        glVertex2i(880,185);
        glVertex2i(880,165);
        glVertex2i(895,165);
        glVertex2i(895,120);
        glVertex2i(900,120);
        //glVertex2i(880,165);
	glEnd();

	// Body
	glBegin(GL_POLYGON);
	glColor3f(0.68, 0.50, 0.77);
	glVertex2i(850,185);
	glVertex2i(890,185);
	glVertex2i(890,120);
	glVertex2i(850,120);
	glEnd();


	// Pant
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.33, 0.56);
	glVertex2i(850,120);
	glVertex2i(890,120);
	glVertex2i(890,100);
	glVertex2i(850,100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.33, 0.56);
	glVertex2i(850,100);
	glVertex2i(865,100);
	glVertex2i(865,55);
	glVertex2i(850,55);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.33, 0.56);
	glVertex2i(875,100);
	glVertex2i(890,100);
	glVertex2i(890,55);
	glVertex2i(875,55);
	glEnd();



	/*// Shoes
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 7, py + 3);
	glVertex2i(px + 19, py + 3);
	glVertex2i(px + 19, py + 8);
	glVertex2i(px + 7, py + 8);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(px + 25, py + 3);
	glVertex2i(px + 38, py + 3);
	glVertex2i(px + 38, py + 8);
	glVertex2i(px + 25, py + 8);
	glEnd();*/
}
/*void drawCharacters(int leftCannibalVisibility[],int leftMissionaryVisibility[],int rightMissionaryVisibility[],int rightCannibalVisibility[],int boatMissionaryVisibility[],int boatCannibalVisibility[]){

	if (leftCannibalVisibility[0]==1){
        glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(-825,450,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

	if (leftCannibalVisibility[1]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(-725,450,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

	if (leftCannibalVisibility[2]==1){
        glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(-625,450,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

	if (leftMissionaryVisibility[0]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(-525,450,1);
        draw_missionaries();
        glPopMatrix();
        glFlush();
	}

	if (leftMissionaryVisibility[1]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(-425,450,1);
        draw_missionaries();
        glPopMatrix();
        glFlush();
	}

	if (leftMissionaryVisibility[2]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(-325,450,1);
        draw_missionaries();
        glPopMatrix();
        glFlush();
	}

	if (rightCannibalVisibility[0]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(585,450,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

	if (rightCannibalVisibility[1]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(685,450,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

	if (rightCannibalVisibility[2]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(785,450,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

	if (rightMissionaryVisibility[0]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(885,450,1);
        draw_missionaries();
        glPopMatrix();
	}

	if (rightMissionaryVisibility[1]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(985,450,1);
        draw_missionaries();
        glPopMatrix();
	}


	if (rightMissionaryVisibility[2]==1){
		glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(1085,450,1);
        draw_missionaries();
        glPopMatrix();
        glFlush();
	}

	if (boatCannibalVisibility[0] == 1){
        glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(-270,220,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

	if (boatCannibalVisibility[1] == 1){
        glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(20,220,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}

    if (boatCannibalVisibility[2] == 1){
        glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(20,220,1);
        draw_cannibals();
        glPopMatrix();
        glFlush();
	}
	if (boatMissionaryVisibility[0] == 1){
        glPushMatrix();
        glScaled(0.5,0.5,1);
        glTranslated(20,220,1);
        draw_missionaries();
        glPopMatrix();
        glFlush();
	}

}*/


