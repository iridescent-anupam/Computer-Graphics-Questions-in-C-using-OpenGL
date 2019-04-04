#include<GL/glut.h>
#include<stdio.h>

int ex, ey, rx, ry;

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

void drawEllipse(int cx, int cy, int x, int y)
{
	plot(cx+x, cy+y);
	plot(cx+x, cy-y);
	plot(cx-x, cy+y);
	plot(cx-x, cy-y);
}

void bresenhamEllipse(int ex, int ey, int rx, int ry, int check)
{
	int x=0, y=ry, rx2=rx*rx, ry2=ry*ry;
	int pk=2*ry2-2*rx2*ry+rx2;
	while (-x*ry2/((float)y*rx2)>-1)
	{
		if(check)
		{
			drawEllipse(ex, ey, x, y);
		}
		else
		{
			drawEllipse(ex, ey, y, x);
		}
		if (pk<0) 
		{
			pk=pk+2*ry2*(2*x+3);
		} 
		else 
		{
			pk=pk+2*ry2*(2*x+3)+4*rx2*(1-y);
			y--;
		}
		x++;
  	}
	x=rx, y=0;
	pk=2*ry2*(2*rx+1);
	while (-x*ry2/((float)y*rx2)<-1) 
	{
		if(check)
		{
			drawEllipse(ex, ey, x, y);
		}
		else
		{
			drawEllipse(ex, ey, y, x);
		}
		if (pk<0)
		{
			pk=pk+2*rx2*(2*y+3);
		} else 
		{
			pk=pk+2*rx2*(2*y+3)+4*ry2*(1-x);
			x--;
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
	gluOrtho2D(-640,640,-480,480);
	printf("Enter the center of the ellipse: ");
	scanf("%d%d",&ex, &ey);
	printf("Enter the x and y axis radius: ");
	scanf("%d%d", &rx, &ry);
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
	if(rx>ry)
	{
		bresenhamEllipse(ex, ey, rx, ry, 1);	
	}
	else
	{
		bresenhamEllipse(ex, ey, ry, rx, 0);
	}
	glEnd();
	glFlush();
}

void main(int argc,char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Ellipse");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
