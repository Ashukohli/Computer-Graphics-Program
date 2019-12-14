#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
const int WINH= 500;
const int WINW=500;
float x_vert[4]={100.0,200.0,300.0,400.0};
float y_vert[4]={200,450,0,200};
class Point{
public:
static GLfloat getX(GLfloat x){
return (x-WINW/2)/(WINW/2);
}
static GLfloat getY(GLfloat y){
return (y-WINH/2)/(WINH/2);
}
};

void display(){
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.4,0.5,0.6,1.0);
glPointSize(4.0);
glBegin(GL_POINTS);
glColor3f(0.0,1.0,1.0);
Point p;
GLfloat xi0=p.getX(x_vert[0]);
GLfloat xi1=p.getX(x_vert[1]);
GLfloat xi2=p.getX(x_vert[2]);
GLfloat xi3=p.getX(x_vert[3]);
GLfloat yi0=p.getY(y_vert[0]);
GLfloat yi1=p.getY(y_vert[1]);
GLfloat yi2=p.getY(y_vert[2]);
GLfloat yi3=p.getY(y_vert[3]);
GLfloat xp,yp;
for(float i=0.0; i<=1.0;  i=i+0.001){
//printf("hello %d\n",i);
xp= i*i*i*xi0+3*i*i*xi1*(1-i)+3*(1-i)*(1-i)*i*xi2+(1-i)*(1-i)*(1-i)*xi3;
yp= i*i*i*yi0+3*i*i*yi1*(1-i)+3*(1-i)*(1-i)*i*yi2+(1-i)*(1-i)*(1-i)*yi3;
glVertex2f(xp,yp);
}
glEnd();
glFlush();
}

int main(int argc, char ** argv){
	
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(WINH,WINW);
glutInitWindowPosition(100,100);
glutCreateWindow("Create Bezier curve");
glutDisplayFunc(display);
glutMainLoop();

return 0;
}

