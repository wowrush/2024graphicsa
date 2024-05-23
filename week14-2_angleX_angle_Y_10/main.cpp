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
GLMmodel * upperA = NULL;
GLMmodel * lowerA = NULL;
GLMmodel * body = NULL;

void drawbody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}


void drawUpperA(void)
{
    if (!upperA) {
	upperA = glmReadOBJ("data/upperA.obj");
	if (!upperA) exit(0);
	glmUnitize(upperA);
	glmFacetNormals(upperA);
	glmVertexNormals(upperA, 90.0);
    }

    glmDraw(upperA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLowerA(void)
{
    if (!lowerA) {
	lowerA = glmReadOBJ("data/lowerA.obj");
	if (!lowerA) exit(0);
	glmUnitize(lowerA);
	glmFacetNormals(lowerA);
	glmVertexNormals(lowerA, 90.0);
    }

    glmDraw(lowerA, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody(){ ///我的身體
    glPushMatrix();///備分矩陣
        glColor3f(1,0,0);///紅色的
        glutSolidCube(0.6);///mybody  但是空心變實心solid才能正確打
    glPopMatrix();///還原矩陣
}
///float angle = 0,da=1;///加這行, 讓它轉動
/// angle[20] = {};///20個角度,都設成0
float angleX[10] = {},angleY[10] = {};///
int angleID = 0; ///可以是角度0,角度1,角度2
int oldx=0,oldy=0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x,int y){ ///加入 mouse motion 對應的函式
     angleX[angleID] += y - oldy;///angleX對Y
     angleY[angleID] -= x - oldx;///angleY對X
    oldx = x;
    oldy = y;
    glutPostRedisplay();
    ///把原來 motion()裡的存檔的程式碼，剪下來，貼到 keyboard()



}
void mouse(int button , int state, int x,int y){
    oldx=x;
    oldy=y;
}
float newAngleX[10]={},oldAngleX[10]={};
float newAngleY[10]={},oldAngleY[10]={};
void timer(int t){
    glutTimerFunc(50,timer,t+1);
    if(t%20==0){
           if(fin==NULL) fin = fopen("angle.txt","r");
           for(int i=0; i<10; i++){///針對20個關節
                oldAngleX[i] = newAngleX[i];
                oldAngleY[i] = newAngleY[i];
                fscanf(fin, "%f",&newAngleX[i]);
                fscanf(fin, "%f",&newAngleY[i]);
           }
    }

    float alpha = (t%20) / 20.0;
    for(int i=0; i<10; i++){///針對20個關節
        angleX[i] = newAngleX[i]*alpha + oldAngleX[i]*(1-alpha);
       angleY[i] = newAngleY[i]*alpha + oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y){
    if(key=='p'){///play播放
        glutTimerFunc(0,timer,0);
    }
    if(key == 'r'){
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0; i<10; i++){

            fscanf(fin,"%f",&angleX[i]);
            fscanf(fin,"%f",&angleY[i]);
        }
        glutPostRedisplay();
    }else if(key=='s'){///按S會存檔
        if(fout==NULL) fout = fopen("angle.txt","w+");
        for(int i=0; i<10; i++){
            ///printf("%.1f ",angle[i]);
            printf("%.1f ",angleX[i]);
            printf("%.1f ",angleY[i]);
            ///fprintf(fout,"%.1f ",angle[i]);
            fprintf(fout,"%.1f ",angleX[i]);
            fprintf(fout,"%.1f ",angleY[i]);
        }
    }
    if(key == '0') angleID = 0;
    if(key == '1') angleID = 1;
    if(key == '2') angleID = 2;
    if(key == '3') angleID = 3;
    if(key == '4') angleID = 4;
    if(key == '5') angleID = 5;
    if(key == '6') angleID = 6;
    if(key == '7') angleID = 7;
    if(key == '8') angleID = 8;
    if(key == '9') angleID = 9;



}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      ///glDisable(GL_TEXTURE_2D);///把貼圖先功能關掉，不然手會被擋住
      glPushMatrix();
        glRotatef(angleX[0],1,0,0);
         glRotatef(angleY[0],0,1,0);
        glRotatef(180,0,1,0);///轉成正面
        drawbody();///畫身體
      glPopMatrix();
    ///glutSolidSphere(0.1,30,30);
    ///glEnable(GL_TEXTURE_2D);///再把貼圖功能開起來，才能draw
    glColor3f(1,1,1);
	glPushMatrix();
        glTranslatef(-0.1,0,0);
		glRotatef(angleX[1],1,0,0);
		glRotatef(angleY[1],0,1,0);
		glTranslatef(0,-0.07,0);
        drawUpperA();///(3)上手臂放好
    	glPushMatrix(); ///(0)
        	glTranslatef(-0.02,-0.09,0);///(3)再掛到上手臂的位置
        	glRotatef(angleX[2],1,0,0);///(2) x軸轉
        	glRotatef(angleY[2],0,1,0);
        	glTranslatef(0,-0.21,0);///(1)
        	drawLowerA(); ///(0)
    	glPopMatrix(); ///(0)
    glPopMatrix();

    glutSwapBuffers();///(0)


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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);


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
