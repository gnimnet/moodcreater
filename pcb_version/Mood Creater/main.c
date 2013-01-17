#include "at89x52.h"
#include "intrins.h"
#include "MyFont(ASCII).h"
#include "MyMood.h"
#include "Welcome.h"

#define uchar unsigned char
#define uint unsigned int
#define nop _nop_()

sbit Key1=P3^0;//����1
sbit Key2=P3^1;//����2

/**********ģʽ��Ӧ����**********/
void Mode0();//ģʽ0��ASCII(+)(-)
void Mode1();//ģʽ1��ASCII(���)
void Mode2();//ģʽ2������ͼ��(���)
void Mode3();//ģʽ3������ͼ��(���)
void Mode4();//ģʽ4��ͼ��ͼ��(���)
void Mode5();//ģʽ5����̬ͼ��(+)(-)
void Mode6();//ģʽ6����̬����(ģʽ1--һֱѭ��һ��)(ģʽ2--һ�������ʾ��һ��)
void Mode7();//ģʽ7����֡����(+)(-)
void Mode8();//ģʽ8����֡����(+)(-)
void Mode9();//ģʽ9����֡����(+)(-)
void Mode10();//ģʽ10��DIYͼ��
void Mode11();//ģʽ11��DIY��֡����
void Mode12();//ģʽ12��DIY��֡����
void Mode13();//ģʽ13��DIY��֡����
void Mode14();//ģʽ14�����Թ�
void Mode15();//ģʽ15,By ��

//PlayLED��ز�����
#define SPEED_LOW		16	//���٣�����N֡����
#define SPEED_MEDIUM	12	//����
#define SPEED_HIGH		8	//���٣�����ͼ������

#define ALWAYSSTAY	0	//һֱͣ��
#define STAYTIMES	32	//ͣ��32��

/**********ͨ�ú���**********/
uchar GetMode();//��ȡ4bitģʽ(��4λ���ػ�ȡ)
uchar PlayLED(const uchar figure[][8],const uchar num,uchar stop,uchar back,uchar drawret,uchar speed,uchar staytimes);//������ʾˢ�¶�̬ͼ��
void Refresh(const uchar figure[]);//ˢ�µ�����
void SetupBuf();//ͨ��4λ���ػ�ȡLED����(4*16��)
void MyDelay(uint tm);//��ʱ����
void DoWelcome();//��ӭ����

/**********�Թ�����**********/
uchar CanGo(char x,char y);//�ж�����(x,y)�Ƿ������
void SolveGo(char x,char y,uchar Last);//��ȡ�����ߵķ��򣬲���LastΪ�ϴε��ƶ�����

/**********ȫ�ֱ���**********/
uchar BufferLED[8];//��ʾ����
uchar PlayBuf[6][8];//DIY��������
uchar code Maze[8]={0x22,0x6A,0x28,0x0F,0xE0,0x0A,0x7A,0x42};//Ĭ���Թ�
uchar Goto[4];//���߷���(���ڼ���)
uchar GotoCnt;//��¼�����ߵķ������
uchar Mode;//����ģʽ

