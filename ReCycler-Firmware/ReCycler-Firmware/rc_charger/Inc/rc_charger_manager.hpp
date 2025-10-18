/*
 * charger_manager.hpp
 *
 *  Created on: Oct 16, 2025
 *      Author: diego
 */

#ifndef INC_RC_CHARGER_MANAGER_HPP_
#define INC_RC_CHARGER_MANAGER_HPP_

#include "stm32f4xx_hal.h"
#include "rc_charger_driver.hpp"

class ChargerManager {

public:

	/*!
	 * Default Constructor.
	 */
	ChargerManager();

	/*
	 * @brief	Initializes the Charger Manager.
	 */
	HAL_StatusTypeDef init();



};



#endif /* INC_RC_CHARGER_MANAGER_HPP_ */
