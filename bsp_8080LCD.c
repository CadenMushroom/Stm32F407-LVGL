#include "stm32f4xx.h"                  // Device header
#include "bsp_8080LCD.h" 
#include "main.h"
#include "gpio.h"
#include "fsmc.h"

uint16_t LCD_X_LENGTH = ILI9806G_MORE_PIXEL;
uint16_t LCD_Y_LENGTH = ILI9806G_LESS_PIXEL;

uint32_t WriteCmdAdr = 0x68000000;
uint32_t WriteDataAdr = 0x68000002;

void lcdWriteCmd(uint16_t cmd)
{
	*(uint16_t *)WriteCmdAdr = cmd;
}

void lcdWriteData(uint16_t data)
{
	*(uint16_t *)WriteDataAdr = data;
}

uint16_t lcdReadData(void)
{
	return ( * ( __IO uint16_t * ) ( WriteDataAdr ) );
}

void lcdReset(void)
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_Delay(2);
}

void lcdGetId(uint8_t *ID)
{
	uint16_t ID1 = 0x00;
	uint16_t ID2 = 0x00;
	uint16_t ID3 = 0x00;
	uint16_t ID4 = 0x00;
	lcdReset();
	
	lcdWriteCmd(0xFF);
	lcdWriteData(0xFF);
	lcdWriteData(0x98);
	lcdWriteData(0x06);
	
	lcdWriteCmd(0xD3);
	ID1=lcdReadData();
	ID2=lcdReadData();
	ID3=lcdReadData();
	ID4=lcdReadData();
	ID[0] = (uint8_t)ID1;
	ID[1] = (uint8_t)ID2;
	ID[2] = (uint8_t)ID3;
	ID[3] = (uint8_t)ID4;
}

void lcdRegConfig(void)
{
	lcdWriteCmd(0xFF);
	lcdWriteData(0xFF);
	lcdWriteData(0x98);
	lcdWriteData(0x06);
	
	lcdWriteCmd(0xBA);
	lcdWriteData(0x60);
	
	//GIP begin
	lcdWriteCmd(0xBC);
	lcdWriteData(0x01);
	lcdWriteData(0x0E);
	lcdWriteData(0x61);
	lcdWriteData(0xFB);
	lcdWriteData(0x10);
	lcdWriteData(0x10);
	lcdWriteData(0x0B);
	lcdWriteData(0x0F);
	lcdWriteData(0x2E);
	lcdWriteData(0x73);
	lcdWriteData(0xFF);
	lcdWriteData(0xFF);
	lcdWriteData(0x0E);
	lcdWriteData(0x0E);
	lcdWriteData(0x00);
	lcdWriteData(0x03);
	lcdWriteData(0x66);
	lcdWriteData(0x63);
	lcdWriteData(0x01);
	lcdWriteData(0x00);
	lcdWriteData(0x00);
	
	lcdWriteCmd(0xBD);
	lcdWriteData(0x01);
	lcdWriteData(0x23);
	lcdWriteData(0x45);
	lcdWriteData(0x67);
	lcdWriteData(0x01);
	lcdWriteData(0x23);
	lcdWriteData(0x45);
	lcdWriteData(0x67);
	
	lcdWriteCmd(0xBE);
	lcdWriteData(0x00);
	lcdWriteData(0x21);
	lcdWriteData(0xAB);
	lcdWriteData(0x60);
	lcdWriteData(0x22);
	lcdWriteData(0x22);
	lcdWriteData(0x22);
	lcdWriteData(0x22);	
	lcdWriteData(0x22);	
	
	//GIP end
	
	lcdWriteCmd(0xC7);	//Vcom
	lcdWriteData(0x6F);
	
	lcdWriteCmd(0xED);
	lcdWriteData(0x7F);
	lcdWriteData(0x0F);
	
	lcdWriteCmd(0xC0);
	lcdWriteData(0x37);
	lcdWriteData(0x0B);
	lcdWriteData(0x0A);
	
	lcdWriteCmd(0xFC);
	lcdWriteData(0x0A);
	
	lcdWriteCmd(0xDF);
	lcdWriteData(0x00);
	lcdWriteData(0x00);
	lcdWriteData(0x00);
	lcdWriteData(0x00);
	lcdWriteData(0x00);
	lcdWriteData(0x20);
	
	lcdWriteCmd(0xF3);
	lcdWriteData(0x74);
	
	lcdWriteCmd(0xB4);
	lcdWriteData(0x00);
	lcdWriteData(0x00);
	lcdWriteData(0x00);
	
	lcdWriteCmd(0xF7);
	lcdWriteData(0x8A);
	
	lcdWriteCmd(0xB1);
	lcdWriteData(0x00);
	lcdWriteData(0x12);
	lcdWriteData(0x13);
	
	lcdWriteCmd(0xF2);
	lcdWriteData(0x80);
	lcdWriteData(0x5B);
	lcdWriteData(0x40);
	lcdWriteData(0x28);
	
	lcdWriteCmd(0xC1);
	lcdWriteData(0x17);
	lcdWriteData(0x7D);
	lcdWriteData(0x7A);
	lcdWriteData(0x20);
	
	lcdWriteCmd(0xE0);
	lcdWriteData(0x00);
	lcdWriteData(0x11);
	lcdWriteData(0x1C);
	lcdWriteData(0x0E);
	lcdWriteData(0x0F);
	lcdWriteData(0x0C);
	lcdWriteData(0xC7);
	lcdWriteData(0x06);
	lcdWriteData(0x06);
	lcdWriteData(0x0A);
	lcdWriteData(0x10);
	lcdWriteData(0x12);
	lcdWriteData(0x0A);
	lcdWriteData(0x10);
	lcdWriteData(0x02);
	lcdWriteData(0x00);
	
	lcdWriteCmd(0xE1);
	lcdWriteData(0x00);
	lcdWriteData(0x12);
	lcdWriteData(0x18);
	lcdWriteData(0x0C);
	lcdWriteData(0x0F);
	lcdWriteData(0x0A);
	lcdWriteData(0x77);
	lcdWriteData(0x06);
	lcdWriteData(0x07);
	lcdWriteData(0x0A);
	lcdWriteData(0x0E);
	lcdWriteData(0x0B);
	lcdWriteData(0x10);
	lcdWriteData(0x1D);
	lcdWriteData(0x17);
	lcdWriteData(0x00);
	
	lcdWriteCmd(0x35);
	lcdWriteData(0x00);
	
	lcdWriteCmd(0x3A);
	lcdWriteData(0x55);

	lcdWriteCmd(0x11);
	HAL_Delay(1);		//1.2ms
	lcdWriteCmd(0x29);
}              

