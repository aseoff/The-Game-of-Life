//OutputFile header file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class OutputFile
{
  public:
    //default constructor and destructor
      OutputFile();
      ~OutputFile();

    //public methods
      void openFile(string outputFileName);
      void writeToFile(char c);
      void writeToFile(int i);
      void writeToFile(string s);
      void writeNewLine();
      void closeFile();

  private:
    //member variables
      ofstream outputFileStream;
};
