#include <GL/glut.h>

void display(){
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot( 0.3 );
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char *argv[])///��138��,main()�禡
{
    glutInit(&argc, argv);///��140��,�}��GLUT�\��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143��,�]�w��ܼҦ�
    glutCreateWindow("2024�q���Ͼǲ�01�g");///145��A�}�@��GLUT����
    glutDisplayFunc(display);
    glutMainLoop();///174��,�D�n���j��,�b�o�̤@���B�@
}