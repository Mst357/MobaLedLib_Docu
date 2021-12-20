// This file contains the DCC and LED definitions.
//
// It was automatically generated by the program Prog_Generator_MobaLedLib.xlsm Ver. 3.1.0A      by Hardi
// File creation: 20.12.2021 11:54:20
// (Attention: The display in the Arduino IDE is not updated if Options/External Editor is disabled)

#ifndef __LEDS_AUTOPROG_H__
#define __LEDS_AUTOPROG_H__

#ifndef ARDUINO_RASPBERRY_PI_PICO
#define FASTLED_INTERNAL       // Disable version number message in FastLED library (looks like an error)
#include <FastLED.h>           // The FastLED library must be installed in addition if you got the error message "..fatal error: FastLED.h: No such file or directory"
                               // Arduino IDE: Sketch / Include library / Manage libraries                    Deutsche IDE: Sketch / Bibliothek einbinden / Bibliothek verwalten
                               //              Type "FastLED" in the "Filter your search..." field                          "FastLED" in das "Grenzen Sie ihre Suche ein" Feld eingeben
                               //              Select the entry and click "Install"                                         Gefundenen Eintrag auswaehlen und "Install" anklicken
#else
#include <PicoFastLED.h>       // Juergens minimum version or FastLED for Raspberry Pico
#endif

#include <MobaLedLib.h>

#define START_MSG "LEDs_AutoProg Ver 1: Ver_3.1.0 20.12.21 11:54"

#define TWO_BUTTONS_PER_ADDRESS 1      // Two buttons (Red/Green) are used (DCC/CAN)
#ifdef NUM_LEDS
  #warning "'NUM_LEDS' definition in the main program is replaced by the included 'LEDs_AutoProg.h' with 28"
  #undef NUM_LEDS
#endif

#define NUM_LEDS 28                    // Number of LEDs (Maximal 256 RGB LEDs could be used)

#define LEDS_PER_CHANNEL ",28"

#define RECEIVE_LED_COLOR_PER_RS232
// Input channel defines for local inputs and expert users


//*** Analog switches ***

#include <AnalogScanner.h>   // Interrupt driven analog reading library. The library has to be installed manually from https://github.com/merose/AnalogScanner
AnalogScanner scanner;       // Creates an instance of the analog pin scanner.

#include <Analog_Buttons10.h>


#define SWITCH_DAMPING_FACT   1  // 1 = Slow, 100 Fast (Normal 1)

#include "Read_LDR.h"     // Darkness sensor


//*** Output Channels ***
#define INCH0                   0
#define INCH1                   1
#define INCH2                   2
#define INCH3                   3
#define INCH4                   4
#define INCH5                   5

/*********************/
#define SETUP_FASTLED()                                                      \
/*********************/                                                      \
  CLEDController& controller0 = FastLED.addLeds<NEOPIXEL,  6>(leds+  0, 28); \
                                                                             \
  controller0.clearLeds(256);                                                \
  FastLED.setDither(DISABLE_DITHER);       // avoid sending slightly modified brightness values
/*End*/

#define USE_ADDITIONAL_SETUP_PROC                                  // Activate the usage of the Additional_Setup_Proc()

//--------------------------
void Additional_Setup_Proc()
//--------------------------
{
  int scanOrder[] = {A7};
  const int SCAN_COUNT = sizeof(scanOrder) / sizeof(scanOrder[0]);

  Init_DarknessSensor(A7, 50, SCAN_COUNT); // Attention: The analogRead() function can't be used together with the darkness sensor !
  scanner.setCallback(A7, Darkness_Detection_Callback);
  scanner.setScanOrder(SCAN_COUNT, scanOrder);
  scanner.beginScanning();

}



