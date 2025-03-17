dd if=/dev/urandom bs=768 count=1 | ffmpeg -f rawvideo -pix_fmt rgb24 -s 16x16 -i - -vf scale=256x256:flags=neighbor -y random_palette.png
