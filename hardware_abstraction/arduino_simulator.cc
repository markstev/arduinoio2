#include "arduino_simulator.h"
#include <chrono>
#include <ctime>

namespace {
bool CreateAndCloseFile(const char *filename) {
  FILE *f = fopen(filename, "w");
  if (f == nullptr) return false;
  fclose(f);
  return true;
}
}  // namespace

unsigned long micros() {
  using std::chrono::high_resolution_clock;
  using std::chrono::duration;
  using std::chrono::duration_cast;
  const static high_resolution_clock::time_point t1 =
      high_resolution_clock::now();
  const high_resolution_clock::time_point t2 = high_resolution_clock::now();
  const duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  return static_cast<unsigned long>(1e6 * time_span.count());
}

void digitalWrite(const unsigned int pin, bool value) {
}

bool digitalRead(const unsigned int pin) {
  return false;
}

SerialAbstraction::~SerialAbstraction() {
  fclose(incoming_file_);
  fclose(outgoing_file_);
}

void SerialAbstraction::write(const unsigned char c) {
  fputc(c, outgoing_file_);
  fflush(outgoing_file_);
  printf("Wrote %c\n", c);
}

int SerialAbstraction::read() {
  if (next_byte_ != EOF) {
    const int ret = next_byte_;
    next_byte_ = EOF;
    return ret;
  }
  int read_result = fgetc(incoming_file_);
  if (read_result == EOF) {
    clearerr(incoming_file_);
    return -1;
  }
  return read_result;
}

bool SerialAbstraction::available() {
  if (next_byte_ != EOF) {
    return true;
  }
  next_byte_ = fgetc(incoming_file_);
  if (next_byte_ != EOF) {
    return true;
  } else {
    clearerr(incoming_file_);
    return false;
  }
}

bool SerialAbstraction::UseFiles(const char *incoming, const char *outgoing) {
  incoming_file_ = fopen(incoming, "rb+");
  if (incoming_file_ == nullptr) {
    // Creates the file and tries again.
    CreateAndCloseFile(incoming);
    incoming_file_ = fopen(incoming, "rb+");
  }
  outgoing_file_ = fopen(outgoing, "wb+");
  return incoming_file_ != nullptr && outgoing_file_ != nullptr;
}
