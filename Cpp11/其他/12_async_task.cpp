
#include <future>
#include <cmath>
#include <iostream>
using namespace std;


static const int MAX = 10e8;
static double sum = 0;

void worker(int min, int max) {
  for (int i = min; i <= max; i++) {
    sum += sqrt(i);
  }
}

int main() {
  sum = 0;
  auto f1 = async(worker, 0, MAX);
  cout << "Async task triggered" << endl;
  f1.wait();
  cout << "Async task finish, result: " << sum << endl << endl;
}
