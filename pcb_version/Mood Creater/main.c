#include "at89x52.h"
#include "intrins.h"
#include "MyFont(ASCII).h"
#include "MyMood.h"
#include "Welcome.h"

#define uchar unsigned char
#define uint unsigned int
#define nop _nop_()

sbit Key1=P3^0;//按键1
sbit Key2=P3^1;//按键2

/**********模式对应函数**********/
void Mode0();//模式0，ASCII(+)(-)
void Mode1();//模式1，ASCII(随机)
void Mode2();//模式2，数字图形(随机)
void Mode3();//模式3，表情图形(随机)
void Mode4();//模式4，图像图形(随机)
void Mode5();//模式5，动态图形(+)(-)
void Mode6();//模式6，动态数字(模式1--一直循环一个)(模式2--一个完成显示下一个)
void Mode7();//模式7，两帧动画(+)(-)
void Mode8();//模式8，四帧动画(+)(-)
void Mode9();//模式9，六帧动画(+)(-)
void Mode10();//模式10，DIY图形
void Mode11();//模式11，DIY两帧动画
void Mode12();//模式12，DIY四帧动画
void Mode13();//模式13，DIY六帧动画
void Mode14();//模式14，走迷宫
void Mode15();//模式15,By 明

//PlayLED相关参数宏
#define SPEED_LOW		16	//低速，用于N帧动画
#define SPEED_MEDIUM	12	//中速
#define SPEED_HIGH		8	//高速，用于图形生成

#define ALWAYSSTAY	0	//一直停留
#define STAYTIMES	32	//停留32次

/**********通用函数**********/
uchar GetMode();//获取4bit模式(从4位开关获取)
uchar PlayLED(const uchar figure[][8],const uchar num,uchar stop,uchar back,uchar drawret,uchar speed,uchar staytimes);//用于显示刷新动态图形
void Refresh(const uchar figure[]);//刷新点阵函数
void SetupBuf();//通过4位开关获取LED缓冲(4*16次)
void MyDelay(uint tm);//延时函数
void DoWelcome();//欢迎函数

/**********迷宫函数**********/
uchar CanGo(char x,char y);//判断坐标(x,y)是否可以走
void SolveGo(char x,char y,uchar Last);//获取可行走的方向，参数Last为上次的移动方向

/**********全局变量**********/
uchar BufferLED[8];//显示缓冲
uchar PlayBuf[6][8];//DIY动画缓冲
uchar code Maze[8]={0x22,0x6A,0x28,0x0F,0xE0,0x0A,0x7A,0x42};//默认迷宫
uchar Goto[4];//行走方向(用于计算)
uchar GotoCnt;//记录可行走的方向个数
uchar Mode;//运行模式

void main(){
	MyDelay(1000);//延迟等待电源平稳
	TMOD=0x21;//Timer1为8位自动加载(作为随机数产生器)
	TCON=0x40;//Timer1启动
	DoWelcome();//显示欢迎动画同时获取工作模式
	while(1){
		if(Mode==0){//模式0，ASCII(+)(-)
			Mode0();//Never Return
		}
		else if(Mode==1){//模式1，ASCII(随机)
			Mode1();//Never Return
		}
		else if(Mode==2){//模式2，数字图形(随机)
			Mode2();//Never Return
		}
		else if(Mode==3){//模式3，表情图形(随机)
			Mode3();//Never Return
		}
		else if(Mode==4){//模式4，图像图形(随机)
			Mode4();//Never Return
		}
		else if(Mode==5){//模式5，动态图形(+)(-)
			Mode5();//Never Return
		}
		else if(Mode==6){//模式6，动态数字(模式1--一直循环一个)(模式2--一个完成显示下一个)
			Mode6();//Never Return
		}
		else if(Mode==7){//模式7，两帧动画(+)(-)
			Mode7();//Never Return
		}
		else if(Mode==8){//模式8，四帧动画(+)(-)
			Mode8();//Never Return
		}
		else if(Mode==9){//模式9，六帧动画(+)(-)
			Mode9();//Never Return
		}
		else if(Mode==10){//模式10，DIY图形
			Mode10();//Never Return
		}
		else if(Mode==11){//模式11，DIY两帧动画
			Mode11();//Never Return
		}
		else if(Mode==12){//模式12，DIY四帧动画
			Mode12();//Never Return
		}
		else if(Mode==13){//模式13，DIY六帧动画
			Mode13();//Never Return
		}
		else if(Mode==14){//模式14，走迷宫
			Mode14();//Never Return
		}
		else if(Mode==15){//模式15,By 明
			Mode15();//Never Return
		}
	}
}

