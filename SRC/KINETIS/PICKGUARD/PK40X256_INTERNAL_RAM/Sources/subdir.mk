################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/AudioProcess.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/AudioProcess.c \
../Sources/main.c \

OBJS += \
./Sources/AudioProcess.obj \
./Sources/main.obj \

OBJS_QUOTED += \
"./Sources/AudioProcess.obj" \
"./Sources/main.obj" \

C_DEPS += \
./Sources/AudioProcess.d \
./Sources/main.d \

C_DEPS_QUOTED += \
"./Sources/AudioProcess.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/AudioProcess.obj \
./Sources/main.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/AudioProcess.obj: ../Sources/AudioProcess.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/AudioProcess.args" -o "Sources/AudioProcess.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/main.args" -o "Sources/main.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


