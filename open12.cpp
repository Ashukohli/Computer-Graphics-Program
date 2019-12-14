#include "GL/freeglut.h"
#include "GL/gl.h"
#include<math.h>

void drawTriangle(){
glClearColor(1,1,1,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1.0,0);
glBegin(GL_LINES);
glVertex2f(0,-1);
glVertex2f(0,1);
glVertex2f(-1,0);
glVertex2f(1,0);
glEnd();
glColor3f(0.0,0.0,0.0);
GLubyte y[7]={"Y-AXIS"};
GLubyte x[7]={"X-AXIS"};
for(int k=0;k<6; k++){
glRasterPos2f(0.05+k*0.05,0.95);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,y[k]);
}
glPointSize(4.0);
glColor3f(1.0,0.0,0);
glBegin(GL_POINTS);
   for(float i=0;i<=3.14*2;i+=0.005)
   glVertex2f(i/(3.14*2)-0.5,sin(i));
   glEnd();
  glFlush();
}


int main(int argc, char **argv){
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(600,600);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Create Sine curve");
 glutDisplayFunc(drawTriangle);
 glutMainLoop();
 return 0;
}

