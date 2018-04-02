/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */
//#include <map>
#include "SPICE/Component.h"

Component::Component(const std::string *similiarNames, std::map<std::string, Node> &myMap) {
  //std::cout << "entering component constructor";
  name_ = similiarNames[0];
  myMap[similiarNames[1]].PosCompName= name_;
  myMap[similiarNames[2]].NegativeCompName = name_;

}
