//---------------------------------------------------------------------------
#ifndef myPIDH
#define myPIDH
//---------------------------------------------------------------------------

class PID_DATA{
 public:
  //! Last process value, used to find derivative of process value.
  int lastProcessValue;
  //! Summation of errors, used for integrate calculations
  float sumError;
  //! The Proportional tuning constant, multiplied with SCALING_FACTOR
  float P_Factor;
  //! The Integral tuning constant, multiplied with SCALING_FACTOR
  float I_Factor;
  //! The Derivative tuning constant, multiplied with SCALING_FACTOR
  float D_Factor;
  //! Maximum allowed error, avoid overflow
  float maxError;
  //! Maximum allowed sumerror, avoid overflow
  float maxSumError;
};
//---------------------------------------------------------------------------
void pid_Init(float p_factor, float i_factor, float d_factor, struct PID_DATA *pid);
int pid_Controller(int setPoint, int processValue, struct PID_DATA *pid_st);
void pid_Reset_Integrator(PID_DATA *pid_st);
//---------------------------------------------------------------------------

#endif


