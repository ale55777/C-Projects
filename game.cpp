//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*
int l=15 , m=730;
void drawCarY(){
DrawSquare(l, m, 30, colors[YELLOW]);			//Taxi
	glutPostRedisplay();
}
*/


int xI = 15, yI = 730;

void drawCar() {
	
	DrawSquare(xI, yI, 30, colors[RED]);	
	DrawCircle(xI+8,yI , 6, colors[BLACK]);
	DrawCircle(xI+21,yI ,6 , colors[BLACK]);						//Taxi
	 cout<<xI<<"-"<<yI<<endl;
	glutPostRedisplay();
}


			// Enemy cars //
 int  y=200;
void drawCar1() {
	DrawSquare(50,y , 30, colors[KHAKI]);
	DrawCircle(50+8,y , 6, colors[BLACK]);
	DrawCircle(50+21,y ,6 , colors[BLACK]);
	glutPostRedisplay();
}

int a=260;
void drawCar2() {
	DrawSquare(a,550 , 30, colors[KHAKI]);
	DrawCircle(a+8,550 , 6, colors[BLACK]);
	DrawCircle(a+21,550 ,6 , colors[BLACK]);
	glutPostRedisplay();
}

int j=500,k=300;
void drawCar3() {
	DrawSquare(j, k, 30, colors[KHAKI]);
	DrawCircle(j+8,k , 6, colors[BLACK]);
	DrawCircle(j+21,k ,6 , colors[BLACK]);
	
	glutPostRedisplay();
}

int z=500;
void drawCar4() {
	DrawSquare(800, z, 30, colors[KHAKI]);
	DrawCircle(800+8,z , 6, colors[BLACK]);
	DrawCircle(800+21,z ,6 , colors[BLACK]);
	
	glutPostRedisplay();
}

		//...............................//
	

bool flag = true;
void moveCar1() {
	if (y> 10 && flag) {
		y -= 10;
		
		if(y < 150)
			
			flag = false;

	}
	else if (y < 1010 && !flag) {
		
		y+= 10;
		if (y >450)
			flag = true;
	}
	
}

bool flag1 = true;
void moveCar2() {
	
	if (a> 10 && flag1) {
		a -= 10;
		
		if(a < 255)
			
			flag1 = false;

	}
	else if (a < 1010 && !flag1) {
		
		a += 10;
		if (a >755 )
			flag1 = true;
	}
}

	



bool flag3 = true;
void moveCar3() {
	
	if (k > 10 && flag3) {
		k -= 10;
		
		if(k < 110)
			
			flag3 = false;

	}
	else if (k< 450 && !flag3) {
		
		k += 10;
		if (k > 350)
			flag3= true;
	}
}


bool flag4 = true;
void moveCar4() {
	
if (z > 10 && flag4) {
		z -= 10;
		
		if(z < 110)
			
			flag4 = false;

	}
	else if (z< 450 && !flag4) {
		
		z += 10;
		if (z > 350)
			flag4= true;
	}
}


void obstacles(){
 // center line left 
 if(xI<=450 && xI>=240 && yI==270 )
yI-=10;
else if(xI<=450 && xI>=240 && yI==340 )
yI+=10;
else if(yI<=320 && yI>=300 && xI==215)
xI-=10;
else if(yI<=320 && yI>=300 && xI==455)
xI+=10;


 // center line right 
  if(xI<=800 && xI>=600 && yI==270 )
yI-=10;
else if(xI<=800 && xI>=600 && yI==340 )
yI+=10;
else if(yI<=320 && yI>=300 && xI==565)
xI-=10;
else if(yI<=320 && yI>=300 && xI==805)
xI+=10;

//Down 3 line left //
if(yI<=275 && yI>=150 && xI==155 )
xI+=10;
else if(yI<=275 && yI>=150 && xI==65 )
xI-=10;

//Down 3 line right //
if(yI<=275 && yI>=150 && xI==155 )
xI+=10;
else if(yI<=275 && yI>=150 && xI==865 )
xI-=10;

else if(yI<=275 && yI>=150 && xI==955 )
xI+=10;

else if (xI<=955 && xI>=865 && yI==300) 
yI+=10;
else if (xI<=140 && xI>=75 && yI== 300)
yI+=10;
//........................//
//bottom line//

if (xI<=575 && xI>=445 && yI==100 )
yI+=10;
else if(xI<=575 && xI>=445 && yI==30 )
yI-=10;

//upper line//
if (xI<=575 && xI>=445 && yI==700 )
yI+=10;
else if(xI<=575 && xI>=445 && yI==630 )
yI-=10;

//.............................//
if(yI<=650 && yI>=495 && xI==155 )
xI+=10;
else if(yI<=650 && yI>=495 && xI==65 )
xI-=10;

//.........................//

 if(yI<=650 && yI>=495 && xI==955 )
xI+=10;

//...........................//

glutPostRedisplay();
}

