/** Copyright 2018
 * David Mercanti
 * Alejandro Martinez
 * 
 * */

#include "SPICE/Circuit.h"

void Circuit::seperateCommonComponents(std::stringstream &myStream, std::string *commonCompItems ){
  std::string tempString;
  for (int i = 0; i < 3; i ++) {
    myStream >> tempString;
    commonCompItems[i] = tempString;
    tempString = "";

  }

}

std::ostream &operator<<(std::ostream &os, Node n) {
  os << n.PosCompName << ":P ";
  os << n.NegativeCompName << ":N ";
  return os;
}

void Circuit::decomposeLineS(std::stringstream &myStream) {
  //this is the function called when we have a current source
  //we want to get the common values (from a function, and store them in an array)
  std::string hold3Strings[3];
  seperateCommonComponents(myStream, hold3Strings);
  //now we call the constructor, and pop it onto the component list vector
  currentSourceList_.push_back( new CurrentSource (hold3Strings, myStream, nodeList_));
}

void Circuit::decomposeLineR(std::stringstream &myStream) {
  //this is the function called when we have a current source
  //we want to get the common values (from a function, and store them in an array)
  std::string hold3Strings[3];
  seperateCommonComponents(myStream, hold3Strings);
  //now we call the constructor, and pop it onto the component list vector
  resistorList_.push_back( new Resistor (hold3Strings, myStream, nodeList_));
}

void Circuit::decomposeLineT(std::stringstream &myStream) {
  myStream >> cirTime.Name_;
  std::string tempString;
  myStream >> tempString;
  cirTime.step_ = getValueFromString(tempString, cirTime.stepSuff_);
  tempString ="";
  myStream >> tempString;
  cirTime.stop_ = getValueFromString(tempString, cirTime.stopSuff_);
  
}


void Circuit::load(const std::string &fileName) {
  //open the file
 // std::cout << "entering load";
  std::ifstream inputData(fileName);
  std::string tempString;
  std::stringstream tempSS;
  std::string holders[3];
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


std::ostream &operator<<(std::ostream &os, const Circuit &cirName) {
  //output components

  os << "Components " << std::endl;
  //loop through every component and output it
  for (int i = 0; i < cirName.resistorList_.size(); i++) {
    os << *(cirName.resistorList_[i]) << std::endl;
  }
  for (int b = 0; b < cirName.currentSourceList_.size(); b++) {
    os << *(cirName.currentSourceList_[b]) << std::endl;
  }
  //now output all the Nodes
  os << "Nodes : ";
  for (const auto &myPair : cirName.nodeList_){
    os << myPair.first << " "<< myPair.second << std::endl;
  }
  return os;
}
