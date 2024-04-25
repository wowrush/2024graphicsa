#include <GL/glut.h>
#include <mmsystem.h>
void myBody(){

	glPushMatrix();
        glColor3f(1,0,0);
        glutWireCube(0.6);///myboby()
    glPopMatrix();
}
void myArm(){
    glPushMatrix();
        glColor3f(0,1,0);
        glScalef(1,0.4,0.4);
        glutWireCube(0.3);///myboby()
    glPopMatrix();
}
float angle = 0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();///我的身體
	glPushMatrix();
        glTranslatef(0.3,0.3,0);///掛到肩上
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(0.15,0,0);///(右移)把旋轉中心，放在畫面中心
	myArm();///我的手臂
        glPushMatrix();
            glTranslatef(0.15,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.15,0,0);
            myArm();
            glPopMatrix();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(-0.3,0.3,0);///掛到肩上
        glRotatef(-angle,0,0,1);///旋轉
        glTranslatef(-0.15,0,0);///(右移)把旋轉中心，放在畫面中心
	myArm();///我的手臂
        glPushMatrix();
            glTranslatef(-0.15,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.15,0,0);
            myArm();
            glPopMatrix();
	glPopMatrix();



	glutSwapBuffers();
}
void motion(int x,int y){
    angle = x;///加上 mouse motion
    glutPostRedisplay();///告訴GLUT，貼上便利貼，問GLUT有空時，就要重劃畫面
}
int main(int argc, char*argv[])
{
    PlaySound("C:/horse.wav",NULL, SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10 Microsoft Visual Studio");
	glutDisplayFunc(display);
	glutMotionFunc(motion);///week10-7加上mouse motion
	glutIdleFunc(display);
	glutMainLoop();
}
