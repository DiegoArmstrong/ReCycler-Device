################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../re_fsm/Src/rc_fsm.cpp 

OBJS += \
./re_fsm/Src/rc_fsm.o 

CPP_DEPS += \
./re_fsm/Src/rc_fsm.d 


# Each subdirectory must supply rules for building sources it contributes
re_fsm/Src/%.o re_fsm/Src/%.su re_fsm/Src/%.cyclo: ../re_fsm/Src/%.cpp re_fsm/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/diego/dev/ReCycler/ReCycler/re_fsm/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-re_fsm-2f-Src

clean-re_fsm-2f-Src:
	-$(RM) ./re_fsm/Src/rc_fsm.cyclo ./re_fsm/Src/rc_fsm.d ./re_fsm/Src/rc_fsm.o ./re_fsm/Src/rc_fsm.su

.PHONY: clean-re_fsm-2f-Src

