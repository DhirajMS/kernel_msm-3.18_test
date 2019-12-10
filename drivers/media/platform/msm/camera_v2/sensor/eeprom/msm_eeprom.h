/* Copyright (c) 2011-2015, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef MSM_EEPROM_H
#define MSM_EEPROM_H

#include <linux/i2c.h>
#include <linux/gpio.h>
#include <soc/qcom/camera2.h>
#include <media/v4l2-subdev.h>
#include <media/msmb_camera.h>
#include "msm_camera_i2c.h"
#include "msm_camera_spi.h"
#include "msm_camera_io_util.h"
#include "msm_camera_dt_util.h"

struct msm_eeprom_ctrl_t;

#define DEFINE_MSM_MUTEX(mutexname) \
	static struct mutex mutexname = __MUTEX_INITIALIZER(mutexname)

#define PROPERTY_MAXSIZE 32

struct msm_eeprom_ctrl_t {
	struct platform_device *pdev;
	struct mutex *eeprom_mutex;

	struct v4l2_subdev sdev;
	struct v4l2_subdev_ops *eeprom_v4l2_subdev_ops;
	enum msm_camera_device_type_t eeprom_device_type;
	struct msm_sd_subdev msm_sd;
	enum cci_i2c_master_t cci_master;
	enum i2c_freq_mode_t i2c_freq_mode;

	struct msm_camera_i2c_client i2c_client;
	struct msm_eeprom_board_info *eboard_info;
	uint32_t subdev_id;
	int32_t userspace_probe;
	struct msm_eeprom_memory_block_t cal_data;
	uint8_t is_supported;
};
#ifdef CONFIG_HQ_HI553_OTP
struct msm_camera_i2c_reg_array hi553_readotp_init_regval[] = {
	{0x0a00, 0x0000, 0x0000}, //stream off
	{0x0e00, 0x0102, 0x0000}, //tg_pmem_sckpw/sdly
	{0x0e02, 0x0102, 0x0000}, //tg_dmem_sckpw/sdly
	{0x2000, 0x4031, 0x0000},
	{0x2002, 0x8400, 0x0000},
	{0x2004, 0x430d, 0x0000},
	{0x2006, 0x430c, 0x0000},
	{0x2008, 0x0900, 0x0000},
	{0x200a, 0x7312, 0x0000},
	{0x200c, 0x43d2, 0x0000},
	{0x200e, 0x0f82, 0x0000},
	{0x2010, 0x0cff, 0x0000},
	{0x2012, 0x0cff, 0x0000},
	{0x2014, 0x0cff, 0x0000},
	{0x2016, 0x0cff, 0x0000},
	{0x2018, 0x0cff, 0x0000},
	{0x201a, 0x0cff, 0x0000},
	{0x201c, 0x0c32, 0x0000},
	{0x201e, 0x40f2, 0x0000},
	{0x2020, 0x000e, 0x0000},
	{0x2022, 0x0f90, 0x0000},
	{0x2024, 0x43d2, 0x0000},
	{0x2026, 0x0180, 0x0000},
	{0x2028, 0x4392, 0x0000},
	{0x202a, 0x760e, 0x0000},
	{0x202c, 0x0900, 0x0000},
	{0x202e, 0x760c, 0x0000},
	{0x2030, 0x9382, 0x0000},
	{0x2032, 0x760c, 0x0000},
	{0x2034, 0x2002, 0x0000},
	{0x2036, 0x0c64, 0x0000},
	{0x2038, 0x3ffb, 0x0000},
	{0x203a, 0x421f, 0x0000},
	{0x203c, 0x760a, 0x0000},
	{0x203e, 0x931f, 0x0000},
	{0x2040, 0x2023, 0x0000},
	{0x2042, 0x421d, 0x0000},
	{0x2044, 0x018a, 0x0000},
	{0x2046, 0x4d82, 0x0000},
	{0x2048, 0x7600, 0x0000},
	{0x204a, 0x4382, 0x0000},
	{0x204c, 0x7602, 0x0000},
	{0x204e, 0x0260, 0x0000},
	{0x2050, 0x0000, 0x0000},
	{0x2052, 0x0c64, 0x0000},
	{0x2054, 0x0240, 0x0000},
	{0x2056, 0x0000, 0x0000},
	{0x2058, 0x0260, 0x0000},
	{0x205a, 0x0000, 0x0000},
	{0x205c, 0x0c1e, 0x0000},
	{0x205e, 0x4382, 0x0000},
	{0x2060, 0x7602, 0x0000},
	{0x2062, 0x4d82, 0x0000},
	{0x2064, 0x7600, 0x0000},
	{0x2066, 0x0270, 0x0000},
	{0x2068, 0x0000, 0x0000},
	{0x206a, 0x0c1c, 0x0000},
	{0x206c, 0x0270, 0x0000},
	{0x206e, 0x0001, 0x0000},
	{0x2070, 0x421f, 0x0000},
	{0x2072, 0x7606, 0x0000},
	{0x2074, 0x4fc2, 0x0000},
	{0x2076, 0x0188, 0x0000},
	{0x2078, 0x0260, 0x0000},
	{0x207a, 0x0000, 0x0000},
	{0x207c, 0x421f, 0x0000},
	{0x207e, 0x7606, 0x0000},
	{0x2080, 0x4fc2, 0x0000},
	{0x2082, 0x0188, 0x0000},
	{0x2084, 0x4d0c, 0x0000},
	{0x2086, 0x3fd0, 0x0000},
	{0x2088, 0x903f, 0x0000},
	{0x208a, 0x0201, 0x0000},
	{0x208c, 0x23cd, 0x0000},
	{0x208e, 0x531d, 0x0000},
	{0x2090, 0x4d0e, 0x0000},
	{0x2092, 0x108e, 0x0000},
	{0x2094, 0xf37e, 0x0000},
	{0x2096, 0xc312, 0x0000},
	{0x2098, 0x100e, 0x0000},
	{0x209a, 0x110e, 0x0000},
	{0x209c, 0x110e, 0x0000},
	{0x209e, 0x110e, 0x0000},
	{0x20a0, 0x4c0f, 0x0000},
	{0x20a2, 0x108f, 0x0000},
	{0x20a4, 0xf37f, 0x0000},
	{0x20a6, 0xc312, 0x0000},
	{0x20a8, 0x100f, 0x0000},
	{0x20aa, 0x110f, 0x0000},
	{0x20ac, 0x110f, 0x0000},
	{0x20ae, 0x110f, 0x0000},
	{0x20b0, 0x9f0e, 0x0000},
	{0x20b2, 0x240e, 0x0000},
	{0x20b4, 0x0261, 0x0000},
	{0x20b6, 0x0000, 0x0000},
	{0x20b8, 0x4382, 0x0000},
	{0x20ba, 0x7600, 0x0000},
	{0x20bc, 0x4382, 0x0000},
	{0x20be, 0x7602, 0x0000},
	{0x20c0, 0x0260, 0x0000},
	{0x20c2, 0x0000, 0x0000},
	{0x20c4, 0x0c64, 0x0000},
	{0x20c6, 0x0240, 0x0000},
	{0x20c8, 0x0000, 0x0000},
	{0x20ca, 0x0260, 0x0000},
	{0x20cc, 0x0000, 0x0000},
	{0x20ce, 0x0c1e, 0x0000},
	{0x20d0, 0x4382, 0x0000},
	{0x20d2, 0x7602, 0x0000},
	{0x20d4, 0x4d82, 0x0000},
	{0x20d6, 0x7600, 0x0000},
	{0x20d8, 0x0270, 0x0000},
	{0x20da, 0x0000, 0x0000},
	{0x20dc, 0x0c1c, 0x0000},
	{0x20de, 0x0270, 0x0000},
	{0x20e0, 0x0001, 0x0000},
	{0x20e2, 0x421f, 0x0000},
	{0x20e4, 0x7606, 0x0000},
	{0x20e6, 0x4fc2, 0x0000},
	{0x20e8, 0x0188, 0x0000},
	{0x20ea, 0x0260, 0x0000},
	{0x20ec, 0x0000, 0x0000},
	{0x20ee, 0x3fc6, 0x0000},
	{0x20f0, 0x4030, 0x0000},
	{0x20f2, 0xf0f4, 0x0000},
	{0x20f4, 0xdf02, 0x0000},
	{0x20f6, 0x3ffe, 0x0000},
	{0x20f8, 0x430e, 0x0000},
	{0x20fa, 0x430f, 0x0000},
	{0x20fc, 0x3c08, 0x0000},
	{0x20fe, 0xc312, 0x0000},
	{0x2100, 0x100d, 0x0000},
	{0x2102, 0x100c, 0x0000},
	{0x2104, 0x2802, 0x0000},
	{0x2106, 0x5a0e, 0x0000},
	{0x2108, 0x6b0f, 0x0000},
	{0x210a, 0x5a0a, 0x0000},
	{0x210c, 0x6b0b, 0x0000},
	{0x210e, 0x930c, 0x0000},
	{0x2110, 0x23f6, 0x0000},
	{0x2112, 0x930d, 0x0000},
	{0x2114, 0x23f4, 0x0000},
	{0x2116, 0x4130, 0x0000},
	{0x2118, 0x4030, 0x0000},
	{0x211a, 0xf0f8, 0x0000},
	{0x211c, 0xee0e, 0x0000},
	{0x211e, 0x403b, 0x0000},
	{0x2120, 0x0011, 0x0000},
	{0x2122, 0x3c05, 0x0000},
	{0x2124, 0x100d, 0x0000},
	{0x2126, 0x6e0e, 0x0000},
	{0x2128, 0x9a0e, 0x0000},
	{0x212a, 0x2801, 0x0000},
	{0x212c, 0x8a0e, 0x0000},
	{0x212e, 0x6c0c, 0x0000},
	{0x2130, 0x6d0d, 0x0000},
	{0x2132, 0x831b, 0x0000},
	{0x2134, 0x23f7, 0x0000},
	{0x2136, 0x4130, 0x0000},
	{0x2138, 0xef0f, 0x0000},
	{0x213a, 0xee0e, 0x0000},
	{0x213c, 0x4039, 0x0000},
	{0x213e, 0x0021, 0x0000},
	{0x2140, 0x3c0a, 0x0000},
	{0x2142, 0x1008, 0x0000},
	{0x2144, 0x6e0e, 0x0000},
	{0x2146, 0x6f0f, 0x0000},
	{0x2148, 0x9b0f, 0x0000},
	{0x214a, 0x2805, 0x0000},
	{0x214c, 0x2002, 0x0000},
	{0x214e, 0x9a0e, 0x0000},
	{0x2150, 0x2802, 0x0000},
	{0x2152, 0x8a0e, 0x0000},
	{0x2154, 0x7b0f, 0x0000},
	{0x2156, 0x6c0c, 0x0000},
	{0x2158, 0x6d0d, 0x0000},
	{0x215a, 0x6808, 0x0000},
	{0x215c, 0x8319, 0x0000},
	{0x215e, 0x23f1, 0x0000},
	{0x2160, 0x4130, 0x0000},
	{0x2162, 0x4130, 0x0000},
	{0x2ffe, 0xf000, 0x0000},
	{0x0b00, 0x0000, 0x0000},
	{0x0b02, 0x1807, 0x0000},
	{0x0b04, 0x3540, 0x0000},
	{0x0b06, 0x3540, 0x0000},
	{0x0b08, 0x0000, 0x0000},
	{0x0b0a, 0x0000, 0x0000},
	{0x0b0c, 0x0000, 0x0000},
	{0x0b0e, 0x8200, 0x0000},
	{0x0b10, 0x0020, 0x0000},
	{0x0b12, 0x0000, 0x0000},
	{0x0b14, 0x001c, 0x0000},
	{0x0b16, 0x6e0b, 0x0000},
	{0x0b18, 0xf20b, 0x0000},
	{0x0b1a, 0x0000, 0x0000},
	{0x0b1c, 0x0000, 0x0000},
	{0x0b1e, 0x0081, 0x0000},
	{0x0b20, 0x0000, 0x0000},
	{0x0b22, 0x4c80, 0x0000},
	{0x0b24, 0x0000, 0x0000},
	{0x0b26, 0x0000, 0x0000},
	{0x0b28, 0x0000, 0x0000},
	{0x0e0a, 0x0001, 0x0000}, //tg_pmem_cen, rom_cen enable
	{0x004a, 0x0100, 0x0000}, //tg enable,hdr off
	{0x0a00, 0x0100, 0x0000}, //stream on
};

struct msm_camera_i2c_reg_setting hi553_otp_read_init_setting = {
	.reg_setting = hi553_readotp_init_regval,
	.size = ARRAY_SIZE(hi553_readotp_init_regval),
	.addr_type = MSM_CAMERA_I2C_WORD_ADDR,
	.data_type = MSM_CAMERA_I2C_WORD_DATA,
	.delay = 2,
};

struct msm_camera_i2c_reg_array hi553_readotp_init_regval_start[] = {
	{0x0a02, 0x1, 0 },//fast sleep on
        {0x0a00, 0x0, 10},//standby on, sleep 10
        {0x0f02, 0x0, 0 },//pll disable
        {0x011a, 0x1, 0 },//CP TRIM_H
        {0x011b, 0x9, 0 },//IPGM TRIM_H
        {0x0d04, 0x1, 0 },//Fsync(OTP busy) Output Enable
        {0x0d00, 0x7, 0 },//Fsync(OTP busy) Output Drivability
        {0x0e0a, 0x00, 0},     //TG PMEM CEN enable
        {0x003f, 0x10, 0 },//***OTP R/W mode
        {0x0a00, 0x1, 0 },//stand by off
        //start read
	{0x10a, 0x5, 0},//high
	{0x10b, 0x1, 0},//low
	{0x102, 0x1, 0},
};
struct msm_camera_i2c_reg_setting hi553_otp_read_init_setting_start = {
	.reg_setting = hi553_readotp_init_regval_start,
	.size = ARRAY_SIZE(hi553_readotp_init_regval_start),
	.addr_type = MSM_CAMERA_I2C_WORD_ADDR,
	.data_type = MSM_CAMERA_I2C_BYTE_DATA,
	.delay = 2,
};
#endif
#endif
