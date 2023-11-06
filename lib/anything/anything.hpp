#include <EEPROM.h>

#define FLIGHT_STATE_ADDRESS 34
#define EEPROM_MEMSIZE 512

void setupState();

uint8_t readFromAddress(int addr);

void writeToAddress(int addr, uint8_t val);

void commitMemory();

class State
{
public:
  int flight_state;
  int random;
  void reloadStatefromDisk();
  void writeFlightState(uint8_t val);
};