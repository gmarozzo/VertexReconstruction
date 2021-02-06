#include <iostream>
#include <TRandom3.h>
#include <TString.h>
#include "vertex.h"
#include <TMath.h>
using namespace std;


void vertexsimul(int seed){
gRandom->SetSeed(seed);
double sigma=5.3;
  vertex v1(sigma) ; 
  v1.prodotti();    
  
}