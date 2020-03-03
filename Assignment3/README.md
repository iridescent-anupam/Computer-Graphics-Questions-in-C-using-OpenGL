# Questions -
Assignment 3: Plotting points

Q1.) Study the following functions of OpenGL:

a) glutInit( )

b) glutInitDisplayMode( )

c) glutInitWindowSize( )

d) glutInitWindowPosition( )

e) glutCreateWindow( )

f) gluOrtho2D( )

g) glCleanColor( )

h) glColor3f( )


Q2.) Run and study the following program.

#include <GL/glut.h>

void myInit(void)

{ glClearColor(1.0,1.0,1.0,0.0);

  glColor3f(0.0f,0.0f,0.0f);
  
  glPointSize(4.0);

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluOrtho2D(0.0,640.0,0.0,480.0); }


void myDisplay(void)

{ glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS); glVertex2i(100, 50);

  glVertex2i(100, 130);

  glVertex2i(150, 130);

  glEnd();

  glFlush();
} 


void main(int argc, char** argv)

{
  glutInit(&argc, argv);
  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(640,480);
  
  glutInitWindowPosition(100, 150);
  
  glutCreateWindow("My first program");
  
  glutDisplayFunc(myDisplay);

  myInit();
   
  glutMainLoop();

}

Q3.) Modify the above program to locate the origin (0, 0) of the created window, and also the origin (0, 0) of your screen.

Q4.) Write a program to create a window, in which origin is at middle position.

Q5.) Write a program to plot points, whose coordinates are given by the user through Mouse.

Q6.) Write a program to draw a set of lines, in which end points are given by the user through Mouse or Keyboard.
by the user through Mouse/Keyboard.
