#!/bin/bash
list_of_files=""
for file in $(ls source); do
    list_of_files="$list_of_files source/$file"
done
gcc $list_of_files -nostdlib -I include -e startHorizon -o binary/program
