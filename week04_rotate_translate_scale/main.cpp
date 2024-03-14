#include <GL/glut.h>
#include <stdio.h>
float angle=0,oldX=0;
void display()
{
    glClearColor(1.0,1.0,0.9,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();

        glRotatef(angle++,0,0,1);///轉動中的
        glTranslatef(0.7,0,0);///放到右邊去
        glColor3f(0,1,1);
        glutSolidTeapot(0.3);
        glPopMatrix();
    glutSwapBuffers();
}

int main(int argc,char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 translate rotate scale");
    glutDisplayFunc(display);
    glutIdleFunc(display);///有空就重製畫面
    glutMainLoop();
}
