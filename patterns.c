#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include "hilbert.c"
#include "font.c"
#include "crc32.c"


void draw_string_rgba(uint32_t *pixels, int width, int height, char *msg, int ox, int oy, uint32_t color){
int q,ch,tpos_x,tpos_y,px,py,a,s,len=strlen(msg);
int sx,sy,sbit,sbyte;
for(q=0;q<len;q++){
ch=(uint32_t)msg[q];
tpos_x=ch%16;
tpos_y=ch/16;

for(s=0;s<font_height;s++){
for(a=0;a<font_width;a++){
px=a+ox;
py=s+oy;
sx=tpos_x*font_width+a;
sy=tpos_y*font_height+s;
sbyte=(sx>>3)+sy*font_stride;
sbit=sx&7;
if(px>=0 && py>=0 && px<width && py<height && ((font_bits[sbyte]>>sbit)&1)==1){
pixels[px+py*width]=color;
}
}
}
ox+=font_width;
}
}

void draw_string_glow_rgba(uint32_t *pixels, int width, int height, char *msg, int ox, int oy){
int q,w;
for(w=-1;w<=1;w++){
for(q=-1;q<=1;q++){
draw_string_rgba(pixels, width, height, msg, ox+q, oy+w, 0x80000000);
}
}
draw_string_rgba(pixels, width, height, msg, ox, oy, 0xFFFFFFFF);
}

void createSignatureOverlay(int width, int height, char *text){
uint32_t *pixels=malloc(width*height*4);
uint32_t colors[4];
uint32_t sum=calculate_crc32c(0,text,strlen(text));
static char info[256];
sprintf(info,"0x%08x (%dx%d)",sum,width,height);
char *signs[2]={text,info};
int q,w,cc;

// define colors;
for(q=0;q<4;q++){
cc=(sum>>(q*6));
colors[q]=((cc&3)<<6)|(((cc>>2)&3)<<14)|(((cc>>4)&3)<<22);
colors[q]|=0x3f000000;
}

for(w=0;w<height;w++){
for(q=0;q<width;q++){
cc=((q>>3)^(w>>3))&3;
pixels[q+w*width]=colors[cc];
}
}

srand(time(0));
q=0;
for(w=0;w<height;w+=15){
draw_string_glow_rgba(pixels,width,height,signs[rand()&1],5+q*50,5+w);
q^=1;
}
fwrite(pixels,1,width*height*4,stdout);

free(pixels);
}



void createBayer(int size){
uint8_t bayer_base[]={0,3,1,2};
uint8_t *pixels=malloc(size*size);
pixels[0]=0;
int not_done=size;
int l,q,a,s,ox,oy,st;
for(l=0;not_done;l++,not_done>>=1){
st=powl(2,l-1);
for(q=3;q>=0;q--){
ox=bayer_base[q]&1;
oy=(bayer_base[q]>>1)&1;
for(s=0;s<st;s++){
for(a=0;a<st;a++){
pixels[a+ox*st+(s+oy*st)*size]=pixels[a+s*size]*4+q;
}
}
}
}

// out to console
int w;
for(w=0;w<size;w++){
fprintf(stderr,"{");
for(q=0;q<size;q++){
fprintf(stderr,"% 3d%s",pixels[q+w*size],q==size-1?"":", ");
}
fprintf(stderr,"},\n");
}

// multiple to 256
int mult=256/(size*size);
for(w=0;w<size;w++){
for(q=0;q<size;q++){
pixels[q+w*size]*=mult;
}
}
fwrite(pixels,1,size*size,stdout);
free(pixels);
}


void createGradient4(int size){
uint8_t *pixels=malloc(size*size);
int q,w,p,mode;
int side=size>>1;
double dx,dy,dl;
for(mode=0;mode<4;mode++){
for(w=0;w<side;w++){
for(q=0;q<side;q++){
p=(q+(mode&1)*side)+(w+((mode>>1)&1)*side)*size;

if(mode==0){//radial
dx=side-q;
dy=side-w;
dl=sqrt(dx*dx+dy*dy);
pixels[p]=(uint8_t)dl;
}

if(mode==1){//horizontal
pixels[p]=side-1-w;
}

if(mode==2){//vertical
pixels[p]=side-1-q;
}

if(mode==3){//diagonal
pixels[p]=q<w?q:w;
}

}
}
}
fwrite(pixels,1,size*size,stdout);
free(pixels);
}



void createHilbert(int size, int scale){
int q,p,level=log2(size/scale)+1,psize=size*size;
int count=hilbert_points_at_level(level);
int cx,cy,nx,ny;
uint8_t *pixels=malloc(psize);
memset(pixels,0,psize);
for(q=0;q<count;q++){
hilbert(q,level,&nx,&ny);
nx*=scale;
ny*=scale;
if(q==0){
cx=nx;cy=ny;
}
do{
p=cx+cy*size;
if(p>=0 && p<psize && cx<size){
pixels[p]=255;
}
if(cx<nx){cx++;}
if(cx>nx){cx--;}
if(cy<ny){cy++;}
if(cy>ny){cy--;}
}while(cx!=nx || cy!=ny);

}
fwrite(pixels,1,size*size,stdout);
free(pixels);
}


void createBinarySun(int size, int is_skew_checker, int mindist){
uint8_t *pixels=malloc(size*size);
int q,w,p;
int center=size>>1;
int distances=size<<3;
int *dist2count=malloc(sizeof(int)*distances);
int curpow=0;
for(q=0;q<distances;q++){
if((q>>(curpow))>0){curpow++;}
dist2count[q]=1<<(curpow);
}
for(w=0;w<size;w++){
for(q=0;q<size;q++){
p=q+w*size;
double angle=atan2(center-w,center-q);
if(angle<0){angle=2.0*M_PI+angle;}
double dist=sqrt(pow(center-q,2)+pow(center-w,2));
double circlen=2.0*M_PI*dist-.5;
int sides=dist2count[(int)(circlen)]>>1;
int sides_eq=1<<(int)(dist/(double)mindist);
if(sides_eq<sides){
sides=sides_eq;
}
int pos=((int)(angle/2.0/M_PI*sides+(is_skew_checker?log2(sides):0)));
pixels[p]=pos&1?255:0;
}
}
fwrite(pixels,1,size*size,stdout);
free(pixels);
free(dist2count);
}

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


void createGradient(int size){
uint32_t *pixels=malloc(size*size*4);
int q,w,qi,wi,p;
double qf,wf;
int red,green,blue;
for(w=0;w<size;w++){
for(q=0;q<size;q++){
qf=(double)q/size;
wf=(double)w/size;
qi=0.5+qf*256.0;
wi=0.5+wf*256.0;
p=q+w*size;
red=255-wi;
green=qi;
blue=wi;
pixels[p]=0xFF000000 | blue | (green<<8) | (red<<16);
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

if(strstr(op,"gradient1")){
createGradient(twidth);
}

if(strstr(op,"gradient4")){
createGradient4(twidth);
}

if(strstr(op,"binarysun")){
createBinarySun(twidth,atoi(argv[3]),atoi(argv[4]));
}

if(strstr(op,"hilbert")){
createHilbert(twidth,atoi(argv[3]));
}

if(strstr(op,"bayer")){
createBayer(twidth);
}

if(strstr(op,"signature")){
createSignatureOverlay(twidth,atoi(argv[3]),argv[4]);
}

return EXIT_SUCCESS;
}



