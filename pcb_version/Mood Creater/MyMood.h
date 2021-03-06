#ifndef _MYMOOD_H_
#define _MYMOOD_H_

//********************静态点阵********************//

#define MOOD_NUM 18
unsigned char code Mood[MOOD_NUM][8]={
	{0x00,0x36,0x36,0x00,0x00,0x41,0x22,0x1C},
	{0x04,0x04,0x44,0x40,0x40,0x44,0x04,0x04},
	{0x04,0x02,0x44,0x40,0x40,0x44,0x02,0x04},
	{0x04,0x02,0x24,0x40,0x40,0x24,0x02,0x04},
	{0x0A,0x0E,0x4A,0x40,0x40,0x4A,0x0E,0x0A},
	{0x0A,0x0A,0x4A,0x40,0x40,0x4A,0x0A,0x0A},
	{0x04,0xFC,0x44,0x40,0x40,0x44,0xFC,0x04},
	{0x02,0x04,0x42,0x40,0x40,0x42,0x04,0x02},
	{0x0A,0x04,0x4A,0x40,0x40,0x4A,0x04,0x0A},
	{0x00,0x04,0x40,0x40,0x40,0x40,0x04,0x00},
	{0x00,0x04,0x00,0x40,0x00,0x00,0x04,0x00},
	{0x00,0x04,0x40,0x40,0x40,0x40,0x04,0x00},
	{0x02,0x06,0x42,0x40,0x40,0x42,0x06,0x02},
	{0x0E,0x0A,0x4E,0x44,0x44,0x4E,0x0A,0x0E},
	{0x00,0x04,0x60,0xA0,0xA0,0x60,0x04,0x00},
	{0x04,0x04,0x64,0xA0,0xA0,0x64,0x04,0x04},
	{0x04,0x02,0x64,0xA0,0xA0,0x64,0x02,0x04},
	{0x02,0x06,0x02,0x40,0x00,0x02,0x06,0x02}
};

#define GRAPH_NUM 8
#define BY_INDEX 6
#define MING_INDEX 7
unsigned char code Graph[GRAPH_NUM][8]={
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x3C},//圆圈
	{0x3C,0x42,0x99,0xA5,0xB5,0x85,0x49,0x32},//螺旋
	{0x00,0x40,0xE0,0xE0,0x7F,0x02,0x04,0x04},//音符
	{0x00,0x0C,0x12,0x22,0x44,0x22,0x12,0x0C},//心型
	{0x3C,0x42,0xA1,0x91,0x89,0x85,0x42,0x3C},//停止标识
	{0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81},//错误符号
	{0x3E,0x2A,0x2A,0x14,0x80,0xB8,0xA0,0x78},//By
	{0x7C,0x54,0x7C,0x80,0x7F,0x15,0x95,0xFF}//明
};

#define NUMBERS_NUM 10
unsigned char code Numbers[NUMBERS_NUM][8]={
	{0x3C,0x42,0x81,0xBF,0xA3,0xBF,0x42,0x3C},//No.0
	{0x3C,0x42,0x81,0xA5,0xBF,0xA1,0x42,0x3C},//No.1
	{0x3C,0x42,0x81,0xBB,0xAB,0xAF,0x42,0x3C},//No.2
	{0x3C,0x42,0x81,0xAB,0xAB,0xBF,0x42,0x3C},//No.3
	{0x3C,0x42,0x81,0x8F,0x89,0xBF,0x42,0x3C},//No.4
	{0x3C,0x42,0x81,0xAF,0xAB,0xBB,0x42,0x3C},//No.5
	{0x3C,0x42,0x81,0xBF,0xAB,0xBB,0x42,0x3C},//No.6
	{0x3C,0x42,0x81,0x83,0x83,0xBF,0x42,0x3C},//No.7
	{0x3C,0x42,0x81,0xBF,0xAB,0xBF,0x42,0x3C},//No.8
	{0x3C,0x42,0x81,0xAF,0xAB,0xBF,0x42,0x3C},//No.9
};

//********************动态点阵********************//