void DoWelcome(){//欢迎函数
	uchar tmp;
	uchar ascindex;
	tmp=PlayLED(Welcome,WELCOME_NUM,1,0,1,SPEED_LOW,ALWAYSSTAY);//不自动返回，等待按键
	if(tmp==1){//按键1，按4位开关获取模式
		Mode=GetMode();//获取4位模式设定
	}
	else if(tmp==2){//按键2，随机产生模式
		Mode= TL1 % 0x10;//通过Timer1的计数获取随机数，得到工作模式
		if(Mode>9){
			ascindex='A'-0x20-10+Mode;
		}
		else{
			ascindex='0'-0x20+Mode;
		}
		for(tmp=0;tmp<200;tmp++)
			Refresh(&MyFont[ascindex][0]);//显示产生的随机模式序号
	}
	else{
		Mode=GetMode();//获取4位模式设定
	}
}

void Mode0(){//模式0，ASCII(+)(-)
	uchar skip=0;//按键越过判断变量
	uchar index=0x5F;
	while(1){
		if(skip==0){//判断按键
			if(Key1==0){
				if(index==0x5F){
					index=0;
				}
				else{
					index++;
				}
				skip=0x3F;
			}
			else if(Key2==0){
				if(index==0){
					index=0x5F;
				}
				else{
					index--;
				}
				skip=0x3F;
			}
		}
		Refresh(&MyFont[index][0]);//刷新图形
		if(skip!=0){//减小按键忽略计数
			skip--;
		}
	}
}

void Mode1(){//模式1，ASCII(随机)
	uchar skip=0;//按键越过判断变量
	uchar index=0x5F;
	while(1){
		if(skip==0){//判断按键
			if(Key1==0||Key2==0){
				index= TL1 %0x60;//通过Timer1的计数获取随机数
				skip=0x3F;
			}
		}
		Refresh(&MyFont[index][0]);//刷新图形
		if(skip!=0){//减小按键忽略计数
			skip--;
		}
	}
}

void Mode2(){//模式2，数字图形(随机)
	uchar skip=0;//按键越过判断变量
	uchar index=0;
	while(1){
		if(skip==0){//判断按键
			if(Key1==0||Key2==0){
				index= TL1 % NUMBERS_NUM;//通过Timer1的计数获取随机数
				skip=0x3F;
			}
		}
		Refresh(&Numbers[index][0]);//刷新图形
		if(skip!=0){//减小按键忽略计数
			skip--;
		}
	}
}

void Mode3(){//模式3，表情图形(随机)
	uchar skip=0;//按键越过判断变量
	uchar index=0;
	while(1){
	
		if(skip==0){//判断按键
			if(Key1==0||Key2==0){
				index= TL1 % MOOD_NUM;//通过Timer1的计数获取随机数
				skip=0x3F;
			}
		}
		Refresh(&Mood[index][0]);//刷新图形
		if(skip!=0){//减小按键忽略计数
			skip--;
		}
	}
}

void Mode4(){//模式4，图像图形(随机)
	uchar skip=0;//按键越过判断变量
	uchar index=0;
	while(1){
	
		if(skip==0){//判断按键
			if(Key1==0||Key2==0){
				index= TL1 % GRAPH_NUM;//通过Timer1的计数获取随机数
				skip=0x3F;
			}
		}
		Refresh(&Graph[index][0]);//刷新图形
		if(skip!=0){//减小按键忽略计数
			skip--;
		}
	}
}

