#include "api.h"
#include "config.cpp"
double kP = 0.0;
double kI = 0.0;
double kD = 0.0;

int error; //SensorValue- DesiredValue = position
int pError = 0; //position 20ms ago
int de; // error-pError : speed
int tE = 0; // accumulative error, tE = tE+error


double circumferenceI = M_PI * 4;
double circumferenceE = circumferenceI * 900;
double ItoE = circumferenceI / 900; //dividing the circumference by the equivalent Encoder Units gives the ratio of encoder ticks to inches
