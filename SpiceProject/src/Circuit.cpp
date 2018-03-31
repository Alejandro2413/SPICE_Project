/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */

#include <vector>
#include <string>
#include <sstream>
#include <ifstream>
#include "SPICE/Circuit.h"





void Circuit::load(const std::string &fileName) {
  //open the file
  ifstream inputData(fileName);
  string tempString;
  stringstream tempSS;
  string holders[3];
  do {
    //get the line
    std::getline(inputData, tempString);
    //convert tempString into a stringStreaam
    //should hold the whole line
    tempSS.str(tempString);
    switch(tempSS.peek()) {
      case'.' :
        //we have a time value, 
        decomposeLineT(tempSS);
        break;
      case 'R' :
      case 'r' : 
        decomposeLineR(tempSS);
        break;
      case 'I' :
      case 'i' :
        decomposeLineS(tempSS);
      }

  } while (!(inputData.fail()));
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

friend void decomposeLineS(const std::stringstream &myStream) {
  //this is the function called when we have a current source
  //we want to get the common values (from a function, and store them in an array)
  string hold3Strings[3];
  seperateCommonComponents(myStream, hold3Strings);
  //now we call the constructor, and pop it onto the component list vector
  componentList_.pop_back( new CurrentSource (hold3Strings, myStream, nodeList_));
}

friend void decomposeLineR(const std::stringstream &myStream) {
  //this is the function called when we have a current source
  //we want to get the common values (from a function, and store them in an array)
  string hold3Strings[3];
  seperateCommonComponents(myStream, hold3Strings);
  //now we call the constructor, and pop it onto the component list vector
  componentList_.pop_back( new Resistor (hold3Strings, myStream, nodeList_));
}

friend void decomposeLineT(const std::stringstream &myStream) {
  myStream >> cirTime.Name_;
  std::string tempString;
  myStream >> tempString;
  cirTime.step_ = getValueFromString(tempString, cirTime.stepSuff_);
  tempString ="";
  myStream >> tempString;
  cirTime.stop_ = getValueFromString(tempString, stopSuff_);
  
}

std::ostream &operator<<(std::ostream &os, const Circuit &cirName) {
  //output components
  os << "Components " << endl;
  //loop through every component and output it
  for (int i = 0; i < componentList_.size(); i++) {
    os << *(componentList_[i]) << endl;
  }
  //now output all the Nodes
  os << "Nodes : "
  for (const auto &myPair : nodeList_){
    os << myPair.first << " "<< myPair.second;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const Node &n) {
  os << *(n.PosComp).name_ << ":P ";
  os << *(n.NegativeComp).name_ << ":N"
  return os;
}