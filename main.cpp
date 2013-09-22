#include <GL/glut.h>
#include <iostream>
using namespace std;

int width = 800;
int height = 600;

int rotatex = 0;
int rotatey = 0;

void keyboard(unsigned char c, int x, int y)
{

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW );
    glLoadIdentity();

    glRotated(rotatex, 0, 1, 0);
    cout<<"rotatex: "<<rotatex<<endl;

    glBegin(GL_TRIANGLES);
    glVertex3f(-1, 0 , -2);
    glVertex3f(1, 0, -2);
    glVertex3f(0, 1, -2);
    glEnd();


    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport( 0, 0, w, h);
    gluPerspective(90, w/h, 1, 100);

}

void update_orientation(int x, int y)
{
    // Mouse changed in x or y direction;
    if(x != width/2 || y != height/2)
    {
       rotatex += ((x - width/2))/2  ;
       rotatex = rotatex % 360;
        
    }
    // No rotation
    else{
        rotatex += 0;
        rotatey += 0;
    }
    glutWarpPointer(width/2, height/2);
}


int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(width,height);
    glutCreateWindow("First person Controller Test");
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(update_orientation);
    glutMainLoop();
    
    return 0;
}

