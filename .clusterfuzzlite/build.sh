#!/bin/bash -eu

# build project
# e.g.
# ./autogen.sh
# ./configure
# make -j$(nproc) all

# build fuzzers
# e.g.
# $CXX $CXXFLAGS -std=c++11 -Iinclude \
#     /path/to/name_of_fuzzer.cc -o $OUT/name_of_fuzzer \
#     $LIB_FUZZING_ENGINE /path/to/library.a
export CXX=clang
export CXXFLAGS='-g -fsanitize=address,fuzzer'

$CXX $CXXFLAGS fuzz_target.c vulnerable_parser.c -o $OUT/fuzz_vulnerable_parser
