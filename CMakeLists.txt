cmake_minimum_required(VERSION 3.13)
project(CompetitiveProgramming)
set(CMAKE_CXX_STANDARD 20)

# single file executables
add_executable(test test.cpp)
add_executable(Knapsack1 Misc/Knapsack1.cpp)
add_executable(Golf CCC/Golf.cpp)
add_executable(BobsReverseNumber Misc/BobsReverseNumber.cpp)
add_executable(DansPowerAttack Misc/DansPowerAttack.cpp)
add_executable(AdamsParty Misc/AdamsParty.cpp)
add_executable(ReturningHome Misc/ReturningHome.cpp)