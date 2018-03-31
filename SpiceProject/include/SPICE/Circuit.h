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
#include <string>
#include <sstream>
#include <map>

#include "SPICE/Component.h"
#include "SPICE/CurrentSource.h"
#include "SPICE/Reisitor.h"

typedef enum {NONE,PICO,NANO,MICRO,MILLI,KILO,MEGA} Suffix;

typedef struct timeStruct {
  string Name_;
  int step_;
  int stop_;
  Suffix stepSuff_;
  Suffix stopSuff_;
} timeStruct;


typedef struct Node  {
  Component *PosComp;
  Component *NegativeComp;
} Node;
std::ostream& operator<<(std::ostream &os, Node &n);

class Circuit {
  private:
  float step_;
  std::vector<*Component> componentList_;
  std::map<std::String, Node> nodeList_;
  timeStuct cirTime;
  public:
   void load(const std::string &fileName);
   friend void decomposeLineS(const std::stringstream &myStream);
   friend void decomposeLineR(const std::stringstream &myStream);
   friend void decomposeLineT(const std::stringstream &myStream);
   void seperateCommonComponents(const std::stringStream, std::string *commonCompItems);
};
std::ostream &operator<<(std::ostream &os, const Circuit &cirName);
std::ostream &operator<<(std::ostream &os, Suffix &mySuff);
int getValueFromString(std::string myString, Suffix &mySuff);


#endif // SPICEPROJECT_INCLUDE_SPICE_CIRCUIT_H_