################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_assert.c \
../utilities/fsl_debug_console.c 

C_DEPS += \
./utilities/fsl_assert.d \
./utilities/fsl_debug_console.d 

OBJS += \
./utilities/fsl_assert.o \
./utilities/fsl_debug_console.o 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c utilities/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_K32L2B31VLH0A -DCPU_K32L2B31VLH0A_cm0plus -DFRDM_K32L2B -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\source" -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\utilities" -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\drivers" -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\device" -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\component\uart" -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\component\lists" -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\CMSIS" -I"C:\Users\gnagu\Documents\MCUXpressoIDE_11.6.1_8255\workspace\frdmk32l2b_led_blinky\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-utilities

clean-utilities:
	-$(RM) ./utilities/fsl_assert.d ./utilities/fsl_assert.o ./utilities/fsl_debug_console.d ./utilities/fsl_debug_console.o

.PHONY: clean-utilities

