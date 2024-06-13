///���� week08-1_glm_gundam ���{���K�W��
///���@�U, �n�A�[�K�Ϫ� 18��{��
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * righthand1 = NULL;
GLMmodel * righthand2 = NULL;
GLMmodel * righthand3 = NULL;
GLMmodel * righthand4 = NULL;
GLMmodel * lefthand1 = NULL;
GLMmodel * lefthand2 = NULL;
GLMmodel * lefthand3 = NULL;
GLMmodel * lefthand4 = NULL;
GLMmodel * head1 = NULL;
GLMmodel * head2 = NULL;
GLMmodel * body = NULL;
GLMmodel * rightleg1 = NULL;
GLMmodel * rightleg2 = NULL;
GLMmodel * rightleg3 = NULL;
GLMmodel * rightleg4 = NULL;
GLMmodel * leftleg1 = NULL;
GLMmodel * leftleg2 = NULL;
GLMmodel * leftleg3 = NULL;
GLMmodel * leftleg4 = NULL;


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

void drawrighthand1(void)
{
    if (!righthand1) {
	righthand1 = glmReadOBJ("data/righthand1.obj");
	if (!righthand1) exit(0);
	glmUnitize(righthand1);
	glmFacetNormals(righthand1);
	glmVertexNormals(righthand1, 90.0);
    }

    glmDraw(righthand1, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrighthand2(void)
{
    if (!righthand2) {
	righthand2 = glmReadOBJ("data/righthand2.obj");
	if (!righthand2) exit(0);
	glmUnitize(righthand2);
	glmFacetNormals(righthand2);
	glmVertexNormals(righthand2, 90.0);
    }

    glmDraw(righthand2, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrighthand3(void)
{
    if (!righthand3) {
	righthand3 = glmReadOBJ("data/righthand3.obj");
	if (!righthand3) exit(0);
	glmUnitize(righthand3);
	glmFacetNormals(righthand3);
	glmVertexNormals(righthand3, 90.0);
    }

    glmDraw(righthand3, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrighthand4(void)
{
    if (!righthand4) {
	righthand4 = glmReadOBJ("data/righthand4.obj");
	if (!righthand4) exit(0);
	glmUnitize(righthand4);
	glmFacetNormals(righthand4);
	glmVertexNormals(righthand4, 90.0);
    }

    glmDraw(righthand4, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlefthand1(void)
{
    if (!lefthand1) {
	lefthand1 = glmReadOBJ("data/lefthand1.obj");
	if (!lefthand1) exit(0);
	glmUnitize(lefthand1);
	glmFacetNormals(lefthand1);
	glmVertexNormals(lefthand1, 90.0);
    }

    glmDraw(lefthand1, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlefthand2(void)
{
    if (!lefthand2) {
	lefthand2 = glmReadOBJ("data/lefthand2.obj");
	if (!lefthand2) exit(0);
	glmUnitize(lefthand2);
	glmFacetNormals(lefthand2);
	glmVertexNormals(lefthand2, 90.0);
    }

    glmDraw(lefthand2, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlefthand3(void)
{
    if (!lefthand3) {
	lefthand3 = glmReadOBJ("data/lefthand3.obj");
	if (!lefthand3) exit(0);
	glmUnitize(lefthand3);
	glmFacetNormals(lefthand3);
	glmVertexNormals(lefthand3, 90.0);
    }

    glmDraw(lefthand3, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlefthand4(void)
{
    if (!lefthand4) {
	lefthand4 = glmReadOBJ("data/lefthand4.obj");
	if (!lefthand4) exit(0);
	glmUnitize(lefthand4);
	glmFacetNormals(lefthand4);
	glmVertexNormals(lefthand4, 90.0);
    }

    glmDraw(lefthand4, GLM_SMOOTH | GLM_TEXTURE);
}

void drawhead1(void)
{
    if (!head1) {
	head1 = glmReadOBJ("data/head1.obj");
	if (!head1) exit(0);
	glmUnitize(head1);
	glmFacetNormals(head1);
	glmVertexNormals(head1, 90.0);
    }

    glmDraw(head1, GLM_SMOOTH | GLM_TEXTURE);
}

void drawhead2(void)
{
    if (!head2) {
	head2 = glmReadOBJ("data/head2.obj");
	if (!head2) exit(0);
	glmUnitize(head2);
	glmFacetNormals(head2);
	glmVertexNormals(head2, 90.0);
    }

    glmDraw(head2, GLM_SMOOTH | GLM_TEXTURE);
}



void drawrightleg1(void)
{
    if (!rightleg1) {
	rightleg1 = glmReadOBJ("data/rightleg1.obj");
	if (!rightleg1) exit(0);
	glmUnitize(rightleg1);
	glmFacetNormals(rightleg1);
	glmVertexNormals(rightleg1, 90.0);
    }

    glmDraw(rightleg1, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightleg2(void)
{
    if (!rightleg2) {
	rightleg2 = glmReadOBJ("data/rightleg2.obj");
	if (!rightleg2) exit(0);
	glmUnitize(rightleg2);
	glmFacetNormals(rightleg2);
	glmVertexNormals(rightleg2, 90.0);
    }

    glmDraw(rightleg2, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightleg3(void)
{
    if (!rightleg3) {
	rightleg3 = glmReadOBJ("data/rightleg3.obj");
	if (!rightleg3) exit(0);
	glmUnitize(rightleg3);
	glmFacetNormals(rightleg3);
	glmVertexNormals(rightleg3, 90.0);
    }

    glmDraw(rightleg3, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightleg4(void)
{
    if (!rightleg4) {
	rightleg4 = glmReadOBJ("data/rightleg4.obj");
	if (!rightleg4) exit(0);
	glmUnitize(rightleg4);
	glmFacetNormals(rightleg4);
	glmVertexNormals(rightleg4, 90.0);
    }

    glmDraw(rightleg4, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftleg1(void)
{
    if (!leftleg1) {
	leftleg1 = glmReadOBJ("data/leftleg1.obj");
	if (!leftleg1) exit(0);
	glmUnitize(leftleg1);
	glmFacetNormals(leftleg1);
	glmVertexNormals(leftleg1, 90.0);
    }

    glmDraw(leftleg1, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftleg2(void)
{
    if (!leftleg2) {
	leftleg2 = glmReadOBJ("data/leftleg2.obj");
	if (!leftleg2) exit(0);
	glmUnitize(leftleg2);
	glmFacetNormals(leftleg2);
	glmVertexNormals(leftleg2, 90.0);
    }

    glmDraw(leftleg2, GLM_SMOOTH | GLM_TEXTURE);
}
void drawleftleg3(void)
{
    if (!leftleg3) {
	leftleg3 = glmReadOBJ("data/leftleg3.obj");
	if (!leftleg3) exit(0);
	glmUnitize(leftleg3);
	glmFacetNormals(leftleg3);
	glmVertexNormals(leftleg3, 90.0);
    }

    glmDraw(leftleg3, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftleg4(void)
{
    if (!leftleg4) {
	leftleg4 = glmReadOBJ("data/leftleg4.obj");
	if (!leftleg4) exit(0);
	glmUnitize(leftleg4);
	glmFacetNormals(leftleg4);
	glmVertexNormals(leftleg4, 90.0);
    }

    glmDraw(leftleg4, GLM_SMOOTH | GLM_TEXTURE);
}


void myBody(){ ///�ڪ�����
    glPushMatrix();///�Ƥ��x�}
        glColor3f(1,0,0);///���⪺
        glutSolidCube(0.6);///mybody  ���O�Ť��ܹ��solid�~�ॿ�T��
    glPopMatrix();///�٭�x�}
}
///float angle = 0,da=1;///�[�o��, �������
/// angle[20] = {};///20�Ө���,���]��0
float angleX[10] = {},angleY[10] = {};///
int angleID = 0; ///�i�H�O����0,����1,����2
int oldx=0,oldy=0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x,int y){ ///�[�J mouse motion �������禡
     angleX[angleID] += y - oldy;///angleX��Y
     angleY[angleID] -= x - oldx;///angleY��X
    oldx = x;
    oldy = y;
    glutPostRedisplay();
    ///���� motion()�̪��s�ɪ��{���X�A�ŤU�ӡA�K�� keyboard()



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
           for(int i=0; i<10; i++){///�w��20�����`
                oldAngleX[i] = newAngleX[i];
                oldAngleY[i] = newAngleY[i];
                fscanf(fin, "%f",&newAngleX[i]);
                fscanf(fin, "%f",&newAngleY[i]);
           }
    }

    float alpha = (t%20) / 20.0;
    for(int i=0; i<10; i++){///�w��20�����`
        angleX[i] = newAngleX[i]*alpha + oldAngleX[i]*(1-alpha);
       angleY[i] = newAngleY[i]*alpha + oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y){
    if(key=='p'){///play����
        glutTimerFunc(0,timer,0);
    }
    if(key == 'r'){
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0; i<10; i++){

            fscanf(fin,"%f",&angleX[i]);
            fscanf(fin,"%f",&angleY[i]);
        }
        glutPostRedisplay();
    }else if(key=='s'){///��S�|�s��
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

      glPushMatrix();
        glRotatef(angleX[0],1,0,0);
         glRotatef(angleY[0],0,1,0);
        glRotatef(180,0,1,0);///�ন����
        drawbody();///�e����
      glPopMatrix();
    glColor3f(1,1,1);


    glutSwapBuffers();///(0)


}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///�[�o��, �������

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
    glutIdleFunc(display); ///�[�o��, �������
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);


    ///myTexture("data/Diffuse.jpg");

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
