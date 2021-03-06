#ifndef _PINS_H
#define _PINS_H
 
/****************************************************************************************
* Sanguinololu pin assignment
*
****************************************************************************************/
#if MOTHERBOARD == 62
#undef MOTHERBOARD
#define MOTHERBOARD 6
#define SANGUINOLOLU_V_1_2 
#endif
#if MOTHERBOARD == 6
#define KNOWN_BOARD 1
#ifndef __AVR_ATmega644P__
#ifndef __AVR_ATmega1284P__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif
#endif

#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_MIN_PIN          18
#define X_MAX_PIN           -1

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_MIN_PIN          19
#define Y_MAX_PIN          -1

#define Z_STEP_PIN         3
#define Z_DIR_PIN          2
#define Z_MIN_PIN          20
#define Z_MAX_PIN          -1

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0

#define PROBE_PIN          20

#define LED_PIN            -1
#define FAN_PIN            -1

#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       13 // (extruder)
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1

#ifdef SANGUINOLOLU_V_1_2

#define HEATER_BED_PIN     10 // (bed) - 10 for spare DIO pin and bed MOSFET, 12 for SL MOSFET
#define X_ENABLE_PIN       14
#define Y_ENABLE_PIN       14
#define Z_ENABLE_PIN       26
#define E0_ENABLE_PIN       14

#else

#define HEATER_BED_PIN       14  // (bed)
#define X_ENABLE_PIN       -1
#define Y_ENABLE_PIN       -1
#define Z_ENABLE_PIN       -1
#define E0_ENABLE_PIN       -1

#endif

#define TEMP_0_PIN          7   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 33 extruder)
#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1
#define TEMP_BED_PIN        6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 34 bed)
#define SDPOWER            -1
#define SDSS               31


#endif

/****************************************************************************************
* Melzi pin assignment
*
****************************************************************************************/
#if MOTHERBOARD == 63
#define KNOWN_BOARD 1
#ifndef __AVR_ATmega644P__
#ifndef __AVR_ATmega1284P__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif
#endif

#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_MIN_PIN          18
#define X_MAX_PIN           -2

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_MIN_PIN          19
#define Y_MAX_PIN          -1

#define Z_STEP_PIN         3
#define Z_DIR_PIN          2
#define Z_MIN_PIN          20
#define Z_MAX_PIN          -1

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0
#ifdef DOUBLEEXTRUDER
#define E1_DIR_PIN          28
#define E1_STEP_PIN         17
#endif

#define PROBE_PIN          29    //29 on Melzi1284p A2

#define LED_PIN            27

#define FAN_PIN            4 

#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       13 // (extruder)
#ifdef DOUBLEEXTRUDER
#define HEATER_1_PIN       30
#else
#define HEATER_1_PIN       -1
#endif
#define HEATER_2_PIN       -1

#define HEATER_BED_PIN     12 // bed (change to 10 for gate pin of MOSFET on heated bed)
#define X_ENABLE_PIN       14
#define Y_ENABLE_PIN       14
#define Z_ENABLE_PIN       26
#define E0_ENABLE_PIN      14
#ifdef DOUBLEEXTRUDER
#define E1_ENABLE_PIN      29
#endif

#define TEMP_0_PIN          7   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 33 extruder)
#ifdef DOUBLEEXTRUDER
#define TEMP_1_PIN          4
#else
#define TEMP_1_PIN          -1
#endif
#define TEMP_2_PIN         -1
#define TEMP_BED_PIN        6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 34 bed)
#define SDPOWER            -1
#define SDSS               31

#define SLAVE_CLOCK    16

#endif


//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, HEATER_0_PIN,
#ifdef REPRAPPRO_MULTIMATERIALS
  #define _E1_PINS -1, -1, -1, -1,
  #define _E2_PINS -1, -1, -1, -1,
#else 
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, LED_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN,                  \
                        _E0_PINS _E1_PINS _E2_PINS             \
                        TEMP_0_PIN, TEMP_1_PIN, TEMP_2_PIN, TEMP_BED_PIN }



/****************************************************************************************
 * Arduino Mega pin assignment
 *
 ****************************************************************************************/
