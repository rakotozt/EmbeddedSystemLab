
#include "pid_control.h"

int32_t const  IntegMin = -1000;
int32_t const IntegMax = 4000;
void pid_init(){
	actuator = 0;
	errorPrev = 0;
	Kp = 50, Ki = 10, Kd = 20;
}

int16_t pid (int16_t error, int32_t fan_power){
	deriv = errorPrev - error;
	Integ = Integ + error ;
	if( Integ > IntegMax) {
		Integ = IntegMax ;
	}else if ( Integ < IntegMin) {
		Integ = IntegMin;
	}
    //PID formula
	actuator = (Kp*error)+ (Ki*Integ) - (Kd*deriv) ;


	if(actuator < 0 ){ //check underflow
      fan_power = 0;
    } else if(actuator > 65535) {//check overflow
      fan_power = 65535;
    } else {
      fan_power = actuator;
    }
	
	errorPrev = error; 
	return (int16_t)fan_power;
}


