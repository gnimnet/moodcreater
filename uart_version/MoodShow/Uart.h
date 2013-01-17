/******************************************************************************
ʹ��ע������:
1.��UART.c���趨��ʹ�õľ���ʹ��ڲ�����
2.�ڳ���ʼӦ���Ƚ��д��ڳ�ʼ������
******************************************************************************/
#ifndef	_UART_H_
#define	_UART_H_

#include "at89x52.h"
#include "intrins.h"
#define uchar unsigned char
#define uint unsigned int
#define nop _nop_()

//**************ע�Ͳ���Ҫ�ĺ���**************//
#define _HAVE_INIT_UART
#define _HAVE_SENDSTR_UART
#define _HAVE_SENDBYTE_UART
#define _HAVE_RECIVEBYTE_UART
//********************************************//

#ifdef _HAVE_INIT_UART
	void InitUART();
#endif //end of _HAVE_INIT_UART
#ifdef _HAVE_SENDSTR_UART
	void SendStrUART(char * Str);
#endif //end of _HAVE_SENDSTR_UART
#ifdef _HAVE_SENDBYTE_UART
	void SendByteUART(uchar Data);
#endif //end of _HAVE_SENDBYTE_UART
#ifdef _HAVE_RECIVEBYTE_UART
	uchar ReciveByteUART();
#endif //end of _HAVE_RECIVEBYTE_UART

#endif //end of _UART_H_