void main(){
	MyDelay(1000);//�ӳٵȴ���Դƽ��
	TMOD=0x21;//Timer1Ϊ8λ�Զ�����(��Ϊ�����������)
	TCON=0x40;//Timer1����
	DoWelcome();//��ʾ��ӭ����ͬʱ��ȡ����ģʽ
	while(1){
		if(Mode==0){//ģʽ0��ASCII(+)(-)
			Mode0();//Never Return
		}
		else if(Mode==1){//ģʽ1��ASCII(���)
			Mode1();//Never Return
		}
		else if(Mode==2){//ģʽ2������ͼ��(���)
			Mode2();//Never Return
		}
		else if(Mode==3){//ģʽ3������ͼ��(���)
			Mode3();//Never Return
		}
		else if(Mode==4){//ģʽ4��ͼ��ͼ��(���)
			Mode4();//Never Return
		}
		else if(Mode==5){//ģʽ5����̬ͼ��(+)(-)
			Mode5();//Never Return
		}
		else if(Mode==6){//ģʽ6����̬����(ģʽ1--һֱѭ��һ��)(ģʽ2--һ�������ʾ��һ��)
			Mode6();//Never Return
		}
		else if(Mode==7){//ģʽ7����֡����(+)(-)
			Mode7();//Never Return
		}
		else if(Mode==8){//ģʽ8����֡����(+)(-)
			Mode8();//Never Return
		}
		else if(Mode==9){//ģʽ9����֡����(+)(-)
			Mode9();//Never Return
		}
		else if(Mode==10){//ģʽ10��DIYͼ��
			Mode10();//Never Return
		}
		else if(Mode==11){//ģʽ11��DIY��֡����
			Mode11();//Never Return
		}
		else if(Mode==12){//ģʽ12��DIY��֡����
			Mode12();//Never Return
		}
		else if(Mode==13){//ģʽ13��DIY��֡����
			Mode13();//Never Return
		}
		else if(Mode==14){//ģʽ14�����Թ�
			Mode14();//Never Return
		}
		else if(Mode==15){//ģʽ15,By ��
			Mode15();//Never Return
		}
	}
}

void DoWelcome(){//��ӭ����
	uchar tmp;
	uchar ascindex;
	tmp=PlayLED(Welcome,WELCOME_NUM,1,0,1,SPEED_LOW,ALWAYSSTAY);//���Զ����أ��ȴ�����
	if(tmp==1){//����1����4λ���ػ�ȡģʽ
		Mode=GetMode();//��ȡ4λģʽ�趨
	}
	else if(tmp==2){//����2���������ģʽ
		Mode= TL1 % 0x10;//ͨ��Timer1�ļ�����ȡ��������õ�����ģʽ
		if(Mode>9){
			ascindex='A'-0x20-10+Mode;
		}
		else{
			ascindex='0'-0x20+Mode;
		}
		for(tmp=0;tmp<200;tmp++)
			Refresh(&MyFont[ascindex][0]);//��ʾ���������ģʽ���
	}
	else{
		Mode=GetMode();//��ȡ4λģʽ�趨
	}
}

