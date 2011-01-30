
#include "stdafx.h"
#include "iostream"
#include "glut.h"




using namespace std;


void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 0.0, 0.0);


   glBegin(GL_LINES);
      glVertex2i(100, 150);
      glVertex2i(200,300);
   glEnd();

   glFlush ();
  //glutPostRedisplay();
}

void init (void)
{


   glClearColor (0.0, 0.0, 0.0, 0.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
  gluOrtho2D( 0,500,0,500);


}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Hello");
   init ();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}

