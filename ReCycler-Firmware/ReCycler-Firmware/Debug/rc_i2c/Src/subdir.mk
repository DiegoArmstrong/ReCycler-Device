################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../rc_i2c/Src/rc_i2c_driver.cpp \
../rc_i2c/Src/rc_i2c_mappings.cpp 

OBJS += \
./rc_i2c/Src/rc_i2c_driver.o \
./rc_i2c/Src/rc_i2c_mappings.o 

CPP_DEPS += \
./rc_i2c/Src/rc_i2c_driver.d \
./rc_i2c/Src/rc_i2c_mappings.d 


# Each subdirectory must supply rules for building sources it contributes
rc_i2c/Src/%.o rc_i2c/Src/%.su rc_i2c/Src/%.cyclo: ../rc_i2c/Src/%.cpp rc_i2c/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-rc_i2c-2f-Src

clean-rc_i2c-2f-Src:
	-$(RM) ./rc_i2c/Src/rc_i2c_driver.cyclo ./rc_i2c/Src/rc_i2c_driver.d ./rc_i2c/Src/rc_i2c_driver.o ./rc_i2c/Src/rc_i2c_driver.su ./rc_i2c/Src/rc_i2c_mappings.cyclo ./rc_i2c/Src/rc_i2c_mappings.d ./rc_i2c/Src/rc_i2c_mappings.o ./rc_i2c/Src/rc_i2c_mappings.su

.PHONY: clean-rc_i2c-2f-Src

