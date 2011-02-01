
/*
 * This is a simple, introductory OpenGL program.
 */

#include "iostream"

#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glext.h"


void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* set line colour red (r=1, g=0,b=0).
 */
   glColor3f (1.0, 0.0, 0.0);

/* draw a line from point (100,150) to point (200, 300).*/

   glBegin(GL_LINES);
      glVertex2i(100, 150);
	  glVertex2i(200,300);
   glEnd();

/* keep showing (flushing) line on the screen instead of showing just once.
 */
   glFlush ();
  // glutPostRedisplay();
}

void init (void)
{
/* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
  gluOrtho2D( 0,500,0,500);


}

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
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
   return 0;   /* ANSI C requires main to return int. */
}

