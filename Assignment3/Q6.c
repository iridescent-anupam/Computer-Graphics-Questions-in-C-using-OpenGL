#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

int a,b;
int counter=1;


void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


void myMouse(int button, int state, int x, int y)
{
    int yy;
    yy = glutGet(GLUT_WINDOW_HEIGHT);
    y = yy - y;
    glColor3f(1.0, 0.0, 0.0);
    
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)&&(counter%2==1))
    {
        a=x;
        b=y;
        counter++;
    }
    else if((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)&&(counter%2==0))
    {
        glBegin(GL_LINES);
        glVertex2i(a,b);
        glVertex2i(x, y);
        glEnd();
        counter++;
    }
    glFlush();
}


void myInit(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Line Drawing");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
}
