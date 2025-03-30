#!/bin/sh

SRC_DIR="source"
INC_DIR="include"
OUT="program"

SRCS=$(find "$SRC_DIR" -name "*.c")

gcc -I "$INC_DIR" -nostdlib -e startHorizon main.c $SRCS -o "$OUT"

echo "Build completed: $OUT"
