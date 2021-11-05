# Did it in C

This repository exists to expand my personal abilities. I have never had a
reason to learn C properly. This will be my effort to implement some algorithms
and data structures in C.

I'm sure as I go along, I will learn more about C idioms and best practices, so
this will serve as a record of all my mistakes and progress.

## Implementations

- Hello World
- Looping through an array
- Resizable array struct

## Things I Learned

- How to write a simple Makefile
- How to organize header files
- Array sizing and size\_t
- Using libcheck
- Adding dependencies on headers to Makefile
- Function declaration order matters if a function is not in the header
- The `realloc` call for resizing a variable

## Build Dependencies

- `clang`
- `make`
- `check` [libcheck](https://libcheck.github.io/check/)
- `cpplint` [cpplint](https://github.com/cpplint/cpplint)

## Running

To run the examples:

```sh
make
bin/run
```

Run the tests

```sh
make test
```

## CCLS Language Server

To setup the CCLS language server:

- Install [`bear`](https://github.com/rizsotto/Bear)
- Install [`ccls`](https://github.com/MaskRay/ccls)
- Clean with `make clean`

Generate `compile_commands.json`:

```sh
make clean
bear -- make
bear --append make test
```
