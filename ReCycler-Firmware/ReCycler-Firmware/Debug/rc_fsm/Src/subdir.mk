################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../rc_fsm/Src/rc_fsm.cpp 

OBJS += \
./rc_fsm/Src/rc_fsm.o 

CPP_DEPS += \
./rc_fsm/Src/rc_fsm.d 


# Each subdirectory must supply rules for building sources it contributes
rc_fsm/Src/%.o rc_fsm/Src/%.su rc_fsm/Src/%.cyclo: ../rc_fsm/Src/%.cpp rc_fsm/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-rc_fsm-2f-Src

clean-rc_fsm-2f-Src:
	-$(RM) ./rc_fsm/Src/rc_fsm.cyclo ./rc_fsm/Src/rc_fsm.d ./rc_fsm/Src/rc_fsm.o ./rc_fsm/Src/rc_fsm.su

.PHONY: clean-rc_fsm-2f-Src

