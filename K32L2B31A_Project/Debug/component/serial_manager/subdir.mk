################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/fsl_component_serial_manager.c \
../component/serial_manager/fsl_component_serial_port_uart.c 

C_DEPS += \
./component/serial_manager/fsl_component_serial_manager.d \
./component/serial_manager/fsl_component_serial_port_uart.d 

OBJS += \
./component/serial_manager/fsl_component_serial_manager.o \
./component/serial_manager/fsl_component_serial_port_uart.o 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c component/serial_manager/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_K32L2B31VLH0A -DCPU_K32L2B31VLH0A_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -DCR_PRINTF_CHAR -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\board" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\source" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\drivers" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\CMSIS" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\device" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\component\serial_manager" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\component\uart" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\utilities" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\component\lists" -I"C:\Users\gnagu\Documents\Unimag\IoT\labs_module_2\K32L2B31A_Project\source\libraries" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-serial_manager

clean-component-2f-serial_manager:
	-$(RM) ./component/serial_manager/fsl_component_serial_manager.d ./component/serial_manager/fsl_component_serial_manager.o ./component/serial_manager/fsl_component_serial_port_uart.d ./component/serial_manager/fsl_component_serial_port_uart.o

.PHONY: clean-component-2f-serial_manager
