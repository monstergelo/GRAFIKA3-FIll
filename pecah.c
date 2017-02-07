#include "pecah.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>


int pesawatterakhir;
int peluruterakhir;
int pecahanterakhir;

objekTabrak pesawat[1];
objekTabrak peluru[100];
objekTabrak pecahan[10];

void spawnPecahan(titik p){
	titik p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20;
	int scale = 20;
	warna x = {20, 254, 76, 255};
	p1.x = p.x - (4*scale); p1.y = p.y + (2*scale);
	p2.x = p.x - (3*scale); p2.y = p.y + (2*scale);
	p3.x = p.x - (4*scale); p3.y = p.y - (1*scale);
	p4.x = p.x - (3*scale); p4.y = p.y - (1*scale);
	p5.x = p.x + (1*scale); p5.y = p.y + (3*scale);
	p6.x = p.x + (2*scale); p6.y = p.y + (3*scale);
	p7.x = p.x + (1*scale); p7.y = p.y + (2*scale);
	p8.x = p.x + (2*scale); p8.y = p.y + (2*scale);
	p9.x = p.x - (2*scale); p9.y = p.y + (1*scale);
	p10.x = p.x + (2*scale); p10.y = p.y + (1*scale);
	p11.x = p.x - (2*scale); p11.y = p.y - (1*scale);
	p12.x = p.x + (2*scale); p12.y = p.y - (1*scale);
	p13.x = p.x + (1*scale); p13.y = p.y - (2*scale);
	p14.x = p.x + (2*scale); p14.y = p.y - (2*scale);
	p15.x = p.x + (1*scale); p15.y = p.y - (3*scale);
	p16.x = p.x + (2*scale); p16.y = p.y - (3*scale);
	p17.x = p.x + (3*scale); p17.y = p.y + (1*scale);
	p18.x = p.x + (4*scale); p18.y = p.y + (1*scale); 
	p19.x = p.x + (3*scale); p19.y = p.y - (1*scale);
	p20.x = p.x + (4*scale); p20.y = p.y - (1*scale);
	
	bufferDrawLine(p1,p2,x);
	bufferDrawLine(p2,p4,x);
	bufferDrawLine(p3,p1,x);
	bufferDrawLine(p4,p3,x);
	bufferDrawLine(p5,p6,x);
	bufferDrawLine(p6,p8,x);
	bufferDrawLine(p7,p8,x);
	bufferDrawLine(p7,p5,x);
	bufferDrawLine(p9,p10,x);
	bufferDrawLine(p10,p12,x);
	bufferDrawLine(p11,p12,x);
	bufferDrawLine(p11,p9,x);
	bufferDrawLine(p13,p14,x);
	bufferDrawLine(p14,p16,x);
	bufferDrawLine(p15,p16,x);
	bufferDrawLine(p15,p13,x);
	bufferDrawLine(p17,p18,x);
	bufferDrawLine(p18,p20,x);
	bufferDrawLine(p19,p20,x);
	bufferDrawLine(p19,p17,x);

}

int main(){
	//inisialisasi
	init_fb();
	warna c = {255,255,255,255};
	titik pl0 = {0,0}; //background
	titik pl1 = {1000,600}; //bakcground
	titik p0 = {400,100}; //titik awal pesawat
	titik p1 = {600,400}; 
	titik p2 = {300,450};
	titik p3 = {500,450};

	//inisialisasi pesawat
	spawnObjek('a',p0);

	refreshBuffer(pl0,pl1);	//buat background
	gambarObjek();			//siapin gambar pesawat
	spawnObjek('b',p0);	    //gambar peluru
	//spawnPecahan(pesawat[0].posisi);  //gambar pecahan
	loadBuffer();			//gambar ke layar

	usleep(2000000);
	int i = 0;
	
	while(i<10000)
	{
		refreshBuffer(pl0,pl1);
		spawnPecahan(pesawat[0].posisi);  //gambar pecahan
		gambarObjek();
		jalanObjek();

		pesawat[0].posisi.y+= 5;

		gambarHancur(pesawat[0].posisi);
		pesawat[0].isTabrakan = -1;
		loadBuffer();

		usleep(170);
		i++;
	} 


	return 0;
}