void Mode0(){//ģʽ0��ASCII(+)(-)
	uchar skip=0;//����Խ���жϱ���
	uchar index=0x5F;
	while(1){
		if(skip==0){//�жϰ���
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
		Refresh(&MyFont[index][0]);//ˢ��ͼ��
		if(skip!=0){//��С�������Լ���
			skip--;
		}
	}
}

void Mode1(){//ģʽ1��ASCII(���)
	uchar skip=0;//����Խ���жϱ���
	uchar index=0x5F;
	while(1){
		if(skip==0){//�жϰ���
			if(Key1==0||Key2==0){
				index= TL1 %0x60;//ͨ��Timer1�ļ�����ȡ�����
				skip=0x3F;
			}
		}
		Refresh(&MyFont[index][0]);//ˢ��ͼ��
		if(skip!=0){//��С�������Լ���
			skip--;
		}
	}
}

void Mode2(){//ģʽ2������ͼ��(���)
	uchar skip=0;//����Խ���жϱ���
	uchar index=0;
	while(1){
		if(skip==0){//�жϰ���
			if(Key1==0||Key2==0){
				index= TL1 % NUMBERS_NUM;//ͨ��Timer1�ļ�����ȡ�����
				skip=0x3F;
			}
		}
		Refresh(&Numbers[index][0]);//ˢ��ͼ��
		if(skip!=0){//��С�������Լ���
			skip--;
		}
	}
}

void Mode3(){//ģʽ3������ͼ��(���)
	uchar skip=0;//����Խ���жϱ���
	uchar index=0;
	while(1){
	
		if(skip==0){//�жϰ���
			if(Key1==0||Key2==0){
				index= TL1 % MOOD_NUM;//ͨ��Timer1�ļ�����ȡ�����
				skip=0x3F;
			}
		}
		Refresh(&Mood[index][0]);//ˢ��ͼ��
		if(skip!=0){//��С�������Լ���
			skip--;
		}
	}
}

void Mode4(){//ģʽ4��ͼ��ͼ��(���)
	uchar skip=0;//����Խ���жϱ���
	uchar index=0;
	while(1){
	
		if(skip==0){//�жϰ���
			if(Key1==0||Key2==0){
				index= TL1 % GRAPH_NUM;//ͨ��Timer1�ļ�����ȡ�����
				skip=0x3F;
			}
		}
		Refresh(&Graph[index][0]);//ˢ��ͼ��
		if(skip!=0){//��С�������Լ���
			skip--;
		}
	}
}

void Mode5(){//ģʽ5����̬ͼ��(+)(-)
	uchar index=0;//����Խ���жϱ���
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

		if(tmp==1){//����1����һ��
			if(index==MODE5_NUMS-1)
				index=0;
			else
				index++;
			MyDelay(1000);
		}
		else if(tmp==2){//����2���ػ浱ǰͼ��
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

void Mode6(){//ģʽ6����̬����(ģʽ1--һֱѭ��һ��)(ģʽ2--һ�������ʾ��һ��)
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

		if(tmp==1){//һֱ��ʾһ�����֣���̬��ɺ�ֹ
			staytimes=ALWAYSSTAY;
			MyDelay(1000);
		}
		else if(tmp==2){//һ������ˢ����ʾ��һ��
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

void Mode7(){//ģʽ7����֡����(+)(-)
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

void Mode8(){//ģʽ8����֡����(+)(-)
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

void Mode9(){//ģʽ9����֡����(+)(-)
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

void Mode10(){//ģʽ10��DIYͼ��
	uchar i;
	for(i=0;i<8;i++){
		BufferLED[i]=0;//��ʼ������
	}
	SetupBuf();
	MyDelay(30000);
	while(1){
		if(Key1==0||Key2==0){
			MyDelay(30000);
			SetupBuf();
			MyDelay(30000);
		}
		Refresh(BufferLED);//ˢ��
	}
}

void Mode11(){//ģʽ11��DIY��֡����
	#define FRAME2 2
	uchar i,j,freshtmp,ascindex,tmp;
	while(1){
		for(j=0;j<FRAME2;j++){
			ascindex='1'-0x20+j;
			for(freshtmp=0;freshtmp<200;freshtmp++)
				Refresh(&MyFont[ascindex][0]);//��ʾҪ���õ�֡��
			for(i=0;i<8;i++){
				BufferLED[i]=0;//��ʼ������
			}
			SetupBuf();
			for(i=0;i<8;i++){
				PlayBuf[j][i]=BufferLED[i];//��֡������붯��������
			}
		}
		MyDelay(30000);
		while(1){
			tmp=PlayLED(PlayBuf,FRAME2,0,0,1,SPEED_LOW,ALWAYSSTAY);
			if(tmp==2)break;//���°���2�������趨
		}
	}
}

void Mode12(){//ģʽ12��DIY��֡����
	#define FRAME4 4
	uchar i,j,freshtmp,ascindex,tmp;
	while(1){
		for(j=0;j<FRAME4;j++){
			ascindex='1'-0x20+j;
			for(freshtmp=0;freshtmp<200;freshtmp++)
				Refresh(&MyFont[ascindex][0]);//��ʾҪ���õ�֡��
			for(i=0;i<8;i++){
				BufferLED[i]=0;//��ʼ������
			}
			SetupBuf();
			for(i=0;i<8;i++){
				PlayBuf[j][i]=BufferLED[i];//��֡������붯��������
			}
		}
		MyDelay(30000);
		while(1){
			tmp=PlayLED(PlayBuf,FRAME4,0,0,1,SPEED_LOW,ALWAYSSTAY);
			if(tmp==2)break;//���°���2�������趨
		}
	}
}

void Mode13(){//ģʽ13��DIY��֡����
	#define FRAME6 6
	uchar i,j,freshtmp,ascindex,tmp;
	while(1){
		for(j=0;j<FRAME6;j++){
			ascindex='1'-0x20+j;
			for(freshtmp=0;freshtmp<200;freshtmp++)
				Refresh(&MyFont[ascindex][0]);//��ʾҪ���õ�֡��
			for(i=0;i<8;i++){
				BufferLED[i]=0;//��ʼ������
			}
			SetupBuf();
			for(i=0;i<8;i++){
				PlayBuf[j][i]=BufferLED[i];//��֡������붯��������
			}
		}
		MyDelay(30000);
		while(1){
			tmp=PlayLED(PlayBuf,FRAME6,0,0,1,SPEED_LOW,ALWAYSSTAY);
			if(tmp==2)break;//���°���2�������趨
		}
	}
}

void Mode14(){//ģʽ14�����Թ�
	uchar i,tmp;
	char x,y;//���Թ��ߵ�����
	uchar skip=0;
	uchar LastDer=0;//�ϴε��ƶ�����
	uchar savedata;//���������޸ĵ�����(��Ϊ��Ҫ��˸)
	uchar FreshCnt=0;//ˢ�´�������(�����ж���˸)
	#define TIMES_ON	32	//����ˢ�´���
	#define TIMES_OFF	32	//���ˢ�´���
	#define TIMES_BLOCK	128	//��ס��ʾ��ʾ��ˢ�´���
	#define TIMES_OUT	250	//�ɹ��߳��Թ���ʾ��ʾ��ˢ�´���
	for(i=0;i<8;i++){
		BufferLED[i]=Maze[i];//��ʼ��ΪĬ���Թ�
	}
	x=0;//�趨��ʼ����x
	y=0;//�趨��ʼ����y
	savedata=BufferLED[x];//��������(��˸���޸�BufferLED)
	while(1){
		if(skip==0){
			BufferLED[x]=savedata;
			if(Key1==0){//���Թ�
				SolveGo(x,y,LastDer);//��ȡ�����ߵķ���
				if(GotoCnt==0){
					SolveGo(x,y,0);//��ȡ�����ߵķ���
					if(GotoCnt==0){
						for(i=0;i<TIMES_BLOCK;i++){
							Refresh(&MyFont['B'-0x20][0]);//��ʾB(��ס...Block)
						}
					}
					else{
						tmp=TL1 % GotoCnt;//ͨ��Timer1�ļ�����ȡ��������߷���
						if(Goto[tmp]==1){
							x++;//����
						}
						else if(Goto[tmp]==2){
							y++;//����
						}
						else if(Goto[tmp]==3){
							x--;//����
						}
						else if(Goto[tmp]==4){
							y--;//����
						}
						LastDer=Goto[tmp];
					}
				}
				else{
					tmp=TL1 % GotoCnt;//ͨ��Timer1�ļ�����ȡ��������߷���
					if(Goto[tmp]==1){
						x++;//����
					}
					else if(Goto[tmp]==2){
						y++;//����
					}
					else if(Goto[tmp]==3){
						x--;//����
					}
					else if(Goto[tmp]==4){
						y--;//����
					}
					LastDer=Goto[tmp];
				}
				if(x==7 && y==7){//�ж��Ƿ�ɹ��߳��Թ�
					for(i=0;i<TIMES_OUT;i++){
						Refresh(&Mood[0x02][0]);//��ʾ^_^
					}
				}
				if(x==0 && y==0){//�ж��Ƿ�ص�ԭ��
					for(i=0;i<TIMES_OUT;i++){
						Refresh(&Mood[0x01][0]);//��ʾ-_-
					}
				}
				skip=0x3F;
			}
			else if(Key2==0){//�ֹ������Թ�
				MyDelay(30000);
				SetupBuf();
				BufferLED[x]&=~(1<<y);//�ڳ���ǰ����
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
		Refresh(BufferLED);//ˢ��
		if(skip!=0){//��С�������Լ���
			skip--;
		}
	}
}

void Mode15(){//ģʽ15,By ��
	uchar i;
	#define TIMES_ABOUT	128	//��ʾʱ��
	while(1){
		for(i=0;i<TIMES_ABOUT;i++){
			Refresh(&Graph[BY_INDEX][0]);//ˢ��ͼ��
		}
		for(i=0;i<TIMES_ABOUT;i++){
			Refresh(&Graph[MING_INDEX][0]);//ˢ��ͼ��
		}
	}
}

uchar GetMode(){
	uchar Mode;
	Mode=P3;
	Mode=Mode>>4;
	return Mode;
}

uchar PlayLED(const uchar figure[][8],const uchar num,uchar stop,uchar back,uchar drawret,uchar speed,uchar staytimes){//������ʾˢ�¶�̬ͼ��
//const uchar figure[][8]  --  ��̬ͼ�ζ�ά����
//const uchar num  --  ����ͼ�����
//uchar stop  --  �Ƿ���ˢ����ֹͣ�����һ֡
//uchar back  --  �Ƿ��ڶ�̬ͼ����ʾ��󷵻�
//uchar drawret  --  ����ͼ��ʱ�Ƿ�����������
//uchar speed  --  �任�ٶ�
//uchar staytimes  --  ��̬ͣ������(Ϊ0ʱΪ���޴�)
//����ֵ��0 -- �������أ�1 -- ����1���£�2 -- ����2����
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

void Refresh(const uchar figure[]){//����������ˢ��8x8LED���󣬲���Ϊ����8������
	uchar i;
	for(i=0;i<8;i++){//ˢ��ͼ��
		P2=0xFF;
		P0=figure[i];
		P2=~(1<<i);
		MyDelay(100);
	}
}

void SetupBuf(){
	uchar i=0;
	uchar j=0;
	uchar tmp,data4;//�޸������õı���
	uchar skip=0;
	uchar savedata;//���������޸ĵ�����(��Ϊ��Ҫ��˸)
	uchar FreshCnt=0;
	#define TIMES_ON	32
	#define TIMES_OFF	32
	savedata=BufferLED[0];
	while(1){
		if(skip==0){
			if(Key1==0){
				BufferLED[i]=savedata;//�ָ���������
				if(j==1){
					j=0;
					i++;
					if(i==8)
						return;
				}
				else{
					j++;
				}
				savedata=BufferLED[i];//������һ��Ҫ�޸ĵ�����
				skip=0x3F;
				FreshCnt=0;
			}
			else if(Key2==0){
				BufferLED[i]=savedata;//�ָ���������
				data4=GetMode();//��ȡ4λ����
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
				savedata=BufferLED[i];//������һ��Ҫ�޸ĵ�����
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
		Refresh(BufferLED);//ˢ��
		if(skip!=0){//��С�������Լ���
			skip--;
		}
	}
}

void MyDelay(uint tm){
	uint i;
	for(i=0;i<tm;i++)
		nop;
}

uchar CanGo(char x,char y){//�ж�����(x,y)�Ƿ������
	if(x<0||x>7)
		return 0;//xԽ��
	if(y<0||y>7)
		return 0;//yԽ��
	if(BufferLED[x]&(1<<y))
		return 0;//���ϰ�
	else
		return 1;//��ͨ��
}

void SolveGo(char x,char y,uchar Last){//��ȡ�����ߵķ��򣬲���LastΪ�ϴε��ƶ�����
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
