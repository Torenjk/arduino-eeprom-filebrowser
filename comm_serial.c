/*
Author: Torenjk (Tom Kamprath)

This file will handle all communication between the client and host

*/

//Registers for USART0 are explained on Page 276 of the ATMega328 Datasheet
//Have fun with that clusterfck


volatile uint8_t *baud_rate_reg_high = 0xC5; //USART baud rate register high
volatile uint8_t *baud_rate_reg_low = 0xC4; //USART baud rate register low
volatile uint8_t *control_status_reg_a = 0xC0; //USART control and status Register n A
volatile uint8_t *control_status_reg_b = 0xC1; //USART control and status Register n B (see Page 160 of the datasheet)
volatile uint8_t *control_status_reg_c = 0xC2; //see Page 161 and 172 but its for setting the usart mode (SYNC, ASINC, MSPIM...)
volatile uint8_t *data_reg = 0xC6; //USART I/O Data register (See page 159 of the datasheet)


void
init_usart(){
    //Will init the usart communication by setting the registers to the needed values
  // Set the baud rate to 9600


/*
    i used the following calculation and apparently it works..
    16 MHz / (16 * 9600) - 1 = 103

*/

  *baud_rate_reg_high = 0;
  *baud_rate_reg_low = 103;

  // Set the USART0 to transmit and receive data
  *control_status_reg_b = (1 << RXEN0) | (1 << TXEN0);

  // Set the USART0 to use 8-bit frames and no parity
  *control_status_reg_c = (1 << UCSZ01) | (1 << UCSZ00);

}


void
parse_files(){
    //Will send data of the eeprom over to client
}

//Todo: checksum generation on Client and Host side

void
send_msg(uint8_t msg_len, char msg[]){
    for(int i = 0; i < MSG_LEN; i++){

          while (!(*control_status_reg_a & (1 << 5)));
          *data_reg = MSG[i];
      }

/*

Usage: send_char(3, "TOM");
Will send a message over USART0
*/
}