//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
  RGB_Heartbeat(0)                                                                                            /* Zeigt an, dass die LEDs angesteuert werden                                                                                                                                                  */  #define READ_LDR                                                                                            /* Aktiviert das einlesen des Helligkeitssensors in der .ino Datei                                                                                                                             */  #define READ_LDR_DEBUG                                                                                      /* Aktiviert eine Debug Ausgabe mit der die gemessene und gefilterte "Dunkelheit" mit den seriellen Monitor angezeigt wird.                                                                    */  #define SWITCH_DAMPING_FACT   1  // 1 = Slow, 100 Fast (Normal 1)                                           /* Bestimmt wie lange der �bergang von Tag auf Nacht ist wenn ein Schalter anstelle eines LDRs verwendet wird.                                                                                 */  // Macro: Fading Traffic light for tests with RGB LEDs                                                      /* Definition einer Ampel welche per Eingang in den Nachtmodus (Gelb Blinken) versetzt werden kann.                                                                                            */  #define RGB_AmpelX_Fade_IO(LED, SI_1)                                                                       /*     "                                                                                                                                                                                       */ \             APatternT8(LED,0,SI_1,18,0,255,0,PF_NO_SWITCH_OFF|PF_INVERT_INP,200 ms,2 Sec,200 ms,1 Sec,200 ms,10 Sec,200 ms,3 Sec,1,2,4,8,144,33,64,134,0,128,2,0,10,128,33,0,134,0,1,2,4,8,16,32,67,128,12,1,0,5,0,20,0,67,0,12)  /*     "                                                                  */ \             APatternT4(LED,0,SI_1,18,0,255,0,PF_NO_SWITCH_OFF,              100 ms,300 ms,100 ms,500 ms,24,48,96,192,0,0,0,0,0) /*     "                                                                                                                                                                    */                                                                                                              /*     "                                                                                                                                                                                       */  Schedule(INCH0, INCH2, SI_1, 60, 110)                                                                       /* Mehrere Zeilen welche bestimmen ab welchen                                                                                                                                                  */  Schedule(INCH3, INCH3, SI_1, 150, 150)                                                                      /* "Dunkelheitswerten" die Eing�nge der folgenden                                                                                                                                              */  Schedule(INCH4, INCH4, SI_1, 50, 50)                                                                        /* Zeilen aktiviert werden. Die letzten beiden Zahlen                                                                                                                                          */  Schedule(INCH5, INCH5, SI_1, 200, 200)                                                                      /* Bestimmen wann die INCH? Geschaltet werden.                                                                                                                                                 */  House(1, INCH0, 2, 5, ROOM_DARK, ROOM_BRIGHT, ROOM_WARM_W, ROOM_TV0,  NEON_LIGHT, ROOM_D_RED, ROOM_COL2)    /* Haus mit mehreren Zimmern welches �ber INCH0 geschaltet wird.                                                                                                                               */  House(8, INCH1, 3, 3, NEON_LIGHT, NEON_LIGHTL, NEON_LIGHTL, NEON_LIGHTD)                                    /* Haus welches �ber INCH1 geschaltet wird.                                                                                                                                                    */  House(12, INCH2, 2, 5, ROOM_TV0, SKIP_ROOM, ROOM_WARM_W, ROOM_COL1, ROOM_CHIMNEY)                           /* Haus welches �ber INCH2 geschaltet wird.                                                                                                                                                    */  Const(15, C_ALL, INCH3, 255, 10)                                                                            /* Beleuchtung des Ladens welche Tags�ber mit voller Helligkeit und sp�t nachts mit reduzierter Helligkeit leuchtet.                                                                           */  GasLights(16, INCH4, GAS_LIGHT, GAS_LIGHT, GAS_LIGHTD, GAS_LIGHT, GAS_LIGHT, GAS_LIGHT)                     /* Die Stra�enlaternen werden �ber INCH4 gesteuert. | Sie werden recht fr�h angeschaltet (Siehe oben).                                                                                         */  RGB_AmpelX_Fade_IO(22,  INCH5)                                                                              /* Verkehrsampel welche nachts �ber INCH5 abgeschaltet wird.                                                                                                                                   */
  EndCfg // End of the configuration
  };
//*******************************************************************

//---------------------------------------------
void Set_Start_Values(MobaLedLib_C &MobaLedLib)
//---------------------------------------------
{
}


// No macros used which are stored to the EEPROM => Disable the ENABLE_STORE_STATUS flag in case it was set in the excel sheet
#ifdef ENABLE_STORE_STATUS
  #undef ENABLE_STORE_STATUS
#endif






#endif // __LEDS_AUTOPROG_H__
