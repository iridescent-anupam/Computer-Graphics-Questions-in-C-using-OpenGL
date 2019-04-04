#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void plot(int x, int y)
{
	glBegin(GL_LINES);
	
	x*=4;
	y*=4;
	int i, j;
	for(i=x-x%4; i<=x-x%4+4; i++)
	{
		for(j=y-y%4; j<=y-y%4+4; j++)
		{
			glVertex2i(i,-j);
			glVertex2i(i,-j+1);	
		}
	}
	glEnd();
	glFlush();
}

void drawParabola(int x, int y)
{
	plot(x, y);
	plot(-x, y);
}

void parabola()
{
	int x=0, y=-100, pk=-3/4.0;
	while(y!=100)
	{
		drawParabola(x, y);
		if(pk<0)
		{
			pk=pk+2*x-1;
			x++;
		}
		else
		{
			pk=pk-1;
		}
		y++;
	}
}

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(640.0,-640.0,-480.0,480.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	    glBegin(GL_LINES);	
	    int i, j;
	    for(i=-640; i<=640; i+=4)
	    {
		  for(j=-480; j<=480; j=j+4)
		  {
			glVertex2i(-640,j);
			glVertex2i(640,j);
			glVertex2i(i,-480);
			glVertex2i(i,480);
		  }
	    }
	    glEnd();
	    
	      glBegin(GL_LINES);
	      glColor3f(1.0f,0.0f,0.0f);
	      glVertex2i(0,480);
	      glVertex2i(0,-480);
	      glVertex2i(640,0);
	      glVertex2i(-640,0);
		  glEnd();
		   
	glBegin(GL_POINTS);
	glColor3f(0.0f,0.0f,1.0f);
	parabola();
	glEnd();
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Parabola");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
