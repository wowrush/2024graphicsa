///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * handa = NULL;
GLMmodel * handb = NULL;
void drawHanda(void)
{
    if (!handa) {
	handa = glmReadOBJ("data/handa.obj");
	if (!handa) exit(0);
	glmUnitize(handa);
	glmFacetNormals(handa);
	glmVertexNormals(handa, 90.0);
    }

    glmDraw(handa, GLM_SMOOTH | GLM_TEXTURE);
}
void drawHandb(void)
{
    if (!handb) {
	handa = glmReadOBJ("data/handb.obj");
	if (!handb) exit(0);
	glmUnitize(handb);
	glmFacetNormals(handb);
	glmVertexNormals(handb, 90.0);
    }

    glmDraw(handb, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody(){ ///我的身體
    glPushMatrix();///備分矩陣
        glColor3f(1,0,0);///紅色的
        glutSolidCube(0.6);///mybody  但是空心變實心solid才能正確打
    glPopMatrix();///還原矩陣
}
float angle = 0; ///加這行, 讓它轉動
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      glDisable(GL_TEXTURE_2D);///把貼圖先功能關掉，不然手會被擋住
      myBody();
      glutSolidSphere(0.1,30,30);
    glEnable(GL_TEXTURE_2D);///再把貼圖功能開起來，才能draw
    glColor3f(1,1,1);
    glPushMatrix(); ///加這行, 讓它轉動
        glTranslatef(0.3,0.3,0);
        glRotatef(angle++,0,0,1);
        glTranslatef(0.15,-0.3,0);
        drawHanda(); //glutSolidTeapot( 0.3 );
    glPopMatrix(); ///加這行, 讓它轉動

    glPushMatrix(); ///加這行, 讓它轉動
        glTranslatef(-0.3,0.3,0);
        glRotatef(angle++,0,0,-1);
        glTranslatef(0.15,-0.3,0);
        drawHanda(); //glutSolidTeapot( 0.3 );
    glPopMatrix(); ///加這行, 讓它轉動
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week08 Gundam");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動

    myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
