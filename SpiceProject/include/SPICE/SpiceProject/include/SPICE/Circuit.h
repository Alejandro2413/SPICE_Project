/***
 * David Mercanti
 * 
 * Copyright 2018
 * The circuit class which holds the
 * circuit. It also needs to read the circuit from the file
 * 
 */
#ifndef SPICEPROJECT_INCLUDE_SPICE_CIRCUIT_H_
#define SPICEPROJECT_INCLUDE_SPICE_CIRCUIT_H_

/*#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <fstream> */
#include "SPICE/circuitLibs.h"
#include "SPICE/Component.h"
#include "SPICE/CurrentSource.h"
#include "SPICE/Resistor.h"

class Circuit {
  public:
  explicit Circuit (std::string &fileName) {load(fileName);}
  float step_;
  std::vector<Resistor*> resistorList_;
  std::vector<CurrentSource*> currentSourceList_;
  std::map<std::string, Node> nodeList_;
  timeStruct cirTime;
  public:
   void decomposeLineS(std::stringstream &myStream);
   void decomposeLineR(std::stringstream &myStream);
   void decomposeLineT(std::stringstream &myStream);
   void load(const std::string &fileName);
   void seperateCommonComponents(std::stringstream &myStream, std::string *commonCompItems);
   friend std::ostream &operator<<(std::ostream &os, const Circuit &cirName);
};





#endif // SPICEPROJECT_INCLUDE_SPICE_CIRCUIT_H_