#define ROUND_NUM 21
unsigned char code Round[ROUND_NUM][8] ={//生成圆圈
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x00},
	{0x00,0x00,0x00,0x00,0x01,0x01,0x02,0x00},
	{0x00,0x00,0x00,0x01,0x01,0x01,0x02,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x02,0x00},
	{0x00,0x02,0x01,0x01,0x01,0x01,0x02,0x00},
	{0x04,0x02,0x01,0x01,0x01,0x01,0x02,0x00},
	{0x0C,0x02,0x01,0x01,0x01,0x01,0x02,0x00},
	{0x1C,0x02,0x01,0x01,0x01,0x01,0x02,0x00},
	{0x3C,0x02,0x01,0x01,0x01,0x01,0x02,0x00},
	{0x3C,0x42,0x01,0x01,0x01,0x01,0x02,0x00},
	{0x3C,0x42,0x81,0x01,0x01,0x01,0x02,0x00},
	{0x3C,0x42,0x81,0x81,0x01,0x01,0x02,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x01,0x02,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x02,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x20},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x30},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x38},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x3C}
};

#define HELIX_NUM 29
unsigned char code Helix[HELIX_NUM][8] ={//生成螺旋
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02},
	{0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x02},
	{0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x02},
	{0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x02},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x00,0x02,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x04,0x02,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x0C,0x02,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x1C,0x02,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x3C,0x02,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x3C,0x42,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x3C,0x42,0x81,0x01,0x01,0x01,0x01,0x02},
	{0x3C,0x42,0x81,0x81,0x01,0x01,0x01,0x02},
	{0x3C,0x42,0x81,0x81,0x81,0x01,0x01,0x02},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x01,0x02},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x41,0x02},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x41,0x22},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x41,0x32},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x49,0x32},
	{0x3C,0x42,0x81,0x81,0x81,0x85,0x49,0x32},
	{0x3C,0x42,0x81,0x81,0x85,0x85,0x49,0x32},
	{0x3C,0x42,0x81,0x85,0x85,0x85,0x49,0x32},
	{0x3C,0x42,0x89,0x85,0x85,0x85,0x49,0x32},
	{0x3C,0x42,0x99,0x85,0x85,0x85,0x49,0x32},
	{0x3C,0x42,0x99,0xA5,0x85,0x85,0x49,0x32},
	{0x3C,0x42,0x99,0xA5,0xA5,0x85,0x49,0x32},
	{0x3C,0x42,0x99,0xA5,0xB5,0x85,0x49,0x32}
};

#define NOTE_NUM 18
unsigned char code Note[NOTE_NUM][8] ={//生成音符
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x40,0x40,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x40,0x60,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x00},
	{0x00,0x40,0x60,0x60,0x00,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0x60,0x00,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x00,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x40,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x60,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x70,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x78,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x7C,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x7E,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x7F,0x00,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x7F,0x02,0x00,0x00},
	{0x00,0x40,0xE0,0xE0,0x7F,0x02,0x04,0x00},
	{0x00,0x40,0xE0,0xE0,0x7F,0x02,0x04,0x04}
};

#define HEART_NUM 15
unsigned char code Heart[HEART_NUM][8] ={//生成心型
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x02,0x04,0x00,0x00,0x00},
	{0x00,0x00,0x02,0x02,0x04,0x00,0x00,0x00},
	{0x00,0x04,0x02,0x02,0x04,0x00,0x00,0x00},
	{0x00,0x0C,0x02,0x02,0x04,0x00,0x00,0x00},
	{0x00,0x0C,0x12,0x02,0x04,0x00,0x00,0x00},
	{0x00,0x0C,0x12,0x22,0x04,0x00,0x00,0x00},
	{0x00,0x0C,0x12,0x22,0x44,0x00,0x00,0x00},
	{0x00,0x0C,0x12,0x22,0x44,0x20,0x00,0x00},
	{0x00,0x0C,0x12,0x22,0x44,0x20,0x10,0x00},
	{0x00,0x0C,0x12,0x22,0x44,0x20,0x10,0x08},
	{0x00,0x0C,0x12,0x22,0x44,0x20,0x10,0x0C},
	{0x00,0x0C,0x12,0x22,0x44,0x20,0x12,0x0C},
	{0x00,0x0C,0x12,0x22,0x44,0x22,0x12,0x0C}
};

#define STOP_NUM 24
unsigned char code Stop[STOP_NUM][8] ={//生成停止标示
	{0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x02,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x04,0x02,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x0C,0x02,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x1C,0x02,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x3C,0x02,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x3C,0x42,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x3C,0x42,0x81,0x01,0x01,0x01,0x00,0x00},
	{0x3C,0x42,0x81,0x81,0x01,0x01,0x00,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x01,0x00,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x00,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x40,0x00},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x40,0x20},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x40,0x30},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x40,0x38},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x40,0x3C},
	{0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x81,0x81,0x85,0x42,0x3C},
	{0x3C,0x42,0x81,0x81,0x89,0x85,0x42,0x3C},
	{0x3C,0x42,0x81,0x91,0x89,0x85,0x42,0x3C},
	{0x3C,0x42,0xA1,0x91,0x89,0x85,0x42,0x3C}
};

