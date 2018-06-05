#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#define F_CPU 1000000UL // ������� ������������� ���������������� 1���
#define DQ 0
#define RS 1
#define RW 2
#define E  3
//****************************************************************************************
void count_termo(uint16_t counter);
void display_init(void);
void display_write(uint8_t reg, uint8_t bit, uint8_t display_data);
void display_write_word(uint8_t data[], uint8_t counter);
uint16_t sensor_write(uint8_t function_cmd, uint8_t scratchpad);
void sensor_write_1_0(uint8_t bit);
uint8_t sensor_read_1_0(void);
//****************************************************************************************
int main(void)
{
	// ��������� ����� �����/������
	uint16_t counter; // ���������� ��������
	DDRB=254; // 7 ����� �� ���������� ��������, 1 ����� �� ������
	PORTB=0; // ����� ����� PB1-PB7 � �������������� ��������� PB0
	// ��������� ������� ������������ ���������
	display_init(); // ������������� �������
	sensor_write(0x4E, 0x1F); // ���������� �������������� 9 ���
	while(1)
	{
sensor_write(0x44, 0x00); // �������������� �����������
_delay_ms(200);
counter=sensor_write(0xBE, 0x00); // ������ ������������� ������
display_write(0, 0, 0x1);
_delay_ms(20); // �������� �� ����� ���������� ��������
count_termo(counter);
	}
}
//****************************************************************************************
void count_termo(uint16_t counter)
{
uint16_t buffer;
    uint8_t doli=0; // ����
	uint8_t edin=0; // �������
	uint8_t des=0; // �������
	uint8_t sot=0; // �����
	counter=counter>>3;
	buffer=counter;
	if ((counter & 256)==256)
	{
	    ;
	}

	else if ((counter & 256)==0)
	{
	counter=buffer;
	while(counter>0)
	{
	    ++doli;
		if (doli>1)
		{
		    doli=0;
			++edin;
			if (edin>9)
			{
			    edin=0;
				++des;
				if (des>9)
				{
				    des=0;
				    ++sot;
				}
			}
		}
		--counter;
	}
	if (sot==1)
	{
	display_write_word("1", 1);
	if (des==0)
	display_write_word("0", 1);
	else if (des==1)
	display_write_word("1", 1);
	else if (des==2)
	display_write_word("2", 1);
	else if (des==3)
	display_write_word("3", 1);
	else if (des==4)
	display_write_word("4", 1);
	else if (des==5)
	display_write_word("5", 1);
	else if (des==6)
	display_write_word("6", 1);
	else if (des==7)
	display_write_word("7", 1);
	else if (des==8)
	display_write_word("8", 1);
	else if (des==9)
	display_write_word("9", 1);
	
	if (edin==0)
	display_write_word("0", 1);
	else if (edin==1)
	display_write_word("1", 1);
		else if (edin==2)
	display_write_word("2", 1);
		else if (edin==3)
	display_write_word("3", 1);
		else if (edin==4)
	display_write_word("4", 1);
		else if (edin==5)
	display_write_word("5", 1);
		else if (edin==6)
	display_write_word("6", 1);
		else if (edin==7)
	display_write_word("7", 1);
		else if (edin==8)
	display_write_word("8", 1);
		else if (edin==9)
	display_write_word("9", 1);
	
	display_write_word(",", 1);
	
	if (doli==0)
	display_write_word("0", 1);
	else if (doli==1)
	display_write_word("5", 1);
	return;
	}
	else if (des>0)
	{
	if (des==1)
	display_write_word("1", 1);
	else if (des==2)
	display_write_word("2", 1);
	else if (des==3)
	display_write_word("3", 1);
	else if (des==4)
	display_write_word("4", 1);
	else if (des==5)
	display_write_word("5", 1);
	else if (des==6)
	display_write_word("6", 1);
	else if (des==7)
	display_write_word("7", 1);
	else if (des==8)
	display_write_word("8", 1);
	else if (des==9)
	display_write_word("9", 1);
	
	if (edin==0)
	display_write_word("0", 1);
	else if (edin==1)
	display_write_word("1", 1);
		else if (edin==2)
	display_write_word("2", 1);
		else if (edin==3)
	display_write_word("3", 1);
		else if (edin==4)
	display_write_word("4", 1);
		else if (edin==5)
	display_write_word("5", 1);
		else if (edin==6)
	display_write_word("6", 1);
		else if (edin==7)
	display_write_word("7", 1);
		else if (edin==8)
	display_write_word("8", 1);
		else if (edin==9)
	display_write_word("9", 1);
	
	display_write_word(",", 1);
	
	if (doli==0)
	display_write_word("0", 1);
	else if (doli==1)
	display_write_word("5", 1);
	return;
	}
	else if (edin==0)
	display_write_word("0", 1);
	else if (edin==1)
	display_write_word("1", 1);
		else if (edin==2)
	display_write_word("2", 1);
		else if (edin==3)
	display_write_word("3", 1);
		else if (edin==4)
	display_write_word("4", 1);
		else if (edin==5)
	display_write_word("5", 1);
		else if (edin==6)
	display_write_word("6", 1);
		else if (edin==7)
	display_write_word("7", 1);
		else if (edin==8)
	display_write_word("8", 1);
		else if (edin==9)
	display_write_word("9", 1);
	
	display_write_word(",", 1);
	
	if (doli==0)
	display_write_word("0", 1);
	else if (doli==1)
	display_write_word("5", 1);
	return;
	}
}
// �������
// display_init - ������� ������������� �������
void display_init(void)
{
	// ������������� �������
	_delay_ms(20); // �������� 20�� ��� ������������ �������
	display_write(0, 1, 0x3); // ��������� ����������� 8 ���
	display_write(0, 1, 0x3); // ��������� ����������� 8 ���
	display_write(0, 1, 0x3); // ��������� ����������� 8 ���
	display_write(0, 1, 0x2); // ��������� ����������� 4 ���
	display_write(0, 0, 0x28); // ��������� ����������
	display_write(0, 0, 0x8); // ���������� �������
	display_write(0, 0, 0x1); // ������� �������
	_delay_ms(20); // �������� 20�� �� ����� ��������� ��������
	display_write(0, 0, 0x6); // ��������� ������ ����� ������
	display_write(0, 0, 0xC); // ��������� �������
}
// display_write - ������� ������ �������/������ � �������
// reg - 0/1 => �������/������
// bit - 0/1 => ������� ����������� ���� ������ ������� 4/8 ���
// display_data - 0xXX => ��������, ������������ � �������
void display_write(uint8_t reg, uint8_t bit, uint8_t display_data)
{
        // ������ �������/������
	// ���������� ����������
	uint8_t buffer; // ������������� ������ ������
	// ������ ������/�������
	if (bit==1)
	{
		// ���� ������������ 8-������ �����
		display_data=(display_data & 0xF0) | (0<<RS) | (0<<RW) | (1<<E); // ��������� ���� E
		PORTB=display_data; // ������ �������
		display_data=(display_data & 0xF0) | (0<<RS) | (0<<RW) | (0<<E); // ����� ���� E
		PORTB=display_data; // ������ �������
		_delay_us(100); // �������� ����� ������ �������/������
	}
	else if (bit==0)
	{
		// ���� ������������ 4-������ �����
		buffer=display_data; // ����������� ������ � ������
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (1<<E); // ��������� ���� E
		PORTB=display_data; // ������ �������
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (0<<E); // ����� ���� E
		PORTB=display_data; // ������ �������
		display_data=buffer; // ����������� ������ �� �������
		display_data=(display_data<<4); // �������� �� 4 ���� �����
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (1<<E); // ��������� ���� E
		PORTB=display_data; // ������ �������
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (0<<E); // ����� ���� E
		PORTB=display_data; // ������ �������
		_delay_us(100); // �������� ����� ������ �������/������
	}
}
// display_write_word - ������� ������ ������ � �������
// data[] - ������ ��������
// counter - ������� ��������
void display_write_word(uint8_t data[], uint8_t counter)
{
        // ���������� ����������
	uint8_t i; // ������������� �������
	for(i=0; i<counter; ++i)
	{
		display_write(1, 0, data[i]); // ������ ������ �������� � �������
	}
}
// sensor_write - ������� ������ ������/������ ������ �����������
// function_cmd - �������������� �������
// scratchpad - ������
uint16_t sensor_write(uint8_t function_cmd, uint8_t scratchpad)
{
	// ���������� ����������
	uint8_t i; // ������� 8/16 ���
    uint8_t logic_level; // ���������� ������� �� ����� DQ
	uint8_t rom_cmd; // ������� ROM ������
	uint8_t buffer; // ������ ������
	uint16_t response; // ������������ ������������� ������
	rom_cmd=0xCC; // ������ Skip ROM
    response=0x0; // ��������� ���������� ������ �����������
	// ������� ������ � ������� �����������
	DDRB=DDRB | (1<<DQ); // ������ 0
	_delay_us(960); // �������� 480���
	DDRB=DDRB & 0xFE; // ������ 1
	_delay_us(960); // �������� 480���
	// ������ ������� ROM ������
	for(i=0; i<8; ++i)
	{
		buffer=rom_cmd; // ����������� ������
		buffer=buffer & 0x1; // ��������� 1-�� ����
		if(buffer==0x1)
		{
			sensor_write_1_0(1); // ������ 1
		}
		else if (buffer==0x0)
		{
			sensor_write_1_0(0); // ������ 0
		}
		rom_cmd=(rom_cmd>>1); // �������� ���������� ����� ������� �� ������ ������
	}
	_delay_ms(20); // �������� ����� ���������
	rom_cmd=function_cmd; // ���������� ���������� �������
	for(i=0; i<8; ++i)
	{
		buffer=function_cmd; // ����������� ������
		buffer=buffer & 0x1; // ��������� 1-�� ����
		if(buffer==0x1)
		{
			sensor_write_1_0(1); // ������ 1
		}
		else if (buffer==0x0)
		{
			sensor_write_1_0(0); // ������ 0
		}
		function_cmd=(function_cmd>>1); // �������� ���������� ����� ������� �� ������ ������
	}
	_delay_ms(20); // �������� ����� ���������
	function_cmd=rom_cmd; // ���������� ���������� �������������� �������
	if (function_cmd==0x4E)
	{
		// ���� ������������ ������� Write_Scratchpad
		for(i=0; i<16; ++i)
		{
			sensor_write_1_0(0); // ������ 0
		}
		for(i=0; i<8; ++i)
			{
				buffer=scratchpad; // ����������� ������
				buffer=buffer & 0x1; // ��������� 1-�� ����
				if(buffer==0x1)
				{
					sensor_write_1_0(1); // ������ 1
				}
				else if (buffer==0x0)
				{
					sensor_write_1_0(0); // ������ 0
				}
				scratchpad=(scratchpad>>1); // �������� ���������� ����� ������ �� ������ ������
			}
		_delay_ms(20); // �������� ����� ������ ������
		return; // ������� �� �������
	}
	else if (function_cmd==0xBE)
	{
		// ���� ������������ ������� Read_Scratchpad
		for(i=0; i<16; ++i)
		{
                        logic_level=sensor_read_1_0(); // ������ ����� DQ
			if(logic_level==1)
            {
                response=response | (1<<i); // ������ ����� ������ �����������
            }
		}
		_delay_ms(20); // �������� ����� ������ ������
		return response; // � ������ ���������� ������ �����������
	}
	else return; // �������
}
// sensor_write_1_0 - ������� ������ 1/0
// bit - 0/1 => ������ 0/1
void sensor_write_1_0(uint8_t bit)
{
	if (bit==0)
	{
		DDRB=DDRB | (1<<DQ); // ������ 0
		_delay_us(100); // �������� 100���
		DDRB=DDRB & 0xFE; // ������ 1
	}
	else if (bit==1)
	{
		DDRB=DDRB | (1<<DQ); // ������ 0
		DDRB=DDRB & 0xFE; // ������ 1
		_delay_us(100); // �������� 100���
	}
}
// sensor_read_1_0 - ������� ������ 1/0
uint8_t sensor_read_1_0(void)
{
    // ���������� ����������
    uint8_t bit; // ������ DQ
	DDRB=DDRB | (1<<DQ); // ������ 0
	DDRB=DDRB & 0xFE; // ������ 1
	_delay_us(8); // ��������
    bit=PINB & 0x1; // ������ ��������� ����� DQ
    _delay_us(100); // �������� 100���
	if (bit==0x1)
	{
		return 1; // ����������� 1
	}
	else if (bit==0x0)
	{
		return 0; // ����������� 0
	}
}
//********************************************************************************