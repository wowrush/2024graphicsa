#include <GL/glut.h>
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
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();///�ڪ�����
	myArm();///�ڪ����u




	glutSwapBuffers();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10 Microsoft Visual Studio");
	glutDisplayFunc(display);
	glutMainLoop();
}