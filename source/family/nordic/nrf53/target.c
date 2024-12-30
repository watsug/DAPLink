/**
 * @file    target.c
 * @brief   Target information for the nRF52 Family
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

#include "target_config.h"

// The file flash_blob.c must only be included in target.c
#include "flash_blob.c"

// target information for nRF5340 with 256 KB RAM / 1024 KB Flash
target_cfg_t target_device = {
    .version = kTargetConfigVersion,
    .sectors_info = sectors_info_nrf53,
    .sector_info_length =
        (sizeof(sectors_info_nrf53)) / (sizeof(sector_info_t)),
    .flash_regions[0].start = flash_start_nrf53xx_application,
    .flash_regions[0].end = flash_size_nrf53xx_application,
    .flash_regions[0].flags = kRegionIsSecure,
    .flash_regions[0].flash_algo =
        (program_target_t *)&flash_nrf53xx_application,
    .flash_regions[1].start = flash_start_nrf53xx_network,
    .flash_regions[1].end = flash_size_nrf53xx_network,
    .flash_regions[1].flags = kRegionIsSecure,
    .flash_regions[1].flash_algo = (program_target_t *)&flash_nrf53xx_network,
    // .flash_regions[2].start = flash_start_nrf53xx_application_uicr,
    // .flash_regions[2].end = flash_size_nrf53xx_application_uicr,
    // .flash_regions[2].flags = kRegionIsSecure,
    // .flash_regions[2].flash_algo =
    //     (program_target_t *)&flash_nrf53xx_application_uicr,
    // .flash_regions[3].start = flash_start_nrf53xx_network_uicr,
    // .flash_regions[3].end = flash_size_nrf53xx_network_uicr,
    // .flash_regions[3].flags = kRegionIsSecure,
    // .flash_regions[3].flash_algo =
    //     (program_target_t *)&flash_nrf53xx_network_uicr,
    .ram_regions[0].start = 0x21000000, // RAM
    .ram_regions[0].end = 0x21010000,
    .ram_regions[1].start = 0x20000000, // APP_RAM0
    .ram_regions[1].end = 0x20040000,
    .ram_regions[2].start = 0x20040000, // APP_RAM1
    .ram_regions[3].end = 0x20080000,
    .erase_reset = 1,
    .target_vendor = "NordicSemiconductor",
    .target_part_number = "nRF5340_xxAA",
};
