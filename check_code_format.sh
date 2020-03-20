#!/bin/bash
# Runs clang-format and fails if any file has changed
# Copyright (c) 2020 Benardi Nunes <benardinunes@gmail.com>
# ---------------------------------------------------------------------

# Make it executable
# chmod +x ./check_code_format.sh

# Requires Git and clang-format to be installed
# sudo apt install git-all
# sudo apt install clang-format

cleanstate=`git status | grep "modified"`
if ! [[ -z $cleanstate ]]; then
  echo "Script must be applied on a clean git state"
  exit 1
fi

# Execute clang-format 
/bin/bash ./format_code.sh

# check if something was modified
notcorrectlist=`git status | grep "modified"`

n_total="$(ls {tests/*.c,src/*.c,src/include/*.h} -1 | wc -l)"

if [[ -z $notcorrectlist ]]; then
  # if nothing changed ok
  echo "┬──┬◡ﾉ(° -°ﾉ)"
  echo "${n_total} files would be left unchanged"  
  exit 0;
else
  changed="$(git diff --name-only ./src/ ./tests/)"
  n_changed="$(git diff --name-only ./src/ ./tests | wc -l)"
  declare -i n_unchanged
  n_unchanged=$((${n_total} - ${n_changed}))

  for file in ${changed}; do
    echo "would reformat ${PWD}/${file}"
  done 

  echo "(╯°□°)╯︵ ┻━┻"
  echo "${n_changed} files would be reformatted, ${n_unchanged} files would be left unchanged." 
fi

# cleanup changes in git
git reset HEAD --hard &> /dev/null

exit 1

