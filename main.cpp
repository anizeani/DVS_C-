#include <iostream>
#include "Event.h"
#include "utils.h"
#include <vector>

#include <fstream>
#include <sstream>

#include <unistd.h>
#define GetCurrentDir getcwd

#include <iterator>
#include <algorithm>
#include <sqltypes.h>

//for async tasks:
#include <future>
using namespace std;

// This is a C++ implementation of code written by Tobi Delbruck in Java for jAER

static std::vector<Event> read_from_txt_to_EventBuffer() {

/*  //To write into an output File
    std::ofstream myfile;
    myfile.open ("outputFileWithCommas.txt");
*/
    ifstream fileIn("/home/msc20h13/CLionProjects/DVS_EventProcessing/SliderCloseEvents.txt");

    vector<Event> EventBuffer;

    vector<string> vecOfStrs;
    string str;

    // cout << get_current_dir() << endl; //get current directory to check where files are stored

    int i = 0;
    while (getline(fileIn, str))
    {
        if (str.size() > 0) { //If there is any string at all do...

            // replace spaces with commas between elements
            /*replace(str.begin(),str.end(),' ',',');
            vecOfStrs.push_back(str);*/

            // if I want to add curly braces and commas between lines
            /*str.insert(0,"{");
            str.insert(str.end(),'}');
            str.insert(str.end(),',');*/

//            if(EventBuffer.size() < 1000)
//            {
            string TSstring = str.substr(0, str.find(' '));
            float timestamp = stof(TSstring);

            int posXBeg = nthSubstr(1, str, " ") + 1;
            int posXEnd = nthSubstr(2, str, " ");
            int deltaX = posXEnd - posXBeg;
            string XStr = str.substr(posXBeg, deltaX);
            int x = stoi(XStr);

            int posYBeg = nthSubstr(2, str, " ") + 1;
            int posYEnd = nthSubstr(3, str, " ");
            int deltaY = posYEnd - posYBeg;
            string yStr = str.substr(posYBeg, deltaY);
            int y = stoi(yStr);

            int posPolBeg = nthSubstr(3, str, " ") + 1;
            string polarity = str.substr(posPolBeg, str.size());
            bool pol = polarity != "0";

            //cout << timestamp << " " << x << " " << y << " " << pol << endl;

            Event Event(timestamp, x, y, pol);
            EventBuffer.push_back(Event);
            //EventBuffer[i];
            //++i;
//            }
//            else {
////                cout << "FrameSize == 1000 \n";
//                  return EventBuffer;
//                  }
            }
        }

    /* to write into an output file comment out and also in the beginning where myfile is defined
    ostream_iterator<string> output_iterator(myfile, "\n");
    copy(vecOfStrs.begin(), vecOfStrs.end(), output_iterator);
    myfile.close();*/

    return EventBuffer;
}

/*void delete_element(vector<Event>& temp, int col)
{
    temp.erase(temp.begin()+col);
}*/

int main() {
    // the management of the eventFlow here should be handled by an eventHandler
//    while(true) {
        std::vector<Event> EventBuffer = read_from_txt_to_EventBuffer(); // for now from txt file, later from camera
        vector<vector<bool>> FilteredEventMap = BackGroundActivityFilter(EventBuffer);
        for(int i = 0; i<239; ++i)
        {
            for (int j =0; j<179; ++j)
                if(FilteredEventMap[i][j] == true)
                cout << "x = " << i << " y = " << j << endl;
        }
//    }
    return 0;
}

