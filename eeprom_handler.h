/*
Author: Torenjk (Tom Kamprath)
Brief Description: Handles all eeprom functions on Host Side
*/

#pragma once

void eeprom_write_byte(uint8_t *address, uint8_t data)
    //Will write Data to the eeprom on specified address

void eeprom_read(uint8_t *address)
    //Will read Data from eeprom on specified address

void map_eeprom(void)
    //Will map whole eeprom for graphical display on Client