void Mode5(){//模式5，动态图形(+)(-)
	uchar index=0;//按键越过判断变量
	uchar tmp;
	#define MODE5_NUMS 6
	while(1){
		if(index==0)
			tmp=PlayLED(Round,ROUND_NUM,1,0,0,SPEED_HIGH,ALWAYSSTAY);
		else if(index==1)
			tmp=PlayLED(Helix,HELIX_NUM,1,0,0,SPEED_HIGH,ALWAYSSTAY);
		else if(index==2)
			tmp=PlayLED(Note,NOTE_NUM,1,0,0,SPEED_HIGH,ALWAYSSTAY);
		else if(index==3)
			tmp=PlayLED(Heart,HEART_NUM,1,0,0,SPEED_HIGH,ALWAYSSTAY);
		else if(index==4)
			tmp=PlayLED(Stop,STOP_NUM,1,0,0,SPEED_HIGH,ALWAYSSTAY);
		else if(index==5)
			tmp=PlayLED(Wrong,WRONG_NUM,1,0,0,SPEED_HIGH,ALWAYSSTAY);

		if(tmp==1){//按键1，下一个
			if(index==MODE5_NUMS-1)
				index=0;
			else
				index++;
			MyDelay(1000);
		}
		else if(tmp==2){//按键2，重绘当前图形
			/*
			if(index==0)
				index=MODE5_NUMS-1;
			else
				index--;
			MyDelay(1000);
			*/
		}
	}
}

