find_package(GTest REQUIRED)
# set(CMAKE_CXX_STANDARD 17)
# add_executable(hello_test TestAdd.cpp)

set(BINARY ${CMAKE_PROJECT_NAME}_test)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cpp)
set(RESOURCES ${TEST_SOURCES})
add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} ${CMAKE_PROJECT_NAME}_lib GTest::gtest GTest::gtest_main)
