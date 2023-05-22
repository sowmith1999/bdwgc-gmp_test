#include <iostream>
#include "gmp.h"
#include "gmpxx.h"
#include "gc.h"
#include "gmp_func.h"

void fibonacci(unsigned long int n, mpz_t &result){
    if(n<= 1){
        mpz_set_ui(result, n);
        return;
    }
    mpz_t previous, next;
    mpz_init(next);
    mpz_init_set_ui(previous,0);
    mpz_init_set_ui(result,1);
    for (unsigned long int i = 2; i <= n; i++)
    {
        mpz_add(next, result, previous);
        mpz_set(previous, result);
        mpz_set(result, next);
    }

}

int main()
{
    mp_set_memory_functions(&allocate_function, 
                            &reallocate_function,
                            &deallocate_function);
    mpz_t result;
    mpz_init(result);
    fibonacci(499, result);
    std::cout << mpz_get_str(nullptr, 10, result) << std::endl;
    return 0;
}
