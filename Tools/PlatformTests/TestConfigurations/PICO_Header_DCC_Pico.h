// This file contains the DCC and LED definitions.
//
// It was automatically generated by the program Prog_Generator_MobaLedLib.xlsm Ver. 3.1.0A      by Hardi
// File creation: 20.12.2021 11:57:46
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

// Definition of external adressesconst PROGMEM Ext_Addr_T Ext_Addr[] =         { // Addr & Typ    InCnt
           { 10   + S_ONOFF, 1 },      // Blinkertest           { 11   + S_ONOFF, 1 },      // Blaulicht 1           { 12   + S_ONOFF, 1 },      // Leuchtfeuer           { 13   + S_ONOFF, 1 },      // Andreaskreuz 1           { 14   + S_ONOFF, 1 },      // Andreaskreuz 2           { 20   + S_ONOFF, 1 },      // Schwei�licht, Pause 1 - 10 Sekunden, Dauer 2 - 5 Sekunden           { 21   + S_ONOFF, 1 },      // Excel row 15           { 22   + S_ONOFF, 1 },      // Excel row 16           { 23   + S_ONOFF, 1 },      // Excel row 17           { 30   + S_ONOFF, 1 },      // Excel row 19           { 40   + S_ONOFF, 1 },      // Excel row 22           { 50   + B_RED,   3 },      // Excel row 24           { 52   + B_RED,   3 },      // Excel row 25           { 60   + B_RED,   4 },      // Excel row 28         };


// Input channel defines for local inputs and expert users
#define INCH_DCC_10_ONOFF       0      // Blinkertest#define INCH_DCC_11_ONOFF       1      // Blaulicht 1#define INCH_DCC_12_ONOFF       2      // Leuchtfeuer#define INCH_DCC_13_ONOFF       3      // Andreaskreuz 1#define INCH_DCC_14_ONOFF       4      // Andreaskreuz 2#define INCH_DCC_20_ONOFF       5      // Schwei�licht, Pause 1 - 10 Sekunden, Dauer 2 - 5 Sekunden#define INCH_DCC_21_ONOFF       6      // Excel row 15#define INCH_DCC_22_ONOFF       7      // Excel row 16#define INCH_DCC_23_ONOFF       8      // Excel row 17#define INCH_DCC_30_ONOFF       9      // Excel row 19#define INCH_DCC_40_ONOFF       10     // Excel row 22#define INCH_DCC_50_RED         11     // Excel row 24#define INCH_DCC_50_GREEN       12     //     "#define INCH_DCC_51_RED         13     //     "#define INCH_DCC_52_RED         14     // Excel row 25#define INCH_DCC_52_GREEN       15     //     "#define INCH_DCC_53_RED         16     //     "#define INCH_DCC_60_RED         17     // Excel row 28#define INCH_DCC_60_GREEN       18     //     "#define INCH_DCC_61_RED         19     //     "#define INCH_DCC_61_GREEN       20     //     "// Local InCh variables#define LOC_INCH0               21#define LOC_INCH1               22

//*** Digital switches ***

#define SwitchB1                24
#define SwitchB2                25
#define SwitchB3                26
#define SwitchB4                27
#define SwitchB5                28
#define SwitchB6                29
#define SwitchB7                30
#define SwitchB8                31
#define SwitchB9                32
#define SwitchB10               33
// Reserve channels: 6 because MobaLedLib_Copy_to_InpStruct always writes multiple of 8 channels

//*** Direct connected switches ***

#define SwitchD1                40
#define SwitchD2                41
#define SwitchD3                42
// Reserve channels: 5 because MobaLedLib_Copy_to_InpStruct always writes multiple of 8 channels

const PROGMEM uint8_t SwitchD_Pins[] = { 10,9,8 };                 // Array of pins which read switches 'D'
#define SWITCH_D_INP_CNT sizeof(SwitchD_Pins)


