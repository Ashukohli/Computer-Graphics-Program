#include"GL/freeglut.h"
#include"GL/gl.h"

float _angle=0.0f;

void display(){
	glClearColor(0.3,0.4,0.5,0.6);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glRotatef(15,0.1,0.1,1.0);
//	glColor3f(1.0,0.0,1.0);
	
	//FRONT
	glBegin(GL_POLYGON);
	
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0.5,0.5,-0.5);
	
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0.5,-0.5,-0.5);
	
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-0.5,-0.5,-0.5);
	
	glColor3f(1.0,0.0,1.0);
	glVertex3f(-0.5,0.5,-0.5);
	
	glEnd();
	
	//BACK
	glBegin(GL_POLYGON);
	
	glColor3f(1.0,1.0,1.0);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(-0.5,0.5,0.5);
	
	glEnd();
	
	//RIGHT
	glBegin(GL_POLYGON);
	
	glColor3f(1.0,0.0,1.0);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glVertex3f(0.5,0.5,-0.5);
	
	glEnd();
	
	//LEFT
	glBegin(GL_POLYGON);
	
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-0.5,0.5,-0.5);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(-0.5,0.5,0.5);
	
	glEnd();
	
	//TOP
	glBegin(GL_POLYGON);
	
	glColor3f(0.0,0.0,1.0);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,0.5,-0.5);
	glVertex3f(-0.5,0.5,-0.5);
	glVertex3f(-0.5,0.5,0.5);
	
	glEnd();
	
	//BOTTOM
	glBegin(GL_POLYGON);
	
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(-0.5,-0.5,0.5);
	
	glEnd();
	
	glFlush();
	
	glutSwapBuffers();
	
	
}

void update(int value){
	_angle+=2.0f;
	
	if(_angle>360){
		_angle-=360;
	}
	glutPostRedisplay();
	
	glutTimerFunc(300,update,0);
}

int main(int argc,char **argv){
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(900,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rotating Cube");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutTimerFunc(50,update,0);
	glutMainLoop();
	
	return 0;
}
