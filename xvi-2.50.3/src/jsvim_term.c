#include "xvi.h"
#include "jsvim_term.h" 
#include <emscripten.h> 

char terminfo_linux[] = {
  0x1a, 0x01, 0x14, 0x00, 0x1d, 0x00, 0x10, 0x00, 0x7d, 0x01, 0x49, 0x03,
  0x6c, 0x69, 0x6e, 0x75, 0x78, 0x7c, 0x6c, 0x69, 0x6e, 0x75, 0x78, 0x20,
  0x63, 0x6f, 0x6e, 0x73, 0x6f, 0x6c, 0x65, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0xff, 0xff, 0x08, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x08, 0x00, 0x40, 0x00, 0x12, 0x00, 0xff, 0xff,
  0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x15, 0x00, 0x1a, 0x00, 0x21, 0x00,
  0x25, 0x00, 0x29, 0x00, 0xff, 0xff, 0x34, 0x00, 0x45, 0x00, 0x47, 0x00,
  0x4b, 0x00, 0x57, 0x00, 0xff, 0xff, 0x59, 0x00, 0x65, 0x00, 0xff, 0xff,
  0x69, 0x00, 0x6d, 0x00, 0x79, 0x00, 0x7d, 0x00, 0xff, 0xff, 0xff, 0xff,
  0x81, 0x00, 0x87, 0x00, 0x8c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x91, 0x00,
  0x96, 0x00, 0xff, 0xff, 0xff, 0xff, 0x9b, 0x00, 0xa0, 0x00, 0xa5, 0x00,
  0xaa, 0x00, 0xb3, 0x00, 0xb9, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc1, 0x00,
  0xc6, 0x00, 0xcc, 0x00, 0xd2, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe4, 0x00, 0xe8, 0x00, 0xff, 0xff,
  0xec, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xee, 0x00, 0xff, 0xff,
  0xf3, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x00,
  0xfc, 0x00, 0x02, 0x01, 0x07, 0x01, 0x0c, 0x01, 0x11, 0x01, 0x16, 0x01,
  0x1c, 0x01, 0x22, 0x01, 0x28, 0x01, 0x2e, 0x01, 0x33, 0x01, 0xff, 0xff,
  0x38, 0x01, 0xff, 0xff, 0x3c, 0x01, 0x41, 0x01, 0x46, 0x01, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x4a, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0x4e, 0x01, 0xff, 0xff, 0x51, 0x01, 0x5a, 0x01, 0x63, 0x01, 0x6c, 0x01,
  0xff, 0xff, 0x75, 0x01, 0x7e, 0x01, 0x87, 0x01, 0xff, 0xff, 0x90, 0x01,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x99, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x01,
  0xa2, 0x01, 0xad, 0x01, 0xb0, 0x01, 0xb2, 0x01, 0xb5, 0x01, 0x0b, 0x02,
  0xff, 0xff, 0x0e, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x10, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x14, 0x02, 0xff, 0xff, 0x55, 0x02, 0xff, 0xff, 0xff, 0xff,
  0x59, 0x02, 0x5f, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x65, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6a, 0x02, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6c, 0x02,
  0x72, 0x02, 0x78, 0x02, 0x7e, 0x02, 0x84, 0x02, 0x8a, 0x02, 0x90, 0x02,
  0x96, 0x02, 0x9c, 0x02, 0xa2, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa8, 0x02, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xad, 0x02, 0xb8, 0x02,
  0xbd, 0x02, 0xc3, 0x02, 0xc7, 0x02, 0xd0, 0x02, 0xd4, 0x02, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0x25, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x29, 0x03, 0x33, 0x03,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0x3d, 0x03, 0x43, 0x03, 0x07, 0x00, 0x0d, 0x00, 0x1b, 0x5b, 0x25, 0x69,
  0x25, 0x70, 0x31, 0x25, 0x64, 0x3b, 0x25, 0x70, 0x32, 0x25, 0x64, 0x72,
  0x00, 0x1b, 0x5b, 0x33, 0x67, 0x00, 0x1b, 0x5b, 0x48, 0x1b, 0x5b, 0x4a,
  0x00, 0x1b, 0x5b, 0x4b, 0x00, 0x1b, 0x5b, 0x4a, 0x00, 0x1b, 0x5b, 0x25,
  0x69, 0x25, 0x70, 0x31, 0x25, 0x64, 0x47, 0x00, 0x1b, 0x5b, 0x25, 0x69,
  0x25, 0x70, 0x31, 0x25, 0x64, 0x3b, 0x25, 0x70, 0x32, 0x25, 0x64, 0x48,
  0x00, 0x0a, 0x00, 0x1b, 0x5b, 0x48, 0x00, 0x1b, 0x5b, 0x3f, 0x32, 0x35,
  0x6c, 0x1b, 0x5b, 0x3f, 0x31, 0x63, 0x00, 0x08, 0x00, 0x1b, 0x5b, 0x3f,
  0x32, 0x35, 0x68, 0x1b, 0x5b, 0x3f, 0x30, 0x63, 0x00, 0x1b, 0x5b, 0x43,
  0x00, 0x1b, 0x5b, 0x41, 0x00, 0x1b, 0x5b, 0x3f, 0x32, 0x35, 0x68, 0x1b,
  0x5b, 0x3f, 0x38, 0x63, 0x00, 0x1b, 0x5b, 0x50, 0x00, 0x1b, 0x5b, 0x4d,
  0x00, 0x1b, 0x5b, 0x31, 0x31, 0x6d, 0x00, 0x1b, 0x5b, 0x35, 0x6d, 0x00,
  0x1b, 0x5b, 0x31, 0x6d, 0x00, 0x1b, 0x5b, 0x32, 0x6d, 0x00, 0x1b, 0x5b,
  0x34, 0x68, 0x00, 0x1b, 0x5b, 0x37, 0x6d, 0x00, 0x1b, 0x5b, 0x37, 0x6d,
  0x00, 0x1b, 0x5b, 0x34, 0x6d, 0x00, 0x1b, 0x5b, 0x25, 0x70, 0x31, 0x25,
  0x64, 0x58, 0x00, 0x1b, 0x5b, 0x31, 0x30, 0x6d, 0x00, 0x1b, 0x5b, 0x30,
  0x3b, 0x31, 0x30, 0x6d, 0x00, 0x1b, 0x5b, 0x34, 0x6c, 0x00, 0x1b, 0x5b,
  0x32, 0x37, 0x6d, 0x00, 0x1b, 0x5b, 0x32, 0x34, 0x6d, 0x00, 0x1b, 0x5b,
  0x3f, 0x35, 0x68, 0x1b, 0x5b, 0x3f, 0x35, 0x6c, 0x24, 0x3c, 0x32, 0x30,
  0x30, 0x2f, 0x3e, 0x00, 0x1b, 0x5b, 0x40, 0x00, 0x1b, 0x5b, 0x4c, 0x00,
  0x7f, 0x00, 0x1b, 0x5b, 0x33, 0x7e, 0x00, 0x1b, 0x5b, 0x42, 0x00, 0x1b,
  0x5b, 0x5b, 0x41, 0x00, 0x1b, 0x5b, 0x32, 0x31, 0x7e, 0x00, 0x1b, 0x5b,
  0x5b, 0x42, 0x00, 0x1b, 0x5b, 0x5b, 0x43, 0x00, 0x1b, 0x5b, 0x5b, 0x44,
  0x00, 0x1b, 0x5b, 0x5b, 0x45, 0x00, 0x1b, 0x5b, 0x31, 0x37, 0x7e, 0x00,
  0x1b, 0x5b, 0x31, 0x38, 0x7e, 0x00, 0x1b, 0x5b, 0x31, 0x39, 0x7e, 0x00,
  0x1b, 0x5b, 0x32, 0x30, 0x7e, 0x00, 0x1b, 0x5b, 0x31, 0x7e, 0x00, 0x1b,
  0x5b, 0x32, 0x7e, 0x00, 0x1b, 0x5b, 0x44, 0x00, 0x1b, 0x5b, 0x36, 0x7e,
  0x00, 0x1b, 0x5b, 0x35, 0x7e, 0x00, 0x1b, 0x5b, 0x43, 0x00, 0x1b, 0x5b,
  0x41, 0x00, 0x0d, 0x0a, 0x00, 0x1b, 0x5b, 0x25, 0x70, 0x31, 0x25, 0x64,
  0x50, 0x00, 0x1b, 0x5b, 0x25, 0x70, 0x31, 0x25, 0x64, 0x4d, 0x00, 0x1b,
  0x5b, 0x25, 0x70, 0x31, 0x25, 0x64, 0x42, 0x00, 0x1b, 0x5b, 0x25, 0x70,
  0x31, 0x25, 0x64, 0x40, 0x00, 0x1b, 0x5b, 0x25, 0x70, 0x31, 0x25, 0x64,
  0x4c, 0x00, 0x1b, 0x5b, 0x25, 0x70, 0x31, 0x25, 0x64, 0x44, 0x00, 0x1b,
  0x5b, 0x25, 0x70, 0x31, 0x25, 0x64, 0x43, 0x00, 0x1b, 0x5b, 0x25, 0x70,
  0x31, 0x25, 0x64, 0x41, 0x00, 0x1b, 0x63, 0x1b, 0x5d, 0x52, 0x00, 0x1b,
  0x38, 0x00, 0x1b, 0x5b, 0x25, 0x69, 0x25, 0x70, 0x31, 0x25, 0x64, 0x64,
  0x00, 0x1b, 0x37, 0x00, 0x0a, 0x00, 0x1b, 0x4d, 0x00, 0x1b, 0x5b, 0x30,
  0x3b, 0x31, 0x30, 0x25, 0x3f, 0x25, 0x70, 0x31, 0x25, 0x74, 0x3b, 0x37,
  0x25, 0x3b, 0x25, 0x3f, 0x25, 0x70, 0x32, 0x25, 0x74, 0x3b, 0x34, 0x25,
  0x3b, 0x25, 0x3f, 0x25, 0x70, 0x33, 0x25, 0x74, 0x3b, 0x37, 0x25, 0x3b,
  0x25, 0x3f, 0x25, 0x70, 0x34, 0x25, 0x74, 0x3b, 0x35, 0x25, 0x3b, 0x25,
  0x3f, 0x25, 0x70, 0x35, 0x25, 0x74, 0x3b, 0x32, 0x25, 0x3b, 0x25, 0x3f,
  0x25, 0x70, 0x36, 0x25, 0x74, 0x3b, 0x31, 0x25, 0x3b, 0x25, 0x3f, 0x25,
  0x70, 0x39, 0x25, 0x74, 0x3b, 0x31, 0x31, 0x25, 0x3b, 0x6d, 0x00, 0x1b,
  0x48, 0x00, 0x09, 0x00, 0x1b, 0x5b, 0x47, 0x00, 0x2b, 0x10, 0x2c, 0x11,
  0x2d, 0x18, 0x2e, 0x19, 0x30, 0xdb, 0x60, 0x04, 0x61, 0xb1, 0x66, 0xf8,
  0x67, 0xf1, 0x68, 0xb0, 0x69, 0xce, 0x6a, 0xd9, 0x6b, 0xbf, 0x6c, 0xda,
  0x6d, 0xc0, 0x6e, 0xc5, 0x6f, 0x7e, 0x70, 0xc4, 0x71, 0xc4, 0x72, 0xc4,
  0x73, 0x5f, 0x74, 0xc3, 0x75, 0xb4, 0x76, 0xc1, 0x77, 0xc2, 0x78, 0xb3,
  0x79, 0xf3, 0x7a, 0xf2, 0x7b, 0xe3, 0x7c, 0xd8, 0x7d, 0x9c, 0x7e, 0xfe,
  0x00, 0x1b, 0x5b, 0x5a, 0x00, 0x1b, 0x5b, 0x3f, 0x37, 0x68, 0x00, 0x1b,
  0x5b, 0x3f, 0x37, 0x6c, 0x00, 0x1b, 0x5b, 0x34, 0x7e, 0x00, 0x1a, 0x00,
  0x1b, 0x5b, 0x32, 0x33, 0x7e, 0x00, 0x1b, 0x5b, 0x32, 0x34, 0x7e, 0x00,
  0x1b, 0x5b, 0x32, 0x35, 0x7e, 0x00, 0x1b, 0x5b, 0x32, 0x36, 0x7e, 0x00,
  0x1b, 0x5b, 0x32, 0x38, 0x7e, 0x00, 0x1b, 0x5b, 0x32, 0x39, 0x7e, 0x00,
  0x1b, 0x5b, 0x33, 0x31, 0x7e, 0x00, 0x1b, 0x5b, 0x33, 0x32, 0x7e, 0x00,
  0x1b, 0x5b, 0x33, 0x33, 0x7e, 0x00, 0x1b, 0x5b, 0x33, 0x34, 0x7e, 0x00,
  0x1b, 0x5b, 0x31, 0x4b, 0x00, 0x1b, 0x5b, 0x25, 0x69, 0x25, 0x64, 0x3b,
  0x25, 0x64, 0x52, 0x00, 0x1b, 0x5b, 0x36, 0x6e, 0x00, 0x1b, 0x5b, 0x3f,
  0x36, 0x63, 0x00, 0x1b, 0x5b, 0x63, 0x00, 0x1b, 0x5b, 0x33, 0x39, 0x3b,
  0x34, 0x39, 0x6d, 0x00, 0x1b, 0x5d, 0x52, 0x00, 0x1b, 0x5d, 0x50, 0x25,
  0x70, 0x31, 0x25, 0x78, 0x25, 0x70, 0x32, 0x25, 0x7b, 0x32, 0x35, 0x35,
  0x7d, 0x25, 0x2a, 0x25, 0x7b, 0x31, 0x30, 0x30, 0x30, 0x7d, 0x25, 0x2f,
  0x25, 0x30, 0x32, 0x78, 0x25, 0x70, 0x33, 0x25, 0x7b, 0x32, 0x35, 0x35,
  0x7d, 0x25, 0x2a, 0x25, 0x7b, 0x31, 0x30, 0x30, 0x30, 0x7d, 0x25, 0x2f,
  0x25, 0x30, 0x32, 0x78, 0x25, 0x70, 0x34, 0x25, 0x7b, 0x32, 0x35, 0x35,
  0x7d, 0x25, 0x2a, 0x25, 0x7b, 0x31, 0x30, 0x30, 0x30, 0x7d, 0x25, 0x2f,
  0x25, 0x30, 0x32, 0x78, 0x00, 0x1b, 0x5b, 0x4d, 0x00, 0x1b, 0x5b, 0x33,
  0x25, 0x70, 0x31, 0x25, 0x64, 0x6d, 0x00, 0x1b, 0x5b, 0x34, 0x25, 0x70,
  0x31, 0x25, 0x64, 0x6d, 0x00, 0x1b, 0x5b, 0x31, 0x31, 0x6d, 0x00, 0x1b,
  0x5b, 0x31, 0x30, 0x6d, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x08, 0x00,
  0x14, 0x00, 0x28, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x00, 0x00, 0x03, 0x00, 0x06, 0x00, 0x09, 0x00, 0x0c, 0x00,
  0x0f, 0x00, 0x12, 0x00, 0x15, 0x00, 0x18, 0x00, 0x1c, 0x00, 0x20, 0x00,
  0x24, 0x00, 0x41, 0x58, 0x00, 0x47, 0x30, 0x00, 0x58, 0x54, 0x00, 0x55,
  0x38, 0x00, 0x45, 0x30, 0x00, 0x45, 0x33, 0x00, 0x53, 0x30, 0x00, 0x54,
  0x53, 0x00, 0x6b, 0x61, 0x32, 0x00, 0x6b, 0x62, 0x31, 0x00, 0x6b, 0x62,
  0x33, 0x00, 0x6b, 0x63, 0x32, 0x00
};
int terminfo_linux_len = 1794;


