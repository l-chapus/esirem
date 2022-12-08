/*********************************************************/
/*                    openGL.cc                          */
/*********************************************************/
/*                                                       */
/*********************************************************/ 

/* inclusion des fichiers d'en-tete Glut */
#include <GL/freeglut.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
//#include <jpeglib.h>
//#include <jerror.h>
#define Pi 3.141592654

double Scal=36;

double trX=0.0,trY=0.0,dist=0.;//,trZ=0.0
char presse;
int anglex,angley,x,y,xold,yold;

/* Prototype des fonctions */
void affichage();//  procedure a modifier en fonction de la scene
void clavier(unsigned char touche,int x,int y); 
void reshape(int x,int y);
void idle();
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);

//-************************************************************
//
//  Procedure avec mise en file des sommets des primitives
//
//-***********************************************************
void init();

int main(int argc,char **argv)
{
  /* initialisation de glut et creation de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(700,700);
  glutCreateWindow("Projet 3A");
  /* Initialisation d'OpenGL */
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(0.0,0.0,0.0);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);


   glColor3f(0.0,0.0,0.0);
   //glEdgeFlag(GL_FALSE);
   glEdgeFlag(GL_TRUE);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
 // glEnable(GL_LIGHTING);
  glDisable(GL_LIGHTING);


  /* enregistrement des fonctions de rappel */
  init();
  glutDisplayFunc(affichage);
  glutKeyboardFunc(clavier);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);


  /* Entree dans la boucle principale glut */
  glutMainLoop();
  return 0;
}


void clavier(unsigned char touche,int x,int y)
{
  switch (touche)
    {
    case 'q' : /*la touche 'q' permet de quitter le programme */
        exit(0);
    case '+' :
      dist+=0.5;
      Scal=Scal+0.5;
      glutPostRedisplay();
      break;
    case '-' :
      dist-=0.5;
      Scal=Scal-0.5;
      glutPostRedisplay();
      break;
    case '6' : trX-=0.25;  glutPostRedisplay();  break;
    case '4' : trX+=0.25;  glutPostRedisplay();  break;
    case '8' : trY+=0.25;  glutPostRedisplay();  break;
    case '2' : trY-=0.25;  glutPostRedisplay();  break;
    }
}



void reshape(int x,int y)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //taille de la scene
  double  Ortho=-150;
  glOrtho(-Ortho,Ortho,-Ortho,Ortho,-Ortho,Ortho);// fenetre
  glMatrixMode(GL_MODELVIEW);
  glViewport(0,0,x,y);
}

void mouse(int button, int state,int x,int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    presse=0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x,int y)
  {
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      anglex=anglex+(x-xold); 
      angley=angley+(y-yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }
    
    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
  }



/****************************************************************
 **                                                            **
 **                    Affichage de  la scene                  **
 **                                                            **
 ****************************************************************/

void openGL(double x, double y, double r0,double g0, double b0, double size)
{
        glColor3f(r0,g0,b0);	//initialisation de la couleur
	glPointSize(size);	// initialisation de la taille
	glBegin(GL_POINTS);	// on trace un point
	  glVertex2f(x,y);	// coordonnees du point
	glEnd();	// fin de glBegin
}

void trace_segment(double x0, double y0,double x1, double y1, double red, double green, double blue, double size)
{
        glColor3f(red,green,blue);//initialisation de la couleur
	glLineWidth(size); // initialisation de la taille
	glBegin(GL_LINES); // on trace un segment
	  glVertex2f(x0,y0); // coordonnees du premier point
          glVertex2f(x1,y1); // coordonnees du dernier point 
	glEnd(); // fin de glBegin
}

	
//fonction ou les objets sont a definir

#include <vector>
#include <assert.h>

