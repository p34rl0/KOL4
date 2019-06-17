#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>
#include<iomanip>
using namespace std;

void fun( int t ) {
  this_thread::sleep_for(chrono::milliseconds(t));
}

double start = omp_get_wtime();
double stop = omp_get_wtime();
int main () {

    // Dopisz ponizej linie mierzace czas wykonania petli
    // i wypisz wynik na koncu

    omp_set_num_threads(8);

    // tu poczatek pomiaru
     cout<< "start: "  << start<<endl;
     
    #pragma omp for 
      for (int i=0; i<20; ++i) fun(i);

     
      
    // tu koniec pomiaru
    cout<< "stop: "   << stop<<endl;
    // wypisz czas trwania cout << 
    cout << "Czas wykonywania: "<< omp_get_wtick()<<endl;

}

