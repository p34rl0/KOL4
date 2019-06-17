#include <omp.h>
#include <iostream>
#include <thread>
using namespace std;

int main () {

  // Wynik koncowy to 5, bo kazdy watek dostaje kopie i
  // Zamien zatem firstprivate na cos innego tak, zeby
  // koncowy wynik byl 10

  int i = 5, j;

  #pragma omp parallel for num_threads(8) shared(i)
     for ( j=0; j<5; ++j ) {
         this_thread::sleep_for(100ms);
         i = i + 1;
     }

  cout << "i = " << i << endl;
}

