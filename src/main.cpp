#include <iostream>
#include "gmp.h"
#include "gmpxx.h"
#include "gc.h"
#include <assert.h>
#include <stdio.h>

using namespace std;

int main ()
{
    mpz_class p, q, r;

    p = "12345698347598234759837459837459239458723947589234758293475829347589234759234759324758";
    q = "-56789894752374859832745983745983745987324958732495872349583";
    r = p*q;
    cout << "sum is " << r << "\n";
    cout << "Hello World!" << endl;
    int i;

  GC_INIT();	/* Optional on Linux/X86; see below.  */
  for (i = 0; i < 10000000; ++i)
   {
     int **p = (int **) GC_MALLOC(sizeof(int *));
     int *q = (int *) GC_MALLOC_ATOMIC(sizeof(int));
     assert(*p == 0);
     *p = (int *) GC_REALLOC(q, 2 * sizeof(int));
     if (i % 100000 == 0)
       printf("Heap size = %d\n", GC_get_heap_size());
   }
  return 0;
}