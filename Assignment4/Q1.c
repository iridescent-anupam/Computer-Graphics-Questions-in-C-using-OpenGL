#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int X1,X2,Y1,Y2,p;

void myInit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);  //Combination of RGB
	glColor3f(1.0f,0.0f,0.0f); //colour of point
	glPointSize(1.0); //size of point
	glMatrixMode(GL_PROJECTION); // sets the current matrix to projection
	glLoadIdentity(); //multiply the current matrix by identity matrix to convert 3D to 2D
	gluOrtho2D(-640.0,640.0,-480.0,480.0); //sets the parallel(orthographic) projection of the full frame buffer 
}



void myDisplay(void)  //Call back function
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);  //writes pixels on the frame buffer with the current drawing color
    int dx=X2-X1;
    int dy=Y2-Y1;
    if(abs(dx)>abs(dy))
      p=abs(dx);
    else
      p=abs(dy);
    float i1=dx/(float)p;
    float i2=dy/(float)p;
    int i=0;
    float x=(float)X1, y=(float)Y1;
    for(i;i<p;i++)
     {
       x=x+i1;
       y=y+i2;
       glColor3f(0.0f,0.0f,1.0f); //colour of point
       glVertex2i(x,y);  // sets vertex
     }
    glEnd();
    glFlush();
}

void main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);  //sets the width and height of the window in pixels
    glutInitWindowPosition(0,0);  //Position of Window on Screen's Origin
    glutCreateWindow("Digital Differential Analyzer"); //Window's name on Titlebar     
    printf("Enter the x coordinate of point 1: ");
	scanf("%d",&X1);
	printf("Enter the y coordinate of point 1: ");
	scanf("%d",&Y1);
	printf("Enter the x coordinate of point 2: ");
	scanf("%d",&X2);
	printf("Enter the y coordinate of point 2: ");
	scanf("%d",&Y2);
	glutDisplayFunc(myDisplay);  //links the display event with the display event handler(display)
	myInit();
	glutMainLoop();  //loops the current event
}
