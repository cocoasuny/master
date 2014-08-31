#ifndef __TIMER_H
#define __TIMER_H

/* Includes ------------------------------------------------------------------*/
#include   "stm32f10x.h"

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void Delay_Init(void);
void Delay_us(unsigned int nus);
void Delay_ms(unsigned short nms);

#endif /* __TIMER_H */
