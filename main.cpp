#include <chrono>  // for time
#include <cstdlib> // for std::atoi
#include <iostream>
#include <thread> // for threads obviously lol

using namespace std;

void timer(int minutes) {
  this_thread::sleep_for(chrono::milliseconds(minutes * 60 * 1000));
  cout << "timer has finished" << endl;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "There are either to few or to many arguments (2 needed)" << endl;
    return 1;
  }

  try {
    float minutes_f = stof(argv[1]);
    int minutes = static_cast<int>(minutes_f);

    if (minutes < 0) {
      cout << "es muss sich im eine positive Zahl handeln" << endl;
      return 1;
    }

    // Start thread with timer
    thread t1([minutes]() { timer(minutes); });

    /*
    for (int x = 0; x <= 1000; x++) {
      cout << x << endl;
    }
    */
    float progress = 0.0;
    while (progress < 1.0) {
      int barWidth = 70;

      std::cout << "[";
      int pos = barWidth * progress;
      for (int i = 0; i < barWidth; ++i) {
        if (i < pos)
          std::cout << "=";
        else if (i == pos)
          std::cout << ">";
        else
          std::cout << " ";
      }
      std::cout << "] " << int(progress * 100.0) << " %\r";
      std::cout.flush();

      progress += 0.16; // for demonstration only
    }
    std::cout << std::endl;
    t1.join();

  } catch (const invalid_argument &e) {
    cout << e.what() << endl;
    return 1;
  } catch (const out_of_range &e) {
    cout << e.what() << endl;
    return 1;
  }

  return 0;
}
