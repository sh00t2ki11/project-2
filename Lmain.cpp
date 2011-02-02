
#include "iostream"

#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glext.h"


//wooden bars
void woodenBar(void){


//grass
   GLfloat c=0.0;
   int temp=-2;
   for(GLint y=235;y<350;y=y+3)
   {
   temp=temp+1;
   for(GLint x=temp;x<997;x=x+1){
   c=c+0.3;
   if(c>1.0 | c==0)   c=0.2;
   glColor3f(0.0,c,0.0);
   glBegin(GL_POLYGON);
   	glVertex2i(x,y);
   	glVertex2i(x+1,y+1);
   	glVertex2i(x+2,y+2);
   	glVertex2i(x+3,y+3);
   	glVertex2i(x+4,y+5);
   	glVertex2i(x+5,y+6);
   	glVertex2i(x+6,y+7);
   glEnd();
   }
   }
   
//horizontal bars
   glColor3f (0.6, 0.4, 0.2);

   for(GLint hor=300;hor>239;hor=hor-12){
   glBegin(GL_POLYGON);
	glVertex2i(2, hor);
	glVertex2i(1000,hor);
	glVertex2i(1000,hor+3);
	glVertex2i(2,hor+3);
   glEnd();
   }
   
//vertical bars
   glColor3f (0.4, 0.3, 0.2);
   for(GLint ver=5;ver<1000;ver=ver+10){
   glBegin(GL_POLYGON);
   	glVertex2i(ver,308);
   	glVertex2i(ver+2,308);
   	glVertex2i(ver+2,235);
   	glVertex2i(ver,235);
   glEnd();
   }
}



void windows(void){
	//multiple windows
	glColor3f(0.4,0.5,0.6);
	for(GLint i=0;i<18;i++){
		for(GLint j=0;j<5;j++){
		glPushMatrix();
			glTranslatef(9.0*j,-16.0*i,0);
			glBegin(GL_POLYGON);
				glVertex2i(104,530);
				glVertex2i(104,520);
				glVertex2i(110,520);
				glVertex2i(110,530);
			glEnd();
		glPopMatrix();
		
		}
	
	}
	glColor3f(0.6,0.7,0.8);
	for(GLint i=0;i<18;i++){
		for(GLint j=0;j<3;j++){
		glPushMatrix();
			glTranslatef(4*j,-16*i,0);
			glBegin(GL_POLYGON);
				glVertex2i(153,533-j);
				glVertex2i(153,523-j);
				glVertex2i(156,520-j);
				glVertex2i(156,530-j);
			glEnd();
			
		glPopMatrix();
		
		}
	
	}
	
}


void building(void){
	
	glColor3f(0.3,0.4,0.4);
	glBegin(GL_POLYGON);
		glVertex2i(100,235);
		glVertex2i(100,535);
		glVertex2i(150,545);
		glVertex2i(150,235);
	glEnd();
	glColor3f(0.5,0.6,0.6);
	glBegin(GL_POLYGON);
		glVertex2i(150,545);
		glVertex2i(165,530);
		glVertex2i(165,235);
		glVertex2i(150,235);
	glEnd();
	windows();
	
}


void wall(void){

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(0,240);
		glVertex2i(40,350);
		glVertex2i(40,450);
		glVertex2i(0,340);
	glEnd();
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2i(40,350);
		glVertex2i(40,450);
		glVertex2i(1000,450);
		glVertex2i(1000,350);
	glEnd();
		
	



}


void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
   
      glPushMatrix();
   	glTranslatef(100.0,160,0.0);
   	glScalef(0.5,0.5,1.0);
   	building();
   glPopMatrix();
   
   glPushMatrix();
   	glTranslatef(0.0,160,0.0);
   	glScalef(0.5,0.5,1.0);
   	wall();
   	woodenBar();
   glPopMatrix();
   



   

   glFlush ();

}

void init (void)
{

   glClearColor (0.4, 0.6, 1.0, 0.0);
   //glClearColor (1.0, 1.0, 1.0, 0.0);
   

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
  gluOrtho2D( 0,500,0,500);


}







int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (1500,1000);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Hello");
   init ();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0; 
}

