//******************************************************************************
//******************************************************************************
char d1[7] absolute 0xA0;
//******************************************************************************
void DebugT(unsigned int var){
 WordToStr(var, d1);
 UART1_Write_Text(d1);
 UART1_Write_Text("\r\n");
}
//******************************************************************************