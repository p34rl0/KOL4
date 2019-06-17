#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int fun( int t ) {
  this_thread::sleep_for(chrono::seconds(1));
  return t+1;
}

// W bloku rownoleglym pierwsza linia ma byc wykonana
// przez watek glowny, a druga linia przez dowolny
// watek ale tylko jeden. Druga linia musi poczekac
// na wynik z pierwsze linii

int a = 0;

int main () {
 
#pragma omp parallel num_threads(8)
{
   #pragma omp master
   a = fun(10); // to ma byc wykonane przez watek glowny
   #pragma omp barrier
   #pragma omp single
   cout<<"watek drugiej lini to :" << omp_get_thread_num() <<endl;
   a = fun(a); // to ma byc wykonane przez jeden (dowolny) watek
   
}

   cout << "a = " << a << endl;
}


