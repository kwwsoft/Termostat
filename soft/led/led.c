//******************************************************************************
short const dig[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
//******************************************************************************
//******************************************************************************
unsigned short led_100 absolute 0x6E;
unsigned short led_bcd absolute 0x6F;
//0xbf
//******************************************************************************
void ShowTemperature(short var){
 //нет датчика
 if (var == 126){
  PORTA = 0xbf & 0xff;
  PORTC = 0x01111111;
  return;
 }
 //show T
 if (var < 100){
  led_100 = 0xff;
 }
 else{
  led_100 = 0x7f;
  var -= 100;
 }
 //
 led_bcd = Dec2Bcd(var);
 //
 PORTA = dig[led_bcd & 0x0f] & led_100;
 //
 led_100 = dig[(led_bcd & 0xF0) >> 4];
 led_bcd = 0xff;
 if ( (led_100 & 0x01) == 0)
  led_bcd.B0 = 0;
 if ( (led_100 & 0x02) == 0)
  led_bcd.B1 = 0;
 if ( (led_100 & 0x04) == 0)
  led_bcd.B3 = 0;
 if ( (led_100 & 0x08) == 0)
  led_bcd.B4 = 0;
 if ( (led_100 & 0x10) == 0)
  led_bcd.B5 = 0;
 if ( (led_100 & 0x20) == 0)
  led_bcd.B6 = 0;
 if ( (led_100 & 0x40) == 0)
  led_bcd.B7 = 0;
 //
 PORTC = led_bcd;
}
//******************************************************************************