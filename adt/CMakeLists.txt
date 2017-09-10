add_library(cat cat.c)
add_executable(main main.c)
target_link_libraries(main cat)
