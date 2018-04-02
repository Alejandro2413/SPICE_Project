#include <iostream>
#include <fstream>
#include "SPICE/circuitLibs.h"
#include "SPICE/Component.h"
#include "SPICE/CurrentSource.h"
#include "SPICE/Resistor.h"
#include "SPICE/Circuit.h"




int main(int argc, char **argv) {
  //we call load
  //create a new circuit object
  std::cout << "hello" << std::endl;
  std::string fileName = "input.txt";
  std::ofstream out("output.txt");
  out << "hello";
  Circuit *newCir = new Circuit (fileName);
  std::cout << *(newCir);

  return 0;
}