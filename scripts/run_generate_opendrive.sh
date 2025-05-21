#! /usr/bin/env bash

set -e

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./third_part && ./bin/generate_opendrive $1
