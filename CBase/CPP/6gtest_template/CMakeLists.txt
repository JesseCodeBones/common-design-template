cmake_minimum_required(VERSION 3.0.0)
project(gtest_demo VERSION 0.1.0)

include(CTest)

#testing
enable_testing()
add_subdirectory(test)
add_subdirectory(src)


include(ExternalProject)
ExternalProject_Add(gcovr
    URL https://github.com/gcovr/gcovr/archive/3.2.zip
    URL_HASH SHA1=7411d3989116c5fa65519ee1a54237df16944ad2
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

set(CMAKE_C_FLAGS_PROFILE -fprofile-arcs -ftest-coverage -fPIC)
set(CMAKE_CXX_FLAGS_PROFILE -fprofile-arcs -ftest-coverage -fPIC)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
