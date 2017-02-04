#include "garis.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
//==============================================================================
void bufferDrawLine2(titik p0, titik p1, warna c){
	int dx, dy, x, y, x_end, y_end, px, py, cx1, cx2, cy1, cy2;
	titik p2;
	titik p3;
	
	dx = abs(p0.x - p1.x);
	dy = abs(p0.y - p1.y);
	
	px = 2 * dx - dy;
	py = 2 * dy - dx;
	cx1 = 2 * dy;
	cx2 = 2 * (dy-dx);
	cy1 = 2 * dx;
	cy2 = 2 * (dx-dy);
	
	if (dy <= dx) {
		if (p0.x > p1.x) {
			x = p1.x;
			y = p1.y;
			x_end = p0.x;
			p3.y = p0.y;
		} else {
			x = p0.x;
			y = p0.y;
			x_end = p1.x;
			p3.y = p1.y;
		}
		
		//setpixel(x, y)
		p2.x = x;
		p2.y = y;
		bufferDrawDot(p2, c);

		int dy;
		if(p2.y > p3.y)
		{
			dy = -1;
		}
		else
		{
			dy = 1;
		}
			
		while (x-1 < x_end) {
			x++;
		
			if (px <= 0) {
				px += cx1;
			} else {
				y += dy;
				px += cx2;
			}
			
			//setpixel(x,y)
			p2.x = x;
			p2.y = y;
			
			bufferDrawDot(p2, c);
		}
	} else {
		if (p0.y >= p1.y) {
			x = p1.x;
			y = p1.y;
			y_end = p0.y;
			p3.x = p0.x;
		} else {
			x = p0.x;
			y = p0.y;
			y_end = p1.y;
			p3.y = p1.x;
		}
		
		//setpixel(x, y)
		p2.x = x;
		p2.y = y;
		bufferDrawDot(p2, c);
		
		int dx;
		if(p2.x >= p3.x)
		{
			dx = -1;
		}
		else
		{
			dx = 1;
		}

		while (y-1 < y_end) {
			y++;
		
			if (py <= 0) {
				py += cy1;
			} else {
				x += dx;
				py += cy2;
			}
			
			//setpixel(x,y)
			p2.x = x;
			p2.y = y;
			bufferDrawDot(p2, c);
		}
	}
}
//==============================================================================
void bufferDrawPlane2(titik* p, warna c, int sisi){
	int i= 0;

	for (i = 0; i < sisi-1; i++) {
		bufferDrawLine(p[i], p[i+1], c);
	}
	

	bufferDrawLine(p[i], p[0], c);
}
//==============================================================================

int main(){
//**setup-objek-game***************************************
	init_fb();
	warna c = {255,255,255,255};
	titik pl0 = {0,0};
	titik pl1 = {1000,600};
	titik p0 = {400,100};
	titik p1 = {600,400};
	titik p2 = {300,450};
	titik p3 = {500,450};

	refreshBuffer(pl0, pl1);
	
	bufferDrawLine2(p0, p1, c);

	titik pt[3];
	pt[0] = p1;
	pt[1] = p2;
	pt[2] = p3;

	bufferDrawPlane2(pt, c, 3);
	loadBuffer();


	garbage_fb();
	return 0;
}