################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ba_C_HW3.c \
../src/child.c \
../src/city.c \
../src/kindergarten.c 

OBJS += \
./src/ba_C_HW3.o \
./src/child.o \
./src/city.o \
./src/kindergarten.o 

C_DEPS += \
./src/ba_C_HW3.d \
./src/child.d \
./src/city.d \
./src/kindergarten.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


