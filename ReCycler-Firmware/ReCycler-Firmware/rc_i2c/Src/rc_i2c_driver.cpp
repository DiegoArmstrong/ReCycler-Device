/*
 * rc_i2c_driver.cpp
 *
 *  Created on: Oct 16, 2025
 *      Author: diego
 */

#include "../../rc_i2c/Inc/rc_i2c_driver.hpp"
#include "../../rc_i2c/Inc/rc_i2c_mappings.hpp"

#define I2C_COMMS_TIMEOUT_DEFAULT	500		/* The default I2C comms timeout duration in ms.  */

/*!
 * Default Constructor.
 */
I2cDriver::I2cDriver(I2C_HandleTypeDef *i2cBusHandler) {
	halI2c_ = i2cBusHandler;
}

/*!
 *	@brief	Retrieves an I2C device address from a I2C Bus Device enum.
 */
static HAL_StatusTypeDef retrieveI2cAddressFromDevice(I2cBusDevices_e device, uint16_t &address) {
	uint16_t lutIndex = 0U;

	while(deviceToI2cAddressLut[lutIndex].i2cDevice != I2C_BUS_DEVICE_MAX) {
		if(device == deviceToI2cAddressLut[lutIndex].i2cDevice) {
			address = deviceToI2cAddressLut[lutIndex].i2cDevice;
			break;
		}

		lutIndex++;
	}
	if(deviceToI2cAddressLut[lutIndex].i2cDevice == I2C_BUS_DEVICE_MAX) {
		return HAL_ERROR;
	}

	return HAL_OK;
}

/*!
 *  Writes data to the selected I2C device.
 */
HAL_StatusTypeDef I2cDriver::writeI2cData(I2cBusDevices_e device, uint8_t *data, uint16_t dataLen) {
	HAL_StatusTypeDef ret = HAL_OK;

	uint16_t address = 0U;

    /* Validate the data pointer. */
    if(data == nullptr) {
        return HAL_ERROR;
    }

	/* Retrieve the device's I2C address. */
	ret = retrieveI2cAddressFromDevice(device, address);
	if(ret != HAL_OK) {
		return ret;
	}

	/* Transmit the data to the device over I2C. */
	ret = HAL_I2C_Master_Transmit(halI2c_, address, data, dataLen, I2C_COMMS_TIMEOUT_DEFAULT);
	if(ret != HAL_OK) {
		return ret;
	}

	return HAL_OK;
}

/*!
 * Writes data to a the selected I2C device's 8-bit register. 
 */
HAL_StatusTypeDef I2cDriver::writeI2cReg8(I2cBusDevices_e device, uint16_t registerAddress, uint16_t registerAddressSize, uint8_t *data, uint16_t dataLen) {
    HAL_StatusTypeDef ret = HAL_OK;

    uint16_t deviceAddress = 0U;

    /* Validate the data pointer. */
    if(data == nullptr) {
        return HAL_ERROR;
    }

	/* Retrieve the device's I2C address. */
	ret = retrieveI2cAddressFromDevice(device, deviceAddress);
	if(ret != HAL_OK) {
		return ret;
	}

    /* Transmit the data to the 8-bit register. */
    ret = HAL_I2C_Mem_Write(halI2c_, deviceAddress, registerAddress, registerAddressSize, data, dataLen, I2C_COMMS_TIMEOUT_DEFAULT);
    if(ret != HAL_OK) {
        return ret;
    }

    return HAL_OK;
}

/*!
 * @brief   Reads data from the selected I2C device.
 */
HAL_StatusTypeDef I2cDriver::readI2cData(I2cBusDevices_e device, uint8_t *data, uint16_t dataLen) {
    HAL_StatusTypeDef ret = HAL_OK;

    uint16_t deviceAddress = 0U;

    /* Validate the data pointer. */
    if(data == nullptr) {
        return HAL_ERROR;
    }

	/* Retrieve the device's I2C address. */
	ret = retrieveI2cAddressFromDevice(device, deviceAddress);
	if(ret != HAL_OK) {
		return ret;
	}

    /* Receive data from the device over I2C. */
    HAL_I2C_Master_Receive(halI2c_, deviceAddress, data, dataLen, I2C_COMMS_TIMEOUT_DEFAULT);
    if(ret != HAL_OK) {
        return ret;
    }

    return HAL_OK;
}

/*!
 * @brief   Reads data from the selected I2C device's 8-bit register. 
 */
HAL_StatusTypeDef I2cDriver::readI2cReg8(I2cBusDevices_e device, uint16_t registerAddress, uint16_t registerAddressSize, uint8_t *data, uint16_t dataLen) {
    HAL_StatusTypeDef ret = HAL_OK;

    uint16_t deviceAddress = 0U;

    /* Validate the data pointer. */
    if(data == nullptr) {
        return HAL_ERROR;
    }

	/* Retrieve the device's I2C address. */
	ret = retrieveI2cAddressFromDevice(device, deviceAddress);
	if(ret != HAL_OK) {
		return ret;
	}

    /* Receive the data to the 8-bit register. */
    ret = HAL_I2C_Mem_Read(halI2c_, deviceAddress, registerAddress, registerAddressSize, data, dataLen, I2C_COMMS_TIMEOUT_DEFAULT);
    if(ret != HAL_OK) {
        return ret;
    }

    return HAL_OK;
}
