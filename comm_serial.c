/*
Author: Torenjk (Tom Kamprath)

This file will handle all communication between the client and host

*/

volatile uint8_t *UB0H = 0xC5; //USART baud rate register high
volatile uint8_t *UB0L = 0xC4; //USART baud rate register low
volatile uint8_t *UC0B = 0xC1; //USART control and status Register n B (see Page 160 of the datasheet)
volatile uint8_t *UC0C = 0xC2; //see Page 161 and 172 but its for setting the usart mode (SYNC, ASINC, MSPIM...)
volatile uint8_t *U0 = 0xC6; //USART I/O Data register (See page 159 of the datasheet)


void
parse_files(){
    //Will send data of the eeprom over to client
}

//Todo: checksum generation on Client and Host side
