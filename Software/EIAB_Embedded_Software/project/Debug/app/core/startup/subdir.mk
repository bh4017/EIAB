################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup/startup_stm32g431cbtx.s 

OBJS += \
./app/core/startup/startup_stm32g431cbtx.o 

S_DEPS += \
./app/core/startup/startup_stm32g431cbtx.d 


# Each subdirectory must supply rules for building sources it contributes
app/core/startup/startup_stm32g431cbtx.o: C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup/startup_stm32g431cbtx.s app/core/startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/inc" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/interfaces" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/startup" -I"C:/Users/brian/git/bh4017/EIAB/Software/EIAB_Embedded_Software/src/system" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-app-2f-core-2f-startup

clean-app-2f-core-2f-startup:
	-$(RM) ./app/core/startup/startup_stm32g431cbtx.d ./app/core/startup/startup_stm32g431cbtx.o

.PHONY: clean-app-2f-core-2f-startup

