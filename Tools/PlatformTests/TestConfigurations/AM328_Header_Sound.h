// This file contains the DCC and LED definitions.
//
// It was automatically generated by the program Prog_Generator_MobaLedLib.xlsm Ver. 3.1.0A      by Hardi
// File creation: 20.12.2021 11:54:22
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

#define LEDS_PER_CHANNEL ",19,1"

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
           { 11   + B_RED,   1 },      // Excel row 9           { 12   + B_RED,   1 },      // Excel row 10           { 13   + B_RED,   1 },      // Excel row 11           { 14   + B_RED,   1 },      // Excel row 12           { 15   + B_RED,   1 },      // Excel row 13           { 101  + B_RED,   1 },      // Excel row 15           { 101  + B_GREEN, 1 },      // Excel row 16           { 1    + S_ONOFF, 1 },      // Excel row 20           { 2    + S_ONOFF, 1 },      // Excel row 21           { 33   + S_ONOFF, 1 },      // Excel row 142         };


// Input channel defines for local inputs and expert users
#define INCH_DCC_11_RED         0      // Excel row 9#define INCH_DCC_12_RED         1      // Excel row 10#define INCH_DCC_13_RED         2      // Excel row 11#define INCH_DCC_14_RED         3      // Excel row 12#define INCH_DCC_15_RED         4      // Excel row 13#define INCH_DCC_101_RED        5      // Excel row 15#define INCH_DCC_101_GREEN      6      // Excel row 16#define INCH_DCC_1_ONOFF        7      // Excel row 20#define INCH_DCC_2_ONOFF        8      // Excel row 21#define INCH_DCC_33_ONOFF       9      // Excel row 142

//*** Output Channels ***
#define S0                      10
#define S1                      11
#define S2                      12
#define S3                      13
#define S4                      14
#define S5                      15
#define S6                      16
#define S7                      17
#define S8                      18
#define S9                      19
#define S10                     20
#define S11                     21
#define S12                     22
#define S13                     23
#define S14                     24
#define S15                     25
#define S16                     26
#define S17                     27
#define S18                     28
#define S19                     29
#define S20                     30
#define S21                     31
#define S22                     32
#define S23                     33
#define S24                     34
#define S25                     35
#define S26                     36
#define S27                     37
#define S28                     38
#define S29                     39
#define S30                     40
#define S31                     41
#define S32                     42
#define SG3                     43
#define SG31                    44
#define Beep                    45

/*********************/
#define SETUP_FASTLED()                                                      \
/*********************/                                                      \
  CLEDController& controller0 = FastLED.addLeds<NEOPIXEL,  6>(leds+  0, 19); \
  CLEDController& controller1 = FastLED.addLeds<NEOPIXEL, A4>(leds+ 19,  1); \
                                                                             \
  controller0.clearLeds(256);                                                \
  controller1.clearLeds(256);                                                \
  FastLED.setDither(DISABLE_DITHER);       // avoid sending slightly modified brightness values
/*End*/

/*****************************/
#define Additional_Loop_Proc2() \
/*****************************/ \
{                               \
   soundProcessor.process();\
}
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
        { S0,                 19,    (0   << 3) | T_EQUAL_THEN,      0   },        { S1,                 19,    (0   << 3) | T_EQUAL_THEN,      1   },        { S2,                 19,    (0   << 3) | T_EQUAL_THEN,      2   },        { S3,                 19,    (0   << 3) | T_EQUAL_THEN,      3   },        { S4,                 19,    (0   << 3) | T_EQUAL_THEN,      4   },        { S5,                 19,    (0   << 3) | T_EQUAL_THEN,      5   },        { S6,                 19,    (0   << 3) | T_EQUAL_THEN,      6   },        { S7,                 19,    (0   << 3) | T_EQUAL_THEN,      7   },        { S8,                 19,    (0   << 3) | T_EQUAL_THEN,      8   },        { S9,                 19,    (0   << 3) | T_EQUAL_THEN,      9   },        { S10,                19,    (0   << 3) | T_EQUAL_THEN,      10  },        { S11,                19,    (0   << 3) | T_EQUAL_THEN,      11  },        { S12,                19,    (0   << 3) | T_EQUAL_THEN,      12  },        { S13,                19,    (0   << 3) | T_EQUAL_THEN,      13  },        { S14,                19,    (0   << 3) | T_EQUAL_THEN,      14  },        { S15,                19,    (0   << 3) | T_EQUAL_THEN,      15  },        { S16,                19,    (0   << 3) | T_EQUAL_THEN,      16  },        { S17,                19,    (0   << 3) | T_EQUAL_THEN,      17  },        { S18,                19,    (0   << 3) | T_EQUAL_THEN,      18  },        { S19,                19,    (0   << 3) | T_EQUAL_THEN,      19  },        { S20,                19,    (0   << 3) | T_EQUAL_THEN,      20  },        { S21,                19,    (0   << 3) | T_EQUAL_THEN,      21  },        { S22,                19,    (0   << 3) | T_EQUAL_THEN,      22  },        { S23,                19,    (0   << 3) | T_EQUAL_THEN,      23  },        { S24,                19,    (0   << 3) | T_EQUAL_THEN,      24  },        { S25,                19,    (0   << 3) | T_EQUAL_THEN,      25  },        { S26,                19,    (0   << 3) | T_EQUAL_THEN,      26  },        { S27,                19,    (0   << 3) | T_EQUAL_THEN,      27  },        { S28,                19,    (0   << 3) | T_EQUAL_THEN,      28  },        { S29,                19,    (0   << 3) | T_EQUAL_THEN,      29  },        { S30,                19,    (0   << 3) | T_EQUAL_THEN,      30  },        { S31,                19,    (0   << 3) | T_EQUAL_THEN,      31  },        { S32,                19,    (0   << 3) | T_EQUAL_THEN,      32  },        { SG3,                19,    (0   << 3) | T_GREATER_THAN,    2   },        { SG31,               19,    (0   << 3) | T_GREATER_THAN,    30  },
      };