#if MOTHERBOARD == 3 || MOTHERBOARD == 33 || MOTHERBOARD == 34
#define KNOWN_BOARD 1

//////////////////FIX THIS//////////////
#ifndef __AVR_ATmega1280__
#ifndef __AVR_ATmega2560__
#error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
#endif
#endif

// uncomment one of the following lines for RAMPS v1.3 or v1.0, comment both for v1.2 or 1.1
// #define RAMPS_V_1_3
// #define RAMPS_V_1_0

#if MOTHERBOARD == 33 || MOTHERBOARD == 34

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          -1 //Es el 15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          15 // es el 18
#define Z_MAX_PIN          -1 // es el 19

#define Z2_STEP_PIN        36
#define Z2_DIR_PIN         34
#define Z2_ENABLE_PIN      30

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#if MOTHERBOARD == 33
#define FAN_PIN            9 // (Sprinter config)
#else
#define FAN_PIN            4 // IO pin. Buffer needed
#endif
#define PS_ON_PIN          12

#if defined(REPRAP_DISCOUNT_SMART_CONTROLLER) || defined(G3D_PANEL)
#define KILL_PIN           41
#else
#define KILL_PIN           -1
#endif

#define HEATER_0_PIN       10   // EXTRUDER 1
#if MOTHERBOARD == 33
#define HEATER_1_PIN       -1
#else
#define HEATER_1_PIN       9    // EXTRUDER 2 (FAN On Sprinter)
#endif
#define HEATER_2_PIN       -1
#define TEMP_0_PIN         13   // ANALOG NUMBERING
#define TEMP_1_PIN         -1   // 15 ANALOG NUMBERING
#define TEMP_2_PIN         -1   // ANALOG NUMBERING
#define HEATER_BED_PIN     8    // BED
#define TEMP_BED_PIN       14   // ANALOG NUMBERING

#ifdef ULTRA_LCD

#ifdef NEWPANEL
//encoder rotation values
#define encrot0 0
#define encrot1 2
#define encrot2 3
#define encrot3 1

#define BLEN_A 0
#define BLEN_B 1
#define BLEN_C 2

#define LCD_PINS_RS 16
#define LCD_PINS_ENABLE 17
#define LCD_PINS_D4 23
#define LCD_PINS_D5 25
#define LCD_PINS_D6 27
#define LCD_PINS_D7 29

#ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
#define BEEPER 37

#define BTN_EN1 31
#define BTN_EN2 33
#define BTN_ENC 35

#define SDCARDDETECT 49
#else
//arduino pin which triggers an piezzo beeper
#define BEEPER 33	 // Beeper on AUX-4

//buttons are directly attached using AUX-2
#define BTN_EN1 37
#define BTN_EN2 35
#define BTN_ENC 31  //the click

#ifdef G3D_PANEL
#define SDCARDDETECT 49
#else
#define SDCARDDETECT -1  // Ramps does not use this port
#endif
#endif

#else //old style panel with shift register
//arduino pin witch triggers an piezzo beeper
#define BEEPER 33		No Beeper added

//buttons are attached to a shift register
// Not wired this yet
//#define SHIFT_CLK 38
//#define SHIFT_LD 42
//#define SHIFT_OUT 40
//#define SHIFT_EN 17

#define LCD_PINS_RS 16
#define LCD_PINS_ENABLE 17
#define LCD_PINS_D4 23
#define LCD_PINS_D5 25
#define LCD_PINS_D6 27
#define LCD_PINS_D7 29

//encoder rotation values
#define encrot0 0
#define encrot1 2
#define encrot2 3
#define encrot3 1


//bits in the shift register that carry the buttons for:
// left up center down right red
#define BL_LE 7
#define BL_UP 6
#define BL_MI 5
#define BL_DW 4
#define BL_RI 3
#define BL_ST 2

#define BLEN_B 1
#define BLEN_A 0
#endif
#endif //ULTRA_LCD

#else // RAMPS_V_1_1 or RAMPS_V_1_2 as default (MOTHERBOARD == 3)

