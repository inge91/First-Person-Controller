#include <GL/glut.h>
#include <iostream>
using namespace std;

int width = 800;
int height = 600;

int rotatex = 180;
int rotatey = 0;

double forward = 0;

void keyboard(unsigned char c, int x, int y)
{
    if(c == 'w' )
    {
        forward += 0.5;
    
    }

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW );
    glLoadIdentity();

    glRotated(rotatey, 1, 0, 0);
    glTranslated(0, 0, forward);
    glRotated(rotatex, 0, 1, 0);
    

    glBegin(GL_TRIANGLES);
    glVertex3f(-1, 0, -2);
    glVertex3f(1, 0, -2);
    glVertex3f(0, 1, -2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-4,-4, -4);
    glVertex3f(4, -4, -4);
    glVertex3f(4, -4, 4);
    glVertex3f(-4, -4, 4);
    glEnd();




    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport( 0, 0, w, h);
    gluPerspective(90, w/h, 0, 100);
}

void update_orientation(int x, int y)
{
    // Mouse changed in x or y direction;
   rotatex += ((x - width/2))/4  ;
   rotatex = rotatex % 360;

   
   // In case of y
   rotatey += ((y - height/2))/4  ;
   if(rotatey > 50){
       rotatey = 50;
   }
   if(rotatey < -50)
   {
       rotatey = -50;
   }

   glutWarpPointer(width/2, height/2);
   glFlush();
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
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(update_orientation);
    glutMainLoop();
    
    return 0;
}

