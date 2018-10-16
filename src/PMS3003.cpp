#include "PMS3003.h"

void PMS3003::begin()
{
  // Initialize serial port
  Serial1.begin(9600);
}

/*
 * Implementation based on
 * https://github.com/neojou/arduino-ameba/blob/master/example/pms3003-test/pms3003-test.ino
 */
PM PMS3003::read()
{
  int count = 0;
  unsigned char c = 0;
  unsigned char high = 0;
  bool complete = false;

  struct PM sample;

  while (Serial1.available() && !complete)
  {
    c = Serial1.read();
    if ((count == 0 && c != 0x42) || (count == 1 && c != 0x4d))
    {
      complete = true;
      sample.at10 = -1;
      sample.at25 = -1;
      sample.at100 = -1;
      sample.cf10 = -1;
      sample.cf25 = -1;
      sample.cf100 = -1;
      break;
    }
    if (count > 15)
    {
      complete = true;
      break;
    }
    else if (count == 4 || count == 6 || count == 8 || count == 10 ||
             count == 12 || count == 14)
    {
      high = c;
    }
    else if (count == 5)
    {
      sample.cf10 = 256 * high + c;
    }
    else if (count == 7)
    {
      sample.cf25 = 256 * high + c;
    }
    else if (count == 9)
    {
      sample.cf100 = 256 * high + c;
    }
    else if (count == 11)
    {
      sample.at10 = 256 * high + c;
    }
    else if (count == 13)
    {
      sample.at25 = 256 * high + c;
    }
    else if (count == 15)
    {
      sample.at100 = 256 * high + c;
    }
    count++;
  }

  // Clear serial buffer
  while (Serial1.available())
  {
    Serial1.read();
  }

  return sample;
}