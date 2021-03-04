//main cpp file - contains main method
#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  cout << endl << "The game of Life was designed in the 1970s by the mathematician J.H. Conway." << endl;
  cout << "The game gained popularity after appearing in a Scientific American article, and took the computing world by storm." << endl;
  cout << "The game is a simulation that models the life cycle of bacteria, providing entertainment wrapped up in what some would call mathematical elegance." << endl;
  cout << endl << "So, without further ado..." << endl;
  cout << endl << "PRESS ENTER TO RUN THE SIMULATION!";
  cin.ignore();

  Simulation s;
  s.simulate(); //runs the simulation!

  cout << endl << endl << "END OF SIMULATION! PRESS ENTER TO EXIT THE PROGRAM!";
  cin.ignore();

  cout << endl << endl;
  return 0;
}
