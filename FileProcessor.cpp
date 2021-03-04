//FileProcessor cpp file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "FileProcessor.h"

using namespace std;

// //default constructor
FileProcessor::FileProcessor()
{
}

//default destructor
FileProcessor::~FileProcessor()
{
}

//method used to process input file and set array parameters in order to populate the generation array to execute the simulation
void FileProcessor::processFile(string inputFile)
{
  string string_numRows;
  string string_numCols;
  int numRows;
  int numCols;

  inputFileStream.open(inputFile);

   if (!inputFileStream.is_open())
   {
     cout << "Could not open file " << inputFile << "." << endl;
   }
   else
   {
     getline(inputFileStream, string_numRows);
     stringstream numRowsStringStream(string_numRows);
     numRowsStringStream >> numRows;
     m_numRows = numRows;
     getline(inputFileStream, string_numCols);
     stringstream numColsStringStream(string_numCols);
     numColsStringStream >> numCols;
     m_numCols = numCols;
     populateArray();
   }
   inputFileStream.close();
}

//uses parameters from input file to populate array matching what was given in input file
void FileProcessor::populateArray()
{
  generationArray = new char*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    generationArray[i] = new char[m_numCols];
  }

  string row;
  int loop = 0;
  while (getline(inputFileStream, row))
  {
    cout << endl;
    for (int i = 0; i < m_numCols; ++i)
    {
      generationArray[loop][i] = row[i];
    }
    ++loop;
  }
}

//returns character at specific index in array
char FileProcessor::getArrayCell(int rowIndex, int columnIndex)
{
  return generationArray[rowIndex][columnIndex];
}
int FileProcessor::getNumRows()
{
  return m_numRows;
}
int FileProcessor::getNumCols()
{
  return m_numCols;
}
