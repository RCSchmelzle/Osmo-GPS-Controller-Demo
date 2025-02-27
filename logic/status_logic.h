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

#ifndef STATUS_LOGIC_H
#define STATUS_LOGIC_H

#include <stdint.h>

// 相机状态全局变量声明（其他的后续可补充）
// Declaration of global variables for camera status (more can be added later)
extern uint8_t current_camera_mode;
extern uint8_t current_camera_status;
extern uint8_t current_video_resolution;
extern uint8_t current_fps_idx;
extern uint8_t current_eis_mode;
extern bool camera_status_initialized;

bool is_camera_recording();

void print_camera_status();

int subscript_camera_status(uint8_t push_mode, uint8_t push_freq);

void update_camera_state_handler(void *data);

#endif