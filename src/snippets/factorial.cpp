#include <iostream>
#include "gmp.h"
#include "gmpxx.h"
#include "gc.h"
#include "gmp_func.h"



void factorial(unsigned long int n, mpz_t &result){
    mpz_set_ui(result, 1);

    for (unsigned long int i = 1; i <= n; i++)
    {
        mpz_mul_ui(result, result, i);
    }
}

int main()
{
    mp_set_memory_functions(&allocate_function, 
                        &reallocate_function,
                        &deallocate_function);
    mpz_t result;
    mpz_init(result);
    factorial(10000, result);
    std::cout << "The value of result is: " << mpz_get_str(nullptr, 10, result) << std::endl;
    return 0;
}
