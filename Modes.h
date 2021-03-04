//Modes header file
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Modes
{
  public:
  //default constructor and destructor
    Modes();
    ~Modes();

  //public methods
    float classicMode(int rowIndex, int columnIndex);
    float doughnutMode(int rowIndex, int columnIndex);
    float mirrorMode(int rowIndex, int columnIndex);
    void createArray();
    void setGenerationArray(int rowIndex, int columnIndex, char c);

  //setters
    void setNumRows(int numRows);
    void setNumCols(int numCols);


  private:
  //private member variables
    int m_numRows;
    int m_numCols;
    char** generationArray;

  //private methods
    void neighborTester(char status, float& numberOfNeighbors);
};
