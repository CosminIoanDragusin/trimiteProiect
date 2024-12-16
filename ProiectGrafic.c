/*
Programul afiseaza un patrat pe care il translateaza
pe axa x la apasarea sagetilor stanga, dreapta
*/
#include "glos.h"
#include <glaux.h>
#include <gl.h>
#include <glu.h>
#include <glaux.h>
#include<math.h>
#include<stdio.h>


void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK movelight(AUX_EVENTREC* event);

static GLfloat x = 0;
static GLfloat y = 0;
static GLfloat z = 0;
static GLfloat alfa = 27;

static int spin = 0;
static int spiny = 0;


void myinit(void) {

    
    GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    //componenta ambientala din sursa 0 este lumina cu intensitate 0
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    //componenta difuza din sursa 0 este lumina cu intensitate 1 
    //pentru fiecare componenta de culoare R, G, B
    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //componenta speculara din sursa 0 este lumina cu intensitate 1 
    //pentru fiecare componenta de culoare
    GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
    //sursa 0 este la infinit pe directia y=3, z=2
    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat local_view[] = { 0.0 };

    glEnable(GL_DEPTH_TEST);//activare test de adancime
    glDepthFunc(GL_LESS);//modelul de comparatie in testul de adancime

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

    glEnable(GL_LIGHTING);//activare iluminare
    glEnable(GL_LIGHT0);//activare sursa 0
    glEnable(GL_AUTO_NORMAL);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glClearColor(2.0, 2.0, 2.0, 2.0);
}

void CALLBACK movelight(AUX_EVENTREC* event)
{
    spin = (spin + 30) % 360;
}
void CALLBACK MutaStanga(void)
{
    x = x - 10;
}
void CALLBACK MutaDreapta(void)
{
    x = x + 10;
}
void CALLBACK display(void)
{
    GLfloat low_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat more_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat most_ambient[] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat matrice[] = { 1.0, 0.0, 1.0, 0.0 };
    GLfloat matrice2[] = { 0.0, 1.0, 1.0, 0.0 };
    GLfloat matrice3[] = { 1.0, 1.0, 1.0, 0.3 };
    GLfloat matrice4[] = { 0.3, 0.3, 0.3, 0.0 };
    GLfloat matrice5[] = { 0.1, 0.1, 1.0, 0.0 };//aici sunt
    GLfloat matrice6[] = { 1.0, 0.5, 0.0, 0.0 };
    GLfloat matrice7[] = { 0.0, 0.0, 1.0, 0.0 };
    GLfloat matrice8[] = { 1.0, 0.0, 1.0, 0.0 };
    GLfloat matrice9[] = { 0.0, 1.0, 1.0, 0.0 };
    GLfloat matrice10[] = { 0.0, 0.0, 0.0, 0.0 };
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };//coeficient de reflexie ambientala
    GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
    GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };//coeficient de reflexie difuza
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//coeficient de reflexie speculara
    GLfloat no_shininess[] = { 0.0 };//exponentul de reflexie speculara
    GLfloat low_shininess[] = { 25.0 };//exponentul de reflexie speculara
    GLfloat high_shininess[] = { 100.0 };//exponentul de reflexie speculara
    GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };//intensitatea luminii emise

    GLfloat position[] = { -90.0, -90.0, 0.0, 0.0 }; // pozitia susrei
    
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glLoadIdentity();

glTranslatef(0.0, 0.0, -5.0); // pozitia de observare

glPushMatrix();
glRotated((GLdouble)spin, 1.0, 0.0, 0.0);//rotatia sursei
glRotated(1.0, 0.0, 0.0, 0.0);
glLightfv(GL_LIGHT0, GL_POSITION, position); 	// functie apelata
// doar dupa ce s-a stabilit matricea de rotaie

// se deseneaza cubul corespunzând pozitiei sursei
glTranslated(280.0, 100.0,0.0);
//glDisable(GL_LIGHTING);
glColor3f(1.0, 1.0, 0.0);
auxWireSphere(40);
//glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix();
glBegin(GL_POLYGON);//statia1

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice2);
glMaterialfv(GL_FRONT, GL_DIFFUSE, low_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);


glVertex3f(-700, 80, 0);
glVertex3f(-700, 180, 0);
glVertex3f(-500, 180, 0);
glVertex3f(-500, 80, 0);


glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_TRIANGLES);//acoperis 1

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice4);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glVertex3f(-600, 250, 0);
glVertex3f(-700, 180, 0);
glVertex3f(-500, 180, 0);

glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//statia2

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice6);
glMaterialfv(GL_FRONT, GL_DIFFUSE, more_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glVertex3f(500, 80, 0);
glVertex3f(500, 180, 0);
glVertex3f(700, 180, 0);
glVertex3f(700, 80, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_TRIANGLES);//acoperis2

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice9);
glMaterialfv(GL_FRONT, GL_DIFFUSE, most_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(600, 250, 0);
glVertex3f(700, 180, 0);
glVertex3f(500, 180, 0);

glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//linie

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice10);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-2000, 0, 0);
glVertex3f(-2000, -15, 0);
glVertex3f(+2000, -15, 0);
glVertex3f(+2000, 0, 0);
glEnd();
glPopMatrix();

//de aici se misca trenul
glTranslatef(x, 0.0, 0.0);

glPushMatrix();