uint8_t LCD_SCAN_MODE =6;
void lcdScanModel ( uint8_t ucOption )
{	
	//������飬ֻ������0-7
	if(ucOption >7 )
		return;
	
	//����ģʽ����LCD_SCAN_MODE��ֵ����Ҫ���ڴ�����ѡ��������
	LCD_SCAN_MODE = ucOption;
	
	//����ģʽ����XY��������ؿ��
	if(ucOption%2 == 0)	
	{
		//0 2 4 6ģʽ��X�������ؿ��Ϊ480��Y����Ϊ854
		LCD_X_LENGTH = ILI9806G_LESS_PIXEL;
		LCD_Y_LENGTH =	ILI9806G_MORE_PIXEL;
	}
	else				
	{
		//1 3 5 7ģʽ��X�������ؿ��Ϊ854��Y����Ϊ480
		LCD_X_LENGTH = ILI9806G_MORE_PIXEL;
		LCD_Y_LENGTH =	ILI9806G_LESS_PIXEL; 
	}

	//0x36��������ĸ�3λ����������GRAMɨ�跽��	
	lcdWriteCmd ( 0x36 ); 
	lcdWriteData (0x00 | (ucOption<<5));//����ucOption��ֵ����LCD��������0-7��ģʽ
	
//	lcdWriteCmd ( CMD_SetCoordinateX ); 
//	lcdWriteData ( 0x00 );		/* x ��ʼ�����8λ */
//	lcdWriteData ( 0x00 );		/* x ��ʼ�����8λ */
//	lcdWriteData ( ((LCD_X_LENGTH-1)>>8)&0xFF ); /* x ���������8λ */	
//	lcdWriteData ( (LCD_X_LENGTH-1)&0xFF );				/* x ���������8λ */

//	lcdWriteCmd ( CMD_SetCoordinateY ); 
//	lcdWriteData ( 0x00 );		/* y ��ʼ�����8λ */
//	lcdWriteData ( 0x00 );		/* y ��ʼ�����8λ */
//	lcdWriteData ( ((LCD_Y_LENGTH-1)>>8)&0xFF );	/* y ���������8λ */	 
//	lcdWriteData ( (LCD_Y_LENGTH-1)&0xFF );				/* y ���������8λ */

//	/* write gram start */
//	lcdWriteCmd ( CMD_SetPixel );	
}

