################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bill.cpp \
../src/ws7-8\ _derivedclasses.cpp 

OBJS += \
./src/bill.o \
./src/ws7-8\ _derivedclasses.o 

CPP_DEPS += \
./src/bill.d \
./src/ws7-8\ _derivedclasses.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ws7-8\ _derivedclasses.o: ../src/ws7-8\ _derivedclasses.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/ws7-8 _derivedclasses.d" -MT"src/ws7-8\ _derivedclasses.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


