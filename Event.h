//
// Created by msc20h13 on 9/29/20.
//

#ifndef UNTITLED_EVENT_H
#define UNTITLED_EVENT_H

class Event {
public:
    float _timestamp;
    int _x;
    int _y;
    bool _pol;
    bool isFilteredOut = false;
    Event(float ts, int x, int y, bool pol);
    void SetEvent(float ts, int x, int y, bool pol);
};
#endif //UNTITLED_EVENT_H
