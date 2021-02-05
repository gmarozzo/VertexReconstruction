#include <TRandom3.h>
#include <cmath>
#include <iostream>

//function that changes the direction of the trajectory

void multiplescattering(double &theta,double &phi){
  
  gRandom->SetSeed(0);
  
  double thetaprimo = gRandom-> Gaus(0,0.0001);
  double phiprimo = 2*acos(-1)*gRandom->Rndm();

  //transformation matrix
  double M[3][3];
  M[0][0]=-sin(phi);
  M[0][1]=-cos(theta)*cos(phi);
  M[0][2]=sin(theta)*cos(phi);
  M[1][0]=cos(phi);
  M[1][1]=-sin(theta)*cos(phi);
  M[1][2]=sin(theta)*sin(phi);
  M[2][0]=0;
  M[2][1]=sin(theta);
  M[2][2]=cos(theta);

  //coordinates of new vector in scattering point's frame of reference
  double usecondo[3];
  usecondo[0]=sin(thetaprimo)*cos(phiprimo);
  usecondo[1]=sin(thetaprimo)*sin(phiprimo);
  usecondo[2]=cos(thetaprimo);

  //coordinates of new vector in original frame of reference
  double u[3];
  for(int i=0;i<3;i++){
    u[i]=0;
    for(int j=0;j<3;j++){
      u[i]+=M[i][j]*usecondo[j];}}

  phi=atan(u[1]/u[0]);
  theta=atan(sqrt(u[0]*u[0]+u[1]*u[1])/u[2]);
  
}

void tester (double theta, double phi){
  
  multiplescattering(theta,phi);
  cout<<"Theta= "<<theta<<", Phi= "<<phi<<endl;
}
