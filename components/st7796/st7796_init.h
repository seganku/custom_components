#pragma once
#include "esphome/core/helpers.h"

namespace esphome {
namespace st7796 {

// clang-format off
static const uint8_t PROGMEM INITCMD_M5STACK[] = {
  0xEF, 3, 0x03, 0x80, 0x02,
  0xCF, 3, 0x00, 0xC1, 0x30,
  0xED, 4, 0x64, 0x03, 0x12, 0x81,
  0xE8, 3, 0x85, 0x00, 0x78,
  0xCB, 5, 0x39, 0x2C, 0x00, 0x34, 0x02,
  0xF7, 1, 0x20,
  0xEA, 2, 0x00, 0x00,
  ST7796_PWCTR1  , 1, 0x23,             // Power control VRH[5:0]
  ST7796_PWCTR2  , 1, 0x10,             // Power control SAP[2:0];BT[3:0]
  ST7796_VMCTR1  , 2, 0x3e, 0x28,       // VCM control
  ST7796_VMCTR2  , 1, 0x86,             // VCM control2
  ST7796_MADCTL  , 1, MADCTL_BGR,       // Memory Access Control
  ST7796_VSCRSADD, 1, 0x00,             // Vertical scroll zero
  ST7796_PIXFMT  , 1, 0x55,
  ST7796_FRMCTR1 , 2, 0x00, 0x13,
  ST7796_DFUNCTR , 3, 0x08, 0x82, 0x27, // Display Function Control
  0xF2, 1, 0x00,                         // 3Gamma Function Disable
  ST7796_GAMMASET , 1, 0x01,             // Gamma curve selected
  ST7796_GMCTRP1 , 15, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, // Set Gamma
                        0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03,
                        0x0E, 0x09, 0x00,
  ST7796_GMCTRN1 , 15, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, // Set Gamma
                        0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C,
                        0x31, 0x36, 0x0F,
  ST7796_SLPOUT  , 0x80,                // Exit Sleep
  ST7796_DISPON  , 0x80,                // Display on
  0x00                                   // End of list
};

static const uint8_t PROGMEM INITCMD_TFT[] = {
  0xEF, 3, 0x03, 0x80, 0x02,
  0xCF, 3, 0x00, 0xC1, 0x30,
  0xED, 4, 0x64, 0x03, 0x12, 0x81,
  0xE8, 3, 0x85, 0x00, 0x78,
  0xCB, 5, 0x39, 0x2C, 0x00, 0x34, 0x02,
  0xF7, 1, 0x20,
  0xEA, 2, 0x00, 0x00,
  ST7796_PWCTR1  , 1, 0x23,             // Power control VRH[5:0]
  ST7796_PWCTR2  , 1, 0x10,             // Power control SAP[2:0];BT[3:0]
  ST7796_VMCTR1  , 2, 0x3e, 0x28,       // VCM control
  ST7796_VMCTR2  , 1, 0x86,             // VCM control2
  ST7796_MADCTL  , 1, 0x48,             // Memory Access Control
  ST7796_VSCRSADD, 1, 0x00,             // Vertical scroll zero
  ST7796_PIXFMT  , 1, 0x55,
  ST7796_FRMCTR1 , 2, 0x00, 0x18,
  ST7796_DFUNCTR , 3, 0x08, 0x82, 0x27, // Display Function Control
  0xF2, 1, 0x00,                         // 3Gamma Function Disable
  ST7796_GAMMASET , 1, 0x01,             // Gamma curve selected
  ST7796_GMCTRP1 , 15, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, // Set Gamma
                        0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03,
                        0x0E, 0x09, 0x00,
  ST7796_GMCTRN1 , 15, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, // Set Gamma
                        0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C,
                        0x31, 0x36, 0x0F,
  ST7796_SLPOUT  , 0x80,                // Exit Sleep
  ST7796_DISPON  , 0x80,                // Display on
  0x00                                   // End of list
};
static const uint8_t PROGMEM INITCMD_test[] = {
 0xA7,true, 0xB0,true,
 0x80, 0xB1,true, 0x80,
 0x10, 0xB4,true, 0x00,
 0xB5,true, 0x02, 0x03,
 0x00, 0x04, 0xB6,true,
 0x00, 0x02, 0xB7,true,
 0xc6, 0xC2,true, 0xC5,true,
 0x24, 0xE0,true, 0xF0, 0x09,
 0x13, 0x12, 0x12, 0x2B, 0x3C,
 0x44, 0x4B, 0x1B, 0x18, 0x17,
 0x1D, 0x21, 0XE1,true, 0xF0,
 0x09, 0x13, 0x0C, 0x0D, 0x27,
 0x3B, 0x44, 0x4D, 0x0B, 0x17,
 0x17, 0x1D, 0x21, 0xE4,true,
 0x31, 0xE8,true, 0x40, 0x8A,
 0x00, 0x00, 0x29, 0x19, 0xA5,
 0x33, 0xF0,true, 0xC3,
 0xF0,true, 0x69, 0x3A,true,
 0x66, 0x36,true, 0x48, 0X13,true,
 0X11,true,
 0x00
  
};

// clang-format on
}  // namespace st7796
}  // namespace esphome