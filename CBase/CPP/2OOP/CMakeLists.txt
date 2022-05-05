cmake_minimum_required(VERSION 3.0.0)
project(oop VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(oop main.cpp)
# add_executable(oop OperatorOverride.cpp)
# add_executable(oop FriendlyClass.cpp)
add_executable(oop ObjectArray.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
