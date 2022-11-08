cmake_minimum_required(VERSION 3.0.0)
project(jitdemo VERSION 0.1.0)

enable_testing()

add_executable(jitdemo main.cpp)
file(GLOB sources CONFIGURE_DEPENDS src/*.cpp src/*.hpp)
target_sources(jitdemo PUBLIC ${sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Set the compiler options
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
# set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
# set(OBJECT_DIR ${CMAKE_BINARY_DIR}/tests/CMakeFiles/hello_test.dir/__)
# message("-- Object files will be output to: ${OBJECT_DIR}")

include(CPack)

add_subdirectory(tests)

# find_program(GCOV_PATH gcov)
# if(NOT GCOV_PATH)
#   message(FATAL_ERROR "Code coverage analysis requires gcov!")
# endif()

# add_custom_target(gcov
#     COMMAND ctest -j8 -C Debug -T test --output-on-failure
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#     )
# add_custom_command(TARGET gcov
#     COMMAND echo "=================== GCOV ===================="
#     COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}/src -d -s -x coverage.xml
#     COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}"
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}  # Need separate command for this line
#     )
# add_dependencies(gcov jitdemo)

# add_custom_target(gcov
#     COMMAND mkdir -p coverage
#     COMMAND ${CMAKE_MAKE_PROGRAM} test
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#     )
# add_custom_command(TARGET gcov
#     COMMAND echo "=================== GCOV ===================="
#     COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}/src --txt >CoverageSummary.tmp
#     COMMAND cat CoverageSummary.tmp
#     COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage  # Need separate command for this line
#     )

# add_dependencies(gcov jitdemo)