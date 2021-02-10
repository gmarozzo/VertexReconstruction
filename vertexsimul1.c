#include <iostream>
#include <TRandom3.h>
#include <TString.h>
#include "vertex.h"
#include "track1.h"
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
      
 
    
  }
  
  int i=0, j=0;
int	s=0;
while (j<v1.multi) {while (i<v1.multi) { if (tracce[j].intpoint(v1.x, v1.y, v1.z, X[j], Y[j], Z[j], 3.4)){ i++; j++; s++;} else { i++;  } } } 
if (! tracce[i].intpoint(v1.x, v1.y, v1.z, X[j], Y[j], Z[j], 3.4))s=s-1;
 double X1[s];   
  double Y1[s];
  double Z1 [s];
  for (int i=0; i<s;i++){X1[i]=X[i];Y1[i]=Z[i];Y1[i]=Z[i];} 
  TGraph2D *g =new TGraph2D(v1.multi,X1,Y1,Z1);
  new TCanvas("cV","beam",600,600);
g->Draw();
  
}


	

 
