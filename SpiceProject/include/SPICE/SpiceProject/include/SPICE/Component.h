/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */

#ifndef SPICEPROJECT_INCLUDE_SPICE_COMPONENT_H_
#define SPICEPROJECT_INCLUDE_SPICE_COMPONENT_H_

/*#include <string>
#include <map> */
#include "SPICE/circuitLibs.h"



/*components are only ever going to be inherited from
 *so it will not need constructors or anything of the sort
 * 
 * */

class Component {
  //CompType thisType_;
  /*store two connecting nodes*/
  public:
    std::string name_;
    explicit Component(const std::string *similiarNames, std::map<std::string, Node> &myMap);
  
};

#endif // SPICEPROJECT_INCLUDE_SPICE_COMPONENT_H_

