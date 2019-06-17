#include <omp.h>
#include <iostream>
using namespace std;

// Program sie nie kompiluje i jest niepoprawny
// Poprzez dopisanie odpowiednich klauzul w obu 
// liniach pragma spraw, zeby program sie 
// kompilowal i liczyl poprawny wynik 100 i 100

int main () {

   int i;
   const int NSIZE = 100;
   int suma1 = 0;
   int suma2 = 0;

#pragma omp parallel num_threads(40) default(none) shared(suma1,suma2)
{

#pragma omp for schedule(static,1)

   for ( i=0; i<NSIZE; ++i ) {
      suma1 = suma1 + 1;
      suma2 = suma2 + 1;
   }
}
   cout << "SUMA = " << suma1 << " i " << suma2 << endl;

}

