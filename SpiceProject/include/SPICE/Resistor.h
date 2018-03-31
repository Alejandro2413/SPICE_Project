/***
 * David Mercanti
 * 
 * Copyright 2018
 * 
 */
#ifndef SPICEPROJECT_INCLUDE_SPICE_RESISTOR_H_
#define SPICEPROJECT_INCLUDE_SPICE_RESISTOR_H_
#include <vector>
#include "SPICE/Component.h"
#include "SPICE/Circuit.h"
class Resistor : public Component {
  public:
    /*Calculates the cucrrent in the resistor, implement later*/
    //float CalculateCurrent();
    explicit Resistor(const std::string *componentNames, std::stringstream &restOfLine, std::map<std::string, Node> &myMap);
    int getResistance () { return Resistance_;}
    Suffix getSuffix() {return ResisSuff_;}
    private:
    int Resistance_;
    Suffix ResisSuff_;
    friend std::ostream &operator<<(std::ostream &os, const Resistor &rName);
};
std::ostream &operator<<(std::ostream &os, const Resistor &rName);

#endif // SPICEPROJECT_INCLUDE_SPICE_COMPONENT_H_