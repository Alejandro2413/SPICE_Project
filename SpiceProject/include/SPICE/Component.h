/***
 * David Mercanti
 * 
 * Copyright 2018
 * 
 */

#ifndef SPICEPROJECT_INCLUDE_SPICE_COMPONENT_H_
#define SPICEPROJECT_INCLUDE_SPICE_COMPONENT_H_

#include <string>


class Component {
  //CompType thisType_;
  /*store two connecting nodes*/
  Node topeNode_;
  Node bottomNode_;
  std::string name_;
  
};

#endif // SPICEPROJECT_INCLUDE_SPICE_COMPONENT_H_