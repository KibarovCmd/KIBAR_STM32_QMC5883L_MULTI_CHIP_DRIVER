/*
 * kibar_qmc5883l.c
 *
 *  Created on: Aug 5, 2024
 *      Author: İskender Musaoğlu
 */

#include <kibar_qmc5883l.h>

KIBAR_QMC5883L_ NEW_KIBAR_QMC5883L(I2C_HandleTypeDef* kibar_i2c_) {
	KIBAR_QMC5883L_ kibar_qmc5883l = (KIBAR_QMC5883L_)malloc(sizeof(struct KIBAR_QMC5883L));
	kibar_qmc5883l->kibar_i2c_ = kibar_i2c_;
	kibar_qmc5883l->kibar_interrupt_enable = kibar_TRUE;
	kibar_qmc5883l->kibar_rol_pointer_enable = kibar_FALSE;
	kibar_qmc5883l->KIBAR_QMC5883L_INIT_BASIC_LEVEL_ = &KIBAR_QMC5883L_INIT_BASIC_LEVEL_;
	kibar_qmc5883l->KIBAR_QMC5883L_INIT_HIGH_LEVEL_  = &KIBAR_QMC5883L_INIT_HIGH_LEVEL_;
	kibar_qmc5883l->KIBAR_QMC5883L_INIT_HIGH_LEVEL_TWO_ = &KIBAR_QMC5883L_INIT_HIGH_LEVEL_TWO_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_READ_AXIS_DATA_ = &KIBAR_QMC5883L_REGISTER_READ_AXIS_DATA_;
	kibar_qmc5883l->KIBAR_QMC5883L_GET_ANGLE_ = &KIBAR_QMC5883L_REGISTER_READ_AXIS_DATA_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_READ_STATUS_DATA_ = &KIBAR_QMC5883L_REGISTER_READ_STATUS_DATA_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_READ_TEMPERATURE_ = &KIBAR_QMC5883L_REGISTER_READ_TEMPERATURE_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_READ_CHIP_ID_ = &KIBAR_QMC5883L_REGISTER_READ_CHIP_ID_;
	kibar_qmc5883l->KIBAR_QMC5883L_IS_ACTIVE_ = &KIBAR_QMC5883L_IS_ACTIVE_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_WRITE_OSR_ = &KIBAR_QMC5883L_REGISTER_WRITE_OSR_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_WRITE_RNG_ = &KIBAR_QMC5883L_REGISTER_WRITE_RNG_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_WRITE_ODR_ = &KIBAR_QMC5883L_REGISTER_WRITE_ODR_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_WRITE_MODE_ = &KIBAR_QMC5883L_REGISTER_WRITE_MODE_;
	kibar_qmc5883l->KIBAR_QMC5883L_SOFTWARE_RESET_ = &KIBAR_QMC5883L_SOFTWARE_RESET_;
	kibar_qmc5883l->KIBAR_QMC5883L_ENABLE_ROL_POINTER_ = &KIBAR_QMC5883L_ENABLE_ROL_POINTER_;
	kibar_qmc5883l->KIBAR_QMC5883L_DISABLE_ROL_POINTER_ = &KIBAR_QMC5883L_DISABLE_ROL_POINTER_;
	kibar_qmc5883l->KIBAR_QMC5883L_ENABLE_INTERRUPT_ = &KIBAR_QMC5883L_ENABLE_INTERRUPT_;
	kibar_qmc5883l->KIBAR_QMC5883L_DISABLE_INTERRUPT_ = &KIBAR_QMC5883L_DISABLE_INTERRUPT_;
	kibar_qmc5883l->KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_ = &KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_;
	kibar_qmc5883l->KIBAR_QMC5883L_DELETE_ = &KIBAR_QMC5883L_DELETE_;
	return kibar_qmc5883l;
}

