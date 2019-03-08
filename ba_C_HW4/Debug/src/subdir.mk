################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/City.c \
../src/General.c \
../src/Kindergarten.c \
../src/ba_C_HW4.c \
../src/child.c \
../src/list.c 

OBJS += \
./src/City.o \
./src/General.o \
./src/Kindergarten.o \
./src/ba_C_HW4.o \
./src/child.o \
./src/list.o 

C_DEPS += \
./src/City.d \
./src/General.d \
./src/Kindergarten.d \
./src/ba_C_HW4.d \
./src/child.d \
./src/list.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


