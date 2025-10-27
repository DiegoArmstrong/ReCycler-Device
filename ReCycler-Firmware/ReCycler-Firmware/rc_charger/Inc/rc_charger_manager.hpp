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
	explicit ChargerManager(ChargerDriver *chargerDriver);

	/*
	 * @brief	Initializes the Charger Manager.
	 */
	HAL_StatusTypeDef init();

	HAL_StatusTypeDef testI2cDriverFunc();


private:
    ChargerDriver *chargerDriver_{nullptr};   /* The charger manager's charger driver object. */

};



#endif /* INC_RC_CHARGER_MANAGER_HPP_ */