KIBAR_STATUS KIBAR_QMC5883L_INIT_BASIC_LEVEL_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	uint8_t kibar_data[3] = {0x00, 0x01, 0x11};
	KIBAR_STATUS statusone = KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_(kibar_qmc5883l_, &kibar_data[1]);
	KIBAR_STATUS statustwo = KIBAR_QMC5883L_REGISTER_WRITE_ODR_(kibar_qmc5883l_, kibar_ODR_10Hz);
	KIBAR_STATUS statusthree= KIBAR_QMC5883L_REGISTER_WRITE_RNG_(kibar_qmc5883l_, kibar_RNG_8G);
	KIBAR_STATUS statusfour = KIBAR_QMC5883L_REGISTER_WRITE_OSR_(kibar_qmc5883l_, kibar_OSR_64);
	KIBAR_STATUS statusfive = KIBAR_QMC5883L_REGISTER_WRITE_MODE_(kibar_qmc5883l_, kibar_MODE_CONTINUOUS);
	if((statusone + statustwo + statusthree + statusfour + statusfive) == (uint8_t)kibar_FALSE) return kibar_OK;
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_QMC5883L_INIT_HIGH_LEVEL_(KIBAR_QMC5883L_ kibar_qmc5883l_, KIBAR_OSR kibar_osr, KIBAR_RNG kibar_rng, KIBAR_ODR kibar_odr, KIBAR_MODE kibar_mode) {
	uint8_t kibar_data[1] = {0x01};
	KIBAR_STATUS statusone = KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_(kibar_qmc5883l_, kibar_data);
	KIBAR_STATUS statustwo = KIBAR_QMC5883L_REGISTER_WRITE_ODR_(kibar_qmc5883l_, kibar_odr);
	KIBAR_STATUS statusthree= KIBAR_QMC5883L_REGISTER_WRITE_RNG_(kibar_qmc5883l_, kibar_rng);
	KIBAR_STATUS statusfour = KIBAR_QMC5883L_REGISTER_WRITE_OSR_(kibar_qmc5883l_, kibar_osr);
	KIBAR_STATUS statusfive = KIBAR_QMC5883L_REGISTER_WRITE_MODE_(kibar_qmc5883l_, kibar_mode);
	if((statusone + statustwo + statusthree + statusfour + statusfive) == (uint8_t)kibar_FALSE) return kibar_OK;
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_QMC5883L_INIT_HIGH_LEVEL_TWO_(KIBAR_QMC5883L_ kibar_qmc5883l_, KIBAR_OSR kibar_osr, KIBAR_RNG kibar_rng, KIBAR_ODR kibar_odr, KIBAR_MODE kibar_mode, uint8_t* set_reset_period) {
	KIBAR_STATUS statusone = KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_(kibar_qmc5883l_, set_reset_period);
	KIBAR_STATUS statustwo = KIBAR_QMC5883L_REGISTER_WRITE_ODR_(kibar_qmc5883l_, kibar_odr);
	KIBAR_STATUS statusthree= KIBAR_QMC5883L_REGISTER_WRITE_RNG_(kibar_qmc5883l_, kibar_rng);
	KIBAR_STATUS statusfour = KIBAR_QMC5883L_REGISTER_WRITE_OSR_(kibar_qmc5883l_, kibar_osr);
	KIBAR_STATUS statusfive = KIBAR_QMC5883L_REGISTER_WRITE_MODE_(kibar_qmc5883l_, kibar_mode);
	if((statusone + statustwo + statusthree + statusfour + statusfive) == (uint8_t)kibar_FALSE) return kibar_OK;
	else return kibar_ERROR;
}

KIBAR_AXIS_DATA KIBAR_QMC5883L_REGISTER_READ_AXIS_DATA_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	KIBAR_AXIS_DATA kibar_data; uint8_t kibar_axis_data[6];
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_DATA_OUTPUT_X_MSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[0], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_DATA_OUTPUT_X_LSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[1], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_DATA_OUTPUT_Y_MSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[2], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_DATA_OUTPUT_Y_LSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[3], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_DATA_OUTPUT_Z_MSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[4], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_DATA_OUTPUT_Z_LSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[5], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	kibar_data.kibar_DATA_AXIS_X = (int16_t)((kibar_axis_data[0] << 8) | kibar_axis_data[1]);
	kibar_data.kibar_DATA_AXIS_Y = (int16_t)((kibar_axis_data[2] << 8) | kibar_axis_data[3]);
	kibar_data.kibar_DATA_AXIS_Z = (int16_t)((kibar_axis_data[4] << 8) | kibar_axis_data[5]);
	return kibar_data;
}

KIBAR_QMC5883L_HEAD_ANGLE KIBAR_QMC5883L_GET_ANGLE_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	KIBAR_AXIS_DATA kibar_data = KIBAR_QMC5883L_REGISTER_READ_AXIS_DATA_(kibar_qmc5883l_);
	KIBAR_QMC5883L_HEAD_ANGLE head_angle = atan2(kibar_data.kibar_DATA_AXIS_Y, kibar_data.kibar_DATA_AXIS_X) * (180.0 / M_PI);
	if((uint16_t)head_angle < 0) (uint16_t)head_angle = (uint16_t)head_angle + 360;
	return head_angle;
}

KIBAR_STATUS_DATA KIBAR_QMC5883L_REGISTER_READ_STATUS_DATA_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	KIBAR_STATUS_DATA kibar_data; uint8_t kibar_axis_data[1];
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_STATUS_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[0], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	kibar_data.kibar_DATA_INT_FLAG = (kibar_axis_data[0] >> 0) & 0x01;
	kibar_data.kibar_DATA_LOSS_FLAG = (kibar_axis_data[0] >> 1) & 0x01;
	kibar_data.kibar_DATA_OVERFLOW_FLAG = (kibar_axis_data[0] >> 2) & 0x01;
	return kibar_data;
}

KIBAR_QMC5883L_TEMPERATURE KIBAR_QMC5883L_REGISTER_READ_TEMPERATURE_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	KIBAR_QMC5883L_TEMPERATURE kibar_data; uint8_t kibar_axis_data[2];
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_TEMPERATURE_MSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[0], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_TEMPERATURE_LSB_, KIBAR_REGISTER_GENERAL_SIZE_, &kibar_axis_data[1], KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	kibar_data = ((kibar_axis_data[0] << 8) | kibar_axis_data[1]);
	return kibar_data;
}

