#include <Riostream.h>
#include "track1.h"
#include <TMath.h>

using namespace TMath; 

ClassImp(track)


track :: track() : TObject (){
	c1=0;
	c2=0;
	c3=0;
}


track :: track (double theta, double phi) : TObject(){
	c1=Sin(theta)*Cos(phi);
	c2=Sin(theta)*Sin(phi);
	c3=Cos(theta);
}
double track :: Delta (double x0, double y0,double R){  //valutazione parametro t
		
		
		double prod = x0*c1+y0*c2;
		double C = c1*c1+c2*c2;
		
		double Delta = (prod*prod)-C*((x0*x0)+(y0*y0)-(R*R));
		return Delta;
		
}


double track :: parameter (double x0, double y0,double Delta){  //valutazione parametro t
		
		double prod = x0*c1+y0*c2;
		double C = c1*c1+c2*c2;
		
		double t;
		double t1 = (-prod+sqrt(Delta))/C;
		double t2 = (-prod-sqrt(Delta))/C;
		
		if(t1>0) t=t1;
		else t=t2;
		if(t<0.00000000001)t=0;
		
		return t;
}

bool track :: intpoint(double x0, double y0, double z0, double &X, double &Y, double &Z, double R){  //valutazione punto di intersezione
	
	if (this->Delta(x0,y0,R)>=0){X=x0+c1*this->parameter(x0,  y0,this->Delta(x0,y0,R)); 
									Y=y0+c2*this->parameter(x0,  y0,this->Delta(x0,y0,R));
									Z=z0+c3*this->parameter( x0,  y0,this->Delta(x0,y0,R)); return true;
									}
					
					else{				X=100001; 
									Y=100001;
									Z=100001; return false;
									}
					
		
					
	
	
}



