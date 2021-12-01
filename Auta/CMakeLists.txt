# CMakeList.txt : CMake project for Auta, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Auta")

# Add source to this project's executable.
add_executable (Auta "Auta.cpp" "Auta.h" "AutaDB.h" "AutaDB.cpp")

# TODO: Add tests and install targets if needed.
