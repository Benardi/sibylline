# Sibylline

Data Structures and Algorithms written in C

## Status

[![BSD licensed](https://img.shields.io/github/license/vndmtrx/check-cmake-example.svg)](https://github.com/vndmtrx/check-cmake-example/blob/master/LICENSE)
[![Build Status](https://travis-ci.org/Benardi/sibylline.svg?branch=master)](https://travis-ci.org/Benardi/sibylline)

***

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project as an external dependency.

## Installation

To run this project the following programs need to be installed on your system:
- Cmake
- Check

Then, do as follows to build and test this library:

```bash
$ mkdir build && cd build
$ cmake ..
$ make
$ make test
```

### Build Type

By default `Release` build type will be used. Note that assert will be disabled with this build type.

You can a specific build type vai the `CMAKE_BUILD_TYPE` flag.


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
To generate documentation make sure to install Doxygen. Once inside the folder type the below command
to generate the documentation:

```
doxygen ./docs/Doxyfile.in
```
The documentation will be generated in the doc_doxygen folder under html & latex folders.
## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/Benardi/sibylline/tags). 

## Authors

* **Benardi Nunes** - *Initial work* - [Benardi](https://github.com/Benardi)

## License

This project is licensed under the BSD-3 Clause License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* **Eduardo Rolim** - check-cmake-example [example repo](https://github.com/vndmtrx/check-cmake-example)

* **Fábio Silva** - lotterypp [automatic test discovery](https://github.com/ffosilva/lotopp)
