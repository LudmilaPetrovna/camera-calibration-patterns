#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>


int hilbert_points_at_level(int level){
if(level<0){level=0;}
return(powl(powl(2,level),2));
}

int hilbert_side_at_level(int level){
if(level<0){level=0;}
return(powl(2,level));
}

void hilbert(uint32_t i, uint32_t level, uint32_t *out_x, uint32_t *out_y){
static uint32_t h[4]={28942,13897,51893,36338};
uint32_t hs=h[0];
uint32_t ox=0,oy=0;
int q;
for(q=level-1;q>=0;q--){
hs=(hs>>(((i>>(q<<1))&3)<<2))&0xf;
ox=(ox<<1)|(hs&1);
oy=(oy<<1)|((hs>>1)&1);
hs=h[hs>>2];
}
*out_x=ox;
*out_y=oy;
}

/*

int main(){

int q;

printf("<?xml version=\"1.0\" standalone=\"no\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");
// viewBox=\"0 0 500 500\"
printf("<path d=\"");

int level=4;
int points=powl(powl(2,level),2);
uint32_t ox,oy;
for(q=0;q<points;q++){
hilbert(q,level,&ox,&oy);
ox*=5;
oy*=5;
if(q==0){
printf("M %d.5 %d.5 ",ox,oy);
} else {
printf("L %d.5 %d.5 ",ox,oy);
}

}


printf("\" fill=\"gold\" stroke=\"black\" stroke-width=\"1\" />");

printf("</svg>");





return 0;
}

*/
