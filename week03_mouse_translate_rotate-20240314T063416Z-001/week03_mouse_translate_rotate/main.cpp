
#include <GL/glut.h>
#include <stdio.h>

float teapotX=0, teapotY = 0;
float angle =0 ;
int method =1;///1轉動,2移動
int oldX=0,oldY=0;///舊的座標
void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}
void display()
{
    ///清除座標
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY,0);
        glRotatef(angle,0,0,1);///對Z軸轉
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y){
        if(method==1){///轉動angle
            angle+=x-oldX;
    }else if(method==2){
        teapotX +=(x-oldX)/150.0;
        teapotY -=(y-oldY)/150.0;
    }
    oldX=x;
    oldY=y;
    display();///呼叫12行的display
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='e') method=1;///移動
    if(key=='w') method=2;///移動
}
int main(int argc, char *argv[])///第138行,main()函式
{
    glutInit(&argc, argv);///第140行,開啟GLUT功能
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143行,設定顯示模式
    glutCreateWindow("week03 mouse");///145行，開一個GLUT視窗
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///註冊mouse函式
    glutMotionFunc(motion);///motion的細節，滑鼠的移動
    glutKeyboardFunc(keyboard);///按鍵
    glutMainLoop();///174行,主要的迴圈,在這裡一直運作
}
