
#include <GL/glut.h>
#include <stdio.h>

float teapotX=0, teapotY = 0;
void mouse(int button, int state, int x, int y)
{
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;
}
void display()
{
    ///清除座標
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])///第138行,main()函式
{
    glutInit(&argc, argv);///第140行,開啟GLUT功能
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143行,設定顯示模式
    glutCreateWindow("week03 mouse");///145行，開一個GLUT視窗
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///註冊mouse函式
    glutMainLoop();///174行,主要的迴圈,在這裡一直運作
}
