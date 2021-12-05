#include "stm8s.h"


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

#define LED_GPIO_PORT (GPIOE)
#define LED_GPIO_PINS (GPIO_PIN_5)


void Delay(uint16_t nCount){
    while (nCount)
    {
        nCount--;
    }
}

void main(void){
    GPIO_Init(LED_GPIO_PORT,(GPIO_Pin_TypeDef)LED_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
    while (1)
    {
        GPIO_WriteReverse(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS);
        Delay(0xFFFF);
    }
}