#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#define F_CPU 1000000UL // частота синхронизации микроконтроллера 1МГц
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
	// настройка линий ввода/вывода
	uint16_t counter; // переменная счетчика
	DDRB=254; // 7 линий на управление дисплеем, 1 линия на датчик
	PORTB=0; // сброс линий PB1-PB7 и подтягивающего резистора PB0
	// настройка внешних периферийных устройств
	display_init(); // инициализация дисплея
	sensor_write(0x4E, 0x1F); // разрешение преобразования 9 бит
	while(1)
	{
sensor_write(0x44, 0x00); // преобразование температуры
_delay_ms(200);
counter=sensor_write(0xBE, 0x00); // чтение температурных данных
display_write(0, 0, 0x1);
_delay_ms(20); // задержка на время выполнения операции
count_termo(counter);
	}
}
//****************************************************************************************
void count_termo(uint16_t counter)
{
uint16_t buffer;
    uint8_t doli=0; // доли
	uint8_t edin=0; // единицы
	uint8_t des=0; // десятки
	uint8_t sot=0; // сотни
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
// функции
// display_init - функция инициализации дисплея
void display_init(void)
{
	// инициализация дисплея
	_delay_ms(20); // задержка 20мс для установления питания
	display_write(0, 1, 0x3); // установка разрядности 8 бит
	display_write(0, 1, 0x3); // установка разрядности 8 бит
	display_write(0, 1, 0x3); // установка разрядности 8 бит
	display_write(0, 1, 0x2); // установка разрядности 4 бит
	display_write(0, 0, 0x28); // установка параметров
	display_write(0, 0, 0x8); // выключение дисплея
	display_write(0, 0, 0x1); // очистка дисплея
	_delay_ms(20); // задержка 20мс на время выполения операции
	display_write(0, 0, 0x6); // установка режима ввода данных
	display_write(0, 0, 0xC); // включение дисплея
}
// display_write - функция записи команды/данных в дисплей
// reg - 0/1 => команда/данные
// bit - 0/1 => текущая разрядность шины данных дисплея 4/8 бит
// display_data - 0xXX => значение, записываемое в дисплей
void display_write(uint8_t reg, uint8_t bit, uint8_t display_data)
{
        // запись команды/данных
	// объявление переменных
	uint8_t buffer; // промежуточный буффер данных
	// запись данных/команды
	if (bit==1)
	{
		// если используется 8-битный режим
		display_data=(display_data & 0xF0) | (0<<RS) | (0<<RW) | (1<<E); // установка бита E
		PORTB=display_data; // запись команды
		display_data=(display_data & 0xF0) | (0<<RS) | (0<<RW) | (0<<E); // сброс бита E
		PORTB=display_data; // запись команды
		_delay_us(100); // задержка после записи команды/данных
	}
	else if (bit==0)
	{
		// если используется 4-битный режим
		buffer=display_data; // копирование данных в буффер
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (1<<E); // установка бита E
		PORTB=display_data; // запись команды
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (0<<E); // сброс бита E
		PORTB=display_data; // запись команды
		display_data=buffer; // копирование данных из буффера
		display_data=(display_data<<4); // сдвинуть на 4 бита влево
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (1<<E); // установка бита E
		PORTB=display_data; // запись команды
		display_data=(display_data & 0xF0) | (reg<<RS) | (0<<RW) | (0<<E); // сброс бита E
		PORTB=display_data; // запись команды
		_delay_us(100); // задержка после записи команды/данных
	}
}
// display_write_word - функция записи строки в дисплей
// data[] - массив символов
// counter - счетчик символов
void display_write_word(uint8_t data[], uint8_t counter)
{
        // объявление переменных
	uint8_t i; // промежуточный счетчик
	for(i=0; i<counter; ++i)
	{
		display_write(1, 0, data[i]); // запись строки символов в дисплей
	}
}
// sensor_write - функция записи команд/данных датчик температуры
// function_cmd - функциональная команда
// scratchpad - данные
uint16_t sensor_write(uint8_t function_cmd, uint8_t scratchpad)
{
	// объявление переменных
	uint8_t i; // счетчик 8/16 бит
    uint8_t logic_level; // логический уровень на линии DQ
	uint8_t rom_cmd; // команда ROM памяти
	uint8_t buffer; // буффер данных
	uint16_t response; // двухбайтовые температурные данные
	rom_cmd=0xCC; // всегда Skip ROM
    response=0x0; // обнуление переменной данных температуры
	// импульс сброса и импульс присутствия
	DDRB=DDRB | (1<<DQ); // запись 0
	_delay_us(960); // задержка 480мкс
	DDRB=DDRB & 0xFE; // запись 1
	_delay_us(960); // задержка 480мкс
	// запись команды ROM памяти
	for(i=0; i<8; ++i)
	{
		buffer=rom_cmd; // копирование данных
		buffer=buffer & 0x1; // выделение 1-го бита
		if(buffer==0x1)
		{
			sensor_write_1_0(1); // запись 1
		}
		else if (buffer==0x0)
		{
			sensor_write_1_0(0); // запись 0
		}
		rom_cmd=(rom_cmd>>1); // сдвинуть содержимое слова команды на разряд вправо
	}
	_delay_ms(20); // задержка между командами
	rom_cmd=function_cmd; // копировать назначение команды
	for(i=0; i<8; ++i)
	{
		buffer=function_cmd; // копирование данных
		buffer=buffer & 0x1; // выделение 1-го бита
		if(buffer==0x1)
		{
			sensor_write_1_0(1); // запись 1
		}
		else if (buffer==0x0)
		{
			sensor_write_1_0(0); // запись 0
		}
		function_cmd=(function_cmd>>1); // сдвинуть содержимое слова команды на разряд вправо
	}
	_delay_ms(20); // задержка между командами
	function_cmd=rom_cmd; // копировать назначение функциональной команды
	if (function_cmd==0x4E)
	{
		// если используется команда Write_Scratchpad
		for(i=0; i<16; ++i)
		{
			sensor_write_1_0(0); // запись 0
		}
		for(i=0; i<8; ++i)
			{
				buffer=scratchpad; // копирование данных
				buffer=buffer & 0x1; // выделение 1-го бита
				if(buffer==0x1)
				{
					sensor_write_1_0(1); // запись 1
				}
				else if (buffer==0x0)
				{
					sensor_write_1_0(0); // запись 0
				}
				scratchpad=(scratchpad>>1); // сдвинуть содержимое слова данных на разряд вправо
			}
		_delay_ms(20); // задержка после записи данных
		return; // возврат из функции
	}
	else if (function_cmd==0xBE)
	{
		// если используется команда Read_Scratchpad
		for(i=0; i<16; ++i)
		{
                        logic_level=sensor_read_1_0(); // чтение линии DQ
			if(logic_level==1)
            {
                response=response | (1<<i); // сборка слова данных температуры
            }
		}
		_delay_ms(20); // задержка после записи данных
		return response; // в ответе содержатся данные температуры
	}
	else return; // выходим
}
// sensor_write_1_0 - функция записи 1/0
// bit - 0/1 => запись 0/1
void sensor_write_1_0(uint8_t bit)
{
	if (bit==0)
	{
		DDRB=DDRB | (1<<DQ); // запись 0
		_delay_us(100); // задержка 100мкс
		DDRB=DDRB & 0xFE; // запись 1
	}
	else if (bit==1)
	{
		DDRB=DDRB | (1<<DQ); // запись 0
		DDRB=DDRB & 0xFE; // запись 1
		_delay_us(100); // задержка 100мкс
	}
}
// sensor_read_1_0 - функция чтения 1/0
uint8_t sensor_read_1_0(void)
{
    // объявление переменных
    uint8_t bit; // данные DQ
	DDRB=DDRB | (1<<DQ); // запись 0
	DDRB=DDRB & 0xFE; // запись 1
	_delay_us(8); // задержка
    bit=PINB & 0x1; // чтение состояния линии DQ
    _delay_us(100); // задержка 100мкс
	if (bit==0x1)
	{
		return 1; // возвращение 1
	}
	else if (bit==0x0)
	{
		return 0; // возвращение 0
	}
}
//********************************************************************************