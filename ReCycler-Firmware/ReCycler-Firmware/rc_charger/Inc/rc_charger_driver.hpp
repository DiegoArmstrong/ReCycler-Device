/*
 * charger_driver.hpp
 *
 *  Created on: Oct 16, 2025
 *      Author: diego
 */

#ifndef INC_RC_CHARGER_DRIVER_HPP_
#define INC_RC_CHARGER_DRIVER_HPP_

#include "../../rc_util/Inc/rc_data_types.hpp"
#include "../../rc_i2c/Inc/rc_i2c_driver.hpp"

/*!
* A type mapping a Charging IC's 8-bit I2C register to the register address.
*/
typedef struct {
    Charger8BitI2cRegisters_e chargerRegister;  /* The charger register with a corresponding address. */
    uint16_t registerAddress;                   /* The corresponding address. */
} ChargerRegisterToAddress_t;

extern const ChargerRegisterToAddress_t chargerRegisterToAddress[];

/*
* @brief   typedef enabling Input Source Control Register bit access.
*/
typedef union {

    struct {
        uint8_t inputCurrentLimit : 3;
        uint8_t inputVoltageLimit : 4;
        uint8_t enable : 1; 
    };
    uint8_t raw;

} InputSourceControlReg_t;

/*
* @brief   typedef enabling Power On Config Register bit access.
*/
typedef union {

    struct {
        uint8_t reserved : 1;
        uint8_t minSysVoltLimit : 3;
        uint8_t chargerConfig : 2;
        uint8_t watchdogTimer : 1;
        uint8_t registerReset : 1;
    };
    uint8_t raw;

} PowerOnConfigReg_t;

/*
* @brief   typedef enabling Charge Current Control Register bit access.
*/
typedef union {

    struct {
        uint8_t force20Pct : 1;
        uint8_t reserved : 1;
        uint8_t chargeCurrentLimit : 6;
    };
    uint8_t raw;

} ChargeCurrentControlReg_t;

/*
* @brief   typedef enabling Pre Charge Current Control Register bit access.
*/
typedef union {

    struct {
        uint8_t terminationCurrentLimit : 4;
        uint8_t preChargeCurrentLimit : 4;
    };
    uint8_t raw;

} PreChargeCurrentControlReg_t;

/*
* @brief   typedef enabling Charge Voltage Control Register bit access.
*/
typedef union {

    struct {
        uint8_t batteryRechargeThreshold : 1;
        uint8_t batteryPrechargeToFastChargeThreshold : 1;
        uint8_t chargeVoltageLimit : 6;
    };
    uint8_t raw;

} ChargeVoltageControl_t;

/*
* @brief   typedef enabling Charge Termination Control Register bit access.
*/
typedef union {

    struct {
        uint8_t reserved : 1;
        uint8_t fastChargerTimer : 2;
        uint8_t chargingSafetyTimerEnable : 1;
        uint8_t watchdogTimer : 2;
        uint8_t terminationIndicatorThreshold : 1;
        uint8_t chargingTerminationEnable : 1;
    };
    uint8_t raw;

} ChargeTerminationControlReg_t;

/*
* @brief   typedef enabling Thermal Regulation Control Register bit access.
*/
typedef union {

    struct {
        uint8_t thermalRegulationThreshold : 2;
        uint8_t reserved : 6;
    };
    uint8_t raw;

} ThermalRegulationControlReg_t;

/*
* @brief   typedef enabling System Status Register bit access.
*/
typedef union {

    struct {
        uint8_t voltageSystemStatus : 1;
        uint8_t thermalRegulationStatus : 1;
        uint8_t powerGoodStatus : 1;
        uint8_t dynamicPowerManagementStatus : 1;
        uint8_t chargingStatus : 2;
        uint8_t vbusStatus : 2;
    };
    uint8_t raw;
} SystemStatusReg_t;

/*
* @brief   typedef enabling Fault Register bit access.
*/
typedef union {

    struct {
        uint8_t thermistorFault : 3;
        uint8_t batteryOverVoltageFault : 1;
        uint8_t chargeFault : 2;
        uint8_t reserved : 1;
        uint8_t watchdogFault : 1;
    };
    uint8_t raw;

} FaultReg_t;

class ChargerDriver {
public: 

	/*!
	 * Default Constructor.
	 */
	explicit ChargerDriver(I2cDriver *i2cDriver);

    /*
     * @brief    Writes to the Input Source Control Register.
     */
   HAL_StatusTypeDef writeInputSrcCtrlReg(uint8_t data);

    /*
     * @brief   Reads data from the Input Source Control Register. 
     */
   HAL_StatusTypeDef readInputSrcCtrlReg(uint8_t &data);

private:
    I2cDriver *i2cDriver_;       /* The Charger Driver's I2C driver object. */

};

#endif /* INC_RC_CHARGER_DRIVER_HPP_ */
