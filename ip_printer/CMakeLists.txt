set(NAME print_ip)

add_executable(${NAME}
  src/ip_printer.cpp
  )

set_target_properties(${NAME}
  PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS NO
  )

target_compile_options(${NAME}
  PUBLIC
  -Werror -Wpedantic -Wall -Wextra)

target_link_libraries(${NAME} ip_printer_lib)

install(TARGETS ${NAME}
  RUNTIME DESTINATION bin)

