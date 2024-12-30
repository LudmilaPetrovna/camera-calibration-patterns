#define font_width 5
#define font_height 8
#define font_stride 10
unsigned char font_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xDE, 0x03, 0x3A, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x62, 0x8C, 
  0x63, 0xC8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x2D, 0x56, 0x5A, 0x2A, 0x28, 
  0x15, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x6A, 0x5E, 0x72, 0x28, 0x09, 0x00, 
  0x00, 0x00, 0x00, 0xC6, 0x62, 0x8C, 0x63, 0xC8, 0x14, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFE, 0x03, 0x7A, 0x0F, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x39, 0xE5, 0x1D, 0x00, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x83, 0x7D, 0x55, 0x03, 0x00, 0x80, 0x10, 0x02, 
  0x14, 0xF9, 0xC7, 0x11, 0x55, 0x0D, 0x00, 0x80, 0x30, 0x13, 0xA2, 0x73, 
  0xEF, 0x11, 0x55, 0x13, 0x00, 0x80, 0xFC, 0x1F, 0xFE, 0x27, 0xC7, 0x7D, 
  0x60, 0x0D, 0x00, 0xE0, 0x33, 0x13, 0x22, 0x00, 0x83, 0x39, 0x45, 0x11, 
  0x00, 0xC0, 0x11, 0xF2, 0x14, 0x00, 0x01, 0x11, 0x40, 0x0F, 0x00, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x40, 0x00, 0x20, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x40, 
  0x40, 0x28, 0xE5, 0x80, 0x20, 0x84, 0x00, 0x00, 0x00, 0x40, 0x40, 0x94, 
  0x37, 0x52, 0x11, 0x84, 0x24, 0x02, 0x00, 0x20, 0x40, 0x00, 0x85, 0x88, 
  0x00, 0x84, 0x18, 0x07, 0x1C, 0x20, 0x00, 0x80, 0x77, 0x44, 0x01, 0x84, 
  0x18, 0x42, 0x00, 0x10, 0x40, 0x00, 0x25, 0xD2, 0x02, 0x48, 0x24, 0x40, 
  0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x18, 
  0x93, 0x9E, 0x79, 0xC6, 0x00, 0x00, 0x00, 0x30, 0xC8, 0xA4, 0x94, 0x42, 
  0x40, 0x29, 0x01, 0x00, 0x00, 0x48, 0x8D, 0x20, 0x92, 0xCE, 0x21, 0x26, 
  0x11, 0x42, 0x1C, 0x41, 0x8B, 0x18, 0xB4, 0x50, 0x22, 0x49, 0x01, 0x20, 
  0x00, 0x32, 0x89, 0x84, 0x84, 0x52, 0x12, 0x09, 0x01, 0x42, 0x1C, 0x01, 
  0xC6, 0x3D, 0x83, 0x8C, 0x11, 0xC6, 0x10, 0x02, 0x00, 0x10, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x9D, 0x73, 0xDE, 0x3B, 0xC9, 
  0xB9, 0x14, 0x52, 0x3A, 0x29, 0xA5, 0x94, 0x42, 0x48, 0x89, 0xA0, 0x14, 
  0xDE, 0x4A, 0x29, 0x9D, 0x90, 0xCE, 0x09, 0x8F, 0xA0, 0x13, 0x5E, 0x4B, 
  0xED, 0xA5, 0x90, 0x42, 0x68, 0x89, 0xA0, 0x14, 0x5E, 0x4B, 0x21, 0xA5, 
  0x94, 0x42, 0x48, 0x89, 0xA4, 0x94, 0x52, 0x4A, 0x26, 0x3D, 0xF7, 0x5E, 
  0x70, 0xC9, 0xB9, 0xF4, 0x52, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xE7, 0x9C, 0xF3, 0x52, 0x4A, 0x29, 0xBD, 0x23, 0x38, 0x01, 
  0x29, 0xA5, 0x44, 0x52, 0x4A, 0x29, 0xA1, 0x20, 0xA0, 0x02, 0x29, 0x25, 
  0x41, 0x52, 0x7A, 0x26, 0x91, 0x40, 0x20, 0x00, 0x2F, 0x1D, 0x42, 0x52, 
  0x7A, 0xC9, 0x89, 0x40, 0x20, 0x00, 0xA1, 0xA4, 0x44, 0x92, 0x7A, 0x09, 
  0x85, 0x80, 0x20, 0x00, 0x41, 0x25, 0x47, 0x1C, 0x31, 0xC9, 0xBD, 0x83, 
  0x38, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x80, 
  0x01, 0x81, 0xA0, 0x20, 0x00, 0x00, 0xC4, 0x9D, 0xF7, 0x4E, 0x38, 0x01, 
  0x80, 0x24, 0xCE, 0x39, 0x3F, 0xA5, 0x90, 0xDE, 0x49, 0xC7, 0xA0, 0x23, 
  0x5E, 0x4A, 0x2E, 0xA5, 0x90, 0x42, 0x50, 0x89, 0xA0, 0xA4, 0x5E, 0x4A, 
  0xCA, 0x39, 0xE7, 0x5C, 0x40, 0xC9, 0xA5, 0xC4, 0x5E, 0x72, 0x00, 0x00, 
  0x00, 0x00, 0x70, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x40, 0x00, 0x88, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x42, 
  0x08, 0xAD, 0xE7, 0x38, 0x77, 0x52, 0x4A, 0x29, 0x3D, 0x41, 0x90, 0xEA, 
  0x29, 0x85, 0x21, 0x52, 0x7A, 0x26, 0x91, 0x41, 0x30, 0xA8, 0xCF, 0x05, 
  0x26, 0x92, 0x7A, 0xC9, 0x09, 0x41, 0x10, 0x88, 0x01, 0x85, 0xC3, 0x1C, 
  0x31, 0x09, 0x3D, 0x42, 0x08, 0x70, 0x01, 0x01, 0x00, 0x00, 0x00, 0xC0, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0xE7, 0x9C, 0x77, 0x5E, 0x3D, 0x69, 0x25, 0x96, 0xD2, 0x79, 
  0x29, 0xA4, 0x90, 0x42, 0x4D, 0x29, 0x25, 0xF5, 0x52, 0x4A, 0xE9, 0x9C, 
  0x90, 0x8E, 0x23, 0xAD, 0x9D, 0xF4, 0x5E, 0x4A, 0x2F, 0xA5, 0x90, 0x42, 
  0x45, 0xAD, 0xA5, 0xF4, 0x52, 0x4A, 0x29, 0xA5, 0x90, 0x42, 0x4D, 0x6B, 
  0xA5, 0x94, 0x52, 0x4A, 0xE9, 0xB9, 0xF0, 0x5F, 0x75, 0x29, 0xA5, 0x94, 
  0x92, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE7, 0xBC, 
  0xE4, 0x52, 0x4A, 0x31, 0x8E, 0x14, 0x4E, 0x72, 0x29, 0x91, 0x54, 0x53, 
  0x4A, 0xB5, 0x8A, 0x14, 0x52, 0x4D, 0x29, 0x90, 0x54, 0x4D, 0x4A, 0xB5, 
  0x9A, 0x75, 0xD8, 0x4D, 0x2F, 0x10, 0x57, 0x53, 0x72, 0xB5, 0xAA, 0x92, 
  0x50, 0x75, 0x21, 0x11, 0xE4, 0x52, 0x42, 0xB5, 0xA9, 0x92, 0x52, 0x4D, 
  0xC1, 0x11, 0x43, 0x92, 0x47, 0xDE, 0xBA, 0xF5, 0x5C, 0x4E, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xE0, 0x0C, 0x60, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x2E, 0x94, 0x87, 0x4E, 0x3D, 0x29, 0x25, 0x96, 0xD2, 0x79, 
  0xE9, 0x9C, 0xE0, 0x9E, 0x33, 0x29, 0x1D, 0xF5, 0x5E, 0x4A, 0x29, 0xA5, 
  0x90, 0x42, 0x45, 0xAD, 0xA5, 0xF4, 0x52, 0x4A, 0xCE, 0xBD, 0xE0, 0x4C, 
  0x3D, 0x4A, 0xA5, 0x94, 0x92, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xB5, 0x56, 0xC6, 0x18, 0x05, 0x80, 0x52, 0x40, 
  0x29, 0x03, 0x40, 0x7D, 0xC6, 0x18, 0x05, 0x80, 0x52, 0x40, 0x29, 0x03, 
  0xAA, 0x2A, 0xC6, 0x18, 0x05, 0x80, 0x52, 0x40, 0x29, 0x03, 0x40, 0x7D, 
  0xC6, 0x1E, 0x05, 0xEF, 0xD2, 0x7F, 0xE9, 0x03, 0xB5, 0x56, 0xF6, 0xD8, 
  0xFD, 0x0C, 0x52, 0x08, 0x3F, 0x7B, 0x40, 0x7D, 0xC6, 0x1E, 0xA5, 0xEF, 
  0xD2, 0xFB, 0xC1, 0x63, 0xAA, 0x2A, 0xC6, 0x18, 0xA5, 0x8C, 0x52, 0x0A, 
  0x00, 0x60, 0x40, 0x7D, 0xC6, 0x18, 0xA5, 0x8C, 0x52, 0x0A, 0x00, 0x60, 
  0x8C, 0x01, 0x06, 0x18, 0xA3, 0x14, 0x50, 0x40, 0x01, 0x65, 0x8C, 0x01, 
  0x06, 0x18, 0xA3, 0x14, 0x50, 0x40, 0x01, 0x65, 0x8C, 0x01, 0x06, 0x18, 
  0xA3, 0x14, 0x50, 0x40, 0x01, 0x65, 0x8C, 0x01, 0x06, 0x18, 0xBF, 0xF4, 
  0xDF, 0x7F, 0xFF, 0xFF, 0xFC, 0xFF, 0xFE, 0xFF, 0xA3, 0x84, 0x00, 0x40, 
  0x00, 0x00, 0x00, 0x30, 0x06, 0x18, 0xBF, 0xFC, 0xFF, 0x7F, 0xFF, 0xFF, 
  0x00, 0x30, 0x06, 0x18, 0xA3, 0x80, 0x02, 0x4A, 0x01, 0x05, 0x00, 0x30, 
  0x06, 0x18, 0xA3, 0x80, 0x02, 0x4A, 0x01, 0x05, 0x14, 0x00, 0xCA, 0x00, 
  0xA0, 0x8C, 0x81, 0x0F, 0x1E, 0xFF, 0x14, 0x00, 0xCA, 0x00, 0xA0, 0x8C, 
  0x81, 0x0F, 0x1E, 0xFF, 0x14, 0x00, 0xCA, 0x00, 0xA0, 0x8C, 0x81, 0x0F, 
  0x1E, 0xFF, 0xF4, 0x1F, 0xCE, 0xFB, 0xA0, 0xFF, 0x81, 0x0F, 0x1E, 0xFF, 
  0xFF, 0xFD, 0xFE, 0x18, 0xBF, 0xEC, 0xF1, 0xFF, 0x1F, 0x3C, 0xE0, 0x5F, 
  0xC6, 0xFB, 0xA5, 0xFF, 0xB0, 0xFF, 0x1F, 0x3C, 0x80, 0x51, 0x00, 0x18, 
  0xA5, 0x0C, 0xB0, 0xFF, 0x1F, 0x3C, 0x80, 0x51, 0x00, 0x18, 0xA5, 0x0C, 
  0xB0, 0xFF, 0x1F, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE7, 0xBC, 
  0xE4, 0x52, 0x4A, 0x31, 0x8E, 0x14, 0x4E, 0x72, 0x29, 0x91, 0x54, 0x4D, 
  0x4A, 0xB5, 0x9A, 0x75, 0xDC, 0x4D, 0x2F, 0x10, 0x57, 0x53, 0x72, 0xB5, 
  0xAA, 0x92, 0x50, 0x75, 0xC1, 0x11, 0xE4, 0x92, 0x47, 0xDE, 0x9B, 0xE5, 
  0x4E, 0x4A, 0x01, 0x00, 0x43, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 
  0x0A, 0x00, 0x02, 0x33, 0x00, 0x00, 0x00, 0x00, 0x58, 0x15, 0xAF, 0x30, 
  0x8E, 0x31, 0x06, 0x0C, 0x00, 0x20, 0x26, 0x00, 0x01, 0x60, 0x86, 0x31, 
  0x60, 0x16, 0x00, 0x50, 0x51, 0x00, 0xE7, 0xC0, 0x83, 0xB1, 0xDF, 0x96, 
  0x87, 0x88, 0x08, 0x00, 0xE1, 0x61, 0x86, 0xB1, 0x1F, 0x8C, 0x07, 0x45, 
  0x7D, 0x00, 0x21, 0xB0, 0x8D, 0x37, 0x60, 0x00, 0x00, 0x22, 0x02, 0x00, 
  0xCF, 0xD1, 0x8B, 0x1D, 0x96, 0x00, 0xF0, 0x00, 0x40, 0x00, 0x00, 0x60, 
  0x86, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
