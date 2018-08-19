#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

int i=0;
int flag=0;
//float x_r=0,y_r=0;
int left_bank_cannibals;
int left_bank_missionaries;
int right_bank_cannibals;
int right_bank_missionaries;
int cannibal_on_boatleft;
int missionary_on_boatleft;
int cannibal_on_boatright;
int missionary_on_boatright;
int left_cannibal_visibility[3],left_missionary_visibility[3],boat_left_character,boat_right_character;
int right_cannibal_visibility[3],right_missionary_visibility[3];
int onboat;
void *currentfont;
void display();
int right_bank;

/*for(i=0;i<3;i++){
    rightCannibalVisibility[i] = 1;
    rightMissionaryVisibility[i] = 1;
}*/
//int boat_left_character;
//int boat_right_character;
void setFont(void *font){
    currentfont=font;
    //printf("in set font");
   // printf("%c",*font);
}
void draw_bank();
void draw_river();

/*void reset(){
 for(i=0;i<3;i++){
    leftCannibalVisibility[i] = 1;
    leftMissionaryVisibility[i] = 1;
    rightMissionaryVisibility[i] = 1;
    rightCannibalVisibility[i] = 1;
    }
    //leftCannibalVisibility[0] = 0;
    //rightMissionaryVisibility[2] = 1;
}*/