int m=165 , n=40;
int s=930 , t=330;
void pessenger1(){

  DrawCircle(m, n, 10, colors[BLACK]);				
  DrawRectangle(m-5,n-15,10, 20, colors[BLACK]);			

if(m==8000)

DrawCircle(s,t, 18, colors[CHOCOLATE]);


glutPostRedisplay();
}








void drawmap()
{

    DrawRectangle(0,0,1020,760,colors[WHITE]);
    for (int i=0 ; i<19 ; i++) 
    {
  DrawLine( 50,1020 , 50,10 ,  4,colors[BLACK]);
  DrawLine( 100,1020 , 100,10 ,  4,colors[BLACK]);
  DrawLine( 150,1020 , 150,10 ,  4,colors[BLACK]);
  DrawLine( 200,1020 , 200,10 ,  4,colors[BLACK]);
  DrawLine( 250,1020 , 250,10 ,  4,colors[BLACK]);
  DrawLine( 300,1020 , 300,10 ,  4,colors[BLACK]);
  DrawLine( 350,1020 , 350,10 ,  4,colors[BLACK]);
  DrawLine( 400,1020 , 400,10 ,  4,colors[BLACK]);
  DrawLine( 450,1020 , 450,10 ,  4,colors[BLACK]);
  DrawLine( 500,1020 , 500,10 ,  4,colors[BLACK]);
  DrawLine( 550,1020 , 550,10 ,  4,colors[BLACK]);
  DrawLine( 600,1020 , 600,10 ,  4,colors[BLACK]);
  DrawLine( 650,1020 , 650,10 ,  4,colors[BLACK]);
  DrawLine( 700,1020 , 700,10 ,  4,colors[BLACK]);
  DrawLine( 750,1020 , 750,10 ,  4,colors[BLACK]);
  DrawLine( 800,1020 , 800,10 ,  4,colors[BLACK]);
  DrawLine( 850,1020 , 850 ,10,  4,colors[BLACK]);
  DrawLine( 900,950 , 900,10 ,  4,colors[BLACK]);
  DrawLine( 950,950 , 950,10 ,  4,colors[BLACK]);
  DrawLine( 1000,950 , 1000,10, 4,colors[BLACK]);
  DrawLine( 1050,950 , 1050,10, 4,colors[BLACK]);
 
 //...............................................//
 //OBSTACLES//
 
 
   //1 down//
   //DrawSquare(100,100 , 50, colors[BLACK]);
   DrawSquare(100,150 , 50, colors[BLACK]);
   DrawSquare(100,200 , 50, colors[BLACK]);
   DrawSquare(100,250 , 49, colors[BLACK]);
   //CENTER LINE
   DrawSquare(400,300 , 49, colors[BLACK]);
   DrawSquare(350,300 , 49, colors[BLACK]);
   DrawSquare(300,300 , 49, colors[BLACK]);
   DrawSquare(250,300 , 49, colors[BLACK]);
   
   //1 up //
   DrawSquare(100,500 , 49, colors[BLACK]);
   DrawSquare(100,550 , 49, colors[BLACK]);
   DrawSquare(100,600 , 49, colors[BLACK]);
   DrawSquare(150,550 , 49, colors[BLACK]);
   DrawSquare(200,550 , 49, colors[BLACK]);
  
   //2 up//
   DrawSquare(800,550 , 49, colors[BLACK]);
   DrawSquare(850,550 , 49, colors[BLACK]);
   DrawSquare(900,550 , 49, colors[BLACK]); 
   DrawSquare(900,500 , 49, colors[BLACK]); 
   DrawSquare(900,600 , 49, colors[BLACK]); 
   
   // CENTER LINE
   DrawSquare(600,300 , 49, colors[BLACK]);
   DrawSquare(650,300 , 49, colors[BLACK]);
   DrawSquare(700,300 , 49, colors[BLACK]);
   DrawSquare(750,300 , 49, colors[BLACK]);
   
   //2 down //
   DrawSquare(900,150 , 50, colors[BLACK]);
   DrawSquare(900,200 , 50, colors[BLACK]);
   DrawSquare(900,250 , 49, colors[BLACK]);  
 //.........................................//
 
 //Middle line down//
 
   DrawSquare(450,50 , 50, colors[BLACK]);
   DrawSquare(500,50 , 50, colors[BLACK]);
   DrawSquare(550,50 , 50, colors[BLACK]);
   
  //Middle line up//
   DrawSquare(450,650 , 50, colors[BLACK]);
   DrawSquare(500,650 , 50, colors[BLACK]);
   DrawSquare(550,650 , 50, colors[BLACK]); 
   //.....................................................//
   //END//
  /* 
    DrawSquare(0,0 , 10, colors[BLACK]);
   DrawSquare(50,0 , 10, colors[BLACK]);
  DrawSquare(100,0 , 10, colors[BLACK]);
  DrawSquare(150,0 , 10, colors[BLACK]);
  DrawSquare(200,0 , 10, colors[BLACK]);
  DrawSquare(250,0 , 10, colors[BLACK]);
  DrawSquare(300,0 , 10, colors[BLACK]);
  DrawSquare(350,0 , 10, colors[BLACK]);
  DrawSquare(400,0 , 10, colors[BLACK]);
  DrawSquare(450,0 , 10, colors[BLACK]);
  DrawSquare(500,0 , 10, colors[BLACK]);
  DrawSquare(550,0 , 10, colors[BLACK]);
  DrawSquare(600,0 , 10, colors[BLACK]);
  DrawSquare(650,0 , 10, colors[BLACK]);
  DrawSquare(700,0 , 10, colors[BLACK]);
  /*
 */
 //x axis//
  DrawRectangle(0, 0, 50, 10, colors[RED]);
  DrawRectangle(50, 0, 50, 10, colors[BLACK]);
  DrawRectangle(100, 0, 50, 10, colors[RED]);
  DrawRectangle(150, 0, 50, 10, colors[BLACK]);
  DrawRectangle(200, 0, 50, 10, colors[RED]);
  DrawRectangle(250, 0, 50, 10, colors[BLACK]);
  DrawRectangle(300, 0, 50, 10, colors[RED]);
  DrawRectangle(350, 0, 50, 10, colors[BLACK]);
  DrawRectangle(400, 0, 50, 10, colors[RED]);
  DrawRectangle(450, 0, 50, 10, colors[BLACK]);
  DrawRectangle(500, 0, 50, 10, colors[RED]);
  DrawRectangle(550, 0, 50, 10, colors[BLACK]);
  DrawRectangle(600, 0, 50, 10, colors[RED]);
  DrawRectangle(650, 0, 50, 10, colors[BLACK]);
  DrawRectangle(700, 0, 50, 10, colors[RED]); 
  DrawRectangle(750, 0, 50, 10, colors[BLACK]);
  DrawRectangle(800, 0, 50, 10, colors[RED]);
  DrawRectangle(850, 0, 50, 10, colors[BLACK]);
  DrawRectangle(900, 0, 50, 10, colors[RED]);
  DrawRectangle(950, 0, 50, 10, colors[BLACK]);
  
  //left tree//
  DrawCircle(275, 380, 22, colors[GREEN]);
  DrawRectangle(270, 350, 15, 20, colors[BROWN]);
  //right tree//	
  DrawCircle(775, 380, 22, colors[GREEN]);
  DrawRectangle(770, 350, 15, 20, colors[BROWN]);
  //right up tree//
  DrawCircle(225, 630, 22, colors[GREEN]);
  DrawRectangle(220, 600, 15, 20, colors[BROWN]);
  //left up tree//
   DrawCircle(825, 630, 22, colors[GREEN]);
  DrawRectangle(820, 600, 15, 20, colors[BROWN]);
  //end of trees/
  //blue boxes//
   DrawSquare(400,350 , 50, colors[BLUE]);
   DrawSquare(600,350 , 50, colors[BLUE]);
   DrawSquare(250,10 , 50, colors[BLUE]);
   DrawSquare(750,10 , 50, colors[BLUE]);
//..............................................//
 
 DrawString( 910, 720, "SCORE=0", colors[BLACK]);
glutPostRedisplay();
}
}

void GameDisplay()/**/
		{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	//glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	//0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	
	
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	
	drawmap();
	drawCar();
	drawCar1();
	drawCar2();
	drawCar3();
	drawCar4();
	obstacles();
	pessenger1();
	
	glutSwapBuffers(); // do not modify this line..

}



  

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
       
	}
	if( key== 32 && (xI>=m-30 && xI<=m+30)&&(yI>=n-30 && yI<=n+30))
	m=8000;
	if( key== 32 && (xI>=s-20 && xI<=s+20)&&(yI>=t-20 && yI<=t+20))
	m=s;
	n=t;
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveCar1();
	moveCar2();
	moveCar3();
	moveCar4();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 760; 
	int choice;
	int user,pass;
	int colour;
	
	cout << "\n\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|*******************************************************|\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t WELLCOME TO RUSH HOUR GAME '\t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t_________________________________________________________\n";
//......................................................................................................//	
	
	
	

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Ali Raza Khan"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	
	return 1;
}

#endif /* RushHour_CPP_ */
