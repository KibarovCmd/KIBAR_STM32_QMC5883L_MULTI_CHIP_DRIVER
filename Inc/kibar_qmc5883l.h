/*
 * kibar_qmc5883l.h
 *
 *  Created on: Aug 5, 2024
 *      Author: İskender Musaoğlu
 */

#ifndef KIBAR_QMC5883L_INC_KIBAR_QMC5883L_H_
#define KIBAR_QMC5883L_INC_KIBAR_QMC5883L_H_

#include <kibar_qmc5883l_ext.h>

struct KIBAR_QMC5883L {
	I2C_HandleTypeDef* kibar_i2c_;
	KIBAR_BOOLEAN kibar_interrupt_enable;
	KIBAR_BOOLEAN kibar_rol_pointer_enable;
	KIBAR_STATUS (*KIBAR_QMC5883L_INIT_BASIC_LEVEL_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_INIT_HIGH_LEVEL_)(struct KIBAR_QMC5883L*, KIBAR_OSR, KIBAR_RNG, KIBAR_ODR, KIBAR_MODE);
	KIBAR_STATUS (*KIBAR_QMC5883L_INIT_HIGH_LEVEL_TWO_)(struct KIBAR_QMC5883L*, KIBAR_OSR, KIBAR_RNG, KIBAR_ODR, KIBAR_MODE, uint8_t*);
	KIBAR_AXIS_DATA (*KIBAR_QMC5883L_REGISTER_READ_AXIS_DATA_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS_DATA (*KIBAR_QMC5883L_REGISTER_READ_STATUS_DATA_)(struct KIBAR_QMC5883L*);
	KIBAR_QMC5883L_TEMPERATURE (*KIBAR_QMC5883L_REGISTER_READ_TEMPERATURE_)(struct KIBAR_QMC5883L*);
	KIBAR_QMC5883L_CHIP_ID (*KIBAR_QMC5883L_REGISTER_READ_CHIP_ID_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_IS_ACTIVE_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_REGISTER_WRITE_OSR_)(struct KIBAR_QMC5883L*, KIBAR_OSR);
	KIBAR_STATUS (*KIBAR_QMC5883L_REGISTER_WRITE_RNG_)(struct KIBAR_QMC5883L*, KIBAR_RNG);
	KIBAR_STATUS (*KIBAR_QMC5883L_REGISTER_WRITE_ODR_)(struct KIBAR_QMC5883L*, KIBAR_ODR);
	KIBAR_STATUS (*KIBAR_QMC5883L_REGISTER_WRITE_MODE_)(struct KIBAR_QMC5883L*, KIBAR_MODE);
	KIBAR_STATUS (*KIBAR_QMC5883L_SOFTWARE_RESET_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_ENABLE_ROL_POINTER_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_DISABLE_ROL_POINTER_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_ENABLE_INTERRUPT_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_DISABLE_INTERRUPT_)(struct KIBAR_QMC5883L*);
	KIBAR_STATUS (*KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_)(struct KIBAR_QMC5883L*, uint8_t*);
	KIBAR_STATUS (*KIBAR_QMC5883L_DELETE_)(struct KIBAR_QMC5883L*);
};

typedef struct KIBAR_QMC5883L* KIBAR_QMC5883L_;

KIBAR_QMC5883L_ NEW_KIBAR_QMC5883L(I2C_HandleTypeDef*);
KIBAR_STATUS KIBAR_QMC5883L_INIT_BASIC_LEVEL_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_INIT_HIGH_LEVEL_(KIBAR_QMC5883L_, KIBAR_OSR, KIBAR_RNG, KIBAR_ODR, KIBAR_MODE);
KIBAR_STATUS KIBAR_QMC5883L_INIT_HIGH_LEVEL_TWO_(KIBAR_QMC5883L_, KIBAR_OSR, KIBAR_RNG, KIBAR_ODR, KIBAR_MODE, uint8_t*);
KIBAR_AXIS_DATA KIBAR_QMC5883L_REGISTER_READ_AXIS_DATA_(KIBAR_QMC5883L_);
KIBAR_STATUS_DATA KIBAR_QMC5883L_REGISTER_READ_STATUS_DATA_(KIBAR_QMC5883L_);
KIBAR_QMC5883L_TEMPERATURE KIBAR_QMC5883L_REGISTER_READ_TEMPERATURE_(KIBAR_QMC5883L_);
KIBAR_QMC5883L_CHIP_ID KIBAR_QMC5883L_REGISTER_READ_CHIP_ID_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_IS_ACTIVE_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_OSR_(KIBAR_QMC5883L_, KIBAR_OSR);
KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_RNG_(KIBAR_QMC5883L_, KIBAR_RNG);
KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_ODR_(KIBAR_QMC5883L_, KIBAR_ODR);
KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_MODE_(KIBAR_QMC5883L_, KIBAR_MODE);
KIBAR_STATUS KIBAR_QMC5883L_SOFTWARE_RESET_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_ENABLE_ROL_POINTER_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_DISABLE_ROL_POINTER_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_ENABLE_INTERRUPT_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_DISABLE_INTERRUPT_(KIBAR_QMC5883L_);
KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_(KIBAR_QMC5883L_, uint8_t*);
KIBAR_STATUS KIBAR_QMC5883L_DELETE_(KIBAR_QMC5883L_);

#endif /* KIBAR_QMC5883L_INC_KIBAR_QMC5883L_H_ */
