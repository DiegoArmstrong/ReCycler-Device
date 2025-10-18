/*
 * rc_fsm.cpp
 *
 *  Created on: Oct 1, 2025
 *      Author: diego
 */

#include "../../rc_fsm/Inc/rc_fsm.hpp"
#include "../../rc_i2c/Inc/rc_i2c_driver.hpp"


#define FOREVER     1	/* Forever loop condition. */

/*!
 * Default Constructor.
 */
ReCyclerFSM::ReCyclerFSM() : rcState_(RC_STATE_INIT), chargerManager_() {}

/*!
 * @brief	Starts the ReCycler's FSM.
 */
HAL_StatusTypeDef ReCyclerFSM::rcFsmStart() {
	do {

		switch (rcState_) {

		case RC_STATE_INIT:
			rcFsmStateInit();
			break;

		case RC_STATE_PRECHECK:
			rcFsmStatePreCheck();
			break;

		case RC_STATE_CHARGING:
			rcFsmStateCharging();
			break;

		case RC_STATE_DISCHARGING:
			rcFsmStateDischarging();
			break;

		case RC_STATE_FAULT:
			rcFsmStateFault();
			break;
		}

	} while(FOREVER);
}

/*!
 * @brief	Initializes the ReCycler's FSM.
 */
HAL_StatusTypeDef ReCyclerFSM::rcFsmStateInit() {

	HAL_StatusTypeDef ret = HAL_OK;

	/* Initialize the Charger Manager. */
	ret = chargerManager_.init();
	if(ret != HAL_OK) {
		return ret;
	}




	return HAL_OK;
}

/*!
 * @brief	Ensures that the ReCycler is safe to engage in Charging or Discharging.
 */
HAL_StatusTypeDef ReCyclerFSM::rcFsmStatePreCheck() {


	return HAL_OK;
}

/*!
 * @brief	Charges the battery.
 */
HAL_StatusTypeDef ReCyclerFSM::rcFsmStateCharging() {


	return HAL_OK;
}

/*!
 * @brief	Discharges the battery.
 */
HAL_StatusTypeDef ReCyclerFSM::rcFsmStateDischarging() {

	return HAL_OK;
}

/*!
 * @brief	Handles the ReCycler's fault state.
 */
HAL_StatusTypeDef ReCyclerFSM::rcFsmStateFault() {


	return HAL_OK;
}