KIBAR_QMC5883L_CHIP_ID KIBAR_QMC5883L_REGISTER_READ_CHIP_ID_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	KIBAR_QMC5883L_CHIP_ID kibar_id[1];
	HAL_I2C_Mem_Read(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CHIP_ID_, KIBAR_REGISTER_GENERAL_SIZE_, (uint8_t*)kibar_id, KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	return kibar_id[0];
}

KIBAR_STATUS KIBAR_QMC5883L_IS_ACTIVE_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	if(KIBAR_QMC5883L_REGISTER_READ_CHIP_ID_(kibar_qmc5883l_) == 0xFF) return kibar_OK;
	else return kibar_FALSE;
}

KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_OSR_(KIBAR_QMC5883L_ kibar_qmc5883l_, KIBAR_OSR kibar_osr) {
	if(kibar_osr == kibar_OSR_512) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ZERO_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 6, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_osr == kibar_OSR_256) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ONE_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 6, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_osr == kibar_OSR_128) {
		return KIBAR_I2C_WRITE_VALUE_ONE_ZERO_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 6, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_osr == kibar_OSR_64) {
		return KIBAR_I2C_WRITE_VALUE_ONE_ONE_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 6, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_RNG_(KIBAR_QMC5883L_ kibar_qmc5883l_, KIBAR_RNG kibar_rng) {
	if(kibar_rng == kibar_RNG_2G) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ZERO_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 4, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_rng == kibar_RNG_8G) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ONE_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 4, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_ODR_(KIBAR_QMC5883L_ kibar_qmc5883l_, KIBAR_ODR kibar_odr) {
	if(kibar_odr == kibar_ODR_10Hz) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ZERO_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 2, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_odr == kibar_ODR_50Hz) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ONE_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 2, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_odr == kibar_ODR_100Hz) {
		return KIBAR_I2C_WRITE_VALUE_ONE_ZERO_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 2, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_odr == kibar_ODR_200Hz) {
		return KIBAR_I2C_WRITE_VALUE_ONE_ONE_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 2, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_MODE_(KIBAR_QMC5883L_ kibar_qmc5883l_, KIBAR_MODE kibar_mode) {
	if(kibar_mode == kibar_MODE_STANDBY) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ZERO_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 0, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else if(kibar_mode == kibar_MODE_CONTINUOUS) {
		return KIBAR_I2C_WRITE_VALUE_ZERO_ONE_BITS_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 0, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_ONE_);
	}
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_QMC5883L_SOFTWARE_RESET_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	return KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 7, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_TWO_);
}

KIBAR_STATUS KIBAR_QMC5883L_ENABLE_ROL_POINTER_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	if(kibar_qmc5883l_->kibar_rol_pointer_enable == kibar_TRUE) {
		return kibar_ERROR;
	}
	else {
		kibar_qmc5883l_->kibar_rol_pointer_enable = kibar_TRUE;
		return KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 6, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_TWO_);
	}
}

KIBAR_STATUS KIBAR_QMC5883L_DISABLE_ROL_POINTER_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	if(kibar_qmc5883l_->kibar_rol_pointer_enable == kibar_FALSE) {
		return kibar_ERROR;
	}
	else {
		kibar_qmc5883l_->kibar_rol_pointer_enable = kibar_FALSE;
		return KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 6, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_TWO_);
	}
}

KIBAR_STATUS KIBAR_QMC5883L_ENABLE_INTERRUPT_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	if(kibar_qmc5883l_->kibar_interrupt_enable == kibar_TRUE) {
		return kibar_ERROR;
	}
	else {
		kibar_qmc5883l_->kibar_interrupt_enable = kibar_TRUE;
		return KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 0, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_TWO_);
	}
}

KIBAR_STATUS KIBAR_QMC5883L_DISABLE_INTERRUPT_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	if(kibar_qmc5883l_->kibar_interrupt_enable == kibar_FALSE) {
		return kibar_ERROR;
	}
	else {
		kibar_qmc5883l_->kibar_interrupt_enable = kibar_FALSE;
		return KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(kibar_qmc5883l_->kibar_i2c_, 0, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_CONTROL_TWO_);
	}
}

KIBAR_STATUS KIBAR_QMC5883L_REGISTER_WRITE_SET_RESET_PERIOD_(KIBAR_QMC5883L_ kibar_qmc5883l_, uint8_t* data) {
	if(HAL_I2C_Mem_Write(kibar_qmc5883l_->kibar_i2c_, KIBAR_ADDRESS_DEVICE_, KIBAR_REGISTER_SET_RESET_PERIOD_, KIBAR_REGISTER_GENERAL_SIZE_, data, KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_) == (uint8_t)kibar_FALSE) {
		return kibar_OK;
	}
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_QMC5883L_DELETE_(KIBAR_QMC5883L_ kibar_qmc5883l_) {
	free(kibar_qmc5883l_);
	return kibar_TRUE;
}
