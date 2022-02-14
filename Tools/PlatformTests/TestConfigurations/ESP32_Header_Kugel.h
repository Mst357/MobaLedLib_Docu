// This file contains the DCC and LED definitions.
//
// It was automatically generated by the program Prog_Generator_MobaLedLib.xlsm Ver. 3.1.0A      by Hardi
// File creation: 20.12.2021 11:53:58
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

#define START_MSG "LEDs_AutoProg Ver 1: Ver_3.1.0 20.12.21 11:53"

#define TWO_BUTTONS_PER_ADDRESS 1      // Two buttons (Red/Green) are used (DCC/CAN)
#ifdef NUM_LEDS
  #warning "'NUM_LEDS' definition in the main program is replaced by the included 'LEDs_AutoProg.h' with 166"
  #undef NUM_LEDS
#endif

#define NUM_LEDS 166                   // Number of LEDs (Maximal 256 RGB LEDs could be used)

#define LEDS_PER_CHANNEL ",150,16"

#define RECEIVE_LED_COLOR_PER_RS232
#define USE_EXT_ADDR
#define USE_RS232_OR_SPI_AS_INPUT      // Use the RS232 or SPI Input to read DCC/SX commands from the second Arduino and from the PC (The SPI is only used if enabled with USE_SPI_COM)
#define ADDR_OFFSET 0

#define ADDR_MSK  0x3FFF  // 14 Bits are used for the Address

#define S_ONOFF   (uint16_t)0
#define B_RED     (uint16_t)(1<<14)
#define B_GREEN   (uint16_t)(2<<14)
#define B_RESERVE (uint16_t)(3<<14)    // Not used at the moment
#define B_TAST    B_RED


typedef struct
    {
    uint16_t AddrAndTyp; // Addr range: 0..16383. The upper two bytes are used for the type
    uint8_t  InCnt;
    } __attribute__ ((packed)) Ext_Addr_T;

// Definition of external adresses
           { 3003 + B_RED,   1 },      // Excel row 8


// Input channel defines for local inputs and expert users
#define INCH_DCC_3003_RED       0      // Excel row 8

//*** Output Channels ***
#define S0                      145
#define S1                      146
#define S2                      147
#define S3                      148
#define S4                      149
#define S5                      150
#define FL1                     151

/*********************/
#define SETUP_FASTLED()                                                      \
/*********************/                                                      \
  CLEDController& controller0 = FastLED.addLeds<WS2811, 27, RGB>(leds+  0,150); \
  CLEDController& controller1 = FastLED.addLeds<WS2811, 32, RGB>(leds+150, 16); \
                                                                             \
  controller0.clearLeds(256);                                                \
  controller1.clearLeds(256);                                                \
  FastLED.setDither(DISABLE_DITHER);       // avoid sending slightly modified brightness values
/*End*/



//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
  #define COLOR_CORRECTION 0x606060                                                                           /* Excel row 4                                                                                                                                                                                 */
  EndCfg // End of the configuration
  };
//*******************************************************************

//---------------------------------------------
void Set_Start_Values(MobaLedLib_C &MobaLedLib)
//---------------------------------------------
{
}


// if function returns TRUE the calling loop stops
typedef bool(*HandleValue_t) (uint8_t CallbackType, uint8_t ValueId, uint8_t* Value, uint16_t EEPromAddr, uint8_t TargetValueId, uint8_t Options);


#define InCnt_MSK  0x0007  // 3 Bits are used for the InCnt
#define IS_COUNTER (uint8_t)0x80
#define IS_PULSE   (uint8_t)0x40
#define IS_TOGGLE  (uint8_t)0x00
#define COUNTER_ID

typedef struct
    {
    uint8_t TypAndInCnt; // Type bit 7, InCnt bits 0..3, reserved 0 bits 4..6
    uint8_t Channel;
    } __attribute__ ((packed)) Store_Channel_T;

// Definition of channels and counters that need to store state in EEProm
           { IS_COUNTER    , COUNTER_ID 1        },      // Excel row 8






#endif // __LEDS_AUTOPROG_H__