//SimulationSteps header file
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Modes.h"
#include "FileProcessor.h"

using namespace std;

class SimulationSteps
{
  public:
  //default constructor and destructor
    SimulationSteps();
    ~SimulationSteps();

  //public methods
    void createBaseArrays();
    int getNumRows();
    int getNumCols();
    char getArrayCell(int rowIndex, int columnIndex);
    void setNumRows(int numRows);
    void setNumCols(int numCols);
    void setModesParameters();
    void defaultArrayFromFile(string inputFileName);
    void printArray();
    void calculateNeighbors(int gameMode);
    void createNewGenerationArray();
    void calculateAverageNeighbors();
    bool isStable();
    void generateRandomArray(float populationDensity);
    void setGenerationArray();

  private:
  //member variables
    int calculateNeighborsCounter;
    int m_numRows;
    int m_numCols;
    Modes m;
    char** generationArray;
    char** newGenerationArray;
    float** currentNeighborArray;
    float** p1_neighborArray;
    float** p2_neighborArray;
    float** averageNeighborArray;
    int* generationTracker;

    //private methods
    void setModesArray();
    void set_p2Array();
    void set_p1Array();
    void calculateNeighborsClassic();
    void calculateNeighborsDoughnut();
    void calculateNeighborsMirror();
};
