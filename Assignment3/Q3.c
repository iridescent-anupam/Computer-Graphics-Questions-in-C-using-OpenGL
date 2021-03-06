#include<GL/glut.h>

void myInit(void)
{
 glClearColor(1.0,1.0,1.0,0.0); //Combination of RGB
 glColor3f(0.0f,0.0f,0.0f);
 glPointSize(20.0); //Pixel size is 20x20
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity(); //use of Identity matrix to convert 3D to 2D
 gluOrtho2D(0.0,640.0,0.0,480.0); 
}

void myDisplay(void)  //Call back function
{ 
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POINTS);
 glVertex2i(0,480);
 glVertex2i(0,0); //Origin of Window
 glVertex2i(320,240); //Center of Window
 glEnd();
 glFlush();
}

void main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
 glutInitWindowSize(640,480);
 glutInitWindowPosition(0,0);  //Position of Window on Screen's Origin
 glutCreateWindow("Program of Origins"); //Window's name on Titlebar
 glutDisplayFunc(myDisplay);
 myInit(); 
 glutMainLoop(); //Main function is repeating within a loop
}