#define X_STEP_PIN         26
#define X_DIR_PIN          28
#define X_ENABLE_PIN       24
#define X_MIN_PIN           3
#define X_MAX_PIN          -1    //2

#define Y_STEP_PIN         38
#define Y_DIR_PIN          40
#define Y_ENABLE_PIN       36
#define Y_MIN_PIN          16
#define Y_MAX_PIN          -1    //17

#define Z_STEP_PIN         44
#define Z_DIR_PIN          46
#define Z_ENABLE_PIN       42
#define Z_MIN_PIN          15
#define Z_MAX_PIN          -1    //19

#define E0_STEP_PIN         32
#define E0_DIR_PIN          34
#define E0_ENABLE_PIN       30

#define SDPOWER            48
#define SDSS               53
#define LED_PIN            13
#define PS_ON_PIN          -1
#define KILL_PIN           -1

#ifdef RAMPS_V_1_0 // RAMPS_V_1_0
#define HEATER_0_PIN     12    // RAMPS 1.0
#define HEATER_BED_PIN   -1    // RAMPS 1.0
#define FAN_PIN          11    // RAMPS 1.0
#else // RAMPS_V_1_1 or RAMPS_V_1_2
#define HEATER_0_PIN     10    // RAMPS 1.1
#define HEATER_BED_PIN    8    // RAMPS 1.1
#define FAN_PIN           9    // RAMPS 1.1
#endif
#define HEATER_1_PIN        -1
#define HEATER_2_PIN        -1
#define TEMP_0_PIN          2    // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#define TEMP_1_PIN          -1
#define TEMP_2_PIN          -1
#define TEMP_BED_PIN        1    // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#endif// MOTHERBOARD == 33 || MOTHERBOARD == 34

// SPI for Max6675 Thermocouple

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
#define MAX_SCK_PIN          52
#define MAX_MISO_PIN         50
#define MAX_MOSI_PIN         51
#define MAX6675_SS       53
#else
#define MAX6675_SS       49
#endif

#endif//MOTHERBOARD == 3 || MOTHERBOARD == 33 || MOTHERBOARD == 34

/****************************************************************************************
 * Arduino Mega pin assignment
 *
 ****************************************************************************************/
#if MOTHERBOARD == 3 || MOTHERBOARD == 33 || MOTHERBOARD == 34
#define KNOWN_BOARD 1

//////////////////FIX THIS//////////////
#ifndef __AVR_ATmega1280__
#ifndef __AVR_ATmega2560__
#error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
#endif
#endif

// uncomment one of the following lines for RAMPS v1.3 or v1.0, comment both for v1.2 or 1.1
// #define RAMPS_V_1_3
// #define RAMPS_V_1_0

#if MOTHERBOARD == 33 || MOTHERBOARD == 34

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          -1 // 15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          15 // 18
#define Z_MAX_PIN          -1 // 19

#define Z2_STEP_PIN        36
#define Z2_DIR_PIN         34
#define Z2_ENABLE_PIN      30

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#if MOTHERBOARD == 33
#define FAN_PIN            9 // (Sprinter config)
#else
#define FAN_PIN            4 // IO pin. Buffer needed
#endif
#define PS_ON_PIN          12

#if defined(REPRAP_DISCOUNT_SMART_CONTROLLER) || defined(G3D_PANEL)
#define KILL_PIN           41
#else
#define KILL_PIN           -1
#endif

#define HEATER_0_PIN       10   // EXTRUDER 1
#if MOTHERBOARD == 33
#define HEATER_1_PIN       -1
#else
#define HEATER_1_PIN       9    // EXTRUDER 2 (FAN On Sprinter)
#endif
#define HEATER_2_PIN       -1
#define TEMP_0_PIN         13   // ANALOG NUMBERING
#define TEMP_1_PIN         -1   // 15 ANALOG NUMBERING
#define TEMP_2_PIN         -1   // ANALOG NUMBERING
#define HEATER_BED_PIN     8    // BED
#define TEMP_BED_PIN       14   // ANALOG NUMBERING

#ifdef ULTRA_LCD

#ifdef NEWPANEL
//encoder rotation values
#define encrot0 0
#define encrot1 2
#define encrot2 3
#define encrot3 1

