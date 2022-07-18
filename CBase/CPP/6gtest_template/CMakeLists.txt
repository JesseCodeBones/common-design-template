cmake_minimum_required(VERSION 3.0.0)
project(gtest_demo VERSION 0.1.0)

include(CTest)
enable_testing()


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

ExternalProject_Get_Property(gcovr source_dir)
SET(GCOVR ${source_dir}/scripts/gcovr)

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS "-lgcov")
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )               

set(gcovr_options_basic --exclude-throw-branches --exclude-unreachable-branches --gcov-executable ${GCOVR} -r ${CMAKE_CURRENT_SOURCE_DIR}/src .)
set(gcovr_options_xml ${gcovr_options_basic} -d -s -x coverage.xml)

add_custom_target(run_ctest
    COMMAND  ctest "--output-on-failure"
    ARG
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

add_custom_target(coverage_basic VERBATIM
    COMMAND  gcovr ${gcovr_options_basic}
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS run_ctest
)
add_custom_target(
        coverage VERBATIM
        COMMAND  gcovr ${gcovr_options_xml}
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        DEPENDS coverage_basic
)

# add_custom_command(OUTPUT _run_gcovr_parser
#     COMMAND ${GCOVR} -r ${CMAKE_SOURCE_DIR}/src --object-dir=
#     ${CMAKE_BINARY_DIR} 
#     COMMAND ${GCOVR} -r ${CMAKE_SOURCE_DIR}/src --object-dir=
#     ${CMAKE_BINARY_DIR} --branches --exclude-unreachable-branches
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
#     add_custom_target (coverage DEPENDS _run_gcovr_parser)

# set(CovExecutable "gcov")
# set(gcovr_options_basic --exclude-throw-branches --exclude-unreachable-branches --gcov-executable ${CovExecutable} -r ${CMAKE_CURRENT_SOURCE_DIR}/src .)
# set(gcovr_options_xml ${gcovr_options_basic} -d -s -x coverage.xml)

# add_custom_target(run_ctest
#     COMMAND  ctest "--output-on-failure"
#     ARG
#     WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
# )
# add_custom_target(coverage_basic VERBATIM
#     COMMAND  gcovr ${gcovr_options_basic}
#     WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
#     DEPENDS run_ctest
# )
# add_custom_target(
#         coverage VERBATIM
#         COMMAND  gcovr ${gcovr_options_xml}
#         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
#         DEPENDS coverage_basic
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
