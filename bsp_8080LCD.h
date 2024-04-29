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

#define 			ILI9806G_LESS_PIXEL	  		480			//液晶屏较短方向的像素宽度
#define 			ILI9806G_MORE_PIXEL	 		800			//液晶屏较长方向的像素宽度


#define      WHITE		 		                  0xFFFF	   //白色
#define      BLACK                         0x0000	   //黑色 
#define      GREY                          0xF7DE	   //灰色 
#define      BLUE                          0x001F	   //蓝色 
#define      BLUE2                         0x051F	   //浅蓝色 
#define      RED                           0xF800	   //红色 
#define      MAGENTA                       0xF81F	   //红紫色，洋红色 
#define      GREEN                         0x07E0	   //绿色 
#define      CYAN                          0x7FFF	   //蓝绿色，青色 
#define      YELLOW                        0xFFE0	   //黄色 
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF

#define      CMD_SetCoordinateX		 		    0x2A	     //设置X坐标
#define      CMD_SetCoordinateY		 		    0x2B	     //设置Y坐标
#define      CMD_SetPixel		 		          0x2C	     //填充像素
