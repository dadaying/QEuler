#! /usr/bin/env bash

set -e

test_file_list=$(ls ./bin/*_test)
test_file_num=$(ls ./bin/*_test | wc -l)

echo "Running tests: nums=""${test_file_num}"

for test_file in $test_file_list
do
    echo "Running $test_file"
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./third_part && ./$test_file
done

echo "All tests passed!"