#define BLEN_A 0
#define BLEN_B 1
#define BLEN_C 2

#define LCD_PINS_RS 16
#define LCD_PINS_ENABLE 17
#define LCD_PINS_D4 23
#define LCD_PINS_D5 25
#define LCD_PINS_D6 27
#define LCD_PINS_D7 29

#ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
#define BEEPER 37

#define BTN_EN1 31
#define BTN_EN2 33
#define BTN_ENC 35

#define SDCARDDETECT 49
#else
//arduino pin which triggers an piezzo beeper
#define BEEPER 33	 // Beeper on AUX-4

//buttons are directly attached using AUX-2
#define BTN_EN1 37
#define BTN_EN2 35
#define BTN_ENC 31  //the click

#ifdef G3D_PANEL
#define SDCARDDETECT 49
#else
#define SDCARDDETECT -1  // Ramps does not use this port
#endif
#endif

#else //old style panel with shift register
//arduino pin witch triggers an piezzo beeper
#define BEEPER 33		No Beeper added

//buttons are attached to a shift register
// Not wired this yet
//#define SHIFT_CLK 38
//#define SHIFT_LD 42
//#define SHIFT_OUT 40
//#define SHIFT_EN 17

#define LCD_PINS_RS 16
#define LCD_PINS_ENABLE 17
#define LCD_PINS_D4 23
#define LCD_PINS_D5 25
#define LCD_PINS_D6 27
#define LCD_PINS_D7 29

//encoder rotation values
#define encrot0 0
#define encrot1 2
#define encrot2 3
#define encrot3 1


//bits in the shift register that carry the buttons for:
// left up center down right red
#define BL_LE 7
#define BL_UP 6
#define BL_MI 5
#define BL_DW 4
#define BL_RI 3
#define BL_ST 2

#define BLEN_B 1
#define BLEN_A 0
#endif
#endif //ULTRA_LCD

#else // RAMPS_V_1_1 or RAMPS_V_1_2 as default (MOTHERBOARD == 3)

#define X_STEP_PIN         26
#define X_DIR_PIN          28
#define X_ENABLE_PIN       24
#define X_MIN_PIN           3
#define X_MAX_PIN          -1    //2

#define Y_STEP_PIN         38
#define Y_DIR_PIN          40
#define Y_ENABLE_PIN       36
#define Y_MIN_PIN          16
#define Y_MAX_PIN          -1    //17

#define Z_STEP_PIN         44
#define Z_DIR_PIN          46
#define Z_ENABLE_PIN       42
#define Z_MIN_PIN          15 //18
#define Z_MAX_PIN          -1    //19

#define E0_STEP_PIN         32
#define E0_DIR_PIN          34
#define E0_ENABLE_PIN       30

#define SDPOWER            48
#define SDSS               53
#define LED_PIN            13
#define PS_ON_PIN          -1
#define KILL_PIN           -1

#ifdef RAMPS_V_1_0 // RAMPS_V_1_0
#define HEATER_0_PIN     12    // RAMPS 1.0
#define HEATER_BED_PIN   -1    // RAMPS 1.0
#define FAN_PIN          11    // RAMPS 1.0
#else // RAMPS_V_1_1 or RAMPS_V_1_2
#define HEATER_0_PIN     10    // RAMPS 1.1
#define HEATER_BED_PIN    8    // RAMPS 1.1
#define FAN_PIN           9    // RAMPS 1.1
#endif
#define HEATER_1_PIN        -1
#define HEATER_2_PIN        -1
#define TEMP_0_PIN          2    // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#define TEMP_1_PIN          -1
#define TEMP_2_PIN          -1
#define TEMP_BED_PIN        1    // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#endif// MOTHERBOARD == 33 || MOTHERBOARD == 34

// SPI for Max6675 Thermocouple

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
#define MAX_SCK_PIN          52
#define MAX_MISO_PIN         50
#define MAX_MOSI_PIN         51
#define MAX6675_SS       53
#else
#define MAX6675_SS       49
#endif

#endif//MOTHERBOARD == 3 || MOTHERBOARD == 33 || MOTHERBOARD == 34
#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

#endif
