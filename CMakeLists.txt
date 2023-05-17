cmake_minimum_required(VERSION 3.0.0)
project(bdwgc-gmp_test VERSION 0.1.0)

include(CTest)
enable_testing()

# Set additional directories
set(DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
set(BDWGC_INCLUDE_DIR ${DEPENDENCIES_DIR}/bdwgc/include)
set(GMP_INCLUDE_DIR ${DEPENDENCIES_DIR}/gmp/include)
set(VALGRIND_INCLUDE_DIR ${DEPENDENCIES_DIR}/valgrind/include)
set(HAMT_INCLUDE_DIR ${DEPENDENCIES_DIR}/hamt)

# Set additional library directories
set(BDWGC_LIBRARY_DIR ${DEPENDENCIES_DIR}/bdwgc/lib)
set(GMP_LIBRARY_DIR ${DEPENDENCIES_DIR}/gmp/lib)
set(VALGRIND_LIBRARY_DIR ${DEPENDENCIES_DIR}/valgrind/lib)

# Include directories
include_directories(${BDWGC_INCLUDE_DIR} ${GMP_INCLUDE_DIR} ${VALGRIND_INCLUDE_DIR} ${HAMT_INCLUDE_DIR})

# Link directories
link_directories(${BDWGC_LIBRARY_DIR} ${GMP_LIBRARY_DIR} ${VALGRIND_LIBRARY_DIR})

# Add executable
add_executable(bdwgc-gmp_test src/factorial_gmp.cpp)
# add_executable(bdwgc-gmp_test src/main.cpp)
# add_executable(bdwgc-gmp_test src/test_hamt.cpp)


# Link libraries
target_link_libraries(bdwgc-gmp_test PRIVATE gmpxx gmp gc)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
