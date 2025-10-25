#!/bin/bash

rm patterns
gcc patterns.c -ggdb3 -lm -o patterns || exit


convert -size 512x512 plasma:fractal -swirl 360 -normalize tmp-plasma-512.png
convert -size 512x512 -colorspace gray plasma:fractal -gamma 1.3 -normalize -level 5%,100% dirt-512.png

./patterns alphatest 512 512 16 0 | ffmpeg -pix_fmt rgb32 -s 512x512 -f rawvideo -i - -y alphatest-nodither-frames%01d.png
./patterns alphatest 512 512 16 1 | ffmpeg -pix_fmt rgb32 -s 512x512 -f rawvideo -i - -y alphatest-dither-frames%01d.png
convert tmp-plasma-512.png -compose copy-opacity alphatest-nodither-frames2.png -composite -compose src-over alphatest-nodither-frames1.png -composite alphatest-nodither-plasma.png
convert tmp-plasma-512.png -compose copy-opacity alphatest-dither-frames2.png -composite -compose src-over alphatest-dither-frames1.png -composite alphatest-dither-plasma.png
convert dirt-512.png -compose copy-opacity alphatest-nodither-frames2.png -composite -compose src-over alphatest-nodither-frames1.png -composite alphatest-nodither-dirt.png
convert dirt-512.png -compose copy-opacity alphatest-dither-frames2.png -composite -compose src-over alphatest-dither-frames1.png -composite alphatest-dither-dirt.png

rm tmp-plasma-512.png dirt-512.png

exit
convert -size 256x256 -colorspace gray plasma:fractal -gamma 1.3 -normalize -level 5%,100% dirt-256.png
./patterns alphatest 256 256 16 0 | ffmpeg -pix_fmt rgb32 -s 256x256 -f rawvideo -i - -y alphatest-nodither-frames%01d.png
convert -size 256x256 plasma:fractal -swirl 360 -normalize -compose copy-opacity alphatest-nodither-frames2.png -composite -compose src-over alphatest-nodither-frames1.png -composite alphatest-nodither-plasma-256.png
convert dirt-256.png -compose copy-opacity alphatest-nodither-frames2.png -composite -compose src-over alphatest-nodither-frames1.png -composite alphatest-nodither-dirt-256.png
./patterns alphatest 256 256 16 1 | ffmpeg -pix_fmt rgb32 -s 256x256 -f rawvideo -i - -y alphatest-dither-frames%01d.png
convert -size 256x256 plasma:fractal -swirl 360 -normalize -compose copy-opacity alphatest-dither-frames2.png -composite -compose src-over alphatest-dither-frames1.png -composite alphatest-dither-plasma-256.png
convert dirt-256.png -compose copy-opacity alphatest-dither-frames2.png -composite -compose src-over alphatest-dither-frames1.png -composite alphatest-dither-dirt-256.png


exit

#./patterns signature 256 512 "this is just a test" | ffmpeg -pix_fmt rgb32 -s 256x512 -f rawvideo -i - -y signature.png

exit
./patterns bayer 2 | ffmpeg -pix_fmt gray -s 2x2 -f rawvideo -i - -y bayer2.png
./patterns bayer 4 | ffmpeg -pix_fmt gray -s 4x4 -f rawvideo -i - -y bayer4.png
./patterns bayer 8 | ffmpeg -pix_fmt gray -s 8x8 -f rawvideo -i - -y bayer8.png

./patterns gradient4 512 | ffmpeg -pix_fmt gray -s 512x512 -f rawvideo -i - -y gradient4.png
./patterns binarysun 256 0 20 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y sun.png
./patterns binarysun 256 0 15 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y sun2.png
./patterns binarysun 256 1 15 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y sun3.png
./patterns hilbert 256 2 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y hilbert-2.png
./patterns hilbert 256 3 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y hilbert-3.png

./patterns checker 256 4 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -pix_fmt rgb32 -y checker-2.png
./patterns checker 256 8 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -pix_fmt rgb32 -y checker-4.png
./patterns checker 256 16 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -pix_fmt rgb32 -y checker-8.png
./patterns checker 256 32 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -pix_fmt rgb32 -y checker-16.png

./patterns gradient1 256 | ffmpeg -pix_fmt rgb32 -s 256x256 -f rawvideo -i - -y gradient.png

./patterns circle 256 8 1 0 1 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y circle-narrow.png
./patterns circle 256 1 10 0 0 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y circle-target.png
./patterns xor 256 | ffmpeg -pix_fmt rgb32 -s 256x256 -f rawvideo -i - -y xor.png
./patterns grid 256 8 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y grid-8.png
./patterns grid 256 16 | ffmpeg -pix_fmt gray -s 256x256 -f rawvideo -i - -y grid-16.png

perl numbers.pl numbers.png 256 16 1 0
perl numbers.pl numbers-big.png 1024 32 1 1
perl numbers.pl numbers-small.png 256 8 1 0

convert -colorspace Lab checker-4.png numbers-small.png -composite checker-4-numbered.png

convert xor.png numbers-small.png -composite xor-numbered.png
convert grid-8.png numbers-small.png -composite grid-8-numbered.png

convert -compose Screen gradient.png \( circle-target.png -negate \) -composite circle-target-colored.png
convert -compose Overlay gradient.png grid-8.png -composite -compose Multiply grid-8.png -composite grid-8-colored.png
convert -compose Overlay gradient.png grid-16.png -composite grid-16-colored.png
convert -compose colorize grid-8-numbered.png gradient.png -composite grid-8-numbered-colored.png

perl random-pto.pl 0 > random.pto
perl random-pto.pl 1 > random-roll.pto
perl ptsgen.pl random.pto random.pts
perl ptsgen.pl random-roll.pto random-roll.pts
perl ptsgen.pl cube.pto cube.pts
