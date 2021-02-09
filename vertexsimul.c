
#include <iostream>
#include <TRandom3.h>
#include <TString.h>
#include "vertex.h"
#include "track.h"
#include <TH3D.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TGraph2D.h>
using namespace std;


void vertexsimul(int seed){
gRandom->SetSeed(seed);
double sigma=5.3;
  vertex v1(sigma, "No",0,0,0) ; 
  v1.prod();    
  track tracce[v1.multi]  ;
  double X[v1.multi];   
  double Y[v1.multi];
  double Z [v1.multi];
  
  for (int i=0; i< v1.multi;i++)  {
  cout<<v1.theta[i]<<v1.phi[i]<<endl; 
    tracce[i]=track(v1.theta[i],  v1.phi[i]);
       tracce[i].intpoint(v1.x, v1.y, v1.z, X[i], Y[i], Z[i], 3.4)   ;
 
    
  }
  TGraph2D *g =new TGraph2D(v1.multi,X,Y,Z);
  new TCanvas("cV","beam",600,600);
g->Draw();
  
}








