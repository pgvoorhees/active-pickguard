################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.c" \
"../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.c" \

C_SRCS += \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.c \
../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.c \

OBJS += \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.obj \

OBJS_QUOTED += \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.obj" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.obj" \

C_DEPS += \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.d \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.d \

C_DEPS_QUOTED += \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.d" \
"./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.d" \

OBJS_OS_FORMAT += \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.obj \
./Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.c
	@echo 'Building file: $<'
	@echo 'Executing target #64 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_f32.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/%.d: ../Sources/Cortex-M4-M3/MatrixFunctions/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.c
	@echo 'Building file: $<'
	@echo 'Executing target #65 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q15.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.c
	@echo 'Building file: $<'
	@echo 'Executing target #66 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_add_q31.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.c
	@echo 'Building file: $<'
	@echo 'Executing target #67 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_f32.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.c
	@echo 'Building file: $<'
	@echo 'Executing target #68 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q15.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.c
	@echo 'Building file: $<'
	@echo 'Executing target #69 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_init_q31.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.c
	@echo 'Building file: $<'
	@echo 'Executing target #70 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_inverse_f32.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.c
	@echo 'Building file: $<'
	@echo 'Executing target #71 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_f32.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.c
	@echo 'Building file: $<'
	@echo 'Executing target #72 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q15.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.c
	@echo 'Building file: $<'
	@echo 'Executing target #73 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_fast_q31.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.c
	@echo 'Building file: $<'
	@echo 'Executing target #74 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q15.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.c
	@echo 'Building file: $<'
	@echo 'Executing target #75 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_mult_q31.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.c
	@echo 'Building file: $<'
	@echo 'Executing target #76 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_f32.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.c
	@echo 'Building file: $<'
	@echo 'Executing target #77 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q15.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.c
	@echo 'Building file: $<'
	@echo 'Executing target #78 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_scale_q31.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.c
	@echo 'Building file: $<'
	@echo 'Executing target #79 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_f32.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.c
	@echo 'Building file: $<'
	@echo 'Executing target #80 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q15.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.c
	@echo 'Building file: $<'
	@echo 'Executing target #81 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_sub_q31.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.c
	@echo 'Building file: $<'
	@echo 'Executing target #82 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_f32.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.c
	@echo 'Building file: $<'
	@echo 'Executing target #83 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q15.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.obj: ../Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.c
	@echo 'Building file: $<'
	@echo 'Executing target #84 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.args" -o "Sources/Cortex-M4-M3/MatrixFunctions/arm_mat_trans_q31.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

