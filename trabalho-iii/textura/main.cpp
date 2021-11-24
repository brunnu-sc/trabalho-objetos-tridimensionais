#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "BmpLoader.h"
#include <iostream>

using namespace std;

unsigned int ID;
void desenhar_cubo();
void renderizar(int, int);

void inicializar()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void carregar_textura(const char*filename)
{
    BmpLoader bl(filename);
    glGenTextures(1,&ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData);
}

void transformar()
{
    glTranslatef(1.5,1.5,0.0);
    glRotatef(300.0,0.0,0.0,1.0);
    glScalef(0.90,0.90,0.90);
}

void desenhar_cubo()
{
    glEnable(GL_TEXTURE_2D);
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0.0,0.0,-6.0);
    glRotatef(0,1.0,2.0,0.0);
    for(int i=0;i<6;i++)
    {
        glPushMatrix();
        if(i==1)
        {
            glTranslatef(1.0,0.0,0.0);
            glRotatef(90,0.0,1.0,0.0);
            glTranslatef(1.0,0.0,0.0);
        }
        else if(i==2)
        {
            glTranslatef(0.0,0.0,-2.0);
            glRotatef(180.0,0.0,1.0,0.0);
        }
        else if(i==3)
        {
            glTranslatef(-1.0,0.0,0.0);
            glRotatef(-90.0,0.0,1.0,0.0);
            glTranslatef(-1.0,0.0,0.0);
        }
        else if(i==4)
        {
            glTranslatef(0.0,1.0,0.0);
            glRotatef(-90.0,1.0,0.0,0.0);
            glTranslatef(0.0,1.0,0.0);
        }
        else if(i==5)
        {
            glTranslatef(0.0,-1.0,0.0);
            glRotatef(90.0,1.0,0.0,0.0);
            glTranslatef(0.0,-1.0,0.0);
        }
        glBegin(GL_QUADS);
            glTexCoord2f(1.0,1.0);  glVertex3f(1.0,1.0,0.0);
            glTexCoord2f(0.0,1.0);  glVertex3f(-1.0,1.0,0.0);
            glTexCoord2f(0.0,0.0);  glVertex3f(-1.0,-1.0,0.0);
            glTexCoord2f(1.0,0.0);  glVertex3f(1.0,-1.0,0.0);
        glEnd();

        glPopMatrix();
    }
    glutSwapBuffers();
    glDisable(GL_TEXTURE_2D);
}

void renderizar(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,50.0);
    transformar();
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Exemplo Cubo 3D");
    carregar_textura("imagem-1.bmp");
    glutDisplayFunc(desenhar_cubo);
    glutReshapeFunc(renderizar);
    inicializar();
    glutMainLoop();
    return 0;
}
