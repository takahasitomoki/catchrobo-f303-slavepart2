################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/encoder.c \
../Src/main.c \
../Src/motor.c \
../Src/robotstate.c \
../Src/stm32f3xx_hal_msp.c \
../Src/stm32f3xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f3xx.c 

OBJS += \
./Src/encoder.o \
./Src/main.o \
./Src/motor.o \
./Src/robotstate.o \
./Src/stm32f3xx_hal_msp.o \
./Src/stm32f3xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f3xx.o 

C_DEPS += \
./Src/encoder.d \
./Src/main.d \
./Src/motor.d \
./Src/robotstate.d \
./Src/stm32f3xx_hal_msp.d \
./Src/stm32f3xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f3xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"C:/Users/tomok/Documents/catch_robo/0823catch-slavef303/Inc" -I"C:/Users/tomok/Documents/catch_robo/0823catch-slavef303/Drivers/STM32F3xx_HAL_Driver/Inc" -I"C:/Users/tomok/Documents/catch_robo/0823catch-slavef303/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"C:/Users/tomok/Documents/catch_robo/0823catch-slavef303/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"C:/Users/tomok/Documents/catch_robo/0823catch-slavef303/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


