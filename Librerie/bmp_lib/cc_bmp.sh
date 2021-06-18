#!/bin/sh
gcc -lm -o$1 -DBMPSHOWALL $1.c bmp.c
