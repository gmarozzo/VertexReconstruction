#include <Riostream.h>
#include "track.h"
#include <TMath.h>

using namespace TMath; 

ClassImp(track)


track :: track() : TObject(){
	c1=0;
	c2=0;
	c3=0;
}


track :: track (double theta, double phi) : TObject(){
	c1=Sin(theta)*Cos(phi);
	c2=Sin(theta)*Sin(phi);
	c3=Cos(theta);
}


double track :: parameter (double x0, double y0, double R){  //valutazione parametro t
		
		
		double prod = x0*c1+y0*c2;
		double C = c1*c1+c2*c2;
		
		double Delta = (prod*prod)-C*((x0*x0)+(y0*y0)-(R*R));
		if (Delta<0){
			cout<<"Errore, discriminante negativo."<<endl;	
			return 0;
		}
		double t;
		double t1 = (-prod+sqrt(Delta))/C;
		double t2 = (-prod-sqrt(Delta))/C;
		
		if(t1>0) t=t1;
		else t=t2;
		
		return t;
}

void track :: intpoint(double x0, double y0, double z0, double &X, double &Y, double &Z, double R){  //valutazione punto di intersezione
	
	double t =  parameter(x0, y0, R);

	Z=z0+c3*t;
	X=x0+c1*t;
	Y=y0+c2*t;
	
}



