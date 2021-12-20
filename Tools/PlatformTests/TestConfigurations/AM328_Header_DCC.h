// This file contains the DCC and LED definitions.
//
// It was automatically generated by the program Prog_Generator_MobaLedLib.xlsm Ver. 3.1.0A      by Hardi
// File creation: 20.12.2021 11:54:19
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
  #warning "'NUM_LEDS' definition in the main program is replaced by the included 'LEDs_AutoProg.h' with 20"
  #undef NUM_LEDS
#endif

#define NUM_LEDS 20                    // Number of LEDs (Maximal 256 RGB LEDs could be used)

#define LEDS_PER_CHANNEL ",20"

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

// Definition of external adressesconst PROGMEM Ext_Addr_T Ext_Addr[] =         { // Addr & Typ    InCnt
           { 1    + B_RED,   2 },      // Steppersignal           { 33   + B_RED,   3 },      // Excel row 12           { 2    + S_ONOFF, 1 },      // Excel row 13         };


// Input channel defines for local inputs and expert users
#define INCH_DCC_1_RED          0      // Steppersignal#define INCH_DCC_1_GREEN        1      //     "#define INCH_DCC_33_RED         2      // Excel row 12#define INCH_DCC_33_GREEN       3      //     "#define INCH_DCC_34_RED         4      //     "#define INCH_DCC_2_ONOFF        5      // Excel row 13

//*** Direct connected switches ***

#define SwitchD1                6
// Reserve channels: 7 because MobaLedLib_Copy_to_InpStruct always writes multiple of 8 channels

const PROGMEM uint8_t SwitchD_Pins[] = { 7,8,9 };                  // Array of pins which read switches 'D'
#define SWITCH_D_INP_CNT sizeof(SwitchD_Pins)

/*********************/
#define SETUP_FASTLED()                                                      \
/*********************/                                                      \
  CLEDController& controller0 = FastLED.addLeds<NEOPIXEL,  6>(leds+  0, 20); \
                                                                             \
  controller0.clearLeds(256);                                                \
  FastLED.setDither(DISABLE_DITHER);       // avoid sending slightly modified brightness values
/*End*/

#define USE_ADDITIONAL_SETUP_PROC                                  // Activate the usage of the Additional_Setup_Proc()

//--------------------------
void Additional_Setup_Proc()
//--------------------------
{

  for (uint8_t i = 0; i < SWITCH_D_INP_CNT; i++)
    pinMode(pgm_read_byte_near(&SwitchD_Pins[i]), INPUT_PULLUP);
}

/****************************/
#define Additional_Loop_Proc() \
/****************************/ \
{                              \
  for (uint8_t i = 0; i < 1; i++) \
      MobaLedLib.Set_Input(SwitchD1 + i, !digitalRead(pgm_read_byte_near(&SwitchD_Pins[i])));\
}


//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
  RGB_Heartbeat2(0, 5, 100)                                                                                   /* LED auf dem Mainboard                                                                                                                                                                       */  #define ENABLE_STORE_STATUS()                                                                               /* Excel row 9                                                                                                                                                                                 */  // Activation: N_OneTimeBut1                                                                                /* Steppersignal                                                                                                                                                                               */  InCh_to_LocalVar1(0, 2)                                                                                     /*     "                                                                                                                                                                                       */  PatternT2(1,28,SI_LocalVar,2,0,255,0,PM_SEQUENZ_NO_RESTART,10,3 Sek,0,0,127,255,0,0,127,0,0,0  ,63,128,63,128,63) /*     "                                                                                                                                                                                 */  EntrySignal3_RGB(2, 2)                                                                                      /* Excel row 12                                                                                                                                                                                */  Const(5, C3, 5, 0, 100)                                                                                     /* Excel row 13                                                                                                                                                                                */  House(6, SwitchD1, 1, 2, ROOM_DARK, ROOM_BRIGHT, ROOM_WARM_W)                                               /* Excel row 23                                                                                                                                                                                */
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

// Definition of channels and counters that need to store state in EEPromconst PROGMEM Store_Channel_T Store_Values[] =         { // Mode + InCnt , Channel
           { IS_PULSE  + 2 , INCH_DCC_1_RED      },      // Steppersignal           { IS_PULSE  + 3 , INCH_DCC_33_RED     },      // Excel row 12           { IS_TOGGLE + 1 , INCH_DCC_2_ONOFF    },      // Excel row 13         };






#endif // __LEDS_AUTOPROG_H__
