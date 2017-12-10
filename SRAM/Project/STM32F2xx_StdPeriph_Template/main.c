/**
  ******************************************************************************
  * @file    FSMC/SRAM/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32_eval.h"
#include "stm322xg_eval_fsmc_sram.h"
#include "usart.h"

/** @addtogroup STM32F2xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup FSMC_SRAM
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BUFFER_SIZE        0x100
#define WRITE_READ_ADDR    0x800

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint16_t TxBuffer[BUFFER_SIZE], RxBuffer[BUFFER_SIZE];
__IO uint32_t WriteReadStatus = 0;
uint32_t Index = 0;

/* Private function prototypes -----------------------------------------------*/
void Fill_Buffer(uint16_t *pBuffer, uint16_t BufferLenght, uint32_t Offset);

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f2xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f2xx.c file
     */
  
  /* Initialize LEDs on STM322xG-EVAL board */
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);
  USART_Configuration();
    
  /* Configure FSMC Bank 1 NOR/SRAM2  */
  SRAM_Init();
  printf("\r\nSRAM has Init..\r\n");
  /* Write data to FSMC SRAM memory */
  /* Fill the buffer to send */
  Fill_Buffer(TxBuffer, BUFFER_SIZE, 0x320F);
  SRAM_WriteBuffer(TxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);
  printf("\r\nSRAM has Write..\r\n");
  /* Read data from FSMC SRAM memory */
  SRAM_ReadBuffer(RxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);  
  printf("\r\nSRAM has Read..\r\n");
  printf("\r\nSRAM Read Data:");
  /* Read back SRAM memory and check content correctness */   
  for (Index = 0x00; (Index < BUFFER_SIZE) /*&& (WriteReadStatus == 0)*/; Index++)
  {
    if (RxBuffer[Index] != TxBuffer[Index])
    {
      WriteReadStatus++;
    }
	printf("  0x%x  ",RxBuffer[Index]);
  }	

  if (WriteReadStatus == 0)
  {
    /* OK */
    /* Turn on LD1 */
    STM_EVAL_LEDOn(LED1);
	printf("\r\nSRAM Read succeedful...\r\n");
  }
  else
  { 
    /* KO */
    /* Turn on LD2 */
    STM_EVAL_LEDOn(LED2); 
	printf("\r\nSRAM Read Wrong btye:%d\r\n",WriteReadStatus);    
  }

  while (1)
  {
  }
}

/**
  * @brief  Fills buffer with user predefined data.
  * @param  pBuffer: pointer on the buffer to fill
  * @param  BufferLenght: size of the buffer to fill
  * @param  Offset: first value to fill on the buffer
  * @retval None
  */
void Fill_Buffer(uint16_t *pBuffer, uint16_t BufferLenght, uint32_t Offset)
{
  uint16_t IndexTmp = 0;

  /* Put in global buffer different values */
  for (IndexTmp = 0; IndexTmp < BufferLenght; IndexTmp++ )
  {
    pBuffer[IndexTmp] = IndexTmp + Offset;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
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

/**
  * @}
  */

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/