#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159265
#define SPEED 0.25

int width = 800;
int height = 600;

int rotatex = 0;
int rotatey = 0;

double forwz = -6;
double forwx = 0;

// Key holds
bool w = false;
bool s = false;
bool d = false;
bool a = false;

void handle_pressed_keys()
{
	if(w)
	{
		forwz += cos(rotatex * PI/180.0) * SPEED;
		forwx += -sin(rotatex * PI/180.0) * SPEED;
	}
	if(s)
	{
		forwz -= cos(rotatex * PI/180.0) * SPEED;
		forwx -= -sin(rotatex * PI/180.0) * SPEED;
	}

	if(d)
	{
		forwx -= cos(rotatex * PI/180.0) * SPEED;
		forwz += -sin(rotatex * PI/180.0) * SPEED;
	}

	if(a)
	{
		forwx += cos(rotatex * PI/180.0) * SPEED;
		forwz -= -sin(rotatex * PI/180.0) * SPEED;
	}
}

void keyboardDown(unsigned char c, int x, int y)
{
	handle_pressed_keys();
    if(c == 'w' && w == false )
    {
		forwz += cos(rotatex * PI/180.0) * SPEED;
		forwx += -sin(rotatex * PI/180.0) * SPEED;
		w = true;
    }

    if(c == 's' && s == false )
    {
		forwz -= cos(rotatex * PI/180.0) * SPEED;
		forwx -= -sin(rotatex * PI/180.0) * SPEED;
		s = true;
    }
	if(c == 'd' && d == false )
    {
		forwx -= cos(rotatex * PI/180.0) * SPEED;
		forwz += -sin(rotatex * PI/180.0) * SPEED;
		d = true;
    }

	if(c == 'a' && a == false )
    {
	
		forwx += cos(rotatex * PI/180.0) * SPEED;
		forwz -= -sin(rotatex * PI/180.0) * SPEED;
		a = true;
    }


	if(c == 'q')
	{
		exit(0);
	}

}

void keyboardUp(unsigned char c, int x, int y)
{
	if(c == 'w')
	{
		w = false;
	}
	if(c == 's')
	{
		s = false;
	}
	if(c == 'd')
	{
		d = false;
	}
	if(c == 'a')
	{
		a = false;
	}

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW );
    glLoadIdentity();


	//Determine the rotation


	// Translate to the right angle
	glRotated(rotatey, 1, 0, 0);
	glRotated(rotatex, 0, 1, 0);
    glTranslated(forwx, 0, forwz);

	// Draw a triangle for position reference
    glBegin(GL_TRIANGLES);
    glVertex3f(-1, 0, -2);
    glVertex3f(1, 0, -2);
    glVertex3f(0, 1, -2);
    glEnd();

	// Draw a square on which we stand
    glBegin(GL_QUADS);
    glVertex3f(-4,-3, -4);
    glVertex3f(4, -3, -4);
    glVertex3f(4, -3, 4);
    glVertex3f(-4, -3, 4);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport( 0, 0, w, h);
    gluPerspective(70, w/h, 0, 100);
}

void update_orientation(int x, int y)
{
    // Mouse changed in x or y direction;
   rotatex += ((x - width/2))  ;
   rotatex = rotatex % 360;

   
   // In case of y
   rotatey += ((y - height/2))  ;
   if(rotatey > 50){
       rotatey = 50;
   }
   if(rotatey < -50)
   {
       rotatey = -50;
   }

   glutWarpPointer(width/2, height/2);
   glFlush();
   display();
}


int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(width,height);
    glutCreateWindow("First person Controller Test");

    glutSetCursor(GLUT_CURSOR_NONE);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp); 
    glutPassiveMotionFunc(update_orientation);
    glutMainLoop();
    
    return 0;
}

