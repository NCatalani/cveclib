#!/bin/bash

LIBNAME=libcvec.a
OUTPUT_DIR=output
LIB_DIR=out
RELEASE=""
VERSION=$(cat README.md | head -n 1 | egrep -o -e '[0-9]{1}.[0-9]*')

[ -n "$1" ] && RELEASE="Y"

make clean && make

[[ "$RELEASE" != "Y" ]] && exit 0

OUTPUT="${OUTPUT_DIR}/libcvec_v${VERSION}.tar.gz"

mkdir output/ 2>/dev/null
rm -rf ${OUTPUT} 2>/dev/null

tar -czvf ${OUTPUT} ${LIB_DIR}

