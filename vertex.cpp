#include <iostream>
#include <TRandom3.h>
#include <TString.h>
#include "vertex.h"
#include <TMath.h>
using namespace std;
using namespace TMath ;

ClassImp(vertex)




vertex::vertex(double sigmaz,  TString mult, double zv,double xv, double yv):TObject()    //seed settato in main
    //controllo in main se sigmaz >=0  
  {  x=xv;     //Setx
  y=yv;   
  z=zv;
  sigma=sigmaz;
  multi=0;
  theta=NULL;
  phi=NULL;    //Sety
  this->Setz();
  if (mult=="No") this->multconst();
  else this->multfunc() ;}


double vertex::randgauss(){
  double  u1=gRandom->Rndm();
  double u2=gRandom->Rndm();
  double x;
  return x=Sqrt(-2*Log(u1))*Cos (2*Pi()*u2)*sigma;
}     
  
  
void vertex::Setz() {
  if (sigma>0 ) z=randgauss();
  cout<<endl<<"z vertice = "<<z<<endl;}   
                               
  
  
void vertex::multconst(){
  cout<<endl<<"inserire molteplicita"<<endl;
  int m;
  cin>>m;
  if (m>0) multi=m;
  else cout<<"errore: la molteplicita deve essere positiva"<<endl;
}
  
void vertex::multfunc(){multi=4;}      //da scegliere dopo test che funzione mettere
  
void vertex::prod(){
  phi=new double[multi];
  theta=new double[multi];
  cout<<endl<<"Angoli particelle prodotte: "<<endl;
  for (int i=0;i<multi; i++){
          phi[i]=gRandom->Rndm()*2*Pi();      //HP iniziale produzione isotropa su sfera (uniformità in phi e costheta)
          theta [i]=ACos(1-2*gRandom->Rndm());
          cout<<"Phi[i]= "<<phi[i]<<"       "<<"Cos(theta[i])= "<<Cos(theta[i])<<endl;    }
  cout<<endl;
}

vertex::~vertex(){
  delete  [] theta;
  delete[] phi;   
  sigma=0; 
  multi=0;     
  x=0;
  y=0;
  z=0;    }
          
          
  
