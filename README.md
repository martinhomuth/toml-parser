# TOML-Parser

This is an explorative [TOML](https://github.com/toml-lang/toml)-Parser project.

## Build instructions

```
$ mkdir build && cd build
$ cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
$ make
$ ./main
$ make test      # Makes and runs the tests.
$ make coverage  # Generate a coverage report.
$ make doc       # Generate html documentation.
```
