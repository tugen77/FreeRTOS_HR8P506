/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_printf.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  Printf���ܿ⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIBPRINTF_H__
#define __LIBPRINTF_H__

#include "lib_uart.h"
#include <stdio.h>
#include <type.h>

#ifdef __clang__ 
ErrorStatus UART_printf(uint8_t *Data, ...);

#elif defined __CC_ARM

#define UART_printf  printf

#endif


#endif