int tputs(const char *str, int affcnt, int (*putc)(int)) {
    const char *p = str;
    //EM_ASM_({console.log("TPUTS",UTF8ToString($0),$1,$2);},str, affcnt, putc);
    while(*p) {
        putc(*p);
        p++;
    }
    return 1;
    /*
    //printf(str);
    return EM_ASM_INT({return vim_tputs(UTF8ToString($0),$1,$2)},str,affcnt,putc);
    */
}

int tgetflag(char *id) {
    return ERR;
}

int tgetent(char *bp, const char *name) {
    // Return the constant linux termcap entry
    strcpy(bp, terminfo_linux);
    return terminfo_linux_len;
}

int tgetnum(char *id) {
    int c = EM_ASM_INT({return vim_tgetnum(UTF8ToString($0))},id);
    //EM_ASM_({console.log("TGETNUM",UTF8ToString($0),"=",$1);},id,c);
    return c;
}


char *tgetstr(char *id, char **area) {
    char *result = NULL;
    if(strcmp("cm",id)==0) { result = strdup("\033[<L>;<C>f"); }
    else if(strcmp("bc",id)==0) { result = strdup("\b"); }
    else if(strcmp("up",id)==0) { result = strdup("\033[1A"); }
    else if(strcmp("do",id)==0) { result = strdup("\033[1B"); }
    else if(strcmp("cr",id)==0) { result = strdup("\r"); }
    else if(strcmp("nd",id)==0) { result = strdup("\033[1C"); }
    else if(strcmp("ce",id)==0) { result = strdup("\033[K"); }
    else if(strcmp("cl",id)==0) { result = strdup("\033[2J"); }
    else if(strcmp("al",id)==0) { result = strdup("\033[1L"); }
    else if(strcmp("dl",id)==0) { result = strdup("\033[1M"); }
    else if(strcmp("ho",id)==0) { result = strdup("\033[H"); }
    // TODO: now at `cs' capability

    if((NULL != result) && (NULL != area)) {
        *area = result;
    }
    //EM_ASM_({console.log("TGETSTR",UTF8ToString($0),"=", (0==$1)?"NULL":UTF8ToString($1));},id,result);
    return result;
}

char *tgoto(char *cap, int col, int row) {
    sprintf(cap, "\033[<%d>;<%d>f", row, col);
    return cap;
}

int
kbgetc()
{
    return EM_ASM_INT({return vim_kbgetc($0)},0);
}


