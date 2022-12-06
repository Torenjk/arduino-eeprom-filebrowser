
volatile uint8_t *E_CONT_REG = 0x3F; //EECR 
volatile uint8_t *E_DATA_REG = 0x40; //EEDR 
volatile uint16_t *E_ACC_REG = 0x41; //EEARL

//I really fcked up naming those constants TODO: change
const uint8_t E_MW_EN = 2; //Master Write Enable bit in EECR
const uint8_t E_WR_E = 1;// Write Enable bit in EECR
const uint8_t E_R_E = 0;// Read Enable bit in EECR

// The size of the EEPROM memory, in bytes but needs to be changed if the model has bigger EEPROM
const uint16_t EEPROM_SIZE = 1024;
const uint8_t *EEPROM_BASE_ADDR = 0x00; //This is just the Base address of the EEPROM which we will loop trough

//EEPROM ADDRESS SPACE: 0x00 - 0x1F

void 
eeprom_write(uint8_t *address, uint8_t data){
//Safety check
if (address >= EEPROM_SIZE){
    //Call an error handler here!! TODO
    return;
  }

  while (*E_CONT_REG & (1 << E_WR_E));  // Wait until the Write Enable bit is cleared
  *E_ACC_REG = (uint16_t)address; // Set the address to write to in the Access Register
  *E_DATA_REG = data;  // Set the data to write in the Data Register
  *E_CONT_REG |= (1 << E_MW_EN); // Set the Write Enable bit in the Control Register
  *E_CONT_REG |= (1 << E_WR_E); // Set the Write Enable bit in the Control Register to start the write operation
}

void //maybe change to uint8_t so it will directly return the data
eeprom_read(uint8_t *address){ //maybe rename to read_cell? so we dont get confused as this only reads ONE cell
//Safety check
if (address >= EEPROM_SIZE){
    //Call an error handler here!! TODO
    return;
}
  *E_ACC_REG = (uint16_t)address; // Set the address to read from in the Access Register
  *E_CONT_REG |= (1 << E_R_E); // Set the Read Enable bit in the Control Register to start the read operation
  uint8_t data = *E_DATA_REG; // Read the data from the Data Register
}


void
map_eeprom(void){
/*
Maps the entire eeprom so that we can send it over serial to the Client
where it will be presented like a file browser
Each 8-Bit Address (so one cell) will equal one "file"
*/

//Additional Note: writing while reading is very unstable so we kinda need something like a lockbit or so

for (int i = 0; i < EEPROM_SIZE; i++){
      read_cell(EEPROM_BASE_ADDR++); //THIS WONT COMPILE NOW AS ITS JUST CALLING THE FUNCTION!!!!!
      //need to add a routine to work with the return value of read_cell
      //return value should be sent over USART including the address so we can map it into my programm then
    }  





//TODO: Implement
}

/*
More TODOs:
- lock interrupts to make sure the eeprom is not beeing written to

*/
