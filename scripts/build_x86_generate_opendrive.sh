#!/usr/bin/env bash

set -e

# Build x86
build_platform="x86"
build_dir="build_${build_platform}"
echo "Building ${build_platform}..."

if [ -d "${build_dir}" ]; then
    echo "Build directory ${bild_dir} already exists, removing it..."
    rm -rf "${build_dir}"
fi

mkdir -p "${build_dir}"
cd "${build_dir}"

cmake .. -DCMAKE_BUILD_TYPE=Debug      \
         -DBUILD_DIR=${build_dir}      \
         -DINSTALL_DIR="output"        \
         -DBUILD_GENERATE_OPENDRIVE=ON \
         -DENABLE_TEST=OFF

make -j4
make install