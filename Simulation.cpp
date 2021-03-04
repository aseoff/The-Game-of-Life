//Simulation cpp file
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include "Simulation.h"

using namespace std;

//default constructor
Simulation::Simulation()
{
}
//default destructor
Simulation::~Simulation()
{
}

//public method that runs entire simulation meeting all of the outlined requirements
void Simulation::simulate()
{
  getConfigurationType();
  configurationSetUp();
  getBoundaryMode();
  getSimulationPreference();
  runSimulationPreference();
}

//PRIVATE METHODS------------------

//pauses program for specified duration
void Simulation::pause(int duration)
{
int temp = time(NULL) + duration;

while(temp > time(NULL));
}

//prompts for configuration type and stores accordingly
void Simulation::getConfigurationType()
{
  cout << endl << "Select a configuration type:" << endl << endl;
  cout << "1) Random (default option)" << endl;
  cout << "2) From a file" << endl;
  cout << endl << "-> ";
  cin >> configurationType;
}

//sets up parameters for random configuration type
void Simulation::randomConfigurationSetUp()
{
  int numRows;
  cout << endl << "Enter number of rows: " << endl;
  cout << endl << "-> ";
  cin >> numRows;
  int numCols;
  cout << endl << "Enter number of columns: " << endl;
  cout << endl << "-> ";
  cin >> numCols;

  float populationDensity;
  cout << endl << "Enter decimal value between 0 and 1 to represent initial population density: " << endl;
  cout << endl << "-> ";
  cin >> populationDensity;

  ss.setNumRows(numRows);
  ss.setNumCols(numCols);
  ss.createBaseArrays();
  ss.setModesParameters();
  ss.generateRandomArray(populationDensity);
}

//sets up details for the file configuration option
void Simulation::fileConfigurationSetUp()
{
  cout << endl << "Enter name of input file: " << endl;
  cout << endl << "-> ";
  cin >> inputFileName;
  ss.defaultArrayFromFile(inputFileName);
}

//sets up configuration details using sub methods
void Simulation::configurationSetUp()
{
  if (configurationType == 1)
  {
    randomConfigurationSetUp();
  }
  else if (configurationType == 2)
  {
    fileConfigurationSetUp();
  }
  else
  {
    randomConfigurationSetUp();
  }
}

//prompts and stores boundary mode
void Simulation::getBoundaryMode()
{
  cout << endl << "Select a boundary mode:" << endl << endl;
  cout << "1) Classic (default option)" << endl;
  cout << "2) Doughnut" << endl;
  cout << "3) Mirror" << endl;
  cout << endl << "-> ";
  cin >> boundaryMode;
}

//prompts and stores simulation preference
void Simulation::getSimulationPreference()
{
  cout << endl << "Select a simulation type:" << endl << endl;
  cout << "1) Pause between each generation" << endl;
  cout << "2) Press enter key to view next generation" << endl;
  cout << "3) Output simulation to a file (default option)" << endl;
  cout << endl << "-> ";
  cin >> simulationPreference;
}

//simulation that pauses each generation
void Simulation::pauseSimulation()
{
  int counter = 0;
  cout << endl;
  while (!ss.isStable() || counter < 2)
  {
    pause(2);
    cout << "GENERATION " << counter << ": " << endl;
    ss.printArray();
    ss.calculateNeighbors(boundaryMode);
    ss.calculateAverageNeighbors();
    ss.createNewGenerationArray();
    ++counter;
  }
}

//simulation that prints new generation on enter key
void Simulation::enterKeySimulation()
{
  int counter = 0;
  while (!ss.isStable() || counter < 2)
  {
    cin.ignore();
    cout << endl << endl << "GENERATION " << counter << ": " << endl;
    ss.printArray();
    ss.calculateNeighbors(boundaryMode);
    ss.calculateAverageNeighbors();
    ss.createNewGenerationArray();
    ++counter;
    cout << "Press enter to view next generation!";
  }
}

//simulation that outputs information to text file
void Simulation::outputFileSimulation(string outputFileName)
{
  int counter = 0;
  OutputFile of;
  of.openFile(outputFileName);

  while (!ss.isStable() || counter < 2)
  {
    if (counter != 0)
    {
      of.writeNewLine();
    }
    of.writeToFile("GENERATION ");
    of.writeToFile(counter);
    of.writeToFile(": ");
    for (int i = 0; i < ss.getNumRows(); ++i)
    {
      of.writeNewLine();
      for (int j = 0; j < ss.getNumCols(); ++j)
      {
        of.writeToFile(ss.getArrayCell(i, j));
      }
    }

    of.writeNewLine();
    ss.calculateNeighbors(boundaryMode);
    ss.calculateAverageNeighbors();
    ss.createNewGenerationArray();
    ++counter;
  }

  of.closeFile();
}

//runs simulation using preference sub methods
void Simulation::runSimulationPreference()
{
  if (simulationPreference == 1)
  {
    pauseSimulation();
  }
  else if (simulationPreference == 2)
  {
    enterKeySimulation();
  }
  else
  {
    cout << endl << "Enter name of output file: " << endl;
    cout << endl << "-> ";
    cin >> outputFileName;
    outputFileSimulation(outputFileName);
  }
}
