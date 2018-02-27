################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/a1.cpp \
../src/crop.cpp \
../src/plant.cpp \
../src/test.cpp 

OBJS += \
./src/a1.o \
./src/crop.o \
./src/plant.o \
./src/test.o 

CPP_DEPS += \
./src/a1.d \
./src/crop.d \
./src/plant.d \
./src/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


