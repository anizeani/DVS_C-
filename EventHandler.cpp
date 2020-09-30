//
// Created by msc20h13 on 9/30/20.
//

#include "EventHandler.h"
#include <vector>

EventHandler::EventHandler(int sizeX, int sizeY){
     std::vector<std::vector<bool>> _filteredMap(sizeX, std::vector<bool>(sizeY));
     filteredMap = _filteredMap;
}