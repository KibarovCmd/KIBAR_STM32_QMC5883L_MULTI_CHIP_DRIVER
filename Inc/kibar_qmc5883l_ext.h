/*
 * kibar_qmc5883l_ext.h
 *
 *  Created on: Aug 5, 2024
 *      Author: İskender Musaoğlu
 */

#ifndef KIBAR_QMC5883L_INC_KIBAR_QMC5883L_EXT_H_
#define KIBAR_QMC5883L_INC_KIBAR_QMC5883L_EXT_H_

#include <kibar_qmc5883l_def.h>
#include <stm32f4xx_hal.h>

KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ONE_BIT_TO_REGISTER(I2C_HandleTypeDef*, uint8_t, uint8_t, uint8_t);
KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ZERO_BIT_TO_REGISTER(I2C_HandleTypeDef*, uint8_t, uint8_t, uint8_t);
KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ONE_ONE_BITS_TO_REGISTER(I2C_HandleTypeDef*, uint8_t, uint8_t, uint8_t);
KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ONE_ZERO_BITS_TO_REGISTER(I2C_HandleTypeDef*, uint8_t, uint8_t, uint8_t);
KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ZERO_ONE_BITS_TO_REGISTER(I2C_HandleTypeDef*, uint8_t, uint8_t, uint8_t);
KIBAR_STATUS KIBAR_I2C_WRITE_VALUE_ZERO_ZERO_BITS_TO_REGISTER(I2C_HandleTypeDef*, uint8_t, uint8_t, uint8_t);

#endif /* KIBAR_QMC5883L_INC_KIBAR_QMC5883L_EXT_H_ */
