/****************************************************************************************
* 37
* RAMPS 1.3 / 1.4
* RAMPS_13_HHH (Hotend0, Hotend1, Hotend2)
****************************************************************************************/

#define KNOWN_BOARD
#define BOARD_NAME "RAMPS 1.4"

#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
  #error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
#endif

#define LARGE_FLASH true

// X axis pins
#define ORIG_X_STEP_PIN         54
#define ORIG_X_DIR_PIN          55
#define ORIG_X_ENABLE_PIN       38
#define ORIG_X_MIN_PIN          3
#define ORIG_X_MAX_PIN          2

// Y axis pins
#define ORIG_Y_STEP_PIN         60
#define ORIG_Y_DIR_PIN          61
#define ORIG_Y_ENABLE_PIN       56
#define ORIG_Y_MIN_PIN          14
#define ORIG_Y_MAX_PIN          15

#define Y2_STEP_PIN             36
#define Y2_DIR_PIN              34
#define Y2_ENABLE_PIN           30

// Z axis pins
#define ORIG_Z_STEP_PIN         46
#define ORIG_Z_DIR_PIN          48
#define ORIG_Z_ENABLE_PIN       62
#define ORIG_Z_MIN_PIN          18
#define ORIG_Z_MAX_PIN          19

#define Z2_STEP_PIN             36
#define Z2_DIR_PIN              34
#define Z2_ENABLE_PIN           30

// E axis pins
#define ORIG_E0_STEP_PIN        26
#define ORIG_E0_DIR_PIN         28
#define ORIG_E0_ENABLE_PIN      24

#define ORIG_E1_STEP_PIN        36
#define ORIG_E1_DIR_PIN         34
#define ORIG_E1_ENABLE_PIN      30

#define SDPOWER                 -1
#define SDSS                    53
#define LED_PIN                 13

#define ORIG_FAN_PIN            8
#define ORIG_PS_ON_PIN          12

#define ORIG_HEATER_0_PIN       10  // HOTEND 1
#define ORIG_HEATER_1_PIN       9   // HOTEND 2
#define ORIG_HEATER_2_PIN       8   // HOTEND 3
#define ORIG_HEATER_3_PIN       -1

#define ORIG_TEMP_0_PIN         13  // ANALOG NUMBERING
#define ORIG_TEMP_1_PIN         15  // ANALOG NUMBERING
#define ORIG_TEMP_2_PIN         14  // ANALOG NUMBERING
#define ORIG_TEMP_3_PIN         -1  // ANALOG NUMBERING

#define ORIG_HEATER_BED_PIN     -1  // BED
#define ORIG_TEMP_BED_PIN       -1  // ANALOG NUMBERING

#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER) || ENABLED(G3D_PANEL)
  #define KILL_PIN              41
#else
  #define KILL_PIN              -1
#endif

#if NUM_SERVOS > 0
  #define SERVO0_PIN            11
  #if NUM_SERVOS > 1
    #define SERVO1_PIN          6
    #if NUM_SERVOS > 2
      #define SERVO2_PIN        5
      #if NUM_SERVOS > 3
        #define SERVO3_PIN      4
      #endif
    #endif
  #endif
#endif

