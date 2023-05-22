/*
    0)
        a) Initialization
    1) Addition
    2) Subtraction
    3) Multiplication
    4) Division
    5) Exponents
    6) Integer Comparison
        a) >, <, ==
    7) Prime Check
*/

#include<iostream>
#include "gmp.h"
#include "gmpxx.h"
#include "gc.h"
#include "gmp_func.h"

int main(int argc, char const *argv[])
{
    mp_set_memory_functions(&allocate_function, 
                        &reallocate_function,
                        &deallocate_function);
    mpz_t op1, op2, op3, result;

    //Initialization
    //op1
    mpz_init(op1);
    mpz_set_str(op1, "91934875934875", 10);
    std::cout <<"op1 = " << mpz_get_str(nullptr, 10, op1) << std::endl;
    
    //op2
    const char* op2_val = "93284759328475";
    mpz_init_set_str(op2, op2_val, 10);
    std::cout <<"op2 = " << mpz_get_str(nullptr, 10, op2) << std::endl;

    //op3
    unsigned long int op3_val = 4294967283;
    mpz_init_set_ui(op3, op3_val);
    std::cout <<"op3 = " << mpz_get_str(nullptr, 10, op3) << std::endl;

    //result
    mpz_init(result);
    std::cout <<"result = " << mpz_get_str(nullptr, 10, result) << std::endl;

    //Addition
    mpz_add(result, op1, op2); // Also supports between a mpz_t and unsigned long int
    std::cout << "Result after addition: " << mpz_get_str(nullptr, 10, result) << std::endl;

    //Subtraction
    mpz_sub(result, op1, op2);
    std::cout << "Result after Subtraction: " << mpz_get_str(nullptr, 10, result) << std::endl;

    //Multiplication
    mpz_mul(result, op1, op2);
    std::cout << "Result after Multiplication: " << mpz_get_str(nullptr, 10, result) << std::endl;

    //Division
    mpz_div(result, op1, op2);
    std::cout << "Result after Division: " << mpz_get_str(nullptr, 10, result) << std::endl;

    //Exponents
    mpz_pow_ui(result, op1, 2);
    std::cout << "Result after Exponents: " << mpz_get_str(nullptr, 10, result) << std::endl;

    //Integer Comparison
    if(mpz_cmp(op1, op2) > 0){
        std::cout << "op1 is greater than op2" << std::endl;
    }
    else if(mpz_cmp(op1, op2) < 0){
        std::cout << "op1 is less than op2" << std::endl;
    }
    else{
        std::cout << "op1 is equal to op2" << std::endl;
    }

    // prime check
    if(mpz_probab_prime_p(op3, 25) > 0){
        std::cout << "op3 is prime" << std::endl;
    }
    else{
        std::cout << "op3 is not prime" << std::endl;
    }
    return 0;
}
