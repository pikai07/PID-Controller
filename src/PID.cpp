#include "PID.h"
#include <math.h> 

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp=Kp;
	this->Ki=Ki;
	this->Kd=Kd;

	p_error=0;
	i_error=0;
	d_error=0;
}

void PID::UpdateError(double cte) {
	d_error = cte-p_error; /* Previous cte is p_error */
	p_error = cte;
	i_error += cte;

}

double PID::TotalError() {
	double steering= Kp*p_error+Ki*i_error+Kd*d_error;

	if (fabs(steering)>1.0){
    if (steering> 0){
      steering = 1.0;
    } else {
      steering = -1.0;
    }
  }
	return steering;
}

