// ************************************
// * USEQ -Header 
// ************************************
//#include <USEQ.h>
// USEQ.h
//
// Version 1.0 21-07-20
// 
// Standard datasets & commands for USEQ series I2C product
// Default Address for the USEQ device is 0x65h
// (Note ... is this shifted 1 bit to 11001010b / 202d / 0xCA)
//
//  There are 5 24-bit A-D's (Channels 00 - 04)
//  On single pixel USEQMS, the data comes in on Channel 2
//  On 2 x 2 pixel USEQMS, the data comes in on Channel 0-3
//
// Channel 0 is the Dark Pixel on the Sensor or the Temperature Sensor on the ASIC
// depending on the Configuration Setup
//
// USEQ i2c commands available
#define EP_TEST                 0x00
#define EP_VER                  0x02
#define EP_FIFO_STAT            0x04
#define EP_FIFO_RD_FULL         0x06
#define EP_FIFO_RD_ACTV         0x08
#define EP_FIFO_CLR             0x0A
#define EP_FIFO_RST             0x0C
#define EP_CCP_RD               0x0E
#define EP_CCP_WR               0x10
#define EP_AFE_RD               0x12
#define EP_AFE_WR               0x14
#define EP_WUP_RD               0x16
#define EP_WUP_WR               0x18
#define EP_ENG_RD               0x1A
#define EP_ENG_WR               0x1C
#define EP_ADDR_WR              0x1E
#define EP__SLEEP               0x20
#define EP_WAKE                 0x22
#define EP_RST_SFT              0x24
#define EP_RST_FULL             0x26
#define EP_MEMTST_ON            0x28
#define EP_MEMTST_OFF           0x2A
#define EP_MEMTST_WR_SAME       0x2C
#define EP_MEMTST_WR_ALT        0x2E
#define EP_MEMTST_RD            0x30

// I2C Error & State Flags
#define ERR_OK                  0
#define ERR_LON_DATA            1
#define ERR_NAK_ADDR            2
#define ERR_NAK_DATA            3
#define ERR_UNKNOWN             4
#define ON                      1
#define OFF                     0

// Data Set Package Definitions
#define EP_FIFO_SZ              17
#define EP_CCP_SZ               5
#define EP_AFE_SZ               2
//#define EP_WUP_SZ               6

#define EP_FIFO_CH0             0
#define EP_FIFO_CH1             3
#define EP_FIFO_CH2             6
#define EP_FIFO_CH3             9
#define EP_FIFO_CH4             12
#define EP_FIFO_FC              15

#define EP_OR_CH0               0x00
#define EP_OR_CH1               0x01
#define EP_OR_CH2               0x02
#define EP_OR_CH3               0x03
#define EP_OR_CH4               0x04

#define EP_OR_MSK               0x80  // Position of the OR flag for each channel

// Channel Control Packet
// **** Switch on Channel 2 only (Single Sensor) *****
#define EP_CCP_EN               0x01
#define EP_CCP_AMP_01X          0x0C
#define EP_CCP_AMP_02X          0x0A
#define EP_CCP_AMP_04X          0x08
#define EP_CCP_AMP_08X          0x06
#define EP_CCP_AMP_16X          0x04
#define EP_CCP_AMP_32X          0x02
#define EP_CCP_AMP_64X          0x00
#define EP_CCP_HP_FLTR1         0x00
#define EP_CCP_HP_FLTR2         0x10
#define EP_CCP_HP_FLTR4         0x20  
#define EP_CCP_HP_FLTR8         0x30
#define EP_CCP_TRNS_120T        0x00
#define EP_CCP_TRNS_060T        0x40  
#define EP_CCP_TRNS_030T        0x80  
#define EP_CCP_TRNS_015T        0xC0

#define EP_CCP_HPF_MSK         ~EP_CCP_HP_FLTR8
#define EP_CCP_TRNS_MSK       ~(EP_CCP_TRNS_060T| EP_CCP_TRNS_030T| EP_CCP_TRNS_015T)
#define EP_CCP_AMP_MSK         ~(EP_CCP_AMP_32X| EP_CCP_AMP_16X| EP_CCP_AMP_04X)
// Analog Front End Packet

#define EP_INT_EN               0x01
#define EP_TMP                  0x02
#define EP_SYN_SLV              0x04
#define EP_CLK_OUT_EN           0x08
#define EP_LOPASS_FRQ_090       0x10
#define EP_LOPASS_FRQ_045       0x20
#define EP_LOPASS_FRQ_022_5     0x30
#define EP_HIPASS_FLTR          0x40
#define EP_LO_POW               0x80

#define EP_LOPASS_MSK           ~(EP_LOPASS_FRQ_090| EP_LOPASS_FRQ_045|EP_LOPASS_FRQ_022_5)
#define EP_INT_DIS              0x00
#define EP_SYNC_MSTR            0x00
#define EP_CLK_OUT_DIS          0x00
#define EP_LOPASS_FRQ_180       0x00

// Define the I2C I/O pins
#define SDA_PORT                PORTD  
#define SDA_PIN                 4              // SDA = D4
#define SCL_PORT                PORTD          // SCL = D5
#define SCL_PIN                 5

// Define all the pin assignments for the Backplane Board
#define EP_LED_RUN              A0
#define EP_LED_RDY              A1
#define EP_CS1                  6
#define EP_CS2                  11
#define EP_CS3                  12
#define EP_CS4                  13
#define EP_INT1                 A4
#define EP_INT3                 A5
#define EP_INT4                 A6
