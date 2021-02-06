#ifndef VERTEX_H
#define VERTEX_H


#include "TObject.h"
#include <TString.h>


class vertex : public TObject {  
public:                      
   vertex(double sigmaz,  TString moltep="No", double zv=0,double xv=0., double yv=0.);   //vertice di default=origine
 ~vertex(); 
   
 
  void prodotti(); 
    double randgauss();
  
  
  
  private:
  int molteplicita ;
  double *theta;
  double *phi;
  double x,y,z,sigma;
      
  //void Setx();
  //void Sety();
  void Setz(); //cambio della coordinata z con distribuzione scelta     
   void moltcost();
 void moltfunz();
  ClassDef(vertex,1) 
};          



#endif


