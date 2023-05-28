#include <iostream>
#include "gmp.h"
#include "gmpxx.h"
#include "gc.h"
#include "gmp_func.h"
#include <stdio.h>
#include <bits/stdc++.h>

std::string decimalToBinary(int n)
{
    // finding the binary form of the number and
    // converting it to string.
    std::string s = std::bitset<64>(n).to_string();

    // Finding the first occurrence of "1"
    // to strip off the leading zeroes.
    const auto loc1 = s.find('1');

    if (loc1 != std::string::npos)
        return s.substr(loc1);
    // return s;

    return "0";
}

void *addTag(mpz_t mpz_obj, int tag)
{
    void *new_ptr;
    new_ptr = reinterpret_cast<void *>(reinterpret_cast<intptr_t>(mpz_obj) | tag);

    return new_ptr;
}

mpz_t *getPtr(void *mpz_obj)
{
    intptr_t tagMask = 7;
    intptr_t pointerMask = ~tagMask;
    mpz_t *new_ptr = reinterpret_cast<mpz_t *>(reinterpret_cast<intptr_t>(mpz_obj) & pointerMask);
    return new_ptr;
}

int getTag(void *mpz_obj)
{
    intptr_t tagMask = 7;
    int tag = reinterpret_cast<intptr_t>(mpz_obj) & tagMask;
    return tag;
}

int main()
{
    mp_set_memory_functions(&allocate_function,
                            &reallocate_function,
                            &deallocate_function);

    // mpz_t num;
    // mpz_init(num);
    // mpz_set_ui(num, 25);
    // std::cout << mpz_get_str(nullptr, 10, num) << std::endl;
    // std::cout << decimalToBinary(reinterpret_cast<intptr_t>(num)) << std::endl;
    // mpz_t *new_ptr = addTag(num, 5);
    // std::cout << decimalToBinary(reinterpret_cast<intptr_t>(new_ptr)) << std::endl;
    // std::cout << decimalToBinary(reinterpret_cast<intptr_t>(getPtr(new_ptr))) << std::endl;
    // std::cout << mpz_get_str(nullptr, 10, *(getPtr(new_ptr))) << std::endl;
    // std::cout << getTag(new_ptr) << std::endl;
// mpz_get_str
    mpz_t* num;
    mpz_init(*num);
    mpz_set_ui(*num, 25);
    std::cout << mpz_get_str(nullptr, 10, *num) << std::endl;
    std::cout << decimalToBinary(reinterpret_cast<intptr_t>(num)) << std::endl;
    void* tagNum = addTag(*num, 5);
    std::cout << decimalToBinary(reinterpret_cast<intptr_t>(tagNum)) << std::endl;
    std::cout << decimalToBinary(reinterpret_cast<intptr_t>(getPtr(num))) << std::endl;
    std::cout << mpz_get_str(nullptr, 10, *(getPtr(num))) << std::endl;
    std::cout << getTag(tagNum) << std::endl;
}