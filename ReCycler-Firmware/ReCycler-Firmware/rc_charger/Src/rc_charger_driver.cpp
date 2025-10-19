/*
 * charger_driver.cpp
 *
 *  Created on: Oct 16, 2025
 *      Author: diego
 */

#include "stm32f4xx_hal.h"
#include "../../rc_util/Inc/rc_data_types.hpp"
#include "../../rc_charger/Inc/rc_charger_driver.hpp"

const ChargerRegisterToAddress_t chargerRegisterToAddress[] = {
    {INPUT_SOURCE_CONTROL_REG, 0x00},
    {POWER_ON_CONFIG_REG, 0x01},
    {CHARGE_CURRENT_CONTROL_REG, 0x02},
    {PRECHARGE_CURRENT_CONTROL_REG, 0x03},
    {CHARGE_VOLTAGE_CONTROL_REG, 0x04},
    {CHARGE_TERMINATION_CONTROL_REG, 0x05},
    {THERMAL_REGULATION_CONTROL_REG, 0x06},
    {SYSTEM_STATUS_REG, 0x08},
    {FAULT_REG, 0x09},

    {REGISTER_MAX, 0U},
};

static HAL_StatusTypeDef retrieveAddressFromChargerRegister(Charger8BitI2cRegisters_e registerType, uint16_t &address) {
    uint16_t lutIndex = 0U;

    while(chargerRegisterToAddress[lutIndex].chargerRegister != REGISTER_MAX) {
        if(chargerRegisterToAddress[lutIndex].chargerRegister == registerType) {
            address = chargerRegisterToAddress[lutIndex].registerAddress;
            break;
        }
        lutIndex++;
    }

    return HAL_OK;
}


/*!
 * Default Constructor.
 */
ChargerDriver::ChargerDriver() {}

/*
 * @brief    Writes to the Input Source Control Register.
 */
HAL_StatusTypeDef ChargerDriver::writeInputSrcCtrlReg(uint8_t data) {
    HAL_StatusTypeDef ret = HAL_OK;




    return HAL_OK;
}