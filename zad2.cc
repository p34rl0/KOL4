#include <omp.h>
#include <iostream>
using namespace std;

// Wyslij kazde wywolanie fun do odrebnego zadania (task)
// i tak zabezpiecz, zeby liczylo sie poprawnie (tzn. koncowy
// wynik byl 30)

int fun( int c ) { 
   return c+10;
}

int main () {

   int a = 0;

#pragma omp parallel num_threads(4)
{
	#pragma omp single 
{

	#pragma omp task 
   	  a = fun( a );
   	#pragma omp task 
      a = fun( a );
    #pragma omp task 
      a = fun( a );
}
   
}
cout << "a = " << a << endl;
}

