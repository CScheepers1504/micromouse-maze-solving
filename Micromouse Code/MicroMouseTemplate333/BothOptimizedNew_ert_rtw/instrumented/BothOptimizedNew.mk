###########################################################################
## Makefile generated for component 'BothOptimizedNew'. 
## 
## Makefile     : BothOptimizedNew.mk
## Generated on : Fri Oct 18 13:50:21 2024
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/BothOptimizedNew.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = BothOptimizedNew
MAKEFILE                  = BothOptimizedNew.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2024b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ARM Cortex-M
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ../..
COMPILER_COMMAND_FILE     = BothOptimizedNew_comp.rsp
CMD_FILE                  = BothOptimizedNew.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2024b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                    = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_NAME_WITHOUT_EXTN = $(basename $(PRODUCT))
PRODUCT_BIN               = $(PRODUCT_NAME_WITHOUT_EXTN).bin
PRODUCT_HEX               = $(PRODUCT_NAME_WITHOUT_EXTN).hex
CPFLAGS                   = -O binary
SHELL                     = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = "$(EXESIZEPATH)/arm-none-eabi-size"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPPFLAGS             = -std=gnu++14 \
                       -fno-rtti \
                       -fno-exceptions \
                       $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPP_LDFLAGS          = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXESIZE_FLAGS        = $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/BothOptimizedNew.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMW_TIM3_ENABLED=1 -DMW_ADC2_ENABLED=1 -DMW_ADC2_VAR=mw_adc2 -DMW_ADC2_DMA_ENABLED=DMA1_Channel2_IRQHandler -DMW_ADC2_DMA1_Channel2_TC_ENABLED=1 -DMW_ADC2_DMA_STREAM=2 -DMW_ADC2_DMA_BUFFER_SIZE=18 -DMW_STANDALONE_EXECUTION_PROFILER_ON -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L476xx -DMW_TIMEBASESOURCE=TIM1
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -D__FPU_PRESENT=1U -D__FPU_USED=1U -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=BothOptimizedNew -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/stm_timer_ll.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/stm_adc_ll.c $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/BothOptimizedNew.c $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/BothOptimizedNew_data.c $(START_DIR)/MicroMouseProgramming/Core/Src/instrumented/IMU.c $(START_DIR)/MicroMouseProgramming/Core/Src/instrumented/CustomWhile.c $(START_DIR)/MicroMouseProgramming/Core/Src/instrumented/Motors.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/platform_timer.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/main.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/gpio.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/adc.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/dma.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/i2c.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/tim.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/usart.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/App/USB_DE~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/Target/USBD_C~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/App/USBD_D~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/App/USBD_C~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/STM32L~3.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/STM32L~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/STM32L~2.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STM32L~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STM32L~2.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STM32L~3.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STM32L~4.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STCC21~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STBDD7~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STB373~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STD8DD~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST54A6~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STC5F4~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STDFF3~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST2C6F~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STDA0D~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST11D5~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST126C~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST7949~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST2161~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STA2F2~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STB268~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STB65E~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST078C~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STDFD8~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST3369~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST87EB~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STF273~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STEDBA~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/STEB6D~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/ST9CC8~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Core/Src/USBD_C~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Core/Src/USBD_C~2.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Core/Src/USBD_I~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Class/CDC/Src/usbd_cdc.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/SYSTEM~1.C C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/STM32C~1/APPLIC~1/User/Core/syscalls.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/STM32C~1/APPLIC~1/User/Core/sysmem.c C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/STM32C~1/APPLIC~1/User/Startup/STARTU~1.S code_profiling_utility_functions.c

