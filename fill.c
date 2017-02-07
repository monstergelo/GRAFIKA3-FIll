#include "fill.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

// int is_color(titik p, warna c) {
// 	return buffer_r[p.x][p.y] == c.r && buffer_g[p.x][p.y] == c.g
// 	&& buffer_b[p.x][p.y] == c.b && buffer_a[p.x][p.y] == c.a;
// }
//
// void bufferDrawPlaneSolid(titik* p, warna c, warna bound_c, int sisi) {
// 	int i, x_mid = 0, y_mid = 0;
// 	titik flare_point;
// 	bufferDrawPlane(p, bound_c, sisi);
// 	for (i = 0; i < sisi; i++) {
// 		x_mid += p[i].x;
// 		y_mid += p[i].y;
// 	}
// 	flare_point.x = x_mid / sisi;
// 	flare_point.y = y_mid / sisi;
// 	printf("%d %d\n", flare_point.x, flare_point.y);
// 	fill(flare_point, c, bound_c);
// }
//
// void fill(titik p, warna c, warna bound_c) {
// 	if (!is_color(p, c) && !is_color(p, bound_c)) {
// 		bufferDrawDot(p, c);
// 		titik new_p = {p.x, p.y+1};
// 		fill(new_p, c, bound_c);
// 		new_p.x = p.x-1; new_p.y = p.y;
// 		fill(new_p, c, bound_c);
// 		new_p.x = p.x+1; new_p.y = p.y;
// 		fill(new_p, c, bound_c);
// 		new_p.x = p.x; new_p.y = p.y-1;
// 		fill(new_p, c, bound_c);
// 	}
// }

int main(){
//**setup-objek-game***************************************
	init_fb();
	warna c = {255,255,255,255};
	warna bc = {255, 255, 255, 255};
	titik pl0 = {0,0};
	titik pl1 = {1000,600};

	titik pf = {500,200};

	titik p00 = {400,100};
	titik p01 = {600,100};

	titik p10 = {400,300};
	titik p11 = {600,300};

	titik p20 = {450,80};
	titik p21 = {450,400};

	titik p30 = {550, 80};
	titik p31 = {550, 400};

	refreshBuffer(pl0, pl1);

	bufferDrawLine(p00, p01, c);
	bufferDrawLine(p10, p11, c);
	bufferDrawLine(p20, p21, c);
	bufferDrawLine(p30, p31, c);

	//bufferDrawDot(pf, c);
	fill(pf, bc, c);

	titik p[3];
	p[0].x = 200; p[0].y = 200;
	p[1].x = 400; p[1].y = 200;
	p[2].x = 300; p[2].y = 300;
	bufferDrawPlaneSolid(p, c, bc, 3);
	loadBuffer();

	garbage_fb();
	return 0;
}
