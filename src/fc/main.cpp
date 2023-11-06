#include <flightcom.h>

void setup()
{
  Serial.begin(115200);
  setupState();
}

State currState;

void loop()
{
  currState.reloadStatefromDisk();
  Serial.printf("State = %d\n", currState.flight_state);
  while (Serial.available() <= 0)
  {
  }
  char newState = Serial.read();
  Serial.printf("newState: %d\n", (uint8_t)atoi(&newState));
  currState.writeFlightState((uint8_t)atoi(&newState));
  commitMemory();
}