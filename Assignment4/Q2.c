#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float x1,yi,x2,y2;

void myInit(void)
{
	glClearColor(0.0,1.0,1.0,0.0);
	glColor3f(10.0f,0.0f,0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0,640.0,-480.0,480.0);
}

void myDisplay(void)
{
      glClear(GL_COLOR_BUFFER_BIT);
      glBegin(GL_POINTS);
      int dx,dy,p,n;
      float x,y;
      dx=(x2-x1);
      dy=(y2-yi);
      p=2*abs(dy)-abs(dx);
      if(abs(dy)<abs(dx) || dy<0 || dx<0)
      {
         if(x1 > x2)
          {
            x=x2;
            y=y2;
            n=x1;
          }
         else
          {
            x=x1;
            y=yi;
            n=x2;
          }
         glVertex2s(x,y);
         while(x<n)
          {
            if(dx!=0)
             x=x+1;
            if(p < 0)
              p=p+2*abs(dy);
            else
             {
              if(dx!=0 && dy/dx<0)
                y=y-1;
              else
                y=y+1;
                p=p+2*(abs(dy)-abs(dx));
             }
             glVertex2s(x,y);
           }
      }
      else
      {
       if(x1>x2)
        {
         x=x2;
         y=y2;
         n=yi;
        }
       else
        {
         x=x1;
         y=yi;
         n=y2;
        }
        glVertex2s(x,y);
        while(y<n)
        {
         y=y+1;
         if(p<0)
          {
           p=p+2*abs(dy);
          }
         else
          {
           if(dx!=0)
            x=x+1;
           p=p+2*(abs(dy)-abs(dx));
          }
         glVertex2s(x,y);
        }
      }
      glEnd();
      glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bresenham's Algorithm");
	printf("Enter the value of x1 : ");
    scanf("%f",&x1);
    printf("Enter the value of y1 : ");
    scanf("%f",&yi);
    printf("Enter the value of x2 : ");
    scanf("%f",&x2);
    printf("Enter the value of y2 : ");
    scanf("%f",&y2);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
