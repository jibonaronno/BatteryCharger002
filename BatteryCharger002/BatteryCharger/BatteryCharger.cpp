/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
#include <string.h>

/*End of auto generated code by Atmel studio */

// include the library code:
#include <LiquidCrystal.h>
#include "TimerOne.h"
#include "BatteryCharger.h"
#include "ButtonMatrix.h"
//Beginning of Auto generated function prototypes by Atmel Studio
void t1callback();

void setup();
void loop();
//End of Auto generated function prototypes by Atmel Studio

uint16_t SetAndShowU16(uint16_t *iVal, char *chStr);
int readDebounce(int pin_no, int deb_low_count);


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 35, en = 34, d4 = 33, d5 = 32, d6 = 31, d7 = 30;

int vbatt_pin = A0;
int vrect_pin = A1;
int vearth_pin = A2;
uint32_t vBatt_adc = 0;
uint32_t vRect_adc = 0;
uint32_t vEarth_adc = 0;
uint32_t Batt_adc = 0;
uint32_t Rect_adc = 0;
uint32_t Earth_adc = 0;
uint32_t vBattDisplay = 0;
uint32_t vRectDisplay = 0;
uint32_t vEarthDisplay = 0;

uint32_t adc_collection_counter = 0;
uint32_t vbat_adc_accumulator = 0;
uint32_t vrect_adc_accumulator = 0;
uint32_t vearth_adc_accumulator = 0;

bool boost_on_flag = 0;
uint32_t boost_on_counter = 0;

bool mains_fail_status = false;
uint32_t mains_fail_count = 0;

#define RECT_LOW_VOLTAGE	21
#define RECT_UNDER_V1		22
#define RECT_OVER_V1		23
#define RECT_OVER_V2		24
int rect_voltage_state = RECT_OVER_V2;
uint16_t rect_low_voltage_count = 0;
uint16_t rect_under_v1_count = 0;
uint16_t rect_over_v1_count = 0;
uint16_t rect_over_v2_count = 0;

bool t1tick001 = false;
int t1tickCount002 = 0;
bool t1tick002 = false;
int t1tickCount003 = 0;
bool t1tick003 = false;

char strText01[20];
char strText02[20];

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

uint16_t data001 = 150;

SETTINGS settings;

void StoreBuffer(unsigned char *buffer, uint8_t _size)
{
	eeprom_write_block ((void *)buffer, (void *)10, _size);
}

void RestoreBuffer(unsigned char *buffer, uint8_t _size)
{
	eeprom_read_block ((void *)buffer, (void *)10, _size);
}

void StoreEnergyReading(char *buffer, uint8_t _size)
{
	eeprom_write_block ((void *)buffer, (void *)30, _size);
}

void ReStoreEnergyReading(char *buffer, uint8_t _size)
{
	eeprom_read_block ((void *)buffer, (void *)30, _size);
}

void setup() 
{
  Timer1.initialize(5000); //5000 Microseconds = 5 miliseconds
  Timer1.attachInterrupt(t1callback);
  
  pinMode(14, INPUT); //Button Up
  pinMode(15, INPUT); //Button Down
  pinMode(16, INPUT); //Button Menu
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  
  // LED PINS
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  //MAINS FAIL PIN
  pinMode(A3, INPUT);
  digitalWrite(A3, HIGH);
  
  //BOOST ON PIN INPUT
  pinMode(45, INPUT);
  digitalWrite(45, HIGH);
  
  //BOOST ON RELAY
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  
  //BOOST ON LED
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  
  //Relay PINS
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  analogReference(INTERNAL2V56);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Calibrating");
  
  RestoreBuffer((unsigned char*)&settings, sizeof(SETTINGS));
  
  if (settings.avrVoltHi >= 0XAAAA)
  {
	  settings.avrVoltHi = 128;
	  settings.avrVoltLo = 121;
	  settings.rectVoltCalib = 682; // Multiply ADC Value with 100 and divide by this value
	  settings.battVoltCalib = 682; // Multiply ADC Value with 100 and divide by this 
	  StoreBuffer((unsigned char*)&settings, sizeof(SETTINGS));
  }
}

