//FileProcessor header file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class FileProcessor
{
  public:
    //default constructor and destructor
      FileProcessor();
      ~FileProcessor();

    //public methods
      void processFile(string inputFile);
      int getNumRows();
      int getNumCols();
      char getArrayCell(int rowIndex, int columnIndex);

  private:
    //private member variables
      int m_numRows;
      int m_numCols;
      ifstream inputFileStream;
      char** generationArray;

    //private methods
      void populateArray();
};
