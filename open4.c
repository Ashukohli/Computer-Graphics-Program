#include"GL/freeglut.h"
#include"GL/gl.h"

void drawShape(){
	glClearColor(0.3,0.4,0.5,0.6);
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(15,0.0,0.0,1.0);
	glColor3f(0.0,1.0,1.0);
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0,1,0);
	glVertex3f(0.7,0.7,0.0);
	glVertex3f(0,-1,0);
	glVertex3f(-0.7,-0.7,0);
	glVertex3f(0,1,0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(900,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Line Strip");
	glutDisplayFunc(drawShape);
	glutMainLoop();
	
	return 0;
}