#define CTR_CHANNELS_1    10                                       // Number of used counter channels for keyboard 1. Up to 10 if one CD4017 is used, up to 18 if two CD4017 are used, ...
#define CTR_CHANNELS_2    0                                        // Number of used counter channels for keyboard 2. Up to 10 if one CD4017 is used, up to 18 if two CD4017 are used, ...
#define BUTTON_INP_LIST_1 16                                       // Comma separated list of the button input pins
#define BUTTON_INP_LIST_2 Unused                                   // Comma separated list of the button input pins
#define CLK_PIN           14                                       // Pin number used for the CD4017 clock
#define RESET_PIN         15                                       // Pin number used for the CD4017 reset

#include <Keys_4017.h>                                             // Keyboard library which uses the CD4017 counter to save Arduino pins. Attention: The pins (CLK_PIN, ...) must be defined prior.

#define START_SWITCHES_1  24                                       // Define the start number for the first keyboard.
#define START_SWITCHES_2  40                                       // Define the start number for the second keyboard.

/*********************/
#define SETUP_FASTLED()                                                      \
/*********************/                                                      \
  CLEDController& controller0 = FastLED.addLeds<NEOPIXEL,  1>(leds+  0, 50); \
                                                                             \
  controller0.clearLeds(256);                                                \
  FastLED.setDither(DISABLE_DITHER);       // avoid sending slightly modified brightness values
/*End*/

#define USE_ADDITIONAL_SETUP_PROC                                  // Activate the usage of the Additional_Setup_Proc()

//--------------------------
void Additional_Setup_Proc()
//--------------------------
{
  Keys_4017_Setup(); // Initialize the keyboard scanning process

  for (uint8_t i = 0; i < SWITCH_D_INP_CNT; i++)
    pinMode(pgm_read_byte_near(&SwitchD_Pins[i]), INPUT_PULLUP);
}

/****************************/
#define Additional_Loop_Proc() \
/****************************/ \
{                              \
  MobaLedLib_Copy_to_InpStruct(Keys_Array_1, KEYS_ARRAY_BYTE_SIZE_1, START_SWITCHES_1);  \
  for (uint8_t i = 0; i < 3; i++) \
      MobaLedLib.Set_Input(SwitchD1 + i, !digitalRead(pgm_read_byte_near(&SwitchD_Pins[i])));\
}


