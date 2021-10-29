#!/bin/bash
# Runs clang-format on header, source and unit test files
# Copyright (c) 2020 Benardi Nunes <benardinunes@gmail.com>
# ---------------------------------------------------------------------

# Make it executable
# chmod +x ./format_code.sh

# Requires Git and clang-format to be installed
# sudo apt install clang-format

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

clang-format -i ${SCRIPT_DIR}/src/include/*.h
clang-format -i ${SCRIPT_DIR}/src/*.c
clang-format -i ${SCRIPT_DIR}/tests/*.c
