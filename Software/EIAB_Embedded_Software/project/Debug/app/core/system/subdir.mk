################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system/gpio.c \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system/stm32g4xx_it.c \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system/system_stm32g4xx.c 

OBJS += \
./app/core/system/gpio.o \
./app/core/system/stm32g4xx_it.o \
./app/core/system/system_stm32g4xx.o 

C_DEPS += \
./app/core/system/gpio.d \
./app/core/system/stm32g4xx_it.d \
./app/core/system/system_stm32g4xx.d 


# Each subdirectory must supply rules for building sources it contributes
app/core/system/gpio.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system/gpio.c app/core/system/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
app/core/system/stm32g4xx_it.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system/stm32g4xx_it.c app/core/system/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
app/core/system/system_stm32g4xx.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system/system_stm32g4xx.c app/core/system/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app-2f-core-2f-system

clean-app-2f-core-2f-system:
	-$(RM) ./app/core/system/gpio.d ./app/core/system/gpio.o ./app/core/system/gpio.su ./app/core/system/stm32g4xx_it.d ./app/core/system/stm32g4xx_it.o ./app/core/system/stm32g4xx_it.su ./app/core/system/system_stm32g4xx.d ./app/core/system/system_stm32g4xx.o ./app/core/system/system_stm32g4xx.su

.PHONY: clean-app-2f-core-2f-system