void Mode6(){//模式6，动态数字(模式1--一直循环一个)(模式2--一个完成显示下一个)
	uchar index=0;
	uchar tmp;
	uchar staytimes=ALWAYSSTAY;
	#define MODE6_NUMS	10
	while(1){
		if(index==0){
			tmp=PlayLED(Number0,NUMBER0_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==1){
			tmp=PlayLED(Number1,NUMBER1_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==2){
			tmp=PlayLED(Number2,NUMBER2_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==3){
			tmp=PlayLED(Number3,NUMBER3_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==4){
			tmp=PlayLED(Number4,NUMBER4_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==5){
			tmp=PlayLED(Number5,NUMBER5_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==6){
			tmp=PlayLED(Number6,NUMBER6_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==7){
			tmp=PlayLED(Number7,NUMBER7_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==8){
			tmp=PlayLED(Number8,NUMBER8_NUM,1,0,1,SPEED_HIGH,staytimes);
		}
		else if(index==9){
			tmp=PlayLED(Number9,NUMBER9_NUM,1,0,1,SPEED_HIGH,staytimes);
		}

		if(tmp==1){//一直显示一个数字，动态完成后静止
			staytimes=ALWAYSSTAY;
			MyDelay(1000);
		}
		else if(tmp==2){//一个数字刷完显示下一个
			staytimes=STAYTIMES;
			MyDelay(1000);
		}
		else{
			if(index==MODE6_NUMS-1){
				index=0;
			}
			else{
				index++;
			}
		}
	}
}

void Mode7(){//模式7，两帧动画(+)(-)
	uchar index=0;
	uchar tmp;
	while(1){
		tmp=PlayLED(Play2Frame[index],2,0,0,1,SPEED_LOW,ALWAYSSTAY);
		if(tmp==1){
			if(index==PLAYLED_NUM2-1)
				index=0;
			else
				index++;
			MyDelay(30000);
		}
		else if(tmp==2){
			if(index==0)
				index=PLAYLED_NUM2-1;
			else
				index--;
			MyDelay(30000);
		}
	}
}

void Mode8(){//模式8，四帧动画(+)(-)
	uchar index=0;
	uchar tmp;
	while(1){
		tmp=PlayLED(Play4Frame[index],4,0,0,1,SPEED_LOW,ALWAYSSTAY);
		if(tmp==1){
			if(index==PLAYLED_NUM4-1)
				index=0;
			else
				index++;
			MyDelay(30000);
		}
		else if(tmp==2){
			if(index==0)
				index=PLAYLED_NUM4-1;
			else
				index--;
			MyDelay(30000);
		}
	}
}

void Mode9(){//模式9，六帧动画(+)(-)
	uchar index=0;
	uchar tmp;
	while(1){
		tmp=PlayLED(Play6Frame[index],6,0,0,1,SPEED_LOW,ALWAYSSTAY);
		if(tmp==1){
			if(index==PLAYLED_NUM6-1)
				index=0;
			else
				index++;
			MyDelay(30000);
		}
		else if(tmp==2){
			if(index==0)
				index=PLAYLED_NUM6-1;
			else
				index--;
			MyDelay(30000);
		}
	}
}

void Mode10(){//模式10，DIY图形
	uchar i;
	for(i=0;i<8;i++){
		BufferLED[i]=0;//初始化缓冲
	}
	SetupBuf();
	MyDelay(30000);
	while(1){
		if(Key1==0||Key2==0){
			MyDelay(30000);
			SetupBuf();
			MyDelay(30000);
		}
		Refresh(BufferLED);//刷新
	}
}

void Mode11(){//模式11，DIY两帧动画
	#define FRAME2 2
	uchar i,j,freshtmp,ascindex,tmp;
	while(1){
		for(j=0;j<FRAME2;j++){
			ascindex='1'-0x20+j;
			for(freshtmp=0;freshtmp<200;freshtmp++)
				Refresh(&MyFont[ascindex][0]);//显示要设置的帧号
			for(i=0;i<8;i++){
				BufferLED[i]=0;//初始化缓冲
			}
			SetupBuf();
			for(i=0;i<8;i++){
				PlayBuf[j][i]=BufferLED[i];//把帧缓冲存入动画缓冲区
			}
		}
		MyDelay(30000);
		while(1){
			tmp=PlayLED(PlayBuf,FRAME2,0,0,1,SPEED_LOW,ALWAYSSTAY);
			if(tmp==2)break;//按下按键2，重新设定
		}
	}
}

void Mode12(){//模式12，DIY四帧动画
	#define FRAME4 4
	uchar i,j,freshtmp,ascindex,tmp;
	while(1){
		for(j=0;j<FRAME4;j++){
			ascindex='1'-0x20+j;
			for(freshtmp=0;freshtmp<200;freshtmp++)
				Refresh(&MyFont[ascindex][0]);//显示要设置的帧号
			for(i=0;i<8;i++){
				BufferLED[i]=0;//初始化缓冲
			}
			SetupBuf();
			for(i=0;i<8;i++){
				PlayBuf[j][i]=BufferLED[i];//把帧缓冲存入动画缓冲区
			}
		}
		MyDelay(30000);
		while(1){
			tmp=PlayLED(PlayBuf,FRAME4,0,0,1,SPEED_LOW,ALWAYSSTAY);
			if(tmp==2)break;//按下按键2，重新设定
		}
	}
}

void Mode13(){//模式13，DIY六帧动画
	#define FRAME6 6
	uchar i,j,freshtmp,ascindex,tmp;
	while(1){
		for(j=0;j<FRAME6;j++){
			ascindex='1'-0x20+j;
			for(freshtmp=0;freshtmp<200;freshtmp++)
				Refresh(&MyFont[ascindex][0]);//显示要设置的帧号
			for(i=0;i<8;i++){
				BufferLED[i]=0;//初始化缓冲
			}
			SetupBuf();
			for(i=0;i<8;i++){
				PlayBuf[j][i]=BufferLED[i];//把帧缓冲存入动画缓冲区
			}
		}
		MyDelay(30000);
		while(1){
			tmp=PlayLED(PlayBuf,FRAME6,0,0,1,SPEED_LOW,ALWAYSSTAY);
			if(tmp==2)break;//按下按键2，重新设定
		}
	}
}

void Mode14(){//模式14，走迷宫
	uchar i,tmp;
	char x,y;//走迷宫者的坐标
	uchar skip=0;
	uchar LastDer=0;//上次的移动方向
	uchar savedata;//保存正在修改的数据(因为需要闪烁)
	uchar FreshCnt=0;//刷新次数计数(用于判断闪烁)
	#define TIMES_ON	32	//亮的刷新次数
	#define TIMES_OFF	32	//灭的刷新次数
	#define TIMES_BLOCK	128	//堵住显示提示的刷新次数
	#define TIMES_OUT	250	//成功走出迷宫显示提示的刷新次数
	for(i=0;i<8;i++){
		BufferLED[i]=Maze[i];//初始化为默认迷宫
	}
	x=0;//设定起始坐标x
	y=0;//设定起始坐标y
	savedata=BufferLED[x];//保存数据(闪烁会修改BufferLED)
	while(1){
		if(skip==0){
			BufferLED[x]=savedata;
			if(Key1==0){//走迷宫
				SolveGo(x,y,LastDer);//获取可行走的方向
				if(GotoCnt==0){
					SolveGo(x,y,0);//获取可行走的方向
					if(GotoCnt==0){
						for(i=0;i<TIMES_BLOCK;i++){
							Refresh(&MyFont['B'-0x20][0]);//显示B(堵住...Block)
						}
					}
					else{
						tmp=TL1 % GotoCnt;//通过Timer1的计数获取随机可行走方向
						if(Goto[tmp]==1){
							x++;//向右
						}
						else if(Goto[tmp]==2){
							y++;//向下
						}
						else if(Goto[tmp]==3){
							x--;//向左
						}
						else if(Goto[tmp]==4){
							y--;//向上
						}
						LastDer=Goto[tmp];
					}
				}
				else{
					tmp=TL1 % GotoCnt;//通过Timer1的计数获取随机可行走方向
					if(Goto[tmp]==1){
						x++;//向右
					}
					else if(Goto[tmp]==2){
						y++;//向下
					}
					else if(Goto[tmp]==3){
						x--;//向左
					}
					else if(Goto[tmp]==4){
						y--;//向上
					}
					LastDer=Goto[tmp];
				}
				if(x==7 && y==7){//判断是否成功走出迷宫
					for(i=0;i<TIMES_OUT;i++){
						Refresh(&Mood[0x02][0]);//显示^_^
					}
				}
				if(x==0 && y==0){//判断是否回到原点
					for(i=0;i<TIMES_OUT;i++){
						Refresh(&Mood[0x01][0]);//显示-_-
					}
				}
				skip=0x3F;
			}
			else if(Key2==0){//手工重设迷宫
				MyDelay(30000);
				SetupBuf();
				BufferLED[x]&=~(1<<y);//腾出当前坐标
				skip=0x3F;
			}
			savedata=BufferLED[x];
		}
		if(FreshCnt<TIMES_ON){
			BufferLED[x]|=(1<<y);
		}
		else{
			BufferLED[x]&=~(1<<y);
		}
		FreshCnt++;
		if(FreshCnt>=TIMES_ON+TIMES_OFF){
			FreshCnt=0;
		}
		Refresh(BufferLED);//刷新
		if(skip!=0){//减小按键忽略计数
			skip--;
		}
	}
}

void Mode15(){//模式15,By 明
	uchar i;
	#define TIMES_ABOUT	128	//显示时间
	while(1){
		for(i=0;i<TIMES_ABOUT;i++){
			Refresh(&Graph[BY_INDEX][0]);//刷新图形
		}
		for(i=0;i<TIMES_ABOUT;i++){
			Refresh(&Graph[MING_INDEX][0]);//刷新图形
		}
	}
}

uchar GetMode(){
	uchar Mode;
	Mode=P3;
	Mode=Mode>>4;
	return Mode;
}

uchar PlayLED(const uchar figure[][8],const uchar num,uchar stop,uchar back,uchar drawret,uchar speed,uchar staytimes){//用于显示刷新动态图形
//const uchar figure[][8]  --  动态图形二维数组
//const uchar num  --  包含图像个数
//uchar stop  --  是否在刷新完停止在最后一帧
//uchar back  --  是否在动态图形显示完后返回
//uchar drawret  --  绘制图形时是否允许按键返回
//uchar speed  --  变换速度
//uchar staytimes  --  静态停留次数(为0时为无限次)
//返回值：0 -- 正常返回，1 -- 按键1按下，2 -- 按键2按下
	uchar i,j;
	while(1){
		for(i=0;i<num;i++){
			for(j=0;j<speed;j++){
				Refresh(&figure[i][0]);
				if(Key1==0 && drawret)return 1;
				if(Key2==0 && drawret)return 2;
			}
		}
		if(stop){
			if(back){
				return 0;
			}
			else{
				break;
			}
		}
	}
	i=num-1;
	while(1){
		Refresh(&figure[i][0]);
		if(Key1==0)return 1;
		if(Key2==0)return 2;
		if(back)break;
		if(staytimes>0){
			staytimes--;
			if(staytimes==0)break;
		}
	}
	return 0;
}

void Refresh(const uchar figure[]){//本函数用于刷新8x8LED点阵，参数为长度8的数组
	uchar i;
	for(i=0;i<8;i++){//刷新图形
		P2=0xFF;
		P0=figure[i];
		P2=~(1<<i);
		MyDelay(100);
	}
}

void SetupBuf(){
	uchar i=0;
	uchar j=0;
	uchar tmp,data4;//修改数据用的变量
	uchar skip=0;
	uchar savedata;//保存正在修改的数据(因为需要闪烁)
	uchar FreshCnt=0;
	#define TIMES_ON	32
	#define TIMES_OFF	32
	savedata=BufferLED[0];
	while(1){
		if(skip==0){
			if(Key1==0){
				BufferLED[i]=savedata;//恢复保存数据
				if(j==1){
					j=0;
					i++;
					if(i==8)
						return;
				}
				else{
					j++;
				}
				savedata=BufferLED[i];//保存下一个要修改的数据
				skip=0x3F;
				FreshCnt=0;
			}
			else if(Key2==0){
				BufferLED[i]=savedata;//恢复保存数据
				data4=GetMode();//获取4位开关
				if(j==1){
					data4=data4<<4;
					tmp=0x0F;
				}
				else{
					tmp=0xF0;
				}
				BufferLED[i]=(BufferLED[i] & tmp) | data4;
				if(j==1){
					j=0;
					i++;
					if(i==8)
						return;
				}
				else{
					j++;
				}
				savedata=BufferLED[i];//保存下一个要修改的数据
				skip=0x3F;
				FreshCnt=0;
			}
		}
		if(FreshCnt<TIMES_ON){
			if(j==0){
				BufferLED[i]|=0x0F;
			}
			else{
				BufferLED[i]|=0xF0;
			}
		}
		else{
			if(j==0){
				BufferLED[i]&=0xF0;
			}
			else{
				BufferLED[i]&=0x0F;
			}
		}
		FreshCnt++;
		if(FreshCnt>=TIMES_ON+TIMES_OFF){
			FreshCnt=0;
		}
		Refresh(BufferLED);//刷新
		if(skip!=0){//减小按键忽略计数
			skip--;
		}
	}
}

void MyDelay(uint tm){
	uint i;
	for(i=0;i<tm;i++)
		nop;
}

uchar CanGo(char x,char y){//判断坐标(x,y)是否可以走
	if(x<0||x>7)
		return 0;//x越界
	if(y<0||y>7)
		return 0;//y越界
	if(BufferLED[x]&(1<<y))
		return 0;//有障碍
	else
		return 1;//可通行
}

void SolveGo(char x,char y,uchar Last){//获取可行走的方向，参数Last为上次的移动方向
	GotoCnt=0;
	if(CanGo(x+1,y) && Last!=3){
		Goto[GotoCnt++]=1;
	}
	if(CanGo(x,y+1) && Last!=4){
		Goto[GotoCnt++]=2;
	}
	if(CanGo(x-1,y) && Last!=1){
		Goto[GotoCnt++]=3;
	}
	if(CanGo(x,y-1) && Last!=2){
		Goto[GotoCnt++]=4;
	}
}
