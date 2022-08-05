find_package(GTest REQUIRED)
# set(CMAKE_CXX_STANDARD 17)
# add_executable(hello_test TestAdd.cpp)

set(BINARY ${PROJECT_NAME})
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cpp)
set(RESOURCES ${TEST_SOURCES})

macro(add_test_case target_file)

    if(NOT DEFINED CMAKE_CROSSCOMPILING_EMULATOR)
        gtest_add_tests(TARGET      
            ${target_file}
        )
    elseif("${CMAKE_CROSSCOMPILING_EMULATOR}" MATCHES "qemu-aarch64")
        add_test(NAME ${target_file} COMMAND "qemu-aarch64" -L /usr/aarch64-linux-gnu ${CMAKE_CURRENT_BINARY_DIR}/${target_file})
    else()
        message(FATAL_ERROR "unsupported CMAKE_CROSSCOMPILING_EMULATOR for testing")
    endif()

endmacro()

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} ${CMAKE_PROJECT_NAME}_lib GTest::gtest GTest::gtest_main)
add_test_case(${PROJECT_NAME})