#define WRONG_NUM 16
unsigned char code Wrong[WRONG_NUM][8] ={//生成错误符号
	{0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x01,0x02,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x01,0x02,0x04,0x00,0x00,0x00,0x00,0x00},
	{0x01,0x02,0x04,0x08,0x00,0x00,0x00,0x00},
	{0x01,0x02,0x04,0x08,0x10,0x00,0x00,0x00},
	{0x01,0x02,0x04,0x08,0x10,0x20,0x00,0x00},
	{0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x00},
	{0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80},
	{0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x81},
	{0x01,0x02,0x04,0x08,0x10,0x20,0x42,0x81},
	{0x01,0x02,0x04,0x08,0x10,0x24,0x42,0x81},
	{0x01,0x02,0x04,0x08,0x18,0x24,0x42,0x81},
	{0x01,0x02,0x04,0x18,0x18,0x24,0x42,0x81},
	{0x01,0x02,0x24,0x18,0x18,0x24,0x42,0x81},
	{0x01,0x42,0x24,0x18,0x18,0x24,0x42,0x81},
	{0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81}
};

#define NUMBER0_NUM	12
unsigned char code Number0[NUMBER0_NUM][8] ={//No.0
	{0x3C,0x42,0x81,0x81,0x81,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x81,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x87,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x9F,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xA3,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xB3,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xBB,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xBF,0x42,0x3C}
};

#define NUMBER1_NUM	8
unsigned char code Number1[NUMBER1_NUM][8] ={//No.1
	{0x3C,0x42,0x81,0x85,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x85,0x83,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x85,0x87,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x85,0x8F,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x85,0x9F,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0xA5,0x9F,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0xA5,0xBF,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0xA5,0xBF,0xA1,0x42,0x3C}
};

#define NUMBER2_NUM	11
unsigned char code Number2[NUMBER2_NUM][8] ={//No.2
	{0x3C,0x42,0x81,0x83,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x87,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x8B,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8B,0x8B,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x9B,0x8B,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0xBB,0x8B,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0xBB,0xAB,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0xBB,0xAB,0xAF,0x42,0x3C}
};

#define NUMBER3_NUM	11
unsigned char code Number3[NUMBER3_NUM][8] ={//No.3
	{0x3C,0x42,0x81,0x83,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x87,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x8B,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8B,0x8B,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8B,0x8B,0x9F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8B,0x8B,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0x8B,0xAB,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0xAB,0xAB,0xBF,0x42,0x3C}
};

#define NUMBER4_NUM	9
unsigned char code Number4[NUMBER4_NUM][8] ={//No.4
	{0x3C,0x42,0x81,0x83,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x87,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x89,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x89,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x89,0x87,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x89,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x89,0x9F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x89,0xBF,0x42,0x3C}
};

#define NUMBER5_NUM	11
unsigned char code Number5[NUMBER5_NUM][8] ={//No.5
	{0x3C,0x42,0x81,0x81,0x81,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x81,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x87,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x8B,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x9B,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0xBB,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0xAB,0xBB,0x42,0x3C},
	{0x3C,0x42,0x81,0xAF,0xAB,0xBB,0x42,0x3C}
};

#define NUMBER6_NUM	12
unsigned char code Number6[NUMBER6_NUM][8] ={//No.6
	{0x3C,0x42,0x81,0x81,0x81,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x81,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x87,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x9F,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xA3,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xB3,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xBB,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xAB,0xBB,0x42,0x3C}
};

#define NUMBER7_NUM	7
unsigned char code Number7[NUMBER7_NUM][8] ={//No.7
	{0x3C,0x42,0x81,0x83,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x87,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x9F,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0xBF,0x42,0x3C}
};

#define NUMBER8_NUM	13
unsigned char code Number8[NUMBER8_NUM][8] ={//No.8
	{0x3C,0x42,0x81,0x83,0x81,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x87,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0x9F,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0x83,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0x83,0xA3,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0xA3,0xA3,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0xB3,0xA3,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0xBB,0xA3,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xA3,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0xBF,0xAB,0xBF,0x42,0x3C}
};

