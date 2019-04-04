#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
float t;
int x4,y4,c,d,a;
void myInit(void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-620.0,620.0,-480.0,480.0);
	printf("Enter Center coordinates of parabola :\t");
	scanf("%d%d",&x4,&y4);
	printf("Enter Focus of Parabola :\t");
	scanf("%d",&a);
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	float t=-10;
	c=x4;
	d=y4;
	while (t<=10) {
		c=x4+a*t*t;
		d=y4+2*a*t;
		t=t+1;
		glVertex2i(c,d);
	}
	glEnd();
	glFlush();
}

void main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Parabola Drawing");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
