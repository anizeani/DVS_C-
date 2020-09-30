//
// Created by msc20h13 on 9/29/20.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H
using namespace std;
#include "Event.h"
#include <vector>
#include <unistd.h>
#define GetCurrentDir getcwd

std::string get_current_dir();

int nthSubstr(int n, const string& s, const string& p);

vector<vector<bool>> BackGroundActivityFilter(std::vector<Event> EventBuffer);
std::vector<vector<int>> initializeMap(int sizeX,int sizeY);
#endif //UNTITLED_UTILS_H