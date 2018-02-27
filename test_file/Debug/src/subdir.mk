################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test\ file.cpp 

OBJS += \
./src/test\ file.o 

CPP_DEPS += \
./src/test\ file.d 


# Each subdirectory must supply rules for building sources it contributes
src/test\ file.o: ../src/test\ file.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/test file.d" -MT"src/test\ file.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


