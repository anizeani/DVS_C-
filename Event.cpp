//
// Created by msc20h13 on 9/29/20.
//
#include "Event.h"

Event::Event(float ts, int x, int y, bool pol) {
    SetEvent(ts,x,y,pol);
}
void Event::SetEvent(float ts, int x, int y, bool pol) {
    _timestamp = ts;
    _x = x;
    _y = y;
    _pol = pol;
}