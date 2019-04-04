#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cx, cy, r;

void myInit(void)

	{
		glClearColor(1.0,1.0,1.0,1.0);

		glColor3f(0.0f,0.0f,0.0f);

		glPointSize(1.0);

		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		gluOrtho2D(-640,640,-480,480);

	}	



void drawCircle(int cx, int cy, int x, int y)

	{
		glBegin(GL_POINTS);
		
		glColor3f(0.0f,0.0f,1.0f);
		
		glVertex2i(cx+x, cy+y);

		glVertex2i(cx+x, cy-y);

		glVertex2i(cx-x, cy+y);

		glVertex2i(cx-x, cy-y);

		glVertex2i(cx+y, cy+x);

		glVertex2i(cx+y, cy-x);

		glVertex2i(cx-y, cy+x);

		glVertex2i(cx-y, cy-x);
		
		glEnd();
	    glFlush();
	}

void bresCircle(int cx, int cy, int r)

	{
		int x=0, y=r, pk=1-r;

		while (x<y) 
	
			{
				drawCircle(cx, cy, x, y);

				if (pk<0) 
					{
						pk=pk+2*x+3;
					}

				else
					{
					        pk=pk+2*(x-y)+5;
					        y--;
					}

				x++;
			}

			drawCircle(cx, cy, x, y);
	}


void myDisplay(void)

	{
		glClear(GL_COLOR_BUFFER_BIT);
	    glBegin(GL_LINES);	
	    int i, j;
	    for(i=-640; i<=640; i+=20)
	    {
		  for(j=-480; j<=480; j=j+20)
		  {
			glVertex2i(-640,j);
			glVertex2i(640,j);
			glVertex2i(i,-480);
			glVertex2i(i,480);
		  }
	    }
	    
	      glBegin(GL_LINES);
	      glLineWidth(10);
	      glColor3f(1.0f,0.0f,0.0f);
	      glVertex2i(0,480);
	      glVertex2i(0,-480);
	      glVertex2i(640,0);
	      glVertex2i(-640,0);
		  glEnd();

		bresCircle(cx, cy, r);

		glEnd();

		glFlush();

	}

void main(int argc, char** argv)

	{
		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

		glutInitWindowSize(640,480);

		glutInitWindowPosition(0,0);
	
		glutCreateWindow("Circle");
		
		printf("Enter the x&y coordinates of center and then radius of the circle: ");

		scanf("%d%d%d",&cx, &cy, &r );
	
		glutDisplayFunc(myDisplay);
	
		myInit();
	
		glutMainLoop();

	}
