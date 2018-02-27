################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/a3.cpp \
../src/crop.cpp \
../src/garden.cpp \
../src/plant.cpp \
../src/test.cpp 

OBJS += \
./src/a3.o \
./src/crop.o \
./src/garden.o \
./src/plant.o \
./src/test.o 

CPP_DEPS += \
./src/a3.d \
./src/crop.d \
./src/garden.d \
./src/plant.d \
./src/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


