/*
 * kibar_gmc5883l_ext.c
 *
 *  Created on: Aug 5, 2024
 *      Author: İskender Musaoğlu
 */

#include <kibar_qmc5883l_ext.h>

KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(I2C_HandleTypeDef* kibar_i2c, uint8_t shift_value, uint8_t device_address, uint8_t register_address) {
	uint8_t register_data;
	HAL_StatusTypeDef statusone = HAL_I2C_Mem_Read(kibar_i2c, device_address, register_data, KIBAR_REGISTER_GENERAL_SIZE_, &register_data, KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	if(statusone != HAL_OK) return kibar_ERROR;
	register_data = register_data | (0x01 << shift_value);
	statusone = HAL_I2C_Mem_Write(kibar_i2c, device_address, register_data, KIBAR_REGISTER_GENERAL_SIZE_, &register_data, KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	if(statusone != HAL_OK) return kibar_ERROR;
	else return kibar_OK;
}

KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(I2C_HandleTypeDef* kibar_i2c, uint8_t shift_value, uint8_t device_address, uint8_t register_address) {
	uint8_t register_data;
	HAL_StatusTypeDef statusone = HAL_I2C_Mem_Read(kibar_i2c, device_address, register_data, KIBAR_REGISTER_GENERAL_SIZE_, &register_data, KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	if(statusone != HAL_OK) return kibar_ERROR;
	register_data = register_data & (~(0x01) << shift_value);
	statusone = HAL_I2C_Mem_Write(kibar_i2c, device_address, register_data, KIBAR_REGISTER_GENERAL_SIZE_, &register_data, KIBAR_REGISTER_GENERAL_SIZE_, KIBAR_TIMEOUT_);
	if(statusone != HAL_OK) return kibar_ERROR;
	else return kibar_OK;
}

KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ONE_ONE_BITS_TO_REGISTER(I2C_HandleTypeDef* kibar_i2c, uint8_t shift_value, uint8_t device_address, uint8_t register_address) {
	KIBAR_STATUS statusone = KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(kibar_i2c, shift_value + 1, device_address, register_address);
	KIBAR_STATUS statustwo = KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(kibar_i2c, shift_value, device_address, register_address);
	if(statusone + statustwo == (uint8_t)kibar_FALSE) return kibar_OK;
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ONE_ZERO_BITS_TO_REGISTER(I2C_HandleTypeDef* kibar_i2c, uint8_t shift_value, uint8_t device_address, uint8_t register_address) {
	KIBAR_STATUS statusone = KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(kibar_i2c, shift_value + 1, device_address, register_address);
	KIBAR_STATUS statustwo = KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(kibar_i2c, shift_value, device_address, register_address);
	if(statusone + statustwo == (uint8_t)kibar_FALSE) return kibar_OK;
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ZERO_ONE_BITS_TO_REGISTER(I2C_HandleTypeDef* kibar_i2c, uint8_t shift_value, uint8_t device_address, uint8_t register_address) {
	KIBAR_STATUS statusone = KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(kibar_i2c, shift_value + 1, device_address, register_address);
	KIBAR_STATUS statustwo = KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(kibar_i2c, shift_value, device_address, register_address);
	if(statusone + statustwo == (uint8_t)kibar_FALSE) return kibar_OK;
	else return kibar_ERROR;
}

KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ZERO_ZERO_BITS_TO_REGISTER(I2C_HandleTypeDef* kibar_i2c, uint8_t shift_value, uint8_t device_address, uint8_t register_address) {
	KIBAR_STATUS statusone = KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(kibar_i2c, shift_value + 1, device_address, register_address);
	KIBAR_STATUS statustwo = KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(kibar_i2c, shift_value, device_address, register_address);
	if(statusone + statustwo == (uint8_t)kibar_FALSE) return kibar_OK;
	else return kibar_ERROR;
}
