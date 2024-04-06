#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

void createCircleGrid(int size, int count, int width, int radius, int is_checker){
uint8_t *pixels=malloc(size*size);
int q,w,p;
int dx,dy,len,lum;
int ox,a,s,m;
int cell=size/count;
if(radius==0){
radius=cell/2;
}
for(w=0;w<count;w++){
for(q=0;q<count;q++){
ox=cell>>1;
for(s=0;s<cell;s++){
for(a=0;a<cell;a++){
p=q*cell+a+(w*cell+s)*size;
dx=ox-a;
dy=ox-s;
len=(int)(radius-((sqrt(dx*dx+dy*dy)+0.5)))%(width*2);
//fprintf(stderr,"l:%d,",l);
lum=255;
if(len>0){
lum=len>width?255:0;
}
if(is_checker && ((q^w)&1)==0){
lum=255;
}
pixels[p]=lum;
}
}
}
}
fwrite(pixels,1,size*size,stdout);
free(pixels);
}


void createGrid(int size, int count){
uint8_t *pixels=malloc(size*size);
srand(time(0));
int q,w,p;
int dx,dy,l;
int ox,oy,a,s,m;
int cell=size/count;
for(w=0;w<count;w++){
for(q=0;q<count;q++){
if(rand()&1){
ox=rand()%cell;
oy=(rand()&1)*cell;
} else {
ox=(rand()&1)*cell;
oy=rand()%cell;
}
m=rand()%5;
for(s=0;s<cell;s++){
for(a=0;a<cell;a++){
p=q*cell+a+(w*cell+s)*size;
dx=ox-a;
dy=oy-s;
l=255.0-sqrt(dx*dx+dy*dy)*m;
if(a==0 || s==0 || a==(size-1) || s==(size-1)){
l=0;
}
pixels[p]=l;
}
}
}
}
fwrite(pixels,1,size*size,stdout);
free(pixels);
}

void createCheckerboard(int size, int count){
uint8_t *pixels=malloc(size*size);
int q,w,p,s=size/count;
for(w=0;w<size;w++){
for(q=0;q<size;q++){
p=q+w*size;
pixels[p]=((q/s)^(w/s))&1?255:0;
}
}
fwrite(pixels,1,size*size,stdout);
free(pixels);
}

void createXor(int size){
uint32_t *pixels=malloc(size*size*4);
int q,w,p,l=log2(size);
fprintf(stderr,"l:%d\n",l);
int red,green,blue,black;
for(w=0;w<size;w++){
for(q=0;q<size;q++){
p=q+w*size;
red=((q>>(l-4))^(w>>(l-4)))&1?255:0;
green=((q>>(l-3))^(w>>(l-3)))&1?255:0;
blue=((q>>(l-2))^(w>>(l-2)))&1?255:0;
black=((q>>(l-1))^(w>>(l-1)))&1?255:0;
if(black){
red>>=2;
green>>=2;
blue>>=2;
}

pixels[p]=red | (green<<8) | (blue<<16) | 0xFF000000;
}
}
fwrite(pixels,4,size*size,stdout);
free(pixels);
}



int main(int argc, char **argv){


char *op=argv[1];
int twidth=atoi(argv[2]);

if(strstr(op,"checker")){
createCheckerboard(twidth, atoi(argv[3]));
}
if(strstr(op,"xor")){
createXor(twidth);
}
if(strstr(op,"grid")){
createGrid(twidth, atoi(argv[3]));
}
if(strstr(op,"circle")){
createCircleGrid(twidth,atoi(argv[3]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]));
}

return EXIT_SUCCESS;
}



