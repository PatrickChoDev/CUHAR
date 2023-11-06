#include "anything.hpp"

void setupState()
{
  EEPROM.begin(EEPROM_MEMSIZE);
}

uint8_t readFromAddress(int addr)
{
  return EEPROM.read(addr);
}

void writeToAddress(int addr, uint8_t val)
{
  EEPROM.write(addr, val);
}

void commitMemory()
{
  EEPROM.commit();
}

class State
{
public:
  int flight_state;
  int random;
  void reloadStatefromDisk()
  {
    flight_state = readFromAddress(FLIGHT_STATE_ADDRESS);
    random = readFromAddress(0x33);
  }
  void writeFlightState(uint8_t val)
  {
    writeToAddress(FLIGHT_STATE_ADDRESS, val);
  }
};