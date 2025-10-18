/*
 * rc_data_types.hpp
 *
 *  Created on: Oct 17, 2025
 *      Author: diego
 */

#ifndef INC_RC_DATA_TYPES_HPP_
#define INC_RC_DATA_TYPES_HPP_

#include "stm32f4xx_hal.h"

/*!
 * An enumeration describing the different possible FSM states for the ReCycler.
 */
typedef enum {
	RC_STATE_INIT,
	RC_STATE_PRECHECK,
	RC_STATE_CHARGING,
	RC_STATE_DISCHARGING,
	RC_STATE_FAULT,

	RC_STATE_MAX,
} RcState_e;

/*!
 * An enumeration describing the different I2C devices on the ReCycler I2C bus(ses).
 */
typedef enum {
	I2C_BUS_DEVICE_CHARGER_IC,

	I2C_BUS_DEVICE_MAX,
} I2cBusDevices_e;



#endif /* INC_RC_DATA_TYPES_HPP_ */
