/*
 * rc_i2c_mappings.hpp
 *
 *  Created on: Oct 17, 2025
 *      Author: diego
 */

#ifndef INC_RC_I2C_MAPPINGS_HPP_
#define INC_RC_I2C_MAPPINGS_HPP_

#include "../../rc_util/Inc/rc_data_types.hpp"

/*!
 * A type mapping a device to its corresponding I2C address.
 */
typedef struct {
	I2cBusDevices_e i2cDevice;	/* The device with an associated I2C address. */
	uint8_t i2cAddress;			/* The associated I2C address. */
} DeviceToI2cAddress_t;

extern const DeviceToI2cAddress_t deviceToI2cAddressLut[];

#endif /* INC_RC_I2C_MAPPINGS_HPP_ */

