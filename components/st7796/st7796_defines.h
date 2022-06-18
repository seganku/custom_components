#pragma once

namespace esphome {
namespace st7796 {

// Color definitions
// clang-format off
static const uint8_t MADCTL_MY    = 0x80;   ///< Bit 7 Bottom to top
static const uint8_t MADCTL_MX    = 0x40;   ///< Bit 6 Right to left
static const uint8_t MADCTL_MV    = 0x20;   ///< Bit 5 Reverse Mode
static const uint8_t MADCTL_ML    = 0x10;   ///< Bit 4 LCD refresh Bottom to top
static const uint8_t MADCTL_RGB   = 0x00;  ///< Bit 3 Red-Green-Blue pixel order
static const uint8_t MADCTL_BGR   = 0x08;  ///< Bit 3 Blue-Green-Red pixel order
static const uint8_t MADCTL_MH    = 0x04;   ///< Bit 2 LCD refresh right to left
// clang-format on

static const uint16_t ST7796_TFTWIDTH = 480;   ///< ST7796 max TFT width
static const uint16_t ST7796_TFTHEIGHT = 320;  ///< ST7796 max TFT height

// All ST7796 specific commands some are used by init()
static const uint8_t ST7796_NOP = 0x00;
static const uint8_t ST7796_SWRESET = 0x01;
static const uint8_t ST7796_RDDID = 0x04;
static const uint8_t ST7796_RDDST = 0x09;

static const uint8_t ST7796_SLPIN = 0x10;
static const uint8_t ST7796_SLPOUT = 0x11;
static const uint8_t ST7796_PTLON = 0x12;
static const uint8_t ST7796_NORON = 0x13;

static const uint8_t ST7796_RDMODE = 0x0A;
static const uint8_t ST7796_RDMADCTL = 0x0B;
static const uint8_t ST7796_RDPIXFMT = 0x0C;
static const uint8_t ST7796_RDIMGFMT = 0x0A;
static const uint8_t ST7796_RDSELFDIAG = 0x0F;

static const uint8_t ST7796_INVOFF = 0x20;
static const uint8_t ST7796_INVON = 0x21;
static const uint8_t ST7796_GAMMASET = 0x26;
static const uint8_t ST7796_DISPOFF = 0x28;
static const uint8_t ST7796_DISPON = 0x29;

static const uint8_t ST7796_CASET = 0x2A;
static const uint8_t ST7796_PASET = 0x2B;
static const uint8_t ST7796_RAMWR = 0x2C;
static const uint8_t ST7796_RAMRD = 0x2E;

static const uint8_t ST7796_PTLAR = 0x30;
static const uint8_t ST7796_VSCRDEF = 0x33;
static const uint8_t ST7796_MADCTL = 0x36;
static const uint8_t ST7796_VSCRSADD = 0x37;
static const uint8_t ST7796_PIXFMT = 0x3A;

static const uint8_t ST7796_WRDISBV = 0x51;
static const uint8_t ST7796_RDDISBV = 0x52;
static const uint8_t ST7796_WRCTRLD = 0x53;

static const uint8_t ST7796_FRMCTR1 = 0xB1;
static const uint8_t ST7796_FRMCTR2 = 0xB2;
static const uint8_t ST7796_FRMCTR3 = 0xB3;
static const uint8_t ST7796_INVCTR = 0xB4;
static const uint8_t ST7796_DFUNCTR = 0xB6;

static const uint8_t ST7796_PWCTR1 = 0xC0;
static const uint8_t ST7796_PWCTR2 = 0xC1;
static const uint8_t ST7796_PWCTR3 = 0xC2;
static const uint8_t ST7796_PWCTR4 = 0xC3;
static const uint8_t ST7796_PWCTR5 = 0xC4;
static const uint8_t ST7796_VMCTR1 = 0xC5;
static const uint8_t ST7796_VMCTR2 = 0xC7;

static const uint8_t ST7796_RDID4 = 0xD3;
static const uint8_t ST7796_RDINDEX = 0xD9;
static const uint8_t ST7796_RDID1 = 0xDA;
static const uint8_t ST7796_RDID2 = 0xDB;
static const uint8_t ST7796_RDID3 = 0xDC;
static const uint8_t ST7796_RDIDX = 0xDD;  // TBC

static const uint8_t ST7796_GMCTRP1 = 0xE0;
static const uint8_t ST7796_GMCTRN1 = 0xE1;

}  // namespace st7796
}  // namespace esphome
