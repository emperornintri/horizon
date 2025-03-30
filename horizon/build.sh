#!/bin/sh

INC_DIR="include"
SRC_DIR="source"
MAIN="main.c"
OUT="program"
START="startHorizon"

SRCS=$(find "$SRC_DIR" -name "*.c")

gcc -I "$INC_DIR" -nostdlib -e "$START" "$MAIN" $SRCS -o "$OUT"

echo "Build completed: \"$OUT\"."
