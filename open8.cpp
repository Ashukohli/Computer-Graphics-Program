#include"GL/freeglut.h"
#include"GL/gl.h"

float _angle=0.0f;

void display(){
	glClearColor(0.3,0.4,0.5,0.6);
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(_angle,0.0,0.0,1.0);
	glColor3f(0.0,1.0,1.0);
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0,-0.5,0);
	glVertex3f(0,0.5,0);
	glVertex3f(0.5,0.2,0);
	glEnd();
	glFlush();
}

void keypress(int key,int x,int y){
	
	if(key==27){
		exit(0);
	}
	if(key==GLUT_KEY_RIGHT){
		_angle+=5;
	}
	if(key==GLUT_KEY_LEFT){
		_angle-=5;
	}
	
	glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(900,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rotating Triangle");
	glutSpecialFunc(keypress);
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
