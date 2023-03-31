################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/bsp_stm32g431cb.c \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/main.c \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/syscalls.c \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/sysmem.c 

OBJS += \
./app/core/bsp_stm32g431cb.o \
./app/core/main.o \
./app/core/syscalls.o \
./app/core/sysmem.o 

C_DEPS += \
./app/core/bsp_stm32g431cb.d \
./app/core/main.d \
./app/core/syscalls.d \
./app/core/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
app/core/bsp_stm32g431cb.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/bsp_stm32g431cb.c app/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
app/core/main.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/main.c app/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
app/core/syscalls.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/syscalls.c app/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
app/core/sysmem.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/sysmem.c app/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app-2f-core

clean-app-2f-core:
	-$(RM) ./app/core/bsp_stm32g431cb.d ./app/core/bsp_stm32g431cb.o ./app/core/bsp_stm32g431cb.su ./app/core/main.d ./app/core/main.o ./app/core/main.su ./app/core/syscalls.d ./app/core/syscalls.o ./app/core/syscalls.su ./app/core/sysmem.d ./app/core/sysmem.o ./app/core/sysmem.su

.PHONY: clean-app-2f-core

