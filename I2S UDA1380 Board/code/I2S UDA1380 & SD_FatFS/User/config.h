#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>
#include "stm32f2xx.h"

/**
 * @brief Definition for COM port1, connected to USART1
 */ 
	#define Open207Z_USARTx                        	USART3
	#define Open207Z_USARTx_CLK                    	RCC_APB1Periph_USART3
	
	#define Open207Z_USARTx_TX_PIN                 	GPIO_Pin_10
	#define Open207Z_USARTx_TX_GPIO_PORT           	GPIOB
	#define Open207Z_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open207Z_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define Open207Z_USARTx_TX_AF                  	GPIO_AF_USART3
	
	
	#define Open207Z_USARTx_RX_PIN                 	GPIO_Pin_11
	#define Open207Z_USARTx_RX_GPIO_PORT           	GPIOB
	#define Open207Z_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open207Z_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define Open207Z_USARTx_RX_AF                  	GPIO_AF_USART3
	
#define Open207Z_USARTx_IRQn                    USART3_IRQn

#endif	  /*_CONFIG_H*/

