#ifndef __bsp_8080LCD_H__
	#define __bsp_8080LCD_H__
	void lcdInit(void);
	void lcdGetId(uint8_t *ID);
	void lcdWriteCmd(uint16_t cmd);
	void lcdDrawRectangle(void);
	void ILI9806G_Clear ( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight ,uint16_t color);
	uint16_t lcdReadData(void);
	void lcdChangeColor(void);
	void lcdOpenWindow( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight);
	void lcdDrawPixel( uint16_t usX, uint16_t usY ,uint16_t color);
#endif

#define 			ILI9806G_LESS_PIXEL	  		480			//Һ�����϶̷�������ؿ��
#define 			ILI9806G_MORE_PIXEL	 		800			//Һ�����ϳ���������ؿ��


#define      WHITE		 		                  0xFFFF	   //��ɫ
#define      BLACK                         0x0000	   //��ɫ 
#define      GREY                          0xF7DE	   //��ɫ 
#define      BLUE                          0x001F	   //��ɫ 
#define      BLUE2                         0x051F	   //ǳ��ɫ 
#define      RED                           0xF800	   //��ɫ 
#define      MAGENTA                       0xF81F	   //����ɫ�����ɫ 
#define      GREEN                         0x07E0	   //��ɫ 
#define      CYAN                          0x7FFF	   //����ɫ����ɫ 
#define      YELLOW                        0xFFE0	   //��ɫ 
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF

#define      CMD_SetCoordinateX		 		    0x2A	     //����X����
#define      CMD_SetCoordinateY		 		    0x2B	     //����Y����
#define      CMD_SetPixel		 		          0x2C	     //�������
