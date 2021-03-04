//SimulationSteps cpp file
#include <iostream>
#include <string>
#include <stdlib.h>
#include "SimulationSteps.h"

using namespace std;

//default constructor
SimulationSteps::SimulationSteps()
{
  calculateNeighborsCounter = 0;
}


//default destructor
SimulationSteps::~SimulationSteps()
{
}

//creates empty generation array, newgeneration array, and neighbor arrays
void SimulationSteps::createBaseArrays()
{
  generationArray = new char*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    generationArray[i] = new char[m_numCols];
  }

  newGenerationArray = new char*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    newGenerationArray[i] = new char[m_numCols];
  }

  currentNeighborArray = new float*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    currentNeighborArray[i] = new float[m_numCols];
  }
  p1_neighborArray = new float*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    p1_neighborArray[i] = new float[m_numCols];
  }
  p2_neighborArray = new float*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    p2_neighborArray[i] = new float[m_numCols];
  }

  averageNeighborArray = new float*[m_numRows];
  for (int i = 0; i < m_numRows; ++i)
  {
    averageNeighborArray[i] = new float[m_numCols];
  }
}

//sets the mode array in modes class to the generation array in this class
void SimulationSteps::setModesArray()
{
  m.createArray();
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      m.setGenerationArray(i, j, generationArray[i][j]);
    }
  }
}

//sets mode parameters to same as this class parameters
void SimulationSteps::setModesParameters()
{
  m.setNumRows(m_numRows);
  m.setNumCols(m_numCols);
}

//processes input file and reads information in to create generation array and mode array
void SimulationSteps::defaultArrayFromFile(string inputFileName)
{
  FileProcessor fp;
  fp.processFile(inputFileName);
  m_numRows = fp.getNumRows();
  m_numCols = fp.getNumCols();
  createBaseArrays();
  setModesParameters();

  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      generationArray[i][j] = fp.getArrayCell(i,j);
    }
  }

  setModesArray();

}

//prints the generation array
void SimulationSteps::printArray()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    cout << endl;
    for (int j = 0; j < m_numCols; ++j)
    {
      cout << generationArray[i][j] << " ";
    }
  }
  cout << endl << endl;
  generationTracker++;
}

//calculates neighbors using specific mode submethods
void SimulationSteps::calculateNeighbors(int gameMode)
{
  if (gameMode == 1)
  {
    calculateNeighborsClassic();
  }
  else if (gameMode == 2)
  {
    calculateNeighborsDoughnut();
  }
  else if (gameMode == 3)
  {
    calculateNeighborsMirror();
  }
  else
  {
    calculateNeighborsClassic();
  }
}

//uses modes classic method
void SimulationSteps::calculateNeighborsClassic()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      currentNeighborArray[i][j] = m.classicMode(i, j);
    }
  }
}

//uses modes doughnut method
void SimulationSteps::calculateNeighborsDoughnut()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      currentNeighborArray[i][j] = m.doughnutMode(i, j);
    }
  }
}

//uses modes mirror method
void SimulationSteps::calculateNeighborsMirror()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      currentNeighborArray[i][j] = m.mirrorMode(i, j);
    }
  }
}

//creates new generation using averages of current neighbors and past 2 generation neighbors
void SimulationSteps::createNewGenerationArray()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      if (averageNeighborArray[i][j] < 1.5)
      {
        newGenerationArray[i][j] = '-';
      }
      else if (averageNeighborArray[i][j] >= 1.5 && averageNeighborArray[i][j] <= 2.5)
      {
        newGenerationArray[i][j] = generationArray[i][j];
      }
      else if (averageNeighborArray[i][j] > 2.5 && averageNeighborArray[i][j] <= 3.5)
      {
        newGenerationArray[i][j] = 'X';
      }
      else
      {
        newGenerationArray[i][j] = '-';
      }
    }
  }
  setGenerationArray();
  set_p2Array();
  set_p1Array();
}

//sets modes generation array
void SimulationSteps::setGenerationArray()
{
  generationArray = newGenerationArray;
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      m.setGenerationArray(i, j, generationArray[i][j]);
    }
  }

}

//the next 2 methods sets past generations to current one's when they become outdated
void SimulationSteps::set_p2Array()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      p2_neighborArray[i][j] = p1_neighborArray[i][j];
    }
  }
}

void SimulationSteps::set_p1Array()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      p1_neighborArray[i][j] = currentNeighborArray[i][j];
    }
  }
}

//tests whether or not simulation is stable
bool SimulationSteps::isStable()
{
  bool isStable = false;
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      if (currentNeighborArray[i][j] == averageNeighborArray[i][j])
      {
        isStable = true;
      }
      else
      {
        isStable = false;
        break;
        break;
      }
    }
  }
  return isStable;
}

//calculates the average neighbors of past 3 generations
void SimulationSteps::calculateAverageNeighbors()
{
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      if (calculateNeighborsCounter == 0)
      {
        averageNeighborArray[i][j] = currentNeighborArray[i][j];
      }
      else if (calculateNeighborsCounter == 1)
      {
        averageNeighborArray[i][j] = (currentNeighborArray[i][j] + p1_neighborArray[i][j]) / 2.0;
      }
      else
      {
        averageNeighborArray[i][j] = (currentNeighborArray[i][j] + p1_neighborArray[i][j] + p2_neighborArray[i][j]) / 3.0;
      }
  }
}
++calculateNeighborsCounter;
}

//generates a random array using population density parameter
void SimulationSteps::generateRandomArray(float populationDensity)
{
  srand(time(NULL));
  for (int i = 0; i < m_numRows; ++i)
  {
    for (int j = 0; j < m_numCols; ++j)
    {
      float random_float = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10));
      if (random_float <= 10 * populationDensity)
      {
        generationArray[i][j] = 'X';
      }
      else
      {
        generationArray[i][j] = '-';
      }
    }
  }
  setModesArray();
}

//GETTERS/SETTERS========================================================
int SimulationSteps::getNumRows()
{
  return m_numRows;
}
int SimulationSteps::getNumCols()
{
  return m_numCols;
}
char SimulationSteps::getArrayCell(int rowIndex, int columnIndex)
{
  return generationArray[rowIndex][columnIndex];
}
void SimulationSteps::setNumRows(int numRows)
{
  m_numRows = numRows;
}
void SimulationSteps::setNumCols(int numCols)
{
  m_numCols = numCols;
}
