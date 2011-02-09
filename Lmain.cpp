
#include "iostream"
#include <math.h>

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



void windows(float r, float g, float b){
	//multiple windows
	glColor3f(r,g,b);
	
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
	
	glColor3f(r+0.1,g+0.1,b+0.1);
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


void building(float r,float g,float b){
	
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
		glVertex2i(100,235);
		glVertex2i(100,535);
		glVertex2i(150,545);
		glVertex2i(150,235);
	glEnd();
	glColor3f(r+0.2,b+0.2,g+0.2);
	glBegin(GL_POLYGON);
		glVertex2i(150,545);
		glVertex2i(165,530);
		glVertex2i(165,235);
		glVertex2i(150,235);
	glEnd();
	windows(r+0.1,g,b+0.2);
	
}

void bricksLong(int a,int x,int b,int y){
	glColor3f(0.5,0.5,0.4);
	glBegin(GL_POLYGON);
	for(int i=1;i<10;i++){
		glVertex2i(rand()%a+x,rand()%b+y);
	//	glVertex2i(rand()%20+40,rand()%25+420);
	}
	glEnd();
}

void wall(void){

	glColor3f(0.2,0.3,0.4);
	glBegin(GL_POLYGON);
		glVertex2i(2,240);
		glVertex2i(40,350);
		glVertex2i(40,450);
		glVertex2i(2,340);
	glEnd();
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);

		glVertex2i(40,350);
		glVertex2i(40,450);
		glVertex2i(1000,450);
		glVertex2i(1000,350);
	glEnd();
		
	

for(int j=0;j<5;j++){
for(int i=0;i<50;i++){
glPushMatrix();
	glScalef(1.4,1,0.0);
	glTranslatef(20*i,-15*j,0);
	bricksLong(20,40,25,420);
glPopMatrix();
}
}


}


void sun(float r, float g, float b){
glColor3f(r,g,b);
GLfloat x,y;
int radius=10;
int num=20;
int x_centre=420, y_centre=240;
	glBegin(GL_POLYGON);
	for(int i=1;i<=num;i++){

		x = x_centre + radius *cos(i*2.0*3.14/num);
		y = y_centre + radius *sin(i*2.0*3.14/num);
		
		glVertex2f(x,y);
	}
	glEnd();
	
	for(int count=0;count<6;count++){
	glColor3f(1.0-count/15.0,1.0-count/15.0,1.0-count/15.0);
	glBegin(GL_LINE_LOOP);
	for(int i=1;i<=num;i++){

		x = x_centre + (radius+count) *cos(i*2.0*3.14/num);
		y = y_centre + (radius+count) *sin(i*2.0*3.14/num);
		
		glVertex2f(x,y);
	}
	glEnd();
	}

}


void road (void){

glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
	glVertex2i(0,238);
	glVertex2i(0,100);
	glVertex2i(1000,100);
	glVertex2i(1000,238);
glEnd();


glEnable(GL_LINE_STIPPLE);
glLineWidth(6);
glColor3f(0.9,0.9,0.9);
glLineStipple(7,0x00FF);
glBegin(GL_LINES);
	glVertex2i(0,170);
	glVertex2i(1000,170);
glEnd();

glDisable(GL_LINE_STIPPLE);
glLineWidth(1.5);

}

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
   
      glPushMatrix();
   	glTranslatef(100.0,220,0.0);
   	glScalef(0.4,0.4,1.0);
   	building(0.2,0.3,0.3);
   glPopMatrix();
   
   glPushMatrix();
   	glTranslatef(200.0,260.0,0.0);
   	glScalef(0.7,0.3,1.0);
   	building(0.1,0.3,0.3);
   glPopMatrix();
   
      glPushMatrix();
   	glTranslatef(255.0,260.0,0.0);
   	glScalef(0.5,0.2,1.0);
   	building(0.2,0.2,0.2);
   glPopMatrix();
   
   glPushMatrix();
   	glTranslatef(250.0,200.0,0.0);
   	glScalef(1.60,0.4,1.0);
   	building(0.2,0.3,0.3);
   glPopMatrix();
   
   glPushMatrix();
   	glTranslatef(0.0,120,0.0);
   	glScalef(0.5,0.5,1.0);
   	wall();
   	woodenBar();
   glPopMatrix();
   
   glPushMatrix();
   	glScalef(1.1,2.0,1.0);
	sun(0.9,0.9,0.5);
   glPopMatrix();
   
     road();

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

