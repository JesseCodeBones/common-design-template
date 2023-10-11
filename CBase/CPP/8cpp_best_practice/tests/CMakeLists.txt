
find_package(GTest REQUIRED)

file(GLOB 
test_sources 
CONFIGURE_DEPENDS 
./*.cpp
../src/*.cpp
../src/*.hpp)

add_executable(
  cpp_best_practice_tests
  ${test_sources}
)

target_link_libraries(
  cpp_best_practice_tests
  GTest::gtest_main
)

gtest_discover_tests(cpp_best_practice_tests)