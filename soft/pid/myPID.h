//---------------------------------------------------------------------------
#ifndef myPIDH
#define myPIDH
//---------------------------------------------------------------------------
  //! Last process value, used to find derivative of process value.
  int lastProcessValue absolute 0x20;
  //! Summation of errors, used for integrate calculations
  float sumError absolute 0x22;
  //! The Proportional tuning constant, multiplied with SCALING_FACTOR
  float P_Factor absolute 0x26;
  //! The Integral tuning constant, multiplied with SCALING_FACTOR
//  float I_Factor absolute 0x2A;
  //! The Derivative tuning constant, multiplied with SCALING_FACTOR
//  float D_Factor absolute 0x2E;
  //! Maximum allowed error, avoid overflow
  float maxError = 1.6*10e37 / (20 + 1) absolute 0x32;
  //! Maximum allowed sumerror, avoid overflow
  float maxSumError = 1.6*10e37 / (20 + 1) absolute 0x36;
//---------------------------------------------------------------------------
//void pid_Init(float p_factor, float i_factor, float d_factor);
unsigned short pid_Controller(int setPoint, int processValue);
void pid_Reset_Integrator();
//---------------------------------------------------------------------------

#endif