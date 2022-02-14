// This file contains the DCC and LED definitions.
//
// It was automatically generated by the program Prog_Generator_MobaLedLib.xlsm Ver. 3.1.0A      by Hardi
// File creation: 20.12.2021 11:57:34
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

#define START_MSG "LEDs_AutoProg Ver 1: Ver_3.1.0 20.12.21 11:57"

#define TWO_BUTTONS_PER_ADDRESS 1      // Two buttons (Red/Green) are used (DCC/CAN)
#ifdef NUM_LEDS
  #warning "'NUM_LEDS' definition in the main program is replaced by the included 'LEDs_AutoProg.h' with 50"
  #undef NUM_LEDS
#endif

#define NUM_LEDS 50                    // Number of LEDs (Maximal 256 RGB LEDs could be used)

#define LEDS_PER_CHANNEL ",50"

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
           { 22   + B_RED,   1 },      // Zeitgeber (pc) 0 = 0:00, 239 = 23:59


// Input channel defines for local inputs and expert users
#define INCH_DCC_22_RED         0      // Zeitgeber (pc) 0 = 0:00, 239 = 23:59

//*** Output Channels ***
#define t1                      3
#define t2                      4
#define t3                      5
#define t4                      6
#define t5                      7
#define t6                      8
#define t7                      9
#define t8                      10
#define t9                      11
#define t10                     12
#define t11                     13
#define t12                     14
#define t13                     15
#define t14                     16
#define t15                     17
#define t16                     18
#define t17                     19
#define t18                     20
#define t19                     21
#define t20                     22
#define t21                     23
#define t22                     24
#define t23                     25
#define BlinkerEin              26
#define h18bis23                27
#define h22bis03                28
#define h06bis09                29
#define rand1                   30
#define rand2                   31
#define rand3                   32
#define rand4                   33
#define rand5                   34
#define rand6                   35
#define rand7                   36
#define rand8                   37

/*********************/
#define SETUP_FASTLED()                                                      \
/*********************/                                                      \
  CLEDController& controller0 = FastLED.addLeds<NEOPIXEL,  0>(leds+  0, 50); \
                                                                             \
  controller0.clearLeds(256);                                                \
  FastLED.setDither(DISABLE_DITHER);       // avoid sending slightly modified brightness values
/*End*/

// ----- LED to Var -----
  #define USE_LED_TO_VAR

  #define T_EQUAL_THEN     0
  #define T_NOT_EQUAL_THEN 1
  #define T_LESS_THEN      2
  #define T_GREATER_THAN   3
  #define T_BIN_MASK       4
  #define T_NOT_BIN_MASK   5

  typedef struct
      {
      uint8_t  Var_Nr;
      uint8_t  LED_Nr;
      uint8_t  Offset_and_Typ; // ---oottt    Offset: 0..2
      uint8_t  Val;
      } __attribute__ ((packed)) LED2Var_Tab_T;

  const PROGMEM LED2Var_Tab_T LED2Var_Tab[] =
      {
        // Var name           LED_Nr LED Offset   Typ                Compare value
        { t1,                 1,     (0   << 3) | T_GREATER_THAN,    9   },
      };




//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
  RGB_Heartbeat(0)                                                                                            /* Excel row 4                                                                                                                                                                                 */
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
           { IS_TOGGLE + 1 , INCH_DCC_23_ONOFF   },      // Excel row 29






#endif // __LEDS_AUTOPROG_H__