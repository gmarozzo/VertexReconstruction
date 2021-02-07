#ifndef TRACK_H
#define TRACK_H

#include "TObject.h"

class track: public TObject {


private:
	double c1, c2, c3;
	int H = 27;
	
public:
	track();
	track(double theta, double phi);
	double parameter(double x, double y, int R);
	void intpoint(double x, double y, double z, int R);
};

#endif
