/*
 * charger_manager.cpp
 *
 *  Created on: Oct 16, 2025
 *      Author: diego
 */

#include "../../rc_charger/Inc/rc_charger_manager.hpp"
#include "../../rc_charger/Inc/rc_charger_driver.hpp"


/*!
 * Default Constructor.
 */
ChargerManager::ChargerManager(ChargerDriver *chargerDriver)
	: chargerDriver_(chargerDriver)
{}

/*
 * @brief	Initializes the Charger Manager and the Charger Driver.
 */
HAL_StatusTypeDef ChargerManager::init() {
	HAL_StatusTypeDef ret = HAL_OK;





	return HAL_OK;
}

HAL_StatusTypeDef ChargerManager::testI2cDriverFunc() {
    HAL_StatusTypeDef ret = HAL_OK;

    InputSourceControlReg_t inputSourceControlByte = {};

    inputSourceControlByte.inputCurrentLimit = 0b010;
    inputSourceControlByte.inputVoltageLimit = 0b0110;
    inputSourceControlByte.enable = 1;

    ret = chargerDriver_->writeInputSrcCtrlReg(inputSourceControlByte.raw);
    if(ret != HAL_OK) {
    	return ret;
    }

    inputSourceControlByte = {};

    ret = chargerDriver_->readInputSrcCtrlReg(inputSourceControlByte.raw);
    if(ret != HAL_OK) {
    	return ret;
    }

    if(inputSourceControlByte.raw != 0b01001101) {
    	return ret;
    }


    return HAL_OK;
}

