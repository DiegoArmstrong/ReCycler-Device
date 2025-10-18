/*
 * rc_fsm.hpp
 *
 *  Created on: Oct 1, 2025
 *      Author: diego
 */

#ifndef INC_RC_FSM_HPP_
#define INC_RC_FSM_HPP_

#include "stm32f4xx_hal.h"

#include "../../rc_charger/Inc/rc_charger_manager.hpp"
#include "../../rc_i2c/Inc/rc_i2c_driver.hpp"
#include "../../rc_util/Inc/rc_data_types.hpp"

class ReCyclerFSM {
public:

	/*!
	 * Default Constructor.  
     */ 
    ReCyclerFSM(); 
     
    /*!
     * @brief	Starts the ReCycler's FSM.
     */
	HAL_StatusTypeDef rcFsmStart();

	/*!
	 * @brief	Initializes the ReCycler's FSM.
	 */
	HAL_StatusTypeDef rcFsmStateInit();

	/*!
	 * @brief	Ensures that the ReCycler is safe to engage in Charging or Discharging.
	 */
	HAL_StatusTypeDef rcFsmStatePreCheck();

	/*!
	 * @brief	Charges the battery.
	 */
	HAL_StatusTypeDef rcFsmStateCharging();

	/*!
	 * @brief	Discharges the battery.
	 */
	HAL_StatusTypeDef rcFsmStateDischarging();

	/*!
	 * @brief	Handles the ReCycler's fault state.
	 */
	HAL_StatusTypeDef rcFsmStateFault();




private:
	RcState_e rcState_;					/*!< The state of the ReCycler. */

	ChargerManager chargerManager_;		/* The ReCycler FSM's Charger Manager object. */
};



#endif /* INC_RC_FSM_HPP_ */
