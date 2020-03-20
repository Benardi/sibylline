#!/bin/bash
# Runs clang-format on header, source and unit test files
# Copyright (c) 2020 Benardi Nunes <benardinunes@gmail.com>
# ---------------------------------------------------------------------

# Make it executable
# chmod +x ./format_code.sh

# Requires Git and clang-format to be installed
# sudo apt install clang-format

clang-format -i ./src/include/*.h
clang-format -i ./src/*.c
clang-format -i ./tests/*.c