void loop() 
{
	
	if(t1tick001 == true)
	{
		vBatt_adc = analogRead(vbatt_pin);
		vRect_adc = analogRead(vrect_pin);
		vEarth_adc = analogRead(vearth_pin);
		
		if (adc_collection_counter < 10)
		{
			vbat_adc_accumulator += vBatt_adc;
			vrect_adc_accumulator += vRect_adc;
			vearth_adc_accumulator += vEarth_adc;
			adc_collection_counter++;
		}
		else
		{
			Batt_adc = vbat_adc_accumulator / 10;
			Rect_adc = vrect_adc_accumulator / 10;
			Earth_adc = vearth_adc_accumulator / 10;
			
			vbat_adc_accumulator = 0;
			vrect_adc_accumulator = 0;
			vearth_adc_accumulator = 0;
			adc_collection_counter = 0;
		}
		
		
		t1tick001 = false;
	}
	  
  if (t1tick002)
  {  
	  vBattDisplay = ((Batt_adc * 100) / (uint32_t)(settings.battVoltCalib));
	  vRectDisplay = ((Rect_adc * 100) / (uint32_t)(settings.rectVoltCalib));
	  vEarthDisplay = ((Earth_adc * 100) / (uint32_t)100);
	  //lcd.setCursor(0, 1);
	  // print the number of seconds since reset:
	  //lcd.print(millis() / 1000);
	  
	  
	  lcd.setCursor(0, 0);
	  lcd.print("B:");
	  sprintf(strText01, "%03d", vBattDisplay);
	  lcd.print(strText01);
	  //lcd.print(" ");
	  lcd.print("R:");
	  sprintf(strText01, "%03d", vRectDisplay);
	  lcd.print(strText01);
	  
	  if (boost_on_flag)
	  {
		  lcd.print(" BST");
	  }
	  else
	  {
		  lcd.print(" FLT");
	  }
	  
	  lcd.setCursor(0, 1);
	  lcd.print("E:");
	  sprintf(strText01, "%03d", vEarthDisplay);
	  lcd.print(strText01);
	  
	  if (mains_fail_status)
	  {
		  lcd.print("MAINS FAIL");
	  }
	  else
	  {
		  switch (rect_voltage_state)
		  {
			  case RECT_LOW_VOLTAGE:
			  lcd.print(" R1R2  LV");
			  break;
			  case RECT_UNDER_V1:
			  lcd.print(" R1R2 UV1");
			  break;
			  case RECT_OVER_V1:
			  lcd.print(" R1   UV2");
			  break;
			  case RECT_OVER_V2:
			  lcd.print("       OV");
			  break;
		  }
	  }
	  
	  t1tick002 = false;
  }
  
  if (t1tick003)
  {
	  
	  if (vRectDisplay <= 100)
	  {
		   //rect_low_voltage_count = 0;
		   rect_under_v1_count = 0;
		   rect_over_v1_count = 0;
		   rect_over_v2_count = 0;
		  
		  if (rect_low_voltage_count < 5)
		  {
			  rect_low_voltage_count++;
		  }
		  else
		  {
			  rect_voltage_state = RECT_LOW_VOLTAGE;
		  }
	  }
	  else if (vRectDisplay < settings.avrVoltLo)
	  {
		  rect_low_voltage_count = 0;
		  //rect_under_v1_count = 0;
		  rect_over_v1_count = 0;
		  rect_over_v2_count = 0;
		  
		  if (rect_under_v1_count < 4)
		  {
			  rect_under_v1_count++;
		  }
		  else
		  {
			  rect_voltage_state = RECT_UNDER_V1;
		  }
	  }
	  else if (vRectDisplay < settings.avrVoltHi)
	  {
		  rect_low_voltage_count = 0;
		  rect_under_v1_count = 0;
		  //rect_over_v1_count = 0;
		  rect_over_v2_count = 0;
		  
		  if (rect_over_v1_count < 4)
		  {
			  rect_over_v1_count++;
		  } 
		  else
		  {
			  rect_voltage_state = RECT_OVER_V1;
		  }
	  }
	  else if (vRectDisplay >= settings.avrVoltHi)
	  {
		  rect_low_voltage_count = 0;
		  rect_under_v1_count = 0;
		  rect_over_v1_count = 0;
		  //rect_over_v2_count = 0;
		  if (rect_over_v2_count < 4)
		  {
			  rect_over_v2_count++;
		  }
		  else
		  {
			  rect_voltage_state = RECT_OVER_V2;
		  }
	  }
	  
	  if(mains_fail_status == false)
	  {
		  switch (rect_voltage_state)
		  {
			  case RECT_LOW_VOLTAGE:
			  digitalWrite(2, HIGH); //Relay 1
			  digitalWrite(3, HIGH); //Relay 2
		  
			  digitalWrite(13, HIGH); //LED1
			  digitalWrite(12, HIGH); //LED2
			  break;
			  case RECT_UNDER_V1:
			  digitalWrite(2, HIGH);
			  digitalWrite(3, HIGH);
		  
				digitalWrite(13, HIGH); //LED1
				digitalWrite(12, HIGH); //LED2
			  break;
			  case RECT_OVER_V1:
			  digitalWrite(2, HIGH);
			  digitalWrite(3, LOW);
		   
			   digitalWrite(13, HIGH); //LED1
			   digitalWrite(12, LOW); //LED2
		   
			  break;
			  case RECT_OVER_V2:
			  digitalWrite(2, LOW);
			  digitalWrite(3, LOW);
		  
			   digitalWrite(13, LOW); //LED1
			   digitalWrite(12, LOW); //LED2
			  break;
		  }
		  
		  if (boost_on_flag)
		  {
			  digitalWrite(4, HIGH);
			  digitalWrite(11, HIGH);
		  }
		  else
		  {
			  digitalWrite(4, LOW);
			  digitalWrite(11, LOW);
		  }
	  }
	  else
	  {
		  digitalWrite(2, LOW);
		  digitalWrite(3, LOW);
		  
		  digitalWrite(13, LOW); //LED1
		  digitalWrite(12, LOW); //LED2
	  }
	  
	  if (digitalRead(A3) == HIGH)
	  {
		  if (mains_fail_count < 5)
		  {
			  mains_fail_count++;
		  }
		  else
		  {
			  mains_fail_status = true;
		  }
	  }
	  else
	  {
		  if (mains_fail_count > 0)
		  {
			  mains_fail_count--;
		  }
		  else
		  {
			  mains_fail_status = false;
		  }
	  }
	  
	  if (digitalRead(45) == LOW)
	  {
		  if (boost_on_counter < 5)
		  {
			  boost_on_counter++;
		  }
		  else
		  {
			  boost_on_flag = true;
		  }
	  }
	  else
	  {
		  if (boost_on_counter > 0)
		  {
			  boost_on_counter--;
		  }
		  else
		  {
			  boost_on_flag = false;
		  }
	  }
	  
	  t1tick003 = false;
  }
  
  if (readDebounce(SW_MENU, 40) == DEB_OK)
  {
	  lcd.clear();
	  _delay_ms(800);
	  SetAndShowU16(&settings.avrVoltHi, "AVR HIGH:");
	  lcd.clear();
	  _delay_ms(800);
	  SetAndShowU16(&settings.avrVoltLo, "AVR LOW:");
	  lcd.clear();
	  _delay_ms(800);
	  SetAndShowU16(&settings.battVoltCalib, "BAT CALIB:");
	  lcd.clear();
	  _delay_ms(800);
	  StoreBuffer((unsigned char*)&settings, sizeof(SETTINGS));
  }
  
}

