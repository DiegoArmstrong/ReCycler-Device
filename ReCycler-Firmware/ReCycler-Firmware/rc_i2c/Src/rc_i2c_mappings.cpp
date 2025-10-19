/*
 * rc_i2c_mappings.cpp
 *
 *  Created on: Oct 17, 2025
 *      Author: diego
 */

#include "../../rc_i2c/Inc/rc_i2c_driver.hpp"
#include "../../rc_i2c/Inc/rc_i2c_mappings.hpp"

const DeviceToI2cAddress_t deviceToI2cAddressLut[] = {
	{I2C_BUS_DEVICE_CHARGER_IC, CHARGER_IC_ADDRESS},

	{I2C_BUS_DEVICE_MAX, 0U},
};




