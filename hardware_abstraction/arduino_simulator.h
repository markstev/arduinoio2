#ifndef hardware_simulator_arduino_simulator_h_
#define hardware_simulator_arduino_simulator_h_

#include <stdio.h>

// This interface mimics Arduino.h, so it can be used as a drop-in replacement.

void digitalWrite(const unsigned int pin, bool value);
bool digitalRead(const unsigned int pin);
unsigned long micros();

unsigned long micros();

class SerialAbstraction {
 public:
   ~SerialAbstraction();
  void write(const unsigned char c);
  int read();
  bool available();

  bool UseFiles(const char *incoming, const char *outgoing);

 private:
  FILE *incoming_file_, *outgoing_file_;
  int next_byte_ = EOF;
};

#endif
