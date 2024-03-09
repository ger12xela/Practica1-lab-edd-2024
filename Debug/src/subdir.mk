################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Carta.cpp \
../src/Menu.cpp \
../src/NodoCarta.cpp \
../src/Solitarie--201831010.cpp 

CPP_DEPS += \
./src/Carta.d \
./src/Menu.d \
./src/NodoCarta.d \
./src/Solitarie--201831010.d 

OBJS += \
./src/Carta.o \
./src/Menu.o \
./src/NodoCarta.o \
./src/Solitarie--201831010.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Carta.d ./src/Carta.o ./src/Menu.d ./src/Menu.o ./src/NodoCarta.d ./src/NodoCarta.o ./src/Solitarie--201831010.d ./src/Solitarie--201831010.o

.PHONY: clean-src

