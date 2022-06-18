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

  ST7796_PWCTR1  , 1, 0x23,             // Power control VRH[5:0]
  ST7796_PWCTR2  , 1, 0x10,             // Power control SAP[2:0];BT[3:0]
  ST7796_VMCTR1  , 2, 0x3e, 0x28,       // VCM control
  ST7796_VMCTR2  , 1, 0x86,             // VCM control2
  ST7796_MADCTL  , 1, 0x48,             // Memory Access Control
  ST7796_VSCRSADD, 1, 0x00,             // Vertical scroll zero
  ST7796_PIXFMT  , 1, 0x55,
  ST7796_FRMCTR1 , 2, 0x00, 0x18,
  ST7796_DFUNCTR , 3, 0x08, 0x82, 0x27, // Display Function Control
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

// clang-format on
}  // namespace st7796
}  // namespace esphome
