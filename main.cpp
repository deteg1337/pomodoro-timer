#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

int main (int argc, char *argv[]) {
  if (argc < 2) {
    cout << "There has to be an argument!" << endl;
    return 0;
  }
  if (argc > 2) {
    cout << "There are too many arguments!" << endl;
    return 0;
  }
  cout << stof(argv[1]) << endl;
  int minutes = atof(argv[1]);
  this_thread::sleep_for(chrono::milliseconds(minutes*60*1000));
  cout << "timer has finished" << endl;
  return 0;
}