glBegin(GL_POLYGON);//vagonul 1 bucata stanga

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice8);
glMaterialfv(GL_FRONT, GL_DIFFUSE, low_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glVertex3f(-550,0,0);
glVertex3f(-550,60,0);
glVertex3f(-520,60,0);
glVertex3f(-520,0,0);
glEnd();
glPopMatrix();

glPushMatrix();

glBegin(GL_POLYGON);//vagonul 1 bucata sus

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice8);
glMaterialfv(GL_FRONT, GL_DIFFUSE, low_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glVertex3f(-520, 50, 0);
glVertex3f(-520, 60, 0);
glVertex3f(-390, 60, 0);
glVertex3f(-390, 50, 0);
glEnd();
glPopMatrix();

glBegin(GL_POLYGON);//vagonul 1 bucata jos

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice8);
glMaterialfv(GL_FRONT, GL_DIFFUSE, low_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glVertex3f(-520, 20, 0);
glVertex3f(-520, 0, 0);
glVertex3f(-390, 0, 0);
glVertex3f(-390, 20, 0);
glEnd();
glPopMatrix();

glPushMatrix();

glBegin(GL_POLYGON);//vagonul 1 bucata dreapta

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice8);
glMaterialfv(GL_FRONT, GL_DIFFUSE, low_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glVertex3f(-390, 0, 0);
glVertex3f(-390, 60, 0);
glVertex3f(-360, 60, 0);
glVertex3f(-360, 0, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul1 geam 1

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice6);
glMaterialfv(GL_FRONT, GL_DIFFUSE, more_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glVertex3f(-520, 20, 0);
glVertex3f(-520, 50, 0);
glVertex3f(-390, 50, 0);
glVertex3f(-390, 20, 0);

glEnd();
glPopMatrix();



glPushMatrix();
glBegin(GL_LINES);//linile de legatura 1

glColor3f(1.0,0.0,0.0);

glVertex3f(-550, 0, 0);//linia1
glVertex3f(-570, 0, 0);

glVertex3f(-570, 0, 0);//linia2
glVertex3f(-570, 25, 0);

glVertex3f(-570, 25, 0);//linia3
glVertex3f(-550, 25, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul 2 bucata stanga

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice3);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-340, 60, 0);
glVertex3f(-340, 0, 0);
glVertex3f(-310, 0, 0);
glVertex3f(-310, 60, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul 2 bucata sus

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice3);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-310, 50, 0);
glVertex3f(-310, 60, 0);
glVertex3f(-200, 60, 0);
glVertex3f(-200, 50, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul 2 bucata jos

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice3);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-310, 0, 0);
glVertex3f(-310, 20, 0);
glVertex3f(-200, 20, 0);
glVertex3f(-200, 0, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul 2 bucata dreapta

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice3);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-200, 60, 0);
glVertex3f(-200, 0, 0);
glVertex3f(-170, 0, 0);
glVertex3f(-170, 60, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul2 geam 1

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice5); 
glMaterialfv(GL_FRONT, GL_DIFFUSE, more_ambient);
glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glColor3f(0.0, 0.0, 1.0);
glVertex3f(-320, 50, 0);
glVertex3f(-320, 20, 0);
glVertex3f(-170, 20, 0);
glVertex3f(-170, 50, 0);

glEnd();
glPopMatrix();


glPushMatrix();
glBegin(GL_LINES);//linia2

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice7);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-360, 0, 0);//linia1
glVertex3f(-340, 0, 0);

glVertex3f(-360, 15, 0);//linia2
glVertex3f(-340, 15, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul3 bucata mare

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice8);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-150, 60, 0);
glVertex3f(-20, 60, 0);
glVertex3f(-20, 0, 0);
glVertex3f(-150, 0, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);//vagonul3 bucata mica

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice8);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(20, 25, 0);
glVertex3f(-20, 25, 0);
glVertex3f(-20, 0, 0);
glVertex3f(20, 0, 0);
glEnd();
glPopMatrix();


glPushMatrix();
glBegin(GL_LINES);//linia3

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice10);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-170, 0, 0);//linia1
glVertex3f(-150, 0, 0);

glVertex3f(-170, 15, 0);//linia2
glVertex3f(-150, 15, 0);

glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_TRIANGLES);//geamul din fata

glMaterialfv(GL_FRONT, GL_AMBIENT, matrice9);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

glVertex3f(-20, 60, 0);
glVertex3f(-20, 25, 0);
glVertex3f(20, 25, 0);

glEnd();
glPopMatrix();

auxSwapBuffers();

}



void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-320.0, 320.0, 320.0 * (GLfloat)h / (GLfloat)w,
            -320.0 * (GLfloat)h / (GLfloat)w, -100.0, 100.0);
    else
        glOrtho(-320.0 * (GLfloat)w / (GLfloat)h,
            320.0 * (GLfloat)w / (GLfloat)h, -320.0, 320.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_DOUBLE | AUX_RGB);
    auxInitPosition(0, 0, 300, 400);
    auxInitWindow("Un patrat care se translateaza pe axa x");
    myinit();
    auxKeyFunc(AUX_LEFT, MutaStanga);
    auxKeyFunc(AUX_RIGHT, MutaDreapta);
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, movelight);// inregistreaza functia callback moveligh
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
