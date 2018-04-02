/***
 * David Mercanti
 * 
 * Copyright 2018
 * The circuit class which holds the
 * circuit. It also needs to read the circuit from the file
 * 
 */




#ifndef SPICEPROJECT_INCLUDE_SPICE_CIRCUITLIBS_H_
#define SPICEPROJECT_INCLUDE_SPICE_CIRCUITLIBS_H_
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include <iostream>

typedef enum {NONE,PICO,NANO,MICRO,MILLI,KILO,MEGA} Suffix;

typedef struct timeStruct {
  std::string Name_;
  int step_;
  int stop_;
  Suffix stepSuff_;
  Suffix stopSuff_;
}timeStruct;

typedef struct Node  {
  std::string PosCompName;
  std::string NegativeCompName;
}Node;

std::ostream &operator<<(std::ostream &os, Node &n);
std::ostream &operator<<(std::ostream &os, Suffix &mySuff);
int getValueFromString(std::string myString, Suffix &mySuff);





#endif //SPICEPROJECT_INCLUDE_SPICE_CIRCUITLIBS_H_