// Release  : 855 ns      => 0 ns per loop
// Debug    : 9136413 ns  => 9 ns per loop

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
  
  constexpr int           NbIte = 1000000;
  constexpr unsigned char rhs = 'a';

  auto Start = high_resolution_clock::now();
    double lhs;                                                                 // lhs declared outside the for loop on purpose
    for (auto i = 0; i != NbIte; ++i) {
      lhs = static_cast<double>(rhs);
    }
  auto End = high_resolution_clock::now();
  auto Bench = duration_cast<nanoseconds>(End - Start);
  
  cout << lhs << endl;                                                          // make sure the optimizer really update lhs in the for loop
                                                                                // I'm not even sure it does what I really want because this guy is pretty smart :-)
  
  cout << "Total time     : " << Bench.count() << " ns" << endl;
  cout << "Time per cast  : " << Bench.count()/NbIte << " ns" << endl;

  cout << "Press ENTER to quit : ";
  cin.ignore((numeric_limits<streamsize>::max)(), '\n');                        // avoid getchar()

}