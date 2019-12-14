#include"GL/freeglut.h"
#include"GL/gl.h"

float _angle=0.0f;

void display(){
	glClearColor(0.3,0.4,0.5,0.6);
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(_angle,0.0,0.0,1.0);
	glColor3f(0.0,1.0,1.0);
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.5,-0.5,0);
	glVertex3f(-0.5,-0.5,0);
	glVertex3f(-0.5,0.5,0);
	glVertex3f(0.5,0.5,0);
	glEnd();
	glFlush();
}

void update(int value){
	_angle+=2.0f;
	
	if(_angle>360){
		_angle-=360;
	}
	glutPostRedisplay();
	
	glutTimerFunc(150,update,0);
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(900,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rotating Polygon");
	glutTimerFunc(50,update,0);
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