float factorielle(int n){
  assert (n>=0 && "Factorielle non défini.");
  float S=1.0;
  for(int k=1;k<(n+1);++k){
    S=S*k;
  }
  return S;
}
float k_parmi_n(int k,int n){
  assert (n>=k && k>=0 && "Coefficient binomial non défini.");
  float S=factorielle(n)/(factorielle(k)*factorielle(n-k));
  return S;
}
float coef_Bezier(int i,int n,float t){
  float S=0.0;
  S = k_parmi_n(i,n)*pow(t,i)*pow(1-t,n-i);
  return S;
}
void trace_init(std::vector<float> a ,std::vector<float> b){
  assert (a.size()==b.size() && "Taille des listes différentes");
  openGL(a.at(0),b.at(0),0.2,0.2,0.90,10.);
  openGL(a.at(1),b.at(1),0.2,0.2,0.90,10.);
  trace_segment(a.at(0),b.at(0),a.at(1),b.at(1),1.0,0.,0.,0.5);
  int fin=a.size();
  openGL(a.at(fin-1),b.at(fin-1),0.2,0.2,0.90,10.);
  openGL(a.at(fin-2),b.at(fin-2),0.2,0.2,0.90,10.);
  trace_segment(a.at(fin-1),b.at(fin-1),a.at(fin-2),b.at(fin-2),1.0,0.,0.,0.5);
}
void trace_courbe(std::vector<float> a ,std::vector<float> b){
  assert (a.size()==b.size() && "Taille des listes différentes");
  double t = 0.0;
  float m = 1001;
  float x0=a.at(0),y0=b.at(0),x1=0.0,y1=0.0;
  int n = a.size();
  for(int j=0;j<m;++j){
    x1=0.0;
    y1=0.0;
    t=j/m;
    for(int i=0;i<n;++i){
      x1=x1+coef_Bezier(i,n-1,t)*a.at(i);
      y1=y1+coef_Bezier(i,n-1,t)*b.at(i);
    }
    trace_segment(x0,y0,x1,y1,0.0,1.,0.,3.0);
    x0=x1;
    y0=y1;
  }
}

void init()
{ 
  double xO=0.,yO=0.,xI=1.,yI=0.,xJ=0.,yJ=1.;
  glNewList(1,GL_COMPILE_AND_EXECUTE); //liste numero 1
    openGL(xI,yI,1.,0.,0.,10.); //I
    openGL(xJ,yJ,0.,0.5,0.,10.); //J
    openGL(xO,yO,0.,0.,1.,15.);//O
  glEndList();
  glNewList(2,GL_COMPILE_AND_EXECUTE);  //liste numero 2
    trace_segment(xO,yO,xI,yI,1.0,0.0,1.0,2.0); // on trace [OI]
    trace_segment(xO,yO,xJ,yJ,1.0,0.50,0.0,2.0);// on trace [OJ]
  glEndList();
 
  glNewList(4,GL_COMPILE_AND_EXECUTE);  //liste numero 4
    std::vector<float> x = {2,3,5};
    std::vector<float> y = {0,5,2};
    
    trace_init(x,y);
    
    trace_courbe(x,y);

  glEndList();
 
  glNewList(5,GL_COMPILE_AND_EXECUTE);  //liste numero 5
     
  glEndList();
  glNewList(6,GL_COMPILE_AND_EXECUTE); //liste numero 6
      
  glEndList();


cout<<"\n Voila, c'est fini"<<endl;

}   
   
// fonction permettant d'afficher les objets en utilisant des listes   
void affichage() 
{
  /* effacement de l'image avec la couleur de fond */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(0.0,0.0,dist);
  // Pour la 3D
 // glRotatef(-angley,1.0,0.0,0.0);
 //  glRotatef(-anglex,0.0,1.0,0.0);
 // Pour la 2D    
  glRotatef(-anglex+angley,0.0,0.0,1.0);
  glScalef(Scal,Scal,Scal); // diminution de la vue de la scene
  glRotatef(180,0.0,1.0,0.0);
  glRotatef(180,1.0,0.0,0.0);
  glTranslatef(-trX,trY,0.);
      glCallList(1); // appel de la liste numero 1
      glCallList(2);   // appel de la liste numero 2
      glCallList(4);   // appel de la liste numero 2
 glFlush(); 
  // On echange les buffers
  glutSwapBuffers();
}

