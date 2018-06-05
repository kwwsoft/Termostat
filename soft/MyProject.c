#include "built_in.h"
#include "led.h"
#include "debug.h"
#include "ds18b20.h"
#include "myPID.h"
//******************************************************************************
unsigned short MaxT absolute 0x68;
unsigned short pwm absolute 0x69;
unsigned short tmp1 absolute 0x6A;
unsigned short tmp absolute 0x6B;
unsigned int ds18t absolute 0x6C;

//******************************************************************************
void main() {
  OSCCON = (1<<IRCF2)|(1<<IRCF1)|(0<<IRCF0)|(1<<OSTS)|(0<<SCS);
  //65535/31000 = 2.11 sec
  WDTCON = 0b00001011;
  ANSEL = 0;
  ANSELH = 0;
  TRISA = 0;
  TRISB = 0b11000000;
  TRISC = 0;
  PWM1_Init(20000);
  PWM1_Set_Duty(5);
  PWM1_Start();
  //
  lastProcessValue = 0;
  pid_Reset_Integrator();
  maxT = EEPROM_Read(0);

 while(1){
lab_1:;
  asm clrwdt;
  //датчика нет
  if (Ow_Reset(&PORTB, 0) == 1){
   asm clrwdt;
   ShowTemperature(126);
   Delay_100ms();
   goto lab_1;
  }
  //меряем
  ReadTemperature();
  asm clrwdt;
  ShowTemperature(ds18t);
//  DebugT(ds18t);
  pwm = pid_Controller(MaxT, ds18t);
  PWM1_Set_Duty(pwm);


 
 
 
 
  Delay_ms(800);
 }



 while(1){
 };
}
//******************************************************************************