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
int main(int argc, char *argv[])///��138��,main()�禡
{
    glutInit(&argc, argv);///��140��,�}��GLUT�\��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143��,�]�w��ܼҦ�
    glutCreateWindow("week03 mouse");///145��A�}�@��GLUT����
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///���Umouse�禡
    glutMainLoop();///174��,�D�n���j��,�b�o�̤@���B�@
}