// ----- Serial Onboard Sound Makros -----
  #include "SoundChannelMacros.h"

  #define SOUND_CHANNEL_0 0
  #define SOUND_CHANNEL_1 1
  #define SOUND_CHANNEL_2 2



//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
  Set_CandleTab(0, 25, 90, 90, 90, 90, 20, 100, 20)                                                           /* Excel row 5                                                                                                                                                                                 */  House(0, SI_1, 1, 1, CANDLE)                                                                                /* Excel row 6                                                                                                                                                                                 */  Sound_JQ6500_Seq1(1, 0)                                                                                     /* Excel row 9                                                                                                                                                                                 */  Sound_JQ6500_Seq2(1, 1)                                                                                     /* Excel row 10                                                                                                                                                                                */  Sound_JQ6500_Seq3(1, 2)                                                                                     /* Excel row 11                                                                                                                                                                                */  Sound_JQ6500_Seq4(1, 3)                                                                                     /* Excel row 12                                                                                                                                                                                */  Sound_JQ6500_Seq5(1, 4)                                                                                     /* Excel row 13                                                                                                                                                                                */  Sound_JQ6500_DecVol(1, 5, 1)                                                                                /* Excel row 15                                                                                                                                                                                */  Sound_JQ6500_IncVol(1, 6, 1)                                                                                /* Excel row 16                                                                                                                                                                                */  Const(1, C2, 7, 0, 127)                                                                                     /* Excel row 20                                                                                                                                                                                */  Const(1, C3, 8, 0, 127)                                                                                     /* Excel row 21                                                                                                                                                                                */  // Activation: N_Buttons1                                                                                   /* DiscoSequenz (pc)                                                                                                                                                                           */  InCh_to_TmpVar1(INCH_DCC_11_RED  , 1)                                                                       /*     "                                                                                                                                                                                       */  PatternT33(19,28,SI_LocalVar,1,0,255,0,PM_NORMAL,1,12600,6900,450,650,2400,450,650,2850,450,3000,20,1000,1500,830,430,1370,450,1350,450,1250,450,1300,450,450,450,550,450,300,450,450,3750,10000,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33  ,127,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0) /*     " */  // Next_LED(-1)                                                                                             /* Excel row 28                                                                                                                                                                                */  // Activation: N_Buttons1                                                                                   /* DiscoSequenz (pc)                                                                                                                                                                           */  InCh_to_TmpVar1(INCH_DCC_12_RED  , 1)                                                                       /*     "                                                                                                                                                                                       */  PatternT33(19,28,SI_LocalVar,1,0,255,0,PM_NORMAL,1,700,900,450,650,2400,450,650,2850,450,3000,20,1000,1550,830,430,1370,450,1350,450,1250,450,1300,450,450,450,550,450,300,450,450,3750,20000,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33  ,127,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0) /*     " */  // LED_to_Var(S0, 0, =, 0)                                                                                  /* Variable S0 setzten bei Led=0                                                                                                                                                               */  // LED_to_Var(S1, 0, =, 1)                                                                                  /* Variable S1 setzten bei Led=1                                                                                                                                                               */  // LED_to_Var(S2, 0, =, 2)                                                                                  /* Variable S2 setzten bei Led=2                                                                                                                                                               */  // LED_to_Var(S3, 0, =, 3)                                                                                  /* Variable S3 setzten bei Led=3                                                                                                                                                               */  // LED_to_Var(S4, 0, =, 4)                                                                                  /* Variable S4 setzten bei Led=4                                                                                                                                                               */  // LED_to_Var(S5, 0, =, 5)                                                                                  /* Variable S5 setzten bei Led=5                                                                                                                                                               */  // LED_to_Var(S6, 0, =, 6)                                                                                  /* Variable S6 setzten bei Led=6                                                                                                                                                               */  // LED_to_Var(S7, 0, =, 7)                                                                                  /* Variable S7 setzten bei Led=7                                                                                                                                                               */  // LED_to_Var(S8, 0, =, 8)                                                                                  /* Variable S8 setzten bei Led=8                                                                                                                                                               */  // LED_to_Var(S9, 0, =, 9)                                                                                  /* Variable S9 setzten bei Led=9                                                                                                                                                               */  // LED_to_Var(S10, 0, =, 10)                                                                                /* Variable S10 setzten bei Led=10                                                                                                                                                             */  // LED_to_Var(S11, 0, =, 11)                                                                                /* Excel row 41                                                                                                                                                                                */  // LED_to_Var(S12, 0, =, 12)                                                                                /* Excel row 42                                                                                                                                                                                */  // LED_to_Var(S13, 0, =, 13)                                                                                /* Excel row 43                                                                                                                                                                                */  // LED_to_Var(S14, 0, =, 14)                                                                                /* Excel row 44                                                                                                                                                                                */  // LED_to_Var(S15, 0, =, 15)                                                                                /* Variable S15 setzten bei Led=15                                                                                                                                                             */  // LED_to_Var(S16, 0, =, 16)                                                                                /* Variable S16 setzten bei Led=16                                                                                                                                                             */  // LED_to_Var(S17, 0, =, 17)                                                                                /* Variable S17 setzten bei Led=17                                                                                                                                                             */  // LED_to_Var(S18, 0, =, 18)                                                                                /* Variable S18 setzten bei Led=18                                                                                                                                                             */  // LED_to_Var(S19, 0, =, 19)                                                                                /* Variable S19 setzten bei Led=19                                                                                                                                                             */  // LED_to_Var(S20, 0, =, 20)                                                                                /* Variable S20 setzten bei Led=20                                                                                                                                                             */  // LED_to_Var(S21, 0, =, 21)                                                                                /* Variable S21 setzten bei Led=21                                                                                                                                                             */  // LED_to_Var(S22, 0, =, 22)                                                                                /* Variable S22 setzten bei Led=22                                                                                                                                                             */  // LED_to_Var(S23, 0, =, 23)                                                                                /* Variable S23 setzten bei Led=23                                                                                                                                                             */  // LED_to_Var(S24, 0, =, 24)                                                                                /* Variable S24 setzten bei Led=24                                                                                                                                                             */  // LED_to_Var(S25, 0, =, 25)                                                                                /* Variable S25 setzten bei Led=25                                                                                                                                                             */  // LED_to_Var(S26, 0, =, 26)                                                                                /* Variable S26 setzten bei Led=26                                                                                                                                                             */  // LED_to_Var(S27, 0, =, 27)                                                                                /* Variable S27 setzten bei Led=27                                                                                                                                                             */  // LED_to_Var(S28, 0, =, 28)                                                                                /* Variable S28 setzten bei Led=28                                                                                                                                                             */  // LED_to_Var(S29, 0, =, 29)                                                                                /* Variable S29 setzten bei Led=29                                                                                                                                                             */  // LED_to_Var(S30, 0, =, 30)                                                                                /* Variable S30 setzten bei Led=30                                                                                                                                                             */  // LED_to_Var(S31, 0, =, 31)                                                                                /* Variable S31 setzten bei Led=31                                                                                                                                                             */  // LED_to_Var(S32, 0, =, 32)                                                                                /* Variable S32 setzten bei Led=32                                                                                                                                                             */  // LED_to_Var(SG3, 0, >, 2)                                                                                 /* SG3                                                                                                                                                                                         */  // LED_to_Var(SG31, 0, >, 30)                                                                               /* SG31                                                                                                                                                                                        */  Logic(Beep, S4 OR S7 OR S9 OR S11 OR S15 OR S17 OR S19 OR S21 OR S23 OR S25 OR S27 OR S29 OR S31)           /* Excel row 66                                                                                                                                                                                */  APatternT7(2,140,S1,3,0,255,0,0,5500,2000,2000,1600,0,1000,10000,16,0,19,1,136,0,0,64,4,0,0)                /* DiscoMood (pc)                                                                                                                                                                              */  // Next_LED(-1)                                                                                             /* Excel row 68                                                                                                                                                                                */  ConstRGB(2, S2, 0, 0, 0, 127, 0,0)                                                                          /* Excel row 69                                                                                                                                                                                */  // Next_LED(-1)                                                                                             /* Excel row 70                                                                                                                                                                                */  APatternT32(2,140,SG3,3,0,255,0,0,450,650,2400,0,1100,1450,1450,0,450,3000,20,1000,1500,830,430,1370,450,1350,450,1250,450,1300,450,450,450,550,450,300,450,450,450,10000,8,240,0,240,0,240,240,240,0,255,0,240,255,0) /* DiscoMood2 (pc)                                                                  */  // Next_LED(-1)                                                                                             /* Excel row 72                                                                                                                                                                                */  APatternT2(2,12,SG31,3,0,255,0,0,415,0,15,0,0,240,0,0,0,15,0)                                               /* DiscoMood3 (pc)                                                                                                                                                                             */  APatternT19(3,140,S1,3,0,255,0,0,5000,0,300,1500,0,300,400,0,300,350,0,300,140,0,300,3100,0,400,7000,0,240,255,0,0,0,255,15,0,0,240,255,0,0,0,255,15,0,0,240,255,0,0,0,255,15,2,0,0) /* DiscoEffekt (pc)                                                                                                   */  // Next_LED(-1)                                                                                             /* Excel row 134                                                                                                                                                                               */  ConstRGB(3, S2, 0, 0, 0, 127, 0,0)                                                                          /* Excel row 135                                                                                                                                                                               */  // Next_LED(-1)                                                                                             /* Excel row 136                                                                                                                                                                               */  APatternT9(3,140,Beep,3,0,255,0,0,0,50,0,50,0,50,0,50,0,0,15,240,15,255,240,240,15,255,255,255,255,0,0)     /* Disco5Beep (pc)                                                                                                                                                                             */  // Next_LED(-1)                                                                                             /* Excel row 138                                                                                                                                                                               */  APatternT2(3,12,SG31,3,0,255,0,0,415,0,15,0,0,240,0,0,0,15,0)                                               /* DiscoMood3 (pc)                                                                                                                                                                             */  ConstrWarnLightRGB6(4, 9, 5, 255, 100 ms, 0 ms, 500 ms)                                                     /* Excel row 142                                                                                                                                                                               */  // Set_CLK_Pin_Number(6)                                                                                    /* Excel row 146                                                                                                                                                                               */  // SOUND_CHANNEL_DEFINITON(BUTTONS_K,JQ6500)                                                                /* Excel row 149                                                                                                                                                                               */  // SOUND_CHANNEL_DEFINITON(KEY80_P2, JQ6500)                                                                /* Excel row 150                                                                                                                                                                               */  // SOUND_CHANNEL_DEFINITON(KEY80_P4,JQ6500)                                                                 /* Excel row 151                                                                                                                                                                               */
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
           { IS_TOGGLE + 1 , INCH_DCC_1_ONOFF    },      // Excel row 20           { IS_TOGGLE + 1 , INCH_DCC_2_ONOFF    },      // Excel row 21           { IS_TOGGLE + 1 , INCH_DCC_33_ONOFF   },      // Excel row 142         };

// ----- Serial Onboard Sound -----
#ifndef _USE_EXT_PROC
  #error _USE_EXT_PROC must be enabled in MobaLebLib, see file 'Lib_Config.h'
#else
  // includes for Onboard sound processing
#define _SOUNDPROCCESSOR_SEND_FULL_PACKET
  #include "SoundProcessor.h"

  #ifndef _ENABLE_EXT_PROC
  #define _ENABLE_EXT_PROC
  #endif
  #ifndef _SOUND_SERBUFFER_SIZE
  #define _SOUND_SERBUFFER_SIZE  30 
  #endif

  uint8_t serBuffer[_SOUND_SERBUFFER_SIZE];
  SoundPlayer* soundPlayers[] {new JQ6500SoundPlayer( 0, SoundProcessor::CreateSoftwareSerial(A2, 9600)), new JQ6500SoundPlayer( 1, SoundProcessor::CreateSoftwareSerial(7, 9600)), new JQ6500SoundPlayer( 2, SoundProcessor::CreateSoftwareSerial(9, 9600))};
  SoundProcessor soundProcessor(serBuffer, _SOUND_SERBUFFER_SIZE, soundPlayers);
#endif






#endif // __LEDS_AUTOPROG_H__
