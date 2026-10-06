#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	
	while(1)
	{
		// 从 PA0 到 PA7 依次点亮
        for(int i = 0; i < 8; i++)
        {
            GPIO_Write(GPIOA, ~(1 << i));  // 1左移i位：i=0时0x0001，i=1时0x0002...
            Delay_ms(100);
        }
        
        // 从 PA7 回到 PA0（形成往复流水）
        for(int i = 7; i > 0; i--)
        {
            GPIO_Write(GPIOA, ~(1 << i));
            Delay_ms(100);
        }
		
	}

}