#define NUMBER9_NUM	12
unsigned char code Number9[NUMBER9_NUM][8] ={//No.9
	{0x3C,0x42,0x81,0x81,0x89,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x89,0x89,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x8D,0x89,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x89,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x81,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x83,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x87,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x8F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0x9F,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0x8B,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0x8F,0xAB,0xBF,0x42,0x3C},
	{0x3C,0x42,0x81,0xAF,0xAB,0xBF,0x42,0x3C}
};

#define PLAYLED_NUM2 16
unsigned char code Play2Frame[PLAYLED_NUM2][2][8] ={//2帧动画
	{//方向(左上1)
		{0x07,0x03,0x05,0x08,0x10,0x20,0x40,0x00},
		{0x00,0x0E,0x06,0x0A,0x10,0x20,0x40,0x80}
	},
	{//方向(左上2)
		{0x07,0x01,0x1D,0x04,0x74,0x10,0x10,0x00},
		{0x00,0x0E,0x02,0x3A,0x08,0xE8,0x20,0x20}
	},
	{//方向(右上1)
		{0x00,0x40,0x20,0x10,0x08,0x05,0x03,0x07},
		{0x80,0x40,0x20,0x10,0x0A,0x06,0x0E,0x00}
	},
	{//方向(右上2)
		{0x00,0x10,0x10,0x74,0x04,0x1D,0x01,0x07},
		{0x20,0x20,0xE8,0x08,0x3A,0x02,0x0E,0x00}
	},
	{//方向(左下1)
		{0xE0,0xC0,0xA0,0x10,0x08,0x04,0x02,0x00},
		{0x00,0x70,0x60,0x50,0x08,0x04,0x02,0x01}
	},
	{//方向(左下2)
		{0xE0,0x80,0xB8,0x20,0x2E,0x08,0x08,0x00},
		{0x00,0x70,0x40,0x5C,0x10,0x17,0x04,0x04}
	},
	{//方向(右下1)
		{0x00,0x02,0x04,0x08,0x10,0xA0,0xC0,0xE0},
		{0x01,0x02,0x04,0x08,0x50,0x60,0x70,0x00}
	},
	{//方向(右下2)
		{0x00,0x08,0x08,0x2E,0x20,0xB8,0x80,0xE0},
		{0x04,0x04,0x17,0x10,0x5C,0x40,0x70,0x00}
	},
	{//方向(上)
		{0x00,0x04,0x02,0x7F,0x02,0x04,0x00,0x00},
		{0x00,0x08,0x04,0xFE,0x04,0x08,0x00,0x00}
	},
	{//方向(下)
		{0x00,0x20,0x40,0xFE,0x40,0x20,0x00,0x00},
		{0x00,0x10,0x20,0x7F,0x20,0x10,0x00,0x00}
	},
	{//方向(右)
		{0x00,0x08,0x08,0x08,0x08,0x2A,0x1C,0x08},
		{0x08,0x08,0x08,0x08,0x2A,0x1C,0x08,0x00}
	},
	{//方向(左)
		{0x08,0x1C,0x2A,0x08,0x08,0x08,0x08,0x00},
		{0x00,0x08,0x1C,0x2A,0x08,0x08,0x08,0x08}
	},
	{//头撞地
		{0x70,0x70,0x70,0x20,0xE0,0x20,0xE0,0x80},
		{0xE0,0xE0,0xE0,0x40,0xE0,0x10,0xF0,0x80}
	},
	{//点头
		{0x00,0x00,0x20,0xD7,0x3F,0xD7,0x20,0x00},
		{0x00,0x00,0x20,0xDE,0x3E,0xDE,0x20,0x00}
	},
	{//下蹲
		{0x00,0x10,0x57,0xBF,0x57,0x10,0x00,0x00},
		{0x00,0x40,0xAE,0xFE,0xAE,0x40,0x00,0x00}
	},
	{//左右摇摆
		{0x00,0x20,0xD7,0x3F,0x57,0xA0,0x00,0x00},
		{0x00,0x00,0xA0,0x57,0x3F,0xD7,0x20,0x00}
	}
};

