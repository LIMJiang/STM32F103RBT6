#ifndef __BITBAND_H
#define __BITBAND_H

#include "stm32f10x_conf.h"

//该宏是把位带区的地址转换成了位带别名区的地址(无论SRAM区还是片上外设区都可以转换)
#define BIT_BAND(ADDR,BITNUM) ((ADDR & 0xF0000000) + 0x2000000 + ((ADDR & 0xFFFFF) << 5) + (BITNUM << 2))

//该宏是把十六进制数据强制类型转换成地址
#define MEM_ADDR(ADDR) *(volatile unsigned int *)(ADDR)

//把上述两个宏结合
#define BITBAND(ADDR,BITNUM) MEM_ADDR(BIT_BAND(ADDR,BITNUM))

#define GPIOA_IDR_ADDR (GPIOA_BASE + 0x08)//输入数据寄存器的真实地址
#define GPIOA_ODR_ADDR (GPIOA_BASE + 0x0C)//输出数据寄存器的真实地址

#define GPIOB_IDR_ADDR (GPIOB_BASE + 0x08)//输入数据寄存器的真实地址
#define GPIOB_ODR_ADDR (GPIOB_BASE + 0x0C)//输出数据寄存器的真实地址

#define GPIOC_IDR_ADDR (GPIOC_BASE + 0x08)//输入数据寄存器的真实地址
#define GPIOC_ODR_ADDR (GPIOC_BASE + 0x0C)//输出数据寄存器的真实地址

#define GPIOD_IDR_ADDR (GPIOD_BASE + 0x08)//输入数据寄存器的真实地址
#define GPIOD_ODR_ADDR (GPIOD_BASE + 0x0C)//输出数据寄存器的真实地址

#define PAOut(n) BITBAND(GPIOA_ODR_ADDR, n)
#define PAIn(n)  BITBAND(GPIOA_IDR_ADDR, n)

#define PBOut(n) BITBAND(GPIOB_ODR_ADDR, n)
#define PBIn(n)  BITBAND(GPIOB_IDR_ADDR, n)

#define PCOut(n) BITBAND(GPIOC_ODR_ADDR, n)
#define PCIn(n)  BITBAND(GPIOC_IDR_ADDR, n)

#define PDOut(n) BITBAND(GPIOD_ODR_ADDR, n)
#define PDIn(n)  BITBAND(GPIOD_IDR_ADDR, n)

#endif