void drawString(float x,float y,float z,char *string){
    char *c;
    //printf("in draw string");
    glRasterPos3f(x,y,z);
    for(c=string;*c!='\0';c++){
            //printf("in for loop");
            glColor3f(0.0,0.0,0.0);
            glutBitmapCharacter(currentfont,*c);
    }
}
void font_display(){
    //printf("inside font display");
    /*glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);*/
    glColor3f(0,0,1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawString(400,950,0,"PES INSTITUTE OF TECHNOLOGY");
    glColor3f(0.7,0,1);
    drawString(300,850,0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    //drawString(300,850,0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1,0,1);
    drawString(400,750,0,"A MINI PROJECT ON:");
    glColor3f(1,0.0,0.0);
    drawString(350,650,0,"MISSIONARIES AND CANNIBLES");
    glColor3f(1,0,1);
    drawString(100,550,0,"BY:");
    glColor3f(1,0.5,0);
    drawString(100,450,0,"MANISHA S SONEJA  [1PE15CS082]" );
    glColor3f(1,0.5,0);
    drawString(100,350,0,"MONICA R  [1PE15CS090]");
    glColor3f(1,0.1,1);
    drawString(450,150,0,"PRESS ENTER TO START");
    //glutSwapBuffers();
}
void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glOrtho(0,1000,0,1000,-1.0,1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0,0.0,0.0,1.0);
    //glClear(GL_COLOR_BUFFER_BIT);
}

void keys(unsigned char key ,int x,int y){
    if(key==13){
            if(flag==0){
                flag=1;
                //printf("%d",flag);
            }
            mydisplay();
    }
    //display();
    /*if(flag==1){
    if(key=='n'){
        xr = xr - 70;
        yr =yr + 55;
        glutPostRedisplay();
    }
    }*/
}
/*void keyfunc(int keyfun,int x,int y){
    if(keyfun==GLUT_KEY_RIGHT && (boat_left_character==1 || boat_right_character==1)){
            BoatTranslate_right();
    }
    if(keyfun==GLUT_KEY_LEFT && (boat_left_character==1 || boat_right_character==1)){
        //game_over();
        BoatTranslate_left();
        }
}*/
void game_over(){
    printf("\nright_bank_cannibals %d %d %d %d %d %d",right_bank_cannibals,cannibal_on_boatleft,cannibal_on_boatright,right_bank_missionaries,missionary_on_boatleft,missionary_on_boatright);
      printf("\nleft bank cannibals %d %d",left_bank_cannibals,left_bank_missionaries);
      printf("right bank %d",right_bank);
    if(right_bank==0){
        if((left_bank_cannibals+cannibal_on_boatleft+cannibal_on_boatright)>(left_bank_missionaries+missionary_on_boatleft+missionary_on_boatright) && ((left_bank_missionaries+missionary_on_boatleft+missionary_on_boatright)>0)){
            printf("\n game over\n");
            //exit(0);
            glColor3f(1,0,0);
            setFont(GLUT_BITMAP_HELVETICA_18);
            drawString(450,300,0,"GAME OVER");
        }
        else if(right_bank_cannibals>right_bank_missionaries && right_bank_missionaries>0){
            printf("\nGAME OVER");
            glColor3f(1,0,0);
            setFont(GLUT_BITMAP_HELVETICA_18);
            drawString(450,300,0,"GAME OVER");
            //exit(0);
        }
    }
    if(right_bank==1){
        if((right_bank_cannibals+cannibal_on_boatleft+cannibal_on_boatright)>(right_bank_missionaries+missionary_on_boatleft+missionary_on_boatright) && (right_bank_missionaries+missionary_on_boatleft+missionary_on_boatright)>0){
            //printf("\nright_bank_cannibals %d %d %d %d %d %d",right_bank_cannibals,cannibal_on_boatleft,cannibal_on_boatright,right_bank_missionaries,missionary_on_boatleft,missionary_on_boatright);
            printf("\nGAME over");
            glColor3f(1,0,0);
            setFont(GLUT_BITMAP_HELVETICA_18);
            drawString(450,300,0,"GAME OVER");
            //exit(0);
        }
        else if(left_bank_cannibals>left_bank_missionaries && left_bank_missionaries>0){
        printf("game OVER");
        glColor3f(1,0,0);
        setFont(GLUT_BITMAP_HELVETICA_18);
        drawString(450,300,0,"GAME OVER");
        //exit(0);
        }
        glutSwapBuffers();
}
}
void redraw(){
    int xtrans=-825;
    int xtrans1=1085;
    int ytrans=450;
    draw_bank();
    draw_river();
    for(i=0;i<3;i++){                                       //drawing left cannibals
            if(left_cannibal_visibility[i]==1){
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glPushMatrix();
                glScaled(0.5,0.5,1);
                glTranslated(xtrans,ytrans,1);
                draw_cannibals();
                glPopMatrix();

        //glFlush();
                    //xpos=xpos+60;
            }

            xtrans=xtrans+100;
    }
             for(i=0;i<3;i++){
                printf("\n%d",left_missionary_visibility[i]);
                if(left_missionary_visibility[i]==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(xtrans,ytrans,1);
                    draw_missionaries();
                    glPopMatrix();
                    //xpos=xpos+60;
                }
                xtrans=xtrans+100;

            }
            if(right_bank==0){
                if(cannibal_on_boatleft==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(-270,220,1);
                    draw_cannibals();
                    glPopMatrix();
                }
                if(cannibal_on_boatright==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(20,220,1);
                    draw_cannibals();
                    glPopMatrix();
                }
                if(missionary_on_boatleft==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(-270,220,1);
                    draw_missionaries();
                    glPopMatrix();
                }
                if(missionary_on_boatright==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(20,220,1);
                    draw_missionaries();
                    glPopMatrix();

                }
            }
            else{
                if(cannibal_on_boatleft==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(270,220,1);
                    draw_cannibals();
                    glPopMatrix();
                }
                if(cannibal_on_boatright==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(500,220,1);
                    draw_cannibals();
                    glPopMatrix();
                }
                if(missionary_on_boatleft==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(270,220,1);
                    draw_missionaries();
                    glPopMatrix();
                }
                if(missionary_on_boatright==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(500,220,1);
                    draw_missionaries();
                    glPopMatrix();

                }

            }
            if(right_bank==1){
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glPushMatrix();
                glTranslatef(250,0,0);
                draw_boat();
                glPopMatrix();
            }
            else{
                draw_boat();
            }
            for(i=0;i<3;i++){                                       //drawing right cannibals
            if(right_cannibal_visibility[i]==1){
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glPushMatrix();
                glScaled(0.5,0.5,1);
                glTranslated(xtrans1,ytrans,1);
                draw_cannibals();
                glPopMatrix();

        //glFlush();
                    //xpos=xpos+60;
            }

            xtrans1=xtrans1-100;
    }
            for(i=0;i<3;i++){
                printf("\n%d",left_missionary_visibility[i]);
                if(right_missionary_visibility[i]==1){
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glPushMatrix();
                    glScaled(0.5,0.5,1);
                    glTranslated(xtrans1,ytrans,1);
                    draw_missionaries();
                    glPopMatrix();
                    //xpos=xpos+60;
                }
                xtrans1=xtrans1-100;

            }


}
void mouse(int btn,int state,int x,int y){
       float scaled_y = 1000-(y*1000/744);
    //printf("x=%d y=%f vis=%d onboat=%d\n",x,scaled_y,left_cannibal_visibility[0],onboat);
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
            printf("x=%d y=%f vis=%d onboat=%d\n",x,scaled_y,left_cannibal_visibility[0],onboat);
            if(x>=13 && x<=32 && scaled_y>=283 && scaled_y<=348 && left_cannibal_visibility[0]==1 && onboat<2){
                printf("ENTERS FUNC");
                left_cannibal_visibility[0]=0;
                if(boat_left_character==0){
                    printf("Enters the left seat\n");
                    left_bank_cannibals=left_bank_cannibals-1;
                    boat_left_character=1;
                    cannibal_on_boatleft+=1;
                    onboat=onboat+1;
                    redraw();

                }
                else if(boat_right_character==0){
                    printf("Enters right seat");
                    left_bank_cannibals=left_bank_cannibals-1;
                    boat_right_character=1;
                    cannibal_on_boatright+=1;
                    redraw();

                }
            }
            else if(x>=63 && x<=81 && scaled_y>=283 && scaled_y<=348 && left_cannibal_visibility[1]==1 && onboat<2){
                printf("ENTERS FUNC");
                left_cannibal_visibility[1]=0;
                if(boat_left_character==0){
                    printf("Enters the left seat\n");
                    left_bank_cannibals=left_bank_cannibals-1;
                    boat_left_character=1;
                    cannibal_on_boatleft+=1;
                    onboat=onboat+1;
                    redraw();

                }
                else if(boat_right_character==0){
                    printf("Enters right seat");
                    left_bank_cannibals=left_bank_cannibals-1;
                    boat_right_character=1;
                    cannibal_on_boatright+=1;
                    redraw();

                }
            }
            else if(x>=112 && x<=131 && scaled_y>=283 && scaled_y<=348 && left_cannibal_visibility[2]==1 && onboat<2){
                printf("ENTERS FUNC");
                left_cannibal_visibility[2]=0;
                if(boat_left_character==0){
                    printf("Enters the left seat\n");
                    left_bank_cannibals=left_bank_cannibals-1;
                    boat_left_character=1;
                    cannibal_on_boatleft+=1;
                    onboat=onboat+1;
                    redraw();

                }
                else if(boat_right_character==0){
                    printf("Enters right seat");
                    left_bank_cannibals=left_bank_cannibals-1;
                    boat_right_character=1;
                    cannibal_on_boatright+=1;
                    redraw();

                }
            }
            else if(x>=162 && x<=182 && scaled_y>=283 && scaled_y<=348 && left_missionary_visibility[0]==1 && onboat<2){
                printf("ENTERS FUNC");
                left_missionary_visibility[0]=0;
                if(boat_left_character==0){
                    printf("Enters the left seat\n");
                    left_bank_missionaries=left_bank_missionaries-1;
                    boat_left_character=1;
                    missionary_on_boatleft+=1;
                    onboat=onboat+1;
                    redraw();

                }
                else if(boat_right_character==0){
                    printf("Enters right seat");
                    left_bank_missionaries=left_bank_missionaries-1;
                    boat_right_character=1;
                    missionary_on_boatright+=1;
                    redraw();

                }
            }
            else if(x>=211 && x<=230 && scaled_y>=283 && scaled_y<=348 && left_missionary_visibility[1]==1 && onboat<2){
                printf("ENTERS FUNC");
                left_missionary_visibility[1]=0;
                if(boat_left_character==0){
                    printf("Enters the left seat\n");
                    left_bank_missionaries=left_bank_missionaries-1;
                    boat_left_character=1;
                    missionary_on_boatleft+=1;
                    onboat=onboat+1;
                    redraw();

                }
                else if(boat_right_character==0){
                    printf("Enters right seat");
                    left_bank_missionaries=left_bank_missionaries-1;
                    boat_right_character=1;
                    missionary_on_boatright+=1;
                    redraw();

                }
            }
            else if(x>=263 && x<=283 && scaled_y>=283 && scaled_y<=348 && left_missionary_visibility[2]==1 && onboat<2){
                printf("ENTERS FUNC");
                left_missionary_visibility[2]=0;
                if(boat_left_character==0){
                    printf("Enters the left seat\n");
                    left_bank_missionaries=left_bank_missionaries-1;
                    boat_left_character=1;
                    missionary_on_boatleft+=1;
                    onboat=onboat+1;
                    redraw();

                }
                else if(boat_right_character==0){
                    printf("Enters right seat");
                    left_bank_missionaries=left_bank_missionaries-1;
                    boat_right_character=1;
                    missionary_on_boatright+=1;
                    redraw();

                }
            }
            else if(x>=563 && x<=583 && scaled_y>=206 && scaled_y<=271 && cannibal_on_boatleft==1){
                 cannibal_on_boatleft=cannibal_on_boatleft-1;
                right_bank_cannibals=right_bank_cannibals+1;
                for(i=0;i<3;i++){
                    if(left_cannibal_visibility[i]==0&&right_cannibal_visibility[i]==0)
                        break;
                }
                printf("%d",i);
                boat_left_character=0;
                right_cannibal_visibility[i]=1;
                redraw();
                onboat=onboat-1;
            }
            else if(x>=675 && x<=695 && scaled_y>=206 && scaled_y<=271 && cannibal_on_boatright==1){
                 cannibal_on_boatright=cannibal_on_boatright-1;
                right_bank_cannibals=right_bank_cannibals+1;
                for(i=0;i<3;i++){
                    if(left_cannibal_visibility[i]==0&&right_cannibal_visibility[i]==0)
                        break;
                }
                printf("%d",i);
                boat_right_character=0;
                right_cannibal_visibility[i]=1;
                redraw();
                onboat=onboat-1;
            }
            else if(x>=563 && x<=583 && scaled_y>=206 && scaled_y<=271 && missionary_on_boatleft==1){
                 missionary_on_boatleft=missionary_on_boatleft-1;
                right_bank_missionaries=right_bank_missionaries+1;
                for(i=0;i<3;i++){
                    if(left_missionary_visibility[i]==0&&right_missionary_visibility[i]==0)
                        break;
                }
                printf("%d",i);
                boat_left_character=0;
                right_missionary_visibility[i]=1;
                redraw();
                onboat=onboat-1;
            }
            else if(x>=675 && x<=695 && scaled_y>=206 && scaled_y<=271 && missionary_on_boatright==1){
                missionary_on_boatright=missionary_on_boatright-1;
                right_bank_missionaries=right_bank_missionaries+1;
                for(i=0;i<3;i++){
                    if(left_missionary_visibility[i]==0&&right_missionary_visibility[i]==0)
                        break;
                }
                printf("%d",i);
                boat_right_character=0;
                right_missionary_visibility[i]=1;
                redraw();
                onboat=onboat-1;
            }

            //glutPostRedisplay();
    }
      if(right_bank==1 && (right_bank_cannibals+cannibal_on_boatleft+cannibal_on_boatright) == 3 && (right_bank_missionaries+missionary_on_boatleft+missionary_on_boatright)==3){
        printf("WON THE GAME");
        glColor3f(1,0,0);
        setFont(GLUT_BITMAP_HELVETICA_18);
        drawString(400,300,0,"BRAVO!! WON THE GAME");
        glutSwapBuffers();
    }

    else if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        if(x>=968 && x<=988 && scaled_y>=283 && scaled_y<=348 && right_cannibal_visibility[0]==1 && onboat<2){
            right_cannibal_visibility[0]=0;
            if(boat_left_character==0){
                  right_bank_cannibals=right_bank_cannibals-1;
                    boat_left_character=1;
                    cannibal_on_boatleft=cannibal_on_boatleft+1;
                    onboat=onboat+1;
                    redraw();
            }
            else if(boat_right_character==0){
                right_bank_cannibals=right_bank_cannibals-1;
                boat_right_character=1;
                cannibal_on_boatright=cannibal_on_boatright+1;
                onboat=onboat+1;
                redraw();
            }
        }
        else if(x>=918 && x<=938 && scaled_y>=283 && scaled_y<=348 && right_cannibal_visibility[1]==1 && onboat<2){
            right_cannibal_visibility[1]=0;
            if(boat_left_character==0){
                  right_bank_cannibals=right_bank_cannibals-1;
                    boat_left_character=1;
                    cannibal_on_boatleft=cannibal_on_boatleft+1;
                    onboat=onboat+1;
                    redraw();
            }
            else if(boat_right_character==0){
                right_bank_cannibals=right_bank_cannibals-1;
                boat_right_character=1;
                cannibal_on_boatright=cannibal_on_boatright+1;
                onboat=onboat+1;
                redraw();
            }
        }
        else if(x>=867 && x<=887 && scaled_y>=283 && scaled_y<=348 && right_cannibal_visibility[2]==1 && onboat<2){
            right_cannibal_visibility[2]=0;
            if(boat_left_character==0){
                  right_bank_cannibals=right_bank_cannibals-1;
                  boat_left_character=1;
                  cannibal_on_boatleft=cannibal_on_boatleft+1;
                  onboat=onboat+1;
                  redraw();
            }
            else if(boat_right_character==0){
                right_bank_cannibals=right_bank_cannibals-1;
                boat_right_character=1;
                cannibal_on_boatright=cannibal_on_boatright+1;
                onboat=onboat+1;
                redraw();
            }
        }
        else if(x>=818 && x<=838 && scaled_y>=283 && scaled_y<=348 && right_missionary_visibility[0]==1 && onboat<2){
                 right_missionary_visibility[0]=0;
                if(boat_left_character==0){
                    printf("hi");
                    right_bank_missionaries=right_bank_missionaries-1;
                    boat_left_character=1;
                    missionary_on_boatleft=missionary_on_boatleft+1;
                     onboat=onboat+1;
                     redraw();
                    // game_over();

                }
                else if(boat_right_character==0){
                        right_bank_missionaries=right_bank_missionaries-1;
                        boat_right_character=1;
                        missionary_on_boatright=missionary_on_boatright+1;
                         onboat=onboat+1;
                         redraw();
                      //   game_over();


                }
        }
        else if(x>=766 && x<=786 && scaled_y>=283 && scaled_y<=348 && right_missionary_visibility[1]==1 && onboat<2){
                 right_missionary_visibility[1]=0;
                if(boat_left_character==0){
                    printf("hi");
                    right_bank_missionaries=right_bank_missionaries-1;
                    boat_left_character=1;
                    missionary_on_boatleft=missionary_on_boatleft+1;
                     onboat=onboat+1;
                     redraw();
                    // game_over();

                }
                else if(boat_right_character==0){
                        right_bank_missionaries=right_bank_missionaries-1;
                        boat_right_character=1;
                        missionary_on_boatright=missionary_on_boatright+1;
                         onboat=onboat+1;
                         redraw();
                      //   game_over();


                }
        }
        else if(x>=717 && x<=838 && scaled_y>=283 && scaled_y<=348 && right_missionary_visibility[2]==1 && onboat<2){
                 right_missionary_visibility[2]=0;
                if(boat_left_character==0){
                    printf("hi");
                    right_bank_missionaries=right_bank_missionaries-1;
                    boat_left_character=1;
                    missionary_on_boatleft=missionary_on_boatleft+1;
                     onboat=onboat+1;
                     redraw();
                    // game_over();

                }
                else if(boat_right_character==0){
                        right_bank_missionaries=right_bank_missionaries-1;
                        boat_right_character=1;
                        missionary_on_boatright=missionary_on_boatright+1;
                         onboat=onboat+1;
                         redraw();
                      //   game_over();


                }

        }
        else if(x>=291 && x<=311 && scaled_y>=206 && scaled_y<=271 && cannibal_on_boatleft==1){
            cannibal_on_boatleft=cannibal_on_boatleft-1;
               left_bank_cannibals=left_bank_cannibals+1;
               for(i=0;i<3;i++){
                    if(left_cannibal_visibility[i]==0&&right_cannibal_visibility[i]==0)
                        break;
               }
               printf("%d",i);
               boat_left_character=0;
               left_cannibal_visibility[i]=1;
               redraw();
               onboat=onboat-1;
               boat_left_character=0;
        }
       else if(x>=436 && x<=456 && scaled_y>=206 && scaled_y<=271 && cannibal_on_boatright==1){
            cannibal_on_boatright=cannibal_on_boatright-1;
               left_bank_cannibals=left_bank_cannibals+1;
               for(i=0;i<3;i++){
                    if(left_cannibal_visibility[i]==0&&right_cannibal_visibility[i]==0)
                        break;
               }
               printf("%d",i);
               boat_right_character=0;
               left_cannibal_visibility[i]=1;
               redraw();
               onboat=onboat-1;
               boat_right_character=0;
        }
        else if(x>=291 && x<=311 && scaled_y>=206 && scaled_y<=271 && missionary_on_boatleft==1){
             missionary_on_boatleft=missionary_on_boatleft-1;
               left_bank_missionaries=left_bank_missionaries+1;
               for(i=0;i<3;i++){
                    if(left_missionary_visibility[i]==0&&right_missionary_visibility[i]==0)
                        break;
               }
               printf("%d",i);
               boat_left_character=0;
               left_missionary_visibility[i]=1;
               redraw();
               onboat=onboat-1;
               boat_left_character=0;
        }
        else if(x>=436 && x<=456 && scaled_y>=206 && scaled_y<=271 && missionary_on_boatright==1){
            missionary_on_boatright=missionary_on_boatright-1;
               left_bank_missionaries=left_bank_missionaries+1;
               for(i=0;i<3;i++){
                    if(left_missionary_visibility[i]==0&&right_missionary_visibility[i]==0)
                        break;
               }
               printf("%d",i);
               boat_left_character=0;
               left_missionary_visibility[i]=1;
               redraw();
              onboat=onboat-1;
              boat_right_character=0;
        }

}

    glutSwapBuffers();
}
void mydisplay(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0){
        font_display();
        glutSwapBuffers();
        //printf("hello");
    }
    else
        display();

}
void display(){


    glClear(GL_COLOR_BUFFER_BIT);
    //printf("inside display");
    reset();
    draw_background();
    draw_river();
    //draw_boat();
    //draw_background();
    draw_bank();
    draw_curve();
    draw_sun();
    draw_mountain();
    redraw();
  //  drawCharacters(leftCannibalVisibility,leftMissionaryVisibility,rightMissionaryVisibility, rightCannibalVisibility, boatMissionaryVisibility, boatCannibalVisibility);
    draw_boat();
    //draw_missionaries();
    /*glPushMatrix();
    glScaled(0.5,0.5,1);
    glTranslated(700,200,1);
    draw_missionaries();
    glPopMatrix();*/
    //glFlush();
//    BoatTranslate_left();


    //void BoatTranslate_right();
    /*draw_bank();
    draw_river();
    draw_boat();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //if(flag==0){
      //      font_display();
    }//
        glColor3f(1.0,0.0,0.0);
        glVertex2f(560.0+xr,500.0+yr);
        glVertex2f(610.0+xr,500.0+yr);
        glVertex2f(610.0+xr,550.0+yr);
        glVertex2f(560.0+xr,550.0+yr);
    //glEnd();

        //glMatrixMode(GL_MODELVIEW);
        //glLoadIdentity();
        //glTranslatef(500,500,0);

   /* glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-50.0,-50.0);
        glVertex2f(50.0,-50.0);
        glVertex2f(50.0,50.0);
        glVertex2f(-50.0,50.0);
    glEnd();*/

    glutSwapBuffers();
}
void BoatTranslate_right()
{

    //glTranslatef(-200,0,0);
    right_bank=1;
    redraw();
    glutSwapBuffers();
    game_over();
    glFlush();
}
void BoatTranslate_left(){
    right_bank=0;
    redraw();
    glutSwapBuffers();
    game_over();
    glFlush();

}
void reset(){
     for(i=0;i<3;i++){
      right_cannibal_visibility[i]=0;
      right_missionary_visibility[i]=0;
      left_cannibal_visibility[i]=1;
      left_missionary_visibility[i]=1;
    }
    boat_left_character=0;
    right_bank=0;
    boat_right_character=0;
    left_bank_cannibals=3;
    left_bank_missionaries=3;
    right_bank_cannibals=0;
    right_bank_missionaries=0;
    right_bank=0;
    onboat=0;
    missionary_on_boatleft=0;
    missionary_on_boatright=0;
    cannibal_on_boatleft=0;
    cannibal_on_boatright=0;

}

void keyfunc(int keyfun,int x,int y){
    if(keyfun==GLUT_KEY_RIGHT && (boat_left_character==1 || boat_right_character==1)){
            BoatTranslate_right();
    }
    if(keyfun==GLUT_KEY_LEFT && (boat_left_character==1 || boat_right_character==1)){
        //game_over();
        BoatTranslate_left();
        }
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    //printf("Screen height=%d \nwidth=%d\n",glutGet(GLUT_WINDOW_HEIGHT),glutGet(GLUT_WINDOW_WIDTH));
    glutCreateWindow("MISSIONARIES AND CANNIBALS");
    myinit();
    glutMouseFunc(mouse);
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(keys);
    glutSpecialFunc(keyfunc);
    printf("Screen height=%d \nwidth=%d\n",glutGet(GLUT_WINDOW_HEIGHT),glutGet(GLUT_WINDOW_WIDTH));
    //glutMouseFunc(mouse);
    glutMainLoop();
}
