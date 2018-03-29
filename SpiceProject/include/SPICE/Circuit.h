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

#include <vector>
#include "SPICE/Component.h"
#include "SPICE/Node.h"
#include "SPICE/CurrentSource.h"


class Circuit {
  private:
  float step_;
  std::vector<Component> componentList_;
  std::vector<Node> nodeList_;
  public:
   void load(const std::string &fileName);
};
std::ostream &operator<<(std::ostream &os, const Circuit &cirName);

#endif // SPICEPROJECT_INCLUDE_SPICE_CIRCUIT_H_