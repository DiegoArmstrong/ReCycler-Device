################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../rc_charger/Src/rc_charger_driver.cpp \
../rc_charger/Src/rc_charger_manager.cpp 

OBJS += \
./rc_charger/Src/rc_charger_driver.o \
./rc_charger/Src/rc_charger_manager.o 

CPP_DEPS += \
./rc_charger/Src/rc_charger_driver.d \
./rc_charger/Src/rc_charger_manager.d 


# Each subdirectory must supply rules for building sources it contributes
rc_charger/Src/%.o rc_charger/Src/%.su rc_charger/Src/%.cyclo: ../rc_charger/Src/%.cpp rc_charger/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-rc_charger-2f-Src

clean-rc_charger-2f-Src:
	-$(RM) ./rc_charger/Src/rc_charger_driver.cyclo ./rc_charger/Src/rc_charger_driver.d ./rc_charger/Src/rc_charger_driver.o ./rc_charger/Src/rc_charger_driver.su ./rc_charger/Src/rc_charger_manager.cyclo ./rc_charger/Src/rc_charger_manager.d ./rc_charger/Src/rc_charger_manager.o ./rc_charger/Src/rc_charger_manager.su

.PHONY: clean-rc_charger-2f-Src

