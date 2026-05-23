// Target definition
#define RG_TARGET_NAME              "PILOT-S3-HANDHELD"

// Storage — SD_MMC
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDMMC_HOST       SDMMC_HOST_SLOT_1
#define RG_STORAGE_SDMMC_SPEED      SDMMC_FREQ_DEFAULT

// SD MMC pins
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_39
#define RG_GPIO_SDSPI_CMD           GPIO_NUM_38
#define RG_GPIO_SDSPI_D0            GPIO_NUM_40

// Audio — I2S external DAC (PCM5102A)
#define RG_AUDIO_USE_INT_DAC        0
#define RG_AUDIO_USE_EXT_DAC        1

// Video
#define RG_SCREEN_DRIVER            0
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_80M
#define RG_SCREEN_BACKLIGHT         1
#define RG_SCREEN_WIDTH             320
#define RG_SCREEN_HEIGHT            240
#define RG_SCREEN_ROTATE            0
#define RG_SCREEN_VISIBLE_AREA      {0, 0, 0, 0}
#define RG_SCREEN_SAFE_AREA         {0, 0, 0, 0}

// ST7789 init sequence
#define RG_SCREEN_INIT()                                                        \
    ILI9341_CMD(0x36, 0x70);            /* MADCTL: MX|MY|MV for landscape */   \
    ILI9341_CMD(0x3A, 0x55);            /* COLMOD: 16-bit color */             \
    ILI9341_CMD(0xB2, 0x0C, 0x0C, 0x00, 0x33, 0x33); /* Porch setting */      \
    ILI9341_CMD(0xB7, 0x35);            /* Gate control */                     \
    ILI9341_CMD(0xBB, 0x19);            /* VCOMS */                            \
    ILI9341_CMD(0xC0, 0x2C);            /* LCM control */                      \
    ILI9341_CMD(0xC2, 0x01);            /* VDV/VRH enable */                   \
    ILI9341_CMD(0xC3, 0x12);            /* VRH set */                          \
    ILI9341_CMD(0xC4, 0x20);            /* VDV set */                          \
    ILI9341_CMD(0xC6, 0x0F);            /* FR control 2: 60Hz */               \
    ILI9341_CMD(0xD0, 0xA4, 0xA1);     /* Power control 1 */                  \
    ILI9341_CMD(0xE0, 0xD0, 0x04, 0x0D, 0x11, 0x13, 0x2B, 0x3F, 0x54, 0x4C, 0x18, 0x0D, 0x0B, 0x1F, 0x23); \
    ILI9341_CMD(0xE1, 0xD0, 0x04, 0x0C, 0x11, 0x13, 0x2C, 0x3F, 0x44, 0x51, 0x2F, 0x1F, 0x1F, 0x20, 0x23);

// GPIO — SPI display
#define RG_GPIO_LCD_MISO            GPIO_NUM_NC
#define RG_GPIO_LCD_MOSI            GPIO_NUM_11
#define RG_GPIO_LCD_CLK             GPIO_NUM_12
#define RG_GPIO_LCD_CS              GPIO_NUM_10
#define RG_GPIO_LCD_DC              GPIO_NUM_9
#define RG_GPIO_LCD_RST             GPIO_NUM_8
#define RG_GPIO_LCD_BCKL            GPIO_NUM_NC

// I2S DAC pins (PCM5102A)
#define RG_GPIO_SND_I2S_BCK         GPIO_NUM_41
#define RG_GPIO_SND_I2S_WS          GPIO_NUM_42
#define RG_GPIO_SND_I2S_DATA        GPIO_NUM_2

// Buttons
#define RG_GAMEPAD_ADC_MAP {}
#define RG_GAMEPAD_GPIO_MAP {                                                   \
    {RG_KEY_UP,     .num = GPIO_NUM_4,  .pullup = 1, .level = 0},              \
    {RG_KEY_DOWN,   .num = GPIO_NUM_5,  .pullup = 1, .level = 0},              \
    {RG_KEY_LEFT,   .num = GPIO_NUM_7,  .pullup = 1, .level = 0},              \
    {RG_KEY_RIGHT,  .num = GPIO_NUM_15, .pullup = 1, .level = 0},              \
    {RG_KEY_A,      .num = GPIO_NUM_16, .pullup = 1, .level = 0},              \
    {RG_KEY_B,      .num = GPIO_NUM_17, .pullup = 1, .level = 0},              \
    {RG_KEY_START,  .num = GPIO_NUM_18, .pullup = 1, .level = 0},              \
    {RG_KEY_SELECT, .num = GPIO_NUM_6,  .pullup = 1, .level = 0},              \
    {RG_KEY_MENU,   .num = GPIO_NUM_NC, .pullup = 1, .level = 0},              \
}
