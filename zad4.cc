#include <omp.h>
#include <iostream>
#include <thread>
using namespace std;

// Zabezpiecz dzialanie programu tak
// zeby nie bylo data race i wynik byl
// poprawny (tzn 6)

int fun(int c) {
   this_thread::sleep_for(1s);
   return c+2;
}

int main () {

   int a = 0;
#pragma omp parallel num_threads(8) 
{

   #pragma omp parallel sections shared(a)
   {
      #pragma omp section 
	  a = fun(a);
      #pragma omp section
      a = fun(a);
      #pragma omp section
      a = fun(a);

   }

}


cout << "a = " << a << flush <<endl;

}
