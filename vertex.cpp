#include <iostream>
#include <TRandom3.h>
#include <TString.h>
#include "vertex.h"
#include <TMath.h>
using namespace std;
using namespace TMath ;

ClassImp(vertex)




vertex::vertex(double sigmaz,  TString moltep="No", double zv=0,double xv=0., double yv=0.):TObject,    //seed settato in main
sigma(sigmaz),z(zv) , molteplicita(0),theta (NULL), phi(NULL), x (xv), y(yv)      //controllo in main se sigmaz >=0  
  {  x=0;     //Setx
  y=0;       //Sety
  this->Setz();
  if (moltep=="No") this->moltcost();
  else this->moltfunz() ;}
  
  
  double vertex::randgauss(){ 
  double  u1=Rndm(); 
    double u2=Rndm();   
    double x;
    return x=Sqrt(-2*Log(u1))*Cos (2*Pi()*u2)*sigma;
    
  }     
  
  
  void vertex::Setz() {
  if (sigma>0 ) z=randgauss();
  cout<<"zvertice"<<z<<endl;}   
                               
  
  
  void vertex::moltcost(){
  cout<<"molteplicita"<<endl;
  int m;
  cin>>m;
  if (m>0) molteplicita=m;
  else cout<<"errore"<<endl;
  }
  
  void vertex::moltfunz(){molteplicita=4;}      //da scegliere dopo test che funzione mettere
  
  void vertex::prodotti(){  
  phi=new double[molteplicita]; 
   theta=new double[molteplicita];   
  for (int i=0;i<molteplicita; i++){
          phi[i]=Rndm()*2*Pi();      //HP iniziale produzione isotropa su sfera (uniformità in phi e costheta)
          theta [i]=ACos(1-2*Rndm());
          cout<<phi[i]<<"      "<<Cos(theta[i])<<endl;    }    
          
          vertex::~vertex(){
          delete  [theta];
          delete[phi];   
          sigma=0; 
          molteplicita=0;     
          x=0;
          y=0;
          z=0;    }
          
          
  
  
  
  


