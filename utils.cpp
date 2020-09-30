//
// Created by msc20h13 on 9/29/20.
// This is a C++ implementation of code written by Tobi Delbruck in Java for jAER
//
#include <iostream>
#include "utils.h"


std::string get_current_dir() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    return current_working_dir;
}

int nthSubstr(int n, const string& s, const string& p) {
    string::size_type i = s.find(p);     // Find the first occurrence

    int j;
    for (j = 1; j < n && i != string::npos; ++j)
        i = s.find(p, i+1); // Find the next occurrence

    if (j == n)
        return(i);
    else
        return(-1);
}

std::vector<Event> BackGroundActivityFilter(std::vector<Event> EventBuffer) {
    //size of chip
    int SIZE_X = 128;
    int SIZE_Y = 128;
    double dt = 1e-6; //time that spike needs to be supported by prior event in neighborhood to pass through
    float ts = 0;
    int eventCount = 0;
    int filteredOutCount = 0;

    vector<vector<int>> lastTimesMap = initializeMap(SIZE_X,SIZE_Y);
//    std::cout << lastTimesMap.size();
    for(Event e : EventBuffer)
    {
        ts = e._timestamp;
        int x = e._x;
        int y = e._y;

        if( x < 0  || x > SIZE_X || y < 0 || y > SIZE_Y)
        {
            filteredOutCount++;
            continue;
        }

        float lastT = lastTimesMap[x][y];
        int deltaT = (ts - lastT);

        if(!((deltaT < dt) && (lastT != 0)))
        {
            e.isFilteredOut == true; // does it change the real event or just a copy of it... ?
            filteredOutCount++;
        }

        eventCount++;
        //foreach event write the event's timestamp into the lastTimesMap at neighboring locations lastTimesMap[x][y]=ts
        if( (x > 0) && (x < SIZE_X) && ( (y > 0) && (y < SIZE_Y) ) )
        {
            lastTimesMap[x-1][y] = ts;
            lastTimesMap[x-1][y-1] = ts;
            lastTimesMap[x-1][y+1] = ts;
            lastTimesMap[x][y-1] = ts;
            lastTimesMap[x][y+1] = ts;
            lastTimesMap[x+1][y] = ts;
            lastTimesMap[x+1][y-1] = ts;
            lastTimesMap[x+1][y+1] = ts;
        }
        return EventBuffer; // the events are all still inside, just the events which should be filtered out are set to be filtered out, needs to be handeled somewhere
    }

}

std::vector<vector<int>> initializeMap(int sizeX,int sizeY){
    std::vector<vector<int>> lastTimesMap(sizeX, std::vector<int>(sizeY));
    return lastTimesMap;
    //check that vector is initialized correctly
    /*    for (int i=0; i < sizeX; i++)
    {
        for (int j=0; j< sizeY; j++)
        {
            std::cout << lastTimesMap[i][j];
        }
    }*/
}