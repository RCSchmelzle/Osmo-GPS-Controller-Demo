/* SPDX-License-Identifier: MIT */
/*
 * Copyright (C) 2025 SZ DJI Technology Co., Ltd.
 *  
 * All information contained herein is, and remains, the property of DJI.
 * The intellectual and technical concepts contained herein are proprietary
 * to DJI and may be covered by U.S. and foreign patents, patents in process,
 * and protected by trade secret or copyright law.  Dissemination of this
 * information, including but not limited to data and other proprietary
 * material(s) incorporated within the information, in any form, is strictly
 * prohibited without the express written consent of DJI.
 *
 * If you receive this source code without DJI’s authorization, you may not
 * further disseminate the information, and you must immediately remove the
 * source code and notify DJI of its removal. DJI reserves the right to pursue
 * legal actions against you for any loss(es) or damage(s) caused by your
 * failure to do so.
 */

#ifndef KEY_LOGIC_H
#define KEY_LOGIC_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BOOT_KEY_GPIO   GPIO_NUM_9  // 假设 BOOT 按键连接到 GPIO 9
                                    // Assume BOOT button is connected to GPIO 9

// 按键事件
// Key Events
typedef enum {
    KEY_EVENT_NONE = 0,   // 无事件
                          // No event
    KEY_EVENT_SINGLE,     // 单击事件
                          // Single click event
    KEY_EVENT_LONG_PRESS, // 长按事件
                          // Long press event
    KEY_EVENT_ERROR       // 错误事件
                          // Error event
} key_event_t;

void key_logic_init(void);

key_event_t key_logic_get_event(void);

#endif