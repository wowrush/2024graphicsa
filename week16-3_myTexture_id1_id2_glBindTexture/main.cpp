///week05_rotating_earth 專�?
/// ??week05_opencv_opengl_myTexture 程�??��???
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比�?簡單, ?��???High GUI ?�可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad = NULL; ///todo: 要�?一顆�?�?
int id1,id2;///�n�ǳƨ�ӼơA�ΨӦs�K��
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀??
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色�?(?�要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. ?��?貼�??�能
    GLuint id; ///準�?一??unsigned int ?�數, ??貼�?ID
    glGenTextures(1, &id); /// ?��?Generate 貼�?ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁�?bind 貼�?ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼�??�數, 超�??��??��??�T, 就�?覆貼??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼�??�數, 超�??��??��??�S, 就�?覆貼??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼�??�數, ?�大?��??��?, ?��?近�?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼�??�數, 縮�??��??��?, ?��?近�?
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
///?�貼�?0行GLUT程�? (不�?貼�??��?程�?)
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glBindTexture(GL_TEXTURE_2D,id2);///�R�x�I��
    glBegin(GL_POLYGON);
        glTexCoord2f(0,0); glVertex2f(-1,+1);
        glTexCoord2f(0,1); glVertex2f(-1,-1);
        glTexCoord2f(1,1); glVertex2f(+1,-1);
        glTexCoord2f(1,0); glVertex2f(+1,+1);
    glEnd();
    glBindTexture(GL_TEXTURE_2D,id1);///�a�y
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glRotatef(angle++, 0, 0, 1);
        gluSphere(quad, 0.5, 30, 30); ///glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week05");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    id2=myTexture("c:/images.jpg");
    id1=myTexture("c:/earth.jpg");
    quad = gluNewQuadric(); ///todo:?�這�??��?,?�好
    gluQuadricTexture(quad, 1);///todo: ?�好?��??�貼??
    glutMainLoop();
}
