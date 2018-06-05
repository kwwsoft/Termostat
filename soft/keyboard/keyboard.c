//-----------------------------------------------------------------------------
extern short short_1;
extern unsigned long int key_press;
//-----------------------------------------------------------------------------
#include "built_in.h"
#include "global.h"
//-----------------------------------------------------------------------------
char GetKeyNormal(){
 //nothing is pressed
 key_press = 0;
 short_1 = (PORTB & 0b00110000);
 //kbd is not pressed - mask is inverted
 if (short_1 == 0b00110000)
  return key_nothing;
 //check key
 do{
  key_press ++;
  //long press more then 1500 ms
  if (key_press > 20000){
   //если зависка непонятка
   if (key_press > 200000){
    return key_nothing;
   }
   //select long key pressed
   if (short_1 == 0b00000000){
    short_1 = key_select_long;
   }
   //up long key pressed
   else if (short_1 == 0b00010000){
    short_1 = key_up_long;
   }
   //down long key pressed
   else{
    short_1 = key_down_long;
   }
   PlaySound_1000_50();
   PlaySound_500_50();
   PlaySound_1000_50();
   PlaySound_500_50();
   //wait key release
   do{
   }while((PORTB & 0b00110000) != 0b00110000);
   //return key;
   return short_1;
  }
 }while( short_1 == (PORTB & 0b00110000) );
 //key is not pressed for a needed time 100 ms
 if (key_press < 1500){
  return key_nothing;
 }
 //select  pressed
 if (short_1 == 0b00000000){
  short_1 = key_select;
 }
 //up  key pressed
 else if (short_1 == 0b00010000){
  short_1 = key_up;
 }
 //down  key pressed
 else{
  short_1 = key_down;
 }
 PlaySound_1000_50();
 PlaySound_500_50();
 //wait key release
 do{
 }while((PORTB & 0b00110000) != 0b00110000);
//return pressed key
 return short_1;
}
//-----------------------------------------------------------------------------