#if ENABLED(ULTRA_LCD)

  #if ENABLED(REPRAPWORLD_GRAPHICAL_LCD)
    #define LCD_PINS_RS       49 //CS chip select /SS chip slave select
    #define LCD_PINS_ENABLE   51 //SID (MOSI)
    #define LCD_PINS_D4       52 //SCK (CLK) clock
  #elif ENABLED(NEWPANEL) && ENABLED(PANEL_ONE)
    #define LCD_PINS_RS       40
    #define LCD_PINS_ENABLE   42
    #define LCD_PINS_D4       65
    #define LCD_PINS_D5       66
    #define LCD_PINS_D6       44
    #define LCD_PINS_D7       64
  #else
    #define LCD_PINS_RS       16
    #define LCD_PINS_ENABLE   17
    #define LCD_PINS_D4       23
    #define LCD_PINS_D5       25
    #define LCD_PINS_D6       27
    #define LCD_PINS_D7       29
    #if DISABLED(NEWPANEL)
      #define ORIG_BEEPER_PIN 33
      // Buttons are attached to a shift register
      // Not wired yet
      //#define SHIFT_CLK 38
      //#define SHIFT_LD 42
      //#define SHIFT_OUT 40
      //#define SHIFT_EN 17
    #endif
  #endif

  #if ENABLED(NEWPANEL)

    #if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
      #define ORIG_BEEPER_PIN   37

      #define BTN_EN1           31
      #define BTN_EN2           33
      #define BTN_ENC           35

      #define SD_DETECT_PIN     49
      #define KILL_PIN          41

      #if ENABLED(BQ_LCD_SMART_CONTROLLER)
        #define LCD_PIN_BL      39
      #endif

    #elif ENABLED(REPRAPWORLD_GRAPHICAL_LCD)
      #define BTN_EN1           64
      #define BTN_EN2           59
      #define BTN_ENC           63
      #define SD_DETECT_PIN     42
    #elif ENABLED(LCD_I2C_PANELOLU2)
      #define BTN_EN1           47  // reverse if the encoder turns the wrong way.
      #define BTN_EN2           43
      #define BTN_ENC           32
      #define LCD_SDSS          53
      #define SD_DETECT_PIN     -1
      #define KILL_PIN          41
    #elif ENABLED(LCD_I2C_VIKI)
      #define BTN_EN1           22  // reverse if the encoder turns the wrong way.
      #define BTN_EN2            7
      #define BTN_ENC           -1
      #define LCD_SDSS          53
      #define SD_DETECT_PIN     49
    #elif ENABLED(VIKI2) || ENABLED(miniVIKI)
      #define BEEPER_PIN        33

      // Pins for DOGM SPI LCD Support
      #define DOGLCD_A0         44
      #define DOGLCD_CS         45
      #define LCD_SCREEN_ROT_180

      #define BTN_EN1           22
      #define BTN_EN2            7
      #define BTN_ENC           39

      #define SDSS              53
      #define SD_DETECT_PIN     -1  // Pin 49 for display sd interface, 72 for easy adapter board

      #define KILL_PIN          31

      #if ENABLED(TEMP_STAT_LEDS)
        #define STAT_LED_RED    32
        #define STAT_LED_BLUE   35
      #endif
    #elif ENABLED(ELB_FULL_GRAPHIC_CONTROLLER)
      #define BTN_EN1           35  // reverse if the encoder turns the wrong way.
      #define BTN_EN2           37
      #define BTN_ENC           31
      #define SD_DETECT_PIN     49
      #define LCD_SDSS          53
      #define KILL_PIN          41
      #define ORIG_BEEPER_PIN   23
      #define DOGLCD_CS         29
      #define DOGLCD_A0         27
      #define LCD_PIN_BL        33
    #elif ENABLED(MINIPANEL)
      #define BEEPER_PIN        42
      // Pins for DOGM SPI LCD Support
      #define DOGLCD_A0         44
      #define DOGLCD_CS         66
      #define LCD_PIN_BL        65 // backlight LED on A11/D65
      #define SDSS              53

      #define KILL_PIN          64
      // GLCD features
      //#define LCD_CONTRAST 190
      // Uncomment screen orientation
      //#define LCD_SCREEN_ROT_90
      //#define LCD_SCREEN_ROT_180
      //#define LCD_SCREEN_ROT_270
      //The encoder and click button
      #define BTN_EN1           40
      #define BTN_EN2           63
      #define BTN_ENC           59
      //not connected to a pin
      #define SD_DETECT_PIN     49

    #else

      // arduino pin which triggers an piezzo beeper
      #define ORIG_BEEPER_PIN   33  // Beeper on AUX-4

      // buttons are directly attached using AUX-2
      #if ENABLED(REPRAPWORLD_KEYPAD)
        #define BTN_EN1         64  // encoder
        #define BTN_EN2         59  // encoder
        #define BTN_ENC         63  // enter button
        #define SHIFT_OUT       40  // shift register
        #define SHIFT_CLK       44  // shift register
        #define SHIFT_LD        42  // shift register
      #elif ENABLED(PANEL_ONE)
        #define BTN_EN1         59  // AUX2 PIN 3
        #define BTN_EN2         63  // AUX2 PIN 4
        #define BTN_ENC         49  // AUX3 PIN 7
      #else
        #define BTN_EN1         37
        #define BTN_EN2         35
        #define BTN_ENC         31  // the click
      #endif

      #if ENABLED(G3D_PANEL)
        #define SD_DETECT_PIN   49
        #define KILL_PIN        41
      #else
        #define SD_DETECT_PIN   -1  // Ramps does not use this port
      #endif

    #endif
  #endif // NEWPANEL

#endif // ULTRA_LCD

// SPI for Max6675 or Max31855 Thermocouple
#if DISABLED(SDSUPPORT)
  #define MAX6675_SS            66 // Do not use pin 53 if there is even the remote possibility of using Display/SD card
#else
  #define MAX6675_SS            66 // Do not use pin 49 as this is tied to the switch inside the SD card socket to detect if there is an SD card present
#endif
