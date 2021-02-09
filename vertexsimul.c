
#include <iostream>
#include <TRandom3.h>
#include <TString.h>
#include "vertex.cpp"
#include "track.cpp"
#include <TH3D.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TGraph2D.h>
using namespace std;


void vertexsimul(int seed){
  int problemi=0;
  gRandom->SetSeed(seed);
  double sigma=5.3;
  vertex v1(sigma, "No",0,0,0); 
  v1.prod();    
  track tracce[v1.multi];
  double X[v1.multi];   //vettori che contengono le intersezioni delle varie tracce con la beam pipe
  double Y[v1.multi];
  double Z[v1.multi];
  
  for (int i=0; i< v1.multi;i++)  { 
    tracce[i]=track(v1.theta[i],v1.phi[i]);
    tracce[i].intpoint(v1.x, v1.y, v1.z, X[i], Y[i], Z[i], 3.4);
    if(X[i]*X[i]+Y[i]*Y[i]<3.3) {Z[i]=0;}
  }
  
  
  TGraph2D *g =new TGraph2D(v1.multi,X,Y,Z);
  new TCanvas("cV","beam",600,600);
  g->Draw();
  
}








