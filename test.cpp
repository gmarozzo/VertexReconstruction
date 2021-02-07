#include <Riostream.h>
#include "track.h"
#include "track.cpp"



void test(double theta, double phi, double x, double y, double z, int R){
	track t(theta, phi);
	cout<<"Parametro t= "<<t.parameter(x,y,R)<<endl;
	t.intpoint(x, y, z, R);
	cout<<"Il punto di intersezione ha coordinate x= "<<X<<" y= "<<Y<<" z= "<<Z<<endl;
}
