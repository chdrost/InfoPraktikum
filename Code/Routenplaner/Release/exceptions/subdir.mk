################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../exceptions/FileNotFoundException.cpp \
../exceptions/ZeitException.cpp 

OBJS += \
./exceptions/FileNotFoundException.o \
./exceptions/ZeitException.o 

CPP_DEPS += \
./exceptions/FileNotFoundException.d \
./exceptions/ZeitException.d 


# Each subdirectory must supply rules for building sources it contributes
exceptions/%.o: ../exceptions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


