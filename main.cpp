#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
    #include <GL/glu.h>
#endif
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int win;
GLint m_viewport[4];
bool mButtonPressed = false;
enum view { INTRO , MENU , LINEAR , BINARY , EXIT};
view currentView = INTRO;
int mouseX , mouseY;
void *font = GLUT_BITMAP_9_BY_15;
int arr1[15] = {1,3,4,6,2,5,9,7,10,8,11,13,15,12,14};
int arr2[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

const int baseline = 100;
const int barWidth = 30;
const int startX = 100;
const int unitHeight = 20;

const int baseline1 = 100;
const int barWidth1 = 30;
const int startX1 = 100;
const int unitHeight1 = 15;

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
   // glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();
    gluOrtho2D(0,700,0,700);
}
//FIRST
void output(int x , int y , char *str){
    int len, i;
      glRasterPos2f(x, y);
      len = (int) strlen(str);
      for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, str[i]);
      }
}
void rasterDisp(int x , int y , int z , char *str){
    glColor3b(1,1,1);
    glRasterPos3f(x, y, z);
    for(char* c = str; *c != '\0'; c++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  , *c);
    }
}
//END FIRST


//SECOND
void mouseClick(int buttonPressed ,int state ,int x, int y) {
    if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mButtonPressed = true;
       // printf("mousex = %d \nmouseY = %d\n", mouseX, mouseY);
    }
    else
        mButtonPressed = false;
    glutPostRedisplay();
}
void passiveMotionFunc(int x,int y) {
    mouseX = float(x)/(m_viewport[2]/700.0);
    mouseY = 700.0-(float(y)/(m_viewport[3]/700.0));
}
//END SECOND

//THIRD
void keyPressed(unsigned char k, int x, int y){
    printf("key pressed\n");
    switch (k)
    {
        case 13:
            if(currentView == INTRO) {
                currentView = MENU;
                printf("view value changed to %d", currentView);
            }
            printf("enter key pressed\n");
            break;
    }
    glutPostRedisplay();
}
//END THIRD

//FOURTH
void backButton() {
	if(mouseX <= 138 && mouseX >= 69 && mouseY >= 46 && mouseY <= 75){
			glColor3f(0, 0, 1);
			if(mButtonPressed) {
				currentView = MENU;
				mButtonPressed = false;
			}
	}
	else
        glColor3f(1, 0, 0);

	output(82 ,58 , "Back");
}
//END FOURTH

