################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../hilfsklassen/Aktualitaet.cpp 

OBJS += \
./hilfsklassen/Aktualitaet.o 

CPP_DEPS += \
./hilfsklassen/Aktualitaet.d 


# Each subdirectory must supply rules for building sources it contributes
hilfsklassen/%.o: ../hilfsklassen/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


