// Target definition
#define RG_TARGET_NAME             "RETRO-ESP32"

// Storage
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDSPI_HOST       SPI2_HOST
#define RG_STORAGE_SDSPI_SPEED      SDMMC_FREQ_DEFAULT

// Audio - using internal DAC
#define RG_AUDIO_USE_INT_DAC        1   // GPIO25
#define RG_AUDIO_USE_EXT_DAC        0

// Video
#define RG_SCREEN_DRIVER            0   // 0 = ILI9341/ST7789
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_BACKLIGHT         1
#define RG_SCREEN_WIDTH             240
#define RG_SCREEN_HEIGHT            320
#define RG_SCREEN_ROTATE            0
#define RG_SCREEN_VISIBLE_AREA      {0, 0, 0, 0}
#define RG_SCREEN_SAFE_AREA         {0, 0, 0, 0}
#define RG_SCREEN_INIT()                                                        \
    ILI9341_CMD(0x01);                  /* Software Reset */                    \
    vTaskDelay(pdMS_TO_TICKS(120));                                             \
    ILI9341_CMD(0x11);                  /* Sleep Out */                         \
    vTaskDelay(pdMS_TO_TICKS(120));                                             \
    ILI9341_CMD(0x36, 0x00);            /* Memory Access Control */             \
    ILI9341_CMD(0x3A, 0x55);            /* Pixel Format: 16bit RGB565 */        \
    ILI9341_CMD(0xB2, 0x0C, 0x0C, 0x00, 0x33, 0x33); /* Porch Setting */       \
    ILI9341_CMD(0xB7, 0x35);            /* Gate Control */                      \
    ILI9341_CMD(0xBB, 0x19);            /* VCOM Setting */                      \
    ILI9341_CMD(0xC0, 0x2C);            /* LCM Control */                       \
    ILI9341_CMD(0xC2, 0x01);            /* VDV and VRH Command Enable */        \
    ILI9341_CMD(0xC3, 0x12);            /* VRH Set */                           \
    ILI9341_CMD(0xC4, 0x20);            /* VDV Set */                           \
    ILI9341_CMD(0xC6, 0x0F);            /* Frame Rate Control: 60Hz */          \
    ILI9341_CMD(0xD0, 0xA4, 0xA1);      /* Power Control 1 */                   \
    ILI9341_CMD(0xE0, 0xD0, 0x04, 0x0D, 0x11, 0x13, 0x2B, 0x3F, 0x54, 0x4C, 0x18, 0x0D, 0x0B, 0x1F, 0x23); \
    ILI9341_CMD(0xE1, 0xD0, 0x04, 0x0C, 0x11, 0x13, 0x2C, 0x3F, 0x44, 0x51, 0x2F, 0x1F, 0x1F, 0x20, 0x23); \
    ILI9341_CMD(0x21);                  /* Display Inversion On */              \
    ILI9341_CMD(0x29);                  /* Display On */                        \
    vTaskDelay(pdMS_TO_TICKS(10));

// Input - Simple GPIO buttons, active LOW (button connects GPIO to GND)
// GPIO 34 and 35 have NO internal pullup - add 10k resistor from pin to 3.3V!
#define RG_GAMEPAD_GPIO_MAP {\
    {RG_KEY_UP,     .num = GPIO_NUM_35, .pullup = 0, .level = 0},\
    {RG_KEY_DOWN,   .num = GPIO_NUM_27, .pullup = 1, .level = 0},\
    {RG_KEY_LEFT,   .num = GPIO_NUM_13, .pullup = 1, .level = 0},\
    {RG_KEY_RIGHT,  .num = GPIO_NUM_12, .pullup = 1, .level = 0},\
    {RG_KEY_SELECT, .num = GPIO_NUM_25, .pullup = 1, .level = 0},\
    {RG_KEY_START,  .num = GPIO_NUM_26, .pullup = 1, .level = 0},\
    {RG_KEY_A,      .num = GPIO_NUM_32, .pullup = 1, .level = 0},\
    {RG_KEY_B,      .num = GPIO_NUM_33, .pullup = 1, .level = 0},\
    {RG_KEY_MENU,   .num = GPIO_NUM_34, .pullup = 0, .level = 0},\
}

// Battery - disabled
#define RG_BATTERY_DRIVER           0

// SPI Display
#define RG_GPIO_LCD_MISO            GPIO_NUM_19
#define RG_GPIO_LCD_MOSI            GPIO_NUM_23
#define RG_GPIO_LCD_CLK             GPIO_NUM_18
#define RG_GPIO_LCD_CS              GPIO_NUM_5
#define RG_GPIO_LCD_DC              GPIO_NUM_2
#define RG_GPIO_LCD_BCKL            GPIO_NUM_15
#define RG_GPIO_LCD_RST             GPIO_NUM_4

// SPI SD Card
#define RG_GPIO_SDSPI_MISO          GPIO_NUM_19
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_23
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_18
#define RG_GPIO_SDSPI_CS            GPIO_NUM_22
