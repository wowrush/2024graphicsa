#include <GL/glut.h>
#include <stdio.h>

void mouse(int button, int state, int x, int y)
{
    ///printf("Hello Mouse!\n");
    ///printf("%d %d %d %d\n",button,state,x,y);
    if(state==GLUT_DOWN)
            printf("glVertex2f((%d-150)/150.0,-(%d-150)/150.0);\n",x,y);
}
void display()
{
    glutSolidTeapot( 0.3 );
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

