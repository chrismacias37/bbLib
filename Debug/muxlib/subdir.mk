################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../muxlib/chkpinmode.c \
../muxlib/initmux.c \
../muxlib/muxDone.c \
../muxlib/setpinmode.c \
../muxlib/testProgram.c 

OBJS += \
./muxlib/chkpinmode.o \
./muxlib/initmux.o \
./muxlib/muxDone.o \
./muxlib/setpinmode.o \
./muxlib/testProgram.o 

C_DEPS += \
./muxlib/chkpinmode.d \
./muxlib/initmux.d \
./muxlib/muxDone.d \
./muxlib/setpinmode.d \
./muxlib/testProgram.d 


# Each subdirectory must supply rules for building sources it contributes
muxlib/%.o: ../muxlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


