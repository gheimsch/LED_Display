#ifndef TIMERISR_H_
#define TIMERISR_H_

# ifdef __cplusplus
extern "C" {
# endif

/******************************************************************************/
/*! \file TimerISR.h
******************************************************************************
* \brief Library function for the interrupt
*
* \author meert1,heimg1
*
* \version 0.0.1
*
* \history 14.03.2014 File Created
*
*/
/* ****************************************************************************/
/* LED_Display */
/* ****************************************************************************/

/* ----------------------- module procedure declaration ----------------------*/

extern void initISR(int,int,uint16_t *);
extern "C" void TIM2_IRQHandler(void);

/* ****************************************************************************/
/* End Header : TimerISR.h */
/* ****************************************************************************/
# ifdef __cplusplus
}
# endif
#endif /* TIMERISR_H_ */
