################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_dma.c \
../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_exti.c \
../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_gpio.c \
../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_pwr.c \
../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_rcc.c \
../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_usart.c \
../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_utils.c 

OBJS += \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_dma.o \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_exti.o \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_gpio.o \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_pwr.o \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_rcc.o \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_usart.o \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_utils.o 

C_DEPS += \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_dma.d \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_exti.d \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_gpio.d \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_pwr.d \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_rcc.d \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_usart.d \
./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32G4xx_HAL_Driver/Src/%.o Drivers/STM32G4xx_HAL_Driver/Src/%.su: ../Drivers/STM32G4xx_HAL_Driver/Src/%.c Drivers/STM32G4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DUSE_FULL_LL_DRIVER -DDEBUG -DSTM32G431xx -c -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/.libs/QP/ports/arm-cm/qv/gnu" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/aos" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/.libs/QP/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32G4xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32G4xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_dma.d ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_dma.o ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_dma.su ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_exti.d ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_exti.o ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_exti.su ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_gpio.d ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_gpio.o ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_gpio.su ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_pwr.d ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_pwr.o ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_pwr.su ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_rcc.d ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_rcc.o ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_rcc.su ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_usart.d ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_usart.o ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_usart.su ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_utils.d ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_utils.o ./Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_utils.su

.PHONY: clean-Drivers-2f-STM32G4xx_HAL_Driver-2f-Src

