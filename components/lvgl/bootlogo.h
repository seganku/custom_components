// Images can be converted to XBM format by using the online converter here:
// https://www.online-utility.org/image/convert/to/XBM

// The output must be pasted in a header file, renamed and adjusted to appear
// as as a const unsigned char array in PROGMEM (FLASH program memory).

// The xbm format adds padding to pixel rows so they are a whole number of bytes
// In this example 50 pixel width means 56 bits = 7 bytes
// the 50 height then means array uses 50 x 7 = 350 bytes of FLASH
// The library ignores the padding bits when drawing the image on the display.

// The openHASP logo uses the MaterialDesign icons font, released under the OFL license

#pragma once

#define logoBgColor {0,128,128}
#define logoFgColor {255,255,255}

#define logoWidth 200
#define logoHeight 29

// Image is stored in th array below, adjust the width and height accordingly
PROGMEM const unsigned char logoImage[] = {
  0x00, 0xBC, 0x73, 0xEE, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xA4, 0x54, 0x29, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xA4, 0x54, 0x29, 0x15, 0x00, 0xFE, 0xFF, 0x03, 0x7C, 
  0x00, 0xFF, 0x03, 0xF8, 0x03, 0xF0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x3F, 0x00, 0xFE, 0xFF, 0x03, 
  0xFF, 0x01, 0xFF, 0x1F, 0xF8, 0x03, 0xF0, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x60, 0x00, 0xFE, 0xFF, 
  0xC3, 0xFF, 0x07, 0xFF, 0x7F, 0xF8, 0x03, 0xF0, 0x07, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x40, 0x00, 0x38, 
  0x80, 0xC3, 0x83, 0x07, 0x1C, 0xF8, 0xE0, 0x00, 0xC0, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x40, 0x00, 
  0x38, 0x80, 0xE3, 0x01, 0x1F, 0x1C, 0xE0, 0xE0, 0x00, 0xC0, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x40, 
  0x00, 0x38, 0x80, 0xE3, 0x00, 0x1E, 0x1C, 0xE0, 0xE0, 0x00, 0xC0, 0x01, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 
  0x40, 0x00, 0x38, 0x80, 0xE3, 0x00, 0x1E, 0x1C, 0xE0, 0xE0, 0x00, 0xC0, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x80, 
  0x01, 0x40, 0x00, 0x38, 0x00, 0xE0, 0x00, 0x00, 0x1C, 0xE0, 0xE0, 0x00, 
  0xC0, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
  0xC0, 0x03, 0x40, 0x00, 0x38, 0x00, 0xE0, 0x01, 0x00, 0x1C, 0xE0, 0xE0, 
  0x00, 0xC0, 0x01, 0xF8, 0x07, 0x7C, 0x7E, 0xF0, 0x03, 0xE0, 0x1F, 0xFF, 
  0x02, 0xE0, 0x1F, 0x40, 0x00, 0x38, 0x00, 0xC0, 0x03, 0x00, 0x1C, 0xF0, 
  0xE0, 0x00, 0xC0, 0x01, 0xFC, 0x0F, 0xFC, 0xFF, 0xFC, 0x07, 0xF0, 0x3F, 
  0x80, 0x02, 0xF0, 0x1F, 0x40, 0x00, 0xF8, 0x1F, 0xC0, 0x1F, 0x00, 0x1C, 
  0x7C, 0xE0, 0xFF, 0xFF, 0x01, 0x1E, 0x1E, 0xFC, 0xE1, 0x8F, 0x0F, 0x38, 
  0x78, 0xFF, 0x02, 0xF8, 0x1F, 0x40, 0x00, 0xF8, 0x1F, 0x80, 0xFF, 0x00, 
  0xFC, 0x3F, 0xE0, 0xFF, 0xFF, 0x01, 0x07, 0x38, 0xF0, 0xC0, 0x03, 0x0E, 
  0x1C, 0x70, 0x01, 0x02, 0xFC, 0x3F, 0x40, 0x00, 0xF8, 0x1F, 0x00, 0xFE, 
  0x03, 0xFC, 0x0F, 0xE0, 0xFF, 0xFF, 0x01, 0x07, 0x38, 0x70, 0x80, 0x03, 
  0x0E, 0x1C, 0x70, 0xFF, 0x02, 0xFC, 0x3F, 0x40, 0x00, 0x38, 0x00, 0x00, 
  0xF0, 0x07, 0x1C, 0x00, 0xE0, 0x00, 0xC0, 0x81, 0x03, 0x70, 0x70, 0x80, 
  0x03, 0x0E, 0x0E, 0xE0, 0x80, 0x02, 0xF8, 0x1F, 0x40, 0x00, 0x38, 0x00, 
  0x00, 0x80, 0x0F, 0x1C, 0x00, 0xE0, 0x00, 0xC0, 0x81, 0x03, 0x70, 0x70, 
  0x80, 0x03, 0x0E, 0xFE, 0xFF, 0xFF, 0x02, 0xF8, 0x1F, 0x40, 0x00, 0x38, 
  0x00, 0x00, 0x00, 0x0F, 0x1C, 0x00, 0xE0, 0x00, 0xC0, 0x81, 0x03, 0x70, 
  0x70, 0x80, 0x03, 0x0E, 0xFE, 0xFF, 0x01, 0x02, 0xF8, 0x1F, 0x40, 0x00, 
  0x38, 0x00, 0x00, 0x00, 0x1E, 0x1C, 0x00, 0xE0, 0x00, 0xC0, 0x81, 0x03, 
  0x70, 0x70, 0x80, 0x03, 0x0E, 0x0E, 0x00, 0xFF, 0x02, 0xF8, 0x1F, 0x40, 
  0x00, 0x38, 0x00, 0xF0, 0x00, 0x1E, 0x1C, 0x00, 0xE0, 0x00, 0xC0, 0x81, 
  0x03, 0x70, 0x70, 0x80, 0x03, 0x0E, 0x0E, 0x00, 0x80, 0x02, 0x00, 0x00, 
  0x40, 0x00, 0x38, 0x80, 0xF3, 0x00, 0x1E, 0x1C, 0x00, 0xE0, 0x00, 0xC0, 
  0x81, 0x03, 0x30, 0x70, 0x80, 0x03, 0x0E, 0x1C, 0x00, 0xFF, 0x02, 0x00, 
  0x00, 0x40, 0x00, 0x38, 0x80, 0xF3, 0x00, 0x0E, 0x1C, 0x00, 0xE0, 0x00, 
  0xC0, 0x01, 0x07, 0x38, 0x70, 0x80, 0x03, 0x0E, 0x1C, 0x00, 0x01, 0x02, 
  0x00, 0x00, 0x40, 0x00, 0x38, 0x80, 0xC3, 0x01, 0x0F, 0x1C, 0x00, 0xE0, 
  0x00, 0xC0, 0x01, 0x07, 0x3C, 0x70, 0x80, 0x03, 0x0E, 0x3C, 0x00, 0xFF, 
  0x03, 0x00, 0x00, 0x40, 0x00, 0xFE, 0xFF, 0xC3, 0xC7, 0x07, 0x7F, 0x00, 
  0xF8, 0x03, 0xF0, 0x07, 0x1E, 0x1E, 0xFC, 0xE1, 0x87, 0x3F, 0x78, 0x70, 
  0x00, 0x06, 0x00, 0x00, 0x60, 0x00, 0xFE, 0xFF, 0x83, 0xFF, 0x07, 0x7F, 
  0x00, 0xF8, 0x03, 0xF0, 0x07, 0xFE, 0x0F, 0xFC, 0xF1, 0x8F, 0x3F, 0xF0, 
  0x7F, 0x00, 0xFE, 0xFF, 0xFF, 0x3F, 0x00, 0xFE, 0xFF, 0x03, 0xFF, 0x01, 
  0x7F, 0x00, 0xF8, 0x03, 0xF0, 0x07, 0xF8, 0x07, 0xFC, 0xF1, 0x8F, 0x3F, 
  0xE0, 0x1F, 0x00, 0xA4, 0x54, 0x29, 0x15, 0x00, 0x00, 0x00, 0x00, 0x38, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0x00, 0xA4, 0x54, 0x29, 0x15, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xBC, 0x73, 0xEE, 0x1D, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, };