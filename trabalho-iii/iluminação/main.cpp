#include <GL/freeglut.h>

void inicializar(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    float global_ambiente[] = {0.6, 0.6, 0.6, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambiente);

    gluLookAt(2.0,2.0,2.0,
              0.0,0.0,0.0,
              0.0,1.0,0.0);
}

void transformar()
{
    glTranslatef(1.5,0.0,0.0);
    glRotatef(90.0,0.0,0.0,1.0);
    glScalef(0.90,0.90,0.90);
}

void desenhar_cubo()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();

    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
}

void renderizar()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-2.0,2.0,-2.0,2.0,0.0,3.0);
    gluPerspective(90.0, 1.0, 1.0, 4.0);
    //transformar();
    desenhar_cubo();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Exemplo Cubo 3D");
    glutDisplayFunc(renderizar);
    inicializar();
    glutMainLoop();
    return 0;
}
