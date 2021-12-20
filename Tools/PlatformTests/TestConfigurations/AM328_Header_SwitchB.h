// This file contains the DCC and LED definitions.
//
// It was automatically generated by the program Prog_Generator_MobaLedLib.xlsm Ver. 3.1.0A      by Hardi
// File creation: 20.12.2021 11:54:25
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

#define LEDS_PER_CHANNEL ",17,3"

#define RECEIVE_LED_COLOR_PER_RS232
// Input channel defines for local inputs and expert users


//*** Digital switches ***

#define SwitchB1                0
#define SwitchB2                1
#define SwitchB3                2
#define SwitchB4                3
#define SwitchB5                4
#define SwitchB6                5
#define SwitchB7                6
#define SwitchB8                7
#define SwitchB9                8
// Reserve channels: 7 because MobaLedLib_Copy_to_InpStruct always writes multiple of 8 channels

//*** Output Channels ***
#define T1_1                    16
#define T1_2                    17
#define T2_1                    18
#define T2_2                    19
#define T1_3                    20
#define T1_4                    21
#define T4_1                    22
#define T4_2                    23
#define T5_1                    24
#define T5_2                    25
#define T6_1                    26
#define T6_2                    27
#define T7_1                    28
#define T7_2                    29
#define T8_1                    30
#define T8_2                    31
#define T9_1                    32
#define T9_2                    33


#define CTR_CHANNELS_1    9                                        // Number of used counter channels for keyboard 1. Up to 10 if one CD4017 is used, up to 18 if two CD4017 are used, ...
#define CTR_CHANNELS_2    0                                        // Number of used counter channels for keyboard 2. Up to 10 if one CD4017 is used, up to 18 if two CD4017 are used, ...
#define BUTTON_INP_LIST_1 A2                                       // Comma separated list of the button input pins
#define BUTTON_INP_LIST_2 Unused                                   // Comma separated list of the button input pins
#define CLK_PIN           A0                                       // Pin number used for the CD4017 clock
#define RESET_PIN         A3                                       // Pin number used for the CD4017 reset

#include <Keys_4017.h>                                             // Keyboard library which uses the CD4017 counter to save Arduino pins. Attention: The pins (CLK_PIN, ...) must be defined prior.

#define START_SWITCHES_1  0                                        // Define the start number for the first keyboard.
#define START_SWITCHES_2  16                                       // Define the start number for the second keyboard.

/*********************/
#define SETUP_FASTLED()                                                      \
/*********************/                                                      \
  CLEDController& controller0 = FastLED.addLeds<NEOPIXEL,  6>(leds+  0, 17); \
  CLEDController& controller1 = FastLED.addLeds<NEOPIXEL, A4>(leds+ 17,  3); \
                                                                             \
  controller0.clearLeds(256);                                                \
  controller1.clearLeds(256);                                                \
  FastLED.setDither(DISABLE_DITHER);       // avoid sending slightly modified brightness values
/*End*/

#define USE_ADDITIONAL_SETUP_PROC                                  // Activate the usage of the Additional_Setup_Proc()

//--------------------------
void Additional_Setup_Proc()
//--------------------------
{
  Keys_4017_Setup(); // Initialize the keyboard scanning process
}

/****************************/
#define Additional_Loop_Proc() \
/****************************/ \
{                              \
  MobaLedLib_Copy_to_InpStruct(Keys_Array_1, KEYS_ARRAY_BYTE_SIZE_1, START_SWITCHES_1);  \
}


//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
  RGB_Heartbeat(0)                                                                                            /* Excel row 4                                                                                                                                                                                 */  PushButton_w_LED_BL_0_1(17, C1, SwitchB1, T1_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 5                                                                                                                                                                                 */  PushButton_w_LED_BL_0_1(17, C2, SwitchB2, T2_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 6                                                                                                                                                                                 */  PushButton_w_LED_BL_0_1(17, C3, SwitchB3, T1_3, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 7                                                                                                                                                                                 */  PushButton_w_LED_BL_0_1(18, C1, SwitchB4, T4_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 8                                                                                                                                                                                 */  PushButton_w_LED_BL_0_1(18, C2, SwitchB5, T5_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 9                                                                                                                                                                                 */  PushButton_w_LED_BL_0_1(18, C3, SwitchB6, T6_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 10                                                                                                                                                                                */  PushButton_w_LED_BL_0_1(19, C1, SwitchB7, T7_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 11                                                                                                                                                                                */  PushButton_w_LED_BL_0_1(19, C2, SwitchB8, T8_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 12                                                                                                                                                                                */  PushButton_w_LED_BL_0_1(19, C3, SwitchB9, T9_1, 1, 0, 1, 0, 30 Sek, 127, 31)                                /* Excel row 13                                                                                                                                                                                */  ConstRGB(1, T1_1, 0, 0, 0, 127, 127, 127)                                                                   /* Excel row 15                                                                                                                                                                                */  ConstRGB(2, T1_2, 0, 0, 0, 127, 127, 127)                                                                   /* Excel row 16                                                                                                                                                                                */
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
