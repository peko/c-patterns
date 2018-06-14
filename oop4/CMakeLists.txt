set(CMAKE_C_FLAGS "-o0 -Wall -g -pedantic -std=c11 -fms-extensions")
add_executable(main main.c Obj.c Cat.c)
