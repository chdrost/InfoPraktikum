################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../geopunkte/Gebietslokation.cpp \
../geopunkte/Linearlokation.cpp \
../geopunkte/Punktlokation.cpp 

OBJS += \
./geopunkte/Gebietslokation.o \
./geopunkte/Linearlokation.o \
./geopunkte/Punktlokation.o 

CPP_DEPS += \
./geopunkte/Gebietslokation.d \
./geopunkte/Linearlokation.d \
./geopunkte/Punktlokation.d 


# Each subdirectory must supply rules for building sources it contributes
geopunkte/%.o: ../geopunkte/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


