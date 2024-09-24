/*
 * kibar_qmc5883l_basic.h
 *
 *  Created on: Aug 5, 2024
 *      Author: İskender Musaoğlu
 */

#ifndef KIBAR_QMC5883L_INC_KIBAR_QMC5883L_DEF_H_
#define KIBAR_QMC5883L_INC_KIBAR_QMC5883L_DEF_H_

#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*
 * Device Address
 */
#define KIBAR_ADDRESS_DEVICE_ (0x0D << 1)
/*
 * The following registers are those that hold the magnetic field values.
 */
#define KIBAR_REGISTER_DATA_OUTPUT_X_LSB_ (0x00)
#define KIBAR_REGISTER_DATA_OUTPUT_X_MSB_ (0x01)
#define	KIBAR_REGISTER_DATA_OUTPUT_Y_LSB_ (0x02)
#define KIBAR_REGISTER_DATA_OUTPUT_Y_MSB_ (0x03)
#define KIBAR_REGISTER_DATA_OUTPUT_Z_LSB_ (0x04)
#define KIBAR_REGISTER_DATA_OUTPUT_Z_MSB_ (0x05)
/*
 * This register holds flags such as interrupt, overflow, and data loss.
 */
#define	KIBAR_REGISTER_STATUS_ (0x06)
/*
 * These registers hold temperature values.
 */
#define KIBAR_REGISTER_TEMPERATURE_LSB_ (0x07)
#define KIBAR_REGISTER_TEMPERATURE_MSB_ (0x08)
/*
 * This register contains the OSG, RNG, ODR, and MODE configuration bits.
 * OVER SAMPLE RATIO (OSR) = 512, 256, 128, 64
 * FULL SCALE (RNG) = 8G, 2G
 * OUTPUT DATA RATE (ODR) = 200Hz, 100Hz, 50Hz, 10Hz
 * MODE = Standby, Continuous
 */
#define KIBAR_REGISTER_CONTROL_ONE_ (0x09)
/*
 * This register contains the SOFT_RST, ROL_PNT and INT_ENB configuration bits.
 * ||SOFT_RST||
 * If SOFT_RST is used, the device will be reset and return to standby mode.
 * ||ROL_PNT||
 * Pointer roll-over function is controlled by ROL_PNT register.
 * When the point roll-over function is enabled, the I2C data pointer automatically
 * Rolls between 00H ~ 06H, if I2C read begins at any address among 00H~06H.
 * ||INT_ENB||
 * Interrupt enabling is controlled by register INT_ENB in control register 2.
 * Once the interrupt is enabled, it will flag when new data is in Data Output Registers.
 */
#define KIBAR_REGISTER_CONTROL_TWO_ (0x0A)
/*
 * SET/RESET Period is controlled by FBR [7:0].
 * It is recommended that the register 0BH is written by 0x01.
 */
#define KIBAR_REGISTER_SET_RESET_PERIOD_ (0x0B)
/*
 * This register is chip identification register. It returns 0xFF.
 */
#define KIBAR_REGISTER_CHIP_ID_ (0x0D)

#define KIBAR_REGISTER_GENERAL_SIZE_ 1

#define KIBAR_TIMEOUT_ 50

typedef enum {
	kibar_FALSE = 0,
	kibar_TRUE
} KIBAR_BOOLEAN;

typedef enum {
	kibar_OK = 0,
	kibar_ERROR
} KIBAR_STATUS;

typedef enum {
	kibar_OSR_512 = 0x00,
	kibar_OSR_256 = 0x01,
	kibar_OSR_128 = 0x10,
	kibar_OSR_64 = 0x11
} KIBAR_OSR;

typedef enum {
	kibar_RNG_2G = 0x00,
	kibar_RNG_8G = 0x01
} KIBAR_RNG;

typedef enum {
	kibar_ODR_10Hz = 0x00,
	kibar_ODR_50Hz = 0x01,
	kibar_ODR_100Hz = 0x10,
	kibar_ODR_200Hz = 0x11
} KIBAR_ODR;

typedef enum {
	kibar_MODE_STANDBY = 0x00,
	kibar_MODE_CONTINUOUS = 0x01
} KIBAR_MODE;

/*
 * Axis variables are saved to objects of this structure type.
 */

typedef struct {
	int16_t kibar_DATA_AXIS_X;
	int16_t kibar_DATA_AXIS_Y;
	int16_t kibar_DATA_AXIS_Z;
} KIBAR_AXIS_DATA;

/*
 * Head angle variable from compass are saved to objects of this structure types.
 */

typedef uint16_t KIBAR_QMC5883L_HEAD_ANGLE;

/*
 * Status variables are saved to objects of this structure type.
 */

typedef struct {
	uint8_t kibar_DATA_INT_FLAG;
	uint8_t kibar_DATA_OVERFLOW_FLAG;
	uint8_t kibar_DATA_LOSS_FLAG;
} KIBAR_STATUS_DATA;

/*
 * Temperature and chip id variables are saved to objects of this structure types.
 */

typedef int16_t KIBAR_QMC5883L_TEMPERATURE;
typedef uint8_t KIBAR_QMC5883L_CHIP_ID;

#endif /* KIBAR_QMC5883L_INC_KIBAR_QMC5883L_DEF_H_ */
