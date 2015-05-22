################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gpiolib/TestProgram.c \
../gpiolib/gpioDirection.c \
../gpiolib/gpioRead.c \
../gpiolib/gpioWrite.c \
../gpiolib/gpiodone.c \
../gpiolib/gpioinit.c 

OBJS += \
./gpiolib/TestProgram.o \
./gpiolib/gpioDirection.o \
./gpiolib/gpioRead.o \
./gpiolib/gpioWrite.o \
./gpiolib/gpiodone.o \
./gpiolib/gpioinit.o 

C_DEPS += \
./gpiolib/TestProgram.d \
./gpiolib/gpioDirection.d \
./gpiolib/gpioRead.d \
./gpiolib/gpioWrite.d \
./gpiolib/gpiodone.d \
./gpiolib/gpioinit.d 


# Each subdirectory must supply rules for building sources it contributes
gpiolib/%.o: ../gpiolib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


