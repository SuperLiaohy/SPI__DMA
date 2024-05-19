//
// Created by lhy on 5/18/24.
//
#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "tim.h"
#include "spi.h"
#include "usart.h"

extern DMA_HandleTypeDef hdma_usart1_rx;

#ifdef __cplusplus
}
#endif

#include "LCD.h"

extern LCD lcd;
extern int num;
extern int max;
int sec = 0;
int z;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if (htim==&htim2){
        ++sec;
        max = num;
        num = 0;
    }
}

volatile bool one_frame_done = true;
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if (hspi == &hspi1) { one_frame_done = false; }
}
bool val = 0;
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
    val = 1;


}