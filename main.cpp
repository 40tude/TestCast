#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
  auto start = high_resolution_clock::now();
  
  constexpr int NbIte = 1000000;
  for (auto i = 0; i != NbIte; ++i) {
    unsigned char rhs = 'a';
    double lhs = static_cast<double>(rhs);
    lhs = lhs;
  }

  auto end = high_resolution_clock::now();
  auto dur = duration_cast<nanoseconds>(end - start);
  cout << "Total time     : " << dur.count() << " ns" << endl;
  cout << "Time per cast  : " << dur.count()/NbIte << " ns" << endl;

  cout << "Press ENTER to quit : ";
  cin.ignore((numeric_limits<streamsize>::max)(), '\n');

}