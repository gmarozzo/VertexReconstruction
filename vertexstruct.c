#include <iostream>
#include <TRandom3.h>
#include <TMath.h>
using namespace std;
using namespace TMath ;


  double randgauss(double sigma){
    double  u1=gRandom->Rndm(); 
    double u2=gRandom->Rndm();   
    double x;
    return x=Sqrt(-2*Log(u1))*Cos (2*Pi()*u2)*sigma;
    
  }     
  
  
  
  
void vertexdef(int seed){  
gRandom->SetSeed (seed);                   
  struct vertex {
    double xv;
    double yv;
    double zv;
  } ; 
  double sigmaz=5.3;
  vertex v={0,0,randgauss(sigmaz)};    //inizializzazione vertice con z gaussiano, cm     
  
  cout<<"zvertex"<<v.zv <<endl;
   //molteplicià costante
    int mult=10;
    double theta [mult];
    double phi[mult]; //theta e phi a cui partono le particelle prodotte in quel vertice(rispetto a fascio, coordinate sferiche)
    for (int i=0;i<mult; i++){
          phi[i]=gRandom->Rndm()*2*Pi();      //HP iniziale produzione isotropa su sfera (uniformità in phi e costheta)
          theta [i]=ACos(1-2*gRandom->Rndm());
          cout<<phi[i]<<"      "<<Cos(theta[i])<<endl;
    }
  
}