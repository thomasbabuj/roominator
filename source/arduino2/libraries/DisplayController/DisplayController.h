// DisplayController.h

#include "WProgram.h"
#include "NetworkSlave.h"

enum DisplayColor {
  GREEN,
  YELLOW,
  RED
};

class DisplayController {
public:
  DisplayController(LiquidCrystal* lcd, NetworkSlave* slave, int redPin, int yellowPin, int greenPin);

  void setDisplayName(char* displayName);

  void setDisplayColor(DisplayColor displayColor);

  void setCurrentReservation(char* currentReservation);

  void onPressReserveOrExtend();
  void onPressCancel();

  // Do all the actual display logic.
  void draw();

private:
  LiquidCrystal* lcd;
  NetworkSlave* slave;

  char _displayName[21];
  char _currentReservation[21];
  DisplayColor _displayColor;


  int redPin;
  int yellowPin;
  int greenPin;

  void setHigh(DisplayColor displayColor);
};
