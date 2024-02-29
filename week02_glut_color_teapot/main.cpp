#include <GL/glut.h>

void display(){
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot( 0.3 );
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char *argv[])///第138行,main()函式
{
    glutInit(&argc, argv);///第140行,開啟GLUT功能
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143行,設定顯示模式
    glutCreateWindow("2024電腦圖學第01週");///145行，開一個GLUT視窗
    glutDisplayFunc(display);
    glutMainLoop();///174行,主要的迴圈,在這裡一直運作
}
