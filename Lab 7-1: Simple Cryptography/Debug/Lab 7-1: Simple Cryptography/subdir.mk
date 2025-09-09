################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Lab\ 7-1:\ Simple\ Cryptography/main.cpp 

OBJS += \
./Lab\ 7-1:\ Simple\ Cryptography/main.o 

CPP_DEPS += \
./Lab\ 7-1:\ Simple\ Cryptography/main.d 


# Each subdirectory must supply rules for building sources it contributes
Lab\ 7-1:\ Simple\ Cryptography/main.o: ../Lab\ 7-1:\ Simple\ Cryptography/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	Lab 7-1: Simple Cryptographyg++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Lab 7-1: Simple Cryptography/main.d" -MT"Lab\ 7-1:\ Simple\ Cryptography/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


