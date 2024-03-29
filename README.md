  <img src="https://raw.githubusercontent.com/Benardi/sibylline/master/sibylline_icon_wide.png"
       alt="sibylline logo"
       align="center">

# Sibylline

Data Structures and Algorithms written in C

## Status

<p align="center">
    <a href="https://github.com/vndmtrx/check-cmake-example/blob/master/LICENSE">
        <img src="https://img.shields.io/github/license/vndmtrx/check-cmake-example.svg"
            alt="BSD licensed"/>
    </a>
    <a href="https://github.com/Benardi/sibylline/actions/workflows/build_test_checkstyle.yaml">
        <img src="https://github.com/Benardi/sibylline/actions/workflows/build_test_checkstyle.yaml/badge.svg"
            alt="Build, Test, Check Style"/>
    <a href="https://app.fossa.com/projects/git%2Bgithub.com%2FBenardi%2Fsibylline?ref=badge_small" alt="FOSSA Status">
        <img src="https://app.fossa.com/api/projects/git%2Bgithub.com%2FBenardi%2Fsibylline.svg?type=small"/>
    </a>
</p>

***

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project as an external dependency.

## Installation

To build this library the following dependencies must be installed on your system:
- [Cmake](https://cmake.org/)
- [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/)

Then, run the following commands to build this library:

```bash
$ mkdir build && cd build
$ cmake ..
$ make
```

### Build Type and Tests

To run this lib's tests you need the following dependencies:
- [Check](https://github.com/libcheck/check) (At least version 0.11.0)
- [Valgrind](https://valgrind.org/)

By default the `Release` build type will be used. Note that assertions will be disabled with this build type.
You can specify a build type via the flag `CMAKE_BUILD_TYPE`.


```bash
$ mkdir build && cd build
$ cmake -D CMAKE_BUILD_TYPE=Debug ..
$ make
$ make test
```

***

## Deployment

If you wish to install the `sibylline` library run the following command with sudo after building the project:

```bash
$ make install
```

<br>

By default the libray will be built as `SHARED`, if you wish to have it as a `STATIC` library you may edit the `CMakeLists.txt` at the root of the project:

```cmake

# Configure wether libraries will be static or shared linked
set(BUILD_SHARED_LIBS ON)

```

The location of the shared library will be made available in the file `sibylline/build/install_manifest.txt`
* This will install the shared library at `/usr/local/lib/libsibylline.so` in Unix machines.

<br>

If you wish to change the deployment location you may edit the `CMakeLists.txt` at the root of the project:

```cmake

# install shared library at /usr/lib. Use "sudo make install" to apply 

install(TARGETS sibylline DESTINATION lib)
```
## Documentation 
To generate documentation make sure to install Doxygen. Once inside the folder type the command below
to generate the documentation:

```
doxygen ./docs/Doxyfile
```
The documentation will be generated in the doc_doxygen folder under html & latex folders.

## Code formatting 

To format this project's source code we're using [clang-format](https://clang.llvm.org/docs/ClangFormat.html). To format all existing source code run the following command:

```bash
/bin/bash ./check_code_format.sh
```

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/Benardi/sibylline/tags). 

## Authors

* **Benardi Nunes** - *Initial work* - [Benardi](https://github.com/Benardi)

## Acknowledgments

* **Eduardo Rolim** - check-cmake-example [example repo](https://github.com/vndmtrx/check-cmake-example)

* **Fábio Silva** - lotterypp [automatic test discovery](https://github.com/ffosilva/lotopp)

***

## License

This project is licensed under the BSD-3 Clause License - see the [LICENSE.md](LICENSE.md) file for details


[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2FBenardi%2Fsibylline.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2FBenardi%2Fsibylline?ref=badge_large)
