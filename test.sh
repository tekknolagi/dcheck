#!/bin/bash
set -euxo pipefail

CC=gcc CXX=g++ make -i test
CC=clang CXX=clang++ make -i test