#define PLAYLED_NUM4 5
unsigned char code Play4Frame[PLAYLED_NUM4][4][8] ={//4帧动画
	{//风车
		{0x04,0x08,0x90,0x5C,0x3A,0x09,0x10,0x20},
		{0x83,0x84,0x48,0x38,0x1C,0x12,0x21,0xC1},
		{0x40,0x47,0x48,0x38,0x1C,0x12,0xE2,0x02},
		{0x08,0x10,0x10,0x9E,0x79,0x08,0x08,0x10}
	},
	{//四点集中
		{0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x81},
		{0x00,0x42,0x00,0x00,0x00,0x00,0x42,0x00},
		{0x00,0x00,0x24,0x00,0x00,0x24,0x00,0x00},
		{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00}
	},
	{//挥双手
		{0x00,0x00,0x20,0xD7,0x3F,0xD7,0x20,0x00},
		{0x00,0x00,0x10,0xD7,0x3F,0xD7,0x10,0x00},
		{0x00,0x00,0x08,0xD7,0x3F,0xD7,0x08,0x00},
		{0x00,0x00,0x10,0xD7,0x3F,0xD7,0x10,0x00}
	},
	{//挥单手
		{0x00,0x00,0x20,0xD7,0x3F,0xD7,0x20,0x00},
		{0x00,0x00,0x10,0xD7,0x3F,0xD7,0x20,0x00},
		{0x00,0x00,0x08,0xD7,0x3F,0xD7,0x20,0x00},
		{0x00,0x00,0x10,0xD7,0x3F,0xD7,0x20,0x00}
	},
	{//旋转~~
		{0x00,0x10,0x57,0xBF,0x57,0x10,0x00,0x00},
		{0x00,0x00,0x17,0xFF,0x17,0x00,0x00,0x00},
		{0x00,0x00,0x07,0xFF,0x07,0x00,0x00,0x00},
		{0x00,0x00,0x17,0xFF,0x17,0x00,0x00,0x00}
	}
};


#define PLAYLED_NUM6 5
unsigned char code Play6Frame[PLAYLED_NUM6][6][8] ={//6帧动画
	{//四方展开
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x04,0x04,0x04,0x00,0x00,0x00},
		{0x00,0x00,0x04,0x04,0x04,0x1C,0x00,0x00},
		{0x00,0x00,0x04,0x24,0x24,0x3C,0x00,0x00},
		{0x00,0x00,0x3C,0x24,0x24,0x3C,0x00,0x00},
		{0x00,0x3C,0x42,0x42,0x42,0x42,0x3C,0x00}
	},
	{//压缩
		{0x00,0x00,0x3C,0x24,0x24,0x3C,0x00,0x00},
		{0xE7,0x81,0xBD,0x24,0x24,0xBD,0x81,0xE7},
		{0x00,0x66,0x7E,0x24,0x24,0x7E,0x66,0x00},
		{0x00,0x00,0x24,0x18,0x18,0x24,0x00,0x00},
		{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
	},
	{//摇摆~~挥手~~
		{0x00,0x00,0xA0,0x57,0x3F,0xD7,0x20,0x00},
		{0x00,0x00,0xA0,0x57,0x3F,0xD7,0x08,0x00},
		{0x00,0x00,0xA0,0x57,0x3F,0xD7,0x20,0x00},
		{0x00,0x20,0xD7,0x3F,0x57,0xA0,0x00,0x00},
		{0x00,0x08,0xD7,0x3F,0x57,0xA0,0x00,0x00},
		{0x00,0x20,0xD7,0x3F,0x57,0xA0,0x00,0x00}
	},
	{//扔小球
		{0x00,0x20,0xD7,0x3F,0xD7,0x20,0x00,0x00},
		{0x00,0x20,0xD7,0x3F,0xD7,0x10,0x00,0x00},
		{0x00,0x20,0xD7,0x3F,0xD7,0x18,0x00,0x00},
		{0x00,0x20,0xD7,0x3F,0xD7,0x14,0x00,0x00},
		{0x00,0x20,0xD7,0x3F,0xD7,0x18,0x00,0x00},
		{0x00,0x20,0xD7,0x3F,0xD7,0x10,0x00,0x00}
	},
	{//爆头(中弹)
		{0x00,0x20,0xD7,0x3F,0xD7,0x20,0x00,0x00},
		{0x00,0x20,0xD7,0x3F,0xD7,0x20,0x02,0x02},
		{0x00,0x20,0xD7,0x3F,0xD7,0x22,0x02,0x00},
		{0x07,0x27,0xD7,0x3A,0xD2,0x20,0x00,0x00},
		{0x07,0x22,0xD2,0x38,0xD0,0x20,0x00,0x00},
		{0x00,0x20,0xD0,0x38,0xD0,0x20,0x00,0x00}
	}
};

#endif //end of _MYMOOD_H_
