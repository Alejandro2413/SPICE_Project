/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */


#include "SPICE/Resistor.h"

Resistor::Resistor(const std::string *componentNames, std::stringstream &restOfLine, std::map<std::string, Node> &myMap)
 : Component(componentNames, myMap ) {
   //this constructor gives all the component values (using the Component constructor)
   //then now we need to set Resistivity and its suffix
   std::string tempString;
   restOfLine >> tempString;
   Resistance_ = getValueFromString(tempString, ResisSuff_);
 }

 std::ostream &operator<<(std::ostream &os, const Resistor &rName) {
   os << rName.name_;
   os << " Resistor ";
   os << rName.Resistance_;
   os << rName.ResisSuff_;
   return os;
 }
