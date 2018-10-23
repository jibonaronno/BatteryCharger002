/*
 * BatteryCharger.h
 *
 * Created: 8/3/2018 8:03:26 PM
 *  Author: aronno
 */ 


#ifndef BATTERYCHARGER_H_
#define BATTERYCHARGER_H_

#define DEB_OK      55
#define DEB_FAILED  46

#define		SW_MENU			14
#define		SW_DOWN			15
#define		SW_UP			16

typedef struct __SETTINGS
{	
	uint16_t avrVoltHi;
	uint16_t avrVoltLo;
	uint16_t rectVoltCalib;
	uint16_t battVoltCalib;
}SETTINGS;





#endif /* BATTERYCHARGER_H_ */