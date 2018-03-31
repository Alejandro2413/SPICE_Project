/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */
#include <map>
#include "SPICE/Component.h"

Component::Component(const std::string *similiarNames, std::map<std::string, Node> &myMap) {
  name_ = similiarNames[0];
  myMap[similiarNames[1]].PosComp = this;
  myMap[similiarNames[2]].NegativeComp = this;

}
