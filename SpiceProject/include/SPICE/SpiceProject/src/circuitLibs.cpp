/***
 * David Mercanti
 * 
 * Copyright 2018
 * 
 */

#include "SPICE/circuitLibs.h"



std::ostream &operator<<(std::ostream &os, Node &n) {
  os << n.PosCompName << ":P ";
  os << n.NegativeCompName << ":N ";
  return os;
}



std::ostream &operator<<(std::ostream &os, Suffix &mySuff) {
  switch (mySuff) {
    case NONE :
      return os; //do nothing
    case PICO :
      os << "e-12";
      return os;
    case NANO :
      os << "e-9";
      return os;
    case MICRO :
      os << "e-6";
      return os;
    case MILLI :
      os << "e-3";
    case KILO :
      os << "e3";
      return os;
    case MEGA :
      os << "e6";
      return os;
  }
}

int getValueFromString(std::string myString, Suffix &mySuff) {
  //returns the int value from a string and allocates if suffix, if need be
  std::stringstream tempSs;
  tempSs.str(myString);
  int retFloat;
  tempSs >> retFloat;
  switch (tempSs.peek()) {
    case EOF:
      mySuff = NONE;
      return retFloat;
    case 'p' :
    case 'P' :
      mySuff = PICO;
      return retFloat;
    case 'n' :
    case 'N' :
      mySuff = NANO;
      return retFloat;
    case 'u' :
    case 'U' :
      mySuff = MICRO;
      return retFloat;
    case 'k' :
    case 'K' :
      mySuff = KILO;
      return retFloat;
    case 'm' :
    case 'M' :
      //obsurity between milli and Mega
      tempSs >> myString;
      if (myString == "meg") {
        //mega
        mySuff = MEGA;
      } else {
        mySuff = MILLI;
      }
      return retFloat;
    default:
      return retFloat;
  }

}