#pragma hdrstop
#include "myPID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
// *  \param p_factor  Proportional term.
// *  \param i_factor  Integral term.
// *  \param d_factor  Derivate term.
// *  \param pid  Struct with PID status.
//---------------------------------------------------------------------------
void pid_Init(float p_factor, float i_factor, float d_factor, struct PID_DATA *pid){
  pid->sumError = 0;
  pid->lastProcessValue = 0;
  pid->P_Factor = p_factor;
  pid->I_Factor = i_factor;
  pid->D_Factor = d_factor;
  // Limits to avoid overflow
  pid->maxError = 3.4*10e38 / (pid->P_Factor + 1);
  pid->maxSumError =  1.6*10e38 / (pid->P_Factor + 1);
}
//---------------------------------------------------------------------------
// *  \param setPoint  Desired value.
// *  \param processValue  Measured value.
// *  \param pid_st  PID status struct.
//---------------------------------------------------------------------------
int pid_Controller(int setPoint, int processValue, struct PID_DATA *pid_st){
  float error, p_term, d_term, i_term, temp;
  int ret;
  error = (float)(setPoint - processValue);
  // Calculate Pterm and limit error overflow
  if (error > pid_st->maxError){
	p_term = pid_st->maxError;
  }
  else if (error < -pid_st->maxError){
	p_term = -pid_st->maxError;
  }
  else{
	p_term = pid_st->P_Factor * error;
  }
  // Calculate Iterm and limit integral runaway
  temp = pid_st->sumError + error;
  if(temp > pid_st->maxSumError){
	i_term = 1.6*10e38;
	pid_st->sumError = pid_st->maxSumError;
  }
  else if(temp < -pid_st->maxSumError){
	i_term = -1.6*10e38;
	pid_st->sumError = -pid_st->maxSumError;
  }
  else{
	pid_st->sumError = temp;
	i_term = pid_st->I_Factor * pid_st->sumError;
  }
  // Calculate Dterm
  d_term = pid_st->D_Factor * (pid_st->lastProcessValue - processValue);
  pid_st->lastProcessValue = processValue;
  ret = (int)(p_term + i_term + d_term);
  if(ret > 100){
	ret = 100;
  }
  else if(ret <= 0){
	ret = 0;
  }
  return((int)ret);
}
//---------------------------------------------------------------------------
void pid_Reset_Integrator(PID_DATA *pid_st){
  pid_st->sumError = 0;
}
//---------------------------------------------------------------------------
