
volatile uint8_t *E_CONT_REG = 0x3F; //EECR 
volatile uint8_t *E_DATA_REG = 0x40; //EEDR 
volatile uint16_t *E_ACC_REG = 0x41; //EEARL

//I really fcked up naming those constants TODO: change
const uint8_t E_MW_EN = 2; //Master Write Enable bit in EECR
const uint8_t E_WR_E = 1;// Write Enable bit in EECR
const uint8_t E_R_E = 0;// Read Enable bit in EECR

// The size of the EEPROM memory, in bytes
const uint16_t EEPROM_SIZE = 1024;



void 
eeprom_write_byte(uint8_t *address, uint8_t data){
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
eeprom_read(uint8_t *address){
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
Each 8-Bit Address will equal one "file"
*/


//TODO: Implement
}
