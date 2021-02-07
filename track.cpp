#include <Riostream.h>
#include "track.h"
#include <TMath.h>

using namespace TMath; 

ClassImp(track)

double X;
double Y;
double Z;

track :: track() : TObject(){
	c1=0;
	c2=0;
	c3=0;
}


track :: track (double theta, double phi) : TObject(){
	double T = theta*Pi()/180; //da radianti a gradi
	double P = phi*Pi()/180;
	c1=Sin(T)*Cos(P);
	c2=Sin(T)*Sin(P);
	c3=Cos(T);
}


double track :: parameter (double x, double y, int R){  //valutazione parametro t
		
		
		double prod = x*c1+y*c2;
		double C = pow(c1,2)+pow(c2,2);
		
		double Delta = pow(prod,2)-C*(pow(x,2)+pow(y,2)-pow(R,2));
		if (Delta<0){
			cout<<"Errore, discriminante negativo."<<endl;	
			return 0;
		}
		double t;
		double t1 = (-prod+sqrt(Delta))/C;
		double t2 = (-prod-sqrt(Delta))/C;
		
		if(t1>0) t=t1;
		else t=t2;
		if(t<0.00000000001)t=0;
		
		return t;
}

void track :: intpoint(double x, double y, double z, int R){  //valutazione punto di intersezione
	
	double t =  parameter(x, y, R);
	
	if(Z>=-H/2 && Z<=H/2) {
		X=x+c1*t;
		Y=y+c2*t;
		Z=z+c3*t;
		if(X<0.00000000001)X=0;  
		if(Y<0.00000000001)Y=0;
		if(Z<0.00000000001)Z=0;
	}
	else cout<<"ERRORE"<<endl;
	
}



