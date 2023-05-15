cmake_minimum_required(VERSION 3.0.0)
project(bdwgc-gmp_test VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/bdwgc/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/gmp/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/valgrind/include)

add_executable(bdwgc-gmp_test src/main.cpp)
target_link_libraries(bdwgc-gmp_test PRIVATE libgmpxx.so libgmp.so libgc.so)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