void lcdOpenWindow( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight)
{
	lcdWriteCmd ( CMD_SetCoordinateX ); 				 /* ����X���� */
	lcdWriteData ( usX >> 8  );	 /* �ȸ�8λ��Ȼ���8λ */
	lcdWriteData ( usX & 0xff  );	 /* ������ʼ��ͽ�����*/
	lcdWriteData ( ( usX + usWidth - 1 ) >> 8  );
	lcdWriteData ( ( usX + usWidth - 1 ) & 0xff  );

	lcdWriteCmd ( CMD_SetCoordinateY ); 			     /* ����Y����*/
	lcdWriteData ( usY >> 8  );
	lcdWriteData ( usY & 0xff  );
	lcdWriteData ( ( usY + usHeight - 1 ) >> 8 );
	lcdWriteData ( ( usY + usHeight - 1) & 0xff );
	
		//���´���ο���Դ���룬���������ͨʹ��ʱ���Բ��ӣ�������LVGLʱҪ�ӣ�
	lcdWriteCmd(CMD_SetPixel);
}

static __inline void ILI9806G_FillColor ( uint32_t ulAmout_Point, uint16_t usColor )
{
	uint32_t i = 0;

	/* memory write */
	lcdWriteCmd ( CMD_SetPixel );	

	for ( i = 0; i < ulAmout_Point; i ++ )
	{
		lcdWriteData ( usColor );
	}
}

//static uint16_t CurrentBackColor   = YELLOW;//����ɫ

void ILI9806G_Clear( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight, uint16_t color )
{
	lcdOpenWindow ( usX, usY, usWidth, usHeight );

	ILI9806G_FillColor ( usWidth * usHeight, color );				//6
	
}

void lcdInit(void)
{
	lcdReset();
	//softreset cute form open source
	//lcdWriteCmd(0x01);
	//HAL_Delay(500);
	
	lcdRegConfig();
	//HAL_Delay(100);
	lcdScanModel(6);		//Ĭ��6 
	//HAL_Delay(100);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,WHITE);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
}

void lcdChangeColor(void)
{
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,WHITE);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,BLACK);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,GREY);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,BLUE);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,BLUE2);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,RED);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,MAGENTA);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,GREEN);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,CYAN);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,YELLOW);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,BRED);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,GRED);
	HAL_Delay(1500);
	ILI9806G_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH,GBLUE);
	HAL_Delay(1500);
}

void lcdDrawRectangle(void)
{
	uint16_t X,Y,W,H;
	X=50;
	W=250;
	Y=50;
	H=500;
	lcdWriteCmd(0x2a);
	lcdWriteData((X >> 8) & 0xFF); // x0��8λ
	lcdWriteData(X & 0xFF);
	lcdWriteData(((X+W) >> 8) & 0xFF); // x1��8λ
	lcdWriteData((X+W) & 0xFF);

	lcdWriteCmd(0x2b);
	lcdWriteData((Y >> 8) & 0xFF); // y0��8λ
	lcdWriteData(Y & 0xFF);
	lcdWriteData(((Y+H) >> 8) & 0xFF); // y1��8λ
	lcdWriteData((Y+H) & 0xFF);

	lcdWriteCmd(0x2c); // д����������(������ľ��ο��ڰ�ɨ�跽�����д��)
	for (uint32_t i = 0; i < (W+ 1) * (H + 1); i++)
	{
			lcdWriteData(RED);
	}
}


	
/**
 * @brief  ��ILI9806G��ʾ����ĳһ����ĳ����ɫ�������
 * @param  usX �����ض�ɨ�跽���¸õ��X����
 * @param  usY �����ض�ɨ�跽���¸õ��Y����
 * @note ��ʹ��LCD_SetBackColor��LCD_SetTextColor��LCD_SetColors����������ɫ
 * @retval ��
 */
void lcdDrawPixel( uint16_t usX, uint16_t usY ,uint16_t color)	
{	
	if ( ( usX < LCD_X_LENGTH ) && ( usY < LCD_Y_LENGTH ) )
  {
		lcdOpenWindow ( usX, usY, 1, 1);
		
		ILI9806G_FillColor ( 1, color );
	}
}