#include <p18f4525.h> 	//�ǤJ�L����w�q��
#include <delays.h>		//�ǤJ�ɶ�����禡�w�w�q��
//#include <timers.h>		//�ǤJ�p�ɾ��禡�w�w�q��
#include <usart.h>		//�ǤJUSART�禡�w�w�q��
#include <adc.h>
#include <string.h>

void isr_high_direct(void);	
void isr_high(void);

void InitializePORT(void);
void InitializeAD(void);
void InitializeUSART(void);
void InitializeINT(void);

void delay_ms(long);

void err_Modbus(unsigned char err_Code);
unsigned int crcGenerator(unsigned char *crcdata,char sizeofarray);//����CRC
char crcVertify(unsigned char *crcdata,char sizeofarray);//����CRC