void t1callback()
{
  t1tick001 = true;
  
  if (t1tickCount002 < 100)
  {
	  t1tickCount002++;
  }
  else
  {
	  t1tickCount002 = 0;
	  t1tick002 = true;
  }
  
  if (t1tickCount003 < 200)
  {
	  t1tickCount003++;
  }
  else
  {
	  t1tickCount003 = 0;
	  t1tick003 = true;
  }
  
  ButtonMatrixPrimaryCycle();
}


int debounce_hi_count = 0;
int debounce_low_count = 0;
int debounce_pin_no = 0;

int readDebounce(int pin_no, int deb_low_count)
{
	int pinstate = HIGH;
	
	pinstate = digitalRead(pin_no);
	
	while(pinstate == LOW)
	{
		delayMicroseconds(2);
		debounce_low_count++;
		pinstate = digitalRead(pin_no);
		if(debounce_low_count >= deb_low_count)
		{
			debounce_low_count = deb_low_count;
			//break;
		}
	}
	if(debounce_low_count >= deb_low_count)
	{
		debounce_low_count = 0;
		return DEB_OK;
	}
	else
	{
		debounce_low_count = 0;
		return DEB_FAILED;
	}
}

uint8_t StrLen = 0;
char	chUival[8];
static uint8_t btnid=0;
static uint16_t PreValueU16 = 0;

uint16_t SetAndShowU16(uint16_t *iVal, char *chStr)
{
	StrLen = strlen(chStr);
	
	lcd.clear();
	
	PreValueU16 = (*iVal);
	
	while (1)
	{
		lcd.setCursor(0, 1);
		//GetNDigitFromShort(*iVal, chUival, 4);
		sprintf(chUival, "%04d", *iVal);
		//lcdPrintData(chStr, StrLen);
		lcd.print(chStr);
		lcd.print(chUival);
		//lcdPrintData(chUival, 4);
		
		btnid = GetPressedButtonId();
		if (btnid > 0)
		{
			if (btnid == 2)
			{
				if ((*iVal) < 32768)
				{
					(*iVal)++;
				}
			}
			else if (btnid == 3)
			{
				if (*iVal > 1)
				{
					(*iVal)--;
				}
			}
			else if (btnid == 1)
			{
				//(*iVal) = PreValueU16;
				lcd.clear();
				_delay_ms(1000);
				return 0;
			}
			else if (btnid == 2) //not effective
			{
				return 0;
			}
			_delay_ms(200);
		}
		//wdt_reset();
		
	}
	
	return 0;
	
}

