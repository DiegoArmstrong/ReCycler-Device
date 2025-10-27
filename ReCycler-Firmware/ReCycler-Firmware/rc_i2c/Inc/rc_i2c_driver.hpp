/*
 * rc_i2c_driver.hpp
 *
 *  Created on: Oct 16, 2025
 *      Author: diego
 */

#ifndef INC_RC_I2C_DRIVER_HPP_
#define INC_RC_I2C_DRIVER_HPP_

#include "stm32f4xx_hal.h"
#include "../../rc_util/Inc/rc_data_types.hpp"

#define CHARGER_IC_ADDRESS	(0x6B << 1)

class I2cDriver {
public:

	/*!
	 * Default Constructor.
	 */
	I2cDriver(I2C_HandleTypeDef *i2cBusHandler);

	/*!
	 * @brief	Initializes the I2C Driver.
	 */
	HAL_StatusTypeDef init();

	/*!
	 *  @brief  Writes data to the selected I2C device.
	 */
	HAL_StatusTypeDef writeI2cData(I2cBusDevices_e device, uint8_t *data, uint16_t dataLen);

    /*!
     * @brief   Writes data to a the selected I2C device's 8-bit register. 
     */
    HAL_StatusTypeDef writeI2cReg8(I2cBusDevices_e device, uint16_t registerAddress, uint16_t registerAddressSize, uint8_t *data, uint16_t dataLen);

    /*!
     * @brief   Reads data from the selected I2C device.
     */
    HAL_StatusTypeDef readI2cData(I2cBusDevices_e device, uint8_t *data, uint16_t dataLen);

    /*!
     * @brief   Reads data from the selected I2C device's 8-bit register. 
     */
    HAL_StatusTypeDef readI2cReg8(I2cBusDevices_e device, uint16_t registerAddress, uint16_t registerAddressSize, uint8_t *data, uint16_t dataLen);



private:
	I2C_HandleTypeDef *halI2c_;		/* Pointer to an STM32 I2C handler. */
};




#endif /* INC_RC_I2C_DRIVER_HPP_ */
