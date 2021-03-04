//OutputFile cpp file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "OutputFile.h"

using namespace std;

//default constructor
OutputFile::OutputFile()
{
}

//default destructor
OutputFile::~OutputFile()
{
}

//opens the output file stream
void OutputFile::openFile(string outputFileName)
{
  outputFileStream.open(outputFileName);
  if (!outputFileStream.is_open())
  {
    cout << "Could not open file " << outputFileName << "!" << endl;
  }
}

//closes the output file stream
void OutputFile::closeFile()
{
  outputFileStream.close();
}

//next 3 methods are the same with different parameter types - they write in input parameter to output file
void OutputFile::writeToFile(char c)
{
  outputFileStream << c;
}
void OutputFile::writeToFile(int i)
{
  outputFileStream << i;
}
void OutputFile::writeToFile(string s)
{
  outputFileStream << s;
}

//writes a new line in the output file
void OutputFile::writeNewLine()
{
  outputFileStream << endl;
}
