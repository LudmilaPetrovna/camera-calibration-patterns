opendir(dd,".");
foreach $filename(sort grep{/\.(jpe?g|png|gif)$/i}readdir(dd)){
print "![$filename](./$filename)\n"
}
