file(GLOB states "states/*.c")
add_library(cat cat.c cat_state.c ${states})
add_executable(main main.c)
target_link_libraries(main cat) 