//BARS AND SCREENS
void introScreen(){
    glClear(GL_COLOR_BUFFER_BIT);
    //OUTER LINE
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(7,7);
        glVertex2f(696,7);
        glVertex2f(696,696);
        glVertex2f(7,696);
    glEnd();
    //END OUTER LINE

    //INNER LINE
    glColor3f(0,0,0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(14 , 14);
        glVertex2f(689,14);
        glVertex2f(689,689);
        glVertex2f(14,689);
    glEnd();
    //END INNER LINE

    glColor3f(0,0,1);
    output(160, 660 ,"N.M.A.M INSTITUTE OF TECHNOLOGY");
    glColor3f(0,0,0);
    output(120, 630,"Department of Computer Science and Engineering");

    //LINE BELOW COLLEGE LOGO
    glBegin(GL_LINES);
        glVertex2f(20,620);
        glVertex2f(680,620);
    glEnd();
    //END LINE BELOW LOGO

    output(100, 600, "Mini Project Title:");
    output(230, 600, "     Visualization of Searching Algorithms");

    output(100, 570 , "Course Code : ");
    output(230, 570 , "18CS603");

    output(100, 540, "Course Name : ");
    output(230, 540, "Computer Graphics");


    output(100, 510, "Semester : ");
    output(230, 510, "6th ");

    output(100, 480, "Section : ");
    output(230, 480, "C ");

    output(100, 450, "Submitted By : ");
    output(230 , 450, "4NM18CS164");
    output(230 , 425 , "(Sharma Rahul Munna)");

    output(450 , 450 , "4NM18CS128");
    output(450 , 425 , "(Ramsharavan)");

    output(100, 400, "Submitted To :");
    output(230, 400, "Mr Puneeth R.P ");
    output(230 , 380 , "Assistant Professor Grade II");
    output(230 , 350 , "Department Of Computer Science And Engineering");

    output(250 , 200,">>>>>>>ENTER<<<<<<<");
	glFlush();
 	glutSwapBuffers();
}

void startScreen(){
    //LINEAR BUTTON
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(240 , 550);
        glVertex2f(240 , 650);
        glVertex2f(440 , 650);
        glVertex2f(440 , 550);
    glEnd();

    if(mouseX >= 240 && mouseX <= 440 && mouseY>=550 && mouseY<=650){
		glColor3f(0 ,1 ,1);
		if(mButtonPressed){
            currentView = LINEAR;
			mButtonPressed = false;
		}
	} else
		glColor3f(1 , 0, 0);

    rasterDisp(300 , 590 , 0.4 , "LINEAR");
    //END LINEAR BUTTON


    //BINARY BUTTON
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(240 , 350);
        glVertex2f(240 , 450);
        glVertex2f(440 , 450);
        glVertex2f(440 , 350);
    glEnd();

    if(mouseX>=240 && mouseX<=440 && mouseY>=350 && mouseY<=450){
		glColor3f(0 ,1 ,1);
		if(mButtonPressed){
            currentView = BINARY;
			mButtonPressed = false;
		}
	} else
		glColor3f(1 , 0, 0);

    rasterDisp(300 , 390 , 0.4 , "BINARY");
    //END  BINARY BUTTON


    //EXIT BUTTON
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(240 , 150);
        glVertex2f(240 , 250);
        glVertex2f(440 , 250);
        glVertex2f(440 , 150);
    glEnd();

    if(mouseX>=240 && mouseX<=440 && mouseY>=150 && mouseY<=250){
		glColor3f(0 ,1 ,1);
		if(mButtonPressed){
            currentView = EXIT;
			mButtonPressed = false;
		}
	} else
		glColor3f(1 , 0, 0);

    rasterDisp(300 , 190 , 0.4 , "QUIT");
    //END  EXIT BUTTON


    glutPostRedisplay();

}

//END BARS AND SCREEN

//Algorithms Details
void linear_search_detials(){
     glClear(GL_COLOR_BUFFER_BIT);
    backButton();
    //OUTER LINE
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(7,7);
        glVertex2f(696,7);
        glVertex2f(696,696);
        glVertex2f(7,696);
    glEnd();
    //END OUTER LINE*/

    //INNER LINE
    glColor3f(0,0,0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(14 , 14);
        glVertex2f(689,14);
        glVertex2f(689,689);
        glVertex2f(14,689);
    glEnd();
    //END INNER LINE
    rasterDisp(260,640 , 0.5 , "Linear Search");

    output(40 , 600 , "In Linear Search to find the given element the algorithm traverses");
    output(40 , 570 , "through all the present element of the array and compares each");
    output(40 , 540 , "and every value until it finds the element or encounters");
    output(40 , 510 , "the end of the array. Since in this method it traverses till the");
    output(40 , 480 , "end of the array it has the Time Complexity of O(n) (n = size of array).");
}

void binary_search_details(){
    glClear(GL_COLOR_BUFFER_BIT);
    //OUTER LINE
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(7,7);
        glVertex2f(696,7);
        glVertex2f(696,696);
        glVertex2f(7,696);
    glEnd();
    //END OUTER LINE

    //INNER LINE
    glColor3f(0,0,0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(14 , 14);
        glVertex2f(689,14);
        glVertex2f(689,689);
        glVertex2f(14,689);
    glEnd();
    //END INNER LINE
    rasterDisp(260,640 , 0.5 , "Binary Search");

    output(40 , 600 , "Binary search is the search technique which works efficiently on the");
    output(40 , 570 , "sorted lists. Hence, in order to search an element into some list by");
    output(40 , 540 , "using binary search technique, we must ensure that the list is sorted.");
    output(40 , 510 , "Binary search follows divide and conquer approach in which, the list is");
    output(40 , 480 , "divided into two halves and the item is compared with the middle element");
    output(40 , 450 , "of the list.If the match is found then, the location of middle element");
    output(40 , 420 , "is returned otherwise, we search into either of the halves depending upon");
    output(40 , 390 , "the result produced through the match. Time Complexity of");
    output(40 , 360 , "O(log(n)) (n = size of array).");
}

//End Algorithm Details


void long_delay(){
    for(int i=0; i<=800000000; i++);
}

void draw_individual_bar_linear(int i){
    glRectf(startX + i * barWidth + 15 , baseline , startX + i * barWidth + barWidth, baseline + arr1[i] * unitHeight );
    glFlush();
}

/*void draw_initial_linear_bars(){
    glColor3f(0.3,0.6,0.6);
    for(int i=0; i<15; i++){
        //glRectf(startX + i * barWidth + 15 , baseline , startX + i * barWidth + barWidth, baseline + arr2[i] * unitHeight );
        draw_individual_bar_linear(i);
    }
}
*/

void long_delay_2(){
    long_delay();
    long_delay();
}

void color_only_bar(int i){
    glRectf(startX + i * barWidth + 15 , baseline , startX + i * barWidth + barWidth, baseline + arr1[i] * unitHeight );
    glFlush();
}

void traverse_and_color(int val , int n){

    for(int i=0; i<n; i++){
        glColor3f(1,1,0.4);
        draw_individual_bar_linear(i);
        if(arr1[i] == val){
                color_only_bar(i);
                long_delay();
                glColor3f(0.3,0.6,0.6);
                color_only_bar(i);
                long_delay();
                glColor3f(0,1,0.4);//green
                color_only_bar(i);
                long_delay_2();
                exit(0);
        }
        long_delay();
    }
    exit(0);
}

void draw_initial_linear_bars(){

    int n , val_linear;
    /*printf("Enter Size: ");
    scanf("%d" , &n);
    for(int i=0; i<n; i++){
        printf("Enter Element");
        printf("%d" , i+1);
        printf(": ");
        scanf("%d" , &arr1[i]);
    }*/
//ADD INPUT IF YOU WANT HERE
    glColor3f(0.3,0.6,0.6);
    for(int i=0; i<15; i++){
        draw_individual_bar_linear(i);
    }

    traverse_and_color(6 , 15);
    glFlush();
}

void linear(){
    linear_search_detials();
    backButton();
    draw_initial_linear_bars();
}

void draw_individual_bar_binary(int i){
    glRectf(startX1 + i * barWidth1 + 15 , baseline1 , startX1 + i * barWidth1 + barWidth1, baseline1 + arr2[i] * unitHeight1 );
    glFlush();
}


void traverse_and_color_binary(int val_to_find , int n1){
    int low = 0;
    int high = n1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        glColor3f(1,1,0);
        long_delay();
        draw_individual_bar_binary(mid);
        if(arr2[mid] == val_to_find){
            glColor3f(0,1,0);
            long_delay();
            draw_individual_bar_binary(mid);
        }
        else if(arr2[mid] < val_to_find){
            low = mid + 1;
            long_delay();
            glColor3f(0,0,0);
            for(int i=0; i < low; i++){
                draw_individual_bar_binary(i);
            }
        }
        else{
            high = mid - 1;
            long_delay();
            glColor3f(0,0,0);
            for(int i=high; i<n1; i++){
                draw_individual_bar_binary(i);
            }
        }
    }
}

void draw_initial_binary_bars(){
    backButton();
//ADD INPUT IF YOU WANT HERE
    glColor3f(0.3,0.6,0.6);
    for(int i=0; i<15; i++){
        draw_individual_bar_binary(i);
    }
    traverse_and_color_binary(5 , 15);
    glFlush();

}

void exitScreen(){
    glutDestroyWindow(win);
    exit(0);
}
void binary(){
    binary_search_details();
    draw_initial_binary_bars();
    glFlush();

}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	switch (currentView)
	{
		case INTRO:
			introScreen();
			break;
        case MENU:
            startScreen();
            break;
        case LINEAR:
            linear();
            break;
        case BINARY:
            binary();
            break;
        case EXIT:
            exitScreen();
            break;
        default:
            introScreen();
            break;
	}
	glutSwapBuffers();
}
int main(int argc , char **argv){
    	glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(500,90);
   	glutInitWindowSize(700, 700);
	win = glutCreateWindow("Dynamic Searching Visualizer");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMouseFunc(mouseClick);
	glGetIntegerv(GL_VIEWPORT ,m_viewport);
   	glutPassiveMotionFunc(passiveMotionFunc);
	glutMainLoop();
    	return 0;
}
