include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  hello_test
  testMain.cpp
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)
file(GLOB sources CONFIGURE_DEPENDS ../src/*.cpp ../src/*.hpp)
target_sources(hello_test PUBLIC ${sources})

include(GoogleTest)
gtest_discover_tests(hello_test)