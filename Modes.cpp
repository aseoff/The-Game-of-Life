//Modes cpp file
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Modes.h"

using namespace std;

//default constructor
Modes::Modes()
{
}

//default destructor
Modes::~Modes()
{
}

//creates empty array to work with in the modes class
void Modes::createArray()
{
  generationArray = new char*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    generationArray[i] = new char[m_numCols];
  }
}

//MODES AND GETTERS/SETTERS========================================================
//returns number of neighbors for a cell location based on classic rules
float Modes::classicMode(int rowIndex, int columnIndex)
{
  float numberOfNeighbors = 0;
  if (rowIndex == 0)
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
    }
    else
    {
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);

    }
  }

  else if (rowIndex == m_numRows - 1)
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);

    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);

    }
    else
    {
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);

    }
  }
  else
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);

    }
    else
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors); //test 0,0
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors); //test 0,1
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors); //test 0,2
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors); //test 1,0
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors); //test 1,2
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors); //test 2,0
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors); //test 2,1
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors); //test 2,2

    }
  }

  return numberOfNeighbors;

}

//returns number of neighbors for a cell location based on doughnutMode rules
float Modes::doughnutMode(int rowIndex, int columnIndex)
{
  float numberOfNeighbors = 0;
  if (rowIndex == 0)
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors); //test 0,1 .
      neighborTester(generationArray[rowIndex][m_numCols - 1], numberOfNeighbors); //test 0, m_numCols-1.
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors); //test 1,0 .
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors); //test 1,1 .
      neighborTester(generationArray[rowIndex + 1][columnIndex + m_numCols - 1], numberOfNeighbors); //test 1,m_numCols-1
      neighborTester(generationArray[m_numRows - 1][columnIndex], numberOfNeighbors); //test m_numRows-1,0
      neighborTester(generationArray[m_numRows - 1][columnIndex + 1], numberOfNeighbors); //test m_numRows-1,1
      neighborTester(generationArray[m_numRows - 1][m_numCols - 1], numberOfNeighbors); //test m_numRows-1,m_numCols-1
    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex][m_numCols - 2], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][m_numCols - 2], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][m_numCols - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][0], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][0], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][0], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][m_numCols - 2], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][m_numCols - 1], numberOfNeighbors);
    }
    else
    {
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][columnIndex + 1], numberOfNeighbors);
    }
  }
  else if (rowIndex == m_numRows - 1)
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[0][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[0][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[0][m_numCols - 1], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 2][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 2][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 2][m_numCols - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][m_numCols - 1], numberOfNeighbors);
    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[0][0], numberOfNeighbors);
      neighborTester(generationArray[0][m_numCols - 2], numberOfNeighbors);
      neighborTester(generationArray[0][m_numCols - 1], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 2][0], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][m_numCols - 2], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][m_numCols - 1], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][0], numberOfNeighbors);
      neighborTester(generationArray[m_numRows - 1][m_numCols - 2], numberOfNeighbors);
    }
    else
    {
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[0][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[0][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[0][columnIndex + 1], numberOfNeighbors);
    }
  }
  else
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][m_numCols - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][m_numCols - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][m_numCols - 1], numberOfNeighbors);
    }

    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][0], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][0], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][0], numberOfNeighbors);
    }
    else
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
    }
  }

  return numberOfNeighbors;
}

//returns number of neighbors for a cell location based on mirrorMode rules
float Modes::mirrorMode(int rowIndex, int columnIndex)
{
  float numberOfNeighbors = 0;
  if (rowIndex == 0)
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);

    }
    else
    {
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
    }
  }
  else if (rowIndex == m_numRows - 1)
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);

    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
    }
    else
    {
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
    }
  }
  else
  {
    if (columnIndex == 0)
    {
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors);
    }
    else if (columnIndex == m_numCols - 1)
    {
      neighborTester(generationArray[rowIndex][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors);
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors);
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors);
    }
    else
    {
      neighborTester(generationArray[rowIndex - 1][columnIndex - 1], numberOfNeighbors); //test 0,0
      neighborTester(generationArray[rowIndex - 1][columnIndex], numberOfNeighbors); //test 0,1
      neighborTester(generationArray[rowIndex - 1][columnIndex + 1], numberOfNeighbors); //test 0,2
      neighborTester(generationArray[rowIndex][columnIndex - 1], numberOfNeighbors); //test 1,0
      neighborTester(generationArray[rowIndex][columnIndex + 1], numberOfNeighbors); //test 1,2
      neighborTester(generationArray[rowIndex + 1][columnIndex - 1], numberOfNeighbors); //test 2,0
      neighborTester(generationArray[rowIndex + 1][columnIndex], numberOfNeighbors); //test 2,1
      neighborTester(generationArray[rowIndex + 1][columnIndex + 1], numberOfNeighbors); //test 2,2
    }
  }
  return numberOfNeighbors;
}

//used within the modes methods to check if cell is occupied or not, then increases number of neighbors accordingly
void Modes::neighborTester(char status, float& numberOfNeighbors) //tests 8 neighbor locations and returns number occupied
{
  if (status == 'X')
  {
    ++numberOfNeighbors;
  }
}

void Modes::setNumRows(int numRows)
{
  m_numRows = numRows;
}

void Modes::setNumCols(int numCols)
{
  m_numCols = numCols;
}

//sets the generation array to character specified in parameter
void Modes::setGenerationArray(int rowIndex, int columnIndex, char c)
{
  generationArray[rowIndex][columnIndex] = c;
}
