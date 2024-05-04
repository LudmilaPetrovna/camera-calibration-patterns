use GD;

$use_random_roll=$ARGV[0]|0;

print "p w4096 h2048 f2 v360 n\"PNG\" R0 T\"UINT8\"\n";
print "m i6\n\n";


opendir(dd,".");
@images=grep{/\.(gif|gd|gd2|wbmp|bmp|xbm|tga|png|jpe?g|tiff?|webp|xpm)$/i}readdir(dd);
closedir(dd);


foreach $filename(@images){
$image=GD::Image->new($filename);
if(!$image){die "Can't read image $filename!";}
($width,$height)=$image->getBounds();
$yaw=rand()*360.0;
$pitch=rand()*(rand()*178.0-89.0);
$roll=$use_random_roll*(rand()*360.0-180.0);

$fov=10+rand()*80.0*rand();

print "i f0 w${width} h${height} r${roll} p${pitch} y${yaw} v${fov} n\"$filename\"\n";
}

# random by hand
exit;
print "i f0 w256 h256 r0.0 p0.0 y0.0 v90.0 n\"checker-2.png\"\n";
print "i f0 w256 h256 r0.0 p0.0 y90.0 v90.0 n\"checker-4-numbered.png\"\n";
print "i f0 w256 h256 r0.0 p0.0 y180.0 v90.0 n\"checker-8.png\"\n";
print "i f0 w256 h256 r0.0 p0.0 y270.0 v90.0 n\"checker-16.png\"\n";
print "i f0 w256 h256 r0.0 p-89.95 y0.0 v90.0 n\"circle-target-colored.png\"\n";
print "i f0 w256 h256 r0.0 p89.95 y180.0 v90.0 n\"grid-8-numbered-colored.png\"\n";

