# Generic Array Algorithms Library (GRAAL)

# Intro

Was generated a generic library that contains the implementation of the functions: `min`, `reverse`, `copy`, `clone`, `find_if`, `find`, `all_of`, `any_of`, `none_of`, `equal`, `unique`, `partition` and `sort`. The library, Graal.a, can be linked to any application that needs to use the functions defined in there.


# Part 1: Compiling the Library

To compile the libray only we should follow these steps:

1. `cd lib_source`: enters into the main project directory.
2. `mkdir build`: this creates a new directory in which the compilation output will be stored, including the executable.
3. `cd build`: just moves into the directory created in the step above.
4. `cmake -G "Unix Makefiles" ..`: asks cmake to create the Makefile based on the script found in `CMakeLists.txt`, one level up.
5. `cmake --build .`: triggers the compiling process.
5. `make install`: copies the library to the `lib` directory.

And *voilà*, you have an executable inside the `build` directory that tests the library functions.
Also, you will have a library `libGraal.a` in which the functions are compiled.

## Running the tests

Just run as usual (assuming `$` is the terminal prompt):

```
$ ./build/run_tests
```

# Part 2: Compiling the Driver Application


Remember that to compile the driver application we must first complete the library implementation.
After that, follow these steps:

1. `cd app_source`: enters into the main project directory.
2. `cp ../lib_source/include/graal.h include`: copy the library header into this new project.
3. `cp ../lib_source/lib/Graallib.a lib`: copy the external library into the `lib` directory of this project.
2. `mkdir build`: this creates a new directory in which the compilation output will be stored, including the executable.
3. `cd build`: just moves into the directory created in the step above.
4. `cmake -G "Unix Makefiles" ..`: asks cmake to create the Makefile based on the script found in `CMakeLists.txt`, one level up.
5. `cmake --build .`: triggers the compiling process.

And *voilà*, you have an executable inside the `build` directory.

## Running the Driver Application

Just run as usual (assuming `$` is the terminal prompt):

```
$ ./build/driver_int_ranges
```
