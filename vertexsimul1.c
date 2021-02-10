#include <iostream>
#include <TRandom3.h>
#include <TString.h>
#include "vertex.cpp"
#include "track1.cpp"
#include <TH3D.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TGraph2D.h>
using namespace std;


void vertexsimul(int seed){

  const double rbeampipe=3.4;
  
  gRandom->SetSeed(seed);
  double sigma=5.3;
  vertex v1(sigma, "No",0,0,0) ;
  v1.prod();
  track tracce[v1.multi]  ;
  double X[v1.multi];   
  double Y[v1.multi];
  double Z [v1.multi];

  for (int i=0; i< v1.multi;i++)  { 
    tracce[i]=track(v1.theta[i],  v1.phi[i]);
    }

  int good=0; //numero di vere intersezioni
  for(int i=0;i<v1.multi;i++) {
    if(tracce[i].intpoint(v1.x,v1.y,v1.z,X[i],Y[i],Z[i],3.4)) {good++;}
      }
  double X1[good];
  double Y1[good];
  double Z1[good];
  int bad=0; //numero di intersezioni oltre il detector incontrate finora
  for (int j=0;j<v1.multi;j++){
    if(tracce[j].intpoint(v1.x,v1.y,v1.z,X[j],Y[j],Z[j],3.4)){
      X1[j-bad]=X[j];
      Y1[j-bad]=Y[j];
      Z1[j-bad]=Z[j];}
    else{bad++;}
  }
  
  TGraph2D *g =new TGraph2D(good,X1,Y1,Z1);
  new TCanvas("cV","beam",600,600);
  g->Draw();
}


	

 
