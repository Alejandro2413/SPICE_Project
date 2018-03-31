/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */


#ifndef SPICEPROJECT_INCLUDE_SPICE_CURRENTSOURCE_H_
#define SPICEPROJECT_INCLUDE_SPICE_CURRENTSOURCE_H_
//code goes here

#include <string>
#include <vector>
#include "SPICE/Component.h"
#include "SPICE/Circuit.h"


class CurrentSource : public Component {

  public:
    explicit CurrentSource(const std::string *componentNames, std::stringstream &restOfLine, std::map<std::string, Node> &myMap);  //constructors and destructors
    //~CurrentSource(); //worry about this later lmao

  public:
    void setCurrents(int ac, int dc) {acVal_ = ac; dcVal_ = dc;};
    void setAC(int ac) { acVal_ = ac;}
    void setDC(int dc) { dcVal_ = dc;}
    int dcVal_;
    Suffix dcSuff_;
    int acVal_;
    Suffix acSuff_;
    int freq_;
    Suffix freqSuff_;
};
std::ostream& operator<<(std::ostream &os, const CurrentSource &curSou); 



#endif //SPICEPROJECT_INCLUDE_SPICE_CURRENTSOURCE_H_