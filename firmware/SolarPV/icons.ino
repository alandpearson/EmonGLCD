//Icons
/*
 * 4 different images of thermometer each one shows 1/4 filled more than the last
 * eg [0] shows 0 deg, [1] shows 25 deg, 2 shows 75 deg, 3 shows 100deg
 * 
 * 
static const uint8_t icon_heating_8x16 [5][16] PROGMEM = {
{
0x00, 0xFE, 0x03, 0x55, 0x55, 0x03, 0xFE, 0x00, 0x1E, 0x63, 0x5C, 0xDD, 0xDD, 0x5C, 0x63, 0x1E
},{
0x00, 0xFE, 0x03, 0x55, 0x55, 0x03, 0xFE, 0x00, 0x1E, 0x63, 0x5C, 0xDF, 0xDF, 0x5C, 0x63, 0x1E
},{
0x00, 0xFE, 0x03, 0xD5, 0xD5, 0x03, 0xFE, 0x00, 0x1E, 0x63, 0x5C, 0xDF, 0xDF, 0x5C, 0x63, 0x1E
},{
0x00, 0xFE, 0x03, 0xF5, 0xF5, 0x03, 0xFE, 0x00, 0x1E, 0x63, 0x5C, 0xDF, 0xDF, 0x5C, 0x63, 0x1E
},{
0x0E, 0xF3, 0x01, 0xFD, 0xFD, 0x01, 0xF3, 0x0E, 0x1E, 0x63, 0x5C, 0xDF, 0xDF, 0x5C, 0x63, 0x1E
}
};
*/


static const uint8_t icon_home_13x12 [] PROGMEM = {
0x60, 0x30, 0xDF, 0xEF, 0xF6, 0xFB, 0xFD, 0xFB, 0xF6, 0xEC, 0xD8, 0x30, 0x60, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t icon_lines_12x12 [] PROGMEM = {
0x6C, 0x24, 0x36, 0xFE, 0x25, 0x25, 0xFE, 0x36, 0x24, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0C, 0x06, 0x05, 0x06, 0x06, 0x05, 0x06, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


//5 different weather icons
//0 = 3 clouds
//1-4 = sunshine with varying rays
static const uint8_t icon_solar_12x12 [5] [32] PROGMEM = {
{
0xC0, 0x60, 0x30, 0x18, 0x08, 0x0C, 0x92, 0xA2, 0xE2, 0xC4, 0x58, 0x60, 0x00, 0x00, 0x00, 0x00,
0x01, 0x03, 0x02, 0x02, 0x02, 0x07, 0x0D, 0x08, 0x08, 0x08, 0x0D, 0x06, 0x00, 0x00, 0x00, 0x00
},{
0x00, 0x20, 0x04, 0x60, 0x90, 0x08, 0x0A, 0x90, 0x60, 0x04, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},{
0x20, 0x20, 0x04, 0x68, 0x90, 0x08, 0x0B, 0x90, 0x68, 0x04, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x02, 0x01, 0x00, 0x01, 0x0D, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},{
0x60, 0x60, 0x0C, 0x6C, 0x90, 0x0B, 0x0B, 0x90, 0x6C, 0x0C, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0x03, 0x00, 0x0D, 0x0D, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},{
0x60, 0x66, 0x0E, 0x6C, 0x90, 0x0B, 0x0B, 0x90, 0x6C, 0x0E, 0x66, 0x60, 0x00, 0x00, 0x00, 0x00,
0x00, 0x06, 0x07, 0x03, 0x00, 0x0D, 0x0D, 0x00, 0x03, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00
}
};
