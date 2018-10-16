#pragma once
#if defined(PARTICLE)
#include "application.h"
#endif

struct PM
{
    long cf10 = 0;
    long cf25 = 0;
    long cf100 = 0;
    long at10 = 0;
    long at25 = 0;
    long at100 = 0;
};

class PMS3003
{
  public:
    void begin();
    PM read();
};