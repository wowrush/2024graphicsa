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

	myBody();///�ڪ�����
	glPushMatrix();
        glTranslatef(0.3,0.3,0);///����ӤW
        glRotatef(angle,0,0,1);///����
        glTranslatef(0.15,0,0);///(�k��)����त�ߡA��b�e������
	myArm();///�ڪ����u
        glPushMatrix();
            glTranslatef(0.15,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.15,0,0);
            myArm();
            glPopMatrix();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(-0.3,0.3,0);///����ӤW
        glRotatef(-angle,0,0,1);///����
        glTranslatef(-0.15,0,0);///(�k��)����त�ߡA��b�e������
	myArm();///�ڪ����u
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
    angle = x;///�[�W mouse motion
    glutPostRedisplay();///�i�DGLUT�A�K�W�K�Q�K�A��GLUT���ŮɡA�N�n�����e��
}
int main(int argc, char*argv[])
{
    PlaySound("C:/horse.wav",NULL, SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10 Microsoft Visual Studio");
	glutDisplayFunc(display);
	glutMotionFunc(motion);///week10-7�[�Wmouse motion
	glutIdleFunc(display);
	glutMainLoop();
}
