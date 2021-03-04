//Simulation header file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "SimulationSteps.h"
#include "OutputFile.h"

using namespace std;

class Simulation
{
  public:
  //default constructor and destructor
    Simulation();
    ~Simulation();

  //public methods
    void simulate();

  private:
  //private member variables
    SimulationSteps ss;
    ofstream outputFileStream;
    int configurationType;
    int boundaryMode;
    int simulationPreference;
    string inputFileName;
    string outputFileName;

  //private methods
    void pause(int duration);
    void getConfigurationType();
    void randomConfigurationSetUp();
    void fileConfigurationSetUp();
    void configurationSetUp();
    void getBoundaryMode();
    void getSimulationPreference();
    void pauseSimulation();
    void enterKeySimulation();
    void outputFileSimulation(string outputFileName);
    void runSimulationPreference();
};
