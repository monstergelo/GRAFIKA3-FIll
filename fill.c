#include "fill.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>


void bufferDrawPlaneSolid(titik* p, warna c, int sisi){


}

void fill(titik p, warna c){

}

int main(){
//**setup-objek-game***************************************
	init_fb();
	warna c = {255,255,255,255};
	titik pl0 = {0,0};
	titik pl1 = {1000,600};

	titik pf = {600,300};

	titik p00 = {400,100};
	titik p01 = {900,100};

	titik p10 = {400,500};
	titik p11 = {900,500};

	titik p20 = {450,80};
	titik p21 = {450,550};

	titik p30 = {850, 80};
	titik p31 = {850, 550};

	refreshBuffer(pl0, pl1);

	bufferDrawLine(p00, p01, c);

	bufferDrawLine(p10, p11, c);

	bufferDrawLine(p20, p21, c);

	bufferDrawLine(p30, p31, c);

	//bufferDrawDot(pf, c);
	fill(pf,c);


	loadBuffer();


	garbage_fb();
	return 0;
}