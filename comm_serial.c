/*
Author: Torenjk (Tom Kamprath)

This file will handle all communication between the client and host

*/

//Registers for USART0 are explained on Page 276 of the ATMega328 Datasheet
//Have fun with that clusterfck


volatile uint8_t *UB0H = 0xC5; //USART baud rate register high
volatile uint8_t *UB0L = 0xC4; //USART baud rate register low
volatile uint8_t *UC0B = 0xC1; //USART control and status Register n B (see Page 160 of the datasheet)
volatile uint8_t *UC0C = 0xC2; //see Page 161 and 172 but its for setting the usart mode (SYNC, ASINC, MSPIM...)
volatile uint8_t *U0 = 0xC6; //USART I/O Data register (See page 159 of the datasheet)


void
init_usart(){
    //Will init the usart communication by setting the registers to the needed values

}

void
parse_files(){
    //Will send data of the eeprom over to client
}

//Todo: checksum generation on Client and Host side
