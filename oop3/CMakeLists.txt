set(CMAKE_C_FLAGS "-o0 -Wall -g -pedantic -std=c11 -fms-extensions")
add_executable(main main.c Object.c Animal.c Dog.c Cat.c)
