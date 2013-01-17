#include "at89x52.h"
#include "intrins.h"
#include "uart.h"

#define uchar unsigned char
#define uint unsigned int
#define nop _nop_()

void MyDelay(uint tm);

void main(){
	uchar i;
	uchar Mood[8];
	InitUART();//init uart to be use
	SendStrUART("Uart Ready!");
	SendByteUART(0x0D);
	SendByteUART(0x0A);
	for(i=0;i<8;i++){
		SendStrUART("Give me Mood[");
		SendByteUART('0'+i);
		SendByteUART(']');
		SendByteUART(0x0D);
		SendByteUART(0x0A);
		Mood[i]=ReciveByteUART();
	}
	SendStrUART("Show Mood!");
	while(1){
		for(i=0;i<8;i++){
			P2=0xFF;
			P0=Mood[i];
			P2=~(1<<i);
			MyDelay(100);
		}
	}
}

void MyDelay(uint tm){
	uint i;
	for(i=0;i<tm;i++)
		nop;
}