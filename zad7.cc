#include <omp.h>
#include <iostream>
#include <string>
using namespace std;

int main () {

string buf;
char c = 'a';
omp_lock_t blokuj;
omp_init_lock(&blokuj);

// Stworz i zainicjalizuj obiekt typu omp_lock_t
// Nastepnie zabezpiecz za jego pomoca
// operacje w sekcjach, na koniec 
// zwolnij zasoby obiektu omp_lock_t

#pragma omp parallel num_threads(2)
{
    #pragma omp sections nowait
    {
       #pragma omp section
       {
       	  omp_set_lock(&blokuj);
          buf += c++;
          omp_unset_lock(&blokuj);
       }

       #pragma omp section
       {
       	 omp_set_lock(&blokuj);
         buf += c++;
         omp_unset_lock(&blokuj);
       }
    }  
}  

cout << buf << endl;
}
