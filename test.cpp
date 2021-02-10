#include <Riostream.h>
#include "track.cpp"



void test(double theta, double phi, double x, double y, double z, double R){
	track t(theta, phi);
	cout<<"Parametro t= "<<t.parameter(x,y,R)<<endl;
	double X=0;
	double Y=0;
	double Z=0;
	t.intpoint(x,y,z,X,Y,Z,R);
	cout<<"Il punto di intersezione ha coordinate x= "<<X<<" y= "<<Y<<" z= "<<Z<<endl;
}
