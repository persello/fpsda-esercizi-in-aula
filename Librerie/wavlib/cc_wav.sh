#!/bin/sh
gcc -lm -o$1 -DWAVSHOWALL $1.c wav.c

