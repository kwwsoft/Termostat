extern int lastProcessValue;
extern float sumError;
extern float P_Factor;
//extern float I_Factor;
//extern float D_Factor;
extern float maxError;
extern float maxSumError;
float error absolute 0x3a;
float p_term absolute 0x3E;
//float d_term absolute 0x42;
//float i_term absolute 0x46;
float temp absolute 0x4A;
int ret absolute 0x4E;
//---------------------------------------------------------------------------
// *  \param p_factor  Proportional term.
// *  \param i_factor  Integral term.
// *  \param d_factor  Derivate term.
// *  \param pid  Struct with PID status.
//---------------------------------------------------------------------------
//void pid_Init(/*float p_factor, float i_factor, float d_factor*/){
// sumError = 0;
// lastProcessValue = 0;
// P_Factor = p_factor;
// I_Factor = i_factor;
// D_Factor = d_factor;
 //Limits to avoid overflow
// maxError = 1.6*10e37 / (P_Factor + 1);
// maxSumError =  1.6*10e37 / (P_Factor + 1);
//}
//---------------------------------------------------------------------------
unsigned short pid_Controller(int setPoint, int processValue){
  error = (float)(setPoint - processValue);
  // Calculate Pterm and limit error overflow
  if (error > maxError){
        p_term = maxError;
  }
  else if (error < -maxError){
        p_term = -maxError;
  }
  else{
        p_term = 20 * error;
  }
  // Calculate Iterm and limit integral runaway
  temp = sumError + error;
  if(temp > maxSumError){
//        i_term = 1.6*10e37;
        sumError = maxSumError;
  }
  else if(temp < -maxSumError){
//        i_term = -1.6*10e37;
        sumError = -maxSumError;
  }
  else{
        sumError = temp;
        //i_term = I_Factor * sumError;
//        i_term = 0;
  }
  // Calculate Dterm
//  d_term = D_Factor * (lastProcessValue - processValue);
//  d_term = 0;
  lastProcessValue = processValue;
  ret = p_term;
  if(ret > 253){
        ret = 253;
  }
  else if(ret <= 3){
        ret = 3;
  }
  return((unsigned short)ret);
}
//---------------------------------------------------------------------------
void pid_Reset_Integrator(){
 sumError = 0;
}
//---------------------------------------------------------------------------