//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
  RGB_Heartbeat(0)                                                                                            /* Zeigt an, dass die LEDs angesteuert werden                                                                                                                                                  */  // Set_LED_OutpPinLst(1)                                                                                    /* Excel row 4                                                                                                                                                                                 */  BlinkerHD(1, C12, 0, 1 Sek)                                                                                 /* Blinkertest                                                                                                                                                                                 */  BlueLight1(1, C3, 1)                                                                                        /* Blaulicht 1                                                                                                                                                                                 */  BlueLight2(2, C3, INCH_DCC_11_ONOFF)                                                                        /* Blaulicht 2                                                                                                                                                                                 */  Leuchtfeuer(3, C12, 2)                                                                                      /* Leuchtfeuer                                                                                                                                                                                 */  Andreaskreuz(4, C23, 3)                                                                                     /* Andreaskreuz 1                                                                                                                                                                              */  AndreaskrRGB(5, 4)                                                                                          /* Andreaskreuz 2                                                                                                                                                                              */  RandWelding(7, 5, LOC_INCH0, 1 Sek, 10 Sek, 2 Sek, 5 Sek)                                                   /* Schwei�licht, Pause 1 - 10 Sekunden, Dauer 2 - 5 Sekunden                                                                                                                                   */  Flash(8, C23, 6, LOC_INCH1, 1 Sek, 20 Sek)                                                                  /* Excel row 15                                                                                                                                                                                */  AndreaskrRGB(9, 7)                                                                                          /* Excel row 16                                                                                                                                                                                */  ConstrWarnLight6(11, 8, 5, 127, 100 ms, 500 ms)                                                             /* Excel row 17                                                                                                                                                                                */  GasLights(13, 9, GAS_LIGHT, GAS_LIGHT, GAS_LIGHT, GAS_LIGHT, GAS_LIGHT, GAS_LIGHT)                          /* Excel row 19                                                                                                                                                                                */  HouseT(19, 10, 1, 6, 1, 10, ROOM_TV0, NEON_LIGHT, ROOM_DARK, ROOM_CHIMNEY, ROOM_TV1, CANDLE)                /* Excel row 22                                                                                                                                                                                */  EntrySignal3_RGB(25, 11)                                                                                    /* Excel row 24                                                                                                                                                                                */  EntrySignal3_RGB_B(28, 14, 127)                                                                             /* Excel row 25                                                                                                                                                                                */  KS_Hauptsignal_Zs3_Zs6_Zs1_RGB(31, 17, 128)                                                                 /* Excel row 28                                                                                                                                                                                */  RGB_Heartbeat(36)                                                                                           /* Excel row 30                                                                                                                                                                                */  ConstRGB(37, SwitchD1, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 32                                                                                                                                                                                */  ConstRGB(38, SwitchD2, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 33                                                                                                                                                                                */  ConstRGB(39, SwitchD3, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 34                                                                                                                                                                                */  ConstRGB(40, SwitchB1, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 36                                                                                                                                                                                */  ConstRGB(41, SwitchB2, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 37                                                                                                                                                                                */  ConstRGB(42, SwitchB3, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 38                                                                                                                                                                                */  ConstRGB(43, SwitchB4, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 39                                                                                                                                                                                */  ConstRGB(44, SwitchB5, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 40                                                                                                                                                                                */  ConstRGB(45, SwitchB6, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 41                                                                                                                                                                                */  ConstRGB(46, SwitchB7, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 42                                                                                                                                                                                */  ConstRGB(47, SwitchB8, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 43                                                                                                                                                                                */  ConstRGB(48, SwitchB9, 0, 0, 0, 127, 127, 127)                                                              /* Excel row 44                                                                                                                                                                                */  ConstRGB(49, SwitchB10, 0, 0, 0, 127, 127, 127)                                                             /* Excel row 45                                                                                                                                                                                */  #define Mainboard_LED1  SwitchD1                                                                            /* Excel row 47                                                                                                                                                                                */  #define Mainboard_LED2  SwitchD2                                                                            /* Excel row 48                                                                                                                                                                                */  #define Mainboard_LED3  SwitchD3                                                                            /* Excel row 49                                                                                                                                                                                */  #define SEND_INPUTS                                                                                         /* Excel row 51                                                                                                                                                                                */
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
           { IS_TOGGLE + 1 , INCH_DCC_10_ONOFF   },      // Blinkertest           { IS_TOGGLE + 1 , INCH_DCC_11_ONOFF   },      // Blaulicht 1           { IS_TOGGLE + 1 , INCH_DCC_12_ONOFF   },      // Leuchtfeuer           { IS_TOGGLE + 1 , INCH_DCC_13_ONOFF   },      // Andreaskreuz 1           { IS_TOGGLE + 1 , INCH_DCC_14_ONOFF   },      // Andreaskreuz 2           { IS_TOGGLE + 1 , INCH_DCC_20_ONOFF   },      // Schwei�licht, Pause 1 - 10 Sekunden, Dauer 2 - 5 Sekunden           { IS_TOGGLE + 1 , INCH_DCC_21_ONOFF   },      // Excel row 15           { IS_TOGGLE + 1 , INCH_DCC_22_ONOFF   },      // Excel row 16           { IS_TOGGLE + 1 , INCH_DCC_23_ONOFF   },      // Excel row 17           { IS_TOGGLE + 1 , INCH_DCC_30_ONOFF   },      // Excel row 19           { IS_TOGGLE + 1 , INCH_DCC_40_ONOFF   },      // Excel row 22           { IS_PULSE  + 3 , INCH_DCC_50_RED     },      // Excel row 24           { IS_PULSE  + 3 , INCH_DCC_52_RED     },      // Excel row 25           { IS_PULSE  + 4 , INCH_DCC_60_RED     },      // Excel row 28         };






#endif // __LEDS_AUTOPROG_H__
