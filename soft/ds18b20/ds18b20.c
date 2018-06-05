//******************************************************************************
extern unsigned int ds18t;
//******************************************************************************
//******************************************************************************
void ReadTemperature(){
 //135ms
 Ow_Reset(&PORTB, 0);                         // Onewire reset signal
 Ow_Write(&PORTB, 0, 0xCC);                   // Issue command SKIP_ROM
 Ow_Write(&PORTB, 0, 0x4E);                   //
 Ow_Write(&PORTB, 0, 0x1F);                   //
 //
 Ow_Reset(&PORTB, 0);                         // Onewire reset signal
 Ow_Write(&PORTB, 0, 0xCC);                   // Issue command SKIP_ROM
 Ow_Write(&PORTB, 0, 0x44);                   // Issue command CONVERT_T
 Delay_ms(120);
//
 Ow_Reset(&PORTB, 0);
 Ow_Write(&PORTB, 0, 0xCC);                   // Issue command SKIP_ROM
 Ow_Write(&PORTB, 0, 0xBE);                   // Issue command READ_SCRATCHPAD
 ds18t =  Ow_Read(&PORTB, 0);
 ds18t = ((Ow_Read(&PORTB, 0) << 8) + ds18t)>>4;
}
//******************************************************************************