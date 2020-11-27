#ifndef PID_CONTROL_H
#define	PID_CONTROL_H
#include <inttypes.h>

extern int32_t Kp, Ki, Kd, errorPrev, actuator, deriv, Integ;
int16_t pid (int16_t error, int32_t fan_power);

#endif	/* PID_CONTROL_H */
