/**
 * @file    nrf53.c
 * @brief   board ID and meta-data for HIC based on custom nRF5340 board
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2021, Arm Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "compiler.h"
#include "daplink_addr.h"
#include "target_board.h"
#include "target_config.h"
#include "target_family.h"

static char board_name[24] =
    "nRF53"; // needs to be >= longest board name + longest suffix + 1

const board_info_t g_board_info = {
    .info_version = kBoardInfoVersion,
    .flags = kEnablePageErase,
    .family_id = kNordic_Nrf53_FamilyID,
    .target_cfg = &target_device,
    .board_vendor = "Nordic Semiconductor",
    .board_name = board_name,
};
