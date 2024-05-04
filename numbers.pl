#!/usr/bin/perl

use GD;
use utf8;
use Encode;

# Example:
#./numbers.pl out.png 256 16 1 1

$fontfile="/usr/share/fonts/truetype/Fifaks10Dev1.ttf";
$fontsize=9;

$output_filename=$ARGV[0];
$width=$ARGV[1]*1;
$columns=$ARGV[2]*1;

$use_random_bg=$ARGV[3]*1;
$use_empty_cells=$ARGV[4]*1;

$first_letter="A"; # English "A"

if($columns>26){
$first_letter="А"; # Кириллическая "А"
binmode(STDOUT,":utf8");
}

$image=GD::Image->new($width,$width,1);
$image->alphaBlending(0);
$image->saveAlpha(1);

$tmp=GD::Image->new($width,$width,1);
$cell_size=int($width/$columns);

for($w=0;$w<$columns;$w++){
for($q=0;$q<$columns;$q++){

$string="".chr(ord($first_letter)+$w)."".($q+1);
if($cell_size<=16){
$string="".chr(ord($first_letter)+$w)."".($q<10?$q:chr($q+65-10));
}

@bounds=$tmp->stringFT(0,$fontfile,$fontsize,0,10,10,$string);

#         @bounds[0,1]  Lower left corner (x,y)
#         @bounds[2,3]  Lower right corner (x,y)
#         @bounds[4,5]  Upper right corner (x,y)
#         @bounds[6,7]  Upper left corner (x,y)

$width=$bounds[2]-$bounds[6]-1;
$height=int($bounds[7]-$bounds[3]-1-$fontsize/2);

$cx=$q*$cell_size;
$cy=$w*$cell_size;
$sx=int($cx+$cell_size/2-$width/2+.5);
$sy=int($cy+$cell_size/2-$height/2+.5);

$color=0xFF555555;
if($use_random_bg){
$color=rand()>.5?255:0;
$color=$color|($color<<8)|($color<<16)|(int(127-rand()*(10+$use_empty_cells*30))<<24);
}

$image->filledRectangle($cx,$cy,$cx+$cell_size,$cy+$cell_size,$color);

if($use_empty_cells){
$image->filledRectangle($cx+1,$cy+1,$cx+$cell_size-2,$cy+$cell_size-2,0xFF000000);
}

$image->stringFT(0x33FFFFFF,$fontfile,$fontsize,0,$sx-0,$sy-1,$string);
$image->stringFT(0x33FFFFFF,$fontfile,$fontsize,0,$sx+0,$sy+1,$string);
$image->stringFT(0x33FFFFFF,$fontfile,$fontsize,0,$sx-1,$sy+0,$string);
$image->stringFT(0x33FFFFFF,$fontfile,$fontsize,0,$sx+1,$sy+0,$string);
$image->stringFT(0,$fontfile,$fontsize,0,$sx,$sy,$string);


}
}

open(oo,">".$output_filename);
binmode(oo);
print oo $image->png(9);
close(oo);



