set(NAME ip_printer)

add_library(${NAME}_lib
  INTERFACE
  )

target_compile_options(${NAME}_lib
  INTERFACE
  --std=c++14)

target_include_directories(${NAME}_lib
  INTERFACE
  include)

if(GTEST_FOUND)
  add_subdirectory(test)
endif()
