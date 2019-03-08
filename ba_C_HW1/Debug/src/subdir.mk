################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HW1.c \
../src/Q1.c \
../src/Q2.c \
../src/general_func.c 

OBJS += \
./src/HW1.o \
./src/Q1.o \
./src/Q2.o \
./src/general_func.o 

C_DEPS += \
./src/HW1.d \
./src/Q1.d \
./src/Q2.d \
./src/general_func.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


