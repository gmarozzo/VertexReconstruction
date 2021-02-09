#ifndef VERTEX_H
#define VERTEX_H


#include "TObject.h"
#include <TString.h>


class vertex : public TObject {  
public:                      
   vertex(double sigmaz,  TString mult, double zv,double xv, double yv);   //vertice di default=origine
 ~vertex(); 
   
 
  void prod(); 
    double randgauss();
   int multi ;//private
  double *theta;//private
  double *phi;//private
   double x,y,z,sigma;
      
  
  private:
 
 
  //void Setx();
  //void Sety();
  void Setz(); //cambio della coordinata z con distribuzione scelta     
   void multconst();
 void multfunc();
 
 
  ClassDef(vertex,1) 
};          



#endif


