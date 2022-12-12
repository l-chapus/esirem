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

	
//fonctions ou les objets sont a definir

#include <vector>
#include <array>
#include <assert.h>
#include <algorithm>               //pour le std::sort

void trace_init(std::vector<float> x ,std::vector<float> y)
{
  assert (x.size()==y.size() && "Taille des listes différentes (tracer initiale)");
  openGL(x.at(0),y.at(0),0.2,0.2,0.90,10.);                             //permier point
  openGL(x.at(1),y.at(1),0.2,0.2,0.90,10.);                             //deuxième point
  trace_segment(x.at(0),y.at(0),x.at(1),y.at(1),1.0,0.,0.,0.5);
  int fin=x.size();
  openGL(x.at(fin-1),y.at(fin-1),0.2,0.2,0.90,10.);                     //avant dernier point (troisième dans notre cas)
  openGL(x.at(fin-2),y.at(fin-2),0.2,0.2,0.90,10.);                     //dernier point (quatrième dans notre cas)
  trace_segment(x.at(fin-1),y.at(fin-1),x.at(fin-2),y.at(fin-2),1.0,0.,0.,0.5);
}

float distance(float x_A,float y_A,float x_B,float y_B)
{
  return (pow(pow(x_A-x_B ,2) + pow(y_A-y_B ,2) , 0.5));
}

void droite_parallele(std::vector<float> x ,std::vector<float> y,float& x_M,float& y_M)
{
  float d1 = distance(x.at(0),y.at(0),x.at(3),y.at(3));       //[AD]
  float d2 = distance(x.at(0),y.at(0),x.at(2),y.at(2));       //[AC]
  float d3 = distance(x.at(1),y.at(1),x.at(2),y.at(2));       //[BC]
  float d4 = distance(x.at(1),y.at(1),x.at(3),y.at(3));       //[BD]
  std::array<float,4> x0 = {d1,d2,d3,d4};
  std::sort(x0.begin(), x0.end());                            //trie dans l'ordre croissant les distances et ne conserve que la distance la plus petite
  if(x0.at(0)==d1)
  {
    x_M=(x.at(0)+x.at(3))/2;
    y_M=(y.at(0)+y.at(3))/2;
  }
  if(x0.at(0)==d2)
  {
    x_M=(x.at(0)+x.at(2))/2;
    y_M=(y.at(0)+y.at(2))/2;
  }
  if(x0.at(0)==d3)
  {
    x_M=(x.at(1)+x.at(2))/2;
    y_M=(y.at(1)+y.at(2))/2;
  }
  if(x0.at(0)==d4)
  {
    x_M=(x.at(1)+x.at(3))/2;
    y_M=(y.at(1)+y.at(3))/2;
  }
}

void point_controle(std::vector<float> x ,std::vector<float> y,float& x_M,float& y_M)
{
  assert (x.size()==y.size() && "Taille des listes différentes (point de contrôle)");

  float a1=0.0,a2=0.0,b1=0.0,b2=0.0;
  a1 = (y.at(0)-y.at(1))/(x.at(0)-x.at(1));   //coef directeur de la première droite
  a2 = (y.at(2)-y.at(3))/(x.at(2)-x.at(3));   //coef directeur de la deuxième droite
  b1 = y.at(0)-a1*x.at(0);                    //ordonné à l'origine de la première droite
  b2 = y.at(2)-a2*x.at(2);                    //ordonné à l'origine de la deuxième droite

  if((a1-a2)==0)                          //droites parallèles
  {                           
    droite_parallele(x,y,x_M,y_M);
  }
  else                                    //droites sécantes
  {                                     
    x_M = (b2-b1)/(a1-a2);
    y_M = a1*x_M+b1;       //ou y_M = a2*x_M+b2  (même résultat)
  }
}

void trace_courbe(std::vector<float>& x ,std::vector<float>& y,float x_M,float y_M)
{
  assert (x.size()==y.size() && "Taille des listes différentes (tracer de la courbe)");
  
  std::array<float,3> x0 = {0.0,x_M,0.0};
  std::array<float,3> y0 = {0.0,y_M,0.0};
  if(distance(x.at(0),y.at(0),x_M,y_M) < distance(x.at(1),y.at(1),x_M,y_M))        //test de la longueur entre le point A et le point de contrôle
  {
    x0.at(0) = x.at(1);
    y0.at(0) = y.at(1);
  }
  else                                                                            //test de la longueur entre le point B et le point de contrôle
  {
    x0.at(0) = x.at(0);
    y0.at(0) = y.at(0);
  }
  if(distance(x.at(2),y.at(2),x_M,y_M) < distance(x.at(3),y.at(3),x_M,y_M))      //test de la longueur entre le point C et le point de contrôle
  {
    x0.at(2) = x.at(3);
    y0.at(2) = y.at(3);
  }
  else                                                                          //test de la longueur entre le point D et le point de contrôle
  {
    x0.at(2) = x.at(2);
    y0.at(2) = y.at(2);
  }

  double t = 0.0;
  float n = 1001;
  float x_tmp0=x0.at(0),y_tmp0=y0.at(0),x_tmp1=0.0,y_tmp1=0.0;
  for(int k=0;k<n;++k)
  {
    t=k/n;
    x_tmp1=(1-t)*(1-t)*x0.at(0)+2*t*(1-t)*x0.at(1)+t*t*x0.at(2);
    y_tmp1=(1-t)*(1-t)*y0.at(0)+2*t*(1-t)*y0.at(1)+t*t*y0.at(2);
    trace_segment(x_tmp0,y_tmp0,x_tmp1,y_tmp1,0.0,1.,0.,3.0);                 //trace un petit bout de segment
    x_tmp0=x_tmp1;
    y_tmp0=y_tmp1;
  }
}

void trace_tout(std::vector<float>& x ,std::vector<float>& y)
{
  trace_init(x,y);
  float x_M=0.0,y_M=0.0;            //point de contrôle
  point_controle(x,y,x_M,y_M);
  trace_courbe(x,y,x_M,y_M);
  openGL(x_M,y_M,1.,0.,0.,10.);     //tracer du point de contrôle
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
 
  glNewList(4,GL_COMPILE_AND_EXECUTE);  //liste numero 4, cas droite parallèle
      
    std::vector<float> x = {-1,4,-0.5,2};
    std::vector<float> y = {-3,1,-4,-2};
    
    trace_tout(x,y);

  glEndList();
 
  glNewList(5,GL_COMPILE_AND_EXECUTE);  //liste numero 5, cas droite séquente
    
    std::vector<float> x1 = {-1,4,8,7};
    std::vector<float> y1 = {-3,1,-2,-7};
    
    trace_tout(x1,y1);

  glEndList();


cout<<"\nVoila, c'est fini"<<endl;

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
      glCallList(4);   // appel de la liste numero 4
      //glCallList(5);   // appel de la liste numero 5
 glFlush(); 
  // On echange les buffers
  glutSwapBuffers();
}

