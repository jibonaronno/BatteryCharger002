################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../BatteryCharger.cpp \
../ButtonMatrix.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
BatteryCharger.o \
ButtonMatrix.o

OBJS_AS_ARGS +=  \
BatteryCharger.o \
ButtonMatrix.o

C_DEPS +=  \
BatteryCharger.d \
ButtonMatrix.d

C_DEPS_AS_ARGS +=  \
BatteryCharger.d \
ButtonMatrix.d

OUTPUT_FILE_PATH +=BatteryCharger.elf

OUTPUT_FILE_PATH_AS_ARGS +=BatteryCharger.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Users/aronno/Documents/Atmel\ Studio/7.0/Energypac\ Battery/BatteryCharger002/BatteryCharger002/ArduinoCore/Release/libArduinoCore.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./BatteryCharger.o: .././BatteryCharger.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x0010 -DUSB_MANUFACTURER="\"Arduino LLC\"" -DNDEBUG  -I"C:\Program Files (x86)\Atmel\Studio2\7.0\Packs\atmel\ATmega_DFP\1.2.209\include" -I"..\\..\ArduinoCore\include\core" -I"..\\..\ArduinoCore\include\libraries\LiquidCrystal" -I"..\\..\ArduinoCore\include\libraries\timerone" -I"..\\..\ArduinoCore\include\libraries\timerone\config" -I"..\\..\ArduinoCore\include\variants\mega"  -Os -fno-threadsafe-statics -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -w -mmcu=atmega2560 -B "C:\Program Files (x86)\Atmel\Studio2\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega2560" -c -std=gnu++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./ButtonMatrix.o: .././ButtonMatrix.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x0010 -DUSB_MANUFACTURER="\"Arduino LLC\"" -DNDEBUG  -I"C:\Program Files (x86)\Atmel\Studio2\7.0\Packs\atmel\ATmega_DFP\1.2.209\include" -I"..\\..\ArduinoCore\include\core" -I"..\\..\ArduinoCore\include\libraries\LiquidCrystal" -I"..\\..\ArduinoCore\include\libraries\timerone" -I"..\\..\ArduinoCore\include\libraries\timerone\config" -I"..\\..\ArduinoCore\include\variants\mega"  -Os -fno-threadsafe-statics -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -w -mmcu=atmega2560 -B "C:\Program Files (x86)\Atmel\Studio2\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega2560" -c -std=gnu++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="BatteryCharger.map" -Wl,--start-group -Wl,-lm -Wl,-lArduinoCore  -Wl,--end-group -Wl,-L"../../../../../../../Arduino/ArduinoCoreMega2560" -Wl,-L"C:\Users\aronno\DOCUME~1\ATMELS~1\7.0\ENERGY~1\BATTER~2\BATTER~1\ARDUIN~1\Release"  -Wl,--gc-sections -mrelax -mmcu=atmega2560 -B "C:\Program Files (x86)\Atmel\Studio2\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega2560" -Os  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "BatteryCharger.elf" "BatteryCharger.hex"
	"C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "BatteryCharger.elf" "BatteryCharger.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "BatteryCharger.elf" > "BatteryCharger.lss"
	"C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "BatteryCharger.elf" "BatteryCharger.srec"
	"C:\Program Files (x86)\Atmel\Studio2\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "BatteryCharger.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "BatteryCharger.elf" "BatteryCharger.a" "BatteryCharger.hex" "BatteryCharger.lss" "BatteryCharger.eep" "BatteryCharger.map" "BatteryCharger.srec" "BatteryCharger.usersignatures"
	