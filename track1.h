#ifndef TRACK_H
#define TRACK_H

#include "TObject.h"

class track: public TObject {


private:
	double c1, c2, c3;
	int H = 30;
	
public:
	track();
	track(double theta, double phi);
	double Delta(double x0, double y0, double R);
	double parameter(double x0, double y0,double Delta);
	bool intpoint( double x0, double y0, double z0, double &X, double &Y, double &Z, double R);
ClassDef(track,1) 
};

#endif
