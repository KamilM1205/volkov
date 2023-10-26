cmake_minimum_required(VERSION 3.8)
project("labs")

set(CXX_STANDARD C++17)

set(LAB1_SRC lab1/src/main.cpp)
set(LAB2_SRC lab2/src/main.cpp)
set(LAB3_SRC lab3/src/main.cpp)

add_executable(lab1 ${LAB1_SRC})
target_compile_features(lab1 PRIVATE cxx_std_17)

add_executable(lab2 ${LAB2_SRC})
target_compile_features(lab2 PRIVATE cxx_std_17)

add_executable(lab3 ${LAB3_SRC})
target_include_directories(lab3 PUBLIC lab3/include)
target_compile_features(lab3 PRIVATE cxx_std_17)