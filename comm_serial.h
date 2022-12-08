/*
Author: Torenjk (Tom Kamprath)
Brief Description: Handles all eeprom functions on Host Side
*/

bool init_eeprom_com(void)
/*
Initialize the communication to Client (PC)
returns true if communication is ok
returns false if communcation failed
*/
 
init_usart()
/*
Will initialize USART0 for communication
*/


parse_files()
/*
Communicates all EEPROM-Cells and their stored value
*/


send_msg(uint8_t msg_len, char msg[])
/*
sends a message over USART0
Parameter msg_len defines the message length in Bits
Parameter msg contains the actual message as type char
*/