MAIN_SRC = $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = stm_timer_ll.o stm_adc_ll.o BothOptimizedNew.o BothOptimizedNew_data.o IMU.o CustomWhile.o Motors.o overrideHALDelay.o platform_timer.o SysTickScheduler.o m3m4m4f_multitasking.o main.o gpio.o adc.o dma.o i2c.o tim.o usart.o usb_device.o usbd_conf.o usbd_desc.o usbd_cdc_if.o stm32l4xx_it.o stm32l4xx_hal_msp.o stm32l4xx_hal_timebase_tim.o stm32l4xx_ll_utils.o stm32l4xx_ll_exti.o stm32l4xx_ll_gpio.o stm32l4xx_hal_pcd.o stm32l4xx_hal_pcd_ex.o stm32l4xx_ll_usb.o stm32l4xx_hal.o stm32l4xx_hal_rcc.o stm32l4xx_hal_rcc_ex.o stm32l4xx_hal_flash.o stm32l4xx_hal_flash_ex.o stm32l4xx_hal_flash_ramfunc.o stm32l4xx_hal_gpio.o stm32l4xx_hal_i2c.o stm32l4xx_hal_i2c_ex.o stm32l4xx_hal_dma.o stm32l4xx_hal_dma_ex.o stm32l4xx_hal_pwr.o stm32l4xx_hal_pwr_ex.o stm32l4xx_hal_cortex.o stm32l4xx_hal_exti.o stm32l4xx_ll_adc.o stm32l4xx_ll_dma.o stm32l4xx_hal_tim.o stm32l4xx_hal_tim_ex.o stm32l4xx_ll_tim.o stm32l4xx_ll_usart.o stm32l4xx_ll_rcc.o usbd_core.o usbd_ctlreq.o usbd_ioreq.o usbd_cdc.o system_stm32l4xx.o syscalls.o sysmem.o startup_stm32l476vetx.o code_profiling_utility_functions.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/ProgramData/MATLAB/SupportPackages/R2024b/3P.instrset/cmsis_dsp.instrset/Lib/GCC/arm_cortexm4ldfsp_math/libCMSISDSP.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = --specs=nano.specs
CPP_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\Nang'alelwa\OneDrive - University of Cape Town\UCT 4th Year Courses\2nd Semester\EEE3098S\MicroMouseTemplate_v2\MicroMouseProgramming\STM32CubeIDE\STM32L476VETX_FLASH.ld"

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = --specs=nano.specs
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\Nang'alelwa\OneDrive - University of Cape Town\UCT 4th Year Courses\2nd Semester\EEE3098S\MicroMouseTemplate_v2\MicroMouseProgramming\STM32CubeIDE\STM32L476VETX_FLASH.ld"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_ = --specs=nano.specs
LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\Nang'alelwa\OneDrive - University of Cape Town\UCT 4th Year Courses\2nd Semester\EEE3098S\MicroMouseTemplate_v2\MicroMouseProgramming\STM32CubeIDE\STM32L476VETX_FLASH.ld"

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = --specs=nano.specs
SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T"C:\Users\Nang'alelwa\OneDrive - University of Cape Town\UCT 4th Year Courses\2nd Semester\EEE3098S\MicroMouseTemplate_v2\MicroMouseProgramming\STM32CubeIDE\STM32L476VETX_FLASH.ld"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include mw_gnu_arm_tools_path.mk
-include ../mw_gnu_arm_tools_path.mk
-include ../../mw_gnu_arm_tools_path.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Executable Size" ..."
	$(EXESIZE) $(EXESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


stm_timer_ll.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/stm_timer_ll.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm_adc_ll.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/stm_adc_ll.c
	$(CC) $(CFLAGS) -o "$@" "$<"


BothOptimizedNew.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/BothOptimizedNew.c
	$(CC) $(CFLAGS) -o "$@" "$<"


BothOptimizedNew_data.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/BothOptimizedNew_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/BothOptimizedNew_ert_rtw/instrumented/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


IMU.o : $(START_DIR)/MicroMouseProgramming/Core/Src/instrumented/IMU.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CustomWhile.o : $(START_DIR)/MicroMouseProgramming/Core/Src/instrumented/CustomWhile.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Motors.o : $(START_DIR)/MicroMouseProgramming/Core/Src/instrumented/Motors.c
	$(CC) $(CFLAGS) -o "$@" "$<"


overrideHALDelay.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c
	$(CC) $(CFLAGS) -o "$@" "$<"


platform_timer.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/shared/supportpackages/stm32/src/platform_timer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


SysTickScheduler.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c
	$(CC) $(CFLAGS) -o "$@" "$<"


m3m4m4f_multitasking.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


main.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


gpio.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


adc.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/adc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


dma.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


i2c.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/i2c.c
	$(CC) $(CFLAGS) -o "$@" "$<"


tim.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usart.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/usart.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usb_device.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/App/usb_device.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usbd_conf.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/Target/usbd_conf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usbd_desc.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/App/usbd_desc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usbd_cdc_if.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/USB_DE~1/App/usbd_cdc_if.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_it.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/stm32l4xx_it.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_msp.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/stm32l4xx_hal_msp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_timebase_tim.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/stm32l4xx_hal_timebase_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_utils.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_exti.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_gpio.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_pcd.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_pcd.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_pcd_ex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_pcd_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_usb.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_usb.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_rcc.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_rcc_ex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_rcc_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_flash.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_flash.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_flash_ex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_flash_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_flash_ramfunc.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_flash_ramfunc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_gpio.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_i2c.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_i2c.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_i2c_ex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_i2c_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_dma.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_dma_ex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_dma_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_pwr.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_pwr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_pwr_ex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_pwr_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_cortex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_cortex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_exti.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_adc.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_adc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_dma.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_tim.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_hal_tim_ex.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_hal_tim_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_tim.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_usart.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_usart.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32l4xx_ll_rcc.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Drivers/STM32L~1/Src/stm32l4xx_ll_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usbd_core.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Core/Src/usbd_core.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usbd_ctlreq.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Core/Src/usbd_ctlreq.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usbd_ioreq.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Core/Src/usbd_ioreq.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usbd_cdc.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/MIDDLE~1/ST/STM32_~1/Class/CDC/Src/usbd_cdc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


system_stm32l4xx.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/Core/Src/system_stm32l4xx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


syscalls.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/STM32C~1/APPLIC~1/User/Core/syscalls.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sysmem.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/STM32C~1/APPLIC~1/User/Core/sysmem.c
	$(CC) $(CFLAGS) -o "$@" "$<"


startup_stm32l476vetx.o : C:/Users/NANG'A~1/ONEDRI~1/UCT4TH~1/2NDSEM~1/EEE3098S/MICROM~2/MICROM~1/STM32C~1/APPLIC~1/User/Startup/startup_stm32l476vetx.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


