################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../hilfsklassen/Aktualitaet.cpp \
../hilfsklassen/BenutzerInterface.cpp \
../hilfsklassen/GeoKoordinate.cpp \
../hilfsklassen/SuchenKlasse.cpp 

OBJS += \
./hilfsklassen/Aktualitaet.o \
./hilfsklassen/BenutzerInterface.o \
./hilfsklassen/GeoKoordinate.o \
./hilfsklassen/SuchenKlasse.o 

CPP_DEPS += \
./hilfsklassen/Aktualitaet.d \
./hilfsklassen/BenutzerInterface.d \
./hilfsklassen/GeoKoordinate.d \
./hilfsklassen/SuchenKlasse.d 


# Each subdirectory must supply rules for building sources it contributes
hilfsklassen/%.o: ../hilfsklassen/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


