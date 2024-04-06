#!/bin/bash


gcc patterns.c -lm -o patterns
./patterns circle 256 8 1 0 1 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y circle-narrow.png
./patterns circle 256 1 10 0 0 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y circle-target.png
./patterns xor 256 | ffmpeg -pix_fmt rgb32 -s 256x256 -f rawvideo -i - -y xor.png
./patterns checker 256 4 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y checker-2.png
./patterns checker 256 8 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y checker-4.png
./patterns checker 256 16 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y checker-8.png
./patterns checker 256 32 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y checker-16.png
./patterns grid 256 8 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y grid-8.png
./patterns grid 256 16 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y grid-16.png


