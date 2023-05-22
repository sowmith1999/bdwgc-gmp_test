#include<iostream>
#include "gmp.h"
#include "gmpxx.h"
#include "gc.h"
#include "gmp_func.h"

// passing mpz_t to functions
void add1(mpz_t &num){
    mpz_add_ui(num, num, 1);
}

// Passing array to functions
void mul1_array(mpz_t* nums){
    for (int i = 0; i < 5; i++)
    {
        mpz_mul_ui(nums[i],nums[i],2);
        std::cout << "Numbers : " << mpz_get_str(nullptr, 10, nums[i]) << std::endl;
    }
    
}


int main(int argc, char const *argv[])
{
    mp_set_memory_functions(&allocate_function, 
                        &reallocate_function,
                        &deallocate_function);
    // Array Initialization
    mpz_t nums[5];

    for(unsigned long int i=0; i<5; i++){
        mpz_init(nums[i]);
        mpz_set_ui(nums[i], i+1);
    }

    //Printing the array elements
    for(int i=0; i<5; i++){
        add1(nums[i]);
        std::cout << "Numbers : " << mpz_get_str(nullptr, 10, nums[i]) << std::endl;
    }
    mul1_array(nums);
}                        