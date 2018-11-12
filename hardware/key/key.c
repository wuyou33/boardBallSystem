/**
  ******************************************************************************
  * @file    bsp_key.c
  * @brief   ����Ӧ��bsp��ɨ��ģʽ��
  ******************************************************************************
  ******************************************************************************
  */ 
	

#include "key.h" 
#include "delay.h"
#include "sys.h"

key_t key;
/**
  * @brief  ���ð����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*���������˿ڣ�PF����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //��������
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//ѡ��ͨ��������� 
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void Key_button(void)
{	
	int8_t KeyVal = -1;//���ؼ�ֵ
	GPIO_Write(GPIOC,(GPIOC->ODR & 0xf0ff | 0x0100)); //��F�ڵ�8-11�����������0001
	
	if((GPIOC->IDR & 0xf000)>0x0000)
	{
		delay_ms(10);
		if((GPIOC->IDR & 0xf000)>0x0000)
		{
		
	      switch(GPIOC->IDR & 0xf000)//�������12-15��ֵ�����ж�ÿ�п�ʼɨ�� 
	       {
		         case 0x1000: KeyVal=2; break;    
		         case 0x2000: KeyVal=3; break;    
		         case 0x4000: KeyVal=1; break;   
		         case 0x8000: KeyVal=4; break;   
			}
    	}
  }
	
	GPIO_Write(GPIOC,(GPIOC->ODR & 0xf0ff | 0x0200));   
	
	if((GPIOC->IDR & 0xf000)>0x0000)
	{
		delay_ms(10);
		if((GPIOC->IDR & 0xf000)>0x0000)
		{
		
	      switch(GPIOC->IDR & 0xf000)//�������12-15��ֵ�����ж�ÿ�п�ʼɨ�� 
	       {

				 case 0x1000: KeyVal=6; break;    
		         case 0x2000: KeyVal=7; break;   
		         case 0x4000: KeyVal=5; break;    
		         case 0x8000: KeyVal=8; break;
         }
    }
  }
	
	GPIO_Write(GPIOC,(GPIOC->ODR & 0xf0ff | 0x0400));   
	
	if((GPIOC->IDR & 0xf000)>0x0000)
	{
		delay_ms(10);
		if((GPIOC->IDR & 0xf000)>0x0000)
		{
		
	      switch(GPIOC->IDR & 0xf000)//�������12-15��ֵ�����ж�ÿ�п�ʼɨ�� 
	       {
		         case 0x1000: KeyVal=10; break;    
		         case 0x2000: KeyVal=11; break;   
		         case 0x4000: KeyVal=9; break;    
		         case 0x8000: KeyVal=12; break;
         }
    }
  }
	
	GPIO_Write(GPIOC,(GPIOC->ODR & 0xf0ff | 0x0800));   
	
	if((GPIOC->IDR & 0xf000)>0x0000)
	{
		delay_ms(10);
		if((GPIOC->IDR & 0xf000)>0x0000)
		{
		
	      switch(GPIOC->IDR & 0xf000)//�������12-15��ֵ�����ж�ÿ�п�ʼɨ�� 
	       {
				 case 0x1000: KeyVal=14; break;    
		         case 0x2000: KeyVal=15; break;   
		         case 0x4000: KeyVal=13; break;    
		         case 0x8000: KeyVal=16; break;
         }
    }
  }
	if(KeyVal != -1){
		key.isPress = true;
		key.data = KeyVal;
		delay_ms(100);
	}
}
/*********************************************END OF FILE**********************/