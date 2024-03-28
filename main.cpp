void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///²M­I´º
    drawmovdel();
    glutSwapBuffers();
}
int main(int argc, char*argv[])
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 keyboard mouse motion");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
