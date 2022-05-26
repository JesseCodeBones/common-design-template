aux_source_directory(. SOURCE_DIR)
add_library(src ${SOURCE_DIR})
include_directories(SYSTEM ${CMAKE_SOURCE_DIR}/include)