################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dfa.cpp \
../src/DfaInterface.cpp \
../src/Node.cpp \
../src/Transitions.cpp \
../src/main.cpp 

OBJS += \
./src/Dfa.o \
./src/DfaInterface.o \
./src/Node.o \
./src/Transitions.o \
./src/main.o 

CPP_DEPS += \
./src/Dfa.d \
./src/DfaInterface.d \
./src/Node.d \
./src/Transitions.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


